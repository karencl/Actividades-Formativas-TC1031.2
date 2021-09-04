//
//  sorts.h
//  PrograDataStructureAndAlgorithms
//
//  Created by Karen CL on 31/08/21.
//

#ifndef sorts_h
#define sorts_h

#include <iostream>
using namespace std;

// Template class Sorts
template <class T>
class Sorts {
    private:
        // Métodos auxiliares
        void swap(vector<T>&, int, int);
    
    public:
        void ordenaSeleccion(vector<T>&);
        void ordenaBurbuja(vector<T>&);
        
        // 4 métodos para el ordenamiento merge
        void mergeArray(vector<T>&, int, int, int);
        void mergeSplit(vector<T>&, int, int);
        void ordenaMerge(vector<T>&);
    
        int busqBinaria(vector<T>&, int);
        int busqSecuencial(const vector<T>&, int);
};

/*
 * @param vector<T>&, int, int
 * @return
 *
 * Hace la un swap entre dos elementos de un vector que se pasa por referencia.
 *
 */
template <class T>
void Sorts<T>::swap(vector<T> &vec, int i, int j) {
    T aux = vec[i];
    vec[i] = vec[j];
    vec[j] = aux;
}

/*
 * @param vector<T>&
 * @return
 *
 * Ordena un vector que se pasa por referencia, mediante el método de selección.
 *
 */
template <class T>
void Sorts<T>::ordenaSeleccion(vector<T> &vec) {
    for (int i = 0; i < vec.size(); i++) {
        int min_index = i;
        for (int j = i+1; j < vec.size(); j++) {
            if (vec[j] < vec[min_index])
                min_index = j;
        }
        swap(vec, min_index, i);
    }
}

/*
 * @param vector<T>&
 * @return
 *
 * Ordena un vector que se pasa por referencia, mediante el método burbuja.
 *
 */
template <class T>
void Sorts<T>::ordenaBurbuja(vector<T> &vec) {
    int n = vec.size()-1;

    for (int i = n; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (vec[j] > vec[j+1])
                swap(vec, j, j+1);
        }
    }
}

/*
 * @param const vector<T>&, int, int, int
 * @return
 *
 * Se crean los vectores "izquierdo" y "derecho", se les pasan los respectivos
 * elementos para posteriormente, compararlos y ordenarlos en el vector inicial.
 *
 */
template <class T>
void Sorts<T>::mergeArray(vector<T> &vec, int low, int middle, int high) {
    
    // Para el lado derecho
    int elms_der = high - middle;
    std::vector<T> vec_der(elms_der);
    
    for (int i = 0; i < elms_der; i++) {
        vec_der[i] = vec[middle + i + 1];
    }
    
    // Para el lado izquierdo
    int elms_izq = middle - low + 1;
    std::vector<T> vec_izq(elms_izq);
    
    for (int i = 0; i < elms_izq; i++) {
        vec_izq[i] = vec[low+i];
    }
    
    
    // contadores
    int i = 0, j = 0, k = low;
    
    // para ambos casos
    while (i < elms_der && j < elms_izq) {
        if (vec_der[i] >= vec_izq[j])
            vec[k] = vec_izq[j++];
        else
            vec[k] = vec_der[i++];
        k++;
    }
    
    // para cuando solo uno siga teniendo elementos
    while (i < elms_der) {
        vec[k++] = vec_der[i++];
    }
    while (j < elms_izq) {
        vec[k++] = vec_izq[j++];
    }
    
    // vaciamos vectores (izq y der)
    vec_der.clear();
    vec_izq.clear();
}

/*
 * @param const vector<T>&, int, int
 * @return
 *
 * Se manda a llamar recursivamente a si misma, haciendo las divisiones
 * necesarias del vector para posteriormente ser ordenadas al llamar a la función
 * "mergeArray()"; en donde se le pasa el mismo vector por referencia, el índice
 * de inicio, final y en medio (que es calculado en cada llamada de ésta).
 *
 */
template <class T>
void Sorts<T>::mergeSplit(vector<T> &vec, int low, int high) {
    if (low < high) {
        int middle = (low + high) / 2;
        mergeSplit(vec, low, middle); // split izquierdo
        mergeSplit(vec, middle+1, high); // split derecho
        mergeArray(vec, low, middle, high);
    }
}

/*
 * @param const vector<T>&
 * @return
 *
 * Manda a llamar a la función "mergeSplit()" y se le pasa el mismo vector por
 * referencia, así como el índice de inicio y final de este.
 *
 */
template <class T>
void Sorts<T>::ordenaMerge(vector<T> &vec) {
    mergeSplit(vec, 0, vec.size()-1);
}

/*
 * @param vector<T>&, int
 * @return int
 *
 * Realiza una búsqueda binaria de un elemento en un vector, que primero es
 * ordenado a través del método de selección.
 * En caso de que se encuentre el elemento en este, devuelve su índice.
 *
 */
template <class T>
int Sorts<T>::busqBinaria(vector<T> &vec, int x) {
    ordenaSeleccion(vec);
    int high = vec.size()-1;
    int low = 0;
    
    while (high > low) {
        int middle = (high + low) / 2;
        if (x == vec[middle])
            return middle;
        else if (x > vec[middle])
            low = middle + 1;
        else if (x < vec[middle])
            high = middle - 1;
    }
    
    return -1;
}

/*
 * @param const vector<T>&, int
 * @return int
 *
 * Realiza una búsqueda secuencial de un elemento en un vector.
 * En caso de que se encuentre el elemento en este, devuelve su índice.
 *
 */
template <class T>
int Sorts<T>::busqSecuencial(const vector<T> &vec, int x) {
    for (int i = 0; i < vec.size(); i++) {
        if (x == vec[i])
            return i;
    }
    return -1;
}


#endif /* sorts_h */

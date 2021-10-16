/*
 *  heap.h
 *  PrograDataStructureAndAlgorithms
 *
 *  Created by Karen CL on 15/10/21.
*/

#ifndef heap_h
#define heap_h

using namespace std;

// Template class Heap
template <class T>
class Heap {
private:
    // Atributos (privados)
    T *data;
    int h_size;
    int count;
    
    // Métodos (privados)
    int parent(int) const;
    int leftChild(int) const;
    int rightChild(int) const;
    void heapify(int);
    void swap(int, int);
public:
    // Constructor
    Heap(int);
    
    // Métodos
    void push(T);
    void pop();
    T top();
    bool empty() const;
    int size() const;
    string toString() const;
};

/*
 * @param int
 * @return
 *
 * Constructor de un objeto de la clase Heap.
 *
 */
template <class T>
Heap<T>::Heap(int sze) {
    h_size = sze;
    data = new T[h_size];
    count = 0;
}

/*
 * @param int
 * @return int
 *
 * Regresa la posición del padre, utilizando la posición que se le pasa
 * al método, restándole 1 y dividiéndo entre 2.
 *
 */
template <class T>
int Heap<T>::parent(int posicion) const {
    return (posicion - 1) / 2;
}

/*
 * @param int
 * @return int
 *
 * Regresa la posición del hijo izquierdo, utilizando la posición que se le pasa
 * al método, multiplicándola por 2 y sumándole 1.
 *
 */
template <class T>
int Heap<T>::leftChild(int posicion) const {
    return (posicion * 2) + 1;
}

/*
 * @param int
 * @return int
 *
 * Regresa la posición del hijo derecho, utilizando la posición que se le pasa
 * al método, multiplicándola por 2 y sumándole otros 2.
 *
 */
template <class T>
int Heap<T>::rightChild(int posicion) const {
    return (posicion * 2) + 2;
}

/*
 * @param int
 * @return
 *
 * Busca el mínimo comparando a los hijos, dependiendo de la posición que se le
 * pase al método, para luego aplicar "swap()" a los valores si es que no se
 * encuentran en orden.
 *
 */
template <class T>
void Heap<T>::heapify(int posicion) {
    int left = leftChild(posicion);
    int right = rightChild(posicion);
    int min = posicion;
    
    if (right <= count) {
        if (data[right] < data[min])
            min = right;
    }
    if (left <= count) {
        if (data[left] < data[min])
            min = left;
    }
    
    if (min != posicion) {
        swap(min, posicion);
        heapify(min);
    }
}

/*
 * @param int, int
 * @return
 *
 * Simplemente se intercambian dos valores de dos posiciones diferentes que se
 * le pasan al método.
 *
 */
template <class T>
void Heap<T>::swap(int index1, int index2) {
    T aux = data[index1];
    data[index1] = data[index2];
    data[index2] = aux;
}

/*
 * @param T
 * @return
 *
 * Inserta un nuevo elemento y se incrementa el contador.
 * Se usa al método "parent()" para comparar cuál se los dos valores es mayor
 * para luego poder insertar el elemento en la posición correcta.
 *
 */
template <class T>
void Heap<T>::push(T val) {
    int posicion = count;
    count++;
    
    while (val < data[parent(posicion)] && posicion > 0) {
        data[posicion] = data[parent(posicion)];
        posicion = parent(posicion);
    }
    
    data[posicion] = val;
}

/*
 * @param
 * @return
 *
 * Quita el elemento con mayor prioridad y se decrementa el contador.
 * Luego ubica al último elemento en la posición 0 y aplica "heapify()" con esa
 * misma posición para ordenar todo como se debería.
 *
 */
template <class T>
void Heap<T>::pop() {
    if(!empty()) {
        count--;
        data[0] = data[count];
        heapify(0);
    }
}

/*
 * @param
 * @return T
 *
 * Regresa el elemento con mayor prioridad, que es el que se encuentra en la
 * posición 0.
 *
 */
template <class T>
T Heap<T>::top() {
    return data[0];
}


/*
 * @param
 * @return bool
 *
 * Regresa verdadero si la count es 0 (está vacío) y falso si count es mayor a 0
 * (no está vacío).
 *
 */
template <class T>
bool Heap<T>::empty() const {
    return (count == 0);
}

/*
 * @param
 * @return int
 *
 * Es básicamente un getter del atributo count, para saber cuántos elementos
 * hay.
 *
 */
template <class T>
int Heap<T>::size() const {
    return count;
}

/*
 * @param
 * @return string
 *
 * Lo recorre por completo y va agregando a un stringstream los elementos, para
 * poder imprimirlos.
 *
 */
template <class T>
string Heap<T>::toString() const {
    std::stringstream aux;
    aux << "[";
    for (int i = 0; i < count; i++) {
        if (i != 0) {
            aux << " ";
        } aux << data[i];
    } aux << "]";
    return aux.str();
}

#endif /* heap_h */

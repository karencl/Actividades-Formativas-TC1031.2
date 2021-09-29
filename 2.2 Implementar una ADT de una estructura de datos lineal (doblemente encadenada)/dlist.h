/*
 *  dlist.h
 *  PrograDataStructureAndAlgorithms
 *
 *  Created by Karen CL on 26/09/21.
*/

#ifndef dlist_h
#define dlist_h

#include <iostream>
using namespace std;

template <class T> class DList;


// Template class DLink
template <class T>
class DLink {
    private:
        // Atributos (privados)
        T value;
        DLink<T> *previous;
        DLink<T> *next;
        
        // Constructores (privados)
        DLink(T val): value(val), previous(0), next(0){};
        DLink(T val, DLink<T> *prev, DLink<T> *nxt): value(val),
        previous(prev), next(nxt){};

        // Clase "DList" puesta como friend de "DLink"
        friend class DList<T>;
};


// Template class DList
template <class T>
class DList {
    private:
        // Atributos privados
        DLink<T> *head;
        DLink<T> *tail;
        int size;
    
    public:
        // Constructor
        DList(): head(0), tail(0), size(0){};

        // Métodos
        string toStringForward() const;
        string toStringBackward() const;
        void insertion(T);
        int search(T);
        void update(int, T);
        T deleteAt(int);
};

/*
 * @param
 * @return string
 *
 * Pasa la los valores de una lista a un string, para devolverlo e imprimirlo.
 * Lo hace de principio a fin.
 *
 */
template <class T>
string DList<T>::toStringForward() const {
    stringstream aux;
    DLink<T> *p;
    p = head;
    aux << "[";
    while (p != 0) {
        aux << p->value;
        if (p->next != 0) {
            aux << ", ";
        }
        p = p->next;
    }
    aux << "]";
    return aux.str();
}

/*
 * @param
 * @return string
 *
 * Pasa la los valores de una lista a un string, para devolverlo e imprimirlo.
 * Lo hace de fin a principio.
 *
 */
template <class T>
string DList<T>::toStringBackward() const {
    stringstream aux;
    DLink<T> *p;
    p = tail;
    aux << "[";
    while (p != 0) {
        aux << p->value;
        if (p->previous != 0) {
            aux << ", ";
        }
        p = p->previous;
    }
    aux << "]";
    return aux.str();
}

/*
 * @param T
 * @return
 *
 * Inserta un nuevo nodo al final de la lista.
 *
 */
template <class T>
void DList<T>::insertion(T val) {
    DLink<T> *new_link = new DLink<T>(val);
    
    if (!head) {
        head = new_link;
        tail = new_link;
    } else {
        tail->next = new_link;
        new_link->previous = tail;
        tail = new_link;
    }
    
    size++;
}

/*
 * @param T
 * @return int
 *
 * Busca un elemento en la lista.
 * Si lo encuentra, devuelve la posición de este en la lista y si no, devuelve -1.
 *
 */
template <class T>
int DList<T>::search(T val) {
    DLink<T> *aux = head;
    int pos = 0;
    
    while (aux) {
        if (aux->value == val) {
            return pos;
        }
        aux = aux->next;
        pos++;
    }
    
    return -1;
}

/*
 * @param int, T
 * @return
 *
 * Reemplaza un valor por otro en un nodo de la lista.
 *
 */
template <class T>
void DList<T>::update(int pos, T val) {
    DLink<T> *aux = head;
    int pos_check = 0;
    
    while (aux) {
        if (pos_check == pos) {
            aux->value = val;
            break;
        }
        aux = aux->next;
        pos_check++;
    }
}

/*
 * @param int
 * @return T
 *
 * Elimina un nodo específico de la lista.
 * (Se utiliza su posición en esta para ello).
 *
 */
template <class T>
T DList<T>::deleteAt(int pos) {
    DLink<T> *a_eliminar = head;
    T val_eliminado = a_eliminar->value;
    
    
    if (pos == 0) {
        if (head == tail) {
            head = 0;
            tail = 0;
        } else {
            head = head->next;
            head->previous = 0;
        }
        delete a_eliminar;
    } else {
        DLink<T> *aux1 = head;
        DLink<T> *aux2 = aux1->next;
        int pos_check = 1;
        
        while (aux2) {
            if (pos_check == pos) {
                a_eliminar = aux2;
                val_eliminado = aux2->value;
                
                if (aux2 == tail) {
                    aux1->next = 0;
                    tail = aux1;
                } else {
                    aux1->next = aux2->next;
                    aux2->next->previous = aux1;
                }
                
                delete a_eliminar;
                break;
            }
            pos_check++;
            aux1 = aux1->next;
            aux2 = aux2->next;
        }
    }
    
    size--;
    
    return val_eliminado;
}

#endif /* dlist_h */

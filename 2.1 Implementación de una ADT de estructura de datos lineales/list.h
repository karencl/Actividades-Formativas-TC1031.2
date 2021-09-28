/*
 *  list.h
 *  PrograDataStructureAndAlgorithms
 *
 *  Created by Karen CL on 21/09/21.
*/

#ifndef list_h
#define list_h

#include <iostream>
using namespace std;

template <class T> class List;


// Template class Link
template <class T>
class Link {
    private:
        // Atributos (privados)
        T value;
        Link<T> *next;
    
        // Constructores (privados)
        Link(T val): value(val), next(0){};
        Link(T val, Link<T> *nxt): value(val), next(nxt){};
        
        // Clase "List" puesta como friend de "Link"
        friend class List<T>;
    
};


// Template class List
template <class T>
class List {
    private:
        // Atributos privados
        Link<T> *head;
        int     size;
    public:
        // Constructor
        List(): head(0), size(0){};
        // Destructor
        ~List(){delete head;};
    
        // Métodos
        string toString() const;
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
 *
 */
template <class T>
string List<T>::toString() const {
    std::stringstream aux;
    Link<T> *p;
    p = head;
    aux << "[";
    while (p) {
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
 * @param T
 * @return
 *
 * Inserta un nuevo nodo al final de la lista.
 *
 */
template <class T>
void List<T>::insertion(T val) {
    Link<T> *new_link = new Link<T>(val);
    Link<T> *aux = head;
    
    if (aux == 0) {
        head = new_link;
    } else {
        while (aux) {
            if (aux->next == 0) {
                aux->next = new_link;
                break;
            }
            aux = aux->next;
        }
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
int List<T>::search(T val) {
    Link<T> *aux = head;
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
void List<T>::update(int pos, T new_val) {
    Link<T> *aux = head;
    int pos_check = 0;
    
    while (aux) {
        if (pos_check == pos) {
            aux->value = new_val;
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
T List<T>::deleteAt(int pos) {
    T val_eliminado = 0;
    
    if (pos == 0) {
        val_eliminado = head->value;
        head = head->next;
    } else {
        Link<T> *aux1 = head;
        Link<T> *aux2 = aux1->next;
        int pos_check = 1;
    
        while (aux2) {
            if(pos_check == pos) {
                val_eliminado = aux2->value;
                aux1->next = aux2->next;
                break;
            }
            aux1 = aux1->next;
            aux2 = aux2->next;
        }
    }
    
    size--;
    
    return val_eliminado;
}

#endif /* list_h */

/*
 *  hash.h
 *  PrograDataStructureAndAlgorithms
 *
 *  Created by Karen CL on 21/11/21.
 */

#ifndef hash_h
#define hash_h

#include <string>
#include <sstream>

using namespace std;

// Clase template Quadratic
template <class Key, class Value>
class Quadratic {
    private:
        // Atributos (privados)
        unsigned int (*func) (const Key);
        unsigned int size;
        unsigned int count;
        Key *keys;
        Key initialValue;
        Value *values;

        // Método privado
        long indexOf(const Key) const;

    public:
        // Constructor
        Quadratic(unsigned int, Key, unsigned int (*f) (const Key));
    
        // Métodos
        bool put(Key, Value);
        Value get(const Key);
        string toString() const;
};

/*
 * @param unsigned int, Key, unsigned int, const Key
 * @return
 *
 * Constructor de un objeto de la clase "Quadratic".
 *
 */
template <class Key, class Value>
Quadratic<Key, Value>::Quadratic(unsigned int sze, Key init,
                                 unsigned int (*f) (const Key)) {
    size = sze;
    func = f;
    count = 0;
    initialValue = init;
    keys = new Key[size];
    values = new Value[size];
    
    int i;
    for (i = 0; i < size; i++)
        keys[i] = init;
    
    for (i = 0; i < size; i++)
        values[i] = 0;
}

/*
 * @param const Key
 * @return long
 *
 * Obtiene el índice de una "Key" que se le pasa al método, iterando sobre el
 * array de "keys".
 *
 */
template <class Key, class Value>
long Quadratic<Key, Value>::indexOf(const Key k) const {
    unsigned int i = func(k) % size;
    unsigned int start = i;

    do {
        if (keys[i] == k)
            return i;
        
        i = (i + 1) % size;
    } while (start != i);
    
    return -1;
}

/*
 * @param Key, Value
 * @return bool
 *
 * Agrega un nuevo "Key, Value" al hash.
 *
 */
template <class Key, class Value>
bool Quadratic<Key, Value>::put(Key k, Value v) {
    unsigned int i = func(k) % size;
    unsigned int start = i;
    long pos = indexOf(k);
    
    
    if (pos != -1) {
        values[pos] = v;
        return true;
    }
    
    int j = 0;
    do {
        if (keys[i] == initialValue) {
            keys[i] = k;
            values[i] = v;
            count++;
            return true;
        }
        i = (start + j * j) % size;
        j++;
    } while (values[i] != -1);
    
    return false;
}

/*
 * @param const Key
 * @return Value
 *
 * Obtiene el valor de una "Key" que se le pasa al método, a través de obtener su
 * índice primero con el método de "indexOf", recorriendo el array de "keys" y
 * luego con este, su valor recorriendo el arreglo de "values".
 *
 */
template <class Key, class Value>
Value Quadratic<Key, Value>::get(const Key k) {
    long pos = indexOf(k);
    
    return (pos != -1) ? values[pos] : -1;
}

/*
 * @param
 * @return string
 *
 * Regresa el string del hash, recorriendo este y obteniendo tanto las llaves,
 * como los valores.
 *
 */
template <class Key, class Value>
string Quadratic<Key, Value>::toString() const {
    stringstream aux;
    for (int i = 0; i < size; i++){
            if (keys[i] != initialValue){
                aux << "(" << i << " ";
              aux << keys[i] << " : " << values[i] << ") ";
            }
    }
    return aux.str();
}

#endif /* hash_h */

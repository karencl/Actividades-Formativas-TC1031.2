/*
 *  splay.h
 *  PrograDataStructureAndAlgorithms
 *
 *  Created by Karen CL on 19/10/21.
 */

#ifndef splay_h
#define splay_h

#include <string>
#include <sstream>
#include <iostream>

using namespace std;

template <class T> class SplayTree;

// Template class Node
template <class T>
class TreeNode {
    private:
    // Atributos (privados)
    T value;
    TreeNode *left, *right, *parent;

    // Métodos (privados)
    TreeNode<T>* succesor();
    TreeNode<T>* rotRight(TreeNode<T>*);
    TreeNode<T>* rotLeft(TreeNode<T>*);

    public:
        // Constructores
        TreeNode(T val): value(val), left(NULL), right(NULL), parent(NULL){};
        TreeNode(T val, TreeNode<T> *le, TreeNode<T> *ri ,TreeNode<T> *pa): value(val), left(le), right(ri), parent(pa){};
        
        // Métodos
        TreeNode<T>* splay(TreeNode<T>*, TreeNode<T>*);
        TreeNode<T>* add(T);
        TreeNode<T>* find(T);
        TreeNode<T>* remove(T);
        void inorder(stringstream&) const;
        void preorder(stringstream&) const;
        void print_tree(stringstream&) const;

        // Clase "SplayTree" puesta como friend de "TreeNode"
        friend class SplayTree<T>;
};

/*
 * @param
 * @return TreeNode<T>*
 *
 * Obtiene el sucesor de un nodo.
 *
 */
template <class T>
TreeNode<T>* TreeNode<T>::succesor() {
    TreeNode<T> *ri = right;
    TreeNode<T> *le = left;
    
    if (!right->left) {
        right = right->left;
        ri->right = NULL;
        return ri;
    }
    if (!left->right) {
        left = left->right;
        le->left = NULL;
        return ri;
    }
    
    TreeNode<T> *parent = right;
    TreeNode<T> *child = right->left;
    
    while (child->left) {
        parent = child;
        child = child->left;
    }
    
    parent->left = child->right;
    child->right = NULL;
    return child;
}

/*
 * @param TreeNode<T>*
 * @return TreeNode<T>*
 *
 * Se hace una rotación hacia la derecha.
 *
 */
template <class T>
TreeNode<T>* TreeNode<T>::rotRight(TreeNode<T> *nodo) {
    TreeNode<T> *aux = nodo->left;
    nodo->left = aux->right;
    
    if (aux->right)
        aux->right->parent = nodo;
    aux->right = nodo;
    
    aux->parent = nodo->parent;
    nodo->parent = aux;
    
    if (aux->parent) {
        if (aux->parent->left && aux->parent->left->value == nodo->value)
            aux->parent->left = aux;
        else
            aux->parent->right = aux;
    }
    
    return aux;
}

/*
 * @param TreeNode<T>*
 * @return TreeNode<T>*
 *
 * Se hace una rotación hacia la izquierda.
 *
 */
template <class T>
TreeNode<T>* TreeNode<T>::rotLeft(TreeNode<T> *nodo) {
    TreeNode<T> *aux = nodo->right;
    nodo->right = aux->left;
    
    if (aux->left)
        aux->left->parent = nodo;
    aux->left = nodo;
    
    aux->parent = nodo->parent;
    nodo->parent = aux;
    
    if (aux->parent) {
        if (aux->parent->left && aux->parent->left->value == nodo->value)
            aux->parent->left = aux;
        else
            aux->parent->right = aux;
    }
    
    return aux;
}

/*
 * @param TreeNode<T>*, TreeNode<T>*
 * @return TreeNode<T>*
 *
 * Aplica el "splay" para realizar las rotaciones pertinentes.
 *
 */
template <class T>
TreeNode<T>* TreeNode<T>::splay(TreeNode<T> *root, TreeNode<T> *nodo) {
    while (nodo->parent) {
        if (nodo->parent->value == root->value) {
            if (nodo->parent->left && nodo->parent->left->value == nodo->value)
                rotRight(nodo->parent);
            else
                rotLeft(nodo->parent);
        } else {
            TreeNode<T> *padre = nodo->parent;
            TreeNode<T> *abuelo = padre->parent;
            
            if (padre->left && abuelo->left && nodo->value == padre->left->value
                && padre->value == abuelo->left->value) {
                rotRight(abuelo);
                rotRight(padre);
            } else if (padre->right && abuelo->right
                       && nodo->value == padre->right->value
                       && padre->value == abuelo->right->value) {
                rotLeft(abuelo);
                rotLeft(padre);
            } else if (padre->right && abuelo->left
                       && nodo->value == padre->right->value
                       && padre->value == abuelo->left->value) {
                rotLeft(padre);
                rotRight(abuelo);
            } else {
                rotRight(padre);
                rotLeft(abuelo);
            }
        }
    }
    return nodo;
}

/*
 * @param T
 * @return TreeNode<T>*
 *
 * Después de que se comprueba que el árbol no está vacío, se agrega un nuevo
 * nodo al árbol.
 *
 */
template <class T>
TreeNode<T>* TreeNode<T>::add(T val) {
    if (val > value) {
        if (right)
            return (right->add(val));
        else {
            right = new TreeNode<T>(val);
            right->parent = this;
            return right;
        }
    } else {
        if (left)
            return (left->add(val));
        else {
            left = new TreeNode<T>(val);
            left->parent = this;
            return left;
        }
    }
}

/*
 * @param T
 * @return TreeNode<T>*
 *
 * Va iterando sobre el árbol, para encontrar el nodo que se busca y al final (al
 * regresar al método "find()" de la clase SplayTree), modificar la estructura.
 *
 */
template <class T>
TreeNode<T>* TreeNode<T>::find(T val) {
    if (val == value)
        return this;
    else if (val > value) {
        if (right)
            return (right->find(val));
        else
            return this;
    }
    else if (val < value) {
        if (left)
            return (left->find(val));
        else
            return this;
    }
    return this;
}

/*
 * @param T
 * @return TreeNode<T>*
 *
 * Elimina un nodo del árbol, evaluando si tiene dos, uno o cero hijos y haciendo
 * rotaciones para acomodar todo de nuevo.
 *
 */
template <class T>
TreeNode<T>* TreeNode<T>::remove(T val) {
    TreeNode<T> *succesor, *old;
    if (val > value) {
        if (right) {
            if (right->value == val) {
                old = right;
                if (old->right && old->left) {
                    succesor = right->succesor();
                    if (succesor) {
                        succesor->right = old->right;
                        succesor->left = old->left;
                        succesor->parent = old->parent;
                        
                        if (succesor->right)
                            succesor->right->parent = succesor;
                        if (succesor->left)
                            succesor->left->parent = succesor;
                    }
                    right = succesor;
                } else if (old->right) {
                    old->right->parent = right->parent;
                    right = old->right;
                } else if (old->left) {
                    old->left->parent = right->parent;
                    right = old->left;
                } else {
                    right = NULL;
                }
                
                delete old;
                return this;
            } else {
                return right->remove(val);
            }
        }
    } else {
        if (left) {
            if (left->value == val) {
                old = left;
                if (old->right && old->left) {
                    succesor = left->succesor();
                    if (succesor) {
                        succesor->right = old->right;
                        succesor->left = old->left;
                        succesor->parent = old->parent;
                        
                        if (succesor->right)
                            succesor->right->parent = succesor;
                        if (succesor->left)
                            succesor->left->parent = succesor;
                    }
                    left = succesor;
                } else if (old->right) {
                    old->right->parent = left->parent;
                    left = old->right;
                } else if (old->left) {
                    old->left->parent = left->parent;
                    left = old->left;
                } else {
                    left = NULL;
                }
                
                delete old;
                return this;
            } else {
                return left->remove(val);
            }
        }
    }
    return this;
}

/*
 * @param stringstream&
 * @return
 *
 * Recorre el árbol de la forma "in-order", para imprimir los elementos en éste.
 *
 */
template <class T>
void TreeNode<T>::inorder(stringstream &aux) const {
    if (left) {
        left->inorder(aux);
    }
    if (aux.tellp() != 1) {
        aux << " ";
    }
    aux << value;
    if (right) {
        right->inorder(aux);
    }
}

/*
 * @param stringstream&
 * @return
 *
 * Recorre el árbol de la forma "pre-order", para imprimir los elementos en éste.
 *
 */
template <class T>
void TreeNode<T>::preorder(stringstream &aux) const {
    aux << value;
    if (left) {
        aux << " ";
        left->preorder(aux);
    }
    if (right) {
        aux << " ";
        right->preorder(aux);
    }
}

/*
 * @param stringstream&
 * @return
 *
 * Recorre el árbol para imprimir los elementos en éste con formato.
 *
 */
template <class T>
void TreeNode<T>::print_tree(stringstream &aux) const {
    if (parent){
        aux << "\n node " << value;
        aux << " parent " << parent->value;
    }else
        aux << "\n root " << value;
    if (left)
        aux << " left " << left->value;
    if (right)
        aux << " right " << right->value;
    aux << "\n";
    
    if (left) {
        left->print_tree(aux);
    }
    if (right) {
        right->print_tree(aux);
    }
}

// Template class SplayTree
template <class T>
class SplayTree {
    private:
        // Atributos (privados)
        TreeNode<T> *root;
        int sze;
    public:
        // Constructor
        SplayTree(): root(NULL), sze(0){};
        
        // Métodos
        void add(T);
        bool find(T);
        void remove(T);
        int size();
        string inorder() const;
        string preorder() const;
        string print_tree() const;
};

/*
 * @param T
 * @return
 *
 * Evalua si la raíz está vacía o no. (En caso de que sí, el valor se agrega a
 * ésta y en caso contrario, primero se llama al método "add()" de la clase
 * TreeNode y luego al "splay" para organizar el árbol con el elemento más nuevo
 * hasta arriba.
 *
 */
template <class T>
void SplayTree<T>::add(T val) {
    if (root) {
        TreeNode<T> *new_node = root->add(val);
        root = root->splay(root, new_node);
    } else {
        root = new TreeNode<T>(val);
    }
    sze++;
}

/*
 * @param T
 * @return bool
 *
 * Primero revisa si el árbol está vacío o no y luego se manda a llamar al
 * método "find()" de la clase TreeNode, para buscar el elemento al ir recorriendo
 * el árbol.
 * Al final se llama a "splay" para organizar el árbol otra vez.
 *
 */
template <class T>
bool SplayTree<T>::find(T val) {
    if (root) {
        TreeNode<T> *to_find = root->find(val);
        root = root->splay(root, to_find);
        
        return (root->value == val);
    } else {
        return false;
    }
}

/*
 * @param T
 * @return
 *
 * Busca si el elemento que se quiere eliminar se encuentra en la estructura o no
 * y lurgo prosigue a eliminarlo, para finalmente ordenar el árbol.
 *
 */
template <class T>
void SplayTree<T>::remove(T val) {
    if (root) {
        if (root->value == val) {
            TreeNode<T> *succesor = root->succesor();
            if (succesor) {
                succesor->right = root->right;
                succesor->left = root->left;
                succesor->parent = NULL;
                
                if (succesor->right)
                    succesor->right->parent = succesor;
                if (succesor->left)
                    succesor->left->parent = succesor;
            }
            
            delete root;
            root = succesor;
        } else {
            TreeNode<T> *to_remove = root->remove(val);
            root = root->splay(root, to_remove);
        }
        sze--;
    }
}

/*
 * @param
 * @return int
 *
 * Regresa el atributo "size", que es el que va guardando el tamaño del árbol.
 *
 */
template <class T>
int SplayTree<T>::size() {
    return sze;
}

/*
 * @param stringstream&
 * @return
 *
 * Si el árbol NO está vacío, se imprimen sus elementos en la forma "in-order".
 *
 */
template <class T>
string SplayTree<T>::inorder() const {
    stringstream aux;
    
    aux << "[";
    if (root)
        root->inorder(aux);
    aux << "]";
    
    return aux.str();
}

/*
 * @param stringstream&
 * @return
 *
 * Si el árbol NO está vacío, se imprimen sus elementos en la forma "pre-order".
 *
 */
template <class T>
string SplayTree<T>::preorder() const {
    stringstream aux;
    
    aux << "[";
    if (root)
        root->preorder(aux);
    aux << "]";
    
    return aux.str();
}

/*
 * @param stringstream&
 * @return
 *
 * Junta ambas formas de impresión, para obtener un solo string en donde se
 * puedan mostrar al mismo tiempo.
 *
 */
template <class T>
string SplayTree<T>::print_tree() const {
    stringstream aux;
    
    aux << inorder() << "\n";
    aux << preorder();
    
    return aux.str();
}

#endif /* splay_h */

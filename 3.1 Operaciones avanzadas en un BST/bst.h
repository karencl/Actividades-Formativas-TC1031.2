/*
 *  bst.h
 *  PrograDataStructureAndAlgorithms
 *
 *  Created by Karen CL on 11/10/21.
*/

#ifndef bst_h
#define bst_h

#include <string>
#include <sstream>

using namespace std;

template <class T> class BST;

// Template class TreeNode
template <class T>
class TreeNode {
    private:
        // Atributos (privados)
        TreeNode *right, *left;
        T value;
    public:
    // Constructores
    TreeNode(T val): value(val), right(NULL), left(NULL){};
    TreeNode(T val, TreeNode<T> *ri, TreeNode<T> *le): value(val), right(ri), left(le){};
    
    // Métodos
    void add(T);
    bool find(T);
    void inOrder(stringstream&) const;
    void preOrder(stringstream&) const;
    void postOrder(stringstream&) const;
    void levelOrder(stringstream&, int) const;
    int height(TreeNode<T>*);
    void ancestors(stringstream&, T);
    int whatlevelamI(T, int&);
};

/*
 * @param T
 * @return
 *
 * Agrega un nuevo nodo (con valor) al árbol, después de comprobar en el método
 * "add()" de la clase BST, que la raíz no está vacía y que el elemento a agregar
 * no se encuentra ya en el árbol.
 *
 */
template <class T>
void TreeNode<T>::add(T val) {
    if (val < value) {
        if (left)
            left->add(val);
        else
            left = new TreeNode<T>(val);
    } else {
        if (right)
            right->add(val);
        else
            right = new TreeNode<T>(val);
    }
}

/*
 * @param T
 * @return bool
 *
 * Busca un elemento en espcífico en el árbol, recorriéndolo por completo hasta
 * encontrarlo o no.
 * Este método se manda a llamar en el método "find()" de la clase BST, tras
 * comprobar que el árbol no está vacío.
 *
 */
template <class T>
bool TreeNode<T>::find(T val) {
    if (val == value)
        return true;
    else if (val < value) {
        if (left)
            return left->find(val);
    }
    else if (val > value) {
        if (right)
            return right->find(val);
    }
    return false;
}

/*
 * @param stringstream&
 * @return
 *
 * Recorre la lista con el método "IN-ORDER", tras comprobar que el árbol no está
 * vacío en el método de "inOrder()" de la clase BST.
 * Aquí se van guardando los valores que hay en cada nodo en la cadena
 * "in_order_aux".
 *
 */
template <class T>
void TreeNode<T>::inOrder(stringstream &in_order_aux) const {
    if (left)
        left->inOrder(in_order_aux);
    
    if (in_order_aux.tellp() != 1)
        in_order_aux << " ";
    
    in_order_aux << value;
    
    if (right)
        right->inOrder(in_order_aux);
}

/*
 * @param stringstream&
 * @return
 *
 * Recorre la lista con el método "PRE-ORDER", tras comprobar que el árbol no está
 * vacío en el método de "preOrder()" de la clase BST.
 * Aquí se van guardando los valores que hay en cada nodo en la cadena
 * "pre_order_aux".
 *
 */
template <class T>
void TreeNode<T>::preOrder(stringstream &pre_order_aux) const {
    pre_order_aux << value;
    
    if (left) {
        pre_order_aux << " ";
        left->preOrder(pre_order_aux);
    }
    
    if (right) {
        pre_order_aux << " ";
        right->preOrder(pre_order_aux);
    }
}

/*
 * @param stringstream&
 * @return
 *
 * Recorre la lista con el método "POST-ORDER", tras comprobar que el árbol no
 * está vacío en el método de "postOrder()" de la clase BST.
 * Aquí se van guardando los valores que hay en cada nodo en la cadena
 * "post_order_aux".
 *
 */
template <class T>
void TreeNode<T>::postOrder(stringstream &post_order_aux) const {
    if (left) {
        left->postOrder(post_order_aux);
        post_order_aux << " ";
    }
    
    if (right) {
        right->postOrder(post_order_aux);
        post_order_aux << " ";
    }
    
    post_order_aux << value;
}

/*
 * @param stringstream&, int
 * @return
 *
 * Recorre la lista con el método "LEVEL-ORDER", tras comprobar que el árbol no
 * está vacío en el método de "levelOrder()" de la clase BST.
 * Aquí se van guardando los valores que hay en cada nodo en la cadena
 * "level_order_aux"; utilizando el nivel en el que nos encontramos, obtenido
 * al usar la función "height()".
 *
 */
template <class T>
void TreeNode<T>::levelOrder(stringstream &level_order_aux, int level) const {
    if (level == 1) {
        if (level_order_aux.tellp() != 1)
            level_order_aux << " ";
        level_order_aux << value;
    } else if (level > 1) {
        level--;
        if (left)
            left->levelOrder(level_order_aux, level);
        if (right)
            right->levelOrder(level_order_aux, level);
    }
}

/*
 * @param TreeNode<T>*
 * @return int
 *
 * Obtiene la altura del árbol, al encontrar las alturas de cada subárbol.
 *
 * Cada que se va bajando un nivel del árbol, se incrementa una de las dos
 * variables que van guardando la altura del lado derecho e izquierdo.
 * Una vez que se termina este proceso, se comparan para ver cuál es más grande
 * y se devuelve como la altura total del árbol. (Se va a devolver 0 en el método
 * "height()" de la clase BST, si el árbol está vacío. Es decir, no se entra a
 * este método de entrada).
 *
 */
template <class T>
int TreeNode<T>::height(TreeNode<T> *node) {
    int ri_height = 0, le_height = 0;
    if (node) {
        ri_height = node->height(node->right);
        le_height = node->height(node->left);
        
        return (le_height > ri_height) ? (le_height + 1) : (ri_height + 1);
    } else {
        return 0;
    }
}

/*
 * @param stringstream&, T
 * @return
 *
 * Ingresa a un stringstream los nodos ancestros de un valor que se nos pasa,
 * después de checar si este existe con la función "find()", llamada desde
 * "ancestors()" de la clase BST.
 *
 */
template <class T>
void TreeNode<T>::ancestors(stringstream &ancestors, T val) {
    if (val < value) {
        if (left) {
            if (ancestors.tellp() != 1)
                ancestors << " ";
            ancestors << value;
            left->ancestors(ancestors, val);
        }
    } else if (val > value) {
        if (right) {
            if (ancestors.tellp() != 1)
                ancestors << " ";
            ancestors << value;
            right->ancestors(ancestors, val);
        }
    }
}

/*
 * @param T, int&
 * @return int
 *
 * Encuentra el nivel en el que se encuentra un nodo, usando una variable que
 * guarda el nivel, al irla aumentando cada que se baja de un nodo a otro, hasta
 * encontrar el valor requerido.
 *
 * Regresa un entero que indica el nivel en el que se encuentra el nodo. Si no lo
 * encuentra, regresa -1;
 *
 */
template <class T>
int TreeNode<T>::whatlevelamI(T val, int &level) {
    if (value == val)
        return level;
    else if (val < value) {
        if (left) {
            level++;
            return left->whatlevelamI(val, level);
        }
    }
    else if (val > value) {
        if (right) {
            level++;
            return right->whatlevelamI(val, level);
        }
    }
    return -1;
}

// Template class BST
template <class T>
class BST {
    private:
        // Atributos (privados)
        TreeNode<T> *root;
    public:
        // Constructor
        BST(): root(NULL){};
    
        // Métodos
        void add(T);
        string visit() const;
        string inOrder() const;
        string preOrder() const;
        string postOrder() const;
        string levelOrder() const;
        int height();
        string ancestors(T);
        int whatlevelamI(T);
};

/*
 * @param T
 * @return
 *
 * Agrega un nuevo nodo (con valor) al árbol, tras revisar que este no esté vacío
 * y que el valor no se encuentre ya en el mismo. (Una vez que se checa eso, se
 * manda a llamar la función "add()" de la clase TreeNode para esto).
 * En caso de estar vacío el árbol, el nuevo nodo se convierte en la raíz.
 *
 */
template <class T>
void BST<T>::add(T val) {
    if (root) {
        if (!root->find(val))
            root->add(val);
    } else {
        root = new TreeNode<T>(val);
    }
}

/*
 * @param
 * @return string
 *
 * Se mandan a llamar todos los métodos de recorridos ("inOrder()", "preOrder()",
 * "postOrder()" y "levelOrder()"), para después agregar todas sus salidas a un
 * stringstream grandote, para regresarlos al llamar esta función.
 *
 */
template <class T>
string BST<T>::visit() const {
    stringstream aux;
    
    aux << preOrder() << "\n";
    aux << inOrder() << "\n";
    aux << postOrder() << "\n";
    aux << levelOrder();
    
    return aux.str();
}

/*
 * @param
 * @return string
 *
 * Se revisa que la raíz del nodo no esté vacía, para posteriormente mandar a
 * llamar al método "inOrder()" de la clase TreeNode, para recorrer el árbol de
 * esta forma e ir guardando los elementos en un stringstream que se le pasa (se
 * va modificando porque se pasa por referencia).
 *
 */
template <class T>
string BST<T>::inOrder() const {
    stringstream in_order_aux;
    
    in_order_aux << "[";
    if (root)
        root->inOrder(in_order_aux);
    in_order_aux << "]";
    
    return in_order_aux.str();
}

/*
 * @param
 * @return string
 *
 * Se revisa que la raíz del nodo no esté vacía, para posteriormente mandar a
 * llamar al método "preOrder()" de la clase TreeNode, para recorrer el árbol de
 * esta forma e ir guardando los elementos en un stringstream que se le pasa (se
 * va modificando porque se pasa por referencia).
 *
 */
template <class T>
string BST<T>::preOrder() const {
    stringstream pre_order_aux;
    
    pre_order_aux << "[";
    if (root)
        root->preOrder(pre_order_aux);
    pre_order_aux << "]";
    
    return pre_order_aux.str();
}

/*
 * @param
 * @return string
 *
 * Se revisa que la raíz del nodo no esté vacía, para posteriormente mandar a
 * llamar al método "postOrder()" de la clase TreeNode, para recorrer el árbol de
 * esta forma e ir guardando los elementos en un stringstream que se le pasa (se
 * va modificando porque se pasa por referencia).
 *
 */
template <class T>
string BST<T>::postOrder() const {
    stringstream post_order_aux;
    
    post_order_aux << "[";
    if (root)
        root->postOrder(post_order_aux);
    post_order_aux << "]";
    
    return post_order_aux.str();
}

/*
 * @param
 * @return string
 *
 * Se revisa que la raíz del nodo no esté vacía, para posteriormente mandar a
 * llamar al método "levelOrder()" de la clase TreeNode, un cierto número de
 * veces; dependiendo de la altura de éste, para recorrerlo todo e ir guardando
 * los elementos en un stringstream que se le pasa (se va modificando porque se
 * pasa por referencia).
 *
 */
template <class T>
string BST<T>::levelOrder() const {
    stringstream level_order_aux;
    int tree_height, level = 1;
    
    level_order_aux << "[";
    if (root) {
        tree_height = root->height(root);
        while (level <= tree_height) {
            root->levelOrder(level_order_aux, level);
            level++;
        }
    }
    level_order_aux << "]";
    
    return level_order_aux.str();
}

/*
 * @param
 * @return int
 *
 * Se revisa que la raíz del nodo no esté vacía, para posteriormente mandar a
 * llamar al método "height()" de la clase TreeNode, para ir recorriendo el árbol
 * y así obtener su altura.
 *
 * Una vez que ésta se obtiene, se regresa un entero con su valor. En caso de que
 * el árbol esté vacío, se regresa 0.
 *
 */
template <class T>
int BST<T>::height() {
    if (root) {
        return root->height(root);
    }
    return 0;
}

/*
 * @param T
 * @return string
 *
 * Se revisa que la raíz del nodo no esté vacía, para posteriormente mandar a
 * llamar al método "find()" de la clase TreeNode, para checar si el elemento del
 * que se quiere obtener el nivel, sí se encuentra en el árbol o no. Si pasa esta
 * condición, ahora si se manda a llamar al método "ancestors()" de la clase
 * TreeNode, en donde se le manda el valor y un stringstream que se va modificando
 * con el fin de ir agregando a éste aquellos valores anteriores del que se manda,
 * para finalmente regresarlos en este método.
 *
 */
template <class T>
string BST<T>::ancestors(T val) {
    stringstream ancestors;
    
    ancestors << "[";
    if (root) {
        if (root->find(val))
            root->ancestors(ancestors, val);
    }
    ancestors << "]";
    
    return ancestors.str();
}

/*
 * @param T
 * @return string
 *
 * Si la el árbol no está vacío y el elemento del que se quiere conocer el nivel
 * en el que se encuentra sí existe en éste (se comprueba usando el método
 * "find()"), se manda a llamar al método "whatlevelamI()" de la clase TreeNode,
 * con una variable que va guardando el nivel actual, con el
 * fin de irla aumentando, cada vez que saltemos de un nivel a otro.
 *
 * Si el valor NO se encuentra en el árbol, se regresa -1 y en caso contrario, la
 * variable "level" que ya contiene el resultado después de la recursividad.
 *
 */
template <class T>
int BST<T>::whatlevelamI(T val) {
    int level = 1;
    if (root) {
        if (root->find(val))
            return level = root->whatlevelamI(val, level);
    }
    return -1;
}

#endif /* bst_h */

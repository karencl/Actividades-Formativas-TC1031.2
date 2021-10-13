# Análisis de complejidad (en el peor de los casos)

#### Función visit:
En este método, tenemos que se mandan a llamar 4 métodos de la clase, antes de regresar el string con los 4 tipos de recorridos.

En cada uno de esos métodos (*inOrder()*, *preOrder()*, *postOrder()* y *levelOrder()*), tenemos una complejidad de **O(n)**, ya que el árbol se recorre por completo, para desplegar cada uno de los datos almacenados en el BST.

Entonces, tenemos que la comlejidad de visit, sería de **O(n^4)**, si tomamos en cuenta que se llama un método tras otro (sería **n**x**n**x**n**x**n**).

#### Función height:
En este método, tenemos que en el peor de los casos la complejidad es de **O(n)** debido a que es probable que en algunos casos tengamos que pasar por cada nodo una vez (*O(1)*), hasta encontrar la parte más baja según esta función; por lo que tendríamos que un recorrido de los **n** elementos del BST.

#### Función ancestors:
En el método *ancestors()*, lo primero que yo hice fue utilizar una función *find()* para corroborar que el elemento del cual se quiere obtener los ancestros, existe. Ya que en caso contrario, no tendría sentido recorrer el arreglo e ir guardando valores.

Entonces... en el método *find()* tenemos que en el peor de los casos vamos a tener que recorrer todo el árbol para buscar un elemento; por lo que tiene una complejidad de **O(n)**. Y posteriormente, cuando se empiezan a guardar los valores, se recorre el árbol nuevamente, siguiendo el camino del elemento que se nos pasa; lo que nos daría una complejidad en el peor de los casos de **O(n)** también.

Si juntamos esto para obtener la complejidad de tiempo total del método *ancestors()*, tenemos que ésta es de **O(n^2)** para la forma en la que yo lo hice.

#### Función whatlevelamI:
Finalmente, lo que se hace en este método es simplemente ir incrementando una variable que guarda el nivel actual, hasta encontrar o no el elemento deseado; lo que se hace mediante un recorrido del árbol.

Hay que tener en cuenta que aquí también se puede llegar a recorrer el árbol por completo, debido a que el elemento que nos pasan puede estar hasta abajo o simplemente no existir (se regresa -1), por lo que su complejidad para el peor de los casos es de **O(n)**.

(Para esta función también se hubiera podido utilizar *find()* para ver si elemento existe en el árbol o no desde un inicio, pero en caso de que así fuera, le daría una complejidad de *O(n^2)* al método *whatlevelamI()* para el peor de los casos, debido a que se recorrería dos veces el árbol.
Evidentemente esto no lo implementé así, ya que tendríamos una peor complejidad para el método).

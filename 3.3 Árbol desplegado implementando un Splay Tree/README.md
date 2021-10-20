# Análisis de complejidad (en el peor de los casos)

#### Método add:
El método "add()" tiene una complejidad de **O(log(n))**, debido no se recorre el árbol por completo, sino que más bien, solo se va pasando de nivel en nivel, según la posición que el elemento a agregar deba tener y haciendo las rotaciones necesarias para ello. (O sea no se recorre todo el árbol en si). 

#### Método find:
El método "find()" también tiene una complejidad de **O(log(n))**, ya que aquí tampoco se va a recorrer el árbol por completo. Es decir, dependiendo el valor del elemento a buscar (mayor o menor al actual), se va a pasar de nivel en nivel, sin necesidad de comparar el valor deseado con el de cada nodo.
  
#### Método remove:
En el método de "remove()" se tiene una complejidad de tiempo de **O(log(n))**, ya que se va haciendo un tipo de búsqueda como en la función "find()", hasta encontrar el elemento a eliminar (sin necesidad de pasar por cada nodo del árbol), para al final borrarlo y acomodar el árbol nuevamente.

#### Método size:
Por último... el método de "size()" en mi programa tiene una complejidad de tiempo constante **O(1)**, debido a que decidí hacer un atributo que fuera guardando el tamaño del árbol conforme se iban agregando o eliminando nodos.

Sin embargo, si se hubiera sacado el tamaño a través de un recorrido del árbol, este método hubiera tenido una comlejidad de tiempo (para el peor de los casos) de *O(n)*, debido a que se hubiera tenido que pasar por cada nodo para irlos contando hasta terminar.

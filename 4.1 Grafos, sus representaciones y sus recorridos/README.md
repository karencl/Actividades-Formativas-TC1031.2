# Análisis de complejidad (en el peor de los casos)

#### Load Graph List:
Este método tiene una complejidad de tiempo (para el peor de los casos) de O(n), ya que depende de la candidad de lineas de datos que contenga el archivo. Es decir, si este tiene 5 lineas de datos, este es el mismo tiempo que se va llevar agregando los vértices y las aristas en cada vuelta.

#### DFS:
Como en este caso se usa la lista de adyacencia, para la complejidad se toman en cuenta la cantidad de vértices/nodos que se van a visitar y la cantidad de aristas que estos tengan. Es por ello, que entonces la complejidad de tiempo se expresaría algo así como O(v) por el número de vértices y O(a) por el número de aristas; teniendo entonces la complejidad completa de: O(v) + O(a).

Esto de igual manera podría ser expresado de la siguiente manera: O(v + a).

#### BFS:
Y en el caso del BFS, al utilizar también una lista de adyacencia, tenemos la misma complejidad de tiempo (para el peor de los casos), que la del DFS. O sea: O(v + a), al tratarse de la cantidad de vértices que se visitan y las aristas en cada una de estas vueltas.

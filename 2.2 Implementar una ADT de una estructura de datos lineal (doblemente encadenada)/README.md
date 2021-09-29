# Análisis de complejidad (en el peor de los casos)

#### Insertar un elemento en una lista doblemente enlazada:
En este ejercicio, un nuevo elemento se inserta al final de la lista. Y al ser esta una lista doblemente enlazada, la complejidad de tiempo es simplemente **O(1)**, o sea: constante.
Esto se debe, a que en este caso se tiene acceso a *tail*, que es el final de la lista; por lo que con una simple operación, se puede agregar un elemento después de esta, sin necesidad de recorrerla como se hacía en el ejercicio pasado de una lista enlazada simple.

#### Encuentra el elemento en una lista doblemente enlazada y devuelve su posición:
En este caso se tiene una complejidad de **O(n)**, debido a que en el peor de los casos, se va a tener que recorrer la lista entera para encontrar el elemento deseado o bien, regresar *-1*, en caso de no hacerlo.
Si por el contrario, el elemento se encontrara al principio (head) o al final (tail) de la lista, se tendría que una complejidad constante, como el mejor de los casos.

#### Actualizar un elemento dentro de una lista doblemente enlazada:
En este caso también se tiene una complejidad de **O(n)**, ya que de igual manera, se va a tener que recorrer la lista completa en el peor de los casos, para encontrar la posición del elemento que se desea actualizar y después cambiar su respectivo valor.

#### Eliminar un elemento dentro de una lista doblemente enlazada de datos segun su posición:
Y por último, el tener que eliminar un elemento en específico de la lista (dependiendo de la posición que nos pasen), resulta en una complejidad de **O(n)**, debido a que, primero se tiene que localizar en ésta y luego eliminarlo; lo que podría llegar a implicar tener que recorrerla por completo.
Cabe destacar que la única manera de obtener una complejidad constante en este caso, es que se pidira simplemente eliminar el último o primer elemento de la lista (por lo mismo de que tenemos acceso a *head* y *tail* directamente).

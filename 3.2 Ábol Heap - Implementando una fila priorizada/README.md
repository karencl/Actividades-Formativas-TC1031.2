# Análisis de complejidad (en el peor de los casos)

#### Función push:
Para insertar un elemento a la fila priorizada, tenemos una complejidad de **O(log(n))**, debido a que no se va a tener que recorrer en sí toda la fila para moverlo hasta el lugar correcto. Es decir, esto va a depender únicamente de la cantidad de niveles que se tenga que mover.

#### Función pop:
Para eliminar un elemento de la fila priorizada, tenemos también una complejidad de **O(log(n))**, debido a que después de que se decrementa el contador y se pasa a la posición 0 el último elemento, se manda a llamar el método de *heapify()* con 0; en donde igual se va recorriendo ésta, pero de nivel en nivel (o sea no se pasa por todos los elementos del árbol).

#### Función top:
Obtener el elemento con mayor prioridad tiene una complejidad de **O(1)**, debido a que simplemente tenemos que accesar con el índice 0 de los datos, cada vez que queramos hacer esto. (Es una operación nada más).

#### Función empty:
El método *empty()* también es una simple operación, que de igual manera tiene una complejidad de **O(1)**, porque solamente se compara si el tamaño actual (count) es igual a 0 o no (y regresa falso o verdadero).

#### Función size:
Finalmente, obtener el tamaño actual de la fila priorizada (count) es una operación constante, debido a que en la clase ya se tiene guardado esto en un atributo; por lo que su complejidad en todos los casos sería **O(1)**.

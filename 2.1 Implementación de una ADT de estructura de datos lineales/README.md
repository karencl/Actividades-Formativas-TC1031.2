# Análisis de complejidad (en el peor de los casos)

#### Insertar un elemento en la estructura de datos:
Como tenemos que insertar cada elemento al final de la lista, tenemos una complejidad de **O(n)**, ya que siempre la vamos a tener que recorrer, para poder realizar este procedimiento.
Solo si la lista estuviera vacía, la complejidad sería *O(1)* porque sería constante (el mejor de los casos). Es decir, no se tendría que recorrer para insertar el elemento, debido a que se agregaría al inicio.
(Si los elementos se insertaran al principio, la complejidad siempre sería *O(1)*).

#### Encuentra el elemento en la estructura y devuelve su posición:
Para esto, tenemos de igual manera una la complejidad de **O(n)**, debido a que en el peor de los, tendríamos que recorrer toda la lista para encontrar un elemento o para regresar *-1* en caso de que no se encuentre este.

#### Actualizar un elemento dentro de la estructura de datos:
Como aquí también se necesita recorrer la lista para llegar a la posición deseada y cambiar el valor de dicho nodo, tenemos que la complejidad es de **O(n)**. Pues en el peor de los casos tendremos que recorrerla toda para lograr esto.

#### Eliminar un elemento dentro de la estructura de datos segun su posición:
Y por último, en este procedimiento también se tiene que recorrer la lista para llegar a la posición indicada y eliminar dicho nodo. Entonces en el peor de los casos, tendremos que recorrer toda la lista y por ende, su complejidad es de **O(n)**.

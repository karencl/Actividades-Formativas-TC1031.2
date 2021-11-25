# Análisis de complejidad (en el peor de los casos)

#### Put:
Al insertar un nuevo "Key, Value" en el hash, se tiene que tomar en cuenta el tamaño de este en el peor de los casos. Esto pasa debido a que nos podemos encontrar con varias colisioes en una sola vuelta de inserción y por ende, necesitaríamos buscar posibles soluciones (usando prueba cuadrática en este caso), para poder colocar el nuevo "Key, Value". 
Entonces... podríamos decir que en el *peor* escenario, la complejidad del método *put()* es de **O(n)**. (Aunque es más facil encontrarse con el caso promedio).

#### Get:
En el caso del método *get()*, tenemos que la complejidad en el peor de los casos sería de **O(n)**, debido a que se podría llegar a recorrer toda la tabla hash, para encontrar el valor de una llave.

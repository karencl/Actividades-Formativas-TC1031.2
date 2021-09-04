# Análisis de complejidad (en el peor de los casos)

#### Ordenamiento por método de selección:

- Su complejidad es de O(n^2), debido a que tiene dos ciclos. 
- Cada uno de estos se recorren **n** pasos, en donde se van incrementando los contadores de 1 en 1, para encontrar el elemento más chico en cada vuelta del ciclo interno e intercambiarlo por el elemento que toque en el ciclo externo. 

#### Ordenamiento por método burbuja:

- Su complejidad también es de O(n^2), debido a que cuenta con dos ciclos para ordenar el vector.
- En cada uno de estos se recorren **n** pasos, en donde en el ciclo externo se va decrementando el contador de 1 en 1 y por el contrario en el ciclo interior se va incrementando el contador de 1 en 1; donde se busca intercambiar las posiciones de los elementos, si el elemento que toque, es mayor al que le sigue, con el fin de llevar los más grandes hasta el final. 

#### Ordenamiento por método merge:

- Su complejidad es O(n log(n)), debido a que en cada llamada recurisva vamos a dividir el arreglo a la mitad, o sea: **O(log(n))** y posteriormente para juntarlos (hacer el merge), vamos a necesitar hacerlo para los n elementos (subarrays) que obtuvimos en cada vuelta, o sea: **O(n)**.

#### Búsqueda binaria:

- Su complejidad es de O(log(n)), debido a que en cada vuelta, se va a "dividir" el arreglo a la mitad, con el fin de analizar si el elemento deseado se encuentra en la parte izquierda o derecha de este.


- Hay que considerar que para este método se utilizó otro método de ordenamiento (el de selección), el cual tiene una complejidad de O(n^2) y por ende, a pesar de que el método de búsqueda binaria tiene una complejidad de O(log(n)), al ser odenado por éste, el método en general tendría una complejidad de O(n^2 log(n)).
- *El vector ordenado era una precondición del ejercicio*.

#### Búsqueda secuencial:

- Su complejidad es simplemente de O(n), debido a que se hacen **n** vueltas en el ciclo, con el fin de comparar el elemento buscado, con cada elemento que hay en el vector, hasta que sea o no sea encontrado.

/*
 *  funciones.h
 *  PrograDataStructureAndAlgorithms
 *
 *  Created by Karen CL on 22/08/21.
*/

#ifndef funciones_h
#define funciones_h

// Clase Funciones
class Funciones {
    public:
        // Constructor
        Funciones(){};
    
        // Métodos requeridos
        int sumaIterativa(int);
        int sumaRecursiva(int);
        int sumaDirecta(int);
};

/*
 * @param int
 * @return int
 *
 * Hace la suma iterativa del número que se le pasa cpn un ciclo while, hasta que
 * éste llega a 0 (que es cuando se sale del ciclo y regresa la suma).
 *
 */
int Funciones::sumaIterativa(int n) {
    int sum = 0;
    while (n) {
        sum += n;
        n--;
    }
    return sum;
}

/*
 * @param int
 * @return int
 *
 * Hace la suma recursiva del número que se le pasa, llamándose a sí misma hasta
 * que "n" llega a 1.
 * (Primero verifica que el número no sea 0, ya que en ese caso, se retorna 0 de
 * entrada).
 *
 */
int Funciones::sumaRecursiva(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    else
        return (n + sumaIterativa(n-1));
}

/*
 * @param int
 * @return int
 *
 * Hace la suma directa (sin ciclos ni recursividad), utilizando simples
 * operaciones, dependiendo si el número que se le pasa es par o impar.
 * (El 0 se maneja como impar en este caso, pero el resultado sería el mismo).
 *
 */
int Funciones::sumaDirecta(int n) {
    if (n % 2 == 0)
        return ((n * n / 2) + (n / 2));
    else
        return (n * ((n / 2) + 1));
}


#endif /* funciones_h */

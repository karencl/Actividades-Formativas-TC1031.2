/*
 *  graph.h
 *  PrograDataStructureAndAlgorithms
 *
 *  Created by Karen CL on 8/11/21.
 */

#ifndef graph_h
#define graph_h

#include <string>
#include <stdio.h>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>

using namespace std;

// Clase Graph
class Graph {
    private:
        // Atributos privados
        int edgesList;
        int edgesMat;
        int nodes;
        vector<int> *adjList;
        int *adjMatrix;
    public:
        // Constructores
        Graph(): edgesList(0), edgesMat(0){};
    
        // Métodos públicos para graph matrix
        void loadGraphMat(string, int, int);
        void addEdgeAdjMatrix(int, int);
        string printAdjMat();
        string printAdjMat_clean();
    
        // Métodos públicos para graph list
        void loadGraphList(string, int, int);
        void addEdgeAdjList(int, int);
        string printAdjList();
        void sortAdjList();
        
        string DFS(int, int);
        void dfsHelper(int, int, stack<int>&, list<int>&, vector<vector<int>>&, stringstream&);
        string BFS(int, int);
        void bfsHelper(int, int, queue<int>&, list<int>&, vector<vector<int>>&, stringstream&);
        void printPath(vector<vector <int>>&, int, int, stringstream&);
        void printVisited(list<int>, stringstream&);
        bool contains(list<int>, int);
};

/*
 * @param string, int, int
 * @return
 *
 * Carga los datos del archivo en el grafo (la matriz)
 *
 */
void Graph::loadGraphMat(string file_name, int a, int b){
    adjMatrix = new int [a*b];
    nodes = a;
    for (int i = 0; i < a*b; i++) {
        adjMatrix[i] = 0;
        string line;
        ifstream file (file_name);
        int u, v;
        if (file.is_open()){
            while (getline(file, line)){
                u = stoi(line.substr(1,1));
                v = stoi(line.substr(4,1));
                addEdgeAdjMatrix(u,v);
            }
            file.close();
        } else {
            cout << "Unable to open file";
        }
    }
}

/*
 * @param string, int, int
 * @return
 *
 * Carga los datos del archivo en el grafo (la lista)
 *
 */
void Graph::loadGraphList(string file_name, int a, int b) {
    nodes = a;
    adjList = new vector<int>[nodes];
    
    string line;
    ifstream file (file_name);
    int u, v;
    if (file.is_open()){
        while (getline(file, line)){
            u = stoi(line.substr(1,1));
            v = stoi(line.substr(4,1));
            addEdgeAdjList(u, v);
        }
        file.close();
    } else {
        cout << "Unable to open file";
    }
}

/*
 * @param int, int
 * @return
 *
 * Hace una conección entre los dos valores de los nodos que se le pasan (en la
 * matriz).
 *
 */
void Graph::addEdgeAdjMatrix(int u, int v){
    adjMatrix[u*nodes+v] = 1;
    adjMatrix[v*nodes+u] = 1;
    edgesMat++;
}

/*
 * @param int, int
 * @return
 *
 * Hace una conección entre los dos valores de los nodos que se le pasan (en la
 * lista).
 *
 */
void Graph::addEdgeAdjList(int u, int v){
    adjList[u].push_back(v);
    adjList[v].push_back(u);
    edgesList++;
}

/*
 * @param
 * @return string
 *
 * Imprime el grafo (la lista)
 *
 */
string Graph::printAdjList(){
    sortAdjList();
    stringstream aux;
    
    for (int i = 0; i < nodes; i++){
        aux << "vertex " << i << " :";
        for (int j = 0; j < adjList[i].size(); j++) {
                aux << " " << adjList[i][j];
        }
        aux << " ";
    }
    
    return aux.str();
}

/*
 * @param
 * @return string
 *
 * Imprime el grafo (la matriz)
 *
 */
string Graph::printAdjMat(){
    stringstream aux;
    
    for (int i = 0; i < nodes; i++){
       for (int j = 0; j < nodes; j++){
             aux << adjMatrix[i*nodes+j] << " ";
         }
    }
    
    return aux.str();
}

/*
 * @param
 * @return
 *
 * Ordena el grafo (la lista)
 *
 */
void Graph::sortAdjList() {
    for (int i = 0; i < nodes; i++) {
        sort(adjList[i].begin(), adjList[i].end());
    }
}

/*
 * @param
 * @return string
 *
 * Imprime el grafo de forma limpia (la matriz)
 *
 */
string Graph::printAdjMat_clean(){
    stringstream aux;
    aux << "\n nodes \t|";
    for (int i = 0; i < nodes; i++){
            aux << "\t" << i ;
    }
    aux << "\n";
    for (int i = 0; i < nodes; i++){
            aux << "__________";
    }
    aux << "\n";
    for (int i = 0; i < nodes; i++){
         aux << i << "\t|";
       for (int j = 0; j < nodes; j++){
             aux << "\t" << adjMatrix[i*nodes+j];
         }
       aux << "\n";
  }
    return aux.str();
}

/*
 * @param int, int
 * @return string
 *
 * Inicializa las variables para realizar el DFS a partir de un nodo inicial y el
 * nodo meta (al que se quiere llegar).
 * Regresa un string con el path y los nodos visitados, desde el nodo_inicial
 * hasta el nodo_meta.
 *
 */
string Graph::DFS(int nodo_inicial, int nodo_meta) {
    stringstream aux;
    
    stack<int> my_stack;
    list<int> visited;
    vector<vector<int>> paths(nodes, vector<int>(1, -1));
    my_stack.push(nodo_inicial);
    
    dfsHelper(nodo_inicial, nodo_meta, my_stack, visited, paths, aux);
    printPath(paths, nodo_inicial, nodo_meta, aux);
    
    return aux.str();
}

/*
 * @param int, int, stack<int>&, list<int>&, vector<vector<int>>&, stringstream&
 * @return
 *
 * Esta es una función recursiva del algoritmo "dfs", que ace el recorrido por el
 * grafo buscando el nodo_meta.
 * Se van gardando los paths y los nodos visitados en otras estructuras, con el
 * fin de imprimirlos posteriormente.
 *
 */
void Graph::dfsHelper(int current_node, int nodo_meta, stack<int> &my_stack, list<int> &visited, vector<vector<int>> &paths, stringstream &aux) {
    
    if (current_node == nodo_meta) {
        printVisited(visited, aux);
    } else if (my_stack.empty()) {
        aux << "";
    } else {
        current_node = my_stack.top();
        my_stack.pop();
        visited.push_back(current_node);
        for (int  i = 0; i < adjList[current_node].size(); i++) {
            if (!contains(visited, adjList[current_node][i])) {
                my_stack.push(adjList[current_node][i]);
                paths[adjList[current_node][i]][0] = current_node;
            }
        }
        dfsHelper(current_node, nodo_meta, my_stack, visited, paths, aux);
    }
}

/*
 * @param int, int
 * @return string
 *
 * Inicializa las variables para realizar el BFS a partir de un nodo inicial y el
 * nodo meta (al que se quiere llegar).
 * Regresa un string con el path y los nodos visitados, desde el nodo_inicial
 * hasta el nodo_meta.
 *
 */
string Graph::BFS(int nodo_inicial, int nodo_meta) {
    stringstream aux;
    
    queue<int> my_queue;
    list<int> visited;
    vector<vector<int>> paths(nodes, vector<int>(0));
    my_queue.push(nodo_inicial);
    
    bfsHelper(nodo_inicial, nodo_meta, my_queue, visited, paths, aux);
    printPath(paths, nodo_inicial, nodo_meta, aux);
    
    return aux.str();
}

/*
 * @param int, int, queue<int>&, list<int>&, vector<vector<int>>&, stringstream&
 * @return
 *
 * Esta es una función recursiva del algoritmo "bfs", que ace el recorrido por el
 * grafo buscando el nodo_meta.
 * Se van gardando los paths y los nodos visitados en otras estructuras, con el
 * fin de imprimirlos posteriormente.
 *
 */
void Graph::bfsHelper(int current_node, int nodo_meta, queue<int> &my_queue, list<int> &visited, vector<vector<int>> &paths, stringstream &aux) {
    
    if (current_node == nodo_meta) {
        printVisited(visited, aux);
    } else if (my_queue.empty()) {
        aux << "";
    } else {
        current_node = my_queue.front();
        my_queue.pop();
        visited.push_back(current_node);
        for (int  i = 0; i < adjList[current_node].size(); i++) {
            if (!contains(visited, adjList[current_node][i])) {
                my_queue.push(adjList[current_node][i]);
                paths[adjList[current_node][i]].push_back(current_node);
            }
        }
        bfsHelper(current_node, nodo_meta, my_queue, visited, paths, aux);
    }
}

/*
 * @param lis<int>, stringstream
 * @return
 *
 * Imprime los nodos que fueron visitados (guardados en una lista), para obtener
 * el camino del nodo_inicial al nodo_meta.
 *
 */
void Graph::printVisited(list<int> visited, stringstream &aux) {
    aux << "visited: ";
    while (!visited.empty()){
        aux << visited.front() << " ";
        visited.pop_front();
    }
}

/*
 * @param vector<vector<int>>&, int, int, stringstream
 * @return
 *
 * Imprime el path del recorrido desde el nodo_incial, hasta el nodo_meta.
 *
 */
void Graph::printPath(vector<vector <int>> &path, int nodo_inicial, int nodo_meta, stringstream &aux) {
    aux << "path: ";
    int node = path[nodo_meta][0];
    
    stack<int> reverse;
    reverse.push(nodo_meta);
    
    while (node != nodo_inicial) {
        reverse.push(node);
        node = path[node][0];
    }
    
    reverse.push(nodo_inicial);
    while (!reverse.empty()) {
        aux << reverse.top();
        reverse.pop();
        if (!reverse.empty())
            aux << " ";
    }
}

/*
 * @param list<int>, int
 * @return bool
 *
 * Checa si un nodo se encuentra en la lista que se pasa.
 *
 */
bool Graph::contains(list<int> lst, int node) {
    list<int>::iterator it;
    it = find(lst.begin(), lst.end(), node);
    
    return (it != lst.end());
}

#endif /* graph_h */

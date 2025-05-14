#include <iostream>
#include <vector>
#include "Grafo.h"

int main() {
    Grafo<int> grafo;

    // Agregamos vértices (identificados por índices)
    grafo.agregarVertice(0);
    grafo.agregarVertice(1);
    grafo.agregarVertice(2);
    grafo.agregarVertice(3);
    grafo.agregarVertice(4);

    // Conectamos los vértices con pesos
    grafo.conectar(0, 1, 10);
    grafo.conectar(0, 3, -30); 
    grafo.conectar(0, 4, 100);
    grafo.conectar(1, 2, -50); 
    grafo.conectar(2, 4, 10);
    grafo.conectar(3, 2, 20);
    grafo.conectar(3, 4, -60); 

    // Imprimimos la matriz de adyacencia
    std::cout << "Matriz de adyacencia:\n";
    grafo.imprimir();
    
    // Ejecutamos el algoritmo de Floyd-Warshall
    auto [distancias, predecesores] = grafo.floydWarshall();

    // Imprimimos la matriz de distancias más cortas entre todos los pares de vértices
    std::cout << "\nMatriz de distancias más cortas (Floyd-Warshall):\n";
    grafo.imprimirMatrizDistancias(distancias);

    // Pedimos el punto de origen y destino
    int origen, destino;
    std::cout << "\nIntroduce el vértice de origen: ";
    std::cin >> origen;
    std::cout << "Introduce el vértice de destino: ";
    std::cin >> destino;

    // Obtenemos la ruta más corta
    std::vector<int> ruta = grafo.obtenerRutaMasCorta(origen, destino, predecesores);
    
    // Imprimimos la ruta más corta y la distancia total
    if (!ruta.empty()) {
        std::cout << "Ruta más corta de " << origen << " a " << destino << ": ";
        for (int nodo : ruta) {
            std::cout << nodo << " ";
        }
        std::cout << "\nDistancia total: " << distancias[origen][destino] << std::endl;
    } else {
        std::cout << "No hay ruta entre " << origen << " y " << destino << std::endl;
    }

    return 0;
}

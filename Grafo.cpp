/*******************************************
Fecha: 14 de mayo 2025
Autor: Santiago Camargo Trujillo
Tema: Taller Grafos
Estructuras de datos
******************************************/
#include "Grafo.h"
#include <limits>
#include <iostream>
#include <algorithm>

// Constructor
template<class T>
Grafo<T>::Grafo() {}

// Agregar vértice
template<class T>
void Grafo<T>::agregarVertice(const T& vertice) {
    vertices.push_back(vertice);

    // Expandimos la matriz de adyacencia
    for (auto& fila : adyacencia) {
        fila.push_back(std::numeric_limits<float>::max()); // Nueva columna con "infinito"
    }
    adyacencia.push_back(std::vector<float>(vertices.size(), std::numeric_limits<float>::max())); // Nueva fila con "infinito"

    // Aseguramos que la diagonal principal sea 0 (sin costo para ir al mismo nodo)
    adyacencia[vertices.size() - 1][vertices.size() - 1] = 0;
}

// Conectar vértices
template<class T>
void Grafo<T>::conectar(int i, int j, float peso) {
    if (i >= 0 && i < vertices.size() && j >= 0 && j < vertices.size()) {
        adyacencia[i][j] = peso;
    }
}

// Imprimir matriz de adyacencia
template<class T>
void Grafo<T>::imprimir() const {
    for (const auto& fila : adyacencia) {
        for (const auto& elemento : fila) {
            if (elemento == std::numeric_limits<float>::max()) {
                std::cout << "∞ "; // Representación de "infinito"
            } else {
                std::cout << elemento << " ";
            }
        }
        std::cout << std::endl;
    }
}

// Algoritmo de Floyd-Warshall
template<class T>
std::pair<std::vector<std::vector<float>>, std::vector<std::vector<int>>> Grafo<T>::floydWarshall() const {
    int n = vertices.size();
    std::vector<std::vector<float>> dist = adyacencia;
    std::vector<std::vector<int>> predecesores(n, std::vector<int>(n, -1));

    // Inicializamos la matriz de predecesores
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j && dist[i][j] != std::numeric_limits<float>::max()) {
                predecesores[i][j] = i;
            }
        }
    }

    // Aplicamos el algoritmo de Floyd-Warshall
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] != std::numeric_limits<float>::max() && dist[k][j] != std::numeric_limits<float>::max()) {
                    float nuevaDistancia = dist[i][k] + dist[k][j];
                    if (dist[i][j] > nuevaDistancia) {
                        dist[i][j] = nuevaDistancia;
                        predecesores[i][j] = predecesores[k][j];
                    }
                }
            }
        }
    }

    return {dist, predecesores};
}

// Obtener la ruta más corta de origen a destino
template<class T>
std::vector<int> Grafo<T>::obtenerRutaMasCorta(int origen, int destino, const std::vector<std::vector<int>>& predecesores) const {
    std::vector<int> ruta;
    if (predecesores[origen][destino] == -1) {
        return ruta; // No hay ruta
    }

    // Reconstruir la ruta más corta
    for (int v = destino; v != origen; v = predecesores[origen][v]) {
        ruta.push_back(v);
    }
    ruta.push_back(origen);
    std::reverse(ruta.begin(), ruta.end()); // La ruta está en orden inverso
    return ruta;
}

// Imprimir la matriz de distancias de Floyd-Warshall
template<class T>
void Grafo<T>::imprimirMatrizDistancias(const std::vector<std::vector<float>>& dist) const {
    for (const auto& fila : dist) {
        for (const auto& elemento : fila) {
            if (elemento == std::numeric_limits<float>::max()) {
                std::cout << "∞ "; // Representación de "infinito"
            } else {
                std::cout << elemento << " ";
            }
        }
        std::cout << std::endl;
    }
}





















// Plantilla para que el código compile correctamente en archivos separados
template class Grafo<int>;

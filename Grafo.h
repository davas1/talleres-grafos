/*******************************************
Fecha: 14 de mayo 2025
Autor: Santiago Camargo Trujillo
Tema: Taller Grafos
Estructuras de datos
******************************************/
#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include <iostream>
#include <limits>

template<class T>
class Grafo {
public:
    // Constructor
    Grafo();

    // Agregar vértice
    void agregarVertice(const T& vertice);

    // Conectar vértices
    void conectar(int i, int j, float peso);

    // Imprimir la matriz de adyacencia
    void imprimir() const;

    // Algoritmo de Floyd-Warshall
    std::pair<std::vector<std::vector<float>>, std::vector<std::vector<int>>> floydWarshall() const;

    // Obtener la ruta más corta de origen a destino
    std::vector<int> obtenerRutaMasCorta(int origen, int destino, const std::vector<std::vector<int>>& predecesores) const;

    // Imprimir la matriz de distancias
    void imprimirMatrizDistancias(const std::vector<std::vector<float>>& dist) const;

    //
private:
    std::vector<T> vertices;              // Lista de vértices
    std::vector<std::vector<float>> adyacencia; // Matriz de adyacencia
};

#endif // GRAFO_H

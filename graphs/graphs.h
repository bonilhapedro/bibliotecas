#ifndef GRAPHS_H
#define GRAPHS_H

#include <stdio.h>
#include <stdlib.h>

#define vertex int

struct graph {
    int V;     
    int A;     
    int **adj; 
};
typedef struct graph *Graph;


// inicializa um grafo com V vértices
Graph GRAPHinit(int V);

// insere uma aresta com peso no grafo
void GRAPHinsertArc(Graph G, vertex v, vertex w, int peso);

// remove uma aresta do grafo
void GRAPHremoveArc(Graph G, vertex v, vertex w);

// exibe o grafo
void GRAPHshow(Graph G);

#endif // GRAPHS_H

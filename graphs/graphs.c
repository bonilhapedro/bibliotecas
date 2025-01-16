#include "graphs.h"

#define vertex int

struct graph {
   int V;
   int A;
   int **adj;
};
typedef struct graph *Graph;

Graph GRAPHinit(int V) { 
   Graph G = malloc(sizeof *G);
   G->V = V;
   G->A = 0;
   G->adj = MATRIXint(V, V, -1); // inicializa com -1 (sem aresta)
   return G;
}

static int **MATRIXint(int r, int c, int val) { 
   int **m = malloc(r * sizeof(int *));
   for (vertex i = 0; i < r; ++i) 
      m[i] = malloc(c * sizeof(int));
   for (vertex i = 0; i < r; ++i)
      for (vertex j = 0; j < c; ++j)
         m[i][j] = val;
   return m;
}

void GRAPHinsertArc(Graph G, vertex v, vertex w, int peso) { 
   if (G->adj[v][w] == -1) {  // só insere a aresta se ainda não existir
      G->adj[v][w] = peso;
      G->A++;
   } else {
      G->adj[v][w] = peso; // se já existir, atualiza o peso
   }
}

void GRAPHremoveArc(Graph G, vertex v, vertex w) { 
   if (G->adj[v][w] != -1) {  // só remove se a aresta existir
      G->adj[v][w] = -1;
      G->A--;
   }
}


void GRAPHshow(Graph G) { 
   for (vertex v = 0; v < G->V; ++v) {
      printf("%2d:", v);
      for (vertex w = 0; w < G->V; ++w)
         if (G->adj[v][w] != -1) // se houver aresta, exibe o peso
            printf(" (%2d,%d)", w, G->adj[v][w]);
      printf("\n");
   }
}

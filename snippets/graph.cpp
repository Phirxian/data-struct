#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Structure pour le graphique
typedef struct {
  int numVertices;
  int graph[MAX_VERTICES][MAX_VERTICES];
  bool visited[MAX_VERTICES];
} Graph;

// Fonction pour initialiser le graphique
void initGraph(Graph* graph, int numVertices) {
  graph->numVertices = numVertices;
  for (int i = 0; i < numVertices; i++) {
    for (int j = 0; j < numVertices; j++) {
      graph->graph[i][j] = 0;
    }
    graph->visited[i] = false;
  }
}

// Fonction pour ajouter une arête au graphique
void addEdge(Graph* graph, int src, int dest) {
  graph->graph[src][dest] = 1;
  // Pour un graphique non orienté, décommentez la ligne suivante
  // graph->graph[dest][src] = 1;
}

// Fonction pour effectuer la recherche en profondeur (DFS)
void DFS(Graph* graph, int vertex) {
  printf("%d ", vertex); // Afficher le sommet actuel
  graph->visited[vertex] = true; // Marquer le sommet comme visité

  // Visiter tous les sommets adjacents non visités
  for (int i = 0; i < graph->numVertices; i++) {
    if (graph->graph[vertex][i] == 1 && !graph->visited[i]) {
      DFS(graph, i);
    }
  }
}

// Fonction pour effectuer la recherche en largeur (BFS)
void BFS(Graph* graph, int vertex) {
  bool visited[MAX_VERTICES];
  for (int i = 0; i < graph->numVertices; i++) {
    visited[i] = false;
  }

  visited[vertex] = true;
  printf("%d ", vertex); // Afficher le sommet actuel

  int queue[MAX_VERTICES];
  int front = 0, rear = 0;
  queue[rear++] = vertex;

  while (front < rear) {
    int currentVertex = queue[front++];
    for (int i = 0; i < graph->numVertices; i++) {
      if (graph->graph[currentVertex][i] == 1 && !visited[i]) {
        visited[i] = true;
        printf("%d ", i); // Afficher le sommet actuel
        queue[rear++] = i;
      }
    }
  }
}

// Fonction pour compter les composants connexes
int countConnectedComponents(Graph* graph) {
  int count = 0;
  for (int i = 0; i < graph->numVertices; i++) {
    if (!graph->visited[i]) {
      DFS(graph, i);
      count++;
      printf("\n"); // Nouvelle ligne après chaque composant
    }
  }
  return count;
}

int main() {
  Graph graph;
  int numVertices = 8;

  initGraph(&graph, numVertices);

  // Création d'un graphique non connecté avec plusieurs composants
  addEdge(&graph, 0, 1);
  addEdge(&graph, 1, 2);
  addEdge(&graph, 2, 0);

  addEdge(&graph, 3, 4);
  addEdge(&graph, 4, 5);
  addEdge(&graph, 5, 3);

  addEdge(&graph, 6, 7);

  printf("Graphique non connecté avec plusieurs composants:\n");
  printf("Recherche en profondeur pour compter les composants:\n");
  int components = countConnectedComponents(&graph);

  // Réinitialiser les sommets visités pour BFS
  for (int i = 0; i < numVertices; i++) {
    graph.visited[i] = false;
  }

  printf("\nRecherche en largeur (BFS) pour chaque composant:\n");
  for (int i = 0; i < numVertices; i++) {
    if (!graph.visited[i]) {
      printf("Composant %d: ", i + 1);
      BFS(&graph, i);
      printf("\n");
    }
  }

  printf("\nNombre total de composants connexes: %d\n", components);

  return 0;
}

<h1 class="text-center" style="position: relative;top: 50%;">Niveau 2</h1>
<p class="text-center" style="position: relative;top: 50%;">FIFO et LIFO</p>

---
transition: slide-left
---
## Introduction à FIFO

FIFO est un principe de gestion des données où le premier élément ajouté est le premier à être traité.
Cela ressemble à une file d'attente dans la vie réelle, où la personne qui arrive en premier est servie en premier.

| Opération | Description |
|-----------|-------------|
| **Enqueue** | Ajouter un élément à la fin de la file. |
| **Dequeue** | Supprimer l'élément du début de la file. |
| **Peek**   | Voir l'élément du début sans le supprimer. |

---
transition: slide-left
---
### Cas d'utilisation de la Pile

- Gestion de l'historique de navigation dans les navigateurs web
- Fonctionnalités "Annuler/Rétablir" dans les éditeurs de texte (2 piles)
- Appel de fonctions et gestion de la récursion (call stack)
- Évaluation d'expressions mathématiques (infixes)
- Parcours de graph en profondeur (Depth-first search)
- Analyse syntaxique : (syntaxe des programmes - parenthèses et les accolades)

---
transition: slide-left
---
## Introduction à LIFO

LIFO est un principe de gestion des données où le dernier élément ajouté est le premier à être traité.
Cela ressemble à une pile de livres, où le livre posé en dernier est le premier à être retiré.

| Opération | Description |
|-----------|-------------|
| **Push**  | Ajouter un élément au sommet de la pile. |
| **Pop**   | Supprimer l'élément du sommet de la pile. |
| **Peek**  | Voir l'élément du sommet sans le supprimer. |

---
transition: slide-left
---
### Cas d'utilisation de la File

- Gestion des processus dans les systèmes d'exploitation
- Gestion des impressions
- Recherche en largeur (BFS) (explorer les graphes niveau par niveau)
- Gestion des appels dans les centres d'appel
- Tampon de messages dans les systèmes de communication

---
transition: slide-left
---

## Quelles sont les différences ?


| Caractéristique | FIFO | LIFO |
|-----------------|------|------|
| **Ordre de Traitement** | Premier entré, premier sorti | Dernier entré, premier sorti |
| **Utilisations** | Planification des tâches, messagerie | Appels de fonctions, annulation |
| **Implémentation** | File (Queue) | Piles (Stack) |

On peut implémenter LIFO/FIFO de différentes façons :
- Avec un tableau (gestion des réallocations potentielles)
- Avec une liste chainée (problème de cache miss)

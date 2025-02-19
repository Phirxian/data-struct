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

On peut implémenter un FIFO de déffirentes façon
- Avec un buffer (gestion des reallocation potentiel)
- Avec une list chainé

Écrire un code de test de vos structure de donnée permettant de faire une FIFO

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

On peut implémenter un LIFO de différentes façons :
- Avec un tableau (gestion des réallocations potentielles)
- Avec une liste chainée

Écrire un code de test de votre structure de données permettant de faire une LIFO

---
transition: slide-left
---

## Quelles sont les différences ?


| Caractéristique | FIFO | LIFO |
|-----------------|------|------|
| **Ordre de Traitement** | Premier entré, premier sorti | Dernier entré, premier sorti |
| **Utilisations** | Planification des tâches, messagerie | Appels de fonctions, annulation |
| **Implémentation** | Files | Piles |
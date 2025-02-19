<h1 class="text-center" style="position: relative;top: 50%;">Niveau 1</h1>
<p class="text-center" style="position: relative;top: 50%;">Tableaux et listes</p>

---
transition: slide-left
---

## Tableau statique

Les tableaux statiques sont des tableaux dont la taille est fixée au moment de la compilation.
- Ont peu calculer la taille des tableaux statique à l'aide de `sizeof(localArray)/sizeof(*localArray)`
- Attention l'espace de stockage diffère et peu dans certain cas être `read only`

```cpp
// stockage dans .text / might be read only
static const char DATA[] = "SOME DATA";
// stockage dans .data
int globalArray[10] = {1, 2, 3, 4, 5, 0, 0, 0, 0, 0};
// stockage dans .bss
int globalUninitializedArray[10];
// stockage dans .rodata ! / read only
const int globalConstArray[] = {1, 2, 3, 4, 5};
int data[] __attribute__((section("rodata"))) = {1, 2, 3, 4, 5};

int main() {
    // stockage dans .data
    static int localStaticArray[10] = {1, 2, 3, 4, 5, 0, 0, 0, 0, 0};
    // stockage dans .bss
    static int localStaticUninitializedArray[10];
    // dans une fonction, stockage dans la stack
    int localArray[10];
}
```

---
transition: slide-left
---

### Tableau statique

**Sur une architecture 64bits :** Que fait le code suivant ? 


```cpp
#include <stdio.h>

void afficheTaille(int *array) {
  printf("%ld\n", sizeof(array));
  printf("%ld\n", sizeof(array)/sizeof(*array));
}

int main() {
  int localArray[10];
  printf("%ld\n", sizeof(localArray));
  printf("%ld\n", sizeof(localArray)/sizeof(*localArray));
  afficheTaille(localArray);
}
```

---
transition: slide-left
---
## Tableau dynamique

Les tableaux dynamiques sont des tableaux dont la taille est déterminée au moment de l'exécution.

- La mémoire des tableaux dynamiques est allouée à l'aide de fonctions d'allocation
- `malloc()`, `calloc()` et `realloc()`.
- Attention aux fuite mémoire, ne pas oublié `free()`
- Il faut stocker la taille du segment associé, ou avoir une méthode de détection

<br>

```cpp
unsigned int size = 10 * sizeof(int);
// stockage dans la heap
int *array = malloc(size);
// attention, malloc may fail (return NULL)
...
unsigned int new_size = 100 * sizeof(int);
int* temp = realloc(array, new_size);
// attention, realloc may fail (return NULL, @array still valid)
array = temp;
...
free(array);
```

---
transition: slide-left
---

## Liste chainées

- **Concept :**
  - On associe une donnée avec un ou plusieurs pointeurs
- **Avantages :**
  - Insertion et suppression efficaces : En modifiant les pointeurs des nœuds adjacents.
  - Utilisation "efficace" de la mémoire : Seule la mémoire "nécessaire" est allouée
- **Inconvénients :**
  - Recherche très lente : Doit parcourir la liste séquentiellement (mémoire non contigue).
  - Peu d'optimisation possible

Pensé a utiliser une structure pour géré votre liste :

```cpp
typedef struct LinkedList {
    struct Node* head;
    struct Node* tail;
    // etc
} LinkedList;
```

---
transition: slide-left
---
## Liste chainées simple

- **Définition :** Chaque élément (ou nœud) pointe vers le suivant.
- **Head :** Le premier élément de la list (NULL si vide)
- **Tail :** Le dernier élément de la list (NULL si vide, next = NULL) 

```cpp
typedef struct IntNode {
    int data;
    struct IntNode* next;
} IntNode;

typedef struct UserDataNode {
    int size;
    void *data;
    struct UserDataNode* next;
} UserDataNode;
```

---
transition: slide-left
---
## Liste chainées double

- **Définition :** Chaque élément (ou nœud) pointe vers le suivant et le précédent.
- **Mémoire :** Consomme plus de mémoire.
- **Head :** Le premier élément de la list (prev = NULL)
- **Tail :** Le dernier élément de la list (next = NULL) 

```cpp
typedef struct IntNode {
    int data;
    struct IntNode* next;
    struct IntNode* prev;
} IntNode;

typedef struct UserDataNode {
    int size;
    void *data;
    struct UserDataNode* next;
    struct UserDataNode* prev;
} UserDataNode;
```

---
transition: slide-left
---

## Liste chainées circulaire


- **Définition :** Il n'existe pas de `head` ou de `tail` mais plutot un `cursor`
- **Simple ou double :** A choisir en fonction des besoins
- **Prev :** Prédécésseur n'est jamais null (sauf si list vide)
- **Next :** Sucesseur n'est jamais null (sauf si list vide)

## Circular Buffer

- Même principe mais dans une zone mémoire contigue
- Implémenter les deux versions

---
transition: slide-left
---

# Recherche dichotomique

<center>
<img src="/snippets/f8391c1526e6532a4d03df0422fc917a886deae4.jpg" width="60%"/>
</center>
<br>

- Implémenter une recherche dichotomique
- Quelle est la complexité temporel de cet algorithm ?
- https://sleek-think.ovh/index.php/cours/11-l3-algorithmie/12-recherche-dichotomique

---
transition: slide-left
---

### Exercice :
 
- Partir du code https://classroom.github.com/a/g5Lddf1f
- Ecrire un code dans un nouveau fichier (compilation séparé)
  - Les tableaux dynamique et statique (`dynamic_array.c` et `static_array.c`)
  - Les listes simple `single_linked_list.c` et double `double_linked_list.c`
  - Les listes circulaire `circular_linked_list.c`
  - **Bonnus :** Écrire un CircularBuffer (Tableaux dynamique + List Circulaire) 
- Pour chaque méthode implémenter `push_front` / `push_back` / `insert(index)` / `remove(index)`
  - Ex: `push_front(SingleLinkedList*, SLL_IntNode*)`
- Pour chaque méthode expliqué les différents problèmes
  - Complexité temporel : appoximation
  - Complexité spatial
  - **Bonnus :** Expliqué les problemes de cache miss associé, avec schéma
- Chercher des exemples de cas d'utilisation de ces structures de données
- Petit rapport

---
transition: slide-left
---

# Problème de cache miss

- **Accès imprévisible à la mémoire :** Les nœuds sont dispersés dans la mémoire.
- **Manque de localité :** Pas d'accès aux emplacements de mémoire direct \[index\].
- **Augmentation du temps d'accès à la mémoire :** Les échecs de mise en cache entraînent un ralentissement des performances en raison de l'attente des données de la mémoire principale.
- **Chargement inefficace des blocs de mémoire :** Un seul nœud par bloc de cache est utilisé
- **Impact :** Ralentissement de la traversée, recherche très lente.

<h1 class="text-center" style="position: relative;top: 50%;">Niveau 3</h1>
<p class="text-center" style="position: relative;top: 50%;">Structures de données hiérarchiques</p>

---
transition: slide-left
---

# Arbres binnaire

Un arbre binaire est une structure de données où chaque nœud peut avoir au maximum deux enfants.
Les arbres binaires sont utilisés pour représenter des hiérarchies et sont efficaces pour certaines opérations comme la recherche et l'insertion.

- **Maximum de deux enfants** : Chaque nœud a au plus deux enfants.
- **Structure hiérarchique** : Les nœuds sont organisés de manière hiérarchique.
- **Flexibilité** : Peuvent être utilisés pour diverses applications sans nécessiter un ordre spécifique.
- **Problème de balancement :** Largeur et profondeur variable -> change la complexité temporel

Comment peut-on écrire cette structure de données en C ?

---
transition: slide-left
---

## Structure en C

```cpp
typedef struct Node {
  void *data;
  struct Node *left, *right;
} Node;

Node node = { .data=((void*)5), .left=NULL, .right=NULL };
printf("Hello World %lld", (long long)node.data);
```

<center>
<img src="/snippets/Sorted_binary_tree_ALL_RGB.svg.png" width="35%">
<small>source: wikipedia</small>
</center>
---
transition: slide-left
---
## Arbre binnaire : TP

```cpp
Node root = {
    .data = 'F',
    .left = &(Node){
      .data = 'B',
      .left = &(Node){ .data = 'A', .left = NULL, .right = NULL, },
      .right = &(Node){
        .data = 'D',
        .left = &(Node){ .data = 'C', .left = NULL, .right = NULL, },
        .right = &(Node){ .data = 'E', .left = NULL, .right = NULL, },
      },
    },
    .right = &(Node){
      .data = 'G',
      .left = NULL,
      .right = &(Node){
        .data = 'I',
        .left = &(Node){ .data = 'H', .left = NULL, .right = NULL, },
        .right = NULL,
      },
    },
};
```

---
transition: slide-left
---
## Traverser un arbree binnaire (non-optimisé)

```cpp
void inorder(Node *tree, void *user, void(*dosomethink)(Node*, void*))
{
    if(!tree) return;
    inorder(tree->left, user, dosomethink);
    dosomethink(tree, user); // A, B, C, D, E, F, G, H, I
    inorder(tree->right, user, dosomethink);
}

void preorder(Node *tree, void *user, void(*dosomethink)(Node*, void*))
{
    if(!tree) return;
    dosomethink(tree, user); // F, B, A, D, C, E, G, I, H
    preorder(tree->left, user, dosomethink);
    preorder(tree->right, user, dosomethink);
}

void postorder(Node *tree, void *user, void(*dosomethink)(Node*, void*))
{
    if(!tree) return;
    postorder(tree->left, user, dosomethink);
    postorder(tree->right, user, dosomethink);
    dosomethink(tree, user); // A, C, E, D, B, H, I, G, F
}
```

<!-- https://www.geeksforgeeks.org/inorder-traversal-of-binary-tree/ -->

---
transition: slide-left
---
# Arbre binaire de recherche

C'est un arbre binaire pour le quel on associe une fonction de comparaison a chaque noeud.

**Propriété:**
- toutes les clés dans le sous-arbre gauche sont inférieures à la clé du nœud
- toutes les clés dans le sous-arbre droit sont supérieures
- toutes les clés sont uniques

**Caractéristiques**
- Recherche efficace : $O(log(n))$ mais peu dégénéré en $O(n)$
- Insertion et suppression rapides : Maintiennent l'ordre des éléments.
- Utilisation : Tables de recherche, ensembles dynamiques, files de priorité.
- Ordre des éléments : Permet une itération en ordre croissant.

<!-- Meilleure que les listes chaînées. -->

---
transition: slide-left
layout: image-right
image: /snippets/avl-insert.png
backgroundSize: contain
---
# Arbre AVL

Le concept d'arbre avl, se rapporte à des arbres de recherche qui mesure la hauteur de leurs sous arbre gauche et droite.

On modifie les fonction d'insertion et de supression pour rebalancer l'arbre.
- Insertion et supression plus lent.
- La recherche est garantie en $O(log(n))$.
- Un arbre binaire qui s'étale le plus possible
- Division des espaces de recherche

<br>
  
> https://sleek-think.ovh/index.php/cours/l3-algorithmie/38-abres-avl

---
transition: slide-left
---
# Table de hachage

- On utilise une fonction de hachage qui encode la clé de recherche
  - C'est une opération mathématique, idéalement en $O(1)$
  - La fonction de hachage doit éviter les collisions
  - S'il y a une collision, une resolution dois être proposé pour garantir l'unicité.
  - La fonction de hachage permet de `compresser` l'information facilitant la comparaison
  
<br>
  
```cpp
unsigned int hash_function(char* key, int size) {
  unsigned int hash = 5381;
  int c;
  while ((c = *key++))
    hash = ((hash << 5) + hash) + c;
  return hash % size;
}
```

<br>

> On peu mixer les approches : arbre binaire + tableau de hachage

---
transition: slide-left
---
# Graphe orienté et non-orienté
Il existe plusieurs types de représentation pour décrire un graphe.

**Matrice d'adjacence**
```python
connection = np.zeros((n,n))
connection[0,0] = 1 # boucle sur x_1
connection[0,1] = 1 # arc de x_1 -> x_2
```

**Matrice d'incidence sommet-arc**
```python
n = 2, m = 1 # number_of_nodes,  number_of_arcs
connection = np.zeros((n,m))
connection[0,0] = -1 # arc de x_1
connection[1,0] = 1 # vers x_2
```

**Liste d'adjacence**
```python
nodes = [[] for _ in range(nomber_of_nodes)]
nodes[0] = [1] # liste des successeurs de x_1
nodes[1] = [0,2] # liste des successeurs de x_2
nodes[2] = [2,0] # boucle local
```

---
transition: slide-left
---
## Traverser un graphe non-orienté

**Recherche en largeur - Breadth First Search** (BFS)
- FIFO (File d'attente) : Utilisée pour stocker les sommets à visiter.
- Initialisation : Ajouter le sommet de départ dans la file.
- Boucle :
  - Extraire le sommet de la file (FIFO).
  - Marquer le sommet comme visité.
  - Afficher le sommet.
  - Ajouter tous ses voisins non visités à la file.
- Répéter jusqu'à ce que la file soit vide.
- 5, 3, 10, 1, 2, 7, 20

<br>
  
> https://sleek-think.ovh/index.php/cours/l3-maths-pour-l-info/32-theori-des-graphes <br>
  https://www.redblobgames.com/pathfinding/a-star/introduction.html <br>
  https://visualgo.net/en/dfsbfs?slide=1

---
transition: slide-left
layout: image-right
image: /snippets/bfs-vs-dfs.png
backgroundSize: contain
---
**Recherche en Profondeur - Depth First Search** 

- LIFO (Pile) : Sommets à visiter.
- Initialisation : sommet de départ sur la pile.
- Boucle :
  - Extraire le sommet du haut de la pile.
  - Marquer le sommet comme visité.
  - Afficher le sommet.
  - Add ses voisins non visités sur la pile.
- Répéter jusqu'à ce que la pile soit vide.
- 5, 3, 1, 2, 10, 7, 20

---
transition: slide-left
---

<iframe width="100%" height="470" src="https://www.youtube.com/embed/7fujbpJ0LB4" title="Depth First Search Algorithm | Graph Theory" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>

---
transition: slide-left
---
## TP FIFO - LIFO - Arbre binnaire - Graph

- (5 pts) Quelle structure de donnée est la plus adapté pour implémenter un LIFO et un FIFO ?
  - Comparer la complexité temporel et spatial des solutions, expliqué le choix (insertion, recherche, ...)
  - Écrire un code de test de vos structures de donnée existant, permettant de faire une FIFO et un LIFO
- (7 pts) Implémenter les arbres abres binnaires de recherche `binary_search_tree.c`
  - Réécrire les fonctions de traverser d'arbres binnaire sans récursion
  - Insertion et suppression : garantir l'ordonancement
  - Utilise un pointeur sur fonction pour la traversé de l'arbre -> recherche/print/etc
- (8 pts) Implémenter un graph non-orienté `graph.c`
  - Utilisé une représentation par matrice d'adjacences
  - Implémenter BreadthFirstSearch et le DepthFirstSearch
  - Utilisé ces techniques pour compter le nombre de components
  - Vérifier vos algorithmes sur différents graphs
- Code degeu <span style="color:red">**-2**</span> - pas d'explication / mini rapport <span style="color:red">**-2**</span>

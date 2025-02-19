<h1 class="text-center" style="position: relative;top: 50%;">Niveau 2</h1>
<p class="text-center" style="position: relative;top: 50%;">FIFO et LIFO</p>

---
transition: slide-left
---

# Arbres binnaire

Un arbre binaire est une structure de données non linéaire où chaque nœud peut avoir au maximum deux enfants.
Les arbres binaires sont utilisés pour représenter des hiérarchies et sont efficaces pour certaines opérations comme la recherche et l'insertion.

- **Maximum de deux enfants** : Chaque nœud a au plus deux enfants.
- **Structure hiérarchique** : Les nœuds sont organisés de manière hiérarchique.
- **Flexibilité** : Peuvent être utilisés pour diverses applications sans nécessiter un ordre spécifique.
- **Problème de balancement :** Largeur et profondeur variable -> change la complexité temporel

Comment peut-on écrire une structures de données en C ?

---
transition: slide-left
---

### Comparaison avec la Recherche Dichotomique

| Caractéristique | Arbre Binaire | Recherche Dichotomique |
|-----------------|--------------|------------------------|
| **Structure**   | Hiérarchique avec nœuds | Tableau triée |
| **Recherche**   | O(log n) en moyenne pour les arbres équilibrés | O(log n) pour les listes triées |
| **Insertion**   | Peut être complexe si l'arbre devient déséquilibré | Simple mais nécessite de réorganiser la liste |
| **Utilisation** | Utile pour les données hiérarchiques et les requêtes complexes | Idéal pour les recherches rapides dans des listes triées |

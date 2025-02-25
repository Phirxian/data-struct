
# Compétence visées

- Compréhension des différents types de structures de données
- Conception et mise en oeuvre en C
- Analyser et comprendre la complexité temporelle et spatial
- Comprendre les optimisations mémoire (cache miss)
- Savoir utiliser la bonne structure de donnée pour optimiser vos algorithms
- Utilisation avancée des pointeurs et de la gestion de la mémoire

---
transition: slide-left
---

# Programme

- Niveau 0 : Présentation et notion de complexité
- Niveau 1 : Retour sur le tableaux et listes (dynamique vs statique)
  - Listes chainées simple, double, circulaires (push/pop/find)
- Niveau 2 : Piles et files (LIFO / FIFO) et cas d'utilisation
- Niveau 3 : Structures de données hiérarchiques (arbre binnaire, arbre avl, graph, parcours d'arbre)
- Niveau 4 : Algorithme de trie et de recherche (dichotomique, quicksort, boustrophedon, ...)

<br>

# Notes

- Moyenne des TPs coef 1
  - ~1 TP par section
- Exam coef 1 
  
---
transition: slide-left
---

## Convention d'ecriture
- Style consistant !
  - Vous pouvez utiliser `clang-format`
  - Nommer correctement les fonction et variables (semantique)
  - Indentation (bloque)
  - Aérer les lignes du programme
  - Facilite la lecture !!!
- Pas de variables globales
- Commenter vos programmes
  - Pas de commentaire initile
- Attention sanction sur les notes de TP
- Example https://github.com/MaJerle/c-code-style
  
---
transition: fade-out
---
### -2
```cpp
#include<stdio.h>
#define MAX 1000
int a,b,c;float d;
char e[MAX];void F(int x){
if(x>0){printf("Positive");
}else{if(x<0){
printf("Negative");}else{printf("Zero");}}}
int main()
{
a=10;b=20;
c=a+b;
d=3.14159;
// This is a useless comment
printf("Hello World!");F(c);
for(int i=0;i<MAX;i++){e[i]='A';}
    if(d>3)
{
        printf("d is greater than 3");
    }
    else
        {
        printf("d is not greater than 3");
        }
return 0;
}
```





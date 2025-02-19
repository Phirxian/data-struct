<h1 class="text-center" style="position: relative;top: 50%;">Niveau 0</h1>
<p class="text-center" style="position: relative;top: 50%;">Comprendre la complexité</p>

---
transition: fade-out
---
# Introduction
Pourquoi est-elle essentielle dans le développement logiciel ?

**Objectifs de cette présentation :**
- Définir la complexité des algorithmes
- Expliquer les notations asymptotiques (O, Ω, Θ)
- Discuter de l'importance des constantes dans ces notations
- Présenter des exemples pratiques en pseudo-C

**Pourquoi est-ce important ?**
- Optimisation des performances (CPU vs RAM)
- Provisionné vos ressources (contrainte matériel)
- Amélioration de la qualité du code

---
transition: fade-out
---
# Définition de la complexité des algorithmes
Mesurer l'Efficacité des Programmes

La complexité d'un algorithme est une mesure de la quantifir les ressources nécessite pour traiter une donnée.
Elle nous permet de prédire comment l'algorithme se comportera lorsque la taille des données augmente.

**Types de Complexité :**
- **Complexité Temporelle** : Temps nécessaire pour exécuter l'algorithme (CPU).
- **Complexité Spatiale** : Espace mémoire nécessaire pour exécuter l'algorithme (RAM).

**Pourquoi est-elle importante ?**
- **Optimisation des performances** : Améliorer la rapidité et l'efficacité.
- **Évolutivité** : Prévoir comment l'algorithme se comportera avec des données plus volumineuses.
- **Qualité du code** : Écrire des programmes plus efficaces et maintenables.

**Similariter**
- Pour faire simple compter le nombre d'opération quand : $\lim_{n\rightarrow+\infty}f(n)$

---
transition: fade-out
---
**Exemple simple :**

Supposons un algorithme de recherche dans une liste de n éléments.

Voici un pseudo-algo qui vérifie un par un les éléments de la liste pour le trouver
```cpp
int recherche(int *array, size_t size, int value) {
    int index = -1;
    for (size_t i=0; i<size; ++i)
        if (array[i] == value)
            index = i;
    return index;
}
```

Cette algorithm a une complexité temporel lineaire, 
dans tout les cas le temps d'éxécution d'épendra de la taille de `@array`.

---
transition: fade-out
---

# Notations asymptotiques

Les notations asymptotiques sont utilisées pour décrire la complexité d'un algorithme en fonction de la taille de l'entrée. Elles nous aident à prédire comment l'algorithme se comportera lorsque la taille des données augmente.

**Big O**
- **Définition :** Limite supérieure. C'est la pire des situations.
- **Interprétation :** L'algorithme ne prendra jamais plus de temps que O(n) pour une liste de n éléments.

**Big Ω** (parfois minus o)
- **Définition :** Limite inférieure. C'est la meilleure des situations.
- **Interprétation :** L'algorithme prendra au minimum Ω(n) temps pour une liste de n éléments.

**Big Θ**
- **Définition :** Limite exacte à la complexité d'un algorithme. Quand **O(f)=Ω(f)**
- **Interprétation :** L'algorithme prend exactement Θ(n) temps pour une liste de n éléments.

---
transition: fade-out
---

<center>
<img src="/snippets/image-18.png" width="50%"/>
</center>

- 🚀 Complexité constante **O(1)** 
- 🚂 Complexité logarithmique **O(log(n))**
- 🚗 Complexité linéaire **O(n)**
- 📈 Complexité quasi-linéaire **O(n ⋅ log(n))**
- ⚠️ Complexité quadratique **O(n²)**
- 🚧 Complexité exponentielle **O(2n)**
- 🚨 Complexité factorielle **O(n!)**

---
transition: fade-out
---

# Notation asymptotiques et approximation

Dans la notation asymptotique, on oublie les termes constants

- O(2n) = O(n) : Les constantes sont ignorées, donc multiplier par 2 ne change "pas" la complexité.
- O(3n²) = O(n²) : De même, les constantes devant les puissances sont ignorées.
- O(n + 10) = O(n) : Les termes constants sont négligés par rapport aux termes variables.
- O(n² + n) = O(n²) : Dans les polynômes, on ne garde que le terme dominant.

Pourquoi ignorer les constantes ?
- **Échelle de grandeur :** Lorsque la taille des données augmente, les constantes deviennent négligeables par rapport à la croissance globale.
- **Modélisation simplifiée :** Ignorer les constantes simplifie l'analyse et permet de se concentrer sur la tendance générale.

---
transition: fade-out
---

# Attention

> Ses notions sont a savoir et utilisées dans les tests de recrutement,
mais c'est fondamentalement incorrect !

Pourquoi les constantes sont-elles importantes ?
- **Performances réelles :** Dans la pratique, les constantes peuvent avoir un impact significatif sur les performances, surtout si elles représentent des opérations complexes ou des accès mémoire coûteux.
- **Optimisation :** Ignorer les constantes peut conduire à négliger des opportunités d'optimisation importantes. Par exemple, un algorithme avec une constante plus petite mais une complexité similaire est plus rapide en pratique.
- **Cas réels :** Dans de nombreux cas réels, les tailles des données ne sont pas toujours très grandes, et les constantes peuvent donc jouer un rôle crucial dans la performance globale.
- **Taille des données :** Si la notation Big O ce concentre sur de large échelles de donnée, en pratique vous connaitrez presque toujours les tailles. Elles seront presque toujours petites dans ce cas un algorithme en O(n) peut être meilleur qu'un algorithm en O(log(n))'

---
transition: fade-out
---

<iframe width="800" height="500" src="https://www.youtube.com/embed/gCzOhZ_LUps" title="What Big-O notation ACTUALLY tells you, and how I almost failed my Google Interview" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>

---
transition: fade-out
---

# Exemples de complexité en Θ(1)
_

Toute opération qui accede directement a une donnée:

```cpp
int tableau[1000];
int index = 5;
int valeur = tableau[index];
```

ou effectue des calcules

```cpp
bool estPair(int nombre) {
  return nombre % 2 == 0;
}
```

<br>

- Ceci n'est pas vrais pour certaines structures de données complexe (hash map, bin tree, etc) "caché"
- Quelle complexité est caché pour la fonction estPair ?

---
transition: fade-out
---

## Quelle est la complexité de ce code ?

<br>

- Complexité spatial ?
- Complexité temporel ?

<br>

```cpp
int x = 3;
int n = 10;
int result = pow(x, n) * sqrt(x, n);
```

<br>

- **A** : Θ(1)
- **B** : Θ(2)
- **C** : On ne sait pas ?
- **D** : Expliquer

---
transition: fade-out
---

# Exemples de complexité en Θ(n)

```cpp
double pow(double base, int exponent) {
  double result = 1.0;
  for (int i = 0; i < exponent; i++) {
    result *= base;
  }
  return result;
}
```

```cpp
int recherche(int *array, size_t size, int value) {
    int index = -1;
    for (size_t i=0; i<size; ++i)
        if (array[i] == value)
            index = i;
    return index;
}
```

---
transition: fade-out
---

## Quelle est la complexité de ce code ?

<br>

```cpp
int recherche(int *array, size_t size, int value) {
  for (size_t i=0; i<size; ++i)
    if (array[i] == value)
      return i;
  return -1;
}
```

<br>
  
- Complexité spatial ?
  - **A**:  O(1)
  - **B**:  Θ(1)
  - **C**:  Ω(1)
- Complexité temporel ?
  - **A**:  O(n)
  - **B**:  Θ(n)
  - **C**:  Ω(1) et O(n)

---
transition: fade-out
---

# Exemples de complexité en Θ(log(n))

```cpp
double pow(double base, int exponent) {
    double result = 1.0;
    
    while (exponent > 0) {
        if (exponent % 2 == 1)
            result *= base;
        exponent /= 2;
        base *= base;
    }
    
    return result;
}
```

---
transition: fade-out
---
# Exemples de complexité en Θ(log(n))

```cpp
double sqrt(double x) {
    if (x < 0)
        return NAN;
    else if (x == 0 || x == 1)
        return x;

    double guess = x / 2.0;
    double precision = 0.000001;

    while (1) {
        double betterGuess = (guess + x / guess) / 2.0;
        if (fabs(guess - betterGuess) < precision)
            return betterGuess;
        guess = betterGuess;
    }
}
```
<br>

## Peut-on faire mieux ?

---
transition: fade-out
---

# John Carmack et Quake III

```cpp
float fast_sqrt(float number) {
    long i;
    float x2, y;
    const float threehalfs = 1.5F;

    y = number;
    i = *(long*)&y;
    i = 0x5f3759df - (i >> 1); 
    y = *(float*)&i;

    y = y * (threehalfs - (x2 = number * 0.5F) * y * y);
    y = y * (threehalfs - (x2 = number * 0.5F) * y * y);
    
    return 1/y;
}
```

https://en.wikipedia.org/wiki/Fast_inverse_square_root

---
transition: fade-out
---
# Exemples de complexité en Θ(n^2)

```cpp
double pow(double base, int exponent) {
    double result = 1.0;
    
    for (int i = 0; i < exponent; i++)
        for (int j = 0; j < exponent; j++)
            if (i == j)
                result *= base;
                
    return result;
}
```

<br>

> Attention, le compilateur passe par là et fait aussi des optimisations ! (-Ofast -O3 -Og) ;)
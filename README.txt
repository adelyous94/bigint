# Projet BigBinary

Projet de programmation en C qui a pour but de créer une petite bibliothèque capable de manipuler des grands entiers binaires avec des tableaux dynamiques.

---

-- Objectif général

L’idée du projet, c’est d’arriver à représenter des grands nombres sous forme binaire (suite de 0 et de 1), et de pouvoir ensuite les additionner, les comparer, ou faire d’autres opérations dessus, un peu comme avec des entiers classiques, mais “à la main”.

Pour l’instant, on a commencé à poser la base du projet :
- La structure du dossier (`include`, `src`, `Makefile`)
- Debut du squelette structure `BigBinary`
- Des fonctions vides pour tester la compilation et la liaison entre fichiers

---

-- Répartition du travail

L’équipe est composée de **3 personnes** :
- **Adel** : création du squelette du projet, architecture des dossiers, mise en place du `Makefile`, premiers tests dans le `main`.
- **Paige** : documentation du projet (`README.md`, commentaires dans le code) et implémentation future des fonctions d’affichage et de libération mémoire.
- **Johan** : prise en charge de la partie arithmétique (addition, soustraction, comparaisons) et gestion de la mémoire dynamique (allocation/libération).

---

-- Organisation prévue

- **Semaine 1 (cette semaine)** :  
  Création du dépôt GitHub, mise en place de la structure du projet, création des premières fonctions “vides” et test de compilation.  
  Objectif : que le programme affiche déjà quelque chose pour la démo (ce qui est fait ✅).

- **Semaine 2** :  
  Début de l’implémentation de la structure `BigBinary` avec allocation dynamique du tableau de bits.  
  Ajout des premières vraies fonctions (initialisation + affichage réel).

- **Dans 2 semaines (réunion prévue)** :  
  On fera un point d’équipe pour fusionner nos branches (`adel`, `paige`, `johan`) et voir où chacun en est.  
  L’objectif sera d’avoir les fonctions suivantes opérationnelles :
  - `initBigBinary()` : créer un grand entier binaire vide
  - `afficherBigBinary()` : afficher les bits dans le bon ordre
  - `comparerBigBinary()` : vérifier si deux nombres sont égaux

- **Phase suivante (fin du mois)** :  
  Implémenter l’addition et la soustraction binaire (sans gestion du signe dans un premier temps).  
  Commencer à réfléchir à la structure mémoire et à la gestion des zéros inutiles.

---

## 💻 Compilation et exécution

Pour compiler le projet :
```bash
make

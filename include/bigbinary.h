#ifndef BIGBINARY_H
#define BIGBINARY_H

// Ici on veut représenter un "grand entier" en binaire.
// digits = tableau de bits (0/1)
// taille = nombre de bits utilisés
// signe  = +1 (positif) / -1 (négatif) / 0 (zéro)
typedef struct
{
    int *digits; // MSB à gauche (indice 0), LSB à droite (indice taille-1)
    int taille;
    int signe;
} BigBinary;

// On commence simple, juste pour montrer l'avancement.

// alloue un BigBinary de "taille" bits et met tout à 0
// remarque: ne gère pas encore les erreurs avancées, on fait simple
BigBinary bb_init(int taille, int signe);

// libère la mémoire
void bb_free(BigBinary *b);

// affecte une petite valeur (unsigned long long) dans le BigBinary
// si la valeur ne rentre pas dans "taille" bits, on tronque (pour le moment)
void bb_set_from_ull(BigBinary *b, unsigned long long v);

// affiche le nombre en binaire (format simple)
void bb_print(const BigBinary *b);

// renvoie 1 si A == B (même signe + mêmes bits), sinon 0
int bb_equal(const BigBinary *a, const BigBinary *b);

#endif
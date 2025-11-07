#ifndef BIGBINARY_H
#define BIGBINARY_H

#include <stdbool.h>
#include <stddef.h>

#define BASE 2

typedef struct {
    int *Tdigits;   // Tdigits[0] = MSB
    int  Taille;    // nombre de bits significatifs
    int  Signe;     // +1: positif, -1: négatif, 0: nul
} BigBinary;

/* Création/initialisation/libération */
BigBinary createBigBinary(int size);              // alloue size digits (non initialisés)
BigBinary initBigBinary(int taille, int signe);   // alloue et met tous les digits à 0
BigBinary zeroBigBinary(void);                    // représente 0 correctement
void      libereBigBinary(BigBinary *nb);

/* I/O */
void afficheBigBinary(const BigBinary nb);

/* Construction depuis une chaîne  */
BigBinary creerBigBinaryDepuisChaine(const char *chaine);

/* Comparaisons (Phase 1 : nombres non négatifs uniquement) */
bool Egal(const BigBinary *A, const BigBinary *B);         // A == B ?
bool Inferieur(const BigBinary *A, const BigBinary *B);    // A <  B ?

/* Opérations (Phase 1 : A,B ≥ 0 ; pour la soustraction on suppose A ≥ B) */
BigBinary addition(const BigBinary *A, const BigBinary *B);
BigBinary soustraction(const BigBinary *A, const BigBinary *B);

#endif // BIGBINARY_H

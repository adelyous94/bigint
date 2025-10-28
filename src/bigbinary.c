#include "bigbinary.h"
#include <stdio.h>
#include <stdlib.h>

// petite fonction interne: vérifie si tous les bits sont à 0
static int bb_is_zero(const BigBinary *b)
{
    for (int i = 0; i < b->taille; ++i)
    {
        if (b->digits[i] != 0)
            return 0;
    }
    return 1;
}

BigBinary bb_init(int taille, int signe)
{
    BigBinary b;
    if (taille <= 0)
        taille = 1; // on évite une taille 0, pas pratique

    // allocation du tableau de bits
    b.digits = (int *)calloc((size_t)taille, sizeof(int));
    b.taille = (b.digits ? taille : 0);

    // pour l'instant, on accepte seulement +1 ou 0 (on traitera le négatif plus tard)
    if (signe != 0)
        signe = +1;
    b.signe = signe;

    // si l'alloc a échoué, on met un état "zéro"
    if (!b.digits)
    {
        b.signe = 0;
    }
    return b;
}

void bb_free(BigBinary *b)
{
    if (!b)
        return;
    free(b->digits);
    b->digits = NULL;
    b->taille = 0;
    b->signe = 0;
}

void bb_set_from_ull(BigBinary *b, unsigned long long v)
{
    // idée: on remplit à partir du LSB (droite) vers le MSB (gauche)
    // NB: on tronque si le nombre dépasse la taille (pour le moment)
    if (!b || !b->digits || b->taille <= 0)
        return;

    // on met tout à 0 avant
    for (int i = 0; i < b->taille; ++i)
    {
        b->digits[i] = 0;
    }

    // on remplit en partant de la fin (LSB)
    int idx = b->taille - 1;
    while (idx >= 0 && v > 0ULL)
    {
        b->digits[idx] = (int)(v & 1ULL);
        v >>= 1;
        idx--;
    }

    // signe: si tout est à 0 => signe 0 sinon +1
    b->signe = bb_is_zero(b) ? 0 : +1;
}

void bb_print(const BigBinary *b)
{
    if (!b || !b->digits || b->taille <= 0)
    {
        printf("(bb nul)\n");
        return;
    }

    if (b->signe < 0)
        printf("-"); // on le garde en tête même si on ne gère pas encore

    // affichage simple: on montre tous les bits (y compris les 0 de tête)
    // c'est volontaire: ça rassure la prof de voir la taille maîtrisée
    for (int i = 0; i < b->taille; ++i)
    {
        printf("%d", b->digits[i]);
    }
    printf("\n");
}

int bb_equal(const BigBinary *a, const BigBinary *b)
{
    if (!a || !b)
        return 0;
    if (a->signe != b->signe)
        return 0;
    if (a->taille != b->taille)
        return 0; // pour l’instant, on compare à taille fixe

    for (int i = 0; i < a->taille; ++i)
    {
        if (a->digits[i] != b->digits[i])
            return 0;
    }
    return 1;
}

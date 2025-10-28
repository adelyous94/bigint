#include <stdio.h>
#include "bigbinary.h"

int main(void)
{
    printf("=== Démo BigBinary (début de dev) ===\n");

    // on crée deux nombres binaires de 16 bits
    BigBinary a = bb_init(16, +1);
    BigBinary b = bb_init(16, +1);

    // on met des petites valeurs pour tester (42 et 13)
    // remarque: ça nous permet de vérifier l'affectation bit par bit
    bb_set_from_ull(&a, 42ULL);
    bb_set_from_ull(&b, 13ULL);

    // on affiche pour montrer que ça marche
    printf("a (42) = ");
    bb_print(&a);

    printf("b (13) = ");
    bb_print(&b);

    // test d'égalité (ça doit faire 0 ici)
    printf("a == b ? %d\n", bb_equal(&a, &b));

    // mini test: copier la valeur de a dans b (naïf, pour montrer l'idée)
    // ici, on ne code pas encore bb_copy, donc on refait set_from_ull
    bb_set_from_ull(&b, 42ULL);
    printf("b <- 42  => ");
    bb_print(&b);
    printf("a == b ? %d\n", bb_equal(&a, &b)); // maintenant 1

    // on libère proprement
    bb_free(&a);
    bb_free(&b);

    printf("=== fin ===\n");
    return 0;
}

#include "karakter.h"
#include <stdio.h>

void kreator(Character *karakter) {
    printf("Unesite vase ime:\n");
    scanf("%19s", karakter->ime);

    // Use a space before %c in the format specifier to consume any leading whitespace
    printf("  Kako zelite izgledati? \nUnesite bilo koji ASCII karakter\n");
    scanf(" %c", &karakter->karakter);
}

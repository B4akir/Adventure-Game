#include <stdio.h>

typedef struct {
    char karakter;
    char ime[20];
} Character;

void kreator(Character *karakter);

int main() {
    Character karakter;
    kreator(&karakter);

    // Printing the entered data
    printf("Ime: %s\n", karakter.ime);
    printf("Karakter: %c\n", karakter.karakter);

    return 0;
}

void kreator(Character *karakter) {
    printf("Unesite ime karaktera:\n");
    scanf("%19s", karakter->ime);

    // Use a space before %c in the format specifier to consume any leading whitespace
    printf("Unesite karakter:\n");
    scanf(" %c", &karakter->karakter);
}

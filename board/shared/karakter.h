#ifndef KARAKTER_H
#define KARAKTER_H

typedef struct {
    char karakter;
    char ime[20];
} Character;

void kreator(Character *karakter);

#endif // KARAKTER_H

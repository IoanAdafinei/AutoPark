#include "car.h"

void main()
{
    Masina *a;
    FILE *file, *file1, *file2;
    int n, o;
    char c;

    o = count();

    file = fopen("date.in", "r");

    printf("%d\n", o);

    a = calloc(o, sizeof(Masina));

    for(int i = 0; i < o; i++)
        citire(file, &a[i]);

    for(int i = 0; i < o; i++)
        printf("%s %s %s %d %d\n", a[i].marca, a[i].model, a[i].tokenMasina, a[i].pretAchizitie, a[i].pretVanzare);


    sortare(a,o);

    printf("\n");
    for(int i = 0; i < o; i++)
        printf("%s %s %s %d %d\n", a[i].marca, a[i].model, a[i].tokenMasina, a[i].pretAchizitie, a[i].pretVanzare);
}

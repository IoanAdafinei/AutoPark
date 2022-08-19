#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


typedef struct Masina
{
    char *marca;
    char *model;
    char tokenMasina[12];
    int pretAchizitie;
    int pretVanzare;
}Masina;

int count();

void citire(FILE *file, Masina *a);

void swap(Masina *a1,Masina *a2);

int partition(int *v, int low, int high);

void quicksort(int *v, int low, int high);

void sortare(Masina *a, int o);

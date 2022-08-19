#include "car.h"

int count()
{
    FILE* file;
    int o = 0;
    char c;

    file = fopen("date.in", "r");
    rewind(file);

    for (c = getc(file); c != EOF; c = getc(file))
        if (c == '\n')
            o = o + 1;
    rewind(file);
    fclose(file);

    return o;
}

void citire(FILE *file, Masina *a)
{
    char aux[50];

    fscanf(file, "%s", aux);
    a -> marca = calloc(strlen(aux), sizeof(char));
    strcpy(a -> marca, aux);

    fscanf(file, "%s", aux);
    a -> model = calloc(strlen(aux), sizeof(char));
    strcpy(a -> model, aux);

    fflush(stdin);
    fgets(a -> tokenMasina, 12, file);
    fflush(stdin);

    fscanf(file, "%d", &a -> pretAchizitie);

    fscanf(file, "%d", &a -> pretVanzare);
}

void swap(Masina *a1,Masina *a2)
{
    char aux1[150], aux2[150];
    int aux3;

    strcpy(aux1, &a1->marca);
    strcpy(aux2, &a2->marca);
    a1->marca = realloc(a1->marca, strlen(aux2));
    a2->marca = realloc(a2->marca, strlen(aux1));
    strcpy(&a2->marca, aux1);
    strcpy(&a1->marca, aux2);
    //strcpy(&a1->marca, &a2->marca);
    //strcpy(&a2->marca, aux1);

    strcpy(aux1, &a1->model);
    strcpy(aux2, &a2->model);
    a1->model = realloc(a1->model, strlen(aux2));
    a2->model = realloc(a2->model, strlen(aux1));
    strcpy(&a2->model, aux1);
    strcpy(&a1->model, aux2);

    /*strcpy(aux1, &a1->model);
    strcpy(&a1->model, &a2->model);
    strcpy(&a2->model, aux1);*/

    strcpy(aux1, &a1->tokenMasina);
    strcpy(&a1->tokenMasina, &a2->tokenMasina);
    strcpy(&a2->tokenMasina, aux1);

    aux3 = a1->pretAchizitie;
    a1->pretAchizitie = a2->pretAchizitie;
    a2->pretAchizitie = aux3;

    aux3 = a1->pretVanzare;
    a1->pretVanzare = a2->pretVanzare;
    a2->pretVanzare = aux3;
    fflush(stdin);
}

int partition(int *v, int low, int high)
{
    int p,i;
    p=v[high];
    i=low-1;
    for(int j=low; j<high; j++)
    {
        if(v[j]<=p)
        {
            i++;
            swap(&v[i],&v[j]);
        }
    }
    swap(&v[i+1],&v[high]);
    return(i+1);
}

void quicksort(int *v, int low, int high)
{
    int q;

    if(low<high)
        {
    q=partition(v, low, high);
    quicksort(v,low,q-1);
    quicksort(v,q+1,high);
        }
}
void sortare(Masina *a, int o)
{
    int j = 1;

    while(j == 1)
    {
    j = 0;
    for(int i = 0; i < o - 1; i++)
    {
        if(strcmp(a[i].marca,a[i+1].marca)>0)
            {
                swap(&a[i],&a[i+1]);
                j=1;
            }
        if(strcmp(a[i].marca,a[i+1].marca)==0&&strcmp(a[i].model,a[i+1].model)>0)
            {
                swap(&a[i],&a[i+1]);
                j=1;
            }
        if(strcmp(a[i].marca,a[i+1].marca)==0&&strcmp(a[i].model,a[i+1].model)==0&&strcmp(a[i].tokenMasina,a[i+1].tokenMasina)>0)
            {
                swap(&a[i],&a[i+1]);
                j=1;
            }
        for(int i = 0; i < o; i++)
            printf("%s %s %s %d %d\n", a[i].marca, a[i].model, a[i].tokenMasina, a[i].pretAchizitie, a[i].pretVanzare);
            printf("\n");

    }
    o--;
    }
}

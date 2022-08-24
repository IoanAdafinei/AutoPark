# AutoPark

So basically you want to sort cars alphabetically and inventory them by make. Afterwards you read makes from the file marci.in and you want to sell (or eliminate frm the vector) the cars with that make. In the end you want to write the cars remaining in the vector to an output file and on the last line write the total profit after the sale.

You have to implement with htis struct:

typedef struct Masina
{

    char* marca;
    char *model;
    char tokenMasina[11];
    int pretAchizitie;
    int pretVanzare;
}Masina;

Here is the full list of limitation: https://ocw.cs.pub.ro/courses/sda-ab/tema0

It has some memory problems which i did not manage to resolve since it works sometimes and breaks other times regardless of input.

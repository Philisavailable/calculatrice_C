#include <stdio.h>
#include <stdlib.h>

void calcul(double *a, double *b, char operation, double *resultat);
int checkOperateur(char op);


int main(int argc, const char * argv[]) {
    double a;
    char operation;
    double b;
    double resultat;
    int check = 0;
    int opCheck;
    int sortir = 0;
    char choixFin;
    
    printf("_____________Calculatrice_____________\n");
    printf("*************INSTRUCTION**************\n");
    printf("vos nombre doivent être suppérieur à 0\n");
    printf("**************************************\n");
    do {
        do{
            if (check) {
                printf("veuillez entrer des chiffres > 0 uniquement\n\n");
            }
            printf("entrer un nombre à calculer :\n");
            scanf("%lf", &a);
            check = 1;
        }while(a == 0);
        check = 0;
        
        do {
            printf("choisissez l'opération (+, -, /, *):\n");
            scanf(" %c", &operation);
            opCheck = checkOperateur(operation);
        } while (!opCheck);
        
        do{
            if (check) {
                printf("veuillez entrer des chiffres > 0 uniquement\n\n");
            }
            printf("entrer un nombre à calculer :\n");
            scanf("%lf", &b);
            check = 1;
        }while(b == 0);
        check = 0;
        
        calcul(&a, &b, operation, &resultat);
    
    printf("votre opéation : %.2lf%c%.2lf\n", a, operation, b);
    printf("votre résultat : %.2lf\n\n", resultat);
        do {
            printf("Voulez-vous quitter la calculatrice ? (O/N)\n");
            scanf(" %c", &choixFin);
            if (choixFin == 'o' || choixFin == 'O') {
                sortir = 1;
            } else if (choixFin == 'n' || choixFin == 'N') {
                sortir = 0;
            } else {
                printf("veuillez entrer Y ou N\n");
            }
        } while (choixFin != 'o' && choixFin != 'O' && choixFin != 'n' && choixFin != 'N');

    } while (!sortir);

    return 0;
}

void calcul(double *a, double *b, char operation, double *resultat)
{
    switch (operation) {
        case '+':
            *resultat = *a + *b;
            break;
        case '-':
            *resultat = *a - *b;
            break;
        case '/':
            *resultat = *a / *b;
            break;
        case '*':
            *resultat = *a * *b;
            break;
    }
}

int checkOperateur(char op)
{
    if(op == '+' || op == '-' || op == '*' || op == '/'){
        return 1;
    }
    printf("opérateur %c non valide\n", op);
    return 0;
}

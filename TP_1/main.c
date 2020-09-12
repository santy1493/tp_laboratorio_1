#include <stdio.h>
#include <stdlib.h>
#include "aritmetica.h"

int validarDecimal(float);

int main()
{
    int opcion;
    float numero1;
    float numero2;
    int flagNum1;
    int flagNum2;
    int flagDecimalNum1;
    int flagDecimalNum2;
    int flagCalculo;
    float suma;
    float resta;
    float producto;
    float division;
    double factorialA;
    double factorialB;

    flagNum1 = 0; // los flag son para saber si se ingreso el numero al menos una vez.
    flagNum2 = 0;
    flagCalculo = 0; // para saber si se realizo el calculo (opcion 3)

    do {

        printf("\n#################################\n");
        if(flagNum1 == 0) {
        printf("1. Ingresar 1er operando(A=x)");
        }
        else {
            printf("1. Ingresar 1er operando(A=%.2f)", numero1);
        }

        if(flagNum2 == 0) {
            printf("\n2. Ingresar 2do operando (B=y)");
        }
        else {
            printf("\n2. Ingresar 2do operando (B=%.2f)", numero2);
        }

        printf("\n3. Calcular todas las operaciones\n4. Informar resultados\n5. Salir");
        printf("\n#################################\n\n");
        scanf("%d", &opcion);

        switch (opcion) {

            case 1: printf("Ingresar primer operando: ");
                    scanf("%f", &numero1);
                    flagNum1 = 1;
                    flagDecimalNum1 = validarDecimal(numero1); // se llama a la funcion validarDecimal para saber si el numero es entero o decimal
                    flagCalculo = 0;
                    break;

            case 2: printf("Ingresar segundo operando: ");
                    scanf("%f", &numero2);
                    flagNum2 = 1;
                    flagDecimalNum2 = validarDecimal(numero2);
                    flagCalculo = 0;
                    break;

            case 3: if(flagNum1==0) {
                        printf("FALTA INGRESAR 1ER OPERANDO!!!\n");
                    }
                    else if(flagNum2==0) {
                        printf("FALTA INGRESAR 2DO OPERANDO!!!\n");
                    }
                    else {
                        printf("Calculando...\n");
                        suma = sumar(numero1, numero2); //para cada operacion se llama a la funcion correspondiente en la biblioteca aritmetica.h
                        resta = restar(numero1, numero2);
                        producto = multiplicar(numero1, numero2);
                        division = dividir(numero1, numero2);
                        factorialA = factorial(numero1);
                        factorialB = factorial(numero2);
                        flagCalculo = 1;
                    }
                    break;

            case 4: if(flagCalculo==0) {
                        printf("SE DEBE REALIZAR EL CALCULO PRIMERO (OPCION 3)\n"); // si no se realizo el calculo (opcion 3) no permite imprimir los resultados
                    }

                    else {
                    printf("Resultados:\n\nEl resultado de A+B es: %.2f\nEl resultado de A-B es: %.2f\n", suma, resta);

                    if(numero2==0) {
                        printf("El resultado de A/B es: NO ES POSIBLE DIVIDIR POR 0\n");
                    }
                    else {
                        printf("El resultado de A/B es: %.2f\n", division);
                    }

                    printf("El resultado de A*B es: %.2f\n", producto);

                    if(numero1<0) {
                        printf("El factorial de A es: NO ES POSIBLE CALCULAR EL FACTORIAL DE UN NUMERO NEGATIVO\n");
                    }
                    else if(flagDecimalNum1==1) {
                        printf("El factorial de A es: NO ES POSIBLE CALCULAR EL FACTORIAL DE UN NUMERO DECIMAL\n");
                    }
                    else {
                        printf("El factorial de A es: %.0f\n", factorialA);
                    }

                    if(numero2<0) {
                        printf("El factorial de B es: NO ES POSIBLE CALCULAR EL FACTORIAL DE UN NUMERO NEGATIVO\n");
                    }
                    else if(flagDecimalNum2==1) {
                        printf("El factorial de B es: NO ES POSIBLE CALCULAR EL FACTORIAL DE UN NUMERO DECIMAL\n");
                    }
                    else {
                        printf("El factorial de B es: %.0f\n", factorialB);
                    }
                    }
                    break;

            case 5: printf("Saliendo...\n");
                    break;

            default: printf("Opcion invalida\n"); // en caso de poner cualquier numero o letra que no sea opcion
                    break;
        }

    } while (opcion != 5);
}

int validarDecimal(float numero) {

    if((ceil(numero)-numero)>0) { //aplico la funcion ceil() para redondear para arriba y le resto el numero
        return 1;                 //si da mas de 0 el numero es decimal.
    }
    else {
        return 0;
    }
}

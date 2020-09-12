#include "aritmetica.h"

float sumar(float numeroUno, float numeroDos) { //en cada operacion aritmetica se toma los numeros de la funcion main

    float resultado;

    resultado = numeroUno + numeroDos; // se realiza la operacion en este caso suma

    return resultado; // devuelve el valor de la operacion a la variable correspondiente de la funcion main
}

float restar(float numeroUno, float numeroDos) {

    float resultado;

    resultado = numeroUno - numeroDos;

    return resultado;
}

float multiplicar(float numeroUno, float numeroDos) {

    float resultado;

    resultado = numeroUno * numeroDos;

    return resultado;
}

float dividir(float numeroUno, float numeroDos) {

    float resultado;

    resultado = numeroUno / numeroDos;

    return resultado;
}

double factorial(float numero) {

    double resultado;
    int i;

    resultado = 1;

    if(numero == 0) {

        resultado = 1;
    }
    else {

        for(i=1;i<=numero;i++) {  // se calcula el factorial multiplicando desde el 1 hasta el numero ingresado

            resultado = resultado*i;
        }
    }

    return resultado;
}

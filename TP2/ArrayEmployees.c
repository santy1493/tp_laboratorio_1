#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "ArrayEmployees.h"

#define VACIO 0
#define LLENO 1

/**
 * \brief Inicia todos los indices del array empleados en VACIO
 * \param array de estructura eEmployee
 * \param int cantidad de indices del array
 * \return
 */
void initEmployees(eEmployee empleados[], int cantidad)
{
    int i;

    for(i=0;i<cantidad;i++) {

        empleados[i].isEmpty = VACIO;
    }
}

/**
 * \brief Verifica un indice vacio y carga empleados en el array empleados
 * \param array de estructura eEmployee
 * \param int cantidad de indices del array
 * \return
 */
void addEmployees(eEmployee empleados[], int cantidad)
{
    int i;
    int j;
    int len;

    i = buscarIndiceVacio(empleados, cantidad);
    char apellidoNombre[100];

    if(i!=-1) {
        empleados[i].id = crearLegajo(empleados, i);

        printf("Ingresar nombre: ");
        fflush(stdin);
        gets(empleados[i].name);
        printf("Ingresar apellido: ");
        fflush(stdin);
        gets(empleados[i].lastName);
        printf("Ingresar sueldo: ");
        scanf("%f", &empleados[i].salary);
        printf("Ingresar sector: ");
        fflush(stdin);
        gets(empleados[i].sector);

        empleados[i].isEmpty = LLENO;

        strcpy(apellidoNombre, empleados[i].lastName);
        strcat(apellidoNombre, ", ");
        strcat(apellidoNombre, empleados[i].name);

        strlwr(apellidoNombre);
        strlwr(empleados[i].sector);
        len = strlen(apellidoNombre);

        apellidoNombre[0] = toupper(apellidoNombre[0]);
        empleados[i].sector[0] = toupper(empleados[i].sector[0]);

        for(j=0; j<len; j++) {

            if(apellidoNombre[j]==' ') {

                apellidoNombre[j+1] = toupper(apellidoNombre[j+1]);
            }
        }
        printf("\n--------------------------------------------------------------------------------------\n");
        printf("\nEMPLEADO INGRESADO:\n\n"
               "LEGAJO                 APELLIDO Y NOMBRE                    SECTOR                SUELDO\n\n"
               "%4d %35s %25s %20.2f\n", empleados[i].id, apellidoNombre, empleados[i].sector, empleados[i].salary);
    }
}

/**
 * \brief Cambia el estado de la variable isEmpty de la estructura eEployee por VACIO(borrado logico)
 * \param array de estructura eEmployee
 * \param int cantidad de indices del array
 * \return
 */
void removeEmployee(eEmployee empleados[], int cantidad)
{
    int legajoEliminar;
    int legajoError;
    int i;

    legajoError = 1;

    printf("Ingrese el legajo del empleado a dar de baja: ");
    scanf("%d", &legajoEliminar);

    for(i=0;i<cantidad;i++)
    {
        if(empleados[i].id==legajoEliminar)
        {
            empleados[i].isEmpty = VACIO;
            legajoError = 0;
            system("cls");
            printf("**EMPLEADO BORRADO**\n");
        }
    }

    if(legajoError) {
        printf("\n**LEGAJO NO ENCONTRADO**\n\n");
    }
}

/**
 * \brief Ordena los empleados del array en orden alfabetico por apellido y sector
 * \param array de estructura eEmployee
 * \param int cantidad de indices del array
 * \param int orden
 * \return
 */
void sortEmployees(eEmployee empleados[], int cantidad, int orden) {

    int i;
    int j;
    eEmployee auxiliar;


    if(orden==1) {

        for(i=0;i<cantidad-1;i++) {

            for(j=i+1;j<cantidad;j++) {

                    if(strcmp(strlwr(empleados[i].sector), strlwr(empleados[j].sector))>0) {

                        auxiliar = empleados[i];
                        empleados[i] = empleados[j];
                        empleados[j] = auxiliar;
                    }
               }
        }

        for(i=0;i<cantidad-1;i++) {

            for(j=i+1;j<cantidad;j++) {

                if(strcmp(strlwr(empleados[i].sector), strlwr(empleados[j].sector))==0) {

                    if(strcmp(strlwr(empleados[i].lastName), strlwr(empleados[j].lastName))>0) {

                        auxiliar = empleados[i];
                        empleados[i] = empleados[j];
                        empleados[j] = auxiliar;
                    }
               }
            }
        }
    }

    else if(orden==0) {

        for(i=0;i<cantidad-1;i++) {

            for(j=i+1;j<cantidad;j++) {

                    if(strcmp(strlwr(empleados[i].sector), strlwr(empleados[j].sector))<0) {

                        auxiliar = empleados[i];
                        empleados[i] = empleados[j];
                        empleados[j] = auxiliar;
                    }
               }
        }

        for(i=0;i<cantidad-1;i++) {

            for(j=i+1;j<cantidad;j++) {

                    if(strcmp(strlwr(empleados[i].sector), strlwr(empleados[j].sector))==0) {
                    if(strcmp(strlwr(empleados[i].lastName), strlwr(empleados[j].lastName))<0) {

                        auxiliar = empleados[i];
                        empleados[i] = empleados[j];
                        empleados[j] = auxiliar;
                    }
               }
            }
        }
    }

}

/**
 * \brief Imprime lista de empleados
 * \param array de estructura eEmployee
 * \param int cantidad de indices del array
 * \return
 */
void printEmployees(eEmployee empleados[], int cantidad)
{
    int i;
    int j;
    int len;
    char apellidoNombre[100];

    printf("---------------------------------------------------------------------------------------------\n");
    printf("|                                   LISTA DE EMPLEADOS                                      |\n");
    printf("---------------------------------------------------------------------------------------------\n\n");

    printf("LEGAJO                       APELLIDO Y NOMBRE                    SECTOR              SALARIO\n\n");

    for(i=0;i<cantidad;i++)
    {
        if(empleados[i].isEmpty==LLENO)
        {
            strcpy(apellidoNombre, empleados[i].lastName);
            strcat(apellidoNombre, ", ");
            strcat(apellidoNombre, empleados[i].name);

            strlwr(apellidoNombre);
            strlwr(empleados[i].sector);
            len = strlen(apellidoNombre);

            apellidoNombre[0] = toupper(apellidoNombre[0]);
            empleados[i].sector[0] = toupper(empleados[i].sector[0]);

            for(j=0; j<len; j++) {

                if(apellidoNombre[j]==' ') {

                    apellidoNombre[j+1] = toupper(apellidoNombre[j+1]);
                }
            }

            printf("%5d %40s %25s %20.2f\n", empleados[i].id, apellidoNombre, empleados[i].sector, empleados[i].salary);
        }
    }
}

/**
 * \brief Permite modificar nombre, apellido, salario y sector del un empleado.
 * \param array de estructura eEmployee
 * \param int cantidad de indices del array
 * \return
 */
void modificarEmpleado(eEmployee empleados[], int cantidad) {

    int legajoModificar;
    int opcionModificar;
    int legajoError;
    int i;

    legajoError = 1;

    printf("Ingrese el legajo del empleado a modificar: ");
    scanf("%d", &legajoModificar);

    for(i=0;i<cantidad;i++)
    {
        if(empleados[i].id==legajoModificar)
        {
            do {

                system("cls");
                printf("\n##MODIFICAR EMPLEADO##\n\n");
                printf("1.Nombre\n2.Apellido\n3.Salario\n4.Sector\n10.Salir\n\n");
                printf("Elija una opcion: ");
                fflush(stdin);
                scanf("%d", &opcionModificar);

                while((opcionModificar<1 || opcionModificar>4) && opcionModificar!=10) {

                    printf("Opcion invalida. Elije una opcion: ");
                    fflush(stdin);
                    scanf("%d", &opcionModificar);
                }

                switch(opcionModificar) {

                    case 1:
                        printf("Ingrese nombre nuevo: ");
                        fflush(stdin);
                        gets(empleados[i].name);
                        break;
                    case 2:
                        printf("Ingrese apellido nuevo: ");
                        fflush(stdin);
                        gets(empleados[i].lastName);
                        break;
                    case 3:
                        printf("Ingrese salario nuevo: ");
                        scanf("%f", &empleados[i].salary);
                        break;
                    case 4:
                        printf("Ingrese sector nuevo: ");
                        fflush(stdin);
                        gets(empleados[i].sector);
                        break;
                }
            }while(opcionModificar!=10);

            system("cls");
            printf("**EMPLEADO MODIFICADO**\n\n");

            legajoError = 0;
        }
    }

    if(legajoError) {
        printf("\n**LEGAJO NO ENCONTRADO**\n\n");
    }
}

/**
 * \brief Menu principal de empleados
 * \param
 * \param
 * \return retorna la opcion elegida por el usuario
 */
int menuEmpleados()
{
    int opcion;

    printf("\n########################\n");
    printf("1. ALTA\n2. MODIFICAR\n3. BAJA\n4. INFORMAR\n10. SALIR\n");
    printf("########################\n\n");
    printf("Elije una opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    while((opcion<1 || opcion>4) && opcion!=10) {

        printf("Opcion invalida. Elije una opcion: ");
        fflush(stdin);
        scanf("%d", &opcion);
    }

    return opcion;
}

/**
 * \brief Submenu para enlistar empleados del array en orden alfabetico por apellido y sector
 * \param array de estructura eEmployee
 * \param int cantidad de indices del array
 * \return
 */
void menuListaEmpleados(eEmployee empleados[], int cantidad) {

    int opcion;
    int opcionLista;
    int orden;

    printf("1.Lista de empleados ordenados alfabeticamente por apellido y sector\n2.Total y promedio de salarios\n\n");
    printf("Elija una opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    while(opcion!=1 && opcion!=2) {

        printf("\nOpcion invalida. Elija una opcion: ");
        fflush(stdin);
        scanf("%d", &opcion);
    }

    if(opcion==1) {

        system("cls");
        printf("1.Orden ascendente\n2.Orden descendente\n\n");
        printf("Elija una opcion: ");
        fflush(stdin);
        scanf("%d", &opcionLista);

        while(opcionLista!=1 && opcionLista!=2) {

            printf("\nOpcion invalida. Elija una opcion: ");
            fflush(stdin);
            scanf("%d", &opcionLista);
        }

        if(opcionLista==1) {

            orden = 1;
            sortEmployees(empleados, cantidad, orden);
            system("cls");
            printEmployees(empleados, cantidad);
        }

        else if(opcionLista==2) {

            orden = 0;
            sortEmployees(empleados, cantidad, orden);
            system("cls");
            printEmployees(empleados, cantidad);
        }
    }
    else {

        orden = 1;
        sortEmployees(empleados, cantidad, orden);
        system("cls");
        sueldos(empleados, cantidad);
    }
}

/**
 * \brief Busca indice con variable isEmpty en VACIO
 * \param array de estructura eEmployee
 * \param int cantidad de indices del array
 * \return -1 si no encuentra indice vacio y int i si encuentra indice vacio
 */
int buscarIndiceVacio(eEmployee empleados[], int cantidad)
{
    int i;
    int memoriaLlena;

    memoriaLlena = 1;

    for(i=0;i<cantidad;i++) {

        if(empleados[i].isEmpty==VACIO) {
            memoriaLlena = 0;
            break;
        }
    }

    if(memoriaLlena==1) {
        printf("MEMORIA LLENA!!! No se puede cargar mas empleados.\n");
        return -1;
    }
    else {
       return i;
    }
}

/**
 * \brief Funcion para crear legajos
 * \param array de estructura eEmployee
 * \param int cantidad de indices del array
 * \return int legajo
 */
int crearLegajo(eEmployee empleados[], int cantidad) {

    int legajo;
    int legajoLibre;
    int i;

    srand(time(NULL));

    do {
        legajo = rand() % 999 + 1000;

        legajoLibre = 1;

        for(i=0;i<cantidad;i++) {

            if(legajo==empleados[i].id) {
                legajoLibre = 0;
            }
        }

    }while(legajoLibre==0);

    return legajo;
}

/**
 * \brief Calcula total de salarios, salario promedio y empleados que ganan arriba del promedio
 * \param array de estructura eEmployee
 * \param int cantidad de indices del array
 * \return
 */
void sueldos(eEmployee empleados[], int cantidad) {

    int i;
    int j;
    int len;
    int contadorSueldos;
    double acumuladorSueldos;
    double sueldoPromedio;
    char apellidoNombre[100];

    contadorSueldos  = 0;
    acumuladorSueldos = 0;

    for(i=0;i<cantidad;i++) {

        if(empleados[i].isEmpty==LLENO) {

            acumuladorSueldos = acumuladorSueldos + empleados[i].salary;
            contadorSueldos++;
        }
    }

    sueldoPromedio = acumuladorSueldos/(float)contadorSueldos;

    printf("---------------------------------------------------------------------------------------------\n");
    printf("|                                      SALARIOS                                             |\n");
    printf("---------------------------------------------------------------------------------------------\n\n");

    printf("TOTAL DE SALARIOS: $%.2f\nSALARIO PROMEDIO: $%.2f\n\n", acumuladorSueldos, sueldoPromedio);

    printf("EMPLEADOS QUE SUPERAN EL SALARIO PROMEDIO\n");
    printf("LEGAJO                       APELLIDO Y NOMBRE                    SECTOR              SALARIO\n\n");

    for(i=0;i<cantidad;i++) {
        if(empleados[i].isEmpty==LLENO) {

            if(empleados[i].salary>=sueldoPromedio) {

                strcpy(apellidoNombre, empleados[i].lastName);
                strcat(apellidoNombre, ", ");
                strcat(apellidoNombre, empleados[i].name);

                strlwr(apellidoNombre);
                strlwr(empleados[i].sector);
                len = strlen(apellidoNombre);

                apellidoNombre[0] = toupper(apellidoNombre[0]);
                empleados[i].sector[0] = toupper(empleados[i].sector[0]);

                for(j=0; j<len; j++) {

                    if(apellidoNombre[j]==' ') {

                        apellidoNombre[j+1] = toupper(apellidoNombre[j+1]);
                    }
                }

                printf("%5d %40s %25s %20.2f\n", empleados[i].id, apellidoNombre, empleados[i].sector, empleados[i].salary);
            }
        }
    }
}

/**
 * \brief Verifica que halla cargado al menos un empleado
 * \param array de estructura eEmployee
 * \param int cantidad de indices del array
 * \return 0 si no se cargo ningun empleado o 1 si hay al menos uno
 */
int unEmpleadoCargado(eEmployee empleados[], int cantidad) {

    int i;
    int empleadoCargado;

    empleadoCargado = 0;

    for(i=0;i<cantidad;i++) {

        if(empleados[i].isEmpty==LLENO) {
            empleadoCargado = 1;
            break;
        }
    }

    return empleadoCargado;
}


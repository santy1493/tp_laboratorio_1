#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"

#define cantidad 999

int main()
{
    int opcion;
    eEmployee empleados[cantidad];

    initEmployees(empleados, cantidad);

    do
    {
        opcion = menuEmpleados();

        switch (opcion)
        {

            case 1:
                system("cls");
                addEmployees(empleados, cantidad);
                break;
            case 2:
                system("cls");
                if(unEmpleadoCargado(empleados, cantidad)) {
                    modificarEmpleado(empleados, cantidad);
                }
                else{
                    printf("DEBE CARGAR UN EMPLEADO PRIMERO!!!\n");
                }
                break;
            case 3:
                system("cls");
                if(unEmpleadoCargado(empleados, cantidad)) {
                    removeEmployee(empleados, cantidad);
                }
                else{
                    printf("DEBE CARGAR UN EMPLEADO PRIMERO!!!\n");
                }
                break;

            case 4:
                system("cls");
                if(unEmpleadoCargado(empleados, cantidad)) {
                    menuListaEmpleados(empleados, cantidad);
                }
                else{
                    printf("DEBE CARGAR UN EMPLEADO PRIMERO!!!\n");
                }
                break;
        }

    }while(opcion!=10);

    return 0;
}

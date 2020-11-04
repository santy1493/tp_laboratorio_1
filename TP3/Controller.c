#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "Employee.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int parseo = 0;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        FILE* pFile;

        pFile = fopen(path, "r");

        parseo = parser_EmployeeFromText(pFile , pArrayListEmployee);

        fclose(pFile);
    }

    if(parseo)
    {
        printf("\n##Se cargo el archivo de texto con exito\n\n");
    }
    else
    {
        printf("\nNo se pudo cargar el archivo de texto!!!\n\n");
    }

    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int parseo = 0;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        FILE* pFile;

        pFile = fopen(path, "rb");

        parseo = parser_EmployeeFromBinary(pFile , pArrayListEmployee);

        fclose(pFile);
    }
    if(parseo)
    {
        printf("\n##Se cargo el archivo binario con exito\n\n");
    }
    else
    {
        printf("\nNo se pudo cargar el archivo binario!!!\n\n");
    }

    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* empleado;

    char idStr[12];
    char nombre[50];
    char horasTrabajadas[20];
    char sueldo[20];

    crearIdStr(idStr, pArrayListEmployee);

    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(nombre);

    printf("Ingrese horas trabajadas: ");
    fflush(stdin);
    gets(horasTrabajadas);

    printf("Ingrese sueldo: ");
    fflush(stdin);
    gets(sueldo);

    empleado = employee_newParametros(idStr, nombre, horasTrabajadas, sueldo);

    printf("\n\n##Empleado ingresado:\n\n");
    imprimirUnEmpleado(empleado);

    ll_add(pArrayListEmployee, empleado);

    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int indice;
    int opcion;
    Employee* empleadoModificar;
    int len;

    len = ll_len(pArrayListEmployee);

    if(len>0)
    {
        controller_ListEmployee(pArrayListEmployee);

        printf("\n\nIngrese el indice del empleado que desea modificar: ");
        fflush(stdin);
        scanf("%d", &indice);

        empleadoModificar = ll_get(pArrayListEmployee, indice-1);

        do {

            printf("\n\nQue datos desea modificar:\n\n1.Nombre\n2.Horas trabajadas\n3.Sueldo\n10.Volver al menu principal\n\nOpcion: ");
            fflush(stdin);
            scanf("%d", &opcion);

            switch(opcion)
            {
                case 1:
                    modificarNombre(empleadoModificar);
                    break;
                case 2:
                    modificarHorasTrabajadas(empleadoModificar);
                    break;
                case 3:
                    modificarSueldo(empleadoModificar);
                    break;
            }

        }while(opcion!=10);
    }

    if(len)
    {
        printf("\n\n##Empleado Modificado:\n\n");
        imprimirUnEmpleado(empleadoModificar);
    }
    else
    {
        printf("\n\nDebe ingresar al menos un empleado!!!\n\n");
    }


    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int indice;
    int opcion;
    Employee* empleadoEliminar;
    int len;

    len = ll_len(pArrayListEmployee);

    if(len>0)
    {
        controller_ListEmployee(pArrayListEmployee);

        printf("\n\nIngrese el indice del empleado que desea dar de baja: ");
        fflush(stdin);
        scanf("%d", &indice);

        empleadoEliminar = ll_get(pArrayListEmployee, indice-1);

        printf("\nEsta por eliminar el siguiente empleado:\n\n");
        imprimirUnEmpleado(empleadoEliminar);
        printf("Desea continuar?\n\n1.Si\n2.No\n\n");
        fflush(stdin);
        scanf("%d", &opcion);

        printf("\n##Empleado eliminado:\n\n");
        imprimirUnEmpleado(empleadoEliminar);

        if(opcion==1)
        {
            ll_remove(pArrayListEmployee, indice-1);
        }
    }
    else
    {
        printf("\nDebe ingresar al menos un empleado!!\n\n");
    }

    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* empleado;
    int len;
    int i;
    int indice;
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;

    len = ll_len(pArrayListEmployee);

    if(len>0)
    {
        printf("\n\n##Lista de empleados:\n\n");
        printf("INDICE          ID                                   NOMBRE              HS. TRABAJADAS                 SUELDO\n\n");

        for(i=0;i<len;i++)
        {
            empleado = (Employee*) ll_get(pArrayListEmployee, i);
            indice = i+1;

            employee_getId(empleado, &id);
            employee_getNombre(empleado, nombre);
            employee_getHorasTrabajadas(empleado, &horasTrabajadas);
            employee_getSueldo(empleado, &sueldo);

            printf("%4d %13d %40s %27d %22d\n", indice, id, nombre, horasTrabajadas, sueldo);
        }
    }
    else
    {
        printf("\nNo hay ningun empleado ingresado!!\n\n");
    }

    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int opcion;
    int orden;

    printf("\nOrdenar por:\n\n1.ID\n2.Nombre\n3.Horas Trabajadas\n4.Sueldo\n\nOpcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    switch(opcion)
    {
        case 1:
        orden = ordenar();
        ll_sort(pArrayListEmployee, employee_compareById, orden);
        break;
        case 2:
        orden = ordenar();
        ll_sort(pArrayListEmployee, employee_compareByNombre, orden);
        break;
        case 3:
        orden = ordenar();
        ll_sort(pArrayListEmployee, employee_compareByHorasTrabajadas, orden);
        break;
        case 4:
        orden = ordenar();
        ll_sort(pArrayListEmployee, employee_compareBySueldo, orden);
        break;
    }

    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    Employee* empleado;
    int i;
    int len;
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;

    len = ll_len(pArrayListEmployee);

    pFile = fopen(path, "w");

    for(i=0;i<len;i++)
    {
        empleado = ll_get(pArrayListEmployee, i);

        employee_getId(empleado, &id);
        employee_getNombre(empleado, nombre);
        employee_getHorasTrabajadas(empleado, &horasTrabajadas);
        employee_getSueldo(empleado, &sueldo);

        fprintf(pFile, "%d,%s,%d,%d\n", id, nombre, horasTrabajadas, sueldo);
    }

    fclose(pFile);

    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    int len;
    Employee* empleado;

    pFile = fopen(path, "wb");
    len = ll_len(pArrayListEmployee);

    fwrite(&len,sizeof(int),1,pFile);

    for(int i=0;i<len;i++)
    {
        empleado = ll_get(pArrayListEmployee, i);
        fwrite(empleado,sizeof(Employee),1,pFile);
    }

    fclose(pFile);

    return 1;
}

int menu()
{
    int opcion;

    printf("\n################################################################################\n\n");
    printf("                                        MENU                                      \n\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
    printf("10. Salir\n");
    printf("\n################################################################################\n\n\n");

    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    while(opcion<1 || opcion>10)
    {
        printf("Opcion invalida. Ingrese opcion: ");
        fflush(stdin);
        scanf("%d", &opcion);
    }

    return opcion;
}

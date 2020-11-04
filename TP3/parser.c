#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee* empleado;
    char id[10];
    char nombre[50];
    char horasTrabajadas[10];
    char sueldo[10];

    while(!feof(pFile))
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo);
        empleado = employee_newParametros(id, nombre, horasTrabajadas, sueldo);
        ll_add(pArrayListEmployee, empleado);
    }

    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee* empleado;
    int len;

    fread(&len,sizeof(int),1,pFile);

    printf("\n\n%d\n\n", len);

    while(!feof(pFile))
    {
        empleado = employee_new();
        fread(empleado,sizeof(Employee),1,pFile);
        ll_add(pArrayListEmployee, empleado);
    }

    return 0;
}

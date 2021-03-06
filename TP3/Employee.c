#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "LinkedList.h"
#include "Employee.h"

Employee* employee_new()
{
    Employee* empleado;

    empleado = (Employee*) malloc(sizeof(Employee));

    return empleado;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* empleado;

    empleado = employee_new();

    if(empleado != NULL)
    {
        employee_setId(empleado, atoi(idStr));
        employee_setNombre(empleado, nombreStr);
        employee_setHorasTrabajadas(empleado, atoi(horasTrabajadasStr));
        employee_setSueldo(empleado, atoi(sueldoStr));
    }

    return empleado;
}

int employee_setId(Employee* this,int id)
{
    int setteo = 0;

    if(this!=NULL && id>0)
    {
        this->id = id;
        setteo = 1;
    }

    return setteo;
}

int employee_getId(Employee* this,int* id)
{
    int getteo = 0;

    if(this!=NULL && id!=NULL)
    {
        *id = this->id;
        getteo = 1;
    }

    return getteo;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int setteo = 0;

    if(this!=NULL)
    {
        strcpy(this->nombre, nombre);
        setteo = 1;
    }

    return setteo;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int getteo = 0;

    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre, this->nombre);
        getteo = 1;
    }

    return getteo;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int setteo = 0;

    if(this!=NULL && horasTrabajadas>0)
    {
        this->horasTrabajadas = horasTrabajadas;
        setteo = 1;
    }

    return setteo;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int getteo = 0;

    if(this!=NULL && horasTrabajadas!=NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        getteo = 1;
    }

    return getteo;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int setteo = 0;

    if(this!=NULL && sueldo>0)
    {
        this->sueldo = sueldo;
        setteo = 1;
    }

    return setteo;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int getteo = 0;

    if(this!=NULL && sueldo!=NULL)
    {
        *sueldo = this->sueldo;
        getteo = 1;
    }

    return getteo;
}

void modificarId(Employee* this)
{
    int id;
    int setteo = 0;

    printf("\nIngrese nuevo ID: ");
    fflush(stdin);
    scanf("%d", &id);

    setteo = employee_setId(this, id);

    if(setteo==0)
    {
        printf("\n\nNo se pudo modificar ID!!!\n\n");
    }
}

void modificarNombre(Employee* this)
{
    char nombre[40];
    int esNombre = 1;
    int setteo = 0;

    printf("\nIngrese nuevo nombre: ");
    fflush(stdin);
    gets(nombre);

    esNombre = validarNombre(nombre);

    while(esNombre == 0)
    {
        printf("\nNombre invalido. Ingrese nuevamente: ");
        fflush(stdin);
        gets(nombre);

        esNombre = validarNombre(nombre);
    }

    setteo = employee_setNombre(this, nombre);

    if(setteo==0)
    {
        printf("\n\nNo se pudo modificar el nombre!!!\n\n");
    }
}

void modificarHorasTrabajadas(Employee* this)
{
    char horas[12];
    int horasInt;
    int esNumero;
    int setteo = 0;

    printf("\nIngrese nuevas horas trabajadas: ");
    fflush(stdin);
    gets(horas);

    esNumero = validarNumero(horas);

    while(esNumero==0)
    {
        printf("\nHoras trabajadas invalidas. Ingrese nuevamente: ");
        fflush(stdin);
        gets(horas);

        esNumero = validarNumero(horas);
    }

    horasInt = atoi(horas);

    setteo = employee_setHorasTrabajadas(this, horasInt);

    if(setteo==0)
    {
        printf("\n\nNo se pudo modificar las horas trabajadas!!!\n\n");
    }
}

void modificarSueldo(Employee* this)
{
    char sueldo[12];
    int sueldoInt;
    int esNumero;
    int setteo = 0;

    printf("\nIngrese nuevo sueldo: ");
    fflush(stdin);
    gets(sueldo);

    esNumero = validarNumero(sueldo);

    while(esNumero==0)
    {
        printf("\nSueldo invalido. Ingrese nuevamente: ");
        fflush(stdin);
        gets(sueldo);

        esNumero = validarNumero(sueldo);
    }

    sueldoInt = atoi(sueldo);

    setteo = employee_setSueldo(this, sueldoInt);

    if(setteo==0)
    {
        printf("\n\nNo se pudo modificar el sueldo!!!\n\n");
    }
}

void imprimirUnEmpleado(Employee* this)
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;

    employee_getId(this, &id);
    employee_getNombre(this, nombre);
    employee_getHorasTrabajadas(this, &horasTrabajadas);
    employee_getSueldo(this, &sueldo);

    printf("   ID                                   NOMBRE              HS. TRABAJADAS                 SUELDO\n\n");

    printf("%5d %40s %27d %22d\n\n", id, nombre, horasTrabajadas, sueldo);
}

int employee_compareById(void* empleadoUno, void* empleadoDos)
{
    int compara = 0;

    Employee* unEmpleado = empleadoUno;
    Employee* otroEmpleado = empleadoDos;

    int unEmpleadoId;
    int otroEmpleadoId;

    employee_getId(unEmpleado, &unEmpleadoId);
    employee_getId(otroEmpleado, &otroEmpleadoId);

    if(unEmpleadoId>otroEmpleadoId)
    {
        compara = 1;
    }
    else
    {
        if(unEmpleadoId<otroEmpleadoId)
        {
            compara = -1;
        }
    }
    return compara;
}

int employee_compareByNombre(void* empleadoUno, void* empleadoDos)
{
    int compara = 0;

    Employee* unEmpleado = empleadoUno;
    Employee* otroEmpleado = empleadoDos;

    char unEmpleadoNombre[128];
    char otroEmpleadoNombre[128];

    employee_getNombre(unEmpleado, unEmpleadoNombre);
    employee_getNombre(otroEmpleado, otroEmpleadoNombre);

    if(strcmp(strlwr(unEmpleadoNombre), strlwr(otroEmpleadoNombre))>0)
    {
        compara = 1;
    }
    else
    {
        if(strcmp(strlwr(unEmpleadoNombre), strlwr(otroEmpleadoNombre))<0)
        {
            compara = -1;
        }
    }
    return compara;
}

int employee_compareByHorasTrabajadas(void* empleadoUno, void* empleadoDos)
{
    int compara = 0;

    Employee* unEmpleado = empleadoUno;
    Employee* otroEmpleado = empleadoDos;

    int unEmpleadoHorasTrabajadas;
    int otroEmpleadoHorasTrabajadas;

    employee_getHorasTrabajadas(unEmpleado, &unEmpleadoHorasTrabajadas);
    employee_getHorasTrabajadas(otroEmpleado, &otroEmpleadoHorasTrabajadas);

    if(unEmpleadoHorasTrabajadas>otroEmpleadoHorasTrabajadas)
    {
        compara = 1;
    }
    else
    {
        if(unEmpleadoHorasTrabajadas<otroEmpleadoHorasTrabajadas)
        {
            compara = -1;
        }
    }
    return compara;
}

int employee_compareBySueldo(void* empleadoUno, void* empleadoDos)
{
    int compara = 0;

    Employee* unEmpleado = empleadoUno;
    Employee* otroEmpleado = empleadoDos;

    int unEmpleadoSueldo;
    int otroEmpleadoSueldo;

    employee_getSueldo(unEmpleado, &unEmpleadoSueldo);
    employee_getSueldo(otroEmpleado, &otroEmpleadoSueldo);

    if(unEmpleadoSueldo>otroEmpleadoSueldo)
    {
        compara = 1;
    }
    else
    {
        if(unEmpleadoSueldo<otroEmpleadoSueldo)
        {
            compara = -1;
        }
    }
    return compara;
}

int ordenar()
{
    int opcion;

    printf("\n1.Ordenar de forma DESCENDENTE\n2.Ordenar de forma ASCENDENTE\n\nOpcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    if(opcion==1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void imprimirEmpleadosConIndice(Employee* this, int len, int indice)
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;

    employee_getId(this, &id);
    employee_getNombre(this, nombre);
    employee_getHorasTrabajadas(this, &horasTrabajadas);
    employee_getSueldo(this, &sueldo);

    printf("   ID                                   NOMBRE              HS. TRABAJADAS                 SUELDO\n\n");

    for(int i=0;i<len;i++)
    {
        printf("%3d %13d %40s %27d %22d\n", indice, id, nombre, horasTrabajadas, sueldo);
    }

}

void crearIdStr(char* idStr, LinkedList* this)
{
    int id;
    int len;
    int idRepetido;
    Employee* empleado;
    int empleadoId;

    len = ll_len(this);

    if(len>0)
    {
        do
        {
            idRepetido = 0;
            id = rand()%9000 +1000;

            for(int i=0;i<len;i++)
            {
                empleado = ll_get(this, i);
                employee_getId(empleado, &empleadoId);

                if(empleadoId==id)
                {
                    idRepetido = 1;
                    break;
                }
            }

        }while(idRepetido==1);

    }
    else
    {
        id = rand()%9000 +1000;
    }

    sprintf(idStr, "%d", id);
}

int validarNumero(char numero[])
{
    int i;
    int len;
    int numeroInt;
    int esNumero = 1;

    len = strlen(numero);

    for(i=0;i<len;i++)
    {
        if(isdigit(numero[i])==0)
        {
            esNumero = 0;
            break;
        }
    }

    numeroInt = atoi(numero);

    if(numeroInt<0)
    {
        esNumero = 0;
    }

    return esNumero;
}

int validarNombre(char nombre[])
{
    int i;
    int len;
    int esNombre = 1;

    len = strlen(nombre);

    for(i=0;i<len;i++)
    {
        if(isalpha(nombre[i])==0)
        {
            esNombre = 0;
            break;
        }
    }

    return esNombre;
}



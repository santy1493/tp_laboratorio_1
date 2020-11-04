#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

void modificarId(Employee* this);
void modificarNombre(Employee* this);
void modificarHorasTrabajadas(Employee* this);
void modificarSueldo(Employee* this);

int employee_compareById(Employee*, Employee*);
int employee_compareByNombre(Employee*, Employee*);
int employee_compareByHorasTrabajadas(Employee*, Employee*);
int employee_compareBySueldo(Employee*, Employee*);

int ordenar();

void imprimirUnEmpleado(Employee* this);
void crearIdStr(char* idStr, LinkedList* this);

#endif // employee_H_INCLUDED

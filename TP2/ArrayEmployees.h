typedef struct
{
    int id;
    char name[50];
    char lastName[50];
    float salary;
    char sector[50];
    int isEmpty;

}eEmployee;


void initEmployees(eEmployee[], int);
void addEmployees(eEmployee[], int);
void removeEmployee(eEmployee[], int);
void sortEmployees(eEmployee[], int, int);
void printEmployees(eEmployee[], int);
void modificarEmpleado(eEmployee[], int);
int menuEmpleados();
void menuListaEmpleados(eEmployee[], int);
int buscarIndiceVacio(eEmployee[], int);
int crearLegajo(eEmployee[], int);
void sueldos(eEmployee[], int);
int unEmpleadoCargado(eEmployee[], int);

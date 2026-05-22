// Created by SAMILKA AI
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// function prototypes
void PrintArrays();
void GetValidID();
void GetGrades();


// make the array size a constant

#define ROW 21
#define COL 11
#define WORD_LENGTH 30
#define COL_NUM 5
#define ID_COL 7

// global variables
int ID_ROW;
bool valid;

// initialize both sets of arrays
char data[ROW][COL][WORD_LENGTH] = {

    {"ID Universidad", "ID Carrera", "ID Materia", "Periodo", "ID Profesor", "Nombre Profesor", "Apellidos Profesor", "Matricula",   "Nombre Estudiante", "Apellido Estudiante", "Literal"},

    {"1234",           "2401",       "MAT101",     "22024",   "P1001",      "Carlos",          "Fernandez",          "2420240001", "Ana",                "Lopez",               "N/A"},
    {"1234",           "2401",       "MAT101",     "22024",   "P1001",      "Carlos",          "Fernandez",          "2420240002", "Luis",               "Martinez",            "N/A"},
    {"1234",           "2402",       "MAT101",     "22024",   "P1001",      "Carlos",          "Fernandez",          "2420240003", "Maria",              "Gomez",               "N/A"},
    {"1234",           "2402",       "MAT101",     "22024",   "P1001",      "Carlos",          "Fernandez",          "2420240004", "Pedro",              "Santos",              "N/A"},
    {"1234",           "2403",       "MAT101",     "22024",   "P1001",      "Carlos",          "Fernandez",          "2420240005", "Laura",              "Diaz",                "N/A"},
    {"1234",           "2403",       "MAT101",     "22024",   "P1001",      "Carlos",          "Fernandez",          "2420240006", "Jorge",              "Castillo",            "N/A"},
    {"1234",           "2404",       "MAT101",     "22024",   "P1001",      "Carlos",          "Fernandez",          "2420240007", "Sofia",              "Reyes",               "N/A"},
    {"1234",           "2404",       "MAT101",     "22024",   "P1001",      "Carlos",          "Fernandez",          "2420240008", "Miguel",             "Torres",              "N/A"},
    {"1234",           "2405",       "MAT101",     "22024",   "P1001",      "Carlos",          "Fernandez",          "2420240009", "Daniela",            "Vargas",              "N/A"},
    {"1234",           "2405",       "MAT101",     "22024",   "P1001",      "Carlos",          "Fernandez",          "2420240010", "Ricardo",            "Morales",             "N/A"},
    {"1234",           "2406",       "MAT101",     "22024",   "P1001",      "Carlos",          "Fernandez",          "2420240011", "Elena",              "Ruiz",                "N/A"},
    {"1234",           "2406",       "MAT101",     "22024",   "P1001",      "Carlos",          "Fernandez",          "2420240012", "Andres",             "Mendez",              "N/A"},
    {"1234",           "2407",       "MAT101",     "22024",   "P1001",      "Carlos",          "Fernandez",          "2420240013", "Camila",             "Herrera",             "N/A"},
    {"1234",           "2407",       "MAT101",     "22024",   "P1001",      "Carlos",          "Fernandez",          "2420240014", "Jose",               "Pena",                "N/A"},
    {"1234",           "2408",       "MAT101",     "22024",   "P1001",      "Carlos",          "Fernandez",          "2420240015", "Valeria",            "Nunez",               "N/A"},
    {"1234",           "2408",       "MAT101",     "22024",   "P1001",      "Carlos",          "Fernandez",          "2420240016", "Fernando",           "Acosta",              "N/A"},
    {"1234",           "2409",       "MAT101",     "22024",   "P1001",      "Carlos",          "Fernandez",          "2420240017", "Paula",              "Jimenez",             "N/A"},
    {"1234",           "2409",       "MAT101",     "22024",   "P1001",      "Carlos",          "Fernandez",          "2420240018", "Diego",              "Salazar",             "N/A"},
    {"1234",           "2410",       "MAT101",     "22024",   "P1001",      "Carlos",          "Fernandez",          "2420240019", "Natalia",            "Cruz",                "N/A"},
    {"1234",           "2410",       "MAT101",     "22024",   "P1001",      "Carlos",          "Fernandez",          "2420240020", "Samuel",             "Ortiz",               "N/A"}

};

int Notas [ROW][COL_NUM] = {

    {1000, 2000, 3000, 4000, 5000},

    {0,    0,    0,    0,    0},
    {0,    0,    0,    0,    0},
    {0,    0,    0,    0,    0},
    {0,    0,    0,    0,    0},
    {0,    0,    0,    0,    0},
    {0,    0,    0,    0,    0},
    {0,    0,    0,    0,    0},
    {0,    0,    0,    0,    0},
    {0,    0,    0,    0,    0},
    {0,    0,    0,    0,    0},
    {0,    0,    0,    0,    0},
    {0,    0,    0,    0,    0},
    {0,    0,    0,    0,    0},
    {0,    0,    0,    0,    0},
    {0,    0,    0,    0,    0},
    {0,    0,    0,    0,    0},
    {0,    0,    0,    0,    0},
    {0,    0,    0,    0,    0},
    {0,    0,    0,    0,    0},
    {0,    0,    0,    0,    0}

};

char ID[WORD_LENGTH];

int main() {
    PrintArrays();
    GetValidID();

    // esto fue para probar que cogiera la fila correcta lol
    printf("\n");
    printf("Se encuentra en la fila %d de la tabla", ID_ROW );

    /* recuerda que luego de obtener las calificaciones se
       deben desplegar los arrays de nuevo */
}

void PrintArrays() {
    int i, j, k, l;

    // print the WHOLE first row of both the char and integer data
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            for (k = 0; k < WORD_LENGTH; k++) {
                printf("%c", data[i][j][k]);
            }
            printf("  ");
        }
        for (l = 0; l < COL_NUM; l++) {
            printf("%d", Notas[i][l]);
            printf(" ");
        }
        printf("\n");
    }
}

void GetValidID() {
    valid = false;
    do{
    printf("Ingrese Matricula del estudiante: ");
    fgets(ID, WORD_LENGTH, stdin);
    /* Looks for where is the \n in fgets (because when it scans it always ends
    the string with \n) and replaces it with \0 to make sure that the strings that
    we are about to compare have the exact same termination so strcomp can do its
    thing*/
    ID[strcspn(ID, "\n")] = '\0';
    for (ID_ROW = 0; ID_ROW < ROW; ID_ROW++) {
        if (strcmp(ID, data[ID_ROW][ID_COL]) == 0) {
            valid = true;
            printf("Matricula Validada, le pertenece a %s %s", data[ID_ROW][ID_COL+1], data[ID_ROW][ID_COL+2]);
        }
        if (valid == true) {
            break;
        }
    }
    }while (!valid);
}

void GetGrades() {
    /* Aqui se pedira el input del usuario para pedir la
     * calificacion 1, 2, 3 y 4 verificando que sean validas segun lo que dijo
     * el profe en el documento
     * Se deben guardar en los indices correspondientes del array, que serian por ejemplo
     * para la calificacion 1 [ID_ROW][0] porque asi se pone del lado del estudiante y llena el
     * primer espacio
     *
     * Luego de esto, calcular calificacion final mediante la suma de todas las calificaciones
     * ingresadas y almacenarla en [ID_ROW][4] porque seria el quinto espacio.
     *
     * Ahora trabajaras comparando los valores que dio la calificacion final para obtener la calif literal
     * y la guardas en [ID_ROW][lugar donde este la calif literal]
     * recomiendo que el lugar de la literal lo pongas en una constante para no hacerlo hard coded
     *
     *
    */
}
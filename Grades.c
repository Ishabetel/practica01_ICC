// Created by SAMILKA AI
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// function prototypes
void PrintArrays();
void GetValidID();
void GetGrades();
void modificarlista(int opc);
void calcularcalif(int grade_parcial1, int grade_parcial2, int grade_practicas, int grade_examen_final);
void cambiarcalificacion();


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

char notas [ROW][COL_NUM][WORD_LENGTH] = {

    {"Parcial 1y2", "Practicas Total", "Examen Final", "Calificacion Total"},

    {"0",    "0",    "0",    "0"},   
    {"0",    "0",    "0",    "0"},    
    {"0",    "0",    "0",    "0"},    
    {"0",    "0",    "0",    "0"},    
    {"0",    "0",    "0",    "0"},    
    {"0",    "0",    "0",    "0"},    
    {"0",    "0",    "0",    "0"},    
    {"0",    "0",    "0",    "0"},    
    {"0",    "0",    "0",    "0"},
    {"0",    "0",    "0",    "0"},    
    {"0",    "0",    "0",    "0"},    
    {"0",    "0",    "0",    "0"},    
    {"0",    "0",    "0",    "0"},    
    {"0",    "0",    "0",    "0"},    
    {"0",    "0",    "0",    "0"},    
    {"0",    "0",    "0",    "0"},    
    {"0",    "0",    "0",    "0"},    
    {"0",    "0",    "0",    "0"},    
    {"0",    "0",    "0",    "0"},    
    {"0",    "0",    "0",    "0"},    

};

char ID[WORD_LENGTH];

int main() {
    PrintArrays();
    GetValidID();
    GetGrades();
    cambiarcalificacion();

    // esto fue para probar que cogiera la fila correcta lol
    printf("\n");
    printf("Se encuentra en la fila %d de la tabla", ID_ROW );

    PrintArrays();
    /* recuerda que luego de obtener las calificaciones se
       deben desplegar los arrays de nuevo */
}

void PrintArrays() {
    int i, j, k, l;

    // print the WHOLE first row of both the char and integer data
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            printf("%s", data[i][j]); //usar "%s" porque es un char array, no un int, evitando errores
            printf("  ");
        }
        for (l = 0; l < COL_NUM; l++) {
           printf("%s", notas[i][l]);
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
    int grade_parcial1 = 0,grade_parcial2 = 0, grade_practicas = 0, grade_examen_final = 0;
    
    do {
        printf("\nIngrese la calificacion del Parcial 1 (0-10): "); 
        scanf("%d" , &grade_parcial1);
        
        if (grade_parcial1 < 0 || grade_parcial1 > 10) {
            printf("Calificacion no valida, debe ser de 0 a 10\n");
        }
    } while (grade_parcial1 < 0 || grade_parcial1 > 10);
    do {
        printf("\nIngrese la calificacion del Parcial 2 (0-10): "); 
        scanf("%d" , &grade_parcial2);
        
        if (grade_parcial2 < 0 || grade_parcial2 > 10) {
            printf("Calificacion no valida, debe ser de 0 a 10\n");
        }
    } while (grade_parcial2 < 0 || grade_parcial2 > 10);
    do {
        printf("\nIngrese las calificaciones de las practicas (0-30): "); 
        scanf("%d" , &grade_practicas);
        
        if (grade_practicas < 0 || grade_practicas > 30) {
            printf("Calificacion no valida, debe ser de 0 a 30\n");
        }
    } while (grade_practicas < 0 || grade_practicas > 30);

    do {
        printf("\nIngrese la calificacion del Examen Final (0-30): "); 
        scanf("%d" , &grade_examen_final);
        
        if (grade_examen_final < 0 || grade_examen_final > 30) {
            printf("Calificacion no valida, debe ser de 0 a 30\n");
        }
    } while (grade_examen_final < 0 || grade_examen_final > 30);

    calcularcalif(grade_parcial1, grade_parcial2, grade_practicas, grade_examen_final);

}

void calcularcalif(int grade_parcial1, int grade_parcial2, int grade_practicas, int grade_examen_final) {
    int parcial_total = 0, calif_final = 0;

    parcial_total = grade_parcial1 + grade_parcial2;
    calif_final = parcial_total + grade_practicas + grade_examen_final;

    sprintf(notas[ID_ROW][0], "%d", parcial_total);
    sprintf(notas[ID_ROW][1], "%d", grade_practicas);
    sprintf(notas[ID_ROW][2], "%d", grade_examen_final);
    sprintf(notas[ID_ROW][3], "%d", calif_final);


    switch(calif_final) {
        case 90 ... 100:
            strcpy(data[ID_ROW][10], "A");break;
        case 80 ... 89:
            strcpy(data[ID_ROW][10], "B");break;
        case 70 ... 79:
            strcpy(data[ID_ROW][10], "C");break;
        case 60 ... 69:
            strcpy(data[ID_ROW][10], "D");break;
        default:
            strcpy(data[ID_ROW][10], "F"); break;
    }

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

void cambiarcalificacion() {
    // esta funcion es para cambiar la calificacion de un estudiante, se le pide al usuario que ingrese la matricula del estudiante, se valida que exista, y luego se le pide que ingrese la nueva calificacion, se valida que sea correcta, y se actualiza el array con la nueva calificacion
    GetValidID();
    int opc;
    do {
    opc = 0;
    printf("Que busca cambiar? \n1. Parcial 1 \n2. Parcial 2 \n3. Practicas \n4. Examen Final \n5.Salir \n"); scanf("%d", &opc);
    modificarlista(opc);
    PrintArrays();
    } while (opc != 5 || opc < 1 || opc > 5);
}


void modificarlista(int opc)
{
  int grade_parcial1 = 0, grade_parcial2 = 0, grade_practicas = 0, grade_examen_final = 0, calif_final = 0, reemplazo = 0;
  grade_parcial1 = (int) strtol(notas[ID_ROW][0], NULL, 10);
  grade_parcial2 = (int) strtol(notas[ID_ROW][1], NULL, 10);
  grade_practicas = (int) strtol(notas[ID_ROW][2], NULL, 10);
  grade_examen_final = (int) strtol(notas[ID_ROW][3], NULL, 10);

  printf("Inserta nuevo valor: ");
  scanf("%d", &reemplazo);

  switch(opc) {
    case 1:
        grade_parcial1 = reemplazo; break;
    case 2:
        grade_parcial2 = reemplazo; break;
    case 3:
        grade_practicas = reemplazo; break;
    case 4:
        grade_examen_final = reemplazo; break;
    default:break;
  }

  calcularcalif(grade_parcial1,grade_parcial2,grade_practicas,grade_examen_final);
}


//sprintf(lista[opc][3], "%d", disponible);
//Use strcpy (or better, strncpy) when you need to copy a plain string from one location to another without modification. It is generally faster because it has less overhead than a formatting function.
// Use sprintf (or better, snprintf) when you need to format a string—for example, by combining text with integers or other variables into a single buffer.
// Creado por el grupo SAMILKA AI *si profe le pusimos ese nombre*
// Este codigo fue creado con sangre, sudor y lagrimas de Andrey e Ishabetel
// Cada una de las lineas escritas en el siguiente programa encapsula el trabajo
// esclavizado de sus creadores. Necesitamos tocar pasto ASAP.
#include <ctype.h>
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
void CheckStudent();


// make the array size a constant

#define ROW 21
#define COL 11
#define WORD_LENGTH 30
#define COL_NUM 5
#define ID_COL 7

// global variables
int ID_ROW;
bool valid;
bool Student = false;

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

    {"Parcial 1", "Parcial 2", "Practicas Total", "Examen Final", "Calificacion Total"},

    {"0",    "0",    "0",    "0", "0"},   
    {"0",    "0",    "0",    "0", "0"},    
    {"0",    "0",    "0",    "0", "0"},    
    {"0",    "0",    "0",    "0", "0"},    
    {"0",    "0",    "0",    "0", "0"},    
    {"0",    "0",    "0",    "0", "0"},    
    {"0",    "0",    "0",    "0", "0"},    
    {"0",    "0",    "0",    "0", "0"},    
    {"0",    "0",    "0",    "0", "0"},    
    {"0",    "0",    "0",    "0", "0"},    
    {"0",    "0",    "0",    "0", "0"},    
    {"0",    "0",    "0",    "0", "0"},    
    {"0",    "0",    "0",    "0", "0"},    
    {"0",    "0",    "0",    "0", "0"},    
    {"0",    "0",    "0",    "0", "0"},    
    {"0",    "0",    "0",    "0", "0"},    
    {"0",    "0",    "0",    "0", "0"},    
    {"0",    "0",    "0",    "0", "0"},    
    {"0",    "0",    "0",    "0", "0"},    
    {"0",    "0",    "0",    "0", "0"},    

};

char ID[WORD_LENGTH];

int main() {

    /* PrintArrays -> GetValidID -> Checkstudent -> Getgrades -> (1) New student?
     * (2) Modify? (3) exit? -> (1) GetvalidID -> check student -> check grades. */
    char Sec[10];
    int selection;

    printf("\n");
    printf("\n");
    printf("                      ************ BIENVENIDO AL REGISTRO DE CALIFICACIONES *****************                            ");
    printf("\n");
    printf("\n");

    PrintArrays();


    do {
        printf("Que accion desea realizar? [1] Agregar nueva calificacion "
       "[2] Cambiar calificacion [3] Salir del programa\n");

        // verify that the input is a number so the code doesn't EXPLODE
        scanf("%9s", Sec);
        if (isdigit(Sec[0]) && Sec[1] == '\0') {
            selection = atoi(Sec);
            switch (selection) {
                case 1:
                    do {
                        GetValidID();
                        CheckStudent();
                    } while (Student == false);
                    GetGrades();
                    PrintArrays();
                    Student = false;
                    break;

                case 2:
                    printf("Se selecciono cambio de calificacion \n");
                    do {
                        GetValidID();
                        CheckStudent();
                    } while (Student == false);
                    cambiarcalificacion();
                    PrintArrays();
                    Student = false;
                    break;

                case 3: system("cls"); printf(" Saliendo del Programa... "); break;

                default:
                    printf("Opcion invalida. \n");
            }
        } else printf("Opcion invalida. \n");

    } while (selection != 3);

}

void PrintArrays() {
    int i, j, l;
    // system("cls");
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
        if (ID[0] == ' ') {
            printf("Usage error: Debe ingresar la matricula sin"
                   " espacios en blanco al inicio o final.\n");
            printf("\n");
            break;
        }
        if (strcmp(ID, data[ID_ROW][ID_COL]) == 0) {
            valid = true;
            printf("Matricula Validada, le pertenece a %s %s", data[ID_ROW][ID_COL+1], data[ID_ROW][ID_COL+2]);
            printf("\n");
        }
        if (valid == true) {
            break;
        }
    }
    }while (!valid);
}

void CheckStudent() {
        char check[10];
        int selected = 0;
        bool ValidOp = false;
    do{
    
     printf("Desea agregar o modificar la calificacion de %s %s? [1] si [2] volver hacia atras \n",
     data[ID_ROW][ID_COL+1], data[ID_ROW][ID_COL+2]);
        scanf("%9s", check);
        if (isdigit(check[0]) && check[1] == '\0') {
            selected = (int) strtol(check, NULL, 10);
        } else {
            printf("Opcion invalida \n"); ValidOp = false;
            continue;
        }
    switch (selected) {
        case 1: Student = true; ValidOp = true; break;
        case 2: Student = false; ValidOp = true; break;
        default: ValidOp = false; printf("Opcion invalida \n"); break;
    }
    } while (ValidOp == false);

}

void GetGrades() {
    char grade_parcial1[3],
    grade_parcial2[3],
    grade_practicas[3],
    grade_examen_final[3];

    bool Check1, Check2, Check3, Check4;

    int P1, P2, Prac, EX;

    // Consegir nota de practica 1
    do {

        Check1 = true;

        printf("\nIngrese la calificacion del Parcial 1 (0-20): ");

        // solo escaneo dos espacios del array
        scanf("%s", grade_parcial1);

        // verificar que todos los caracteres sean digitos menos el nulo
        for (int i = 0; grade_parcial1[i] != '\0' && i < 2; i++) {

            if (!isdigit(grade_parcial1[i])) {
                Check1 = false;
            }
        }


        if (Check1) {

            // convierto a int
            P1 = atoi(grade_parcial1);

            if (P1 < 0 || P1 > 20) {
                printf("Calificacion no valida\n");
                Check1 = false;
            }
        }
        else {
            printf("Debe ingresar solo numeros\n");
        }

    } while (!Check1);

    // conseguir nota de practica 2



    do {
        Check2 = true;
        printf("\nIngrese la calificacion del Parcial 2 (0-20): ");

        // solo escaneo dos espacios del array
        scanf("%s", grade_parcial2);

        // verificar que todos los caracteres sean digitos menos el nulo
        for (int i = 0; grade_parcial2[i] != '\0' && i < 2; i++) {

            if (!isdigit(grade_parcial2[i])) {
                Check2 = false;
            }
        }

        if (Check2) {

            // convierto a int
            P2 = atoi(grade_parcial2);

            if (P2 < 0 || P2 > 20) {
                printf("Calificacion no valida\n");
                Check2 = false;
            }
        }
        else {
            printf("Debe ingresar solo numeros\n");
        }

    } while (!Check2);

    do {
        Check3 = true;
        printf("\nIngrese la calificacion de las Practicas (0-30): ");

        // solo escaneo dos espacios del array
        scanf("%s", grade_practicas);

        // verificar que todos los caracteres sean digitos menos el nulo
        for (int i = 0; grade_practicas[i] != '\0' && i < 2; i++) {

            if (!isdigit(grade_practicas[i])) {
                Check3 = false;
            }
        }


        if (Check3) {

            // convierto a int
            Prac = atoi(grade_practicas);

            if (Prac < 0 || Prac > 30) {
                printf("Calificacion no valida\n");
                Check3 = false;
            }
        }
        else {
            printf("Debe ingresar solo numeros\n");
        }

    } while (!Check3);

    do {
        Check4 = true;
        printf("\nIngrese la calificacion del Examen final (0-30): ");

        // solo escaneo dos espacios del array
        scanf("%s", grade_examen_final);

        // verificar que todos los caracteres sean digitos menos el nulo
        for (int i = 0; grade_examen_final[i] != '\0' && i < 2; i++) {

            if (!isdigit(grade_examen_final[i])) {
                Check4 = false;
            }
        }

        if (Check4) {

            // convierto a int
            EX = atoi(grade_examen_final);

            if (EX < 0 || EX > 30) {
                printf("Calificacion no valida\n");
                Check4 = false;
            }
        }
        else {
            printf("Debe ingresar solo numeros\n");
        }

    } while (!Check4);

    calcularcalif(P1,P2,Prac,EX);

}

void calcularcalif(int grade_parcial1, int grade_parcial2, int grade_practicas, int grade_examen_final) {
    int parcial_total = 0, calif_final = 0;

    parcial_total = grade_parcial1 + grade_parcial2;
    calif_final = parcial_total + grade_practicas + grade_examen_final;

    sprintf(notas[ID_ROW][0], "%d", grade_parcial1);
    sprintf(notas[ID_ROW][1], "%d", grade_parcial2);
    sprintf(notas[ID_ROW][2], "%d", grade_practicas);
    sprintf(notas[ID_ROW][3], "%d", grade_examen_final);
    sprintf(notas[ID_ROW][4], "%d", calif_final);


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
    // esta funcion es para cambiar la calificacion de un estudiante, se le pide al usuario que ingrese la matricula del estudiante,
    // se valida que exista, y luego se le pide que ingrese la nueva calificacion, se valida que sea correcta,
    // y se actualiza el array con la nueva calificacion
    //GetValidID();
    int opc;
    do {
    opc = 0;
    printf("Que busca cambiar? \n1. Parcial 1 \n2. Parcial 2 \n3. Practicas \n4. Examen Final \n5. Menu \n"); scanf("%d", &opc);
    if (opc >= 1 && opc < 5) {
    modificarlista(opc);
    PrintArrays();}
    else if (opc == 5) {
        printf("Volviendo al inicio... \n");
    }
    else{
        printf("Opcion no valida, intente de nuevo \n");}
    } while (opc != 5 || opc < 1 || opc > 5);
}


void modificarlista(int opc)
{
  int grade_parcial1 = 0, grade_parcial2 = 0, grade_practicas = 0, grade_examen_final = 0, calif_final = 0; int rem = 0;
  grade_parcial1 = (int) strtol(notas[ID_ROW][0], NULL, 10);
  grade_parcial2 = (int) strtol(notas[ID_ROW][1], NULL, 10);
  grade_practicas = (int) strtol(notas[ID_ROW][2], NULL, 10);
  grade_examen_final = (int) strtol(notas[ID_ROW][3], NULL, 10);

  bool CheckA;
  char reemplazo[3];
  do{
  CheckA = true;
        printf("Inserta nuevo valor: ");

        // solo escaneo dos espacios del array
        scanf("%s", reemplazo);

        // verificar que todos los caracteres sean digitos menos el nulo
        for (int i = 0; reemplazo[i] != '\0' && i < 2; i++) {

            if (!isdigit(reemplazo[i])) {
                CheckA = false;
            }
        }
        if (CheckA) {
            // convierto a int
            rem = atoi(reemplazo);
        }
        else {
            printf("Debe ingresar solo numeros\n"); continue;
        }
        
  switch(opc) {
    case 1:
        if (rem < 0 || rem > 20) {
                printf("Calificacion no valida\n");
                CheckA = false;
                continue;} //continue = skip to next iteration of loop (skip button)
        else{grade_parcial1 = rem; break;}
    case 2:
        if (rem < 0 || rem > 20) {
                printf("Calificacion no valida\n");
                CheckA = false;
                continue;}
        else{grade_parcial2 = rem; break;}
    case 3:
        if (rem < 0 || rem > 30) {
                printf("Calificacion no valida\n");
                CheckA = false;
                continue;}    
        else{grade_practicas = rem; break;}
    case 4:
        if (rem < 0 || rem > 30) {
                printf("Calificacion no valida\n");
                CheckA = false;
                continue;}
        else{grade_examen_final = rem; break;}
    default:break;
  }

  } while (!CheckA);

  calcularcalif(grade_parcial1,grade_parcial2,grade_practicas,grade_examen_final);
}


//sprintf(lista[opc][3], "%d", disponible);
//Use strcpy (or better, strncpy) when you need to copy a plain string from one location to another without modification. It is generally faster because it has less overhead than a formatting function.
// Use sprintf (or better, snprintf) when you need to format a string—for example, by combining text with integers or other variables into a single buffer
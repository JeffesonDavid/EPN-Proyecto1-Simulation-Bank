#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <conio.h>
#include "../lib/features.h"

/**************************************************************
Date         : 17.jun.2022
Developer's  : Chileno Jefferson - Narváez Jhoel - Palma Darío
Subject      : Simulation Bank
**************************************************************/

const int DELAY = 1000; // Tiempo de espera
char EnterOrExit;
int positionUserFree; // indica la posicion de usuario

// BUSCA POSITION LIBRE PARA CREAR NUEVO USUARIO
void searchPositionFree()
{
    for (int i = 0; i < 100; i++)
        if (usuarios[i].user[0] == '\0') // si la propiedad esta vacia
        {
            positionUserFree = i;
            break;
        }
}

// CREAR NUEVO USUARIO
void createNewUser()
{
    searchPositionFree(); // ESPACIO PARA NUEVO USUARIO
    // printf("\n soy la posicion %d y estoy vacia", positionUserFree); // revisar la posición vacia

    // GUARDAMOS EL NOMBRE
    fflush(stdin); // LIMPIA EL BUFFER - si no, no permite ingresar a nombre, salta a contrasenia
    printf("\n COMPLETE LOS SIGUIENTES CAMPOS - COMPLETE THE FOLLOWING FIELDS\n");
    printf("\n Nombre - Name:\t\t\t");
    scanf("%s", &usuarios[positionUserFree].user);
    // GUARDAMOS LA CONSTRASEÑA
    fflush(stdin); // LIMPIA EL BUFFER - si no, no permite ingresar a contraseña, salta a email
    printf(" Contrasena - Password:\t\t");
    scanf("%s", &usuarios[positionUserFree].password);
    // GUARDAMOS EMAIL
    fflush(stdin); // LIMPIA EL BUFFER - si no, no permite ingresar a email, salta a country
    printf(" Correo - Email:\t\t");
    scanf("%s", &usuarios[positionUserFree].email);
    // GUARDAMOS PAIS
    fflush(stdin); // LIMPIA EL BUFFER - si no, no permite ingresar a country, salta a city
    printf(" Pais - Country:\t\t");
    scanf("%s", &usuarios[positionUserFree].county);
    // GUARDAMOS CIUDAD
    fflush(stdin); // LIMPIA EL BUFFER - si no, no permite ingresar a city, salta a phoneNumber
    printf(" Ciudad - City:\t\t\t");
    scanf("%s", &usuarios[positionUserFree].city);
    // GUARDAMOS TELEFONO
    fflush(stdin); // LIMPIA EL BUFFER - si no, no permite ingresar a phoneNumber, salta a IdentificationCard
    printf(" Telefono - Phone number:\t0");
    scanf("%s", &usuarios[positionUserFree].phoneNumber);
    // GUARDAMOS IDENTIFICACION
    fflush(stdin); // LIMPIA EL BUFFER - RAM
    printf(" Pasaporte - Passport:\t\t");
    scanf("%s", &usuarios[positionUserFree].identificationCard);
    // ASIGNAR UN ID UNICO
    int ID_Unico = rand() % (maxID - minID + 1) + minID; // ID de 6 cifras
    for (int i = 0; i < positionUserFree; i++)           // BUSCAR TODOS LOS ID - aseguramos todos los anteriores ID son !=
    {
        if (ID_Unico == usuarios[i].ID) // ¿Hay usuario con mismo ID?
        {
            while (ID_Unico == usuarios[i].ID)                   // Cambia numero hasta que sea diferente
                ID_Unico = rand() % (maxID - minID + 1) + minID; // ID NO SE REPITE

            i = -1; // SUPER IMPORTANTE, volvemos a pregunta desde el principio ¿Hay usuario con mismo ID?
        }
    }
    usuarios[positionUserFree].ID = ID_Unico;
    /*TENER ID UNICO*/
    // d  (a   a)  a→ c  →→→  d (a != c) → unico
    // d  (a   a)  a→ d  →→→  d (a != d) → unico  PERO  d == d
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Rutina Principal
void main()
{
    srand(time(NULL)); // Semilla numero aleatorio
    getch();
    inicioAnimacion();
    do
    {
        system("cls");
        inicio();
        scanf("%c", &EnterOrExit);

        if (EnterOrExit == '1') // INCIAR SESION
        {
        volverIniciar:
            system("cls");

            int buscarID;
            char buscarpass[20];
            int result;
            int userPosition; // Posicion usuario
            bool flagSessionSucces = false;
            flagSessionSucces = false; // reiniciar para buscar en cada iteracion

            system("cls");
            HEADER();
            printf(" Inicio / Iniciar Sesion\n");
            printf("\n\n\n\n\n\n\n\t\t\t\t USERNAME:     ");
            scanf("%i", &buscarID);
            printf("\n\n\t\t\t\t PASSWORD:     ");
            fflush(stdin);
            scanf("%s", &buscarpass);

            for (int i = 0; i < 25; i++)
                if (buscarID == usuarios[i].ID)
                {
                    userPosition = i;
                    result = strcmp(usuarios[i].password, buscarpass);
                    // printf("\n \t\t\t Sale 0 contrasenia correcta = %d", result);
                    if (result == 0)
                        flagSessionSucces = true;
                    break;
                }

            if (flagSessionSucces == false)
            {
                printf("\n\n\n\n\n\t\t\t Usuario o Contrasenia incorrecta ");
                getch();
            }

            if (flagSessionSucces == true) // SI ES QUE INICIA SESSION MOSTRAR OPERACIONES
            {
                system("cls");
                HEADER();
                printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t Iniciando Sesion...\n\n");
                showBarrRotateCenter(5);
                system("cls");
                do
                {
                    system("cls");
                    HEADER();
                    printf(" Inicio / Operaciones\n");
                    printf("\n\t\t\t\tW E L C O M E   B A C K, %s\n", usuarios[userPosition].user);
                    printf("\n Lista de opciones\n"
                           "\n 1. Realizar Desposito"
                           "\n 2. Realizar Trasaccion"
                           "\n 3. Ralizar Retiro"
                           "\n\n 0. Salir");

                    printf("\n\n Ingrese una opcion: ");
                    scanf("%s", &EnterOrExit);
                    int Option = EnterOrExit - '0'; // CHAR TO INT
                    float deposito;
                    // int Option = atoi(EnterOrExit); // CHAR TO INT - DON'T WORK
                    switch (Option)
                    {
                    case 1:
                        system("cls");
                        HEADER();
                        printf(" Usuario / Inicio / Deposito\n");

                        printf("\n Dinero a depositar:\t$ ");
                        scanf("%f", &deposito);
                        system("cls");
                        HEADER();
                        printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t Terminamos en un momento...\n\n");
                        showBarrRotateCenter(5);
                        system("cls");
                        HEADER();
                        printf(" Usuario / Inicio / Deposito\n");
                        printf("\n\n Saldo anterior:\t$ %.2f", usuarios[userPosition].cash);
                        usuarios[userPosition].cash += deposito;
                        printf("\n Saldo actual:\t\t$ %-.2f", usuarios[userPosition].cash);
                        printf("\n\n\n\n\n\t\t\t El deposito se realizo correctamente.\n");
                        getch();
                        break;
                    case 2:

                        break;
                    default:
                        printf("\n\n La operacion indicada, no existe.\n");
                        break;
                    }
                } while (EnterOrExit != '0');
                EnterOrExit = 'a'; // SALIR AL MENU PRINCIPAL
            }
            else
                goto volverIniciar; // Volver a iniciar sesion
        }
        if (EnterOrExit == '2') // CREAR CUENTA
        {
            system("cls");
            HEADER();
            printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t CARGANDO REGISTRO... \n\n");
            showBarrRotateCenter(3);
            system("cls");
            HEADER();
            printf(" Inicio / Crear usuario\n");
            createNewUser();
            printf("\n\n CONFIRMACION DE REGISTRO DE CUENTA \n\n"
                   " 0. confirmar \n"
                   " 1. Salir\n\n\n\n\n\n"
                   "\t\t\t\tIngrese una opcion: ");
            fflush(stdin);
            scanf("%s", &EnterOrExit);

            if (EnterOrExit == '0') // GUARDAR USUARIO
            {
                system("cls");
                HEADER();
                printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t VALIDANDO DATOS...\n\n");
                showBarrRotateCenter(30);

                system("cls");
                HEADER();
                // printf("\n soy la posicion %d y estoy llena", positionUserFree); // revisar la posición vacia
                printf(" Inicio / Crear Usuario / Resumen\n");
                printf("\n REGISTRO COMPLETO\n");
                printf("\n Resumen breve\n");
                printf("\n Codigo Unico:\t\t%-d", usuarios[positionUserFree].ID);
                printf("\n Nombre:\t\t%-s", usuarios[positionUserFree].user);
                printf("\n Correo:\t\t%-s", usuarios[positionUserFree].email);

                printf("\n\n Nota: Guardar su user ID (codigo unico).\n Porque todas las transacciones se realizaran con este codigo\n\n\n\n\n\n\n\n\n\n\n\n\n"
                       "\t\t\t\tPresione 0 para continuar ");
                // GUARDAR EN FICHEROS
                FILE *fichero = fopen("usuarios.txt", "a"); // busca/crear archivo +baseDeDatos.txt+
                if ((fichero) == NULL)
                    perror("No se ha posido establecer conexion con el archivo"); // informa si hay errores con PERROR y MUESTRA CUAL ES EL PROBLE EN ESPECIFICO

                fprintf(fichero, "\n\n {%d,"
                                 "%s"
                                 ",%s"
                                 ",%s"
                                 ",%s"
                                 ",%s"
                                 ",%s"
                                 ",%s"
                                 ",%.2f}",
                        usuarios[positionUserFree].ID, usuarios[positionUserFree].user, usuarios[positionUserFree].password, usuarios[positionUserFree].email, usuarios[positionUserFree].county, usuarios[positionUserFree].city, usuarios[positionUserFree].phoneNumber, usuarios[positionUserFree].identificationCard, usuarios[positionUserFree].cash);

                fflush(fichero); // LIMPIAR FICHERO Y RAM
                fclose(fichero); // CERRAR EL FICHERO
                getch();

                EnterOrExit = 'a'; // SALIR AL MENU PRINCIPAL
            }
            else                   // NO HACE NADA POR EL MOMENTO
                EnterOrExit = 'a'; // NO GUARDAR USUARIO y SALIR MENU AL PRINCIPAL
        }

    } while (EnterOrExit != '0');
}

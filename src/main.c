#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <conio.h>
#include "../lib/JeffTools.h"

/**************************************************************
Date       : 17.jun.2022
Developer's  : Chileno Jefferson - Narváez Jhoel - Palma Darío
Subject    : Simulation Bank
***************************************************************/

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
    searchPositionFree();                                            // ESPACIO PARA NUEVO USUARIO
    printf("\n soy la posicion %d y estoy vacia", positionUserFree); // revisar la posición vacia

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

// BUSCAR USUARIO EN BASE DE DATOS <jeffTool.h>
void searchUser()
{
    int searchID;              // guardaremos lo que ingrese por consola
    bool flagFindUser = false; // ayuda para indicar que se ha encontrado el usuario solicitado
    flagFindUser = false;      // reiniciar para buscar en cada iteracion
    // do
    // {
    system("cls");
    HEADER();
    printf("\n Por favor, ingrese el ID para buscarlo en la base de datos: ");
    scanf("%i", &searchID);
    printf(" BUSCANDO...POR FAVOR ESPERE\n");
    showBarrRotate(3);
    for (int i = 0; i < 100; i++)
        if (searchID == usuarios[i].ID)
        {
            system("cls");
            HEADER();
            printf(" \nESTADO DE CUENTA\n\n"
                   " Codigo Unico / ID:\t\t%-d\n"
                   " Usuario / User:\t\t%-s\n"
                   " Correo / Email:\t\t%-s\n"
                   " Identificacion:\t\t%-s\n"
                   " Pais / Country:\t\t%-s\n"
                   " Ciudad / City:\t\t\t%-s\n"
                   " Telefono / Phone:\t\t0%-s\n"
                   " Saldo / Balance:\t\t$ %-.2f\n",
                   usuarios[i].ID, usuarios[i].user, usuarios[i].email, usuarios[i].identificationCard, usuarios[i].county, usuarios[i].city, usuarios[i].phoneNumber, usuarios[i].cash);
            printf("-------------------------------------------------------------------------------\n");
            flagFindUser = true; // Encontre user
            break;
        }

    if (flagFindUser != true)
    {
        system("cls");
        HEADER();
        printf("\n\n El usuario '%d' no se encuentra registrado en la base de datos.\n"
               " Revise e intentelo nuevamente.\n\n",
               searchID);
    }
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

            // JHOELLLLLLLL
            // primero necesitas buscar el Id, elabora algo para obtener ese ID

            if (true) // SI ES QUE INICIA SESSION MOSTRAR OPERACIONES
            {
                do
                {
                    system("cls");
                    HEADER();
                    printf("\n\t\t\t\tW E L C O M E   B A C K:\n");
                    printf("\n Lista de opciones\n"
                           "\n 1. Realizar Desposito"
                           "\n 2. Realizar Trasaccion"
                           "\n 3. Ralizar Retiro"
                           "\n\n 0. Salir");

                    printf("\n\n Ingrese una opcion: ");
                    scanf("%s", &EnterOrExit);
                    int Option = EnterOrExit - '0'; // CHAR TO INT
                    // int Option = atoi(EnterOrExit); // CHAR TO INT - DON'T WORK
                    switch (Option)
                    {
                    case 1:
                        // DARÍOOOOOO
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
            {
                // SI NO INICIA SESION QUE HACE????? JOEELLLLLL
            }
        }
        if (EnterOrExit == '2') // CREAR CUENTA
        {
            system("cls");
            HEADER();
            printf("\n CARGANDO REGISTRO... \n\n");
            showBarrRotate(3);
            system("cls");
            HEADER();
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
                printf("\n VALIDANDO DATOS...\n\n");
                showBarrRotate(30);

                system("cls");
                HEADER();
                printf("\n soy la posicion %d y estoy llena", positionUserFree); // revisar la posición vacia
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

                fprintf(fichero, " \nESTADO DE CUENTA\n\n"
                                 " Codigo Unico / ID:\t\t%-d\n"
                                 " Usuario / User:\t\t%-s\n"
                                 " Correo / Email:\t\t%-s\n"
                                 " Identificacion:\t\t%-s\n"
                                 " Pais / Country:\t\t%-s\n"
                                 " Ciudad / City:\t\t\t%-s\n"
                                 " Telefono / Phone:\t\t0%-s\n"
                                 " Saldo / Balance:\t\t$ %-.2f\n\n\n",
                        usuarios[positionUserFree].ID, usuarios[positionUserFree].user, usuarios[positionUserFree].email, usuarios[positionUserFree].identificationCard, usuarios[positionUserFree].county, usuarios[positionUserFree].city, usuarios[positionUserFree].phoneNumber, usuarios[positionUserFree].cash);

                // fprintf(fichero, "\n\n {%d,"
                //                  "%s"
                //                  ",%s"
                //                  ",%s"
                //                  ",%s"
                //                  ",%s"
                //                  ",%s"
                //                  ",%s"
                //                  ",%.2f}",
                //         usuarios[positionUserFree].ID, usuarios[positionUserFree].user, usuarios[positionUserFree].password, usuarios[positionUserFree].email, usuarios[positionUserFree].county, usuarios[positionUserFree].city, usuarios[positionUserFree].phoneNumber, usuarios[positionUserFree].identificationCard, usuarios[positionUserFree].cash);

                fflush(fichero); // LIMPIAR FICHERO Y RAM
                fclose(fichero); // CERRAR EL FICHERO
                getch();

                EnterOrExit = 'a'; // SALIR AL MENU PRINCIPAL
            }
            else                   // NO HACE NADA POR EL MOMENTO
                EnterOrExit = 'a'; // NO GUARDAR USUARIO y SALIR MENU AL PRINCIPAL
        }

    } while (EnterOrExit != '0');

    // CONSULTA TODOS LOS USUARIOS

    // fflush(stdin);
    // HEADER();
    // searchPositionFree();
    // fflush(stdin);
    // for (int i = 0; i <= positionUserFree; i++)
    // {
    //     // printf(" %d\t\t%s\t\t$%.2f\n", usuarios[i].ID, usuarios[i].user, usuarios[i].cash);
    //     printf(" ESTADO DE CUENTA\n\n"
    //            " Codigo Unico / ID:\t\t%-d\n"
    //            " Usuario / User:\t\t%-s\n"
    //            " Correo / Email:\t\t%-s\n"
    //            " Identificacion:\t\t%-s\n"
    //            " Pais / Country:\t\t%-s\n"
    //            " Ciudad / City:\t\t\t%-s\n"
    //            " Telefono / Phone:\t\t0%-s\n"
    //            " Saldo / Balance:\t\t$ %-.2f\n",
    //            usuarios[i].ID, usuarios[i].user, usuarios[i].email, usuarios[i].identificationCard, usuarios[i].county, usuarios[i].city, usuarios[i].phoneNumber, usuarios[i].cash);
    //     printf("-------------------------------------------------------------------------------\n");
    // }
    // getch();
}

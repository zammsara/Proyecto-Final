#include <iostream>
#include <string.h>
#include "variables.h"
#include <locale.h>
#include <windows.h>


#define ANSI_COLOR_RED_BACKGROUND "\x1b[41m"
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_RESET "\x1b[0m"


using namespace std;

INFORMACION registros[MAX_REG];
int pos = 0;

int obtenerReg(int CodigoPrestamo);
void registroPrestamos(INFORMACION * c);
void editar(INFORMACION *c, int CodigoPrestamo);
void eliminar(int CodigoPrestamo);
void mostrarPrestamos();
INFORMACION buscar(int CodigoPrestamo);
void solicitarDatos();
void editarxRegistro();
void eliminarxRegistro();
void buscarxCodigoPrestamo();
void mostrarTPrestamos();
void showReg(INFORMACION * c);
void editarRegistro();
int menu();
void principal();


void registroPrestamos(INFORMACION * c){
    registros[pos] = *c;
    pos++;
}


INFORMACION buscar(int CodigoPrestamo)
{
    for(int i = 0; i < pos; i++)
    {
        if(CodigoPrestamo == registros[i].CodigoPrestamo)
        {
            return registros[i];
        }
    }
    INFORMACION c = {};
    return c;
}


int obtenerReg(int CodigoPrestamo){
    for (int i = 0; i < pos; i++)
    {
        if (registros[i].CodigoPrestamo == CodigoPrestamo)
        {
            return i;
        }
    }
    return -1;
}

int menu(){
    setlocale(LC_ALL, "spanish");
    int op;
    cout << ANSI_COLOR_RED_BACKGROUND << "Bienvenido al sistema de prestamos" << ANSI_COLOR_RESET<<endl; 
    cout << ANSI_COLOR_RED << "-------------------------------------------------------------------------" << ANSI_COLOR_RESET<<endl;
    cout << ANSI_COLOR_RED << "1. Registrar un nuevo prestamo" << ANSI_COLOR_RESET<<endl;
    cout << ANSI_COLOR_RED << "2. Editar registro" << ANSI_COLOR_RESET<<endl;
    cout << ANSI_COLOR_RED << "3. Eliminar registro" << ANSI_COLOR_RESET<<endl;
    cout << ANSI_COLOR_RED << "4. Buscar registro" << ANSI_COLOR_RESET<<endl;
    cout << ANSI_COLOR_RED << "5. Mostrar los registros" << ANSI_COLOR_RESET<<endl;
    cout << ANSI_COLOR_RED << "6. Salir" << ANSI_COLOR_RESET<<endl;
    cout << ANSI_COLOR_RED << "-------------------------------------------------------------------------" << ANSI_COLOR_RESET<<endl;
    cout << ANSI_COLOR_RED << "Digite la opcion: " << ANSI_COLOR_RESET<<endl;
    cin >> op;
    return op;
}

void principal()
{
    int op;
    do
    {
        op = menu();
        switch (op)
        {
            case 1:
                solicitarDatos();
                break;
            case 2:
                editarxRegistro();
                break;
            case 3:
                eliminarxRegistro();
                break;
            case 4:
                buscarxCodigoPrestamo();
                break;
            case 5:
                mostrarTPrestamos();
                break;
            case 6:
                cout << ANSI_COLOR_RED << "Saliendo del sistema..." << ANSI_COLOR_RESET<<endl;
                break;
            default:
                cout << ANSI_COLOR_RED << "Opcion no valida, intente nuevamente." << ANSI_COLOR_RESET<<endl;
        }

    } while (op != 6);
}


void solicitarDatos(){
    INFORMACION registros;
    cout << ANSI_COLOR_RED_BACKGROUND << "Registro de nuevo prestamo" << ANSI_COLOR_RESET<<endl;
    cout << ANSI_COLOR_RED << "Digite el codigo del prestamo: " << ANSI_COLOR_RESET<<endl;
    cin >> registros.CodigoPrestamo;
    cout << ANSI_COLOR_RED << "Digite el nombre del cliente: " << ANSI_COLOR_RESET<<endl;
    scanf(" %[^\n]", registros.NombreCompleto);
    cout << ANSI_COLOR_RED << "Digite el numero de cedula del cliente: " << ANSI_COLOR_RESET<<endl;
    scanf(" %[^\n]", registros.NumeroCedula);
    cout << ANSI_COLOR_RED << "Digite el numero telefonico del cliente: " << ANSI_COLOR_RESET<<endl;
    scanf(" %[^\n]", registros.NumeroTelefonico);
    cout << ANSI_COLOR_RED << "Digite la cantidad prestada: " << ANSI_COLOR_RESET<<endl;
    scanf(" %[^\n]", registros.CantPrestada);
    cout << ANSI_COLOR_RED << "Digite la fecha del prestamo: " << ANSI_COLOR_RESET<<endl;
    scanf(" %[^\n]", registros.FechaPrestamo);
    cout << ANSI_COLOR_RED << "Digite la fecha establecida para el pago final: " << ANSI_COLOR_RESET<<endl;
    scanf(" %[^\n]", registros.PagoFinal);
    cout << ANSI_COLOR_RED << "Digite la tasa de intereses: " << ANSI_COLOR_RESET<<endl;
    scanf(" %[^\n]", registros.Intereses);
    cout << ANSI_COLOR_RED << "En caso de haber fiador, complete la siguiente informacion:" << ANSI_COLOR_RESET<<endl;
    cout << ANSI_COLOR_RED << "Digite el nombre completo de el fiador: " << ANSI_COLOR_RESET<<endl;
    scanf(" %[^\n]", registros.NombreFiador);
    cout << ANSI_COLOR_RED << "Digite el numero de cedula de el fiador: " << ANSI_COLOR_RESET<<endl;
    scanf(" %[^\n]", registros.CedulaFiador);
    registroPrestamos(&registros);
    cout << ANSI_COLOR_RED << "Registro de prestamo guardado...." << ANSI_COLOR_RESET<<endl;
    cout << ANSI_COLOR_RED << "-------------------------------------------------------------------------" << ANSI_COLOR_RESET<<endl;
}

void editarxRegistro() {
    int CodigoPrestamo;
    cout << ANSI_COLOR_RED_BACKGROUND << "Editar registro" << ANSI_COLOR_RESET<<endl;
    cout << ANSI_COLOR_RED<< "Ingrese el codigo de prestamo: ";
    cin >> CodigoPrestamo;
    int index = obtenerReg(CodigoPrestamo);
    if(index == -1){
        cout << ANSI_COLOR_RED<< "Registro no encontrado..." << ANSI_COLOR_RESET<<endl;
        return;
    }
    INFORMACION c;
    cout << "Digite el nuevo nombre del cliente: ";
    scanf(" %[^\n]", c.NombreCompleto);
    cout << "Digite el nuevo numero de cedula del cliente: ";
    scanf(" %[^\n]", c.NumeroCedula);
    cout << "Digite el nuevo numero telefonico del cliente: ";
    scanf(" %[^\n]", c.NumeroTelefonico);
    cout << "Digite la nueva cantidad prestada: ";
    scanf(" %[^\n]", c.CantPrestada);
    cout << "Digite la nueva fecha del prestamo: ";
    scanf(" %[^\n]", c.FechaPrestamo);
    cout << "Digite la nueva fecha establecida para el pago final: ";
    scanf(" %[^\n]", c.PagoFinal);
    cout << "Digite la nueva tasa de intereses: ";
    scanf(" %[^\n]", c.Intereses);
    cout << "En caso de haber fiador, complete la siguiente informacion:\n";
    cout << "Digite el nuevo nombre completo de el fiador: ";
    scanf(" %[^\n]", c.NombreFiador);
    cout << "Digite el nuevo numero de cedula de el fiador: ";
    scanf(" %[^\n]", c.CedulaFiador);
    registros[index] = c;
    cout << "Registro de prestamo actualizado....\n";
    cout << ANSI_COLOR_RED << "-------------------------------------------------------------------------" << ANSI_COLOR_RESET<<endl;
}

void eliminar(int CodigoPrestamo){
    int pos = obtenerReg(CodigoPrestamo);
    if(pos != -1)
    {
        for(int i = pos; i < MAX_REG - 1; i++){
            registros[i] = registros[i + 1];
        }
        pos--;
        cout << ANSI_COLOR_RED  << "Registro eliminado..." << ANSI_COLOR_RESET<<endl;
    } else 
    {
        cout << ANSI_COLOR_RED << "Registro no encontrado..." << ANSI_COLOR_RESET<<endl;
    }
}

void eliminarxRegistro()
{
    int CodigoPrestamo;
    cout << ANSI_COLOR_RED << "Eliminar registro" << ANSI_COLOR_RESET<<endl;
    cout << ANSI_COLOR_RED << "Ingrese el codigo de prestamo: " << ANSI_COLOR_RESET<<endl;
    cin >> CodigoPrestamo;
    eliminar(CodigoPrestamo);
    cout << ANSI_COLOR_RED << "-------------------------------------------------------------------------" << ANSI_COLOR_RESET<<endl;
}

void buscarxCodigoPrestamo()
{
    int CodigoPrestamo;
    void showReg(INFORMACION &c);

    cout << ANSI_COLOR_RED_BACKGROUND << "Busqueda de registro" << ANSI_COLOR_RESET<<endl;
    cout<< ANSI_COLOR_RED << "Ingrese el codigo de prestamo: " << ANSI_COLOR_RESET<<endl;
    cin >> CodigoPrestamo;
    if(obtenerReg(CodigoPrestamo)== -1){
        cout << "Registro no encontrado..." << ANSI_COLOR_RESET<<endl;
        return;
    }
    INFORMACION c{};
    c = buscar(CodigoPrestamo);
    showReg(c);
}

void mostrarTPrestamos() 
{
    if (pos == 0) 
    {
        cout << ANSI_COLOR_RED << "No hay registros para mostrar." << ANSI_COLOR_RESET<<endl;
        return;
    }

    cout << ANSI_COLOR_RED_BACKGROUND << "Lista de prestamos registrados" << ANSI_COLOR_RESET<<endl;

    for (int i = 0; i < pos; i++) 
    {
        if (registros[i].CodigoPrestamo >= 1)
        {
            cout << "Codigo de Prestamo: " << registros[i].CodigoPrestamo << endl;
            cout << "Nombre del Cliente: " << registros[i].NombreCompleto << endl;
            cout << "Numero de Cedula: " << registros[i].NumeroCedula << endl;
            cout << "Numero Telefonico: " << registros[i].NumeroTelefonico << endl;
            cout << "Cantidad Prestada: " << registros[i].CantPrestada << endl;
            cout << "Fecha del Prestamo: " << registros[i].FechaPrestamo << endl;
            cout << "Fecha de Pago Final: " << registros[i].PagoFinal << endl;
            cout << "Intereses: " << registros[i].Intereses << endl;
            cout << "Nombre del Fiador: " << registros[i].NombreFiador << endl;
            cout << "Cedula del Fiador: " << registros[i].CedulaFiador << endl;
            cout << ANSI_COLOR_RED << "-------------------------------------------------------------------------" << ANSI_COLOR_RESET<<endl;
        }
    }
}

void showReg(INFORMACION &c){
    cout << ANSI_COLOR_RED << "-------------------------------------------------------------------------" << ANSI_COLOR_RESET<<endl;
    cout << "Nombre cliente: " << c.NombreCompleto << endl;
    cout << "Numero de cedula: " << c.NumeroCedula << endl;
    cout << "Numero telefonico: " << c.NumeroTelefonico << endl;
    cout << "Cantidad prestada: " << c.CantPrestada << endl;
    cout << "Fecha del prestamo: " << c.FechaPrestamo << endl;
    cout << "Fecha de pago: " << c.PagoFinal << endl;
    cout << "Porcentaje de intereses: " << c.Intereses << endl;
    cout << "Nombre del fiador: " << c.NombreFiador << endl;
    cout << "Numero de cedula del fiador: " << c.CedulaFiador << endl;
    cout << ANSI_COLOR_RED << "-------------------------------------------------------------------------" << ANSI_COLOR_RESET<<endl;
}
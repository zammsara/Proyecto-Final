#include <iostream>
#include <string.h>
#include "variables.h"
#include <locale.h>

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
void buscarxCodigoPrestamo();
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
    INFORMACION c;
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
    cout << "Bienvenido al sistema de prestamos\n";
    cout << "-------------------------------------------------------------------------\n";
    cout << "1. Registrar un nuevo prestamo\n";
    cout << "2. Editar registro\n";
    cout << "3. Eliminar registro\n";
    cout << "4. Buscar registro\n";
    cout << "5. Mostrar los registros\n";
    cout << "6. Salir\n ";
    cout << "-------------------------------------------------------------------------\n";
    cout << "Digite la opcion: ";
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
            case 4:
                buscarxCodigoPrestamo();
                break;
        }

    } while (op != 6);
}


void solicitarDatos(){
    INFORMACION registros;
    cout << "Digite el código del prestamo: ";
    cin >> registros.CodigoPrestamo;
    cout << "Digite el nombre del cliente: ";
    scanf(" %[^\n]", registros.NombreCompleto);
    cout << "Digite el numero de cedula del cliente: ";
    scanf(" %[^\n]", registros.NumeroCedula);
    cout << "Digite el numero telefonico del cliente: ";
    scanf(" %[^\n]", registros.NumeroTelefonico);
    cout << "Digite la cantidad prestada: ";
    scanf(" %[^\n]", registros.CantPrestada);
    cout << "Digite la fecha del prestamo: ";
    scanf(" %[^\n]", registros.FechaPrestamo);
    cout << "Digite la fecha establecida para el pago final: ";
    scanf(" %[^\n]", registros.PagoFinal);
    cout << "Digite la tasa de intereses: ";
    scanf(" %[^\n]", registros.Intereses);
    cout << "En caso de haber fiador, complete la siguiente informacion:\n";
    cout << "Digite el nombre completo de el fiador: ";
    scanf(" %[^\n]", registros.NombreFiador);
    cout << "Digite el numero de cedula de el fiador: ";
    scanf(" %[^\n]", registros.CedulaFiador);
    registroPrestamos(&registros);
    cout << "Registro de prestamo guardado....\n";
}

void buscarxCodigoPrestamo()
{
    int CodigoPrestamo;
    void showReg(INFORMACION &c);

    cout << "BUSQUEDA DE REGISTRO" <<endl;
    cout << "Ingrese el codigo de prestamo: ";
    cin >> CodigoPrestamo;
    if(obtenerReg(CodigoPrestamo)== -1){
        cout << "Registro no encontrado...\n" << endl;
        return;
    }
    INFORMACION c{};
    c = buscar(CodigoPrestamo);
    showReg(c);
}

void showReg(INFORMACION &c){
    cout << "-------------------------------------------------------------------------\n";
    cout << c.NombreCompleto << endl;
    cout << c.NumeroCedula << endl;
    cout << c.NumeroTelefonico << endl;
    cout << c.CantPrestada << endl;
    cout << c.FechaPrestamo << endl;
    cout << c.PagoFinal << endl;
    cout << c.Intereses << endl;
    cout << c.NombreFiador << endl;
    cout << c.CedulaFiador << endl;
    cout << "-------------------------------------------------------------------------\n";
}

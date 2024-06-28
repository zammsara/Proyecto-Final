#include <iostream>
#include <string.h>
#include "variables.h"
#include <locale.h>
#include <string>
#include <fstream>

#define ANSI_COLOR_WH_BACK "\x1b[47m"
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
void usuario();


void usuario(){
    string usuario, password, storedUsername, storedPassword;

    // Registro de nombre de usuario y contraseña
    cout << ANSI_COLOR_WH_BACK << "Registro de usuario"  << ANSI_COLOR_RESET<<endl;
    cout << "-------------------------------------------------------------------------\n";
    cout << "Ingrese su nombre de usuario: ";
    getline(cin, usuario);
    cout << "Ingrese su contraseña: ";
    getline(cin, password);
    cout << "Informacion de usuario guardada... ";
    cout << "-------------------------------------------------------------------------\n";

    // Guardar nombre de usuario y contraseña en un archivo
    ofstream file("usuario.txt");
    file << usuario << ":" << password << endl;
    file.close();

    // Solicitar nombre de usuario y contraseña
    cout << ANSI_COLOR_WH_BACK << "Inicio de sesión"  << ANSI_COLOR_RESET<<endl;
    cout << "Ingrese su nombre de usuario: ";
    getline(cin, usuario);

    // Leer nombre de usuario y contraseña almacenados
    ifstream fileRead("usuario.txt");
    getline(fileRead, storedUsername, ':');
    getline(fileRead, storedPassword);
    fileRead.close();

    while (true) {
        cout << "Ingrese su contraseña: ";
        getline(cin, password);

        if (usuario == storedUsername && password == storedPassword) {
            cout << "Contraseña correcta! Bienvenido, " << usuario << endl;
            cout << "-------------------------------------------------------------------------\n";
            break;
        } else {
            cout << "Contraseña incorrecta. Intente de nuevo." << endl;
            cout << "-------------------------------------------------------------------------\n";
        }
    }

    void principal();

    principal();
}




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
    cout << ANSI_COLOR_WH_BACK << "Bienvenido al sistema de prestamos"  << ANSI_COLOR_RESET<<endl;
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
                cout << "Saliendo del sistema...\n";
                break;
            default:
                cout << "Opcion no valida, intente nuevamente.\n";
        }

    } while (op != 6);
}


void solicitarDatos(){
    INFORMACION registros;
    cout << "-------------------------------------------------------------------------\n";
    cout << ANSI_COLOR_WH_BACK << "Registro de prestamo"  << ANSI_COLOR_RESET<<endl;
    cout << "Digite el codigo del prestamo: ";
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

void editarxRegistro() {
    int CodigoPrestamo;
    cout << "-------------------------------------------------------------------------\n";
    cout << ANSI_COLOR_WH_BACK << "Editar registro"  << ANSI_COLOR_RESET<<endl;
    cout << "Ingrese el codigo de prestamo: ";
    cin >> CodigoPrestamo;
    int index = obtenerReg(CodigoPrestamo);
    if(index == -1){
        cout << "Registro no encontrado...\n" << endl;
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
}

void eliminar(int CodigoPrestamo){
    int pos = obtenerReg(CodigoPrestamo);
    if(pos != -1)
    {
        for(int i = pos; i < MAX_REG - 1; i++){
            registros[i] = registros[i + 1];
        }
        pos--;
        cout << "Registro eliminado...\n";
        cout << "-------------------------------------------------------------------------\n";
    } else 
    {
        cout << "Registro no encontrado..." << endl;
        cout << "-------------------------------------------------------------------------\n";
    }
}

void eliminarxRegistro()
{
    int CodigoPrestamo;
    cout << "-------------------------------------------------------------------------\n";
    cout << ANSI_COLOR_WH_BACK << "Eliminar registro"  << ANSI_COLOR_RESET<<endl;
    cout << "Ingrese el codigo de prestamo: ";
    cin >> CodigoPrestamo;
    eliminar(CodigoPrestamo);
}

void buscarxCodigoPrestamo()
{
    int CodigoPrestamo;
    void showReg(INFORMACION &c);

    cout << "-------------------------------------------------------------------------\n";
    cout << ANSI_COLOR_WH_BACK << "Busqueda de registro"  << ANSI_COLOR_RESET<<endl;
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

void mostrarTPrestamos() 
{
    if (pos == 0) 
    {
        cout << "No hay registros para mostrar.\n";
        return;
    }

    cout << "-------------------------------------------------------------------------\n";
    cout << ANSI_COLOR_WH_BACK << "Lista de prestamos registrados"  << ANSI_COLOR_RESET<<endl;
    cout << "-------------------------------------------------------------------------\n";

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
            cout << "-------------------------------------------------------------------------\n";
        }
    }
}

void showReg(INFORMACION &c){
    cout << "-------------------------------------------------------------------------\n";
    cout << "Nombre cliente: " << c.NombreCompleto << endl;
    cout << "Numero de cedula: " << c.NumeroCedula << endl;
    cout << "Numero telefonico: " << c.NumeroTelefonico << endl;
    cout << "Cantidad prestada: " << c.CantPrestada << endl;
    cout << "Fecha del prestamo: " << c.FechaPrestamo << endl;
    cout << "Fecha de pago: " << c.PagoFinal << endl;
    cout << "Porcentaje de intereses: " << c.Intereses << endl;
    cout << "Nombre del fiador: " << c.NombreFiador << endl;
    cout << "Numero de cedula del fiador: " << c.CedulaFiador << endl;
    cout << "-------------------------------------------------------------------------\n";
}
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

//Menu
int menu();
void principal();
//Obtener un registro
int obtenerReg(int CodigoPrestamo);
void showReg(INFORMACION * c);
//Registrar un prestamo
void solicitarDatos();
void registroPrestamos(INFORMACION * c);
int ultimoCodigoPrestamo = 0; // Variable para almacenar la última ID utilizada
//Editar un prestamo
void editarxRegistro();
INFORMACION buscar(int CodigoPrestamo);
//Eliminar registro
void eliminar(int CodigoPrestamo);
void eliminarxRegistro();
//Buscar un prestamo
void buscarxCodigoPrestamo();
//Mostrar todos los prestamos
void mostrarTPrestamos();
//Guardado de archivos
int cargarInfo();
void escribirInfo(const INFORMACION &c);
void guardarTodo();

//Registro de usuarios
void usuarios();
void nuevoUsuario();
void ingresar();


void inicializarUltimoCodigoPrestamo() 
{
    ifstream archivo("Prestamos.txt");
    int codigoPrestamo;
    if (archivo.is_open()) {
        while (archivo >> codigoPrestamo) {
            if (codigoPrestamo > ultimoCodigoPrestamo) {
                ultimoCodigoPrestamo = codigoPrestamo;
            }
        }
        archivo.close();
    }
}

int existeCodigoPrestamo(int codigoPrestamo) {
    for (int i = 0; i < pos; i++) {
        if (registros[i].CodigoPrestamo == codigoPrestamo) {
            return i;
        }
    }
    return -1;
}

void registroPrestamos(INFORMACION * c) {
    if (existeCodigoPrestamo(c->CodigoPrestamo) == -1) { 
        registros[pos] = *c;
        pos++;
        if (c->CodigoPrestamo > ultimoCodigoPrestamo) {
            ultimoCodigoPrestamo = c->CodigoPrestamo;
        }
    } else {
        for (int i = 0; i < pos; i++) {
            if (registros[i].CodigoPrestamo == c->CodigoPrestamo) {
                registros[i] = *c;
            }
        }
    }
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
    inicializarUltimoCodigoPrestamo(); 
    int op;
    pos = cargarInfo();
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


void solicitarDatos() {
    INFORMACION registros;
    cout << "-------------------------------------------------------------------------\n";
    cout << ANSI_COLOR_WH_BACK << "Registro de prestamo"  << ANSI_COLOR_RESET << endl;
    registros.CodigoPrestamo = ++ultimoCodigoPrestamo;
    cout << "Codigo de prestamo: " << registros.CodigoPrestamo << endl;
    cout << "Digite el nombre del cliente: ";
    cin.ignore();
    cin.getline(registros.NombreCompleto, 50);
    cout << "Digite el numero de cedula del cliente: ";
    cin.getline(registros.NumeroCedula, 20);
    cout << "Digite el numero telefonico del cliente: ";
    cin.getline(registros.NumeroTelefonico, 20);
    cout << "Digite la cantidad prestada: ";
    cin.getline(registros.CantPrestada, 20);
    cout << "Digite la fecha del prestamo: ";
    cin.getline(registros.FechaPrestamo, 20);
    cout << "Digite la fecha establecida para el pago final: ";
    cin.getline(registros.PagoFinal, 20);
    cout << "Digite la tasa de intereses: ";
    cin.getline(registros.Intereses, 20);
    cout << "En caso de haber fiador, complete la siguiente informacion:\n";
    cout << "Digite el nombre completo de el fiador: ";
    cin.getline(registros.NombreFiador, 50);
    cout << "Digite el numero de cedula de el fiador: ";
    cin.getline(registros.CedulaFiador, 20);
    registroPrestamos(&registros);
    pos++;
    INFORMACION c = registros;
    escribirInfo(c); 
    cout << "Registro de prestamo guardado....\n";
    cout << "-------------------------------------------------------------------------\n";
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
    INFORMACION c = registros[index];
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
    guardarTodo();
    cout << "Registro de prestamo actualizado....\n";
    cout << "-------------------------------------------------------------------------\n";
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

void eliminar(int CodigoPrestamo){
    int pos = obtenerReg(CodigoPrestamo);
    if(pos!= -1)
    {
        for(int i = pos; i < MAX_REG - 1; i++){
            registros[i] = registros[i + 1];
        }
        cout << "Registro eliminado...\n";
        cout << "-------------------------------------------------------------------------\n";
        pos--;
        guardarTodo();
    } else {
        cout << "Registro no encontrado..." << endl;
        cout << "-------------------------------------------------------------------------\n";
    }
}

void buscarxCodigoPrestamo() {
    int CodigoPrestamo;
    void showReg(INFORMACION &c);

    cout << "-------------------------------------------------------------------------\n";
    cout << ANSI_COLOR_WH_BACK << "Busqueda de registro"  << ANSI_COLOR_RESET << endl;
    cout << "Ingrese el codigo de prestamo: ";
    cin >> CodigoPrestamo;

    cargarInfo();

    INFORMACION c = buscar(CodigoPrestamo);

    if (c.CodigoPrestamo != 0) {
        showReg(c);
    } else {
        cout << "Registro no encontrado...\n" << endl;
    }

    cout << "-------------------------------------------------------------------------\n";
}

void mostrarTPrestamos() 
{
    if (pos == 0) 
    {
        cout << "No hay registros para mostrar.\n";
        return;
    }
    cargarInfo();
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

int cargarInfo() 
{
    ifstream archivo("Prestamos.txt");

    pos = 0;
    while (archivo >> registros[pos].CodigoPrestamo) {
        archivo.ignore();
        archivo.getline(registros[pos].NombreCompleto, 50);
        archivo.getline(registros[pos].NumeroCedula, 20);
        archivo.getline(registros[pos].NumeroTelefonico, 20);
        archivo.getline(registros[pos].CantPrestada, 20);
        archivo.getline(registros[pos].FechaPrestamo, 20);
        archivo.getline(registros[pos].PagoFinal, 20);
        archivo.getline(registros[pos].Intereses, 20);
        archivo.getline(registros[pos].NombreFiador, 50);
        archivo.getline(registros[pos].CedulaFiador, 20);
        pos++;
    }
    return pos;
}

void escribirInfo(const INFORMACION &c)
{
    ofstream archivo;

    archivo.open("Prestamos.txt", ios::app);

    archivo << c.CodigoPrestamo << endl;
    archivo << c.NombreCompleto << endl;
    archivo << c.NumeroCedula << endl;
    archivo << c.NumeroTelefonico << endl;
    archivo << c.CantPrestada << endl;
    archivo << c.FechaPrestamo << endl;
    archivo << c.PagoFinal << endl;
    archivo << c.Intereses << endl;
    archivo << c.NombreFiador << endl;
    archivo << c.CedulaFiador << endl;

    archivo.close();
}

void guardarTodo()
{
    ofstream archivo;

    archivo.open("Prestamos.txt", ios::trunc | ios::out);

    for(int i = 0; i<pos; i++)
    {
        archivo << registros[i].CodigoPrestamo << endl;
        archivo << registros[i].NombreCompleto << endl;
        archivo << registros[i].NumeroCedula << endl;
        archivo << registros[i].NumeroTelefonico << endl;
        archivo << registros[i].CantPrestada << endl;
        archivo << registros[i].FechaPrestamo << endl;
        archivo << registros[i].PagoFinal << endl;
        archivo << registros[i].Intereses << endl;
        archivo << registros[i].NombreFiador << endl;
        archivo << registros[i].CedulaFiador << endl;
    }
    archivo.close();
}

int menuUsuario(){
    setlocale(LC_ALL, "spanish");
    int op;
    cout << ANSI_COLOR_WH_BACK << "Bienvenido al sistema de prestamos"  << ANSI_COLOR_RESET<<endl;
    cout << "-------------------------------------------------------------------------\n";
    cout << "1. Registrar un nuevo usuario\n";
    cout << "2. Ingresar\n";
    cout << "-------------------------------------------------------------------------\n";
    cout << "Digite la opcion: ";
    cin >> op;
    return op;
}

void usuarios()
{
    int op;
    pos = cargarInfo();
    do
    {
        op = menuUsuario();
        switch (op)
        {
            case 1:
                nuevoUsuario();
                break;
            case 2:
                ingresar();
                break;
            default:
                cout << "Opcion no valida, intente nuevamente.\n";
        }

    } while (op != 6);
}

void nuevoUsuario()
{
     string usuario, password;
    cout << "Ingrese su nombre de usuario: ";
    cin.ignore();
    getline(cin, usuario);
    cout << "Ingrese su contrasena: ";
    getline(cin, password);
    cout << "Informacion de usuario guardada...\n";
    cout << "-------------------------------------------------------------------------\n";
    
    ofstream file("usuario.txt");
    file << usuario << ":" << password << endl;
    file.close();
}

void ingresar()
{
    string usuario, password, storedUsername, storedPassword;        
    cout << "Ingrese su nombre de usuario: ";
    cin.ignore();
    getline(cin, usuario);
    
    ifstream fileRead("usuario.txt");
    getline(fileRead, storedUsername, ':');
    getline(fileRead, storedPassword);
    fileRead.close();
    
    cout << "Ingrese su contraseña: ";
    getline(cin, password);
    
    if (usuario == storedUsername && password == storedPassword) 
    {
        cout << "Contraseña correcta! Bienvenido, " << usuario << endl;
        cout << "-------------------------------------------------------------------------\n";
        principal();
    } else 
    {
        cout << "Contraseña incorrecta. Intente de nuevo." << endl;
        cout << "-------------------------------------------------------------------------\n";
        usuarios();
    }
}

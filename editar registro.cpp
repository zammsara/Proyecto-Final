#include <iostream>
#include <stdio.h>

struct INFORMACION {
    char NombreCompleto[100];
    char NumeroCedula[20];
    char NumeroTelefonico[20];
    char CantPrestada[20];
    char FechaPrestamo[20];
    char PagoFinal[20];
    char Intereses[20];
    char NombreFiador[100];
    char CedulaFiador[20];
};

void editarRegistro() {
    int CodigoPrestamo;
    std::cout << "EDITAR REGISTRO" << std::endl;
    std::cout << "Ingrese el codigo de prestamo: ";
    std::cin >> CodigoPrestamo;
    int index = obtenerReg(CodigoPrestamo);
    if(index == -1){
        std::cout << "Registro no encontrado...\n" << std::endl;
        return;
    }
    INFORMACION c;
    std::cout << "Digite el nuevo nombre del cliente: ";
    scanf(" %[^\n]", c.NombreCompleto);
    std::cout << "Digite el nuevo numero de cedula del cliente: ";
    scanf(" %[^\n]", c.NumeroCedula);
    std::cout << "Digite el nuevo numero telefonico del cliente: ";
    scanf(" %[^\n]", c.NumeroTelefonico);
    std::cout << "Digite la nueva cantidad prestada: ";
    scanf(" %[^\n]", c.CantPrestada);
    std::cout << "Digite la nueva fecha del prestamo: ";
    scanf(" %[^\n]", c.FechaPrestamo);
    std::cout << "Digite la nueva fecha establecida para el pago final: ";
    scanf(" %[^\n]", c.PagoFinal);
    std::cout << "Digite la nueva tasa de intereses: ";
    scanf(" %[^\n]", c.Intereses);
    std::cout << "En caso de haber fiador, complete la siguiente informacion:\n";
    std::cout << "Digite el nuevo nombre completo de el fiador: ";
    scanf(" %[^\n]", c.NombreFiador);
    std::cout << "Digite el nuevo numero de cedula de el fiador: ";
    scanf(" %[^\n]", c.CedulaFiador);
    registros[index] = c;
    std::cout << "Registro de prestamo actualizado....\n";
}
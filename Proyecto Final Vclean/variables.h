#define MAX_REG 500
#define MAX_CHAR 50


struct INFORMACION{
    int CodigoPrestamo;
    char NombreCompleto[MAX_CHAR];
    char NumeroCedula[MAX_CHAR];
    char NumeroTelefonico[MAX_CHAR];
    char CantPrestada[MAX_CHAR];
    char FechaPrestamo[MAX_CHAR];
    char PagoFinal[MAX_CHAR];
    char PagoMensual[MAX_CHAR];
    char Intereses[MAX_CHAR];
    char NombreFiador[MAX_CHAR];
    char CedulaFiador[MAX_CHAR];
};

typedef struct INFORMACION INFORMACION;
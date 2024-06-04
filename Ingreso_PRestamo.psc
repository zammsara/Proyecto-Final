Algoritmo Registro_de_Prestamos
	Definir NombreCompleto, Fiador, Respuesta Como Cadena;
	Definir Cedula, Telefono, IdentificacionFiador Como Entero;
	Definir CantidadDinero, PorcentajeInteres Como Real;
	Definir FechaPrestamo, FechaPagoFinal, FechaPagoMensual Como Real;
	// A continuaci�n, se muestra un ejemplo de c�mo podr�amos solicitar y almacenar los datos de un nuevo pr�stamo:
	Escribir 'Ingrese el nombre completo del prestatario: ';
	Leer NombreCompleto;
	Escribir 'Ingrese el n�mero de c�dula del prestatario: ';
	Leer Cedula;
	Escribir 'Ingrese el n�mero telef�nico del prestatario: ';
	Leer Telefono;
	Escribir 'Ingrese la cantidad de dinero prestada: ';
	Leer CantidadDinero;
	Escribir 'Ingrese la fecha del pr�stamo (dd/mm/aa): ';
	Leer FechaPrestamo;
	Escribir 'Ingrese la fecha de pago final (dd/mm/aa): ';
	Leer FechaPagoFinal;
	Escribir '�Se realizar� un pago mensual? (si/no)';
	Leer Respuesta;
	Si Respuesta=='si' Entonces
		Escribir 'Ingrese la fecha de pago mensual (dd/mm/aa): ';
		Leer FechaPagoMensual;
	FinSi
	Escribir 'Ingrese el porcentaje de intereses: ';
	Leer PorcentajeInteres;
	Escribir '�Hay un fiador para este pr�stamo? (si/no)';
	Leer Respuesta;
	Si Respuesta=='si' Entonces
		Escribir 'Ingrese el nombre del fiador: ';
		Leer Fiador;
		Escribir 'Ingrese la identificaci�n del fiador: ';
		Leer IdentificacionFiador;
	FinSi
	// Una vez que hemos almacenado todos los datos, podemos mostrarlos en pantalla para verificar que todo est� correcto:
	Escribir '---------------------------------';
	Escribir 'DATOS DEL PR�STAMO';
	Escribir '---------------------------------';
	Escribir 'Nombre completo: ', NombreCompleto;
	Escribir 'N�mero de c�dula: ', Cedula;
	Escribir 'N�mero telef�nico: ', Telefono;
	Escribir 'Cantidad de dinero prestada: ', CantidadDinero;
	Escribir 'Fecha del pr�stamo: ', FechaPrestamo;
	Escribir 'Fecha de pago final: ', FechaPagoFinal;
	Si FechaPagoMensual<>0 Entonces
		Escribir 'Fecha de pago mensual: ', FechaPagoMensual;
	FinSi
	Escribir 'Porcentaje de intereses: ', PorcentajeInteres;
	Si Fiador<>'' Entonces
		Escribir 'Nombre del fiador: ', Fiador;
		Escribir 'Identificaci�n del fiador: ', IdentificacionFiador;
	FinSi
	Escribir '---------------------------------';
FinAlgoritmo

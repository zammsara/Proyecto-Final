Algoritmo Registro_de_Prestamos
	Definir NombreCompleto, Fiador, Respuesta Como Cadena;
	Definir Cedula, Telefono, IdentificacionFiador Como Entero;
	Definir CantidadDinero, PorcentajeInteres Como Real;
	Definir FechaPrestamo, FechaPagoFinal, FechaPagoMensual Como Real;
	// A continuación, se muestra un ejemplo de cómo podríamos solicitar y almacenar los datos de un nuevo préstamo:
	Escribir 'Ingrese el nombre completo del prestatario: ';
	Leer NombreCompleto;
	Escribir 'Ingrese el número de cédula del prestatario: ';
	Leer Cedula;
	Escribir 'Ingrese el número telefónico del prestatario: ';
	Leer Telefono;
	Escribir 'Ingrese la cantidad de dinero prestada: ';
	Leer CantidadDinero;
	Escribir 'Ingrese la fecha del préstamo (dd/mm/aa): ';
	Leer FechaPrestamo;
	Escribir 'Ingrese la fecha de pago final (dd/mm/aa): ';
	Leer FechaPagoFinal;
	Escribir '¿Se realizará un pago mensual? (si/no)';
	Leer Respuesta;
	Si Respuesta=='si' Entonces
		Escribir 'Ingrese la fecha de pago mensual (dd/mm/aa): ';
		Leer FechaPagoMensual;
	FinSi
	Escribir 'Ingrese el porcentaje de intereses: ';
	Leer PorcentajeInteres;
	Escribir '¿Hay un fiador para este préstamo? (si/no)';
	Leer Respuesta;
	Si Respuesta=='si' Entonces
		Escribir 'Ingrese el nombre del fiador: ';
		Leer Fiador;
		Escribir 'Ingrese la identificación del fiador: ';
		Leer IdentificacionFiador;
	FinSi
	// Una vez que hemos almacenado todos los datos, podemos mostrarlos en pantalla para verificar que todo esté correcto:
	Escribir '---------------------------------';
	Escribir 'DATOS DEL PRÉSTAMO';
	Escribir '---------------------------------';
	Escribir 'Nombre completo: ', NombreCompleto;
	Escribir 'Número de cédula: ', Cedula;
	Escribir 'Número telefónico: ', Telefono;
	Escribir 'Cantidad de dinero prestada: ', CantidadDinero;
	Escribir 'Fecha del préstamo: ', FechaPrestamo;
	Escribir 'Fecha de pago final: ', FechaPagoFinal;
	Si FechaPagoMensual<>0 Entonces
		Escribir 'Fecha de pago mensual: ', FechaPagoMensual;
	FinSi
	Escribir 'Porcentaje de intereses: ', PorcentajeInteres;
	Si Fiador<>'' Entonces
		Escribir 'Nombre del fiador: ', Fiador;
		Escribir 'Identificación del fiador: ', IdentificacionFiador;
	FinSi
	Escribir '---------------------------------';
FinAlgoritmo

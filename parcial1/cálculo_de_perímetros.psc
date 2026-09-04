Algoritmo Cálculo_de_perímetros
	Definir opción Como Entero
	Definir lado, radio, perimetro Como Real
	Escribir "CÁLCULO DE PERÍMETROS"
	Escribir "1. Cuadrado"
	Escribir "2. Triángulo equilátero"
	Escribir "3. Círculo"
	Escribir "Seleccione una opción:"
	Leer opcion
	
	Segun opcion hacer
		1:
			Escribir "Ingrese el lado del cuadrado:"
			Leer lado
			perimetro<- 4 * lado
			Escribir "El perímetro del cuadrado es:", perimetro
		2:
			Escribir "Ingrese el lado del triángulo equilátero:"
			Leer lado
			perimetro <- 3 * lado
			Escribir "El perímetro del triángulo equilátero es:", perimetro
		3:
			Escribir "Ingrese el radio del círculo:"
			Leer radio
			perimetro <- 2 * PI* radio
			Escribir " El perímetro del círculo es:", perimetro
		De Otro Modo:
			Escribir "Error: opción no válida."
			
	FinSegun
	
FinAlgoritmo

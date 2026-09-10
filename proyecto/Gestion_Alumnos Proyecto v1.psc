// Subproceso reutilizable para calcular el promedio de 3 calificaciones
	SubProceso  prom <- Calcular_Promedio(c1, c2, c3)
		Definir prom Como Real
		prom <- (c1 + c2 + c3) / 3
FinSubProceso


Algoritmo Gestion_Alumnos
	// Declaración de variables para el Alumno 1
	Definir alumno1_nombre Como Cadena
	Definir alumno1_c1, alumno1_c2, alumno1_c3 Como Real
	
	// Declaración de variables para el Alumno 2
	Definir alumno2_nombre Como Cadena
	Definir alumno2_c1, alumno2_c2, alumno2_c3 Como Real
	
	// Declaración de variables para el Alumno 3
	Definir alumno3_nombre Como Cadena
	Definir alumno3_c1, alumno3_c2, alumno3_c3 Como Real
	
	// Variables auxiliares
	Definir prom1, prom2, prom3 Como Real
	Definir opcion Como Entero
	Definir datosCapturados Como Logico
	
	Datos_Capturados <- Falso
	
	Repetir
		Escribir "================================="
		Escribir "    MENÚ DE GESTIÓN DE ALUMNOS   "
		Escribir "================================="
		Escribir "1. Capturar datos"
		Escribir "2. Mostrar promedios"
		Escribir "3. Mostrar el mejor promedio"
		Escribir "4. Salir"
		Escribir "Seleccione una opción: "
		Leer opcion
		
		Según opcion Hacer
	1:
		Borrar Pantalla
		Escribir "~~~ ALUMNO 1 ~~~"
		Escribir "Ingrese nombre:"
		Leer alumno1_nombre
		Escribir "Calificación 1:"
		Leer alumno1_c1
		Escribir "Calificación 2:"
		Leer alumno1_c2
		Escribir "Calificación 3:"
		Leer alumno1_c3
		
		Escribir ""
		Escribir "~~~ ALUMNO 2 ~~~"
		Escribir "Ingrese nombre:"
		Leer alumno2_nombre
		Escribir "Calificación 1:"
		Leer alumno2_c1
		Escribir "Calificación 2:"
		Leer alumno2_c2
		Escribir "Calificación 3:"
		Leer alumno2_c3
		
		Escribir ""
		Escribir "~~~ ALUMNO 3 ~~~"
		Escribir "Ingrese nombre:"
		Leer alumno3_nombre
		Escribir "Calificación 1:"
		Leer alumno3_c1
		Escribir "Calificación 2:"
		Leer alumno3_c2
		Escribir "Calificación 3:"
		Leer alumno3_c3
		
		DatosCapturados <- Verdadero
		Escribir ""
		Escribir "-> ¡Los datos se capturaron correctamente!"
		Escribir "Presione Enter para continuar..."
		Esperar Tecla
		
	2:
		Borrar Pantalla
		Si datosCapturados Entonces
			prom1 <- Calcular_Promedio(alumno1_c1, alumno1_c2, alumno1_c3)
			prom2 <- Calcular_Promedio(alumno2_c1, alumno2_c2, alumno2_c3)
			prom3 <- Calcular_Promedio(alumno3_c1, alumno3_c2, alumno3_c3)
			
			Escribir "~~~ PROMEDIOS DE LOS ALUMNOS ~~~"
			Escribir "Alumno 1: ", alumno1_nombre, " | Promedio: ", prom1
			Escribir "Alumno 2: ", alumno2_nombre, " | Promedio: ", prom2
			Escribir "Alumno 3: ", alumno3_nombre, " | Promedio: ", prom3
		Sino
			Escribir "Primero debe capturar los datos (Opción 1)."
		FinSi
		Escribir ""
		Escribir "Presione Enter para continuar..."
		Esperar Tecla
		
	3:
		Borrar Pantalla
		Si datosCapturados Entonces
			prom1 <- Calcular_Promedio(alumno1_c1, alumno1_c2, alumno1_c3)
			prom2 <- Calcular_Promedio(alumno2_c1, alumno2_c2, alumno2_c3)
			prom3 <- Calcular_Promedio(alumno3_c1, alumno3_c2, alumno3_c3)
			
			Escribir "~ ALUMNO CON EL MEJOR PROMEDIO ~"
			
			Si prom1 >= prom2 Y prom1 >= prom3 Entonces
				Escribir "El mejor promedio es de ", alumno1_nombre, " con ", prom1
			Sino
				Si prom2 >= prom1 Y prom2 >= prom3 Entonces
					Escribir "El mejor promedio es de ", alumno2_nombre, " con ", prom2
				Sino
					Escribir "El mejor promedio es de ", alumno3_nombre, " con ", prom3
				FinSi
			FinSi
		Sino
			Escribir "Primero debe capturar los datos (Opción 1)."
		FinSi
		Escribir ""
		Escribir "Presione Enter para continuar..."
		Esperar Tecla
		
	4:
		Escribir "Saliendo del programa..."
		
	De Otro Modo:
		Escribir "Opción inválida. Intente de nuevo."
		Esperar Tecla
FinSegún
Borrar Pantalla
Hasta Que opcion = 4
	
FinAlgoritmo

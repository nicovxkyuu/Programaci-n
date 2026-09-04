Algoritmo Notas_De_Un_Estudiante
	Definir N, contador, aprobadas, desaprobadas Como Entero
	Definir nota, suma, suma_Aprobadas, suma_Desaprobadas Como Real
	Definir promedio, promedio_Aprobadas, promedio_Desaprobadas Como Real
	
	Escribir "Ingrese el número de notas:"
	Leer N
	
	contador <- 1
	aprobadas <- 0
	desaprobadas <- 0
	suma <- 0
	sumaAprobadas <- 0
	sumaDesaprobadas <- 0
	
	Mientras contador <= N Hacer
		
		Escribir "Ingrese la nota ", contador, ":"
		Leer nota
		
		suma <- suma + nota
		
		Si nota >= 6 Entonces
			aprobadas <- aprobadas + 1
			suma_Aprobadas <- suma_Aprobadas + nota
		SiNo
			desaprobadas <- desaprobadas + 1
			suma_Desaprobadas <- suma_Desaprobadas + nota
		FinSi
		
		contador <- contador + 1
		
	FinMientras
	
	promedio <- suma / N
	
	Escribir " "
	Escribir "~RESULTADOS~"
	Escribir "Notas aprobadas: ", aprobadas
	Escribir "Notas desaprobadas: ", desaprobadas
	Escribir "Promedio general: ", promedio
	
	Si aprobadas > 0 Entonces
		promedio_Aprobadas <- suma_Aprobadas / aprobadas
		Escribir "Promedio de aprobadas: ", promedio_Aprobadas
	SiNo
		Escribir "No hay notas aprobadas."
	FinSi
	
	Si desaprobadas > 0 Entonces
		promedio_Desaprobadas <- suma_Desaprobadas / desaprobadas
		Escribir "Promedio de desaprobadas: ", promedio_Desaprobadas
	SiNo
		Escribir "No hay notas desaprobadas."
	FinSi
FinAlgoritmo

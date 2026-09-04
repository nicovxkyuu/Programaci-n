Algoritmo Subproceso_reutilizable
	Definir a, b, c Como Real
	Definir promedio Como Real
	
	Escribir "ALUMNO 1"
	Escribir "Ingrese las 3 calificaciones:"
	Leer a, b, c
	
	promedio <- CalcularPromedio(a, b, c)
	Escribir "Promedio del alumno 1: ", promedio
	
	Escribir " "
	Escribir "ALUMNO 2"
	Escribir "Ingrese las 3 calificaciones:"
	Leer a, b, c
	
	promedio <- CalcularPromedio(a, b, c)
	Escribir "Promedio del alumno 2: ", promedio
	
FinAlgoritmo


SubProceso promedio <- CalcularPromedio(a, b, c)
	
	promedio <- (a + b + c) / 3
	
FinSubProceso
	
	


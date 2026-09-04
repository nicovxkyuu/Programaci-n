Algoritmo Calificaciones_de_grupo
	Definir cal_1, cal_2, cal_3, promedio Como Real
	Definir suma_Promedios Como Real
	Definir alumnos Como Entero
	Definir continuar Como Caracter
	
	suma_Promedios <- 0
	alumnos <- 0
	continuar <- "S"
	
	Mientras continuar = "S" O continuar = "s" Hacer
		
		Escribir "Ingrese la calificación del primer parcial:"
		Leer cal_1
		
		Escribir "Ingrese la calificación del segundo parcial:"
		Leer cal_2
		
		Escribir "Ingrese la calificación del tercer parcial:"
		Leer cal_3
		
		promedio <- (cal_1 + cal_2 + cal_3) / 3
		
		Escribir "El promedio del alumno es: ", promedio
		
		suma_Promedios <- suma_Promedios + promedio
		alumnos <- alumnos + 1
		
		Escribir "¿Desea capturar otro alumno? (S/N)"
		Leer continuar
		
	FinMientras
	
	Si alumnos > 0 Entonces
		Escribir " "
		Escribir "~RESULTADOS DEL GRUPO~"
		Escribir "Total de alumnos: ", alumnos
		Escribir "Promedio general del grupo: ", suma_Promedios / alumnos
	SiNo
		Escribir "No se capturaron alumnos."
	FinSi
FinAlgoritmo

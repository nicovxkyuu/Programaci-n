Algoritmo Promedio_y_Estatus
	Definir Cal_1 , Cal_2 , Cal_3 , promedio Como Real;
	Escribir "ingresa la  primera calificación"
	Leer Cal_1;
	Escribir "ingresa la segunda calificación"
	Leer Cal_2;
	Escribir "inngresa la tercera calificación"
	Leer Cal_3;
	promedio <- (Cal_1 + Cal_2 + Cal_3) / 3;
	si promedio <=6 Entonces
		Escribir "reprobado"
	sino 
		escribir "aprobado"
	FinSi
	
	
FinAlgoritmo

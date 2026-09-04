Algoritmo Descuento_Por_Sueldo
	Definir sueldo, descuento, neto Como Real;
	Escribir "ingrese el sueldo del trabajador"
	Leer sueldo
	si sueldo <= 1000 Entonces
		descuento<- sueldo * 0.10
	SiNo
		si sueldo <= 2000 Entonces
			descuento <- 1000 * 0.10 + (sueldo - 1000) * 0.05
		SiNo
			descuento <- 1000 * 0.10 + 1000 * 0.05 + (sueldo - 2000) * 0.03
		FinSi
	FinSi
	
	neto<- sueldo - descuento
	Escribir "descuento: $", descuento
	Escribir "sueldo neto: $", neto
FinAlgoritmo

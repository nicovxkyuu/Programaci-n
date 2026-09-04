Algoritmo Operaciones_con_dos_números
	Definir num1, num2, resultado Como Real
	Escribir "ingrese el primer número:"
	Leer num1
	Escribir "ingrese el segundo número"
	Leer num2
	si num1 = num2 Entonces
		resultado<- num1 * num2
		Escribir "Los números son iguales."
		Escribir "Resultado de la multiplicación:", resultado
	SiNo
		Si num1 > num2 Entonces
			resultado <- num1 - num2
			Escribir "El primer número es mayor."
			Escribir "Resultado de la resta:", resultado
		SiNo
			resultado <- num1 + num2
			Escribir "El primer número es menor."
			Escribir "Resultado de la suma:", resultado
			
			
		FinSi
	FinSi
FinAlgoritmo

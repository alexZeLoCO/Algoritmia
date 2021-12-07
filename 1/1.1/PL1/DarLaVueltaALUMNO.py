# 
# Implementacion en Python del algoritmo dar_la_vuelta
# 
# ALGORITMIA: PRACTICA DE ANALISIS DE ALGORITMOS
#
# Copyright: Raquel Cortina
# Fecha: 1 de setiembre de 2019
#
# ----------------------------------------------------------------------------------------------------------
#
# Programa para medir los tiempos de ejecucion de la implementacion en Python
#
# El modulo time ofrece una funcion para la medicion de tiempos. Su nombre es clock
# y devuelve el numero de segundos que ha dedicado la CPU a la ejecucion del programa
# hasta el punto en el que se efectua la llamada a la funcion. El valor devuelto es tipo float 
#

# El modulo random ofrece la funcion randrange(0,rango) que selecciona un entero al azar entre 0 u rango -1
#
# ----------------------------------------------------------------------------------------------------------

from time import time
from random import randrange

# Funcion que rellena de manera aleatoria un vector de una talla concreta
def rellena(talla,rango):
    valores = [0] * talla
    for i in range(talla):
        valores[i]=randrange(0,rango)
    return valores

# Funcion que da la vuelta al vector valores
def dar_la_vuelta(valores):
    for i in range(1,len(valores)):
        for j in range(1,len(valores)-i+1):
            valores[j-1], valores[j+1-1] = valores[j+1-1], valores[j-1]
            #            
            # la linea anterior es equivalente a las tres que figuran
            # a continuacion
            #
            # aux=valores[j-1]
            # valores[j-1]=valores[(j+1)-1]
            # valores[(j+1)-1]=aux
    return valores


# Programa principal

# se declara un vector de 10 tallas que son las que vamos a medir
talla=[1000,2000,3000,4000,5000,6000,7000,8000,9000,10000, 11000, 12000]
rango=1000

# Fijamos el numero de repeticiones
repeticiones=1

# Para mostrar la cabecera de la tabla en la que figurara talla vs. tiempo
print ("\n\nDAR LA VUELTA A UN VECTOR\n")
print ("Tiempo empleado:\n")
print ("\t\ttalla\t\ttiempo")
print ("\t\t-----\t\t------")

# Bucle que recorre las diferentes tallas a medir
for i in range(len(talla)):
    # Rellenado de un vector de talla[i]
    vector=rellena(talla[i], rango)
 
    # Invocamos a la funcion clock antes de la franja de codigo a medir
    tiempo_inicial = time()
    
    # Bucle para repetir el experimento
    for j in range(repeticiones):
        # Invocacion de la funcion a medir
        dar_la_vuelta(vector)
    
    # Invocamos a la funcion clock despues de la franja de codigo a medir
    tiempo_final = time()

    # Mostramos la talla medida y el tiempo empleado (tiempo medido/repeticiones)
    print ("\t\t%d\t\t%f" % (talla[i],(tiempo_final-tiempo_inicial)/repeticiones))
    
pepito=input() 
    

# Multiplicación de matrices

## 1. Introducción
En el presente trabajo se desarrollan dos algoritmos para realizar operaciones de multiplicación de matrices, con el fin de mostrar los beneficios de performance de un algoritmo concurrente versus un algoritmo tradicional. Para esto se procesarán diferentes volúmenes de datos (dimensiones de matrices) para determinar cuando es más conveniente usar concurrencia y cuando un algoritmo tradicional.

## 2. Multiplicación de matrices con algoritmo tradicional
Para el algoritmo tradicional sobrecargamos el operador “*” para ejecutar la multiplicación de 2 matrices de la siguiente forma.

![](https://github.com/cs2b01/uniform-interface/blob/master/ui3.png)
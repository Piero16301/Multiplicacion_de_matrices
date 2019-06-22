# Multiplicación de matrices

## 1. Introducción
En el presente trabajo se desarrollan dos algoritmos para realizar operaciones de multiplicación de matrices, con el fin de mostrar los beneficios de performance de un algoritmo concurrente versus un algoritmo tradicional. Para esto se procesarán diferentes volúmenes de datos (dimensiones de matrices) para determinar cuando es más conveniente usar concurrencia y cuando un algoritmo tradicional.

## 2. Multiplicación de matrices con algoritmo tradicional
Para el algoritmo tradicional sobrecargamos el operador “*” para ejecutar la multiplicación de 2 matrices de la siguiente forma.

![](https://github.com/Piero16301/Multiplicacion_de_matrices/blob/master/Extra_files/1.jpg)

El algoritmo principalmente recorre las filas de la matriz de resultante, en la segunda iteración recorre las columnas de la matriz resultante y en la tercera iteración se realiza la multiplicación de ambas matrices y se almacena el resultado en la matriz resultante. La complejidad de tiempo de este algoritmo es O (N^3)

![](https://github.com/Piero16301/Multiplicacion_de_matrices/blob/master/Extra_files/2.jpg)

## 3. Multiplicación de matrices con algoritmo concurrente
Para el desarrollo de un algoritmo concurrente se utilizó la implementación de pthread disponible con el compilador g++. En el desarrollo de este algoritmo definimos una variable “MAX” para definir la dimensión de matriz cuadrada 2D de esa longitud. “MAX_THREAD” para definir el numero de hilos a utilizar.

![](https://github.com/Piero16301/Multiplicacion_de_matrices/blob/master/Extra_files/3.jpg)

Definimos un array del tipo “pthread” de longitud MAX_THREAD (4 para este caso) iteramos de acuerdo con la cantidad de hilos disponibles e invocamos la ejecución de la función “multi” encargada de ejecutar la multiplicación matricial.

![](https://github.com/Piero16301/Multiplicacion_de_matrices/blob/master/Extra_files/4.jpg)

Con el uso de la variable global step_i, se realiza la iteración del numero de filas que se encargará cada hilo (bucle exterior) de tal forma que cada hilo se encargará de ejecutar la multiplicación de la cuarta parte del total de filas a procesar.

![](https://github.com/Piero16301/Multiplicacion_de_matrices/blob/master/Extra_files/5.jpg)

![](https://github.com/Piero16301/Multiplicacion_de_matrices/blob/master/Extra_files/6.jpg)

## 4. Descripción del experimento
Estos algoritmos han sido probados en un equipo con las siguientes características:

* **Equipo:** Acer Predator PH315-51-78NP.
* **Sistema operativo:** Linux Deepin 15.10.
* **Tipo de SO:** 64 bits.
* **Procesador:** i7-8750H.
* **Memoria RAM:** 16 GB.
* **Disco duro:** 1 TB.
* **Lenguaje de programación:** C++.
* **Compilador:** g++ 4.2.1.

## 5. Resultados
Se ejecutó la multiplicación de matrices de acuerdo con las dimensiones indicadas obteniendo lo siguientes tiempos de ejecución para cada tipo de algoritmo.

![](https://github.com/Piero16301/Multiplicacion_de_matrices/blob/master/Extra_files/7.jpg)

Y se obtuvo la siguiente gráfica de tiempo de ejecución vs dimesión de la matriz.

![](https://github.com/Piero16301/Multiplicacion_de_matrices/blob/master/Extra_files/8.jpg)

## 6. Conclusiones
* De acuerdo con las pruebas realizadas, determinamos que a partir de matrices de dimensiones superiores a 100 x 100, resulta más beneficioso utilizar algoritmos basados en concurrencia, ya que de esta forma se aprovecharían de manera eficiente los recursos de computo.
* Concluimos que la ejecución serializada mediante algoritmos tradicionales es valida y esta justificada en escenarios donde no hay grandes volúmenes de datos o en aplicaciones donde se podría tolerar un tiempo de espera, ya que incrementar el performance conlleva un incremento de recursos computacionales que a su vez se traduce en mayores costos de infraestructura.
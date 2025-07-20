# C_Serg_Library

BIBLIOTECA DE FUNCIONES DE C

AUTOR: SERGIO JUAN ROLLÁN MORALEJO

VERSIÓN NO: 3.0

FECHA DE FINALIZACIÓN: 20-07-2023

Objetivo de la biblioteca: reducir lo máximo posible el número de ".h" que se incluyan en todos los proyectos de C del usuario, a lo largo de aproximadamente 10000 lineas de código de funciones útiles y reutilizables. Se incluirá en los códigos fuente escribiendo al principio del documento la línea '#include "sergioteca.h"'.

Importaciones que incluye: <stdio.h>, <stdlib.h>, <stdarg.h>, <string.h>, <unistd.h>, <ctype.h>, <math.h>, <time.h>, <conio.h> y <limits.h>.

Sus aportaciones a la abstracción, legibilidad, portabilidad y comodidad del lenguaje C son:

- CAPÍTULO 1: CONSTANTES ÚTILES
- CAPÍTULO 2: TIPO BOOLEANO
- CAPÍTULO 3: FUNCIONES MISCELÁNEAS
- CAPÍTULO 4: LECTURA DE DATOS POR TECLADO
- CAPÍTULO 5: IMPRIMIR DATOS POR CONSOLA
- CAPÍTULO 6: OPERACIONES ÚTILES CON STRINGS
- CAPÍTULO 7: OPERACIONES CON VECTORES Y MATRICES
- CAPÍTULO 8: OPERACIONES CON MATRICES OBJETO
- CAPÍTULO 9: OPERACIONES CON PILAS
- CAPÍTULO 10: OPERACIONES CON COLAS
- CAPÍTULO 11: LISTAS ENLAZADAS CON ORIENTACIÓN A OBJETOS
- CAPÍTULO 12: OTRAS ESTRUCTURAS DE DATOS
- CAPÍTULO 13: ALGORITMOS DE PLANIFICACIÓN DE PROCESOS
- CAPÍTULO 14: ALGORITMOS DE BÚSQUEDA
- CAPÍTULO 15: ALGORITMOS DE ORDENACIÓN
- CAPÍTULO 16: BARAJA DE CARTAS
- CAPÍTULO 17: DIAGRAMAS DE GANTT
- CAPÍTULO 18: ESTIMACIÓN DE ESFUERZO
- CAPÍTULO 19: CÓDIGOS CORRECTORES DE ERRORES
- CAPÍTULO 20: HIPERPLANOS
- CAPÍTULO 21: AUTÓMATAS FINITOS

---

## -------------- CAPÍTULO 1: CONSTANTES ÚTILES --------------

La biblioteca proporciona un conjunto de constantes y tipos de datos que simplifican la programación en C, eliminando la necesidad de recordar detalles técnicos específicos del lenguaje y mejorando la legibilidad del código.

### Constantes de control de flujo

- **NUEVA_LINEA**: Constante que representa un print con solo el carácter de nueva línea (`\n`). Permite cambiar de línea sin recordar la secuencia específica de printf.
- **RETORNO_DE_CARRO**: Constante que representa un print con solo el carácter del retorno de carro (`\r`). Útil para operaciones de control de cursor.

### Constantes de estado

- **EXITO**: Constante que representa el éxito en la ejecución de una función (valor 0).
- **FALLO**: Constante que representa el fallo en la ejecución de una función (valor -1).
- **SUPERFALLO**: Constante que representa un fallo crítico en la ejecución de una función (valor -2).

### Tipos de datos simplificados

- **string**: Tipo de dato que representa una cadena de caracteres (equivalente a `char*`). Elimina la necesidad de recordar los punteros a char terminados en carácter nulo y las operaciones de aritmética de punteros asociadas.

- **vector**: Tipo de dato para vectores de enteros (equivalente a `int*`).
- **vectorf**: Tipo de dato para vectores de números reales de simple precisión (equivalente a `float*`).
- **matriz**: Tipo de dato para matrices de enteros (equivalente a `int**`).
- **matrizf**: Tipo de dato para matrices de números reales de simple precisión (equivalente a `float**`).

### Ejemplo de uso

```c
// Uso de constantes de control de flujo
printf("Primera línea"); NUEVA_LINEA;
printf("Segunda línea"); NUEVA_LINEA;

// Uso de constantes de estado
int resultado = algunaFuncion();
if (resultado == EXITO) {
    printf("Operación completada con éxito\n");
} else if (resultado == FALLO) {
    printf("Error en la operación\n");
} else if (resultado == SUPERFALLO) {
    printf("Error crítico en la operación\n");
}

// Uso de tipos simplificados
string nombre = "Juan";
vector numeros = malloc(10 * sizeof(int));
matriz tabla = malloc(5 * sizeof(int*));
```

---

## -------------- CAPÍTULO 2: TIPO BOOLEANO --------------

La biblioteca incluye un tipo de dato booleano que mejora la legibilidad del código y proporciona una representación más clara de valores lógicos, eliminando la dependencia de valores numéricos para representar verdadero y falso.

### Definición del tipo booleano

- **boolean**: Tipo de dato que representa valores lógicos.
- **TRUE**: Constante que representa el valor verdadero (valor 1).
- **FALSE**: Constante que representa el valor falso (valor 0).

### Características y recomendaciones

- Aunque `TRUE` y `FALSE` son macros que valen 1 y 0 respectivamente, se recomienda realizar comprobaciones con el operador `==` para aumentar la portabilidad del código.
- Esta práctica evita problemas de compatibilidad entre diferentes compiladores y plataformas.

### Ejemplo de uso

```c
// Declaración de variables booleanas
boolean esValido = TRUE;
boolean encontrado = FALSE;

// Función que devuelve un valor booleano
boolean esPar(int numero) {
    return (numero % 2 == 0) ? TRUE : FALSE;
}

// Uso recomendado con operador ==
if (esPar(10) == TRUE) {
    printf("El número es par\n");
}

// Uso correcto en condiciones
if (esValido == TRUE && encontrado == FALSE) {
    printf("Condición válida\n");
}

// Comparación de valores booleanos
boolean resultado = (esPar(5) == FALSE) ? TRUE : FALSE;
```

---

## -------------- CAPÍTULO 3: FUNCIONES MISCELÁNEAS --------------

La biblioteca incluye un conjunto de funciones utilitarias que proporcionan funcionalidades comunes en programación, desde operaciones matemáticas básicas hasta generación de números aleatorios y manejo de archivos.

### Funciones de aproximación y redondeo

- **int aproximar(float numero)**: Recibe un número de punto flotante y devuelve el entero más cercano a él. Esto contrasta con la operación por defecto de C para convertir float a int, que es el truncado.

### Funciones de generación de números aleatorios

- **double aleatorioEntre2(double limiteInferior, double limiteSuperior, int cifrasDePrecision)**: Genera un número real aleatorio entre dos límites dados, con una precisión especificada. Si el límite inferior es mayor al superior, los intercambia automáticamente.

- **int enteroAleatorioConSigno(int limiteInferior, int limiteSuperior)**: Genera un número entero aleatorio entre dos límites, pudiendo ambos ser negativos. Ambos límites están incluidos en las posibilidades del resultado.

- **int aleatorioBinomial(int n, double p)**: Genera un valor aleatorio según una distribución binomial B(n, p).

- **double aleatorioNormal(double mu, double sigma)**: Genera un valor aleatorio según una distribución normal N(μ, σ).

### Funciones matemáticas combinatorias

- **long combinaciones(int n, int m)**: Calcula combinaciones sin repetición C(n, m).
- **long combinacionesConRepeticion(int n, int m)**: Calcula combinaciones con repetición C'(n, m).
- **long variaciones(int n, int m)**: Calcula variaciones sin repetición V(n, m).
- **long variacionesConRepeticion(int n, int m)**: Calcula variaciones con repetición V'(n, m).
- **long permutaciones(int n)**: Calcula permutaciones sin repetición P(n).
- **long permutacionesConRepeticion(int n, const int\* ms, int k)**: Calcula permutaciones con repetición P(n; m1, m2, ..., mk).

### Funciones de interacción con el usuario

- **boolean yesOrNo(string preguntaAImprimir)**: Realiza una pregunta al usuario y solo admite 'y' o 'n' (mayúscula o minúscula). Devuelve `TRUE` si se teclea 'y', `FALSE` si se teclea 'n'. Muestra el prompt: "¿Pregunta? (Y/N): |"

### Funciones de manejo de archivos

- **FILE\* abrirFpBloq(string ruta, string modo)**: Abre un archivo de forma atómica y bloqueante.
- **void cerrarFpBloq(FILE\* fichero)**: Cierra un archivo de forma atómica y bloqueante.

Estas funciones también sirven como método de sincronización debido a las restricciones del lenguaje C para abrir archivos bloqueados.

### Funciones matemáticas

- **int descomponerFactoresPrimos(int n, int\* factores)**: Descompone un número en factores primos y los almacena en el array proporcionado.

- **int descomponerPolinomioRuffini(const int\* coef, int grado, int\* raices)**: Descompone un polinomio en raíces enteras usando el método de Ruffini.

- **int mcd(int a, int b)**: Calcula el máximo común divisor usando el algoritmo de Euclides.

- **int mcm(int a, int b)**: Calcula el mínimo común múltiplo de dos números enteros.

- **int mcd_descp(int a, int b)**: Calcula el máximo común divisor usando descomposición en factores primos.

- **int mcm_descp(int a, int b)**: Calcula el mínimo común múltiplo usando descomposición en factores primos.

### Funciones especializadas

- **float distanciaTecladoQWERTY(char a, char b)**: Calcula la distancia entre dos letras en el teclado QWERTY, considerando la distancia vertical como 0.5 y la horizontal como 1.

### Ejemplo de uso

```c
// Aproximación de números
int redondeado = aproximar(3.7);  // Resultado: 4
int redondeado2 = aproximar(3.2); // Resultado: 3

// Generación de números aleatorios
double aleatorio = aleatorioEntre2(0.0, 1.0, 3);
int entero = enteroAleatorioConSigno(-10, 10);
int binomial = aleatorioBinomial(10, 0.5);
double normal = aleatorioNormal(0.0, 1.0);

// Interacción con usuario
boolean respuesta = yesOrNo("¿Continuar?");

// Operaciones matemáticas
int factores[10];
int numFactores = descomponerFactoresPrimos(24, factores);
int maximo = mcd(48, 18);  // Resultado: 6
int minimo = mcm(12, 18);  // Resultado: 36

// Distancia en teclado
float distancia = distanciaTecladoQWERTY('a', 's');  // Resultado: 1.0

// Cálculos combinatorios
long comb = combinaciones(5, 3);      // C(5,3) = 10
long var = variaciones(5, 3);         // V(5,3) = 60
long perm = permutaciones(4);         // P(4) = 24

// Permutaciones con repetición
int ms[] = {2, 1, 1};  // 2 elementos iguales, 1 diferente, 1 diferente
long permRep = permutacionesConRepeticion(4, ms, 3);  // P(4;2,1,1) = 12
```

---

## -------------- CAPÍTULO 4: LECTURA DE DATOS POR TECLADO --------------

La biblioteca proporciona un sistema completo y simplificado para la lectura de datos desde la entrada estándar, incluyendo tanto lectura normal como lectura oculta para datos sensibles.

### Funciones de lectura normal

La biblioteca permite leer cualquier tipo de dato básico (`int`, `float`, `double`, `long` y `string`) utilizando la función macro `leer`. Esta macro simplifica la entrada de datos eliminando la necesidad de recordar los formatos específicos de `scanf`.

#### Sintaxis de uso

- **int**: `int num = leer(num, "Introduce un número entero: ");`
- **float**: `float num = leer(num, "Introduce un número real de simple precisión: ");`
- **double**: `double num = leer(num, "Introduce un número real de doble precisión: ");`
- **long**: `long num = leer(num, "Introduce un número entero largo: ");`
- **string**: `string nom = leer(nom, "Introduce tu nombre: ", 10);`

**Nota**: Para strings, es necesario especificar el número máximo de caracteres que se admitirán en la lectura.

### Funciones de lectura oculta (contraseñas)

La biblioteca también proporciona funciones para leer datos de la entrada estándar **sin mostrar los caracteres tecleados**, ideal para contraseñas o datos sensibles. Se usan igual que las funciones normales, pero con el prefijo `leerPassword`. En el caso de contraseña string, el último argumento será true para mostrar asteriscos al teclear y false para que no escriba nada ni se mueva el cursor.

#### Sintaxis de uso

- **int**: `int secreto = leerPassword(0, "Introduce un número secreto: ");`
- **long**: `long lsecreto = leerPassword(0L, "Introduce un long secreto: ");`
- **float**: `float fsecreto = leerPassword(0.0f, "Introduce un float secreto: ");`
- **double**: `double dsecreto = leerPassword(0.0, "Introduce un double secreto: ");`
- **string**: `string pass = leerPassword(pass, "Introduce tu contraseña: ", 20, TRUE);`

#### Características de la lectura oculta

- **Strings**: Mientras se escribe, se muestran asteriscos (`*`) en lugar de los caracteres reales.
- **Tipos numéricos**: La entrada permanece completamente oculta, sin mostrar ningún carácter.

### Ejemplo de uso

```c
// Lectura normal
int edad = leer(edad, "Introduce tu edad: ");
float altura = leer(altura, "Introduce tu altura en metros: ");
double peso = leer(peso, "Introduce tu peso en kg: ");
long telefono = leer(telefono, "Introduce tu teléfono: ");
string nombre = leer(nombre, "Introduce tu nombre: ", 50);

// Lectura oculta para datos sensibles
int pin = leerPassword(0, "Introduce tu PIN: ");
string password = leerPassword(password, "Introduce tu contraseña: ", 20, FALSE);

// Verificación de datos leídos
printf("Hola %s, tienes %d años\n", nombre, edad);
printf("Tu altura es %.2f metros y pesas %.1f kg\n", altura, peso);
```

---

## -------------- CAPÍTULO 5: IMPRIMIR DATOS POR CONSOLA --------------

La biblioteca proporciona un sistema simplificado para imprimir datos en la consola, eliminando la necesidad de recordar los formatos específicos de `printf` y proporcionando variantes para diferentes tipos de salida.

### Funciones de impresión básica

La biblioteca permite imprimir cualquier tipo de dato básico (`int`, `float`, `double`, `long` y `string`) utilizando la función macro `print`. Esta macro simplifica la salida de datos eliminando la necesidad de recordar los formatos específicos de `printf`.

#### Sintaxis de uso

- **int**: `int num = 7; print(num);`
- **long**: `long num = 7; print(num);`
- **float**: `float num = 7.0; print(num);`
- **double**: `double num = 7.0; print(num);`
- **string**: `string s = "hola"; print(s);`

### Variantes de impresión

La biblioteca proporciona varias variantes de la función `print` para diferentes necesidades de formato:

- **print**: Imprime el valor sin salto de línea
- **println**: Imprime el valor seguido de un salto de línea (`\n`)
- **printlnln**: Imprime el valor seguido de dos saltos de línea (`\n\n`)
- **printlnlnln**: Imprime el valor seguido de tres saltos de línea (`\n\n\n`)

### Impresión en búfer de errores

Todas las funciones de impresión tienen su equivalente para el búfer de errores (`stderr`), utilizando el prefijo `err`:

- **errprint**: Imprime en el búfer de errores sin salto de línea
- **errprintln**: Imprime en el búfer de errores con un salto de línea
- **errprintlnln**: Imprime en el búfer de errores con dos saltos de línea
- **errprintlnlnln**: Imprime en el búfer de errores con tres saltos de línea

### Ejemplo de uso

```c
// Variables de ejemplo
int numero = 42;
float decimal = 3.14159;
double precision = 2.718281828;
long grande = 1234567890L;
string texto = "Hola mundo";

// Impresión básica
print(numero);      // Imprime: 42
print(decimal);     // Imprime: 3.14159
print(precision);   // Imprime: 2.718281828
print(grande);      // Imprime: 1234567890
print(texto);       // Imprime: Hola mundo

// Impresión con saltos de línea
println(numero);    // Imprime: 42\n
printlnln(texto);   // Imprime: Hola mundo\n\n
printlnlnln(decimal); // Imprime: 3.14159\n\n\n

// Impresión en búfer de errores
errprint("Error: ");           // Imprime en stderr: Error:
errprintln("Valor inválido");  // Imprime en stderr: Valor inválido\n
errprintlnlnln(numero);        // Imprime en stderr: 42\n\n\n

// Equivalente a fprintf(stderr, "%d\n\n\n", numero);
```

---

## -------------- CAPÍTULO 6: OPERACIONES ÚTILES CON STRINGS --------------

La biblioteca incluye un conjunto completo de funciones para el manejo y manipulación de cadenas de caracteres, así como funciones matemáticas combinatorias que son útiles en el procesamiento de strings.

### Funciones de transformación de strings

- **string todoMayusculas(string cadenaParaConvertir)**: Convierte todos los caracteres de la 'a' a la 'z' que haya en un string a mayúsculas, independientemente de si ya lo estaban o no.

- **string todoMinusculas(string cadenaParaConvertir)**: Convierte todos los caracteres de la 'A' a la 'Z' que haya en un string a minúsculas, independientemente de si ya lo estaban o no.

### Funciones de manipulación de strings

- **int meterLetraEnCadena(string\* cadena, char caracterAlFinal)**: Añade un carácter al final de un string. Modifica la cadena original y devuelve el resultado de la operación.

- **string substring(string cadenaParaCortar, int caracterComienzo, int caracterFinal)**: Extrae una subcadena de una cadena dada, desde la posición `caracterComienzo` hasta `caracterFinal` (exclusivo). Si recibe números negativos o una cadena no válida, devuelve NULL.

### Funciones de iteración y búsqueda

- **char siguienteChar(string)**: Implementa un iterador de cadenas de caracteres. Útil para procesar cada carácter de un string por separado. Se utiliza invocándolo con NULL para continuar la iteración.

- **int numaparicioneschar(string cadenaParaRecorrer, char caracterParaBuscar)**: Cuenta el número de veces que aparece un carácter específico en una cadena.

- **int numaparicionessub(string cadenaParaRecorrer, string cadenaParaBuscar)**: Cuenta el número de veces que aparece una subcadena dentro de otra cadena.

### Ejemplo de uso

```c
// Transformación de strings
string texto = "Hola Mundo";
string mayusculas = todoMayusculas(texto);  // "HOLA MUNDO"
string minusculas = todoMinusculas(texto);  // "hola mundo"

// Manipulación de strings
string cadena = "Hola";
meterLetraEnCadena(&cadena, '!');  // cadena = "Hola!"
string sub = substring("Hola mundo", 3, 8);  // "a mun"

// Iteración de caracteres
char c = siguienteChar("Hola");  // 'H'
c = siguienteChar(NULL);         // 'o'
c = siguienteChar(NULL);         // 'l'
c = siguienteChar(NULL);         // 'a'
c = siguienteChar(NULL);         // '\0'

// Búsqueda en strings
int apariciones = numaparicioneschar("hola mundo", 'o');  // 2
int subcadenas = numaparicionessub("hola hola mundo", "hola");  // 2
```

---

## ---------- CAPÍTULO 7: OPERACIONES CON VECTORES Y MATRICES ----------

La biblioteca proporciona un conjunto completo de funciones para el manejo de vectores y matrices, tanto de enteros como de números reales, simplificando las operaciones matemáticas más comunes en programación científica y de ingeniería.

### Operaciones con vectores

La biblioteca define operaciones para los tipos de dato `vector` (enteros) y `vectorf` (floats) mencionados en el capítulo 1.

#### Funciones de entrada y salida

- **vector leerVectorI(int numeroElementos, string cadenaParaImprimir)**: Lee un vector de enteros desde teclado.
- **vectorf leerVectorF(int numeroElementos, string cadenaParaImprimir)**: Lee un vector de floats desde teclado.
- **void imprimirVectorI(vector imprimido, int numeroDeElementosQueTiene)**: Imprime un vector de enteros.
- **void imprimirVectorF(vectorf imprimido, int numeroDeElementosQueTiene)**: Imprime un vector de floats.

#### Operaciones matemáticas

- **int productoEscalarI(vector vector1, vector vector2, int numeroElementosQueTienen)**: Calcula el producto escalar de dos vectores de enteros.
- **float productoEscalarF(vectorf vector1, vectorf vector2, int numeroElementosQueTienen)**: Calcula el producto escalar de dos vectores de floats.
- **vector productoVectorialI(vector vector1, vector vector2)**: Calcula el producto vectorial de dos vectores de enteros (solo para vectores de 3 dimensiones).
- **vectorf productoVectorialF(vectorf vector1, vectorf vector2)**: Calcula el producto vectorial de dos vectores de floats (solo para vectores de 3 dimensiones).

#### Operaciones de combinación

- **vector concatenarVectoresI(vector vectorIzquierda, vector vectorDerecha, int numElementosPrimero, int numElementosSegundo)**: Concatena dos vectores de enteros.
- **vectorf concatenarVectoresF(vectorf vectorIzquierda, vectorf vectorDerecha, int numElementosPrimero, int numElementosSegundo)**: Concatena dos vectores de floats.

### Operaciones con matrices

La biblioteca define operaciones para los tipos de dato `matriz` (enteros) y `matrizf` (floats).

#### Funciones de entrada y salida

- **matriz leerMatrizI(int filas, int columnas, string cadenaParaImprimir)**: Lee una matriz de enteros desde teclado.
- **matrizf leerMatrizF(int filas, int columnas, string cadenaParaImprimir)**: Lee una matriz de floats desde teclado.
- **void imprimirMatrizI(matriz imprimida, int filas, int columnas)**: Imprime una matriz de enteros.
- **void imprimirMatrizF(matrizf imprimida, int filas, int columnas)**: Imprime una matriz de floats.

#### Funciones de generación

- **matriz generarMatrizI(int filas, int columnas, int limiteInferior, int limiteSuperior)**: Genera una matriz de enteros con valores aleatorios.
- **matrizf generarMatrizF(int filas, int columnas, float limiteInferior, float limiteSuperior, int cifrasDePrecision)**: Genera una matriz de floats con valores aleatorios.

#### Operaciones matemáticas

- **matriz multiplicarMatrI(matriz matriz1, matriz matriz2, int filasPrimeraMatriz, int columnasPrimeraTambienFilasSegunda, int columnasSegundaMatriz)**: Multiplica dos matrices de enteros.
- **matrizf multiplicarMatrF(matrizf matriz1, matrizf matriz2, int filasPrimeraMatriz, int columnasPrimeraTambienFilasSegunda, int columnasSegundaMatriz)**: Multiplica dos matrices de floats.
- **matriz sumarMatrI(matriz matriz1, matriz matriz2, int filas, int columnas)**: Suma dos matrices de enteros.
- **matrizf sumarMatrF(matrizf matriz1, matrizf matriz2, int filas, int columnas)**: Suma dos matrices de floats.
- **matriz restarMatrI(matriz matriz1, matriz matriz2, int filas, int columnas)**: Resta dos matrices de enteros.
- **matrizf restarMatrF(matrizf matriz1, matrizf matriz2, int filas, int columnas)**: Resta dos matrices de floats.
- **matriz numPorMatrI(int escalar, matriz matriz, int filas, int columnas)**: Multiplica una matriz de enteros por un escalar.
- **matrizf numPorMatrF(float escalar, matrizf matriz, int filas, int columnas)**: Multiplica una matriz de floats por un escalar.
- **int determinanteI(matriz matriz, int dimension)**: Calcula el determinante de una matriz de enteros.
- **float determinanteF(matrizf matriz, int dimension)**: Calcula el determinante de una matriz de floats.

#### Operaciones de combinación

- **matriz concatenarMatricesEnHorizontalI(matriz matriz1, matriz matriz2, int filasPrimeraTambienFilasSegunda, int columnasPrimeraMatriz, int columnasSegundaMatriz)**: Concatena dos matrices horizontalmente.
- **matrizf concatenarMatricesEnHorizontalF(matrizf matriz1, matrizf matriz2, int filasPrimeraTambienFilasSegunda, int columnasPrimeraMatriz, int columnasSegundaMatriz)**: Concatena dos matrices de floats horizontalmente.
- **matriz concatenarMatricesEnVerticalI(matriz matriz1, matriz matriz2, int filasPrimeraMatriz, int filasSegundaMatriz, int columnasPrimeraTambienColumnasSegunda)**: Concatena dos matrices verticalmente.
- **matrizf concatenarMatricesEnVerticalF(matrizf matriz1, matrizf matriz2, int filasPrimeraMatriz, int filasSegundaMatriz, int columnasPrimeraTambienColumnasSegunda)**: Concatena dos matrices de floats verticalmente.

### Ejemplo de uso

```c
// Operaciones con vectores
vector v1 = leerVectorI(3, "Introduce el primer vector: ");
vector v2 = leerVectorI(3, "Introduce el segundo vector: ");

int escalar = productoEscalarI(v1, v2, 3);
vector producto = productoVectorialI(v1, v2);
vector concatenado = concatenarVectoresI(v1, v2, 3, 3);

imprimirVectorI(v1, 3);
imprimirVectorI(producto, 3);

// Operaciones con matrices
matriz m1 = leerMatrizI(2, 2, "Introduce la primera matriz: ");
matriz m2 = leerMatrizI(2, 2, "Introduce la segunda matriz: ");

matriz suma = sumarMatrI(m1, m2, 2, 2);
matriz producto_mat = multiplicarMatrI(m1, m2, 2, 2, 2);
int det = determinanteI(m1, 2);

imprimirMatrizI(suma, 2, 2);
printf("Determinante: %d\n", det);

// Generación de matrices aleatorias
matrizf aleatoria = generarMatrizF(3, 3, 0.0, 10.0, 2);
imprimirMatrizF(aleatoria, 3, 3);
```

---

## ------------ CAPÍTULO 8: OPERACIONES CON MATRICES OBJETO ------------

La biblioteca incluye estructuras de datos especializadas para matrices que encapsulan tanto los datos como las dimensiones, eliminando la necesidad de manejar manualmente los tamaños y proporcionando una interfaz más intuitiva y segura.

### Estructuras de datos

- **tipoMatriz**: Estructura que encapsula una matriz de enteros junto con sus dimensiones.
- **tipoMatrizf**: Estructura que encapsula una matriz de números reales junto con sus dimensiones.

Estas estructuras son especialmente útiles para ayudar al programador a no tener que preocuparse por los tamaños, ya que todos ellos son manejados de forma subyacente por la API.

### Funciones de entrada y salida

- **tipoMatriz leerMatrizI_O(int filas, int columnas, string imprimir)**: Lee una matriz de enteros desde teclado.
- **tipoMatrizf leerMatrizF_O(int filas, int columnas, string imprimir)**: Lee una matriz de floats desde teclado.
- **void imprimirMatrizI_O(tipoMatriz matrizParaImprimir)**: Imprime una matriz de enteros.
- **void imprimirMatrizF_O(tipoMatrizf matrizParaImprimir)**: Imprime una matriz de floats.

### Funciones de generación

- **tipoMatriz generarMatrizI_O(int filas, int columnas, int limiteInferior, int limiteSuperior)**: Genera una matriz de enteros con valores aleatorios.
- **tipoMatrizf generarMatrizF_O(int filas, int columnas, float limiteInferior, float limiteSuperior, int cifrasDePrecision)**: Genera una matriz de floats con valores aleatorios.

### Operaciones matemáticas

- **tipoMatriz multiplicarMatrI_O(tipoMatriz matriz1, tipoMatriz matriz2)**: Multiplica dos matrices de enteros.
- **tipoMatrizf multiplicarMatrF_O(tipoMatrizf matriz1, tipoMatrizf matriz2)**: Multiplica dos matrices de floats.
- **tipoMatriz sumarMatrI_O(tipoMatriz matriz1, tipoMatriz matriz2)**: Suma dos matrices de enteros.
- **tipoMatrizf sumarMatrF_O(tipoMatrizf matriz1, tipoMatrizf matriz2)**: Suma dos matrices de floats.
- **tipoMatriz restarMatrI_O(tipoMatriz matriz1, tipoMatriz matriz2)**: Resta dos matrices de enteros.
- **tipoMatrizf restarMatrF_O(tipoMatrizf matriz1, tipoMatrizf matriz2)**: Resta dos matrices de floats.
- **tipoMatriz numPorMatrI_O(int escalar, tipoMatriz matriz)**: Multiplica una matriz de enteros por un escalar.
- **tipoMatrizf numPorMatrF_O(float escalar, tipoMatrizf matriz)**: Multiplica una matriz de floats por un escalar.
- **int determinanteI_O(tipoMatriz matriz)**: Calcula el determinante de una matriz de enteros.
- **float determinanteF_O(tipoMatrizf matriz)**: Calcula el determinante de una matriz de floats.

### Operaciones de combinación

- **tipoMatriz concatenarMatricesEnHorizontalI_O(tipoMatriz matriz1, tipoMatriz matriz2)**: Concatena dos matrices de enteros horizontalmente.
- **tipoMatrizf concatenarMatricesEnHorizontalF_O(tipoMatrizf matriz1, tipoMatrizf matriz2)**: Concatena dos matrices de floats horizontalmente.
- **tipoMatriz concatenarMatricesEnVerticalI_O(tipoMatriz matriz1, tipoMatriz matriz2)**: Concatena dos matrices de enteros verticalmente.
- **tipoMatrizf concatenarMatricesEnVerticalF_O(tipoMatrizf matriz1, tipoMatrizf matriz2)**: Concatena dos matrices de floats verticalmente.

### Ventajas de las matrices objeto

- **Gestión automática de dimensiones**: No es necesario pasar manualmente las dimensiones a cada función.
- **Mayor seguridad**: Las operaciones verifican automáticamente la compatibilidad de dimensiones.
- **Código más limpio**: Sintaxis más intuitiva y menos propensa a errores.
- **Encapsulación**: Los datos y sus metadatos están unidos en una sola estructura.

### Ejemplo de uso

```c
// Crear matrices objeto
tipoMatriz m1 = leerMatrizI_O(2, 2, "Introduce la primera matriz: ");
tipoMatriz m2 = leerMatrizI_O(2, 2, "Introduce la segunda matriz: ");

// Operaciones matemáticas sin especificar dimensiones
tipoMatriz suma = sumarMatrI_O(m1, m2);
tipoMatriz producto = multiplicarMatrI_O(m1, m2);
int det = determinanteI_O(m1);

// Imprimir resultados
imprimirMatrizI_O(suma);
imprimirMatrizI_O(producto);
printf("Determinante: %d\n", det);

// Generar matriz aleatoria
tipoMatrizf aleatoria = generarMatrizF_O(3, 3, 0.0, 10.0, 2);
imprimirMatrizF_O(aleatoria);

// Concatenación
tipoMatriz horizontal = concatenarMatricesEnHorizontalI_O(m1, m2);
tipoMatriz vertical = concatenarMatricesEnVerticalI_O(m1, m2);
```

---

## -------------- CAPÍTULO 9: OPERACIONES CON PILAS --------------

La biblioteca incluye una implementación completa de la estructura de datos pila (stack), que funciona como un almacenamiento de datos de tipo LIFO (Last In, First Out - Último en entrar, primero en salir).

### Estructura de datos

- **Pila**: Estructura de datos que implementa el comportamiento LIFO, donde el último elemento insertado es el primero en ser extraído.

### Configuración del tipo de datos

El tipo de dato que almacenará la pila se define mediante la macro `TIPO_INFO_PILAS` pero se utilizará con tipoElementoP:

- **Por defecto**: Si no se define la macro, la pila almacenará enteros (`int`).
- **Configuración personalizada**: `#define TIPO_INFO_PILAS float` hará que la estructura almacene números reales.

**Nota**: Por restricciones del preprocesador de C, solo se puede trabajar con un tipo de dato por programa.

### Funciones principales

- **void pilaCreaVacia(Pila \*pilaParaInicializar)**: Inicializa una pila vacía, preparándola para su uso.

- **boolean pilaVacia(Pila \*pilaParaVerificar)**: Verifica si la pila está vacía. Devuelve `TRUE` si la pila no contiene elementos, `FALSE` en caso contrario.

- **int pilaInserta(tipoElementoP valorParaInsertar, Pila \*pilaDondeSeInsertara)**: Inserta un nuevo elemento en la cima de la pila. Devuelve un código de estado indicando el éxito o fracaso de la operación.

- **tipoElementoP pilaSuprime(Pila \*pilaDeLaQueSeExtraera)**: Extrae y devuelve el elemento que está en la cima de la pila. Si la pila está vacía, el comportamiento depende de la implementación.

- **void pilaImprime(Pila pilaParaImprimir)**: Imprime todos los elementos de la pila en la consola, mostrando su estructura LIFO.

### Características de la implementación

- **Gestión automática de memoria**: La pila maneja automáticamente la asignación y liberación de memoria.
- **Verificación de estado**: Funciones para verificar si la pila está vacía antes de realizar operaciones.
- **Flexibilidad de tipos**: Permite trabajar con diferentes tipos de datos mediante configuración de macros.
- **Operaciones estándar**: Implementa todas las operaciones básicas de una pila (push, pop, peek, isEmpty).

### Ejemplo de uso

```c
// Configurar el tipo de datos (opcional)
#define TIPO_INFO_PILAS int

// Declarar e inicializar la pila
Pila miPila;
pilaCreaVacia(&miPila);

// Verificar si está vacía
if (pilaVacia(&miPila) == TRUE) {
    printf("La pila está vacía\n");
}

// Insertar elementos
pilaInserta(10, &miPila);
pilaInserta(20, &miPila);
pilaInserta(30, &miPila);

// Imprimir la pila
printf("Contenido de la pila:\n");
pilaImprime(miPila);

// Extraer elementos (LIFO: 30, 20, 10)
tipoElementoP elemento1 = pilaSuprime(&miPila);  // 30
tipoElementoP elemento2 = pilaSuprime(&miPila);  // 20
tipoElementoP elemento3 = pilaSuprime(&miPila);  // 10

printf("Elementos extraídos: %d, %d, %d\n", elemento1, elemento2, elemento3);

// Verificar estado final
if (pilaVacia(&miPila) == TRUE) {
    printf("La pila está vacía nuevamente\n");
}
```

---

## -------------- CAPÍTULO 10: OPERACIONES CON COLAS --------------

La biblioteca incluye una implementación completa de la estructura de datos cola (queue), que funciona como un almacenamiento de datos de tipo FIFO (First In, First Out - Primero en entrar, primero en salir).

### Estructura de datos

- **Cola**: Estructura de datos que implementa el comportamiento FIFO, donde el primer elemento insertado es el primero en ser extraído.

### Configuración del tipo de datos

El tipo de dato que almacenará la cola se define mediante la macro `TIPO_INFO_COLAS` pero se utilizará con tipoElementoC:

- **Por defecto**: Si no se define la macro, la cola almacenará enteros (`int`).
- **Configuración personalizada**: `#define TIPO_INFO_COLAS float` hará que la estructura almacene números reales.

**Nota**: Por restricciones del preprocesador de C, solo se puede trabajar con un tipo de dato por programa.

### Funciones principales

- **void colaCreaVacia(Cola \*colaParaInicializar)**: Inicializa una cola vacía, preparándola para su uso.

- **boolean colaVacia(Cola \*colaParaVerificar)**: Verifica si la cola está vacía. Devuelve `TRUE` si la cola no contiene elementos, `FALSE` en caso contrario.

- **int colaInserta(tipoElementoC valorParaInsertar, Cola \*colaDondeSeInsertara)**: Inserta un nuevo elemento al final de la cola. Devuelve un código de estado indicando el éxito o fracaso de la operación.

- **tipoElementoC colaSuprime(Cola \*colaDeLaQueSeExtraera)**: Extrae y devuelve el elemento que está al frente de la cola. Si la cola está vacía, el comportamiento depende de la implementación.

- **void colaImprime(Cola colaParaImprimir)**: Imprime todos los elementos de la cola en la consola, mostrando su estructura FIFO.

### Características de la implementación

- **Gestión automática de memoria**: La cola maneja automáticamente la asignación y liberación de memoria.
- **Verificación de estado**: Funciones para verificar si la cola está vacía antes de realizar operaciones.
- **Flexibilidad de tipos**: Permite trabajar con diferentes tipos de datos mediante configuración de macros.
- **Operaciones estándar**: Implementa todas las operaciones básicas de una cola (enqueue, dequeue, peek, isEmpty).

### Ejemplo de uso

```c
// Configurar el tipo de datos (opcional)
#define TIPO_INFO_COLAS int

// Declarar e inicializar la cola
Cola miCola;
colaCreaVacia(&miCola);

// Verificar si está vacía
if (colaVacia(&miCola) == TRUE) {
    printf("La cola está vacía\n");
}

// Insertar elementos
colaInserta(10, &miCola);
colaInserta(20, &miCola);
colaInserta(30, &miCola);

// Imprimir la cola
printf("Contenido de la cola:\n");
colaImprime(miCola);

// Extraer elementos (FIFO: 10, 20, 30)
tipoElementoC elemento1 = colaSuprime(&miCola);  // 10
tipoElementoC elemento2 = colaSuprime(&miCola);  // 20
tipoElementoC elemento3 = colaSuprime(&miCola);  // 30

printf("Elementos extraídos: %d, %d, %d\n", elemento1, elemento2, elemento3);

// Verificar estado final
if (colaVacia(&miCola) == TRUE) {
    printf("La cola está vacía nuevamente\n");
}
```

---

## --- CAPÍTULO 11: LISTAS ENLAZADAS CON ORIENTACIÓN A OBJETOS ---

La biblioteca incluye implementaciones avanzadas de listas enlazadas que siguen paradigmas de programación orientada a objetos, proporcionando estructuras de datos flexibles y eficientes para diferentes necesidades.

### tipoLista - Lista orientada a objetos

Se define una estructura de datos especial llamada `tipoLista` que funciona como una lista enlazada con paradigmas de programación orientada a objetos.

#### Configuración de tipos de datos

La biblioteca soporta cinco tipos de datos diferentes para las listas:

- **Tres tipos configurables**: Controlados por las macros `TIPO1_INFO_LISTA`, `TIPO2_INFO_LISTA` y `TIPO3_INFO_LISTA` (por defecto `int`).
- **Dos tipos fijos**: Un tipo `int` y un tipo `float` siempre disponibles.

#### Inicialización

Para declarar y configurar una lista:

```c
tipoLista lista;
inicializarTipoLista(&lista);
colocarTipo[Info/2/3/Int/Float]EnLista(&lista);
```

#### Atributos de la lista

- **vacia**: Equivalente a `isEmpty` en otros lenguajes, indica si la lista está vacía.
- **numElementos**: Equivalente a `length`, indica el número de elementos en la lista.
- **lst**: La lista de nodos autorreferenciados propiamente dicha.

#### Métodos disponibles

- **annadirPPio**: Añade un elemento al principio de la lista.
- **annadirFin**: Añade un elemento al final de la lista.
- **annadirEnLugar**: Añade un elemento en una posición específica.
- **mostrarLista**: Imprime la lista por pantalla.
- **borrarPpio**: Borra el primer elemento de la lista.
- **borrarFin**: Borra el último elemento de la lista.
- **borrarElValor**: Borra el primer elemento con un valor específico.
- **modificarElValor**: Sustituye el primer elemento con un valor específico por otro.
- **vaciarLaLista**: Borra todos los elementos de la lista.

### tipoListaSalto - Lista con enlaces de salto

Es una lista circular doblemente enlazada de enteros con enlaces de salto que permiten acceso rápido a posiciones arbitrarias.

#### Características especiales

- **Enlaces de salto**: Cada nodo tiene enlaces adicionales a posiciones 2, 4, 8, 16... nodos adelante.
- **Acceso rápido**: Permite llegar a cualquier posición de la forma más eficiente posible.
- **Recálculo automático**: Cada operación recalcula automáticamente los saltos para mantener la eficiencia.

#### Métodos disponibles

- **annadirPpio**: Añade un elemento al principio.
- **annadirFin**: Añade un elemento al final.
- **annadirEnLugar**: Añade un elemento en una posición específica usando saltos.
- **mostrarLista**: Imprime la lista mostrando también los saltos.
- **borrarPpio**: Borra el primer nodo.
- **borrarFin**: Borra el último nodo.
- **borrarValor**: Borra el primer nodo con un valor específico.
- **modificarValor**: Sustituye el primer elemento con un valor específico.
- **vaciarLista**: Borra todos los elementos.

### tipoListaSet - Lista sin duplicados

Es una lista enlazada simple de enteros que no permite valores repetidos, ideal para representar conjuntos.

#### Características especiales

- **Sin duplicados**: Cada operación garantiza que no se almacenan valores repetidos.
- **Sin nodo centinela**: Implementación más eficiente en memoria.
- **Gestión automática**: Maneja automáticamente la inserción evitando duplicados.

#### Métodos disponibles

- **annadirPpio**: Añade un elemento al principio si no existe ya.
- **annadirFin**: Añade un elemento al final si no existe ya.
- **annadirEnLugar**: Añade un elemento en una posición específica si no existe ya.
- **mostrarLista**: Imprime la lista por pantalla.
- **borrarPpio**: Borra el primer nodo.
- **borrarFin**: Borra el último nodo.
- **borrarValor**: Borra el primer nodo con un valor específico.
- **vaciarLista**: Borra todos los elementos.

### Ejemplo de uso

```c
// Lista orientada a objetos
tipoLista lista;
inicializarTipoLista(&lista);
colocarTipoIntEnLista(&lista);

(lista.annadirPPio)(&lista, 10);
(lista.annadirFin)(&lista, 20);
(lista.annadirEnLugar)(&lista, 1, 15);
(lista.mostrarLista)(&lista);

// Lista con saltos
tipoListaSalto listaSalto;
inicializarListaSalto(&listaSalto);

listaSalto.annadirPpio(&listaSalto, 5);
listaSalto.annadirFin(&listaSalto, 10);
listaSalto.annadirEnLugar(&listaSalto, 1, 7);
listaSalto.mostrarLista(&listaSalto);

// Lista set (sin duplicados)
tipoListaSet set;
inicializarListaSet(&set);

set.annadirPpio(&set, 5);
set.annadirPpio(&set, 5);  // No se añade (duplicado)
set.annadirFin(&set, 10);
set.mostrarLista(&set);
```

---

## -------------- CAPÍTULO 12: OTRAS ESTRUCTURAS DE DATOS --------------

La biblioteca incluye implementaciones de estructuras de datos avanzadas como árboles, montículos y grafos, proporcionando herramientas completas para el manejo de datos jerárquicos y relaciones complejas.

### Árboles binarios

Se define el tipo de dato `Arbol` que almacena datos en forma de árbol binario.

#### Configuración del tipo de datos

El tipo de dato se controla con la macro `TIPO_INFO_ARBOL`, permitiendo personalizar el tipo de información almacenada en cada nodo.

#### Funciones principales

- **Arbol creaArbol(tipoInfoArbol datoParaLaRaiz)**: Crea un nuevo árbol con el dato especificado como raíz.

- **void preOrden(Arbol arbolParaRecorrer)**: Recorre el árbol en preorden (raíz, izquierda, derecha).
- **void enOrden(Arbol arbolParaRecorrer)**: Recorre el árbol en inorden (izquierda, raíz, derecha).
- **void posOrden(Arbol arbolParaRecorrer)**: Recorre el árbol en postorden (izquierda, derecha, raíz).

- **void amplitudArbol(Arbol arbolParaRecorrer)**: Recorre el árbol por niveles (amplitud).

- **int altura(Arbol nodoParaEvaluar)**: Calcula la altura del árbol o subárbol.

- **int numNodos(Arbol arbolParaRecorrer)**: Cuenta el número total de nodos.
- **int numNodosHoja(Arbol arbolParaRecorrer)**: Cuenta el número de nodos hoja.
- **int numNodosInternos(Arbol arbolParaRecorrer)**: Cuenta el número de nodos internos.

- **int sustituye(Arbol raiz, tipoInfoArbol x, tipoInfoArbol y)**: Sustituye todas las ocurrencias de x por y en el árbol.

- **int numHijoUnico(Arbol arbolParaEvaluar)**: Cuenta el número de nodos con un solo hijo.

- **Arbol buscarMax(Arbol arbolParaBuscar)**: Encuentra el nodo con el valor máximo.
- **Arbol buscarMin(Arbol arbolParaBuscar)**: Encuentra el nodo con el valor mínimo.

- **boolean similares(Arbol arbol1, Arbol arbol2)**: Verifica si dos árboles tienen la misma estructura.
- **boolean equivalentes(Arbol arbol1, Arbol arbol2)**: Verifica si dos árboles son idénticos.

- **Arbol especular(Arbol arbolParaEspecularizar)**: Crea el espejo del árbol (intercambia hijos izquierdo y derecho).

### Montículos (Heaps)

Se define el tipo de dato `Monticulo` que funciona como un árbol binario ordenado.

#### Configuración

El comportamiento se controla mediante tres macros:

- **NUM_ELEMS_MONT**: Número máximo de elementos (por defecto 100).
- **TIPO_CLAVE_MONT**: Tipo de dato para las claves (por defecto `int`).
- **TIPO_INFO_MONT**: Tipo de dato para los valores (por defecto `int`).

#### Funciones principales

- **void crearMonticulo(Monticulo \*m)**: Crea un nuevo montículo.
- **void iniciarMonticulo(Monticulo \*m)**: Inicializa un montículo existente.
- **void vaciarMonticulo(Monticulo \*m)**: Vacía el montículo.

- **void filtradoAscendente(Monticulo \*m, int valorParaFiltrar)**: Aplica filtrado ascendente.
- **void filtradoDescendente(Monticulo \*m, int valorParaFiltrar)**: Aplica filtrado descendente.

- **void insertar(Monticulo \*m, tipoClaveMont clave, tipoInfoMont info)**: Inserta un nuevo elemento.
- **void eliminarMinimo(Monticulo \*m)**: Elimina el elemento mínimo.

- **void decrementarClave(Monticulo \*m, int posicion, int nuevaClave)**: Decrementa la clave de un elemento.
- **void incrementarClave(Monticulo \*m, int posicion, int nuevaClave)**: Incrementa la clave de un elemento.

- **boolean esMonticulo(Monticulo \*m)**: Verifica si la estructura cumple las propiedades de montículo.

### Grafos

Se define el tipo de dato `tipoGrafo` para representar grafos con un número limitado de nodos.

#### Configuración

- **NUM_ELEMS_GRAFO**: Número máximo de nodos (por defecto 20).

#### Funciones principales

- **void iniciarGrafo(tipoGrafo \*g)**: Inicializa un grafo vacío.

- **void profundidad(tipoGrafo \*g, int nodoInicial)**: Realiza recorrido en profundidad (DFS).
- **void amplitud(tipoGrafo \*g, int nodoInicial)**: Realiza recorrido en amplitud (BFS).

- **void ordenTop(tipoGrafo \*g)**: Calcula el ordenamiento topológico.

- **void caminos(tipoGrafo \*g, int origen, int destino)**: Encuentra caminos entre dos nodos.

- **void djikstra(tipoGrafo \*g, int nodoOrigen)**: Aplica el algoritmo de Dijkstra.

- **void costeyTrayectoria(tipoGrafo \*g, int origen, int destino)**: Calcula el costo y trayectoria entre dos nodos.

- **void todosCaminosMin(tipoGrafo \*g)**: Encuentra todos los caminos mínimos (Floyd-Warshall).

- **void buscarVertices(tipoGrafo \*g, int criterio)**: Busca vértices según un criterio específico.

#### Función especial

- **void construirMonticuloDeAristas(tipoGrafo *grafo, Monticulo *m)**: Construye un montículo a partir de las aristas del grafo, útil para algoritmos como Kruskal.

### Ejemplo de uso

```c
// Crear y manipular un árbol
Arbol arbol = creaArbol(10);
// ... insertar más nodos ...
preOrden(arbol);
printf("Altura: %d\n", altura(arbol));
printf("Nodos: %d\n", numNodos(arbol));

// Trabajar con montículos
Monticulo monticulo;
crearMonticulo(&monticulo);
insertar(&monticulo, 5, 100);
insertar(&monticulo, 3, 200);
insertar(&monticulo, 7, 150);
eliminarMinimo(&monticulo);

// Manejar grafos
tipoGrafo grafo;
iniciarGrafo(&grafo);
// ... añadir nodos y aristas ...
djikstra(&grafo, 0);
amplitud(&grafo, 0);
```

---

## ------ CAPÍTULO 13: ALGORITMOS DE PLANIFICACIÓN DE PROCESOS -------

En este capítulo se describen los principales algoritmos de planificación de procesos utilizados en sistemas operativos para gestionar la ejecución de tareas. Estos algoritmos determinan el orden en que los procesos acceden a la CPU, optimizando criterios como el tiempo de espera, el tiempo de respuesta o el uso de recursos. A continuación se explican los más relevantes:

- **FCFS (First Come, First Served / Primero en llegar, primero en ser servido):**

  - Los procesos se atienden en el orden en que llegan a la cola de listos.
  - Es sencillo de implementar, pero puede provocar largos tiempos de espera para procesos cortos si llegan detrás de procesos largos (efecto convoy).

- **SJF (Shortest Job First / El trabajo más corto primero):**

  - Se selecciona el proceso con el menor tiempo de ejecución estimado.
  - Minimiza el tiempo de espera promedio, pero requiere conocer o estimar la duración de los procesos.
  - Puede provocar inanición de procesos largos.

- **SRTF (Shortest Remaining Time First / Menor tiempo restante primero):**

  - Variante de SJF, pero con desalojo: si llega un proceso con menor tiempo restante, se interrumpe el actual.
  - Ofrece mejor tiempo de respuesta, pero es más complejo de implementar.

- **Round Robin (RR):**

  - Cada proceso recibe un intervalo de tiempo fijo (quantum) para ejecutarse.
  - Si no termina en ese tiempo, pasa al final de la cola.
  - Es justo y adecuado para sistemas interactivos, pero la elección del quantum es crítica.

- **Multinivel con retroalimentación:**

  - Existen varias colas con diferentes prioridades o algoritmos.
  - Los procesos pueden cambiar de cola según su comportamiento (retroalimentación).
  - Permite adaptar el sistema a diferentes tipos de procesos (interactivos, por lotes, etc.).

Cada algoritmo tiene ventajas e inconvenientes, y la elección depende del contexto y los objetivos del sistema.

## -------------- CAPÍTULO 14: ALGORITMOS DE BÚSQUEDA --------------

En este capítulo se describen los principales algoritmos de búsqueda implementados en la biblioteca, tanto para enteros como para números reales. Los algoritmos de búsqueda permiten localizar la posición de un elemento dentro de un vector, devolviendo la posición si se encuentra o -1 si no está o si ocurre algún error. A continuación se explican los algoritmos incluidos:

- **Búsqueda lineal (Linear Search):**

  - Recorre el vector elemento a elemento hasta encontrar el valor buscado.
  - No requiere que el vector esté ordenado.
  - Es sencilla pero poco eficiente para vectores grandes (O(n)).

- **Búsqueda binaria (Binary Search):**

  - Solo funciona en vectores ordenados ascendentemente.
  - Divide el vector en mitades y compara el valor buscado con el elemento central, descartando la mitad que no puede contenerlo.
  - Muy eficiente (O(log n)), pero requiere comprobación previa de orden.

- **Búsqueda ternaria (Ternary Search):**

  - Variante de la búsqueda binaria, pero divide el vector en tres partes en cada paso.
  - También requiere que el vector esté ordenado.
  - Eficiencia similar a la binaria, pero con más comparaciones por iteración.

- **Búsqueda exponencial (Exponential Search):**

  - Útil para vectores muy grandes y ordenados.
  - Busca un rango exponencialmente creciente donde podría estar el valor y luego aplica búsqueda binaria en ese rango.
  - Complejidad O(log i), donde i es la posición del elemento buscado.

- **Búsqueda por saltos (Jump Search):**

  - Solo para vectores ordenados.
  - Salta bloques de tamaño fijo (raíz cuadrada del tamaño del vector) y luego realiza búsqueda lineal en el bloque donde podría estar el valor.
  - Eficiencia O(√n).

- **Búsqueda de Fibonacci (Fibonacci Search):**
  - Variante de la búsqueda binaria que utiliza números de Fibonacci para determinar los rangos de búsqueda.
  - Solo para vectores ordenados.
  - Eficiencia O(log n), útil en ciertos contextos donde el acceso a memoria es costoso.

Todas las funciones de búsqueda de la biblioteca devuelven la posición del elemento encontrado o FALLO o SUPERFALLO si no está o si ocurre algún fallo de programación defensiva (por ejemplo, vector no ordenado cuando es necesario o recibir valores nulos).

### Tabla de eficiencia de los algoritmos de búsqueda

| Algoritmo             | Mejor caso | Peor caso | Caso promedio |
| --------------------- | ---------- | --------- | ------------- |
| Búsqueda lineal       | O(1)       | O(n)      | O(n)          |
| Búsqueda binaria      | O(1)       | O(log n)  | O(log n)      |
| Búsqueda ternaria     | O(1)       | O(log₃ n) | O(log₃ n)     |
| Búsqueda exponencial  | O(1)       | O(log n)  | O(log n)      |
| Búsqueda por saltos   | O(1)       | O(√n)     | O(√n)         |
| Búsqueda de Fibonacci | O(1)       | O(log n)  | O(log n)      |

- **Notas:**
  - En la búsqueda lineal, el mejor caso es encontrar el elemento en la primera posición.
  - En la binaria, ternaria, exponencial y Fibonacci, el mejor caso es encontrar el elemento en el primer intento (centro o primer salto).
  - Todas las búsquedas, salvo la lineal, requieren el vector ordenado.

## -------------- CAPÍTULO 15: ALGORITMOS DE ORDENACIÓN --------------

En este capítulo se explican los algoritmos de ordenación implementados en la biblioteca, tanto clásicos como avanzados, para enteros y números reales. Los algoritmos de ordenación permiten reorganizar los elementos de un vector o lista según un criterio (habitualmente de menor a mayor). A continuación se describen los principales algoritmos incluidos:

- **Bubble Sort (Ordenación de burbuja):**

  - Compara elementos adyacentes y los intercambia si están desordenados.
  - Repite el proceso hasta que no se realizan más intercambios.
  - Es sencillo pero poco eficiente para grandes volúmenes de datos (O(n²)).

- **Selection Sort (Ordenación por selección):**

  - Busca el elemento más pequeño y lo coloca en la primera posición, luego repite con el resto.
  - Realiza un número fijo de comparaciones, pero también es O(n²).

- **Insertion Sort (Ordenación por inserción):**

  - Inserta cada elemento en su posición correcta dentro de la parte ya ordenada del vector.
  - Muy eficiente para vectores pequeños o casi ordenados.

- **Merge Sort (Ordenación por mezcla):**

  - Divide el vector en mitades, ordena cada mitad recursivamente y luego las fusiona.
  - Complejidad O(n log n), estable y eficiente para grandes volúmenes.

- **Quick Sort (Ordenación rápida):**

  - Selecciona un pivote y divide el vector en elementos menores y mayores que el pivote, ordenando recursivamente.
  - Muy eficiente en la práctica (O(n log n) promedio), pero puede ser O(n²) en el peor caso.

- **Shell Sort:**

  - Variante de insertion sort que compara elementos separados por un intervalo, reduciendo el intervalo progresivamente.
  - Mejora el rendimiento respecto a insertion sort en vectores grandes.

- **Gnome Sort:**

  - Similar a insertion sort, pero se mueve hacia atrás intercambiando elementos desordenados.
  - Sencillo de implementar, pero O(n²).

- **Comb Sort:**

  - Variante de bubble sort que compara elementos separados por una distancia que disminuye en cada pasada.
  - Reduce el número de comparaciones respecto a bubble sort.

- **Odd-Even Sort (Ordenación par-impar):**

  - Realiza pasadas alternando comparaciones entre pares e impares de elementos adyacentes.
  - Útil en entornos paralelos.

- **Bitonic Sort:**

  - Algoritmo paralelo que ordena secuencias bitónicas (primero crecientes, luego decrecientes).
  - Eficiente en hardware especializado.

- **Pancake Sort:**

  - Ordena el vector mediante inversiones (flips) de los primeros k elementos.
  - Inspirado en el problema de ordenar una pila de tortitas de diferentes tamaños.

- **Stooge Sort:**

  - Algoritmo recursivo poco eficiente (O(n^{2.709})), de interés principalmente académico.

- **Counting Sort:**

  - Cuenta las apariciones de cada valor y las utiliza para colocar los elementos en orden.
  - Muy eficiente para enteros en un rango pequeño.

- **Radix Sort:**

  - Ordena los números procesando sus dígitos de menor a mayor (o viceversa).
  - Eficiente para grandes volúmenes de enteros.

- **Bucket Sort:**

  - Distribuye los elementos en "cubos" según su valor, ordena cada cubo y los concatena.
  - Muy eficiente para datos uniformemente distribuidos.

- **Pigeonhole Sort:**

  - Similar a counting sort, pero coloca los elementos directamente en "casillas" según su valor.
  - Eficiente para rangos pequeños.

Cada algoritmo tiene ventajas y desventajas según el tipo y tamaño de los datos. La biblioteca implementa versiones para enteros y floats, siguiendo el patrón de diseño de la librería.

### Tabla de eficiencia de los algoritmos de ordenación

| Algoritmo       | Mejor caso   | Peor caso    | Caso promedio |
| --------------- | ------------ | ------------ | ------------- |
| Bubble Sort     | O(n)         | O(n²)        | O(n²)         |
| Selection Sort  | O(n²)        | O(n²)        | O(n²)         |
| Insertion Sort  | O(n)         | O(n²)        | O(n²)         |
| Merge Sort      | O(n log n)   | O(n log n)   | O(n log n)    |
| Quick Sort      | O(n log n)   | O(n²)        | O(n log n)    |
| Shell Sort      | O(n log n)   | O(n²)        | O(n^1.5)      |
| Gnome Sort      | O(n)         | O(n²)        | O(n²)         |
| Comb Sort       | O(n log n)   | O(n²)        | O(n²)         |
| Odd-Even Sort   | O(n)         | O(n²)        | O(n²)         |
| Bitonic Sort    | O(log² n)    | O(log² n)    | O(log² n)     |
| Pancake Sort    | O(n)         | O(n²)        | O(n²)         |
| Stooge Sort     | O(n^{2.709}) | O(n^{2.709}) | O(n^{2.709})  |
| Counting Sort   | O(n + k)     | O(n + k)     | O(n + k)      |
| Radix Sort      | O(nk)        | O(nk)        | O(nk)         |
| Bucket Sort     | O(n + k)     | O(n²)        | O(n + k)      |
| Pigeonhole Sort | O(n + r)     | O(n + r)     | O(n + r)      |

- **Notas:**
  - n: número de elementos a ordenar.
  - k: rango de los datos (en Counting, Radix, Bucket, American Flag, Postman).
  - r: rango de valores posibles (en Pigeonhole).
  - En algunos algoritmos, el mejor caso ocurre cuando el vector ya está ordenado.
  - Bitonic Sort es eficiente en hardware especializado.
  - Stooge Sort es principalmente de interés académico por su ineficiencia.

## ----------------- CAPÍTULO 16: BARAJA DE CARTAS -------------------

La biblioteca incluye un completo módulo para la gestión y manipulación de barajas de cartas, pensado tanto para juegos clásicos como para utilidades didácticas.

### Funciones principales

- **carta\* generarBaraja(void)**: Genera una baraja estándar de 52 cartas (1-13 de cada palo). Devuelve un puntero a un array dinámico que debe liberarse con `free`.
- **int shuffle(carta \*mazo, int numCartas)**: Baraja aleatoriamente el mazo recibido. Devuelve `EXITO` o `FALLO`.
- **juego* repartir(carta *mazo, jugador \*jugadores, int numJugadores, int cartasPorJugador)**: Reparte cartas del mazo entre los jugadores, asignando dinámicamente las manos. Devuelve un puntero a la estructura `juego`.
- **carta robarCarta(mano \*mazo)**: Extrae la primera carta de la mano/mazo y la devuelve, reduciendo el número de cartas.
- **carta sacarCarta(mano \*mazo, int valor, palo palo)**: Busca y extrae una carta concreta de la mano/mazo.
- **int cogerCarta(mano \*mazo, carta c)**: Añade una carta a la mano/mazo, gestionando la memoria.
- **void mostrarMazo(jugador j)**: Muestra por pantalla el nombre del jugador y todas sus cartas en formato textual (ejemplo: "rey de picas").
- **void mostrarCarta(carta c)**: Muestra una carta individual en formato textual (ejemplo: "as de corazones").

### Ejemplo de uso básico

```c
carta *mazo = generarBaraja();
shuffle(mazo, 52);
jugador jugadores[2];
jugadores[0].nombre = "Ana";
jugadores[1].nombre = "Luis";
juego *j = repartir(mazo, jugadores, 2, 5);
mostrarMazo(j->jugadores[0]);
mostrarMazo(j->jugadores[1]);
carta robada = robarCarta(&j->jugadores[0].mano);
printf("Ana roba: "); mostrarCarta(robada); printf("\n");
free(mazo);
for (int i = 0; i < j->numJugadores; i++) free(j->jugadores[i].mano.cartas);
free(j->jugadores); free(j);
```

## -------------- CAPÍTULO 17: DIAGRAMAS DE GANTT --------------

La biblioteca incluye un módulo completo para la gestión y visualización de diagramas de Gantt, herramientas esenciales en la gestión de proyectos para planificar y programar tareas.

### Estructuras de datos

- **tarea**: Representa una tarea individual del proyecto con:

  - `id`: Identificador único de la tarea
  - `nombre`: Nombre descriptivo de la tarea
  - `duracion`: Duración en unidades de tiempo
  - `dependencias`: Array con los IDs de las tareas de las que depende
  - `numDependencias`: Número de dependencias
  - `tiempoInicio`: Tiempo de inicio mínimo de la tarea

- **gantt**: Contiene toda la información del proyecto:
  - `tareas`: Array de tareas del proyecto
  - `numTareas`: Número total de tareas
  - `caminoCritico`: Array con los IDs de las tareas del camino crítico
  - `numCaminoCritico`: Número de tareas en el camino crítico
  - `nombreProyecto`: Nombre del proyecto

### Funciones principales

- **gantt\* crearGantt(string nombreProyecto)**: Crea un nuevo diagrama de Gantt vacío con el nombre especificado. Devuelve un puntero que debe liberarse manualmente.

- **boolean comprobarGanttValido(gantt \*g)**: Verifica que el diagrama no contenga ciclos en sus dependencias. Devuelve `TRUE` si es válido, `FALSE` si tiene ciclos.

- **int elaborarCaminoCritico(gantt \*g)**: Calcula el camino crítico del proyecto identificando las tareas con holgura cero. Escribe en el array `caminoCritico` los IDs en orden de ejecución. Devuelve `EXITO`, `FALLO` o `SUPERFALLO`.

- **int annadirTarea(gantt *g, int id, string nombre, int duracion, int *dependencias, int numDependencias, int tiempoInicio)**: Añade una nueva tarea al diagrama solo si no crea ciclos. Devuelve `EXITO`, `FALLO` o `SUPERFALLO`.

- **void pintarDiagrama(gantt \*g)**: Visualiza el diagrama de Gantt en la consola usando caracteres ASCII, donde las almohadillas (`#`) representan los tiempos de ejecución de cada tarea.

### Ejemplo de uso básico

```c
gantt *proyecto = crearGantt("Proyecto ejemplo");

// Añadir tareas
annadirTarea(proyecto, 1, "A", 3, NULL, 0, 0);
annadirTarea(proyecto, 2, "B", 4, NULL, 0, 0);
annadirTarea(proyecto, 3, "C", 2, (int[]){1}, 1, 0);
annadirTarea(proyecto, 4, "D", 5, (int[]){2, 3}, 2, 0);

// Verificar validez y calcular camino crítico
if (comprobarGanttValido(proyecto)) {
    elaborarCaminoCritico(proyecto);
    pintarDiagrama(proyecto);
}

// Liberar memoria
free(proyecto->nombreProyecto);
for (int i = 0; i < proyecto->numTareas; i++) {
    free(proyecto->tareas[i].nombre);
    if (proyecto->tareas[i].dependencias) {
        free(proyecto->tareas[i].dependencias);
    }
}
free(proyecto->tareas);
if (proyecto->caminoCritico) free(proyecto->caminoCritico);
free(proyecto);
```

### Características técnicas

- **Detección de ciclos**: Utiliza un algoritmo de búsqueda en profundidad (DFS) para detectar ciclos en las dependencias entre tareas.

- **Cálculo de tiempos**: Determina automáticamente los tiempos de inicio más tempranos y tardíos de cada tarea, considerando las dependencias.

- **Camino crítico**: Identifica las tareas que no pueden retrasarse sin afectar la duración total del proyecto (holgura = 0).

- **Visualización**: Genera una representación gráfica en consola que muestra la programación temporal de todas las tareas.

Esta funcionalidad es especialmente útil para la gestión de proyectos, planificación de recursos y análisis de dependencias entre tareas.

## -------------- CAPÍTULO 18: ESTIMACIÓN DE ESFUERZO --------------

La biblioteca incluye una función para estimar el esfuerzo en horas de desarrollo de proyectos software utilizando el modelo de puntos de caso de uso (UCP - Use Case Points).

### Funciones principales

- **void estimarEsfuerzo(void)**: Realiza una estimación completa del esfuerzo mediante una secuencia de preguntas interactivas sobre el proyecto.

### Proceso de estimación

La función sigue el siguiente flujo de preguntas:

1. **Casos de uso**: Número de casos de uso simples, medios y complejos
2. **Actores**: Número de actores simples, medios y complejos
3. **Factores técnicos**: Puntuación de 0 a 5 para 13 factores de complejidad técnica:

   - Sistemas distribuidos, rendimiento, eficiencia de usuario final
   - Procesamiento interno complejo, reusabilidad, facilidad de instalación
   - Facilidad de uso, portabilidad, facilidad de cambio, concurrencia
   - Seguridad, acceso directo a terceras partes, entrenamiento especial del usuario

4. **Factores de entorno**: Puntuación de 0 a 5 para 8 factores del entorno de desarrollo:
   - Familiaridad con UML, trabajadores a tiempo parcial, capacidad de los analistas
   - Experiencia en entornos de desarrollo, experiencia en orientación a objetos
   - Motivación, dificultad del lenguaje de programación, estabilidad de los requisitos

### Cálculo del esfuerzo

La estimación utiliza la fórmula estándar UCP:

- **UUCW** (Unadjusted Use Case Weight): Casos simples×5 + medios×10 + complejos×15
- **UAW** (Unadjusted Actor Weight): Actores simples×1 + medios×2 + complejos×3
- **TCF** (Technical Complexity Factor): 0.6 + (0.01 × suma de factores técnicos ponderados)
- **ECF** (Environmental Complexity Factor): 1.4 + (-0.03 × suma de factores de entorno ponderados)
- **UCP** = (UUCW + UAW) × TCF × ECF
- **Horas estimadas** = UCP × 27.493

### Ejemplo de uso

```c
estimarEsfuerzo();  // Inicia el proceso interactivo de estimación
```

Esta funcionalidad es especialmente útil para la planificación de proyectos software, estimación de costes y asignación de recursos en el desarrollo de aplicaciones.

## ------------ CAPÍTULO 19: CÓDIGOS CORRECTORES DE ERRORES -------------

La biblioteca incluye un módulo completo para la implementación y gestión de códigos correctores de errores, específicamente códigos de Hamming y códigos lineales generales. Estos códigos son fundamentales en la teoría de la información para detectar y corregir errores en la transmisión de datos.

### Estructuras de datos

- **bit_t**: Tipo de dato que representa un bit (**0 o **1)
- **palabra**: Puntero a un array de bits (bit_t\*)
- **codigo**: Estructura que contiene:
  - `G`: Matriz generadora (bit_t\*\*)
  - `H`: Matriz de paridad (bit_t\*\*)
  - `n`: Longitud del código
  - `m`: Dimensión del espacio de mensajes
  - `s`: Número de bits de información
  - `t`: Capacidad de corrección
  - `d`: Distancia mínima

### Funciones principales

- **palabra encriptar(palabra p, codigo c)**: Codifica un mensaje multiplicándolo por la matriz generadora G. Devuelve la palabra codificada.

- **palabra desencriptar(palabra p, codigo c)**: Decodifica una palabra recibida, detecta y corrige errores usando la matriz de paridad H, y extrae los bits de información original.

- **palabra sindrome(palabra p, codigo c)**: Calcula el síndrome de una palabra multiplicándola por la matriz de paridad H transpuesta. El síndrome indica si hay errores y su posición.

- **codigo generarHamming(int r)**: Genera un código de Hamming estándar con parámetro r. El código tendrá n = 2^r - 1, m = 2^r - r - 1, y distancia mínima 3.

- **codigo generarG_estandar(int k, int n)**: Genera una matriz generadora G en forma estándar [I|A] para un código (n,k).

- **void cambiarBit(palabra p, int posicion)**: Cambia el valor de un bit en una posición específica de una palabra.

- **int peso(palabra p)**: Calcula el peso de una palabra (número de bits a 1).

- **void _normalizarG(codigo_ c)**: Normaliza la matriz generadora G a forma estándar [I|A] usando operaciones elementales de filas.

- **int H2G_estandar(codigo\* c)**: Calcula la matriz generadora G a partir de la matriz de paridad H, asumiendo forma estándar.

- **int G2H_estandar(codigo\* c)**: Calcula la matriz de paridad H a partir de la matriz generadora G, asumiendo forma estándar.

- **int calcularS(codigo\* c)**: Calcula el número de bits de información del código.

- **int calcularT(codigo\* c)**: Calcula la capacidad de corrección del código.

- **int calcularNyM(codigo\* c)**: Calcula los parámetros n y m del código.

- **int calcularD(codigo\* c)**: Calcula la distancia mínima del código.

- **codigo generarCodigoInicializado(bit_t** b)\*\*: Genera un código a partir de una matriz de bits dada.

- **bit_t sacarBit(short int s)**: Extrae un bit de un entero corto.

- **boolean bitEsDeInfo(bit_t** b, int i, int j)\*\*: Determina si un bit en la posición (i,j) es un bit de información.

### Ejemplo de uso básico

```c
// Generar un código Hamming(7,4)
codigo c = generarHamming(3);

// Mensaje original de 4 bits
palabra mensaje = (bit_t[]){__1, __0, __1, __0};

// Codificar
palabra codificado = encriptar(mensaje, c);

// Introducir un error
cambiarBit(codificado, 2);

// Decodificar y corregir
palabra decodificado = desencriptar(codificado, c);

// Liberar memoria
free(codificado);
free(decodificado);
for (int i = 0; i < c.m; i++) free(c.G[i]);
free(c.G);
for (int i = 0; i < c.n - c.m; i++) free(c.H[i]);
free(c.H);
```

### Características técnicas

- **Códigos de Hamming**: Implementación completa de códigos Hamming estándar para cualquier parámetro r.
- **Detección y corrección**: Capacidad de detectar y corregir errores de 1 bit en códigos de Hamming.
- **Matrices sistemáticas**: Generación automática de matrices G y H en forma sistemática.
- **Verificación**: Funciones para verificar la consistencia entre matrices G y H (G\*H^T = 0).
- **Flexibilidad**: Soporte para códigos lineales generales además de códigos de Hamming.

Esta funcionalidad es esencial para aplicaciones de comunicaciones digitales, almacenamiento de datos y cualquier sistema que requiera transmisión confiable de información.

## -------------- CAPÍTULO 20: HIPERPLANOS --------------

La biblioteca incluye un módulo completo para el manejo de hiperplanos en espacios vectoriales de cualquier dimensión. Un hiperplano es una generalización de planos y rectas a espacios de dimensión arbitraria, representado como un sistema de ecuaciones lineales homogéneas.

### Estructuras de datos

- **hiperplano**: Estructura que representa un hiperplano con:
  - `dimension`: Número de variables del espacio
  - `ecuaciones`: Número de ecuaciones que definen el hiperplano
  - `nombresVariables`: Array de caracteres con los nombres de las variables
  - `info`: Array con los coeficientes de las ecuaciones (sin términos independientes)

### Funciones principales

- **hiperplano leerHiperplano(int dimension)**: Lee un hiperplano desde teclado, solicitando los nombres de las variables y los coeficientes de cada ecuación. Las ecuaciones se almacenan en forma homogénea (término independiente = 0).

- **void imprimirHiperplano(hiperplano h)**: Imprime el hiperplano en forma de ecuaciones, mostrando cada ecuación como una combinación lineal de variables igualada a cero.

- **hiperplano hiperplanoOrtogonal(hiperplano h, int ecuacion)**: Calcula el subespacio ortogonal al hiperplano dado. Utiliza eliminación gaussiana para encontrar una base del espacio nulo (kernel) de la matriz de coeficientes.

- **hiperplano hiperplanoInterseccion(hiperplano h1, hiperplano h2)**: Calcula la intersección de dos hiperplanos de la misma dimensión. Combina las ecuaciones de ambos hiperplanos y las reduce a un conjunto mínimo de ecuaciones linealmente independientes mediante eliminación gaussiana.

### Ejemplo de uso básico

```c
// Leer un hiperplano de 3 dimensiones
hiperplano h1 = leerHiperplano(3);

// Imprimir el hiperplano
printf("Hiperplano leído:\n");
imprimirHiperplano(h1);

// Calcular el subespacio ortogonal
hiperplano ort = hiperplanoOrtogonal(h1, 0);
printf("Subespacio ortogonal:\n");
imprimirHiperplano(ort);

// Leer un segundo hiperplano para calcular intersección
hiperplano h2 = leerHiperplano(3);
hiperplano interseccion = hiperplanoInterseccion(h1, h2);
printf("Intersección de hiperplanos:\n");
imprimirHiperplano(interseccion);

// Liberar memoria
free(h1.nombresVariables);
free(h1.info);
free(h2.nombresVariables);
free(h2.info);
free(ort.nombresVariables);
free(ort.info);
free(interseccion.nombresVariables);
free(interseccion.info);
```

### Características técnicas

- **Ecuaciones homogéneas**: Todas las ecuaciones se representan en forma homogénea (Ax = 0), eliminando la necesidad de manejar términos independientes.

- **Eliminación gaussiana**: Utiliza eliminación gaussiana para calcular bases de subespacios ortogonales y reducir sistemas de ecuaciones a forma escalonada.

- **Validación de dimensiones**: Verifica que los hiperplanos tengan la misma dimensión antes de realizar operaciones de intersección.

- **Gestión de memoria**: Manejo automático de la memoria dinámica para los arrays de coeficientes y nombres de variables.

Esta funcionalidad es fundamental para aplicaciones de geometría computacional, álgebra lineal, optimización y análisis de sistemas de ecuaciones lineales en espacios de dimensión arbitraria.

## -------------- CAPÍTULO 21: AUTÓMATAS FINITOS --------------

La biblioteca incluye un módulo completo para la implementación y gestión de autómatas finitos deterministas y no deterministas. Los autómatas finitos son modelos computacionales fundamentales en la teoría de lenguajes formales y teoría de la computación, utilizados para reconocer patrones y validar cadenas de símbolos.

### Estructuras de datos

- **tipoAutomata**: Estructura que representa un autómata finito con:
  - `alfabeto`: Array de caracteres que representa los símbolos del alfabeto
  - `numSimbolos`: Número de símbolos en el alfabeto
  - `estados`: Array de strings con los nombres de los estados
  - `numEstados`: Número de estados del autómata
  - `transiciones`: Matriz de strings que representa la función de transición (estado × símbolo → estado)
  - `estadoInicial`: String con el nombre del estado inicial
  - `estadosFinales`: Array de strings con los nombres de los estados finales
  - `numEstadosFinales`: Número de estados finales

### Funciones principales

- **tipoAutomata* crearAutomata(char* alfabeto, int numSimbolos, string\* estados, int numEstados, string** transiciones, string estadoInicial, string\* estadosFinales, int numEstadosFinales)\*\*: Crea un autómata finito con los parámetros especificados. La matriz de transiciones debe tener dimensiones [numEstados][numSimbolos] y contener los nombres de los estados destino. Para autómatas no deterministas, las transiciones faltantes se representan con NULL o '\0'. Devuelve un puntero al autómata creado o NULL si hay errores.

- **boolean evaluarCadena(tipoAutomata\* automata, string cadena)**: Evalúa una cadena de entrada en el autómata. Procesa la cadena símbolo por símbolo, siguiendo las transiciones del autómata desde el estado inicial. Devuelve TRUE si el autómata termina en un estado final después de procesar toda la cadena, FALSE en caso contrario (incluyendo errores o transiciones faltantes).

- **void destruirAutomata(tipoAutomata\* automata)**: Libera toda la memoria asociada al autómata, incluyendo la matriz de transiciones y sus strings anidados.

### Ejemplo de uso básico

```c
// Definir alfabeto y estados
char alfabeto[] = "01";
string estados[] = {"q0", "q1", "q2"};
string estadoInicial = "q0";
string estadosFinales[] = {"q2"};

// Definir matriz de transiciones (estado × símbolo → estado)
string transiciones[3][2] = {
    {"q1", "q0"},  // q0 con 0 → q1, q0 con 1 → q0
    {"q2", "q1"},  // q1 con 0 → q2, q1 con 1 → q1
    {"q2", "q0"}   // q2 con 0 → q2, q2 con 1 → q0
};

// Crear punteros para la matriz de transiciones
string* transicionesPtr[3];
for (int i = 0; i < 3; i++) {
    transicionesPtr[i] = transiciones[i];
}

// Crear el autómata
tipoAutomata* automata = crearAutomata(alfabeto, 2, estados, 3, transicionesPtr,
                                       estadoInicial, estadosFinales, 1);

// Evaluar cadenas
boolean resultado1 = evaluarCadena(automata, "00");  // TRUE (q0→q1→q2)
boolean resultado2 = evaluarCadena(automata, "01");  // FALSE (q0→q0→q1)
boolean resultado3 = evaluarCadena(automata, "000"); // TRUE (q0→q1→q2→q2)

// Liberar memoria
destruirAutomata(automata);
```

### Características técnicas

- **Autómatas deterministas y no deterministas**: Soporte completo para ambos tipos de autómatas. Los autómatas no deterministas pueden tener transiciones faltantes (NULL o '\0').

- **Validación robusta**: Verificación de parámetros de entrada, consistencia entre dimensiones de matrices y existencia de estados referenciados.

- **Gestión de memoria**: Manejo automático de la memoria dinámica para strings y estructuras anidadas.

- **Evaluación de cadenas**: Procesamiento símbolo por símbolo con búsqueda de transiciones por nombre de estado.

- **Flexibilidad**: Los nombres de estados pueden ser cualquier string, no solo caracteres individuales.

Esta funcionalidad es esencial para aplicaciones de procesamiento de lenguajes, validación de patrones, compiladores, análisis léxico y cualquier sistema que requiera reconocimiento de cadenas según reglas específicas.

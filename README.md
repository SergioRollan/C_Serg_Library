# C_Serg_Library

BIBLIOTECA DE FUNCIONES DE C

AUTOR: SERGIO JUAN ROLLÁN MORALEJO

VERSIÓN NO: 2.1

FECHA DE FINALIZACIÓN: 13-07-2023

Objetivo de la biblioteca: reducir lo máximo posible el número de ".h" que se incluyan en todos los proyectos de C del usuario. Se incluirá en los códigos fuente escribiendo al principio del documento '#include "sergioteca.h"'

Importaciones que incluye: <stdio.h>, <stdlib.h>, <stdarg.h>, <string.h>, <unistd.h>, <ctype.h>, <math.h>, <time.h> y <limits.h>.

Sus aportaciones a la abstracción, legibilidad, portabilidad y comodidad del lenguaje C son:

- CAPÍTULO 1: INTRODUCCIÓN
- CAPÍTULO 2: ESTRUCTURAS DE DATOS BÁSICAS
- CAPÍTULO 3: FUNCIONES AUXILIARES Y UTILIDADES
- CAPÍTULO 4: LECTURA DE DATOS POR TECLADO
- CAPÍTULO 5: OPERACIONES CON VECTORES Y MATRICES
- CAPÍTULO 6: LISTAS ENLAZADAS
- CAPÍTULO 7: PILAS
- CAPÍTULO 8: COLAS
- CAPÍTULO 9: ÁRBOLES BINARIOS
- CAPÍTULO 10: MONTÍCULOS
- CAPÍTULO 11: GRAFOS
- CAPÍTULO 12: FUNCIONES MATEMÁTICAS Y COMBINATORIA
- CAPÍTULO 13: PLANIFICACIÓN DE PROCESOS
- CAPÍTULO 14: BÚSQUEDA EN VECTORES
- CAPÍTULO 15: ORDENACIÓN DE VECTORES
- CAPÍTULO 16: BARAJA DE CARTAS
- CAPÍTULO 17: LÍNEAS DE TRABAJO FUTURO

---

## ---------------- CAPÍTULO 1: CONSTANTES ÚTILES ----------------

- Para cambiar de línea o realizar un retorno de carro, el programador podrá despreocuparse de la secuencia de la función printf y de sus caracteres especiales y teclear "NUEVA_LINEA;" o "RETORNO_DE_CARRO;"
- Para reflejar éxito o fallo en la ejecución de una función computacionalmente costosa, el programador podrá utilizar las constantes "EXITO", "FALLO" y "SUPERFALLO".
- Para operar con cadenas de caracteres, el programador podrá dejar de necesitar el recuerdo de los punteros a char terminados en el carácter nullo y las operaciones de arimética que eso conlleva, utilizando el tipo "string" definido en esta biblioteca, acompañado de las operaciones de <string.h> que ya vienen incluidas, más las implementadas en ella que se mencionarán más adelante.
- Para declarar un vector o una matriz, podrá usarse "vector v" para un vector de enteros, "vectorf v" para un vector de variables de tipo float, "matriz m" para matrices de enteros y "matrizf m" para matrices de tipo float. También se verá una definición más ténica y útil para cálculos con matrices más adelante.

---

## ------------------ CAPÍTULO 2: TIPO BOOLEANO ------------------

- Podrán declararse variables de tipo "boolean", que podrán valer "TRUE" o "FALSE".
- Aunque TRUE y FALSE son macros que valen 1 y 0 respectivamente, se recomienda realizar comprobaciones con el operador '==' para aumentar la portabilidad. Por ejemplo, si se define una función "boolean funcion1();", con "return TRUE" y "return FALSE" dentro, y se utiliza en una sentencia condicional 'if', que sea en la forma "if(funcion1()==TRUE)", en lugar de solo "if(funcion1)".

---

## ------------- CAPÍTULO 3: FUNCIONES MISCELÁNEAS --------------

- La función "aproximar" recibe un float y ofrecerá el número entero más cercano a él. Esto sirve como contraste a la operación por defecto de C para pasar un float a un int, que es el truncado. Declaración: "int aproximar(float numero)". Más información en la documentación de la propia función.
- La función "aleatorioEntre2" generará un número real aleatorio entre dos dados, con una precisión a escoger. Declaración: "double aleatorioEntre2(double limiteInferior, double limiteSuperior, int cifrasDePrecision)". Si el límite inferior es mayor al superior, simplemente se intercambiarán. Más información en la documentación de la propia función.
- La función "enteroAleatorioConSigno" generará un número entero aleatorio entre dos dados, pudiendo ambos ser menores que cero (en aleatorioEntre2 también pueden ser menores que cero). Si el límite inferior es mayor al superior, simplemente se intercambiarán. Declaración: "int enteroAleatorioConSigno(int limiteInferior, int limiteSuperior)". Ambos límites estarán incluidos en las posibilidades del resultado. Más información en la documentación de la propia función.
- La función "aleatorioBinomial" genera un valor aleatorio según una distribución binomial B(n, p). Declaración: "int aleatorioBinomial(int n, double p)".
- La función "aleatorioNormal" genera un valor aleatorio según una distribución normal N(mu, sigma^2). Declaración: "double aleatorioNormal(double mu, double sigma)".
- La función "yesOrNo" es una función booleana que realizará una pregunta al usuario y solo admitirá por teclado una 'y' o una 'n' (mayúscula o minúscula). Devuelve "TRUE" si teclea 'y', "FALSE" si tecla una 'n'. Declaración: "boolean yesOrNo(string preguntaAImprimir)". La salida si se invoca "boolean opcion = yesOrNo("¿Estás seguro?");" Será, textualmente, "¿Estás seguro? (Y/N): |", siendo la última barra vertical el cursor de la consola. Más información en la documentación de la propia función.
- Las funciones "abrirFpBloq" "cerrarFpBloq" se encargan de realizar de forma atómica aperturas y cierres de ficheros de forma bloqueante. Además, por restricciones del propio lenguaje C para abrir ficheros bloqueados, también sirve como método de sincronización. Declaraciones: "FILE *abrirFpBloq(string ruta, string modo)" y "void cerrarFpBloq(FILE *fichero)". Más información en la documentación de la propia función.
- La función "descomponerFactoresPrimos" descompone un número en factores primos y los devuelve en un array. Declaración: "int descomponerFactoresPrimos(int n, int \*factores)".
- La función "descomponerPolinomioRuffini" descompone un polinomio en raíces enteras usando Ruffini y las devuelve en un array. Declaración: "int descomponerPolinomioRuffini(const int *coef, int grado, int *raices)".
- La función "mcd" calcula el máximo común divisor de dos números enteros usando el algoritmo de Euclides. Declaración: "int mcd(int a, int b)".
- La función "mcm" calcula el mínimo común múltiplo de dos números enteros. Declaración: "int mcm(int a, int b)".
- La función "mcd_descp" calcula el máximo común divisor usando la descomposición en factores primos. Declaración: "int mcd_descp(int a, int b)".
- La función "mcm_descp" calcula el mínimo común múltiplo usando la descomposición en factores primos. Declaración: "int mcm_descp(int a, int b)".
- La función "distanciaTecladoQWERTY" calcula la distancia entre dos letras en el teclado QWERTY, considerando la distancia vertical como 0.5 y la horizontal como 1. Declaración: "float distanciaTecladoQWERTY(char a, char b)".

---

## -------------- CAPÍTULO 4: LECTURA DE DATOS POR TECLADO --------------

### Lectura normal

- Podrá leerse cualquier tipo de dato entre 'int', 'float', 'double', 'long' y 'string' invocando a la función macro "leer".
- " int num = leer(num, "Introduce un número entero: ");"
- " float num = leer(num, "Introduce un número real de simple precisión: ");"
- "double num = leer(num, "Introduce un número entero largo: ");"
- " long num = leer(num, "Introduce un número real de doble precisión: ");"
- "string nom = leer(nom, "Introduce tu nombre: ", 10);", es un caso especial, porque requiere al final el número máximo de caracteres que admitirá la lectura.

### Lectura oculta (contraseñas)

La biblioteca también proporciona funciones para leer datos de la entrada estándar **sin mostrar los caracteres tecleados** (ideal para contraseñas o datos sensibles). Se usan igual que las funciones normales, pero con el prefijo `leerPassword` o el macro genérico `leerPassword`:

- `int secreto = leerPassword(0, "Introduce un número secreto: ");`
- `long lsecreto = leerPassword(0L, "Introduce un long secreto: ");`
- `float fsecreto = leerPassword(0.0f, "Introduce un float secreto: ");`
- `double dsecreto = leerPassword(0.0, "Introduce un double secreto: ");`
- `string pass = leerPassword(pass, "Introduce tu contraseña: ", 20);` (requiere el buffer y la longitud máxima, igual que leerString)

En el caso de strings, mientras se escribe se muestran asteriscos (`*`). Para los tipos numéricos, la entrada permanece completamente oculta.

---

## -------------- CAPÍTULO 5: IMPRIMIR DATOS POR CONSOLA --------------

- Podrá imprimirse cualquier tipo de dato entre 'int', 'float', 'double', 'long' y 'string' invocando a la función macro "print".
- " int num=7; print(num);"
- "long num=7; print(num);"
- " float num=7.0; print(num);"
- "double num=7.0; print(num);"
- "string s="hola"; print(s);"
- También existe "println", "printlnln", "printlnlnln" y todo lo mencionado en este capítulo con el prefijo "err" delante, que imprimirá la variable en el búfer de errores.
- Escribir "errprintlnlnln(num);" siendo 'num' una variable entera, es lo mismo que escribir "fprintf(stderr, "%d\n\n\n", num);"

---

## -------------- CAPÍTULO 6: OPERACIONES ÚTILES CON STRINGS --------------

- La función "todoMayusculas" convierte todos los caracteres de la 'a' a la 'z' que haya en un string a mayúsculas, lo estuvieran ya o no. Declaración: "string todoMayusculas(string cadenaParaConvertir)". Más información en la documentación de la propia función. Lo mismo para la función "todoMinusculas".
- La función "meterLetraEnCadena" es una operación simple de colocar un carácter al final de un string. Declaración: "int meterLetraEnCadena(string \*cadena, char caracterAlFinal)". Más información en la documentación de la propia función.
- La función "siguienteChar" constituye un iterador de cadenas de caracteres, útil cuando se quiere evaluar cada letra de un string por separado, por ejemplo, en procesamiento de tramas enviadas por red siguiendo un protocolo en el que el prefijo se divide en campos específicos de un par de caracteres a lo sumo. Se utiliza invocándolo con NULL cuando se quiere iterar. Por ejemplo, haciendo siguienteChar("hola"), obtendremos una 'h'. Después, haciendo siguienteChar(NULL), obtendremos una 'o', y así sucesivamente. Declaración: "char siguienteChar(string)". Más información en la documentación de la propia función.
- La función "substring" recibe una cadena de caracteres y un límite superior e inferior. Devuelve otro string cortado de forma que "string s = substring("Hola mundo", 3, 8);" valdrá "a mund". Si recibe números negativos o una cadena no válida, devolverá NULL. Declaración: "string substring(string cadenaParaCortar, int caracterComienzo, int caracterFinal)". Más información en la documentación de la propia función.
- La función "numaparicioneschar" cuenta el número de veces que aparece un carácter en una cadena. Declaración: "int numaparicioneschar(string cadenaParaRecorrer, char caracterParaBuscar)". Más información en la documentación de la propia función.
- La función "numaparicionessub" busca una cadena dentro de otra cadena. Es análoga a la anterior, pero sustituyendo el char por un segundo string. Declaración: "int numaparicionessub(string cadenaParaRecorrer, string cadenaParaBuscar)". Más información en la documentación de la propia función.
- La función "combinaciones" calcula combinaciones sin repetición C(n, m). Declaración: "long combinaciones(int n, int m)".
- La función "combinacionesConRepeticion" calcula combinaciones con repetición C'(n, m). Declaración: "long combinacionesConRepeticion(int n, int m)".
- La función "variaciones" calcula variaciones sin repetición V(n, m). Declaración: "long variaciones(int n, int m)".
- La función "variacionesConRepeticion" calcula variaciones con repetición V'(n, m). Declaración: "long variacionesConRepeticion(int n, int m)".
- La función "permutaciones" calcula permutaciones sin repetición P(n). Declaración: "long permutaciones(int n)".
- La función "permutacionesConRepeticion" calcula permutaciones con repetición P(n; m1, m2, ..., mk). Declaración: "long permutacionesConRepeticion(int n, const int \*ms, int k)".

---

## -------------- CAPÍTULO 7: OPERACIONES CON VECTORES Y MATRICES --------------

- Se definen operaciones para los tipo de dato "vector" y "vectorf" mencionados en el capítulo 1 de este manual. Son "leerVectorI/F", "imprimirVectorI/F", "productoEscalarI/F", "productoVectorialI/F" y "concatenarVectoresI/F".
- Declaraciones: "vector leerVectorI(int numeroElementos, string cadenaParaImprimir)","vectorf leerVectorF(int numeroElementos, string cadenaParaImprimir)", "void imprimirVectorI(vector imprimido, int numeroDeElementosQueTiene)", "void imprimirVectorF(vectorf imprimido, int numeroDeElementosQueTiene)", "int productoEscalarI(vector vector1, vector vector2, int numeroElementosQueTienen)", "float productoEscalarF(vectorf vector1, vectorf vector2, int numeroElementosQueTienen)", "vector productoVectorialI(vector vector1, vector vector2)", "vectorf productoVectorialF(vectorf vector1, vectorf vector2)", "vector concatenarVectoresI(vector vectorIzquierda, vector vectorDerecha, int numElementosPrimero, int numElementosSegundo)", "vectorf concatenarVectoresF(vectorf vectorIzquierda, vectorf vectorDerecha, int numElementosPrimero, int numElementosSegundo)". Más información en las documentaciones de las propias funciones.
- Se definen operaciones para los tipos de dato "matriz" y "matrizf" mencionados en el capítulo 1 de este manual. Son "leerMatrizI/F", "generarMatrizI/F", "imprimirMatrizI/F", "multiplicar/sumar/restarMatrI/F", "numPorMatrI/F", "determinanteI/F" y "concatenarMatricesEnHorizontal/VerticalI/F".
- Las declaraciones son iguales a las de vectores, pero con un argumento de tipo 'int' más ya que son dos dimensiones. Las excepciones son la de multiplicar, que recibe "int filasPrimeraMatriz, int columnasPrimeraTambienFilasSegunda, int columnasSegundaMatriz", la de concatenación horizontal, que recibe "int filasPrimeraTambienFilasSegunda, int columnasPrimeraMatriz, int columnasSegundaMatriz", y la concatenación vertical, que recibe "int filasPrimeraMatriz, int filasSegundaMatriz, int columnasPrimeraTambienColumnasSegunda". Son casos en los que siempre las variables agrupadas necesitan ser iguales para poder realizar la correspondiente operación. Por último, se añaden generarMatrizI/F, que reciben "int filas, int columnas, int/float limiteInferior, int/float limiteSuperior", y sirven para crear una matriz de tamaño fijo con información aleatoria entre dos umbrales. En generarMatrizF, además, habrá un último campo al final "int cifrasDePrecision". Más información en las documentaciones de las propias funciones.

---

## -------------- CAPÍTULO 8: OPERACIONES CON MATRICES OBJETO --------------

- Se define una estructura de datos especial llamada 'tipoMatriz', con su análoga 'tipoMatrizf' para números reales, que será muy útil para ayudar al programador a no tener que preocuparse en absoluto por los tamaños, siendo todos ellos manejados de forma subyacente por la API. Esta define todas las funciones comentadas en el capítulo anterior para matrices. Adoptarán los mismos nombres, con el sufijo "\_O" al final. Es decir:
- Para leer una matriz, "tipoMatriz[/f] leerMatriz[I/F]\_O(int filas, int columnas, string imprimir)"
- Para generar una matriz con celdas aleatorias, "tipoMatriz[/f] generarMatriz[I/F]\_O(int filas, int columnas, [int/float] limiteInferior, [int/float] limiteSuperior[/, int cifrasDePrecision])"
- Para imprimir una matriz por pantalla, "void imprimirMatriz[I/F]\_O(tipoMatriz[/f] matrizParaImprimir)"
- Para multiplicar matrices, "tipoMatriz[/f] multiplicarMatr[I/F]\_O(tipoMatriz[/f] matriz1, tipoMatriz[/f] matriz2)".
- Para sumar o restar matrices, "tipoMatriz[/f] [sumar/restar]Matr[I/F]\_O(tipoMatriz[/f] matriz1, tipoMatriz[/f] matriz2)".
- Para multiplicar una matriz por un escalar, "tipoMatriz[/f] numPorMatr[I/F]\_O([int/float] escalar, tipoMatriz[/f] matriz)".
- Para obtener el determinante de una matriz, "[int/float] determinante[I/F]\_O(tipoMatriz[/f] matriz)".
- Para concatenar matrices, "tipoMatriz[/f] concatenarMatricesEn[Horizontal/Vertical][I/F]\_O(tipoMatriz[/f] matriz1, tipoMatriz[/f] matriz2)".
- Más información en las documentaciones de las propias funciones.

---

## -------------- CAPÍTULO 9: OPERACIONES CON PILAS --------------

- Se define una estructura de datos especial llamada 'Pila'. Funcionará como un almacenamiento de datos de tipo LIFO.
- El tipo de dato que almacenará dependerá de lo que el usuario defina con la macro 'TIPO_INFO_PILAS'. Por ejemplo, "#define TIPO_INFO_PILAS float" hará que la estructura almacene números reales. Si no se realiza esta acción, el tipo por defecto será 'int'. Naturalmente, por restricciones del preprocesador de C, solo se podrá trabajar con un tipo de dato por programa.
  Ofrecerá las operaciones de inicializado "void pilaCreaVacia(Pila *pilaParaInicializar)", comprobación de tener algo de información "boolean pilaVacia (Pila *pilaParaVerSiTieneAlgo)", insertar un nuevo elemento en la pila "int pilaInserta(tipoElementoDeLaPila valorParaInsertar, Pila *pilaDondeSeInsertara)", sacar el elemento en la cima de la pila "tipoElementoDeLaPila pilaSuprime(Pila *pilaDeLaQueSeExtraera)", e imprimir la pila por consola "void pilaImprime (Pila pilaParaImprimir)".
- Más información en las documentaciones de las propias funciones.

---

## -------------- CAPÍTULO 10: OPERACIONES CON COLAS --------------

- Se define una estructura de datos especial llamada 'Cola'. Funcionará como un almacenamiento de datos de tipo FIFO.
- El tipo de dato que almacenará dependerá de lo que el usuario defina con la macro 'TIPO_INFO_COLAS'. Por ejemplo, "#define TIPO_INFO_COLAS float" hará que la estructura almacene números reales. Si no se realiza esta acción, el tipo por defecto será 'int'. Naturalmente, por restricciones del preprocesador de C, solo se podrá trabajar con un tipo de dato por programa.
  Ofrecerá las operaciones de inicializado "void colaCreaVacia(Cola *colaParaInicializar)", comprobación de tener algo de información "boolean colaVacia (Cola *colaParaVerSiTieneAlgo)", insertar un nuevo elemento en la cola "int colaInserta(tipoElementoDeLaCola valorParaInsertar, Cola *colaDondeSeInsertara)", sacar el elemento al comienzo de la cola "tipoElementoDeLaCola colaSuprime(Cola *colaDeLaQueSeExtraera)", e imprimir la cola por consola "void colaImprime (Cola colaParaImprimir)".
- Más información en las documentaciones de las propias funciones.

---

## -------------- CAPÍTULO 11: LISTAS ENLAZADAS CON ORIENTACION A OBJETOS --------------

- Se define una estructura de datos especial llamada 'tipoLista'. Funcionará como una lista enlazada de cualquier tipo de dato definido con unas operaciones definidas.
- Para este caso, como es muy común utilizar listas enlazadas con tipos de dato diferentes, se han definido cinco datos. Los tres primeros responden a las macros 'TIPO1_INFO_LISTA', 'TIPO2_INFO_LISTA' y 'TIPO3_INFO_LISTA', que por defecto serán 'int'. El cuarto será siempre 'int', y el último será siempre 'float'.
- Para declarar una lista, será necesario realizar las operaciones:
  tipoLista lista;
  inicializarTipoLista(&lista);
  colocarTipo[Info[/2/3]/Int/Float]EnLista(&lista);
- Una vez hecho hecho, se podrá utilizar la lista con los paradigmas de lenguajes orientados a objetos, con sus métodos y atributos.
- Atributos: 'vacia' (equivalente a cualquier 'isEmpty' de otros lenguajes), 'numElementos' (equivalente al 'length' de otros lenguajes) y 'lst' (la lista de nodos autorreferenciados propiamente dicha).
- Métodos:
  'annadirPPio' (ejemplo: "colocarTipoFloatEnLista(&lista); (lista.annadirPPio)(&lista, 9.5);") añadirá un 9.5 al principio de la lista de floats
  'annadirFin' (ejemplo: "(lista.annadirFin)(&lista, 9.5);") añadirá un 9.5 al final de la lista de floats
  'annadirEnLugar' (ejemplo: "(lista.annadirEnLugar)(&lista, 2, 9.5);") añadirá un 9.5 en el tercer lugar de la lista de floats, dejando 2 delante (si hay menos, simplemente lo añadirá al final),
  'mostrarLista' (ejemplo: "(lista.mostrarLista)(&lista)") imprimirá la lista por pantalla
  'borrarPpio' (ejemplo: "(lista.borrarPpio)(&lista)") borrará el primer miembro de la lista de floats.
  'borrarFin' (ejemplo: "(lista.borrarFin)(&lista)") borrará el último miembro de la lista de floats.
  'borrarElValor' (ejemplo: "(lista.borrarElValor)(&lista, 9.5)") borrará el '9.5' de la lista de floats. Si hubiera más de 1, solo borrará el que se encuentre primero de ellos.
  'modificarElValor' (ejemplo: "(lista.modificarElValor)(&lista, 9.5, 9.3)") sustituirá el primer 9.5 que encuentre por un 9.3 .
  'vaciarLaLista' (ejemplo: "(lista.vaciarLaLista)(&lista)") borrará todos los elementos de la lista de floats.

- Se define una estructura de datos especial llamada 'tipoListaSalto'. Es una lista circular doblemente enlazada de enteros, donde cada nodo, además de los enlaces clásicos (siguiente y anterior), dispone de enlaces de salto a posiciones 2, 4, 8, 16... nodos adelante, hasta menos de la mitad de la lista. Esto permite acceder a cualquier posición de la forma más rápida posible.
- Para declarar una lista de este tipo:
  tipoListaSalto lista;
  inicializarListaSalto(&lista);
- Una vez inicializada, se puede utilizar con los siguientes métodos (todos accesibles como punteros a función, igual que en la lista orientada a objetos):
  - 'annadirPpio' (ejemplo: "lista.annadirPpio(&lista, 5);") añade un 5 al principio de la lista.
  - 'annadirFin' (ejemplo: "lista.annadirFin(&lista, 10);") añade un 10 al final de la lista.
  - 'annadirEnLugar' (ejemplo: "lista.annadirEnLugar(&lista, 4, 99);") añade un 99 en la posición 4 (usando saltos para llegar más rápido).
  - 'mostrarLista' (ejemplo: "lista.mostrarLista(&lista)") imprime la lista por pantalla, mostrando también los saltos de cada nodo.
  - 'borrarPpio' (ejemplo: "lista.borrarPpio(&lista)") borra el primer nodo de la lista.
  - 'borrarFin' (ejemplo: "lista.borrarFin(&lista)") borra el último nodo de la lista.
  - 'borrarValor' (ejemplo: "lista.borrarValor(&lista, 99)") borra el primer nodo cuyo valor sea 99.
  - 'modificarValor' (ejemplo: "lista.modificarValor(&lista, 99, 77)") sustituye el primer 99 que encuentre por un 77.
  - 'vaciarLista' (ejemplo: "lista.vaciarLista(&lista)") borra todos los elementos de la lista.
- Cada operación recalcula automáticamente los saltos para mantener la eficiencia.
- Esta estructura es ideal para listas donde se requiera acceso rápido a posiciones arbitrarias, manteniendo la flexibilidad de una lista doblemente enlazada y la eficiencia de los saltos.

- Se define una estructura de datos especial llamada 'tipoListaSet'. Es una lista enlazada simple de enteros, sin nodo centinela y que no permite valores repetidos.
- Para declarar una lista de este tipo:
  tipoListaSet set;
  inicializarListaSet(&set);
- Una vez inicializada, se puede utilizar con los siguientes métodos (todos accesibles como punteros a función, igual que en las otras listas):
  - 'annadirPpio' (ejemplo: "set.annadirPpio(&set, 5);") añade un 5 al principio de la lista si no existe ya.
  - 'annadirFin' (ejemplo: "set.annadirFin(&set, 10);") añade un 10 al final de la lista si no existe ya.
  - 'annadirEnLugar' (ejemplo: "set.annadirEnLugar(&set, 3, 99);") añade un 99 en la posición 3 si no existe ya (si la posición es mayor que el tamaño, lo añade al final).
  - 'mostrarLista' (ejemplo: "set.mostrarLista(&set)") imprime la lista por pantalla.
  - 'borrarPpio' (ejemplo: "set.borrarPpio(&set)") borra el primer nodo de la lista.
  - 'borrarFin' (ejemplo: "set.borrarFin(&set)") borra el último nodo de la lista.
  - 'borrarValor' (ejemplo: "set.borrarValor(&set, 99)") borra el primer nodo cuyo valor sea 99.
  - 'vaciarLista' (ejemplo: "set.vaciarLista(&set)") borra todos los elementos de la lista.
- Cada operación garantiza que no se almacenan valores repetidos en la lista.
- Esta estructura es ideal para representar conjuntos (sets) de enteros, donde no se permiten duplicados y se requiere una gestión sencilla y eficiente.

---

## -------------- CAPÍTULO 12: OTRAS ESTRUCTURAS DE DATOS --------------

- Se define el tipo de dato 'Arbol', que almacenará una serie de datos en forma de árbol.
- Su tipo de dato se controlará con la macro TIPO_INFO_ARBOL.
- Ofrece las operaciones "Arbol creaArbol(tipoInfoArbol datoParaLaRaiz)", "void [pre/en/pos]Orden(Arbol arbolParaRecorrer)", "void amplitudArbol(Arbol arbolParaRecorrer)", "int altura(Arbol nodoParaEvaluar)", "int numNodos[/Hoja/Internos](Arbol arbolParaRecorrer)", "int sustituye(Arbol raiz, tipoInfoArbol x, tipoInfoArbol y)", "int numHijoUnico(Arbol arbolParaEvaluar)", "Arbol buscar[Max/Min](Arbol arbolParaBuscar)", "boolean [similares/equivalentes](Arbol arbol1, Arbol arbol2)" y "Arbol especular(Arbol arbolParaEspecularizar)".
- Se define el tipo de dato 'Monticulo', que funcionará como un árbol binario ordenado.
- Su comportamiento será controlado por tres macros. 'NUM_ELEMS_MONT' controlará el número máximo de elementos que podrá tener un montículo (por defecto será 100), y la información será accesible a través de una clave y un valor, dos campos cuyos datos se definirán con las macros TIPO_CLAVE_MONT y TIPO_INFO_MONT (por defecto serán ambos 'int').
- Ofrece las operaciones '[crear/iniciar/vaciar]Monticulo(Monticulo *m)', 'filtrado[Ascendente/Descendente](Monticulo *m, int valorParaFiltrar)', 'insertar', 'eliminarMinimo', '[decrementar/incrementar]Clave' y la booleana 'esMonticulo'.
- Por último, se define el tipo de dato 'tipoGrafo', que almacenará un número límite de nodos controlado por la macro 'NUM_ELEMS_GRAFO', que por defecto será 20.
- Tendrá operaciones 'iniciarGrafo', 'profundidad', 'amplitud', 'ordenTop', 'caminos', 'djikstra', 'costeyTrayectoria', 'todosCaminosMin', 'buscarVertices'.
- Existirá una función extra "void construirMonticuloDeAristas(tipoGrafo *grafo, Monticulo *m)" que construirá un montículo a partir de un grafo.

---

## -------------- CAPÍTULO 13: ALGORITMOS DE PLANIFICACIÓN DE PROCESOS --------------

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

- **Prioridades:**

  - Cada proceso tiene una prioridad; se atienden primero los de mayor prioridad.
  - Puede ser con o sin desalojo.
  - Riesgo de inanición para procesos de baja prioridad.

- **Multinivel y Multinivel con retroalimentación:**

  - Existen varias colas con diferentes prioridades o algoritmos.
  - Los procesos pueden cambiar de cola según su comportamiento (retroalimentación).
  - Permite adaptar el sistema a diferentes tipos de procesos (interactivos, por lotes, etc.).

- **Planificación por lotes, planificación en tiempo real, planificación garantizada, etc.:**
  - Existen otros algoritmos adaptados a necesidades específicas, como sistemas en tiempo real o sistemas con garantías de servicio.

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

Todas las funciones de búsqueda de la biblioteca devuelven la posición del elemento encontrado o -1 si no está o si ocurre algún fallo de programación defensiva (por ejemplo, vector no ordenado cuando es necesario).

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

## -------------- CAPÍTULO 19: CÓDIGOS CORRECTORES DE ERRORES --------------

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

## -------------- CAPÍTULO 21: LÍNEAS DE TRABAJO FUTURO --------------

- Máquinas de Turing.
- Autómatas finitos, tanto deterministas como no deterministas.
- Gramáticas

# C_Serg_Library

BIBLIOTECA DE FUNCIONES DE C, MANUAL

AUTOR: SERGIO JUAN ROLLÁN MORALEJO

VERSIÓN NO: 1.0   

FECHA DE FINALIZACIÓN: 03-07-2023 


Objetivo de la biblioteca: reducir lo máximo posible el número de ".h" que se incluyan en todos los proyectos de C del usuario. Se incluirá en los códigos fuente escribiendo al principio del documento '#include "sergioteca.h"'

Importaciones que incluye: <stdio.h>, <stdlib.h>, <stdarg.h>, <string.h>, <unistd.h>, <ctype.h>, <math.h>, <time.h>, <limits.h>, <sys/file.h> y <sys/types.h> 

Sus aportaciones a la abstracción, legibilidad, portabilidad y comodidad del lenguaje C son:

- CAPÍTULO 1: CONSTANTES ÚTILES 
- CAPÍTULO 2: TIPO BOOLEANO
- CAPÍTULO 3: FUNCIONES MISCELÁNEAS
- CAPÍTULO 4: LECTURA DE DATOS POR TECLADO
- CAPÍTULO 5: IMPRIMIR DATOS POR CONSOLA
- CAPÍTULO 6: OPERACIONES ÚTILES CON STRINGS
- CAPÍTULO 7: OPERACIONES CON VECTORES Y MATRICES
- CAPÍTULO 8: OPERACIONES CON LA ESTRUCTURA DE DATOS MATRIZ OBJETO
- CAPÍTULO 9: OPERACIONES CON PILAS
- CAPÍTULO 10: OPERACIONES CON COLAS
- CAPÍTULO 11: OPERACIONES CON LISTAS ENLAZADAS CON ORIENTACION A OBJETOS
- CAPÍTULO 12: OTRAS ESTRUCTURAS DE DATOS
- CAPÍTULO 13: LÍNEAS DE TRABAJO FUTURO
- CAPÍTULO 14: IDEAS PARA OTRAS VERSIONES




















-------------------------------------------------------------------------------------------------------------------
---------------- CAPÍTULO 1: CONSTANTES ÚTILES ----------------
---------------------------------------------------------------

* Para cambiar de línea o realizar un retorno de carro, el programador podrá despreocuparse de la secuencia de la función printf y de sus caracteres especiales y teclear "NUEVA_LINEA;" o "RETORNO_DE_CARRO;"
* Para reflejar éxito o fallo en la ejecución de una función computacionalmente costosa, el programador podrá utilizar las constantes "EXITO", "FALLO" y "SUPERFALLO".
* Para operar con cadenas de caracteres, el programador podrá dejar de necesitar el recuerdo de los punteros a char terminados en el carácter nullo y las operaciones de arimética que eso conlleva, utilizando el tipo "string" definido en esta biblioteca, acompañado de las operaciones de <string.h> que ya vienen incluidas, más las implementadas en ella que se mencionarán más adelante.
* Para declarar un vector o una matriz, podrá usarse "vector v" para un vector de enteros, "vectorf v" para un vector de variables de tipo float, "matriz m" para matrices de enteros y "matrizf m" para matrices de tipo float. También se verá una definición más ténica y útil para cálculos con matrices más adelante.




-------------------------------------------------------------------------------------------------------------------
------------------ CAPÍTULO 2: TIPO BOOLEANO ------------------
---------------------------------------------------------------

* Podrán declararse variables de tipo "boolean", que podrán valer "TRUE" o "FALSE".
* Aunque TRUE y FALSE son macros que valen 1 y 0 respectivamente, se recomienda realizar comprobaciones con el operador '==' para aumentar la portabilidad. Por ejemplo, si se define una función "boolean funcion1();", con "return TRUE" y "return FALSE" dentro, y se utiliza en una sentencia condicional 'if', que sea en la forma "if(funcion1()==TRUE)", en lugar de solo "if(funcion1)".




-------------------------------------------------------------------------------------------------------------------
------------- CAPÍTULO 3: FUNCIONES MISCELÁNEAS  --------------
---------------------------------------------------------------

* La función "aproximar" recibe un float y ofrecerá el número entero más cercano a él. Esto sirve como contraste a la operación por defecto de C para pasar un float a un int, que es el truncado. Declaración: "int aproximar(float numero)". Más información en la documentación de la propia función.
* La función "aleatorioEntre2" generará un número real aleatorio entre dos dados, con una precisión a escoger. Declaración: "double aleatorioEntre2(double limiteInferior, double limiteSuperior, int cifrasDePrecision)". Si el límite inferior es mayor al superior, simplemente se intercambiarán. Más información en la documentación de la propia función.
* La función "enteroAleatorioConSigno" generará un número entero aleatorio entre dos dados, pudiendo ambos ser menores que cero (en aleatorioEntre2 también pueden ser menores que cero). Si el límite inferior es mayor al superior, simplemente se intercambiarán. Declaración: "int enteroAleatorioConSigno(int limiteInferior, int limiteSuperior)". Ambos límites estarán incluidos en las posibilidades del resultado. Más información en la documentación de la propia función.
* La función "yesOrNo" es una función booleana que realizará una pregunta al usuario y solo admitirá por teclado una 'y' o una 'n' (mayúscula o minúscula). Devuelve "TRUE" si teclea 'y', "FALSE" si tecla una 'n'. Declaración: "boolean yesOrNo(string preguntaAImprimir)". La salida si se invoca "boolean opcion = yesOrNo("¿Estás seguro?");" Será, textualmente, "¿Estás seguro? (Y/N): |", siendo la última barra vertical el cursor de la consola. Más información en la documentación de la propia función.
* Las funciones "abrirFpBloq" "cerrarFpBloq" se encargan de realizar de forma atómica aperturas y cierres de ficheros de forma bloqueante. Además, por restricciones del propio lenguaje C para abrir ficheros bloqueados, también sirve como método de sincronización. Declaraciones: "FILE *abrirFpBloq(string ruta, string modo)" y "void cerrarFpBloq(FILE *fichero)". Más información en la documentación de la propia función.




-------------------------------------------------------------------------------------------------------------------
-------------- CAPÍTULO 4: LECTURA DE DATOS POR TECLADO --------------
---------------------------------------------------------------

* Podrá leerse cualquier tipo de dato entre 'int', 'float', 'double', 'long' y 'string' invocando a la función macro "leer".
* "   int num = leer(num, "Introduce un número entero: ");"
* " float num = leer(num, "Introduce un número real de simple precisión: ");"
* "double num = leer(num, "Introduce un número entero largo: ");"
* "  long num = leer(num, "Introduce un número real de doble precisión: ");"
* "string nom = leer(nom, "Introduce tu nombre: ", 10);", es un caso especial, porque requiere al final el número máximo de caracteres que admitirá la lectura.




-------------------------------------------------------------------------------------------------------------------
-------------- CAPÍTULO 5: IMPRIMIR DATOS POR CONSOLA --------------
---------------------------------------------------------------

* Podrá imprimirse cualquier tipo de dato entre 'int', 'float', 'double', 'long' y 'string' invocando a la función macro "print".
* " int num=7; print(num);"
* "long num=7; print(num);"
* " float num=7.0; print(num);"
* "double num=7.0; print(num);"
* "string s="hola"; print(s);"
* También existe "println", "printlnln", "printlnlnln" y todo lo mencionado en este capítulo con el prefijo "err" delante, que imprimirá la variable en el búfer de errores.
* Escribir "errprintlnlnln(num);" siendo 'num' una variable entera, es lo mismo que escribir "fprintf(stderr, "%d\n\n\n", num);"




-------------------------------------------------------------------------------------------------------------------
-------------- CAPÍTULO 6: OPERACIONES ÚTILES CON STRINGS --------------
---------------------------------------------------------------

* La función "todoMayusculas" convierte todos los caracteres de la 'a' a la 'z' que haya en un string a mayúsculas, lo estuvieran ya o no. Declaración: "string todoMayusculas(string cadenaParaConvertir)". Más información en la documentación de la propia función. Lo mismo para la función "todoMinusculas".
* La función "meterLetraEnCadena" es una operación simple de colocar un carácter al final de un string. Declaración: "int meterLetraEnCadena(string *cadena, char caracterAlFinal)". Más información en la documentación de la propia función.
* La función "siguienteChar" constituye un iterador de cadenas de caracteres, útil cuando se quiere evaluar cada letra de un string por separado, por ejemplo, en procesamiento de tramas enviadas por red siguiendo un protocolo en el que el prefijo se divide en campos específicos de un par de caracteres a lo sumo. Se utiliza invocándolo con NULL cuando se quiere iterar. Por ejemplo, haciendo siguienteChar("hola"), obtendremos una 'h'. Después, haciendo siguienteChar(NULL), obtendremos una 'o', y así sucesivamente. Declaración: "char siguienteChar(string)". Más información en la documentación de la propia función.
* La función "substring" recibe una cadena de caracteres y un límite superior e inferior. Devuelve otro string cortado de forma que "string s = substring("Hola mundo", 3, 8);" valdrá "a mund". Si recibe números negativos o una cadena no válida, devolverá NULL. Declaración: "string substring(string cadenaParaCortar, int caracterComienzo, int caracterFinal)". Más información en la documentación de la propia función.
* La función "numaparicioneschar" cuenta el número de veces que aparece un carácter en una cadena. Declaración: "int numaparicioneschar(string cadenaParaRecorrer, char caracterParaBuscar)". Más información en la documentación de la propia función.
* La función "numaparicionessub" busca una cadena dentro de otra cadena. Es análoga a la anterior, pero sustituyendo el char por un segundo string. Declaración: "int numaparicionessub(string cadenaParaRecorrer, string cadenaParaBuscar)". Más información en la documentación de la propia función.




-------------------------------------------------------------------------------------------------------------------
-------------- CAPÍTULO 7: OPERACIONES CON VECTORES Y MATRICES --------------
---------------------------------------------------------------

* Se definen operaciones para los tipo de dato "vector" y "vectorf" mencionados en el capítulo 1 de este manual. Son "leerVectorI/F", "imprimirVectorI/F", "productoEscalarI/F", "productoVectorialI/F" y "concatenarVectoresI/F".
* Declaraciones: "vector leerVectorI(int numeroElementos, string cadenaParaImprimir)","vectorf leerVectorF(int numeroElementos, string cadenaParaImprimir)", "void imprimirVectorI(vector imprimido, int numeroDeElementosQueTiene)", "void imprimirVectorF(vectorf imprimido, int numeroDeElementosQueTiene)", "int productoEscalarI(vector vector1,  vector vector2, int numeroElementosQueTienen)", "float productoEscalarF(vectorf vector1, vectorf vector2, int numeroElementosQueTienen)", "vector productoVectorialI(vector vector1,  vector vector2)", "vectorf productoVectorialF(vectorf vector1,  vectorf vector2)", "vector concatenarVectoresI(vector vectorIzquierda, vector vectorDerecha, int numElementosPrimero, int numElementosSegundo)", "vectorf concatenarVectoresF(vectorf vectorIzquierda, vectorf vectorDerecha, int numElementosPrimero, int numElementosSegundo)". Más información en las documentaciones de las propias funciones.
* Se definen operaciones para los tipos de dato "matriz" y "matrizf" mencionados en el capítulo 1 de este manual. Son "leerMatrizI/F", "generarMatrizI/F", "imprimirMatrizI/F", "multiplicar/sumar/restarMatrI/F", "numPorMatrI/F", "determinanteI/F" y "concatenarMatricesEnHorizontal/VerticalI/F".
* Las declaraciones son iguales a las de vectores, pero con un argumento de tipo 'int' más ya que son dos dimensiones. Las excepciones son la de multiplicar, que recibe "int filasPrimeraMatriz, int columnasPrimeraTambienFilasSegunda, int columnasSegundaMatriz", la de concatenación horizontal, que recibe "int filasPrimeraTambienFilasSegunda, int columnasPrimeraMatriz, int columnasSegundaMatriz", y la concatenación vertical, que recibe "int filasPrimeraMatriz, int filasSegundaMatriz, int columnasPrimeraTambienColumnasSegunda". Son casos en los que siempre las variables agrupadas necesitan ser iguales para poder realizar la correspondiente operación. Por último, se añaden generarMatrizI/F, que reciben "int filas, int columnas, int/float limiteInferior, int/float limiteSuperior", y sirven para crear una matriz de tamaño fijo con información aleatoria entre dos umbrales. En generarMatrizF, además, habrá un último campo al final "int cifrasDePrecision". Más información en las documentaciones de las propias funciones.




-------------------------------------------------------------------------------------------------------------------
-------------- CAPÍTULO 8: OPERACIONES CON MATRICES OBJETO --------------
---------------------------------------------------------------

* Se define una estructura de datos especial llamada 'tipoMatriz', con su análoga 'tipoMatrizf' para números reales, que será muy útil para ayudar al programador a no tener que preocuparse en absoluto por los tamaños, siendo todos ellos manejados de forma subyacente por la API. Esta define todas las funciones comentadas en el capítulo anterior para matrices. Adoptarán los mismos nombres, con el sufijo "_O" al final. Es decir:
* Para leer una matriz, "tipoMatriz[/f] leerMatriz[I/F]_O(int filas, int columnas, string imprimir)"
* Para generar una matriz con celdas aleatorias, "tipoMatriz[/f] generarMatriz[I/F]_O(int filas, int columnas, [int/float] limiteInferior, [int/float] limiteSuperior[/, int cifrasDePrecision])"
* Para imprimir una matriz por pantalla, "void imprimirMatriz[I/F]_O(tipoMatriz[/f] matrizParaImprimir)"
* Para multiplicar matrices, "tipoMatriz[/f] multiplicarMatr[I/F]_O(tipoMatriz[/f] matriz1, tipoMatriz[/f] matriz2)".
* Para sumar o restar matrices, "tipoMatriz[/f] [sumar/restar]Matr[I/F]_O(tipoMatriz[/f] matriz1, tipoMatriz[/f] matriz2)".
* Para multiplicar una matriz por un escalar, "tipoMatriz[/f] numPorMatr[I/F]_O([int/float] escalar, tipoMatriz[/f] matriz)".
* Para obtener el determinante de una matriz, "[int/float] determinante[I/F]_O(tipoMatriz[/f] matriz)".
* Para concatenar matrices, "tipoMatriz[/f] concatenarMatricesEn[Horizontal/Vertical][I/F]_O(tipoMatriz[/f] matriz1, tipoMatriz[/f] matriz2)".
* Más información en las documentaciones de las propias funciones.




-------------------------------------------------------------------------------------------------------------------
-------------- CAPÍTULO 9: OPERACIONES CON PILAS --------------
---------------------------------------------------------------

* Se define una estructura de datos especial llamada 'Pila'. Funcionará como un almacenamiento de datos de tipo LIFO. 
* El tipo de dato que almacenará dependerá de lo que el usuario defina con la macro 'TIPO_INFO_PILAS'. Por ejemplo, "#define TIPO_INFO_PILAS float" hará que la estructura almacene números reales. Si no se realiza esta acción, el tipo por defecto será 'int'. Naturalmente, por restricciones del preprocesador de C, solo se podrá trabajar con un tipo de dato por programa.
Ofrecerá las operaciones de inicializado "void pilaCreaVacia(Pila *pilaParaInicializar)", comprobación de tener algo de información "boolean pilaVacia (Pila *pilaParaVerSiTieneAlgo)", insertar un nuevo elemento en la pila "int pilaInserta(tipoElementoDeLaPila valorParaInsertar, Pila *pilaDondeSeInsertara)", sacar el elemento en la cima de la pila "tipoElementoDeLaPila pilaSuprime(Pila *pilaDeLaQueSeExtraera)", e imprimir la pila por consola "void pilaImprime (Pila pilaParaImprimir)".
* Más información en las documentaciones de las propias funciones.




-------------------------------------------------------------------------------------------------------------------
-------------- CAPÍTULO 10: OPERACIONES CON COLAS --------------
---------------------------------------------------------------

* Se define una estructura de datos especial llamada 'Cola'. Funcionará como un almacenamiento de datos de tipo FIFO. 
* El tipo de dato que almacenará dependerá de lo que el usuario defina con la macro 'TIPO_INFO_COLAS'. Por ejemplo, "#define TIPO_INFO_COLAS float" hará que la estructura almacene números reales. Si no se realiza esta acción, el tipo por defecto será 'int'. Naturalmente, por restricciones del preprocesador de C, solo se podrá trabajar con un tipo de dato por programa.
Ofrecerá las operaciones de inicializado "void colaCreaVacia(Cola *colaParaInicializar)", comprobación de tener algo de información "boolean colaVacia (Cola *colaParaVerSiTieneAlgo)", insertar un nuevo elemento en la cola "int colaInserta(tipoElementoDeLaCola valorParaInsertar, Cola *colaDondeSeInsertara)", sacar el elemento al comienzo de la cola "tipoElementoDeLaCola colaSuprime(Cola *colaDeLaQueSeExtraera)", e imprimir la cola por consola "void colaImprime (Cola colaParaImprimir)".
* Más información en las documentaciones de las propias funciones.




-------------------------------------------------------------------------------------------------------------------
-------------- CAPÍTULO 11: LISTAS ENLAZADAS CON ORIENTACION A OBJETOS --------------
---------------------------------------------------------------

* Se define una estructura de datos especial llamada 'tipoLista'. Funcionará como una lista enlazada de cualquier tipo de dato definido con unas operaciones definidas.
* Para este caso, como es muy común utilizar listas enlazadas con tipos de dato diferentes, se han definido cinco datos. Los tres primeros responden a las macros 'TIPO1_INFO_LISTA', 'TIPO2_INFO_LISTA' y 'TIPO3_INFO_LISTA', que por defecto serán 'int'. El cuarto será siempre 'int', y el último será siempre 'float'.
* Para declarar una lista, será necesario realizar las operaciones:
	tipoLista lista;
	inicializarTipoLista(&lista);
	colocarTipo[Info[/2/3]/Int/Float]EnLista(&lista);
* Una vez hecho hecho, se podrá utilizar la lista con los paradigmas de lenguajes orientados a objetos, con sus métodos y atributos.
* Atributos: 'vacia' (equivalente a cualquier 'isEmpty' de otros lenguajes), 'numElementos' (equivalente al 'length' de otros lenguajes) y 'lst' (la lista de nodos autorreferenciados propiamente dicha).
* Métodos: 
	'annadirPPio' (ejemplo: "colocarTipoFloatEnLista(&lista); (lista.annadirPPio)(&lista, 9.5);") añadirá un 9.5 al principio de la lista de floats
	'annadirFin' (ejemplo: "(lista.annadirFin)(&lista, 9.5);") añadirá un 9.5 al final de la lista de floats
	'annadirEnLugar' (ejemplo: "(lista.annadirEnLugar)(&lista, 2, 9.5);") añadirá un 9.5 en el tercer lugar de la lista de floats, dejando 2 delante (si hay menos, simplemente lo añadirá al final),
	'mostrarLista' (ejemplo: "(lista.mostrarLista)(&lista)") imprimirá la lista por pantalla
	'borrarPpio' (ejemplo: "(lista.borrarPpio)(&lista)") borrará el primer miembro de la lista de floats.
	'borrarFin' (ejemplo: "(lista.borrarFin)(&lista)") borrará el último miembro de la lista de floats.
	'borrarElValor' (ejemplo: "(lista.borrarElValor)(&lista, 9.5)") borrará el '9.5' de la lista de floats. Si hubiera más de 1, solo borrará el que se encuentre primero de ellos.
	'modificarElValor' (ejemplo: "(lista.modificarElValor)(&lista, 9.5, 9.3)") sustituirá el primer 9.5 que encuentre por un 9.3 .
	'vaciarLaLista' (ejemplo: "(lista.vaciarLaLista)(&lista)") borrará todos los elementos de la lista de floats.




-------------------------------------------------------------------------------------------------------------------
-------------- CAPÍTULO 12: OTRAS ESTRUCTURAS DE DATOS --------------
---------------------------------------------------------------

* Se define el tipo de dato 'Arbol', que almacenará una serie de datos en forma de árbol. 
* Su tipo de dato se controlará con la macro TIPO_INFO_ARBOL. 
* Ofrece las operaciones "Arbol creaArbol(tipoInfoArbol datoParaLaRaiz)", "void [pre/en/pos]Orden(Arbol arbolParaRecorrer)", "void amplitudArbol(Arbol arbolParaRecorrer)", "int altura(Arbol nodoParaEvaluar)", "int numNodos[/Hoja/Internos](Arbol arbolParaRecorrer)", "int sustituye(Arbol raiz, tipoInfoArbol x, tipoInfoArbol y)", "int numHijoUnico(Arbol arbolParaEvaluar)", "Arbol buscar[Max/Min](Arbol arbolParaBuscar)", "boolean [similares/equivalentes](Arbol arbol1, Arbol arbol2)" y "Arbol especular(Arbol arbolParaEspecularizar)".
* Se define el tipo de dato 'Monticulo', que funcionará como un árbol binario ordenado.
* Su comportamiento será controlado por tres macros. 'NUM_ELEMS_MONT' controlará el número máximo de elementos que podrá tener un montículo (por defecto será 100), y la información será accesible a través de una clave y un valor, dos campos cuyos datos se definirán con las macros TIPO_CLAVE_MONT y TIPO_INFO_MONT (por defecto serán ambos 'int').
* Ofrece las operaciones  '[crear/iniciar/vaciar]Monticulo(Monticulo *m)', 'filtrado[Ascendente/Descendente](Monticulo *m, int valorParaFiltrar)', 'insertar', 'eliminarMinimo', '[decrementar/incrementar]Clave' y la booleana 'esMonticulo'.
* Por último, se define el tipo de dato 'tipoGrafo', que almacenará un número límite de nodos controlado por la macro 'NUM_ELEMS_GRAFO', que por defecto será 20.
* Tendrá operaciones 'iniciarGrafo', 'profundidad', 'amplitud', 'ordenTop', 'caminos', 'djikstra', 'costeyTrayectoria', 'todosCaminosMin', 'buscarVertices'.
* Existirá una función extra "void construirMonticuloDeAristas(tipoGrafo *grafo, Monticulo *m)" que construirá un montículo a partir de un grafo.




-------------------------------------------------------------------------------------------------------------------
-------------- CAPÍTULO 13: LÍNEAS DE TRABAJO FUTURO --------------
---------------------------------------------------------------

* Corregir errores menores y realizar más pruebas de depuración y de caminos.
* Quedará pendiente documentar las funciones de las estructuras de datos del capítulo 12.
* Han quedado definidas, pero sin implementar, las estructuras de datos 'hiperplano' y 'codigo'. En futuras versiones, podrán utilizarse para realizar operaciones geométricas con objetos de cualquier dimensión (pues los vectores se limitan a una y las matrices a dos) y operaciones de aplicación de la teoría de códigos correctores de errores.




-------------------------------------------------------------------------------------------------------------------
-------------- CAPÍTULO 14: IDEAS PARA FUTURAS VERSIONES --------------
---------------------------------------------------------------

* Una función que permita hacer una pausa, tipo 'pause("Pulsa intro para continuar...");', que no dependa del sistema operativo.
* Añadir métodos de ordenación a las listas enlazadas.
* Añadir a las opciones de lectura una que reciba un array de opciones (sirva de expansión al "Y/N" de la función yesOrNo).
* También añadir versiones de contraseña 'leerPassword', también polimórfica para int, string, etc.
* Ya de paso, también implementar algoritmos de ordenación de forma general. 
* Implementar otros interfaces, como Set, LinkedList, SortedLists, Maps, TreeMaps...
* Funciones criptográficas.
* Operaciones con ficheros de texto y ficheros binarios.
* Importación de librerías multicomputador como MPI.
* Permitir delegar la ejecución de una función en particular a otro proceso.
* Funciones de exclusión mutua y acceso a recursos.
* Acceso seguro a un array, que haga que si uno escribe "lista[10]" en una lista de tamaño 8, devuelva "lista[7]" e igual con el límite inferior, y funciones similares.





















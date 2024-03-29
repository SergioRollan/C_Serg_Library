/*****************************************************************************************************************/
/*****************************************************************************************************************/
/********************************** BIBLIOTECA DE FUNCIONES DE C, DECLARACIONES **********************************/
/************************************** AUTOR: SERGIO JUAN ROLLÁN MORALEJO ***************************************/
/*****************************************       VERSIÓN NO: 1.0       *******************************************/
/************************************** FECHA DE FINALIZACIÓN: 03-07-2022 ****************************************/
/*****************************************************************************************************************/
/*****************************************************************************************************************/






/*************************************preprocesador**************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#include <conio.h>
#include <termios.h>
#include <sys/file.h>
#include <sys/types.h>


#define EXITO 0
#define FALLO -1
#define SUPERFALLO -2
#define TRUE 1
#define FALSE 0
#define NUEVA_LINEA puts("")
#define RETORNO_DE_CARRO printf("\r")
















/*****************************************typedefs*******************************************/




//////////////////////////////////////////////// extras
typedef char boolean;
typedef char* string;
typedef int* vector;
typedef vector* matriz;
typedef float* vectorf;
typedef vectorf* matrizf;


//////////////////////////////////////////////// arboles
#ifndef TIPO_INFO_ARBOL
  #define TIPO_INFO_ARBOL char
#endif
typedef TIPO_INFO_ARBOL tipoInfoArbol;
typedef struct tipoNodo
{
	tipoInfoArbol info;
	struct tipoNodo *izq,*der;
} tipoNodo;
typedef tipoNodo *Arbol;


//////////////////////////////////////////////// monticulos

#ifndef NUM_ELEMS_MONT
  #define NUM_ELEMS_MONT 100
#endif
#ifndef TIPO_CLAVE_MONT
  #define TIPO_CLAVE_MONT int
#endif
#ifndef TIPO_INFO_MONT
  #define TIPO_INFO_MONT int
#endif
typedef TIPO_CLAVE_MONT tipoClaveMonticulo;
typedef TIPO_INFO_MONT tipoInfoMonticulo;
typedef struct
{
	tipoClaveMonticulo clave;
	tipoInfoMonticulo  informacion;
}tipoElementoMonticulo;
typedef struct
{
	tipoElementoMonticulo elemento[NUM_ELEMS_MONT];
	int tam;
}Monticulo;


//////////////////////////////////////////////// grafos
#ifndef NUM_ELEMS_GRAFO
  #define NUM_ELEMS_GRAFO 20
#endif
#define INF 9999999
typedef struct tagarco
{ 
    int v;
    int peso;
    struct tagarco *sig;
}arco;
typedef struct
{ 
    int alcanzado;
    int gradoEntrada;
    int ordenTop;
    int distancia;
    int peso;
    int anterior;
    arco *lista;
}vertices;
typedef struct 
{
	vertices directorio[NUM_ELEMS_GRAFO];
	int orden;
}tipoGrafo;


//////////////////////////////////////////////// lista enlazada
#ifndef TIPO1_INFO_LISTA
    #define TIPO1_INFO_LISTA int
#endif
#ifndef TIPO2_INFO_LISTA
    #define TIPO2_INFO_LISTA int
#endif
#ifndef TIPO3_INFO_LISTA
    #define TIPO3_INFO_LISTA int
#endif
typedef TIPO1_INFO_LISTA tipoInfo;
typedef TIPO2_INFO_LISTA tipoInfo2;
typedef TIPO3_INFO_LISTA tipoInfo3;
typedef struct n
{
        tipoInfo info;
		tipoInfo2 info2;
		tipoInfo3 info3;
		int info4;
		float info5;
        struct n *sig;
}nodo;
typedef nodo* lista;
typedef struct s
{
	lista lst;
	int numElementos;
	boolean vacia;
	int (*annadirPPio)(struct s*, ...);
	int (*annadirFin)(struct s*, ...);
	int (*annadirEnLugar)(struct s*, int, ...);
	void (*mostrarLista)(struct s*);
	int (*borrarPpio)(struct s*);
	int (*borrarFin)(struct s*);
	int (*borrarElValor)(struct s*, ...);
	int (*modificarElValor)(struct s*, ...);
	int (*vaciarLaLista)(struct s*);
}tipoLista;
////////////////////////////////////////////////


//////////////////////////////////////////////// pilas
#ifndef TIPO_INFO_PILAS
  #define TIPO_INFO_PILAS int
#endif
typedef TIPO_INFO_PILAS tipoElementoP;
typedef struct tipoCeldaP
{
	tipoElementoP elemento;
	struct tipoCeldaP *sig;
} tipoCeldaP;
typedef tipoCeldaP* Pila;
////////////////////////////////////////////////


//////////////////////////////////////////////// colas
#ifndef TIPO_INFO_COLAS
  #define TIPO_INFO_COLAS int
#endif
typedef TIPO_INFO_COLAS tipoElementoC;
typedef struct tipoCeldaC
{
	tipoElementoC elemento;
	struct tipoCeldaC *sig;
} tipoCeldaC;
typedef struct {tipoCeldaC *frente; tipoCeldaC *fondo;} Cola;
////////////////////////////////////////////////


//////////////////////////////////////////////// colasDeArbol
typedef tipoNodo* tipoElementoCDA;
typedef struct tipoCeldaCDA
{
	tipoElementoCDA elemento;
	struct tipoCeldaCDA *sig;
} tipoCeldaCDA;
typedef struct {tipoCeldaCDA *frente; tipoCeldaCDA *fondo;} ColaArbol;
////////////////////////////////////////////////


//////////////////////////////////////////////// matrices objeto
typedef struct{
	matriz matrix;
	int filas;
	int columnas;
}tipoMatriz;
typedef struct{
	matrizf matrix;
	int filas;
	int columnas;
}tipoMatrizf;
////////////////////////////////////////////////


//////////////////////////////////////////////// hiperplanos
#ifndef TIPO_INFO_HIPERFLANOS
  #define TIPO_INFO_HIPERFLANOS int
#endif
typedef TIPO_INFO_HIPERFLANOS tipoInfoHiperplano;
typedef struct h{
	int dimension;
	int elementos;
	tipoInfoHiperplano info;
	struct h *hijo;
}hiperplano;
////////////////////////////////////////////////



//////////////////////////////////////////////// codigos
typedef char bit_t;
typedef bit_t byte_t[8];
typedef bit_t* palabra;
#define __1 1
#define __0 0
typedef struct{
	bit_t **G;
	bit_t **H;
	unsigned short int s;
	unsigned short int t;
	unsigned short int n;
	unsigned short int m;
	unsigned short int d;
}codigo;
////////////////////////////////////////////////
	





















/*****************************declaraciones******************************************/


/*  pendientes las funciones de importar y exportar matrices y vectores y las de codigos,
	y ojo por si se pueden meter maquinas de turing, grafos y automatas */


//operaciones auxiliares
int aproximar(float); //si recibe 5.63 devuelve 6, si recibe 5.48 devuelve 5
double aleatorioEntre2(double, double, int);
int enteroAleatorioConSigno(int, int);
boolean yesOrNo(string); //imprime el string, y pide un Y o un N, devolviendo true o false.






//operaciones de lectura
#define PRIMER(_1, ...)  (_1)
#define leer(...)                \
  _Generic(PRIMER(__VA_ARGS__),            \
           int: leerInt,  \
           long: leerLong,  \
           string: leerString,  \
           double: leerDouble,  \
           float: leerFloat)(__VA_ARGS__)
string leerString(string, string, int); //imprime el string y devuelve la cadena leída, con una longitud maxima dada.
int leerInt(int, string);
long leerLong(long, string);
float leerFloat(float, string);
double leerDouble(double,string);





//operaciones de imprimir
#define PRIMERR(_1, ...)  (_1)
#define print(...)                \
  _Generic(PRIMERR(__VA_ARGS__),            \
           int: printInt,  \
           long: printLong,  \
           string: printString,  \
           double: printDouble,  \
           float: printFloat)(__VA_ARGS__)
void printString(string);
void printInt(int);
void printLong(long);
void printFloat(float);
void printDouble(double);
#define println(_1) {print(_1); puts("");}
#define printlnln(_1) {println(_1); puts("");}
#define printlnlnln(_1) {printlnln(_1); puts("");}
#define PRIMERRR(_1, ...)  (_1)
#define errprint(...)                \
  _Generic(PRIMERRR(__VA_ARGS__),            \
           int: printInt,  \
           long: printLong,  \
           string: printString,  \
           double: printDouble,  \
           float: printFloat)(__VA_ARGS__)
void errPrintString(string);
void errPrintInt(int);
void errPrintLong(long);
void errPrintFloat(float);
void errPrintDouble(double);
#define errprintln(_1) {errprint(_1); puts("");}
#define errprintlnln(_1) {errprintln(_1); puts("");}
#define errprintlnlnln(_1) {errprintlnln(_1); puts("");}






//operaciones con listas
void inicializarTipoLista(tipoLista*);
void reinicializarTipoLista(tipoLista*);
void colocarTipoInfoEnLista(tipoLista*);
void colocarTipoInfo2EnLista(tipoLista*);
void colocarTipoInfo3EnLista(tipoLista*);
void colocarTipoIntEnLista(tipoLista*);
void colocarTipoFloatEnLista(tipoLista*);

int annadirPPio(tipoLista*, ...);
int annadirPPio2(tipoLista*, ...);
int annadirPPio3(tipoLista*, ...);
int annadirPPioI(tipoLista*, ...);
int annadirPPioF(tipoLista*, ...);

int annadirFin(tipoLista*, ...);
int annadirFin2(tipoLista*, ...);
int annadirFin3(tipoLista*, ...);
int annadirFinI(tipoLista*, ...);
int annadirFinF(tipoLista*, ...);

int annadirEnLugar(tipoLista*, int, ...);
int annadirEnLugar2(tipoLista*, int, ...);
int annadirEnLugar3(tipoLista*, int, ...);
int annadirEnLugarI(tipoLista*, int, ...);
int annadirEnLugarF(tipoLista*, int, ...);

void verLaLista(tipoLista*);
void verLaLista2(tipoLista*);
void verLaLista3(tipoLista*);
void verLaListaI(tipoLista*);
void verLaListaF(tipoLista*);

int modificarElValor(tipoLista*, ...);
int modificarElValor2(tipoLista*, ...);
int modificarElValor3(tipoLista*, ...);
int modificarElValorI(tipoLista*, ...);
int modificarElValorF(tipoLista*, ...);

int borrarElValor(tipoLista*, ...);
int borrarElValor2(tipoLista*, ...);
int borrarElValor3(tipoLista*, ...);
int borrarElValorI(tipoLista*, ...);
int borrarElValorF(tipoLista*, ...);

int borrarPpio(tipoLista*);
int borrarFin(tipoLista*);
int vaciarLaLista(tipoLista*);

nodo *creaNodo(tipoInfo);

int annadirPrincipio(lista*, tipoInfo);
int annadirPrincipio2(lista*, tipoInfo2);
int annadirPrincipio3(lista*, tipoInfo3);
int annadirPrincipioI(lista*, int);
int annadirPrincipioF(lista*, float);

int annadirFinal(lista*, tipoInfo);
int annadirFinal2(lista*, tipoInfo2);
int annadirFinal3(lista*, tipoInfo3);
int annadirFinalI(lista*, int);
int annadirFinalF(lista*, float);

int annadirEnMedio(lista *, int, tipoInfo);
int annadirEnMedio2(lista *, int, tipoInfo2);
int annadirEnMedio3(lista *, int, tipoInfo3);
int annadirEnMedioI(lista *, int, int);
int annadirEnMedioF(lista *, int, float);

void verLista(nodo);
void verLista2(nodo);
void verLista3(nodo);
void verListaI(nodo);
void verListaF(nodo);

int modificarValor(lista*, tipoInfo, tipoInfo);
int modificarValor2(lista*, tipoInfo2, tipoInfo2);
int modificarValor3(lista*, tipoInfo3, tipoInfo3);
int modificarValorI(lista*, int, int);
int modificarValorF(lista*, float, float);

int borrarValor(lista*, tipoInfo);
int borrarValor2(lista*, tipoInfo2);
int borrarValor3(lista*, tipoInfo3);
int borrarValorI(lista*, int);
int borrarValorF(lista*, float);

int borrarPrincipio(lista*);
int borrarFinal(lista*);
int vaciarLista(lista*);
int tamannoDeLaLista(nodo);
boolean estaVacia(lista);







// operaciones con arboles
Arbol creaArbol(tipoInfoArbol info);
void preOrden(Arbol raiz);
void enOrden(Arbol raiz);
void postOrden(Arbol raiz);
void amplitudArbol(Arbol raiz);
int altura(Arbol raiz);
int numNodos(Arbol raiz);
int sustituye(Arbol raiz, tipoInfoArbol x, tipoInfoArbol y);
int numNodosHoja(Arbol raiz);
int numNodosInternos(Arbol raiz);
int numHijoUnico(Arbol raiz);
Arbol buscarMax(Arbol raiz);
Arbol buscarMin(Arbol raiz);
boolean similares(Arbol r1,Arbol r2);
boolean equivalentes(Arbol r1,Arbol r2);
Arbol especular(Arbol raiz);









// operaciones con monticulos

void crearMonticulo(Monticulo *m);
void heapsort(Monticulo *m);
void iniciaMonticulo(Monticulo *m);
int vacioMonticulo(Monticulo m);
void filtradoDescendente(Monticulo *m, int i);
void filtradoAscendente(Monticulo *m, int i);
int insertar(tipoElementoMonticulo x, Monticulo *m);
int eliminarMinimo(Monticulo *m, tipoElementoMonticulo *minimo);
void decrementarClave(int pos, tipoClaveMonticulo cantidad, Monticulo *m);
void incrementarClave(int pos, tipoClaveMonticulo cantidad, Monticulo *m);
int esMonticulo(Monticulo m);









//operaciones con grafos

void iniciarGrafo(tipoGrafo *g);
void profundidad(int v_inicio,tipoGrafo *grafo);
void profundidadMejorado(int v_inicio, tipoGrafo * grafo);
void amplitud(int v_inicio,tipoGrafo *grafo);
int ordenTop1(tipoGrafo *grafo);
int ordenTop2(tipoGrafo *grafo);
int buscarVerticeGradoEntradaCeroNoOrdenTop(tipoGrafo *grafo);
void caminos1(int vInicio, tipoGrafo *grafo);
void caminos2(int vInicio, tipoGrafo *grafo);
void dijkstra1(int vInicio, tipoGrafo *grafo);
void dijkstra2(int vInicio, tipoGrafo *grafo);
int buscarVerticeDistanciaMinimaNoAlcanzado(tipoGrafo *grafo);
void aceptarArista(tipoGrafo *grafo, tipoElementoMonticulo x);
void liberarListas(tipoGrafo *grafo);
int costeyTrayectoria(int vIni, int vFin, tipoGrafo *grafo);
void todosCaminosMin(int vIni, tipoGrafo *grafo);
tipoGrafo *prim1(tipoGrafo *grafo);
tipoGrafo *prim2(tipoGrafo *grafo);
int buscarVerticeCostoMinimoNoAlcanzado(tipoGrafo * grafo);
tipoGrafo *crearArbolDeExpansion(tipoGrafo *grafo);
tipoGrafo *kruskal(tipoGrafo *grafo);
void construirMonticuloDeAristas(tipoGrafo *grafo, Monticulo *m);






//operaciones con strings
string todoMayusculas(string);
string todoMinusculas(string);
int meterLetraEnCadena(string*, char);
char siguienteChar(string);
string substring(string, int, int);
int numaparicioneschar(string, char);
int numaparicionessub(string, string);






//operaciones con matrices y vectores

 matriz leerMatrizI(int, int, string);
tipoMatriz leerMatrizI_O(int, int, string);
matrizf leerMatrizF(int, int, string);
tipoMatrizf leerMatrizF_O(int, int, string);
matriz generarMatrizI(int, int, int, int);
tipoMatriz generarMatrizI_O(int, int, int, int);
matrizf generarMatrizF(int, int, float, float, int);
tipoMatrizf generarMatrizF_O(int, int, int, int, int);
void imprimirMatrizI(matriz,int,int);
void imprimirMatrizI_O(tipoMatriz  mat);
void imprimirMatrizF(matrizf,int,int);
void imprimirMatrizF_O(tipoMatrizf mat);
 vector leerVectorI(int, string);
vectorf leerVectorF(int, string);
void imprimirVectorI(vector ,int);
void imprimirVectorF(vectorf,int);
  

matriz multiplicarMatrI(matriz, matriz, int, int, int);
tipoMatriz multiplicarMatrI_O(tipoMatriz ma, tipoMatriz mb);
matrizf multiplicarMatrF(matrizf, matrizf, int, int, int);
tipoMatrizf multiplicarMatrF_O(tipoMatrizf ma, tipoMatrizf mb);
matriz sumarMatrI(matriz, matriz, int, int);
tipoMatriz sumarMatrI_O(tipoMatriz ma, tipoMatriz mb);
matrizf sumarMatrF(matrizf, matrizf, int, int);
tipoMatrizf sumarMatrF_O(tipoMatrizf ma, tipoMatrizf mb);
matriz restarMatrI(matriz, matriz, int, int);
tipoMatriz restarMatrI_O(tipoMatriz ma, tipoMatriz mb);
matrizf restarMatrF(matrizf, matrizf, int, int);
tipoMatrizf restarMatrF_O(tipoMatrizf ma, tipoMatrizf mb);
matriz numPorMatrI(int, matriz, int, int);
tipoMatriz numPorMatrI_O(int a, tipoMatriz mat);
matrizf numPorMatrF(float, matrizf, int, int);
tipoMatrizf numPorMatrF_O(int a, tipoMatrizf mat);

  int    productoEscalarI( vector,  vector, int);
float    productoEscalarF(vectorf, vectorf, int);
vector   productoVectorialI( vector,  vector);
vectorf  productoVectorialF(vectorf, vectorf);
  int    determinanteI( matriz, int);
float    determinanteF(matrizf, int);
  int  determinanteI_O( tipoMatriz m);
float  determinanteF_O(tipoMatrizf m);
matriz   concatenarMatricesEnHorizontalI(matriz, matriz,int,int,int);
tipoMatriz concatenarMatricesEnHorizontalI_O(tipoMatriz ma, tipoMatriz mb);
matrizf  concatenarMatricesEnHorizontalF(matrizf, matrizf, int,int,int);
tipoMatrizf concatenarMatricesEnHorizontalF_O(tipoMatrizf ma, tipoMatrizf mb);
matriz   concatenarMatricesEnVerticalI(matriz, matriz,int,int,int);
tipoMatriz concatenarMatricesEnVerticalI_O(tipoMatriz ma, tipoMatriz mb);
matrizf  concatenarMatricesEnVerticalF(matrizf,matrizf, int,int,int);
tipoMatrizf concatenarMatricesEnVerticalF_O(tipoMatrizf ma, tipoMatrizf mb);
vector   concatenarVectoresI(vector, vector,int,int);
vectorf  concatenarVectoresF_O(vectorf, vectorf, int,int);



//operaciones con ficheros
FILE *abrirFpBloq(string, string);
void cerrarFpBloq(FILE *);



//operaciones con pilas
int pilaCreaVacia(Pila *);
boolean pilaVacia(Pila *);
int pilaInserta(tipoElementoP, Pila *);
tipoElementoP pilaSuprime(Pila *);
void pilaImprime(Pila);



//operaciones con colas
int colaCreaVacia(Cola *);
boolean colaVacia(Cola *);
int colaInserta(tipoElementoC, Cola *);
tipoElementoC colaSuprime(Cola *);
void colaImprime(Cola);



//operaciones con colas de arbol
int colaArbolCreaVacia(ColaArbol *);
boolean colaArbolVacia(ColaArbol *);
int colaArbolInserta(tipoElementoCDA, ColaArbol *);
tipoElementoCDA colaArbolSuprime(ColaArbol *);



//operaciones con codigos (no disponible en version 1.0)
palabra encriptar(palabra,codigo);
palabra desencriptar(palabra,codigo);
palabra sindrome(palabra,codigo);
codigo generarG_estandar(int, int);
int peso(palabra);
void *normalizarG(codigo*);
int H2G_estandar(codigo*);
int G2H_estandar(codigo*);
int calcularS(codigo*);
int calcularT(codigo*);
int calcularNyM(codigo*);
int calcularD(codigo*);
codigo generarCodigoInicializado(byte_t**);
codigo generarHamming(int);
bit_t sacarBit(short int);
boolean bitEsDeInfo(bit_t**,int,int);



//operaciones con hiperplanos (no disponible en version 1.0)
hiperplano leerPlano(dimension);
void imprimirPlano(hiperplano);
hiperplano hijo(hiperplano, int);
hiperplano planoOrtogonal(hiperplano, int);










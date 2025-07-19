/*****************************************************************************************************************/
/*****************************************************************************************************************/
/********************************** BIBLIOTECA DE FUNCIONES DE C, DECLARACIONES **********************************/
/************************************** AUTOR: SERGIO JUAN ROLLÁN MORALEJO ***************************************/
/*****************************************       VERSIÓN NO: 1.0       *******************************************/
/************************************** FECHA DE FINALIZACIÓN: 03-07-2022 ****************************************/
/*****************************************************************************************************************/
/*****************************************************************************************************************/






/*************************************preprocesador**************************************/

#ifndef SERGIOTECA_H
#define SERGIOTECA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#include <conio.h>
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


//////////////////////////////////////////////// lista circular doblemente enlazada con saltos
typedef struct nodo_salto {
    int info;
    struct nodo_salto *sig;
    struct nodo_salto *ant;
    int numSaltos;
    struct nodo_salto **saltos; // array de punteros a saltos
} nodoSalto;
typedef struct tipoListaSalto tipoListaSalto;
struct tipoListaSalto {
    nodoSalto *cabecera; // apunta al nodo 1 (vacío)
    int numElementos;
    int (*annadirPpio)(tipoListaSalto*, int);
    int (*annadirFin)(tipoListaSalto*, int);
    int (*annadirEnLugar)(tipoListaSalto*, int, int);
    int (*borrarPpio)(tipoListaSalto*);
    int (*borrarFin)(tipoListaSalto*);
    int (*borrarValor)(tipoListaSalto*, int);
    int (*modificarValor)(tipoListaSalto*, int, int);
    int (*vaciarLista)(tipoListaSalto*);
    void (*mostrarLista)(tipoListaSalto*);
};
////////////////////////////////////////////////


//////////////////////////////////////////////// Set
typedef struct nodo_set 
{
    int info;
    struct nodo_set *sig;
} nodoSet;
typedef struct tipoListaSet tipoListaSet;
struct tipoListaSet 
{
    nodoSet *primero;
    int numElementos;
    int (*annadirPpio)(tipoListaSet*, int);
    int (*annadirFin)(tipoListaSet*, int);
    int (*annadirEnLugar)(tipoListaSet*, int, int);
    int (*borrarPpio)(tipoListaSet*);
    int (*borrarFin)(tipoListaSet*);
    int (*borrarValor)(tipoListaSet*, int);
    int (*vaciarLista)(tipoListaSet*);
    void (*mostrarLista)(tipoListaSet*);
};
////////////////////////////////////////////////


//////////////////////////////////////////////// diccionario
typedef char* tipoKey;
typedef char* tipoValor;
typedef struct
{
	tipoKey clave;
	tipoValor valor;
}tipoElementoDiccionario;
typedef struct
{
    tipoElementoDiccionario* entries;
    int size;
    int capacity;
} tipoDiccionario;
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


//////////////////////////////////////////////// procesos ssoo
typedef struct{
	int pid;
	int turnoLlegada;
	int tiempoEjecucion;
	int tiempoRestante;
	int tiempoEspera;
	int tiempoRespuesta;
	int tiempoRetorno;
}proceso;
typedef struct{
	proceso *procesos;
	int numProcesos;
	int cuanto;
	int esperaMaxima;
	int* pidsTurnos;
	int numeroTotalTurnos;
	float tiempoCambioProceso;
	float tiempoTurno;
	float tiempoPromedio;
	float tiempoTotal;
	boolean codigoError;
}ssoo;
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


//////////////////////////////////////////////// cartas
typedef enum{
	desconocido = -1,
	picas = 0,
	diamantes = 1,
	treboles = 2,
	corazones = 3
}palo;
typedef struct{
	int valor;
	palo palo;
}carta;
typedef struct{
	carta *cartas;
	int numCartas;
}mano;
typedef struct{
	mano mano;
	string nombre;
}jugador;
typedef struct{
	jugador *jugadores;
	int numJugadores;
}juego;
////////////////////////////////////////////////
	




//////////////////////////////////////////////// Intercambiar variables
#define SWAP_UNSIGNED(a, b) do { (a) = (a) + (b); (b) = (a) - (b); (a) = (a) - (b); } while(0)
#define SWAP_SIGNED_OR_FLOAT(a, b) (a) = ((a*b)/(b=a)); //no usar con ceros
#define SWAP_XOR(a, b) do { (a) ^= (b); (b) ^= (a); (a) ^= (b); } while(0)
#define SWAP(a, b) _Generic((a), \
    unsigned char: SWAP_UNSIGNED, \
    unsigned short: SWAP_UNSIGNED, \
    unsigned int: SWAP_UNSIGNED, \
    unsigned long: SWAP_UNSIGNED, \
    unsigned long long: SWAP_UNSIGNED, \
    float: SWAP_SIGNED_OR_FLOAT, \
    double: SWAP_SIGNED_OR_FLOAT, \
    long double: SWAP_SIGNED_OR_FLOAT, \
    default: SWAP_XOR \
)(a, b)
////////////////////////////////////////////////


//////////////////////////////////////////////// Gantt
typedef struct{
	int id;
	string nombre;
	int duracion;
	int *dependencias;
	int numDependencias;
	int tiempoInicio;
}tarea;
typedef struct{
	tarea *tareas;
	int numTareas;
	int *caminoCritico;
	int numCaminoCritico;
	string nombreProyecto;
}gantt;
////////////////////////////////////////////////













/*****************************declaraciones******************************************/


//operaciones auxiliares
int aproximar(float);
void alwaysPause(void);
boolean yesOrNo(string);
string elegirOpcion(string s, const char **opciones, int numOpciones);

// numeros aleatorios
double aleatorioEntre2(double, double, int);
int enteroAleatorioConSigno(int, int);
int aleatorioBinomial(int n, double p);
double aleatorioNormal(double mu, double sigma);

//descomponer
int descomponerFactoresPrimos(int n, int *factores);
int descomponerPolinomioRuffini(const int *coef, int grado, int *raices);

// mcd y mcm
int mcd(int a, int b);
int mcm(int a, int b);
int mcd_n(const int *valores, int n);
int mcm_n(const int *valores, int n);
int mcd_descp(int a, int b);
int mcm_descp(int a, int b);

// distancia en teclado QWERTY
float distanciaTecladoQWERTY(char a, char b);

//combinatoria
long combinaciones(int n, int m);
long combinacionesConRepeticion(int n, int m);
long variaciones(int n, int m);
long variacionesConRepeticion(int n, int m);
long permutaciones(int n);
long permutacionesConRepeticion(int n, const int *ms, int k);


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

//operaciones de lectura de contraseñas
#define PRIMERPW(_1, ...)  (_1)
#define leerPassword(...)                \
  _Generic(PRIMERPW(__VA_ARGS__),            \
           int: leerPasswordInt,  \
           long: leerPasswordLong,  \
           string: leerPasswordString,  \
           double: leerPasswordDouble,  \
           float: leerPasswordFloat)(__VA_ARGS__)
int leerPasswordInt(int, string);
long leerPasswordLong(long, string);
float leerPasswordFloat(float, string);
double leerPasswordDouble(double, string);
string leerPasswordString(string, string, int, boolean);



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
void mostrarLista(struct s*);


boolean estaVacia(lista);




// Lista circular doblemente enlazada con saltos
void inicializarListaSalto(tipoListaSalto *lst);
int annadirPpioSalto(tipoListaSalto *lst, int valor);
int annadirFinSalto(tipoListaSalto *lst, int valor);
int annadirEnLugarSalto(tipoListaSalto *lst, int pos, int valor);
int borrarPpioSalto(tipoListaSalto *lst);
int borrarFinSalto(tipoListaSalto *lst);
int borrarValorSalto(tipoListaSalto *lst, int valor);
int modificarValorSalto(tipoListaSalto *lst, int valorAnt, int valorNuevo);
int vaciarListaSalto(tipoListaSalto *lst);
void mostrarListaSalto(tipoListaSalto *lst);




// operaciones con diccionarios
void initDictionary(tipoDiccionario* dict);
void freeDictionary(tipoDiccionario* dict);
boolean addEntry(tipoDiccionario* dict, tipoKey key, tipoValor value);
boolean addEntryIfNotExists(tipoDiccionario* dict, tipoKey key, tipoValor value);
boolean removeEntry(tipoDiccionario* dict, tipoKey key);
tipoValor getValue(tipoDiccionario* dict, tipoKey key);
tipoValor* getValues(tipoDiccionario* dict, int* count);
tipoKey* getKeys(tipoDiccionario* dict, int* count);








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

tipoGrafo* creaGrafo();
void verGrafo(tipoGrafo *g);
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
vectorf  concatenarVectoresF(vectorf, vectorf, int,int);



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

// Planificación de procesos en sistemas operativos
int inicializarProcesoPid(proceso *p, int pid, int turnoLlegada, int tiempoEjecucion);
ssoo proc_FCFS(ssoo sistema);
ssoo proc_RR(ssoo sistema);
ssoo proc_SPN(ssoo sistema);
ssoo proc_SRN(ssoo sistema);
ssoo proc_HRRN(ssoo sistema);
ssoo proc_RA(ssoo sistema);




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
hiperplano leerPlano(int dimension);
void imprimirPlano(hiperplano);
hiperplano hijo(hiperplano, int);
hiperplano planoOrtogonal(hiperplano, int);



int bubbleSortI(int *v, int n);
int bubbleSortF(float *v, int n);
int selectionSortI(int *v, int n);
int selectionSortF(float *v, int n);
int insertionSortI(int *v, int n);
int insertionSortF(float *v, int n);
int mergeSortI(int *v, int n);
int mergeSortF(float *v, int n);
int quickSortI(int *v, int n);
int quickSortF(float *v, int n);
int shellSortI(int *v, int n);
int shellSortF(float *v, int n);
int gnomeSortI(int *v, int n);
int gnomeSortF(float *v, int n);
int combSortI(int *v, int n);
int combSortF(float *v, int n);
int oddEvenSortI(int *v, int n);
int oddEvenSortF(float *v, int n);
int bitonicSortI(int *v, int n);
int bitonicSortF(float *v, int n);
int pancakeSortI(int *v, int n);
int pancakeSortF(float *v, int n);
int stoogeSortI(int *v, int n);
int stoogeSortF(float *v, int n);
int sleepSortI(int *v, int n);
int sleepSortF(float *v, int n);
int cycleSortI(int *v, int n);
int cycleSortF(float *v, int n);
int countingSort(int *v, int n);
int radixSort(int *v, int n);
int bucketSort(int *v, int n);
int pigeonholeSort(int *v, int n);


// Algoritmos de búsqueda para enteros
int linearSearch(const int *vector, int n, int valorBuscado);
int binarySearch(const int *vector, int n, int valorBuscado);
int ternarySearch(const int *vector, int n, int valorBuscado);
int exponentialSearch(const int *vector, int n, int valorBuscado);
int jumpSearch(const int *vector, int n, int valorBuscado);
int fibonacciSearch(const int *vector, int n, int valorBuscado);

// Algoritmos de búsqueda para floats
int linearSearchF(const float *vector, int n, float valorBuscado);
int binarySearchF(const float *vector, int n, float valorBuscado);
int ternarySearchF(const float *vector, int n, float valorBuscado);
int exponentialSearchF(const float *vector, int n, float valorBuscado);
int jumpSearchF(const float *vector, int n, float valorBuscado);
int fibonacciSearchF(const float *vector, int n, float valorBuscado);


// Cartas y mazos
carta* generarBaraja(void);
int shuffle(carta *mazo, int numCartas);
juego* repartir(carta *mazo, jugador *jugadores, int numJugadores, int cartasPorJugador);
carta robarCarta(mano *mazo);
carta sacarCarta(mano *mazo, int valor, palo palo);
int cogerCarta(mano *mazo, carta c);
void mostrarMazo(jugador j);
void mostrarCarta(carta c);


// Sets
void inicializarListaSet(tipoListaSet *lst);
int annadirPpioSet(tipoListaSet *lst, int valor);
int annadirFinSet(tipoListaSet *lst, int valor);
int annadirEnLugarSet(tipoListaSet *lst, int pos, int valor);
int borrarPpioSet(tipoListaSet *lst);
int borrarFinSet(tipoListaSet *lst);
int borrarValorSet(tipoListaSet *lst, int valor);
int vaciarListaSet(tipoListaSet *lst);
void mostrarListaSet(tipoListaSet *lst);


// Diagrama de Gantt
gantt* crearGantt(string nombreProyecto);
boolean comprobarGanttValido(gantt *g);
int elaborarCaminoCritico(gantt *g);
int annadirTarea(gantt *g, int id, string nombre, int duracion, int *dependencias, int numDependencias, int tiempoInicio);
void pintarDiagrama(gantt *g);



#endif

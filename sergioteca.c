/*****************************************************************************************************************/
/*****************************************************************************************************************/
/********************************** BIBLIOTECA DE FUNCIONES DE C, CÓDIGO FUENTE **********************************/
/**********************************     AUTOR: SERGIO JUAN ROLLÁN MORALEJO      **********************************/
/**********************************              VERSIÓN NO: 1.0                **********************************/
/**********************************      FECHA DE PUBLICACIÓN: 03-07-2022       **********************************/
/**********************************     FECHA DE ACTUALIZACIÓN: 09-07-2025      **********************************/
/*****************************************************************************************************************/
/*****************************************************************************************************************/
#include "sergioteca.h"





/**********************************funciones*********************************************/

/**
 * Imprime la línea por pantalla y pregunta al usuario hasta
 * que teclee una 'y' o una 'n', mayúscula o minúscula. 
 * @param s (string): cadena de caracteres que se imprimirá por pantalla para realizar la pregunta.
 * @return TRUE en caso de que se teclee 'y', FALSE en caso de que se teclee 'n'.
 * @example boolean b = yesOrNo("¿Seguro que quieres terminar el programa?");
 */
boolean yesOrNo(string s)
{
	char c;
	printf("%s", s);
	printf("(Y/N): ");
	
	scanf("%c%*c", &c);
	c=toupper(c);
	
	while(c!='Y'&&c!='N')
	{
		printf("(Y/N): ");
		scanf("%c%*c", &c);
		c=toupper(c);
	}
	
	return (c=='Y')?TRUE:FALSE;
	
}

string leerString(string u, string s, int i)
{
	u=malloc(sizeof(char)*(i+1));
	int j;
	string r = malloc((i+1) * sizeof(char));
	if (r == NULL) return NULL;
	printf("%s", s);
	NUEVA_LINEA;
	fgets(r, i, stdin);
	for (j = 0; j < i; j++) if (r[j] == '\0') break; else u[j] = r[j];
	u[j] = '\0';
	return u;
}

int leerInt(int a, string s)
{
	printf("%s", s);
	NUEVA_LINEA;
	scanf("%d%*c", &a);
	return a;
}

long leerLong(long a, string s)
{
	printf("%s", s);
	NUEVA_LINEA;
	scanf("%ld%*c", &a);
	return a;
}

float leerFloat(float a, string s)
{
	printf("%s", s);
	NUEVA_LINEA;
	scanf("%f%*c", &a);
	return a;
}

double leerDouble(double a, string s)
{
	printf("%s", s);
	NUEVA_LINEA;
	scanf("%lf%*c", &a);
	return a;
}

void printInt(int a){fprintf(stdout,"%d",a);}
void printLong(long a){fprintf(stdout,"%ld",a);}
void printFloat(float a){fprintf(stdout,"%f",a);}
void printDouble(double a){fprintf(stdout,"%lf",a);}
void printString(string a){fprintf(stdout,"%s",a);}
void errPrintInt(int a){fprintf(stderr,"%d",a);}
void errPrintLong(long a){fprintf(stderr,"%ld",a);}
void errPrintFloat(float a){fprintf(stderr,"%f",a);}
void errPrintDouble(double a){fprintf(stderr,"%lf",a);}
void errPrintString(string a){fprintf(stderr,"%s",a);}

/**
 * Calcula el número entero más cercano al número real dado.
 * @param f (float): número real que se va a aproximar
 * @return el número entero más cercano al real recibido.
 * @example int a = aproximar(6.67); // a=7;
 */
int aproximar(float f){ return (((int)(f+0.5))>=(((int)f)+1)) ? ((int)f)+1 : (int)f;}

/**
 * Calcula un número aleatorio entre 2 reales dados con un número de cifras decimales
 * @param inf (double): número real que será siempre menor que el número generado por la función
 * @param sup (double): número real que será siempre mayor que el número generado por la función
 * @param prec(int): nivel de precisión ('2' serán centésimas, '3' serán milésimas, etc)
 * @return el número real aleatorio generado si tiene éxito, FALLO si alguno de los argumentos es negativo
 * @example double d = aleatorioEntre2(5.94, 8.32, 4); // d=7.358100;
 */
double aleatorioEntre2(double inf, double sup, int prec)
{
	int infi=(int)inf, supi=((int)sup)+1;
	int r; 
	double decimal;
	int _100tfko;
	double resul, temp;
	if(prec<0 || inf<0 || sup<0) return FALLO;
    if(inf>sup){ inf=sup+inf; sup=inf-sup; inf = inf-sup; }
	temp=inf; inf=0; sup-=temp;
	r = (rand() % (supi-infi+1))+infi;
	_100tfko=pow(10,prec);
	decimal = ((double)(rand()%_100tfko))/(double)_100tfko;
	resul=(double)r + decimal;
	while(resul>sup || resul<inf)
		if(resul < inf) resul+=((sup-inf)/2);
			else if(resul > sup) resul-=((sup-inf)/2);
	return resul+temp;
}

/**
 * Calcula un número entero aleatorio entre 2 enteros dados
 * @param inf (int): número real que será siempre menor o igual que el número generado por la función
 * @param sup (int): número real que será siempre mayor o igual que el número generado por la función
 * @return el número entero aleatorio generado.
 * @example int num = enteroAleatorioConSigno(-4, 4); // [-4, -3, -2, -1, 0, 1, 2, 3 ó 4]
 */
int enteroAleatorioConSigno(int inf, int sup)
{
    int temp = inf;
    int resul=0;
    if(inf>sup){ inf=sup+inf; sup=inf-sup; inf = inf-sup; }
    sup-=inf;
    inf=0;
    resul=rand()%(sup+1);
    return resul+temp;
}

/**
 * Hay que pasarle un puntero a string que esté apuntando a null
 * Deja en el puntero la subcadena de cad que va desde los índices inf a sup.
 * @param cad (string): cadena de caracteres que será recortada por la función.
 * @param inf (int): primer caracter que formará parte de la cadena recortada (empezando en 0)
 * @param sup (int): último caracter que formará parte de la cadena recortada (empezando en 0)
 * @return
 * @example string var = substring("holamundo", 3, 6); // var = "amun"
 */
string substring(string cad, int inf, int sup)
{
    if (cad == NULL || inf < 0 || sup < inf || sup >= (int)strlen(cad)) return NULL;
    int len = sup - inf + 1;
    string result = malloc((len + 1) * sizeof(char));
    if (result == NULL) return NULL;
    for (int i = 0; i < len; i++) {
        result[i] = cad[inf + i];
    }
    result[len] = '\0';
	return result;
}

/**
 * Cuenta el número de veces que aparece el carácter dado en la cadena dada y devuelve el resultado.
 * @param s (string): cadena de caracteres en la que se va a buscarMax
 * @param cc (char): caracter que se va a buscar
 * @return número de veces que 'cc' aparece en 's', o FALLO si 's' es NULL
 * @example int n = numaparicioneschar("holamundo", 'o'); // n=2;
 */
int numaparicioneschar(string s, char cc)
{
	int i=0; char c;
	if(s==NULL) return FALLO;
	c=siguienteChar(s);
	while(c!='\0')
	{
		if(c==cc) i++;
		c=siguienteChar(NULL);
	}
	return i;
}


/**
 * Cuenta el número de veces que aparece una cadena de caracteres en otra cadena dada y devuelve el resultado.
 * @param s (string): cadena de caracteres en la que se va a buscarMax
 * @param ss (string): cadena de caracteres que se va a buscar
 * @return número de veces que 'ss' aparece en 's', o FALLO si alguno de los dos strings es NULL
 * @example int n = numaparicionessub("habersimemuero", "er"); // n=2;
 */
int numaparicionessub(string s, string ss)
{
    if (s == NULL || ss == NULL || strlen(ss) == 0) return 0;
    int count = 0;
    int len_s = strlen(s);
    int len_ss = strlen(ss);
    for (int i = 0; i <= len_s - len_ss; i++) {
        int j = 0;
        while (j < len_ss && s[i + j] == ss[j]) j++;
        if (j == len_ss) count++;
    }
    return count;
}

/** 
 * Va devolviendo el siguiente char de un string respecto a la invocacion anterior.
 * La primera invocacion se debe hacer pasando el string a recorrer. En el resto, NULL.
 * @param cadena (string): cadena a recorrer, será NULL si ya se está realizando un recorrido.
 * @return el siguiente caracter de la cadena, o el primero si no se ha pasado NULL.
 * @example string s = "Hola mundo"; char c; \
 * * c=siguienteChar(s); // c = 'H' \
 * * c=siguienteChar(NULL); // c = 'o' \
 * * c=siguienteChar(NULL); // c = 'l' \
 * * c=siguienteChar(NULL); // c = 'a' \
 * * c=siguienteChar(NULL); // c = ' ' y así sucesivamente
 */
char siguienteChar(string cadena)
{
	static int i=0;
	static char* c=NULL;
	if(cadena!=NULL)
	{
		i=0;
		c=cadena;
	}
	if(c==NULL || strlen(c)<=1) return FALLO;
	return c[i++];
}
/**
 * Función que deja un string entero en mayúsuculas.
 * @param c (string): cadena de caracteres que se pasará a mayúsculas
 * @return string convertido
 * @example string s = "Hola mundo"; s = todoMayusculas(s); // s = "HOLA MUNDO";
 */
string todoMayusculas (string c) 
{
	string copy; char *aux;
	copy = malloc(strlen(c)*sizeof(char)+1);
	strcpy(copy, c);
	aux=copy;
	while (*aux!='\0')
	{
	  	if ((*aux >= 'a' ) && (*aux <= 'z')) *aux -= 32;
	    aux++;
	}
	return copy;
} 
/**
 * Función que deja un string entero en minúsuculas.
 * @param c (string): cadena de caracteres que se pasará a minúsculas
 * @return string convertido
 * @example string s = "Hola mundo"; s = todoMinusculas(s); // s = "hola mundo";
 */
string todoMinusculas (string c) 
{
	string copy; char *aux;
	copy = malloc(strlen(c)*sizeof(char)+1);
	strcpy(copy, c);
	aux=copy;
	while (*aux!='\0')
	{
	  	if ((*aux >= 'A' ) && (*aux <= 'Z')) *aux += 32;
	    aux++;
	}
	return copy;
} 


/**
 * Inicializa los campos de la pila pasada por referencia
 * @param p (Pila ref): variable pila que se va a inicializar
 * @return EXITO si no hay errores, FALLO si la función recibe NULL
 * @example Pila p; pilaCreaVacia(&p);
 */
int pilaCreaVacia(Pila *p)
{
    if(p==NULL) return FALLO;
    *p = NULL;
    return EXITO;
}

/**
 * Comprueba si hay algún elemento metido en la pila
 * @param p (Pila ref): variable pila que se va a examinar
 * @return TRUE si no hay ningún elemento, FALSE en caso contrario
 * @example if(pilaVacia(&p)==TRUE) print(0);
 */
boolean pilaVacia(Pila *pila){return ((*pila)==NULL)?TRUE:FALSE;}

/**
 * Introduce un elemento en la cumbre de la pila
 * @param elemento (tipoElementoP): elemento que se introducirá en la pila
 * @param p (Pila ref): variable pila en la que se introducirá el elemento
 * @return FALLO si 'p' es NULL, EXITO en caso contrario
 * @example pilaInserta(2, &p); pilaInserta(4, &p); // la pila tendrá [4, 2]
 */
int pilaInserta(tipoElementoP elemento, Pila *p)
{
	Pila temp;
	if (p==NULL || NULL == (temp = malloc(sizeof(tipoCeldaP)))) return FALLO;
	temp->elemento = elemento;
	temp->sig = *p;
	*p = temp;
	return EXITO;
}

/**
 * Extrae el elemento en la cumbre de la pila
 * @param p (Pila ref): variable pila de la que se extraerá el elemento
 * @return tipoElementoP: el elemento extraído
 * @example Pila p; pilaCreaVacia(&p); pilaInserta(2, &p); pilaInserta(4, &p); tipoElementoP t = pilaSuprime(&p); // t=4;
 */
tipoElementoP pilaSuprime(Pila *p)
{
	tipoElementoP x;
	Pila temp;
	if (p==NULL||pilaVacia(p)==TRUE) exit(-1);
	x = (*p)->elemento;
	temp=*p;
	(*p) = (*p)->sig;
	free(temp);
	return x;
}

/**
 * Imprime la pila en formato vertical.
 * @param p (Pila): pila que se imprimirá por consola
 * @return void
 * @example Pila p; pilaCreaVacia(&p); pilaInserta(3, &p); pilaInserta(2, &p); pilaInserta(4, &p); pilaImprime(p);
 * Imprimirá: "|4|
 *             |2|
 *             |3|
 *              - 
 *            "
 */
void pilaImprime(Pila p)
{
    tipoElementoP x;
    if(pilaVacia(&p))
    {
        print("\n|_|\n");
        return;
    }
    while(p!=NULL)
    {
        print("|");
        print(p->elemento);
        print("|");
        NUEVA_LINEA;
        p=p->sig;
    }
    print(" -");
    NUEVA_LINEA;
}

/**
 * Inicializa los campos de la cola pasada por referencia
 * @param c (Cola ref): variable cola que se va a inicializar
 * @return EXITO si no hay errores, FALLO si la función recibe NULL
 * @example Cola c; colaCreaVacia(&c);
 */
int colaCreaVacia(Cola *c)
{
	if(NULL==c) return FALLO;
	c->fondo = NULL;
    c->frente = NULL;
 	return EXITO;
}

int colaArbolCreaVacia(ColaArbol *c)
{
	if(NULL==c) return FALLO;
	c->fondo = NULL;
    c->frente = NULL;
 	return EXITO;
}

/**
 * Comprueba si hay algún elemento metido en la cola
 * @param c (Cola ref): variable cola que se va a examinar
 * @return TRUE si no hay ningún elemento, FALSE en caso contrario
 * @example if(colaVacia(&c)==TRUE) print(0);
 */
boolean colaVacia(Cola *c){return ((c->frente==NULL) && (c->fondo==NULL))?TRUE:FALSE;}
boolean colaArbolVacia(ColaArbol *c){return ((c->frente==NULL) && (c->fondo==NULL))?TRUE:FALSE;}

/**
 * Introduce un elemento al final de la cola
 * @param elemento (tipoElementoC): elemento que se introducirá en la cola
 * @param c (Cola ref): variable cola en la que se introducirá el elemento
 * @return FALLO si 'c' es NULL, EXITO en caso contrario
 * @example colaInserta(2, &c); colaInserta(4, &c); // la cola tendrá [2, 4]
 */
int colaInserta(tipoElementoC elemento, Cola *c)
{
	tipoCeldaC *nuevo;
    if (c==NULL || NULL==(nuevo=malloc(sizeof(tipoCeldaC)))) return FALLO;
	nuevo->elemento = elemento;
	nuevo->sig = NULL;
	if(colaVacia(c))
	{
		c->frente = nuevo;
		c->fondo = nuevo;
	}else
	{
		c->fondo->sig = nuevo;
		c->fondo = nuevo;
	}
	return EXITO;    
}

int colaArbolInserta(tipoElementoCDA elemento, ColaArbol *c)
{
	tipoCeldaCDA *nuevo;
    if (c==NULL || NULL==(nuevo=malloc(sizeof(tipoCeldaCDA)))) return FALLO;
	nuevo->elemento = elemento;
	nuevo->sig = NULL;
	if(colaArbolVacia(c))
	{
		c->frente = nuevo;
		c->fondo = nuevo;
	}else
	{
		c->fondo->sig = nuevo;
		c->fondo = nuevo;
	}
	return EXITO;    
}

/**
 * Extrae el elemento al principio de la cola
 * @param c (Cola ref): variable pila de la que se extraerá el elemento
 * @return tipoElementoP: el elemento extraído
 * @example Cola c; colaCreaVacia(&c); colaInserta(2, &c); colaInserta(4, &c); tipoElementoC t = colaSuprime(&c); // t=2;
 */
tipoElementoC colaSuprime(Cola *c)
{
	tipoElementoC x;
    tipoCeldaC *aBorrar;
	if(colaVacia(c)==TRUE) exit(-1);
	x = c->frente->elemento;
	if(c->frente == c->fondo)
	{
		aBorrar = c->frente;
		c->frente = NULL;
		c->fondo = NULL;
		free(aBorrar);
	}else
	{
		aBorrar = c->frente;
		c->frente = c->frente->sig;
		free(aBorrar);
	}
	return x;
}

tipoElementoCDA colaArbolSuprime(ColaArbol *c)
{
	tipoElementoCDA x;
    tipoCeldaCDA *aBorrar;
	if(colaArbolVacia(c)==TRUE) exit(-1);
	x = c->frente->elemento;
	if(c->frente == c->fondo)
	{
		aBorrar = c->frente;
		c->frente = NULL;
		c->fondo = NULL;
		free(aBorrar);
	}else
	{
		aBorrar = c->frente;
		c->frente = c->frente->sig;
		free(aBorrar);
	}
	return x;
}

/**
 * Imprime la cola en formato horizontal de izquierda a derecha.
 * @param c (Cola): cola que se imprimirá por consola
 * @return void
 * @example Cola c; colaCreaVacia(&c); colaInserta(3, &c); colaInserta(2, &c); colaInserta(4, &c); tipoElementoC t = colaImprime(c); //imprime "[3, 2, 4]"
 */
void colaImprime(Cola c)
{
    tipoElementoC x;
    print("[");
    while(c.frente!=NULL)
    {
        print(c.frente->elemento);
        if(c.frente->sig!=NULL) print(", ");
        c.frente=c.frente->sig;
    }
    print("]");
    NUEVA_LINEA;
}

/**
 * Añade un carácter al final de la cadena dada
 * @param a (string ref): cadena a la que se añadirá el carácter
 * @param b (char): caracter que se añadirá a la cadena
 * @return FALLO si se pasa NULL como 'a', o si 'a' apunta a NULL, EXITO en caso contrario
 * @example string s = "asdf"; meterLetraEnCadena(s, "g"); // s = "asdfg";
 */
int meterLetraEnCadena(string *a, char b)
{
	string aux=NULL;
	int tam;
	if(a==NULL||*a==NULL) return FALLO;
	if(!strcmp(*a,"")){**a=b; return EXITO;}
	tam=strlen(*a);
	aux=malloc(sizeof(char)*(tam+1));
	strcpy(aux,*a);
	aux[tam]=b;
	aux[tam+1]='\0';
	*a=aux;
	return EXITO;
}

/**
 * Lee una matriz de enteros de tamaño dado por teclado
 * @param f (int): número de filas de la matriz
 * @param c (int): número de columnas de la matriz
 * @param s (string): cadena que se imprimirá por pantalla para pedir la matriz
 * @return la matriz obtenida
 * @example matriz mat = leerMatrizI(4, 2, "Introduce la matriz de 4 filas y 2 columnas: ");
 */
matriz leerMatrizI(int f, int c, string s)
{
	matriz mat; int i, j;

	if (NULL == (mat = malloc(f * sizeof(vector )))) return NULL;
	for (i = 0; i < f; i++) if (NULL == (mat[i] = malloc(c * sizeof(int)))) return NULL;

    println(s);
	if(f==1)
	{
		printf("Introduce la fila:\n");
		for (j = 0; j < c; j++) mat[0][j] = leer(mat[0][j], "");
		return mat;
	}
	for (i = 0; i < f; i++)
	{
		if (i) printf("Siguiente fila:\n");
		else printf("Primera fila:\n");
		for (j = 0; j < c; j++) mat[i][j] = leer(mat[i][j], "");
	}
	return mat;
}
/**
 * Lee una matriz objeto de enteros de tamaño dado por teclado
 * @param f (int): número de filas de la matriz
 * @param c (int): número de columnas de la matriz
 * @param s (string): cadena que se imprimirá por pantalla para pedir la matriz
 * @return la matriz objeto obtenida
 * @example tipoMatriz mat = leerMatrizI_O(4, 2, "Introduce la matriz de 4 filas y 2 columnas: ");
 */
tipoMatriz leerMatrizI_O(int f, int c, string s)
{
	int i, j;
	matriz mat; 
	tipoMatriz tMat;

	if (NULL == (mat = malloc(f * sizeof(vector )))) {
        tMat.matrix = NULL;
        tMat.filas = f;
        tMat.columnas = c;
        return tMat;
    }
    for (i = 0; i < f; i++) {
        if (NULL == (mat[i] = malloc(c * sizeof(int)))) {
            tMat.matrix = NULL;
            tMat.filas = f;
            tMat.columnas = c;
            return tMat;
        }
    }
    tMat.matrix = mat;
    tMat.filas = f;
    tMat.columnas = c;
	return tMat;
}

/**
 * Lee una matriz de reales de tamaño dado por teclado
 * @param f (int): número de filas de la matriz
 * @param c (int): número de columnas de la matriz
 * @param s (string): cadena que se imprimirá por pantalla para pedir la matriz
 * @return la matriz obtenida
 * @example matrizf mat = leerMatrizF(4, 2, "Introduce la matriz de 4 filas y 2 columnas: ");
 */
matrizf leerMatrizF(int f, int c, string s)
{
	matrizf mat; int i, j;

	if (NULL == (mat = malloc(f * sizeof(vectorf)))) return NULL;
	for (i = 0; i < f; i++) if (NULL == (mat[i] = malloc(c * sizeof(float)))) return NULL;

	println(s);
	if(f==1)
	{
		printf("Introduce la fila:\n");
		for (j = 0; j < c; j++) mat[0][j] = leer(mat[0][j], "");
		return mat;
	}
	for (i = 0; i < f; i++)
	{
		if (i) printf("Siguiente fila:\n");
		else printf("Primera fila:\n");
		for (j = 0; j < c; j++) mat[i][j] = leer(mat[i][j], "");
	}
	return mat;
}

/**
 * Lee una matriz objeto de reales de tamaño dado por teclado
 * @param f (int): número de filas de la matriz
 * @param c (int): número de columnas de la matriz
 * @param s (string): cadena que se imprimirá por pantalla para pedir la matriz
 * @return la matriz objeto obtenida
 * @example tipoMatrizf mat = leerMatrizF_O(4, 2, "Introduce la matriz de 4 filas y 2 columnas: ");
 */
tipoMatrizf leerMatrizF_O(int f, int c, string s)
{
	matrizf mat; int i, j;
	tipoMatrizf tMat;
	
	if (NULL == (mat = malloc(f * sizeof(vectorf)))) {
        tMat.matrix = NULL;
        tMat.filas = f;
        tMat.columnas = c;
        return tMat;
    }
    for (i = 0; i < f; i++) {
        if (NULL == (mat[i] = malloc(c * sizeof(float)))) {
            tMat.matrix = NULL;
            tMat.filas = f;
            tMat.columnas = c;
            return tMat;
        }
    }
    tMat.matrix = mat;
    tMat.filas = f;
    tMat.columnas = c;
	return tMat;
}

/**
 * Calcula una matriz de enteros aleatorios de tamaño dado
 * @param f (int): número de filas de la matriz
 * @param c (int): número de columnas de la matriz
 * @param a (int): límite inferior de los números que contendrá la matriz
 * @param b (int): límite superior de los números que contendrá la matriz
 * @return la matriz generada
 * @example matriz mat = generarMatrizI(4, 2, -9, 9); //matriz de 4 filas y 2 columnas con números de una cifra positivos y negativos
 */
matriz generarMatrizI(int f, int c, int a, int b)
{
	matriz mat; int i, j;
	if (NULL == (mat = malloc(f * sizeof(vector )))) return NULL;
	for (i = 0; i < f; i++) if (NULL == (mat[i] = malloc(c * sizeof(int)))) return NULL;
	if(a>b) { a=a+b; b=a-b; a=a-b; }
	srand(time(NULL));
	for(i=0; i<f; i++)
	    for(j=0; j<c; j++)
	        mat[i][j]=enteroAleatorioConSigno(a,b);
	return mat;
}
/**
 * Calcula una matriz objeto de enteros aleatorios de tamaño dado
 * @param f (int): número de filas de la matriz
 * @param c (int): número de columnas de la matriz
 * @param a (int): límite inferior de los números que contendrá la matriz
 * @param b (int): límite superior de los números que contendrá la matriz
 * @return la matriz objeto generada
 * @example tipoMatriz mat = generarMatrizI_O(4, 2, -9, 9); //matriz de 4 filas y 2 columnas con números de una cifra positivos y negativos
 */
tipoMatriz generarMatrizI_O(int f, int c, int a, int b)
{
	tipoMatriz tMat;
	tMat.filas=f;
	tMat.columnas=c;
	tMat.matrix=generarMatrizI(f,c,a,b);
	return tMat;
}

/**
 * Calcula una matriz de enteros aleatorios de tamaño dado
 * @param f (int): número de filas de la matriz
 * @param c (int): número de columnas de la matriz
 * @param a (float): límite inferior de los números que contendrá la matriz
 * @param b (float): límite superior de los números que contendrá la matriz
 * @param p (int): número de decimales de precisión de los números de la matriz ('2' serán centésimas, '3' serán milésimas, etc)
 * @return la matriz generada
 * @example matrizf mat = generarMatrizF(4, 2, -9.99, 9.99, 2); //matriz de 4 filas y 2 columnas con números reales de una cifra entera y 2 decimales
 */
matrizf generarMatrizF(int f, int c, float a, float b, int p)
{
	matrizf mat; int i, j;
	if (NULL == (mat = malloc(f * sizeof(vectorf )))) return NULL;
	for (i = 0; i < f; i++) if (NULL == (mat[i] = malloc(c * sizeof(float)))) return NULL;
	if(a>b) { a=a+b; b=a-b; a=a-b; }
    srand(time(NULL));
	for(i=0; i<f; i++)
	    for(j=0; j<c; j++)
	        mat[i][j]=aleatorioEntre2((double) a, (double) b, p);
	return mat;
}

/**
 * Calcula una matriz objeto de enteros aleatorios de tamaño dado
 * @param f (int): número de filas de la matriz
 * @param c (int): número de columnas de la matriz
 * @param a (float): límite inferior de los números que contendrá la matriz
 * @param b (float): límite superior de los números que contendrá la matriz
 * @param p (int): número de decimales de precisión de los números de la matriz ('2' serán centésimas, '3' serán milésimas, etc)
 * @return la matriz objeto generada
 * @example tipoMatrizf mat = generarMatrizF_O(4, 2, -9.99, 9.99, 2); //matriz de 4 filas y 2 columnas con números reales de una cifra entera y 2 decimales
 */
tipoMatrizf generarMatrizF_O(int f, int c, int a, int b, int p)
{
	tipoMatrizf tMat;
	tMat.filas=f;
	tMat.columnas=c;
	tMat.matrix=generarMatrizF(f,c,a,b,p);
	return tMat;
}

/**
 * Imprime por consola la matriz de enteros dada
 * @param mat (matriz): matriz a imprimir
 * @param f (int): número de filas de la matriz
 * @param c (int): número de columnas de la matriz
 * @return void
 */
void imprimirMatrizI(matriz  mat, int f, int c)
{
	int i, j;

	if (mat == NULL) return;
	for (i = 0; i < f; i++) if (mat[i]==NULL) return;

	for (i = 0; i < f; i++)
	{
		for (j = 0; j < c; j++) printf("%d\t", mat[i][j]);
		NUEVA_LINEA;
	}
}

/**
 * Imprime por consola la matriz objeto de enteros dada
 * @param mat (tipoMatriz): matriz a imprimir
 * @return void
 */
void imprimirMatrizI_O(tipoMatriz  mat)
{
	imprimirMatrizI(mat.matrix, mat.filas, mat.columnas);
}

/**
 * Imprime por consola la matriz de reales dada
 * @param mat (matrizf): matriz a imprimir
 * @param f (fl): número de filas de la matriz
 * @param c (int): número de columnas de la matriz
 * @return void
 */
void imprimirMatrizF(matrizf mat, int f, int c)
{
	int i, j;

	if (mat == NULL) return;
	for (i = 0; i < f; i++) if (mat[i] == NULL) return;

	for (i = 0; i < f; i++)
	{
		for (j = 0; j < c; j++) printf("%f\t", mat[i][j]);
		NUEVA_LINEA;
	}
}

/**
 * Imprime por consola la matriz objeto de reales dada
 * @param mat (tipoMatrizf): matriz a imprimir
 * @return void
 */
void imprimirMatrizF_O(tipoMatrizf mat)
{
	imprimirMatrizF(mat.matrix, mat.filas, mat.columnas);
}

/**
 * Calcula el producto matricial de dos matrices de enteros dadas
 * @param ma (matriz): matriz que servirá de primer operando
 * @param mb (matriz): matriz que servirá de segundo operando
 * @param a (int): número de filas del primer operando
 * @param bc (int): número de columnas del primer operando y filas del segundo
 * @param d (int): número de columnas del segundo operando
 * @return NULL si alguna de las matrices vale NULL, y la matriz producto final en caso contrario
 * @example matriz m = multiplicarMatrI(ma, mb, 3, 4, 5); // m = resultado de multiplicar una matriz 3x4 por una 4x5
 */
matriz  multiplicarMatrI(matriz  ma, matriz  mb, int a, int bc, int d)
{
	matriz  result; int i, j, k, suma;

	if (ma == NULL) return NULL;
	for (i = 0; i < a; i++) if (ma[i] == NULL) return NULL;

	if (mb == NULL) return NULL;
	for (i = 0; i < bc; i++) if (mb[i] == NULL) return NULL;

	if (NULL == (result = malloc(a * sizeof(vector )))) return NULL;
	for (i = 0; i < a; i++) if (NULL == (result[i] = malloc(d * sizeof(int)))) return NULL;

	for (i = 0; i < d; i++)
	{
		for (int j = 0; j < a; j++)
		{
			suma = 0;
			for (int k = 0; k < bc; k++)
				suma += ma[j][k] * mb[k][i];
			result[j][i] = suma;
		}
	}
	return result;
}

/**
 * Calcula el producto matricial de dos matrices objeto de enteros dadas
 * @param ma (tipoMatriz): matriz que servirá de primer operando
 * @param mb (tipoMatriz): matriz que servirá de segundo operando
 * @return la primera matriz si ocurre algún fallo durante la operación o si los operandos no son compatibles, y la matriz producto final en caso contrario
 * @example tipoMatriz m = multiplicarMatrI_O(ma, mb); // m = resultado de multiplicar ma por mb
 */
tipoMatriz multiplicarMatrI_O(tipoMatriz ma, tipoMatriz mb)
{
	tipoMatriz tMat;
	if(ma.columnas!=mb.filas) return ma;
	tMat.filas=ma.filas;
	tMat.columnas=mb.columnas;
	tMat.matrix= multiplicarMatrI(ma.matrix, mb.matrix, ma.filas, ma.columnas, mb.columnas);	
	if(tMat.matrix==NULL) return ma;
	return tMat;
}

/**
 * Calcula el producto matricial de dos matrices de reales dadas
 * @param ma (matrizf): matriz que servirá de primer operando
 * @param mb (matrizf): matriz que servirá de segundo operando
 * @param a (int): número de filas del primer operando
 * @param bc (int): número de columnas del primer operando y filas del segundo
 * @param d (int): número de columnas del segundo operando
 * @return NULL si alguna de las matrices vale NULL, y la matriz producto final en caso contrario
 * @example matrizf m = multiplicarMatrF(ma, mb, 3, 4, 5); // m = resultado de multiplicar una matriz 3x4 por una 4x5
 */
matrizf multiplicarMatrF(matrizf ma, matrizf mb, int a, int bc, int d)
{
	matrizf result; int i, j, k; float suma;

	if (ma == NULL) return NULL;
	for (i = 0; i < a; i++) if (ma[i] == NULL) return NULL;

	if (mb == NULL) return NULL;
	for (i = 0; i < bc; i++) if (mb[i] == NULL) return NULL;

	if (NULL == (result = malloc(a * sizeof(vectorf)))) return NULL;
	for (i = 0; i < a; i++) if (NULL == (result[i] = malloc(d * sizeof(float)))) return NULL;

	for (i = 0; i < d; i++)
	{
		for (int j = 0; j < a; j++)
		{
			suma = 0;
			for (int k = 0; k < bc; k++)
				suma += ma[j][k] * mb[k][i];
			result[j][i] = suma;
		}
	}
	return result;
}

/**
 * Calcula el producto matricial de dos matrices objeto de reales dadas
 * @param ma (tipoMatrizf): matriz que servirá de primer operando
 * @param mb (tipoMatrizf): matriz que servirá de segundo operando
 * @return la primera matriz si ocurre algún fallo durante la operación o si los operandos no son compatibles, y la matriz producto final en caso contrario
 * @example tipoMatrizf m = multiplicarMatrF_O(ma, mb); // m = resultado de multiplicar ma por mb
 */
tipoMatrizf multiplicarMatrF_O(tipoMatrizf ma, tipoMatrizf mb)
{
	tipoMatrizf tMat;
	if(ma.columnas!=mb.filas) return ma;
	tMat.filas=ma.filas;
	tMat.columnas=mb.columnas;
	tMat.matrix = multiplicarMatrF(ma.matrix, mb.matrix, ma.filas, ma.columnas, mb.columnas);	
	if(tMat.matrix==NULL) return ma;
	return tMat;
}

/**
 * Calcula la suma matricial de dos matrices de enteros dadas
 * @param ma (matriz): matriz que servirá de primer operando
 * @param mb (matriz): matriz que servirá de segundo operando
 * @param f (int): número de filas de los operandos
 * @param c (int): número de columnas de los operandos
 * @return NULL si alguna de las matrices vale NULL, y la matriz suma final en caso contrario
 * @example matriz m = sumarMatrI(ma, mb, 3, 2); // m = resultado de sumar dos matrices 3x2
 */
matriz  sumarMatrI(matriz  ma, matriz  mb, int f, int c)
{
	matriz  result; int i, j;

	if (ma == NULL) return NULL;
	for (i = 0; i < f; i++) if (ma[i] == NULL) return NULL;

	if (mb == NULL) return NULL;
	for (i = 0; i < f; i++) if (mb[i] == NULL) return NULL;

	if (NULL == (result = malloc(f * sizeof(vector )))) return NULL;
	for (i = 0; i < f; i++) if (NULL == (result[i] = malloc(c * sizeof(int)))) return NULL;

	for (i = 0; i < f; i++)
		for (int j = 0; j < c; j++)
			result[i][j] = ma[i][j] + mb[i][j];
	return result;
}

/**
 * Calcula la suma matricial de dos matrices objeto de enteros dadas
 * @param ma (tipoMatriz): matriz que servirá de primer operando
 * @param mb (tipoMatriz): matriz que servirá de segundo operando
 * @return la primera matriz si ocurre algún fallo durante la operación o si los operandos no son compatibles, y la matriz suma final en caso contrario
 * @example tipoMatriz m = sumarMatrI_O(ma, mb); // m = resultado de sumar mb a ma
 */
tipoMatriz sumarMatrI_O(tipoMatriz ma, tipoMatriz mb)
{
	tipoMatriz tMat;
	if(ma.columnas!=mb.columnas) return ma;
	if(ma.filas!=mb.filas) return ma;
	tMat.filas=ma.filas;
	tMat.columnas=ma.columnas;
    tMat.matrix=sumarMatrI(ma.matrix, mb.matrix, ma.filas, ma.columnas);
	if(tMat.matrix==NULL) return ma;
	return tMat;
}

/**
 * Calcula la suma matricial de dos matrices de reales dadas
 * @param ma (matrizf): matriz que servirá de primer operando
 * @param mb (matrizf): matriz que servirá de segundo operando
 * @param f (int): número de filas de los operandos
 * @param c (int): número de columnas de los operandos
 * @return NULL si alguna de las matrices vale NULL, y la matriz suma final en caso contrario
 * @example matrizf m = sumarMatrF(ma, mb, 3, 2); // m = resultado de sumar dos matrices 3x2
 */
matrizf sumarMatrF(matrizf ma, matrizf mb, int f, int c)
{
	matrizf result; int i, j;

	if (ma == NULL) return NULL;
	for (i = 0; i < f; i++) if (ma[i] == NULL) return NULL;

	if (mb == NULL) return NULL;
	for (i = 0; i < f; i++) if (mb[i] == NULL) return NULL;

	if (NULL == (result = malloc(f * sizeof(vectorf)))) return NULL;
	for (i = 0; i < f; i++) if (NULL == (result[i] = malloc(c * sizeof(float)))) return NULL;

	for (i = 0; i < f; i++)
		for (int j = 0; j < c; j++)
			result[i][j] = ma[i][j] + mb[i][j];
	return result;
}

/**
 * Calcula la suma matricial de dos matrices objeto de reales dadas
 * @param ma (tipoMatrizf): matriz que servirá de primer operando
 * @param mb (tipoMatrizf): matriz que servirá de segundo operando
 * @return la primera matriz si ocurre algún fallo durante la operación o si los operandos no son compatibles, y la matriz suma final en caso contrario
 * @example tipoMatrizf m = sumarMatrF_O(ma, mb); // m = resultado de sumar mb a ma
 */
tipoMatrizf sumarMatrF_O(tipoMatrizf ma, tipoMatrizf mb)
{
	tipoMatrizf tMat;
	if(ma.columnas!=mb.columnas) return ma;
	if(ma.filas!=mb.filas) return ma;
	tMat.filas=ma.filas;
	tMat.columnas=ma.columnas;
    tMat.matrix=sumarMatrF(ma.matrix, mb.matrix, ma.filas, ma.columnas);
	if(tMat.matrix==NULL) return ma;
	return tMat;
}

/**
 * Calcula la resta matricial de dos matrices de enteros dadas
 * @param ma (matriz): matriz que servirá de minuendo
 * @param mb (matriz): matriz que servirá de sustraendo
 * @param f (int): número de filas de los operandos
 * @param c (int): número de columnas de los operandos
 * @return NULL si alguna de las matrices vale NULL, y la matriz diferencia en caso contrario
 * @example matriz m = restarMatrI(ma, mb, 3, 2); // m = resultado de restar dos matrices 3x2
 */
matriz  restarMatrI(matriz  ma, matriz  mb, int f, int c)
{
	matriz  result; int i, j;

	if (ma == NULL) return NULL;
	for (i = 0; i < f; i++) if (ma[i] == NULL) return NULL;

	if (mb == NULL) return NULL;
	for (i = 0; i < f; i++) if (mb[i] == NULL) return NULL;

	if (NULL == (result = malloc(f * sizeof(vector )))) return NULL;
	for (i = 0; i < f; i++) if (NULL == (result[i] = malloc(c * sizeof(int)))) return NULL;

	for (i = 0; i < f; i++)
		for (int j = 0; j < c; j++)
			result[i][j] = ma[i][j] - mb[i][j];
	return result;
}

/**
 * Calcula la resta matricial de dos matrices objeto de enteros dadas
 * @param ma (tipoMatriz): matriz que servirá de minuendo
 * @param mb (tipoMatriz): matriz que servirá de sustraendo
 * @return la primera matriz si ocurre algún fallo durante la operación o si los operandos no son compatibles, y la matriz diferencia en caso contrario
 * @example tipoMatriz m = restarMatrI_O(ma, mb); // m = resultado de restar mb a ma
 */
tipoMatriz restarMatrI_O(tipoMatriz ma, tipoMatriz mb)
{
	tipoMatriz tMat;
	if(ma.columnas!=mb.columnas) return ma;
	if(ma.filas!=mb.filas) return ma;
	tMat.filas=ma.filas;
	tMat.columnas=ma.columnas;
    tMat.matrix=restarMatrI(ma.matrix, mb.matrix, ma.filas, ma.columnas);
	if(tMat.matrix==NULL) return ma;
	return tMat;
}

/**
 * Calcula la resta matricial de dos matrices de reales dadas
 * @param ma (matrizf): matriz que servirá de minuendo
 * @param mb (matrizf): matriz que servirá de sustraendo
 * @param f (int): número de filas de los operandos
 * @param c (int): número de columnas de los operandos
 * @return NULL si alguna de las matrices vale NULL, y la matriz diferencia en caso contrario
 * @example matrizf m = restarMatrF(ma, mb, 3, 2); // m = resultado de restar dos matrices 3x2
 */
matrizf restarMatrF(matrizf ma, matrizf mb, int f, int c)
{
	matrizf result; int i, j;

	if (ma == NULL) return NULL;
	for (i = 0; i < f; i++) if (ma[i] == NULL) return NULL;

	if (mb == NULL) return NULL;
	for (i = 0; i < f; i++) if (mb[i] == NULL) return NULL;

	if (NULL == (result = malloc(f * sizeof(vectorf)))) return NULL;
	for (i = 0; i < f; i++) if (NULL == (result[i] = malloc(c * sizeof(float)))) return NULL;

	for (i = 0; i < f; i++)
		for (int j = 0; j < c; j++)
			result[i][j] = ma[i][j] - mb[i][j];
	return result;
}

/**
 * Calcula la resta matricial de dos matrices objeto de reales dadas
 * @param ma (tipoMatrizf): matriz que servirá de minuendo
 * @param mb (tipoMatrizf): matriz que servirá de sustraendo
 * @return la primera matriz si ocurre algún fallo durante la operación o si los operandos no son compatibles, y la matriz diferencia en caso contrario
 * @example tipoMatrizf m = restarMatrF_O(ma, mb); // m = resultado de restar mb a ma
 */
tipoMatrizf restarMatrF_O(tipoMatrizf ma, tipoMatrizf mb)
{
	tipoMatrizf tMat;
	if(ma.columnas!=mb.columnas) return ma;
	if(ma.filas!=mb.filas) return ma;
	tMat.filas=ma.filas;
	tMat.columnas=ma.columnas;
    tMat.matrix=restarMatrF(ma.matrix, mb.matrix, ma.filas, ma.columnas);
	if(tMat.matrix==NULL) return ma;
	return tMat;
}

/**
 * Calcula el producto de una matriz dada por un producto escalar dado
 * @param a (int): escalar que se multiplicará a la matriz
 * @param mat (matriz): matriz a la que se multiplicará el escalar
 * @param f (int): número de filas de la matriz
 * @param c (int): número de columnas de la matriz
 * @return NULL si se pasa NULL como matriz, y el resultado final en caso contrario
 * @example matriz m = numPorMatrI(4, m, 3, 2); // multiplica la matriz 3x2 'm' por 4
 */
matriz numPorMatrI(int a, matriz mat, int f, int c)
{
	int i,j; matriz m;
	if (mat == NULL) return NULL;
	for (i = 0; i < f; i++) if (mat[i] == NULL) return NULL;
	if(NULL==(m=malloc(f*sizeof(vector)))) return NULL;
	for(i=0; i<f;i++) if(NULL==(m[i]=malloc(c*sizeof(int)))) return NULL;
	for(i=0; i<f; i++)
		for(j=0;j<c;j++)
			m[i][j]=mat[i][j]*a;
	return m;
}

/**
 * Calcula el producto de una matriz objeto dada por un producto escalar dado
 * @param a (int): escalar que se multiplicará a la matriz
 * @param mat (tipoMatriz): matriz objeto a la que se multiplicará el escalar
 * @return la matriz original si ocurre algún fallo durante la operación, y la matriz resutlado en caso contrario
 * @example tipoMatriz m = numPorMatrI_O(4, m,); // multiplica la matriz 'm' por 4
 */
tipoMatriz numPorMatrI_O(int a, tipoMatriz mat)
{
	tipoMatriz tMat;
	tMat.filas=mat.filas;
	tMat.columnas=mat.columnas;
	tMat.matrix=numPorMatrI(a,mat.matrix,mat.filas,mat.columnas);
	if(tMat.matrix==NULL) return mat;
	return tMat;
}

/**
 * Calcula el producto de una matriz de reales dada por un producto escalar dado
 * @param a (float): escalar que se multiplicará a la matriz
 * @param mat (matrizf): matriz a la que se multiplicará el escalar
 * @param f (int): número de filas de la matriz
 * @param c (int): número de columnas de la matriz
 * @return NULL si se pasa NULL como matriz, y el resultado final en caso contrario
 * @example matrizf m = numPorMatrF(4.0, m, 3, 2); // multiplica la matriz 3x2 'm' por 4
 */
matrizf numPorMatrF(float a, matrizf mat, int f, int c)
{
	int i,j; matrizf m;
	if (mat == NULL) return NULL;
	for (i = 0; i < f; i++) if (mat[i] == NULL) return NULL;
	if(NULL==(m=malloc(f*sizeof(vectorf)))) return NULL;
	for(i=0; i<f;i++) if(NULL==(m[i]=malloc(c*sizeof(float)))) return NULL;
	for(i=0; i<f; i++)
		for(j=0;j<c;j++)
			m[i][j]=mat[i][j]*a;
	return m;
}

/**
 * Calcula el producto de una matriz objeto de reales dada por un producto escalar dado
 * @param a (int): escalar que se multiplicará a la matriz
 * @param mat (tipoMatrizf): matriz objeto a la que se multiplicará el escalar
 * @return la matriz original si ocurre algún fallo durante la operación, y la matriz resutlado en caso contrario
 * @example tipoMatrizf m = numPorMatrF_O(4.0, m,); // multiplica la matriz 'm' por 4
 */
tipoMatrizf numPorMatrF_O(int a, tipoMatrizf mat)
{
	tipoMatrizf tMat;
	tMat.filas=mat.filas;
	tMat.columnas=mat.columnas;
	tMat.matrix=numPorMatrF(a,mat.matrix,mat.filas,mat.columnas);
	if(tMat.matrix==NULL) return mat;
	return tMat;
}

/**
 * Superpone dos matrices de enteros de forma que se obtiene una matriz final igual de alta y el doble de ancha
 * @param ma (matriz): matriz que quedará encima en la superposición
 * @param mb (matriz): matriz que quedará debajo en la superposición
 * @param ac (int): número de filas de ambas matrices
 * @param b (int): número de columnas de la primera matriz
 * @param d (int): número de columnas de la segunda matriz
 * @return NULL si se recibe NULL en alguno de los operandos, y la matriz [ma|mb] en caso contrario
 * @example matriz m = concatenarMatricesEnHorizontalI(ma, mb, 3, 6, 2) // m = matriz 3x6 concatenada horizontalmente con una matriz 3x2, quedará una 3x8
 */
matriz  concatenarMatricesEnHorizontalI(matriz  ma, matriz  mb, int ac, int b, int d)
{
	matriz  result; int i, j;

	if (ma == NULL) return NULL;
	for (i = 0; i < ac; i++) if (ma[i] == NULL) return NULL;

	if (mb == NULL) return NULL;
	for (i = 0; i < ac; i++) if (mb[i] == NULL) return NULL;

	if (NULL == (result = malloc(ac * sizeof(vector )))) return NULL;
	for (i = 0; i < ac; i++) if (NULL == (result[i] = malloc((b + d) * sizeof(int)))) return NULL;
	for (i = 0; i < ac; i++)
		for (j = 0; j < b; j++)
			result[i][j] = ma[i][j];
	for (i = 0; i < ac; i++)
		for (j = 0; j < d; j++)
			result[i][j + b] = mb[i][j];
	return result;
}

/**
 * Superpone dos matrices objeto de enteros de forma que se obtiene una matriz final igual de alta y el doble de ancha
 * @param ma (tipoMatriz): matriz objeto que quedará encima en la superposición
 * @param mb (tipoMatriz): matriz objeto que quedará debajo en la superposición
 * @return la primera matriz si se recibe NULL en alguno de los operandos o si las matrices no son compatibles, y la matriz [ma|mb] en caso contrario
 * @example tipoMatriz m = concatenarMatricesEnHorizontalI_O(ma, mb) // m = matrices ma y mb concatenadas horizontalmente
 */
tipoMatriz concatenarMatricesEnHorizontalI_O(tipoMatriz ma, tipoMatriz mb)
{
	tipoMatriz tMat;
	if(ma.filas!=mb.filas) return ma;
	tMat.filas=ma.filas;
	tMat.columnas=ma.columnas+mb.columnas;
	tMat.matrix=concatenarMatricesEnHorizontalI(ma.matrix, mb.matrix, ma.filas, ma.columnas, mb.columnas);
	if(tMat.matrix==NULL) return ma;
	return tMat;
}

/**
 * Superpone dos matrices de reales de forma que se obtiene una matriz final igual de alta y el doble de ancha
 * @param ma (matrizf): matriz que quedará encima en la superposición
 * @param mb (matrifz): matriz que quedará debajo en la superposición
 * @param ac (int): número de filas de ambas matrices
 * @param b (int): número de columnas de la primera matriz
 * @param d (int): número de columnas de la segunda matriz
 * @return NULL si se recibe NULL en alguno de los operandos, y la matriz [ma|mb] en caso contrario
 * @example matrizf m = concatenarMatricesEnHorizontalF(ma, mb, 3, 6, 2) // m = matriz 3x6 concatenada horizontalmente con una matriz 3x2, quedará una 3x8
 */
matrizf concatenarMatricesEnHorizontalF(matrizf ma, matrizf mb, int ac, int b, int d)
{
	matrizf result; int i, j;

	if (ma == NULL) return NULL;
	for (i = 0; i < ac; i++) if (ma[i] == NULL) return NULL;

	if (mb == NULL) return NULL;
	for (i = 0; i < ac; i++) if (mb[i] == NULL) return NULL;

	if (NULL == (result = malloc(ac * sizeof(vectorf)))) return NULL;
	for (i = 0; i < ac; i++) if (NULL == (result[i] = malloc((b + d) * sizeof(float)))) return NULL;
	for (i = 0; i < ac; i++)
		for (j = 0; j < b; j++)
			result[i][j] = ma[i][j];
	for (i = 0; i < ac; i++)
		for (j = 0; j < d; j++)
			result[i][j + b] = mb[i][j];
	return result;
}

/**
 * Superpone dos matrices objeto de enteros de forma que se obtiene una matriz final igual de alta y el doble de ancha
 * @param ma (tipoMatrizf): matriz objeto que quedará encima en la superposición
 * @param mb (tipoMatrizf): matriz objeto que quedará debajo en la superposición
 * @return la primera matriz si se recibe NULL en alguno de los operandos o si las matrices no son compatibles, y la matriz [ma|mb] en caso contrario
 * @example tipoMatrizf m = concatenarMatricesEnHorizontalF_O(ma, mb) // m = matrices ma y mb concatenadas horizontalmente
 */
tipoMatrizf concatenarMatricesEnHorizontalF_O(tipoMatrizf ma, tipoMatrizf mb)
{
	tipoMatrizf tMat;
	if(ma.filas!=mb.filas) return ma;
	tMat.filas=ma.filas;
	tMat.columnas=ma.columnas+mb.columnas;
	tMat.matrix=concatenarMatricesEnHorizontalF(ma.matrix, mb.matrix, ma.filas, ma.columnas, mb.columnas);
	if(tMat.matrix==NULL) return ma;
	return tMat;
}

/**
 * Superpone dos matrices objeto de enteros de forma que se obtiene una matriz final igual de ancha y el doble de alta
 * @param ma (matriz): matriz objeto que quedará a la izquierda en la superposición
 * @param mb (matriz): matriz objeto que quedará a la derecha en la superposición
 * @param a (int): número de filas de la primera matriz
 * @param c (int): número de filas de la segunda matriz
 * @param bd (int): número de columnas de ambas matrices
 * @return NULL si se recibe NULL en alguno de los operandos o si las matrices no son compatibles, y la matriz \
 * [ma] \
 * [--] \
 * [mb] en caso contrario.
 * @example matriz m = concatenarMatricesEnVerticalI(ma, mb, 3, 6, 2) // m = matriz 3x2 concatenada verticalmente con una matriz 6x2, quedará una 9x2
 */
matriz concatenarMatricesEnVerticalI(matriz ma, matriz mb, int a, int c, int bd)
{
	matriz  result; int i, j;

	if (ma == NULL) return NULL;
	for (i = 0; i < a; i++) if (ma[i] == NULL) return NULL;

	if (mb == NULL) return NULL;
	for (i = 0; i < c; i++) if (mb[i] == NULL) return NULL;

	if (NULL == (result = malloc((a+c) * sizeof(vector)))) return NULL;
	for (i = 0; i < (a+c); i++) if (NULL == (result[i] = malloc(bd * sizeof(int)))) return NULL;
	for (i = 0; i < a; i++)
		for (j = 0; j < bd; j++)
			result[i][j] = ma[i][j];
	for (i = 0; i < c; i++)
		for (j = 0; j < bd; j++)
			result[i + a][j] = mb[i][j];
	return result;
}

/**
 * Superpone dos matrices objeto de enteros de forma que se obtiene una matriz final igual de ancha y el doble de alta
 * @param ma (tipoMatriz): matriz objeto que quedará a la izquierda en la superposición
 * @param mb (tipoMatriz): matriz objeto que quedará a la derecha en la superposición
 * @return la primera matriz si se recibe NULL en alguno de los operandos o si las matrices no son compatibles, y la matriz \
 * [ma] \
 * [--] \
 * [mb] en caso contrario.
 * @example tipoMatriz m = concatenarMatricesEnVerticalI_O(ma, mb) // m = matrices ma y mb concatenadas verticalmente
 */
tipoMatriz concatenarMatricesEnVerticalI_O(tipoMatriz ma, tipoMatriz mb)
{
	tipoMatriz tMat;
	if(ma.columnas!=mb.columnas) return ma;
	tMat.filas=ma.filas+mb.filas;
	tMat.columnas=ma.columnas;
	tMat.matrix=concatenarMatricesEnVerticalI(ma.matrix, mb.matrix, ma.filas, mb.filas, mb.columnas);
	if(tMat.matrix==NULL) return ma;
	return tMat;
}

/**
 * Superpone dos matrices objeto de reales de forma que se obtiene una matriz final igual de ancha y el doble de alta
 * @param ma (matrizf): matriz objeto que quedará a la izquierda en la superposición
 * @param mb (matrizf): matriz objeto que quedará a la derecha en la superposición
 * @param a (int): número de filas de la primera matriz
 * @param c (int): número de filas de la segunda matriz
 * @param bd (int): número de columnas de ambas matrices
 * @return NULL si se recibe NULL en alguno de los operandos o si las matrices no son compatibles, y la matriz \
 * [ma] \
 * [--] \
 * [mb] en caso contrario.
 * @example matrizf m = concatenarMatricesEnVerticalF(ma, mb, 3, 6, 2) // m = matriz 3x2 concatenada verticalmente con una matriz 6x2, quedará una 9x2
 */
matrizf concatenarMatricesEnVerticalF(matrizf ma, matrizf mb, int a, int c, int bd)
{
	matrizf result; int i, j;

	if (ma == NULL) return NULL;
	for (i = 0; i < a; i++) if (ma[i] == NULL) return NULL;

	if (mb == NULL) return NULL;
	for (i = 0; i < c; i++) if (mb[i] == NULL) return NULL;

	if (NULL == (result = malloc((a+c) * sizeof(vectorf)))) return NULL;
	for (i = 0; i < (a+c); i++) if (NULL == (result[i] = malloc(bd * sizeof(float)))) return NULL;
	for (i = 0; i < a; i++)
		for (j = 0; j < bd; j++)
			result[i][j] = ma[i][j];
	for (i = 0; i < c; i++)
		for (j = 0; j < bd; j++)
			result[i + a][j] = mb[i][j];
	return result;
}

/**
 * Superpone dos matrices objeto de reales de forma que se obtiene una matriz final igual de ancha y el doble de alta
 * @param ma (tipoMatrizf): matriz objeto que quedará a la izquierda en la superposición
 * @param mb (tipoMatrizf): matriz objeto que quedará a la derecha en la superposición
 * @return NULL si se recibe NULL en alguno de los operandos o si las matrices no son compatibles, y la matriz \
 * [ma] \
 * [--] \
 * [mb] en caso contrario.
 * @example tipoMatrizf m = concatenarMatricesEnVerticalF_O(ma, mb) // m = matrices ma y mb concatenadas verticalmente
 */
tipoMatrizf concatenarMatricesEnVerticalF_O(tipoMatrizf ma, tipoMatrizf mb)
{
    tipoMatrizf tMat;
	if(ma.columnas!=mb.columnas) return ma;
	tMat.filas=ma.filas+mb.filas;
	tMat.columnas=ma.columnas;
    tMat.matrix=concatenarMatricesEnVerticalF(ma.matrix, mb.matrix, ma.filas, mb.filas, mb.columnas);
	if(tMat.matrix==NULL) return ma;
	return tMat;
}

/**
 * Lee un vector de enteros de tamaño dado por teclado
 * @param n (int): número de elementos del vector
 * @param s (string): cadena que se imprimirá por pantalla para pedir la matriz
 * @return el vector obtenido
 * @example vector vec = leerVectorI(4, "Introduce los 4 elementos del vector: ");
 */
vector leerVectorI(int n, string s)
{
	matriz aux;
	aux = leerMatrizI(1, n, s);
	return *aux;
}

/**
 * Lee un vector de reales de tamaño dado por teclado
 * @param n (int): número de elementos del vector
 * @param s (string): cadena que se imprimirá por pantalla para pedir la matriz
 * @return el vector obtenido
 * @example vectorf vec = leerVectorF(4, "Introduce los 4 elementos del vector: ");
 */
vectorf leerVectorF(int n, string s)
{
	matrizf aux;
	aux = leerMatrizF(1, n, s);
	return *aux;
}

/**
 * Imprime un vector de enteros de tamaño dado por consola
 * @param vec (vector): referencia del vector que se va a imprimir
 * @param n (int): número de elementos del vector
 * @return void
 */
void imprimirVectorI(vector vec, int n)
{
	int i; 
	if (vec == NULL) return; 
	for (i = 0; i < n; i++) printf("%d\t", vec[i]);
}

/**
 * Imprime un vector de reales de tamaño dado por consola
 * @param vec (vectorf): referencia del vector que se va a imprimir
 * @param n (int): número de elementos del vector
 * @return void
 */
void imprimirVectorF(vectorf vec, int n)
{
	int i;
	if (vec == NULL) return; 
	for (i = 0; i < n; i++) printf("%f\t", vec[i]);
}

/**
 * Calcula el producto escalar de dos vectores de enteros dados
 * @param va (vector): referencia del primer vector del producto
 * @param vb (vector): referencia del segundo vector del producto
 * @param n (int): número de elementos de los vectores
 * @return el resultado de la operación
 * @example int a = productoEscalarI(va, vb, 7); // a = producto escalar entre dos vectores de 7 elementos
 */
int  productoEscalarI(vector  va, vector  vb, int n)
{
	int result = 0, i;
	for (i = 0; i < n; i++) result += va[i] * vb[i];
	return result;
}

/**
 * Calcula el producto escalar de dos vectores de reales dados
 * @param va (vectorf): referencia del primer vector del producto
 * @param vb (vectorf): referencia del segundo vector del producto
 * @param n (int): número de elementos de los vectores
 * @return el resultado de la operación
 * @example float a = productoEscalarF(va, vb, 7); // a = producto escalar entre dos vectores de 7 elementos
 */
float  productoEscalarF(vectorf va, vectorf vb, int n)
{
	float result = 0;int i;
	for (i = 0; i < n; i++) result += va[i] * vb[i];
	return result;
}

/**
 * Calcula el producto vectorial de dos vectores de enteros dados
 * @param va (vector): referencia del primer vector del producto
 * @param vb (vector): referencia del segundo vector del producto
 * @return el vector resultado de la operación
 * @example vector a = productoVectorialI(va, vb); // a = vector de 3 elementos resultado del producto vectorial entre dos vectores de 3 elementos
 */
vector  productoVectorialI(vector  a, vector  b)
{
	vector  resul;
	if (a == NULL || b == NULL) return NULL;
	if (NULL == (resul = malloc(3 * sizeof(int)))) return NULL;
	resul[0] = a[1] * b[2] - a[2] * b[1];
	resul[1] = b[0] * a[2] - b[2] * a[0];
	resul[2] = a[0] * b[1] - a[1] * b[0];
	return resul;
}

/**
 * Calcula el producto vectorial de dos vectores de reales dados
 * @param va (vectorf): referencia del primer vector del producto
 * @param vb (vectorf): referencia del segundo vector del producto
 * @return el vector resultado de la operación
 * @example vectorf a = productoVectorialF(va, vb); // a = vector de 3 elementos resultado del producto vectorial entre dos vectores de 3 elementos
 */
vectorf productoVectorialF(vectorf a, vectorf b)
{
	vectorf resul;
	if (a == NULL || b == NULL) return NULL;
	if (NULL == (resul = malloc(3 * sizeof(float)))) return NULL;
	resul[0] = a[1] * b[2] - a[2] * b[1];
	resul[1] = b[0] * a[2] - b[2] * a[0];
	resul[2] = a[0] * b[1] - a[1] * b[0];
	return resul;
}

/**
 * Calcula el determinante de una matriz cuadrada de enteros dada
 * @param m (matriz): matriz cuyo determinante se calculará
 * @param n (orden): número de filas y columnas de la matriz
 * @return -INF si se da un error durante la operación, el resultado de la operación en caso contrario
 * @example int a = determinanteI(m, 8); // a = determinante de la matriz cuadrada de orden 8 'm'
 */
int determinanteI(matriz m, int orden)
{
	int i,j,k, factor=1, det=0; matriz nuevam;
    if(m==NULL) return -1;
	if (orden==1) return **m;
	
    for(i=0;i<orden;i++) 
	{
		if(NULL == (nuevam = malloc((orden-1) * sizeof(vector)))) return -INF;
		for(j=0;j<orden-1;j++) if (NULL == (nuevam[j] = malloc((orden-1) * sizeof(int)))) return -INF;
		
        for(j=1;j<orden;j++)
        {
            for (k=0;k<orden;k++)
            {
                if(k==i) continue;
                nuevam[j-1][k<i?k:(k-1)]=m[j][k];
            }
        }
        det+= factor*m[0][i]*determinanteI(nuevam, orden-1);
        factor*=-1;
		
		for(j=0;j<orden-1;j++) free(nuevam[j]);
		free(nuevam);
    }
	
    return det;
}

/**
 * Calcula el determinante de una matriz cuadrada de enteros dada
 * @param m (tipoMatriz): matriz cuyo determinante se calculará
 * @return -INF si se da un error durante la operación o si la matriz no es cuadrada, y el resultado de la operación en caso contrario
 * @example int a = determinanteI_O(m); // a = determinante de la matriz cuadrada 'm'
 */
int determinanteI_O(tipoMatriz m) 
{
	if(m.filas!=m.columnas) return -INF;
	return determinanteI(m.matrix, m.filas);
}

/**
 * Calcula el determinante de una matriz cuadrada de reales dada
 * @param m (matrizf): matriz cuyo determinante se calculará
 * @param n (orden): número de filas y columnas de la matriz
 * @return -INF si se da un error durante la operación, el resultado de la operación en caso contrario
 * @example float a = determinanteF(m, 8); // a = determinante de la matriz cuadrada de orden 8 'm'
 */
float determinanteF(matrizf m, int orden)
{
	int i,j,k;
	float factor=1, det=0;
	matrizf nuevam;
    if(m==NULL) return -1.0;
	if (orden==1) return **m;
	
    for(i=0; i<orden; i++) 
	{
		if(NULL == (nuevam = malloc((orden-1) * sizeof(vectorf )))) return -INF;
		for(j=0;j<orden-1;j++) if (NULL == (nuevam[j] = malloc((orden-1) * sizeof(float)))) return -INF;
		
        for(j=1;j<orden;j++)
        {
            for (k=0;k<orden;k++)
            {
                if(k==i) continue;
                nuevam[j-1][k<i?k:(k-1)]=m[j][k];
            }
        }
        det+= factor*m[0][i]*determinanteF(nuevam, orden-1);
        factor*=-1;
		
		for(j=0;j<orden-1;j++) free(nuevam[j]);
		free(nuevam);
    }
	
    return det;
}

/**
 * Calcula el determinante de una matriz cuadrada de reales dada
 * @param m (tipoMatrizf): matriz cuyo determinante se calculará
 * @return -INF si se da un error durante la operación o si la matriz no es cuadrada, y el resultado de la operación en caso contrario
 * @example float a = determinanteF_O(m); // a = determinante de la matriz cuadrada 'm'
 */
float determinanteF_O(tipoMatrizf m) 
{
	if(m.filas!=m.columnas) return -INF;
	return determinanteF(m.matrix, m.filas);
}

/**
 * Concatena dos vectores de enteros dados
 * @param va (vector): vector que quedará a la izquierda en la concatenación
 * @param vb (vector): vector que quedará a la derecha en la concatenación
 * @return NULL si alguno de los vectores en NULL, el vector concatenado en caso contrario
 * @example vector vc = concatenarVectoresI(va, vb, 3, 2); // vc = concatenación del vector de 3 elementos 'va' y el vector de 2 elementos 'vb', tendrá 5 elementos
 */
vector  concatenarVectoresI(vector  va, vector  vb, int n, int m)
{
	int i; matriz  aux;
	if (va == NULL || vb == NULL) return NULL;
	aux = concatenarMatricesEnHorizontalI(&va, &vb, 1, n, m);
	return *aux;
}

/**
 * Concatena dos vectores de reales dados
 * @param va (vectorf): vector que quedará a la izquierda en la concatenación
 * @param vb (vectorf): vector que quedará a la derecha en la concatenación
 * @return NULL si alguno de los vectores en NULL, el vector concatenado en caso contrario
 * @example vectorf vc = concatenarVectoresF(va, vb, 3, 2); // vc = concatenación del vector de 3 elementos 'va' y el vector de 2 elementos 'vb', tendrá 5 elementos
 */
vectorf concatenarVectoresF(vectorf va, vectorf vb, int n, int m)
{
	int i; matrizf aux;
	if (va == NULL || vb == NULL) return NULL;
	aux = concatenarMatricesEnHorizontalF(&va, &vb, 1, n, m);
	return *aux;
}

nodo* creaNodo(tipoInfo info)
{
	nodo* n;
	if (NULL == (n = malloc(sizeof(nodo)))) return NULL;
	n->info = info;
	n->sig = NULL;
	return n;
} //Crea una lista con un solo nodo

nodo* creaNodo2(tipoInfo2 info)
{
	nodo* n;
	if (NULL == (n = malloc(sizeof(nodo)))) return NULL;
	n->info2 = info;
	n->sig = NULL;
	return n;
} //Crea una lista con un solo nodo

nodo* creaNodo3(tipoInfo3 info)
{
	nodo* n;
	if (NULL == (n = malloc(sizeof(nodo)))) return NULL;
	n->info3 = info;
	n->sig = NULL;
	return n;
} //Crea una lista con un solo nodo

nodo* creaNodoI(int info)
{
	nodo* n;
	if (NULL == (n = malloc(sizeof(nodo)))) return NULL;
	n->info4 = info;
	n->sig = NULL;
	return n;
} //Crea una lista con un solo nodo

nodo* creaNodoF(float info)
{
	nodo* n;
	if (NULL == (n = malloc(sizeof(nodo)))) return NULL;
	n->info5 = info;
	n->sig = NULL;
	return n;
} //Crea una lista con un solo nodo

int annadirPrincipio(lista* list, tipoInfo info)
{
	nodo* aux, * nod;
	nod = creaNodo(info);
	if (list == NULL || nod == NULL) return FALLO;
	if (*list == NULL) { *list = nod; return EXITO; }
	aux = *list;
	*list = nod;
	(*list)->sig = aux;
	return EXITO;
}

int annadirPrincipio2(lista* list, tipoInfo2 info)
{
	nodo* aux, * nod;
	nod = creaNodo2(info);
	if (list == NULL || nod == NULL) return FALLO;
	if (*list == NULL) { *list = nod; return EXITO; }
	aux = *list;
	*list = nod;
	(*list)->sig = aux;
	return EXITO;
}

int annadirPrincipio3(lista* list, tipoInfo3 info)
{
	nodo* aux, * nod;
	nod = creaNodo3(info);
	if (list == NULL || nod == NULL) return FALLO;
	if (*list == NULL) { *list = nod; return EXITO; }
	aux = *list;
	*list = nod;
	(*list)->sig = aux;
	return EXITO;
}

int annadirPrincipioI(lista* list, int info)
{
	nodo* aux, * nod;
	nod = creaNodoI(info);
	if (list == NULL || nod == NULL) return FALLO;
	if (*list == NULL) { *list = nod; return EXITO; }
	aux = *list;
	*list = nod;
	(*list)->sig = aux;
	return EXITO;
}

int annadirPrincipioF(lista* list, float info)
{
	nodo* aux, * nod;
	nod = creaNodoF(info);
	if (list == NULL || nod == NULL) return FALLO;
	if (*list == NULL) { *list = nod; return EXITO; }
	aux = *list;
	*list = nod;
	(*list)->sig = aux;
	return EXITO;
}

int annadirFinal(lista* list, tipoInfo info)
{
	nodo* aux, * nod;
	nod = creaNodo(info);
	if (list == NULL || nod == NULL) return FALLO;
	if (*list == NULL) { *list = nod; return EXITO; }
	aux = *list;
	while (aux->sig != NULL) aux = aux->sig;
	aux->sig = nod;
	return EXITO;
}

int annadirFinal2(lista* list, tipoInfo2 info)
{
	nodo* aux, * nod;
	nod = creaNodo2(info);
	if (list == NULL || nod == NULL) return FALLO;
	if (*list == NULL) { *list = nod; return EXITO; }
	aux = *list;
	while (aux->sig != NULL) aux = aux->sig;
	aux->sig = nod;
	return EXITO;
}

int annadirFinal3(lista* list, tipoInfo3 info)
{
	nodo* aux, * nod;
	nod = creaNodo3(info);
	if (list == NULL || nod == NULL) return FALLO;
	if (*list == NULL) { *list = nod; return EXITO; }
	aux = *list;
	while (aux->sig != NULL) aux = aux->sig;
	aux->sig = nod;
	return EXITO;
}

int annadirFinalI(lista* list, int info)
{
	nodo* aux, * nod;
	nod = creaNodoI(info);
	if (list == NULL || nod == NULL) return FALLO;
	if (*list == NULL) { *list = nod; return EXITO; }
	aux = *list;
	while (aux->sig != NULL) aux = aux->sig;
	aux->sig = nod;
	return EXITO;
}

int annadirFinalF(lista* list, float info)
{
	nodo* aux, * nod;
	nod = creaNodoF(info);
	if (list == NULL || nod == NULL) return FALLO;
	if (*list == NULL) { *list = nod; return EXITO; }
	aux = *list;
	while (aux->sig != NULL) aux = aux->sig;
	aux->sig = nod;
	return EXITO;
}

int annadirEnMedio(lista* list, int i, tipoInfo info)
{
	nodo* aux, * ant, * p; int j = 0;
	p = creaNodo(info);
	if (list == NULL || p == NULL) return FALLO;
	if (*list == NULL) { *list = p; return EXITO; }
	if (i <= 0) return annadirPrincipio(list, info);
	if (i >= tamannoDeLaLista(**list)) return annadirFinal(list, info);
	aux = *list;
	while (j < i)
	{
		ant = aux;
		aux = aux->sig;
		j++;
	}
	ant->sig = p;
	p->sig = aux;
	return EXITO;
}

int annadirEnMedio2(lista* list, int i, tipoInfo2 info)
{
	nodo* aux, * ant, * p; int j = 0;
	p = creaNodo2(info);
	if (list == NULL || p == NULL) return FALLO;
	if (*list == NULL) { *list = p; return EXITO; }
	if (i <= 0) return annadirPrincipio2(list, info);
	if (i >= tamannoDeLaLista(**list)) return annadirFinal2(list, info);
	aux = *list;
	while (j < i)
	{
		ant = aux;
		aux = aux->sig;
		j++;
	}
	ant->sig = p;
	p->sig = aux;
	return EXITO;
}

int annadirEnMedio3(lista* list, int i, tipoInfo3 info)
{
	nodo* aux, * ant, * p; int j = 0;
	p = creaNodo3(info);
	if (list == NULL || p == NULL) return FALLO;
	if (*list == NULL) { *list = p; return EXITO; }
	if (i <= 0) return annadirPrincipio3(list, info);
	if (i >= tamannoDeLaLista(**list)) return annadirFinal3(list, info);
	aux = *list;
	while (j < i)
	{
		ant = aux;
		aux = aux->sig;
		j++;
	}
	ant->sig = p;
	p->sig = aux;
	return EXITO;
}

int annadirEnMedioI(lista* list, int i, int info)
{
	nodo* aux, * ant, * p; int j = 0;
	p = creaNodoI(info);
	if (list == NULL || p == NULL) return FALLO;
	if (*list == NULL) { *list = p; return EXITO; }
	if (i <= 0) return annadirPrincipioI(list, info);
	if (i >= tamannoDeLaLista(**list)) return annadirFinalI(list, info);
	aux = *list;
	while (j < i)
	{
		ant = aux;
		aux = aux->sig;
		j++;
	}
	ant->sig = p;
	p->sig = aux;
	return EXITO;
}

int annadirEnMedioF(lista* list, int i, float info)
{
	nodo* aux, * ant, * p; int j = 0;
	p = creaNodoF(info);
	if (list == NULL || p == NULL) return FALLO;
	if (*list == NULL) { *list = p; return EXITO; }
	if (i <= 0) return annadirPrincipioF(list, info);
	if (i >= tamannoDeLaLista(**list)) return annadirFinalF(list, info);
	aux = *list;
	while (j < i)
	{
		ant = aux;
		aux = aux->sig;
		j++;
	}
	ant->sig = p;
	p->sig = aux;
	return EXITO;
}

void verLista(nodo n)
{
	NUEVA_LINEA;
	printf("[");
	while (n.sig != NULL)
	{
		print(n.info);
		printf(", ");
		n = *n.sig;
	}
	print(n.info);
	printf("]");
	NUEVA_LINEA;
}

void verLista2(nodo n)
{
	NUEVA_LINEA;
	print("[");
	while (n.sig != NULL)
	{
		print(n.info2);
		print(", ");
		n = *(n.sig);
	}
	print(n.info2);
	print("]");
	NUEVA_LINEA;
}

void verLista3(nodo n)
{
	NUEVA_LINEA;
	printf("[");
	while (n.sig != NULL)
	{
		print(n.info3);
		printf(", ");
		n = *(n.sig);
	}
	print(n.info3);
	printf("]");
	NUEVA_LINEA;
}

void verListaI(nodo n)
{
	NUEVA_LINEA;
	printf("[");
	while (n.sig != NULL)
	{
		printf("%d, ", n.info4);
		n = *(n.sig);
	}
	printf("%d]", n.info4);
}

void verListaF(nodo n)
{
	NUEVA_LINEA;
	printf("[");
	while (n.sig != NULL)
	{
		printf("%f, ", n.info5);
		n = *(n.sig);
	}
	printf("%f]", n.info5);
}


int borrarPrincipio(lista *list)
{
		nodo *aux;
        if(list ==NULL) return FALLO;
        if(*list==NULL) return SUPERFALLO;
		aux=*list;
		*list=(*list)->sig;
		free(aux);
		return EXITO;
}

int borrarFinal(lista *list)
{
		nodo *aux, *ant;
        if(list ==NULL) return FALLO;
        if(*list==NULL) return FALLO;
		aux=*list;
		while(aux->sig!=NULL){ant=aux;aux=aux->sig;}
		ant->sig=NULL;
		free(aux);
		return EXITO;
}

int borrarValor(lista* list, tipoInfo info)
{
	nodo* aux, * ant; tipoInfo n;
	if (list == NULL) return FALLO;
	if (*list == NULL) return FALLO;
	aux = *list;
	n = (*list)->info;
	while (n != info && aux->sig != NULL)
	{
		ant = aux;
		aux = aux->sig;
		if (aux != NULL) n = aux->info;
	}
	if (aux->info != info) return SUPERFALLO;
	ant->sig = aux->sig;
	free(aux);
	return EXITO;
} //Borra el PRIMER nodo que encuentre en la lista con el valor dado

int borrarValor2(lista* list, tipoInfo2 info)
{
	nodo* aux, * ant; tipoInfo2 n;
	if (list == NULL) return FALLO;
	if (*list == NULL) return FALLO;
	aux = *list;
	n = (*list)->info2;
	while (n != info && aux->sig != NULL)
	{
		ant = aux;
		aux = aux->sig;
		if (aux != NULL) n = aux->info2;
	}
	if (aux->info2 != info) return SUPERFALLO;
	ant->sig = aux->sig;
	free(aux);
	return EXITO;
} //Borra el PRIMER nodo que encuentre en la lista con el valor dado

int borrarValor3(lista* list, tipoInfo3 info)
{
	nodo* aux, * ant; tipoInfo3 n;
	if (list == NULL) return FALLO;
	if (*list == NULL) return FALLO;
	aux = *list;
	n = (*list)->info3;
	while (n != info && aux->sig != NULL)
	{
		ant = aux;
		aux = aux->sig;
		if (aux != NULL) n = aux->info3;
	}
	if (aux->info3 != info) return SUPERFALLO;
	ant->sig = aux->sig;
	free(aux);
	return EXITO;
} //Borra el PRIMER nodo que encuentre en la lista con el valor dado

int borrarValorI(lista* list, int info)
{
	nodo* aux, * ant; int n;
	if (list == NULL) return FALLO;
	if (*list == NULL) return FALLO;
	aux = *list;
	n = (*list)->info4;
	while (n != info && aux->sig != NULL)
	{
		ant = aux;
		aux = aux->sig;
		if (aux != NULL) n = aux->info4;
	}
	if (aux->info4 != info) return SUPERFALLO;
	ant->sig = aux->sig;
	free(aux);
	return EXITO;
} //Borra el PRIMER nodo que encuentre en la lista con el valor dado

int borrarValorF(lista* list, float info)
{
	nodo* aux, * ant; float n;
	if (list == NULL) return FALLO;
	if (*list == NULL) return FALLO;
	aux = *list;
	n = (*list)->info5;
	while (n != info && aux->sig != NULL)
	{
		ant = aux;
		aux = aux->sig;
		if (aux != NULL) n = aux->info5;
	}
	if (aux->info5 != info) return SUPERFALLO;
	ant->sig = aux->sig;
	free(aux);
	return EXITO;
} //Borra el PRIMER nodo que encuentre en la lista con el valor dado

int modificarValor(lista* list, tipoInfo info1, tipoInfo info2)
{
	nodo* aux;
	if (list == NULL) return FALLO;
	if (*list == NULL) return FALLO;
	aux = *list;
	while (aux != NULL && aux->info != info1) aux = aux->sig;
	if (aux == NULL) return SUPERFALLO;
	aux->info = info2;
	return EXITO;
} //Modifica el PRIMER nodo que encuentre en la lista con i1, a i2

int modificarValor2(lista* list,  tipoInfo2 info1, tipoInfo2 info2)
{
	nodo* aux;
	if (list == NULL) return FALLO;
	if (*list == NULL) return FALLO;
	aux = *list;
	while (aux != NULL && aux->info2 != info1) aux = aux->sig;
	if (aux == NULL) return SUPERFALLO;
	aux->info2 = info2;
	return EXITO;
} //Modifica el PRIMER nodo que encuentre en la lista con i1, a i2

int modificarValor3(lista* list, tipoInfo3 info1, tipoInfo3 info2)
{
	nodo* aux;
	if (list == NULL) return FALLO;
	if (*list == NULL) return FALLO;
	aux = *list;
	while (aux != NULL && aux->info3 != info1) aux = aux->sig;
	if (aux == NULL) return SUPERFALLO;
	aux->info3 = info2;
	return EXITO;
} //Modifica el PRIMER nodo que encuentre en la lista con i1, a i2

int modificarValorI(lista* list,  int info1, int info2)
{
	nodo* aux;
	if (list == NULL) return FALLO;
	if (*list == NULL) return FALLO;
	aux = *list;
	while (aux != NULL && aux->info4 != info1) aux = aux->sig;
	if (aux == NULL) return SUPERFALLO;
	aux->info4 = info2;
	return EXITO;
} //Modifica el PRIMER nodo que encuentre en la lista con i1, a i2

int modificarValorF(lista* list,  float info1, float info2)
{
	nodo* aux;
	if (list == NULL) return FALLO;
	if (*list == NULL) return FALLO;
	aux = *list;
	while (aux != NULL && aux->info5 != info1) aux = aux->sig;
	if (aux == NULL) return SUPERFALLO;
	aux->info5 = info2;
	return EXITO;
} //Modifica el PRIMER nodo que encuentre en la lista con i1, a i2

int vaciarLista(lista *l)
{
	if (l == NULL) return FALLO;
	if (*l == NULL) return FALLO;
	while(estaVacia(*l)==FALSE)
		if(borrarPrincipio(l))
					return FALLO;
	return EXITO;
}

int tamannoDeLaLista(nodo n)
{
        int i=1;
        while(n.sig!=NULL)
        {
			i++;
			n=*(n.sig);
        }
        return i;
}

boolean estaVacia(lista list) {return (list==NULL)?TRUE:FALSE;}

/**
 * Inicializa todos los campos internos de la lista enlazada. La lista enlazada no podrá usarse correctamente si esta función no es invocada.
 * @param tipo (tipoLista ref): lista que se va a inicializar
 * @return void
 * @example tipoLista tl; inicializarTipoLista(&tl);
 */
void inicializarTipoLista(tipoLista *tipo)
{
	if(tipo==NULL) return;
	tipo->lst = NULL;
	tipo->numElementos = 0;
	tipo->vacia = TRUE;
	tipo->borrarPpio = &borrarPpio;
	tipo->borrarFin = &borrarFin;
	tipo->vaciarLaLista = &vaciarLaLista;
	tipo->annadirPPio=NULL;
	tipo->annadirFin=NULL;
	tipo->annadirEnLugar=NULL;
	tipo->mostrarLista=NULL;
	tipo->borrarElValor=NULL;
	tipo->modificarElValor=NULL;
}

/**
 * Reinicializa todos los campos internos de la lista enlazada que ya ha sido utilizada. Es más eficiente que volver a invocar inicializarTipoLista
 * @param tipo (tipoLista ref): lista que se va a reinicializar
 * @return void
 * @example tipoLista tl; inicializarTipoLista(&tl); /-*operaciones*-/; reinicializarTipoLista(&tl);
 */
void reinicializarTipoLista(tipoLista *tipo)
{
	if(tipo==NULL) return;
	if (tipo->lst != NULL) vaciarLista(&(tipo->lst));
	tipo->lst = NULL;
	tipo->numElementos = 0;
	tipo->vacia = TRUE;
}


void mostrarLista(tipoLista* tipo)
{
	verLista(*(tipo->lst));
}

void mostrarLista2(tipoLista* tipo)
{
	verLista2(*(tipo->lst));
}

void mostrarLista3(tipoLista* tipo)
{
	verLista3(*(tipo->lst));
}

void mostrarListaI(tipoLista* tipo)
{
	verListaI(*(tipo->lst));
}

void mostrarListaF(tipoLista* tipo)
{
	verListaF(*(tipo->lst));
}

/**
 * coloca el tipo tipoInfo en la lista enlazada, el que se haya definido, y, si no se ha definido ninguno, será int por defecto
 * @param tipo (tipoLista ref): lista en la que se va a colocar el tipo tipoInfo
 * @return void
 * @example tipoLista tl; inicializarTipoLista(&tl); colocarTipoInfoEnLista(&tl);
 */
void colocarTipoInfoEnLista(tipoLista *tipo)
{
	if(tipo==NULL) return;
	tipo->annadirPPio = &annadirPPio;
	tipo->annadirFin = &annadirFin;
	tipo->annadirEnLugar = &annadirEnLugar;
	tipo->mostrarLista = &mostrarLista;
	tipo->borrarElValor = &borrarElValor;
	tipo->modificarElValor = &modificarElValor;
}

/**
 * coloca el tipo tipoInfo2 en la lista enlazada, el que se haya definido, y, si no se ha definido ninguno, será int por defecto
 * @param tipo (tipoLista ref): lista en la que se va a colocar el tipo tipoInfo2
 * @return void
 * @example tipoLista tl; inicializarTipoLista(&tl); colocarTipoInfo2EnLista(&tl);
 */
void colocarTipoInfo2EnLista(tipoLista *tipo)
{
	if(tipo==NULL) return;
	tipo->annadirPPio = &annadirPPio2;
	tipo->annadirFin = &annadirFin2;
	tipo->annadirEnLugar = &annadirEnLugar2;
	tipo->mostrarLista = &mostrarLista2;
	tipo->borrarElValor = &borrarElValor2;
	tipo->modificarElValor = &modificarElValor2;
}

/**
 * coloca el tipo tipoInfo3 en la lista enlazada, el que se haya definido, y, si no se ha definido ninguno, será int por defecto
 * @param tipo (tipoLista ref): lista en la que se va a colocar el tipo tipoInfo3
 * @return void
 * @example tipoLista tl; inicializarTipoLista(&tl); colocarTipoInfo3EnLista(&tl);
 */
void colocarTipoInfo3EnLista(tipoLista *tipo)
{
	if(tipo==NULL) return;
	tipo->annadirPPio = &annadirPPio3;
	tipo->annadirFin = &annadirFin3;
	tipo->annadirEnLugar = &annadirEnLugar3;
	tipo->mostrarLista = &mostrarLista3;
	tipo->borrarElValor = &borrarElValor3;
	tipo->modificarElValor = &modificarElValor3;
}

/**
 * coloca el tipo int en la lista enlazada
 * @param tipo (tipoLista ref): lista en la que se va a colocar el tipo tipoInfo
 * @return void
 * @example tipoLista tl; inicializarTipoLista(&tl); colocarTipoIntEnLista(&tl);
 */
void colocarTipoIntEnLista(tipoLista *tipo)
{
	if(tipo==NULL) return;
	tipo->annadirPPio = &annadirPPioI;
	tipo->annadirFin = &annadirFinI;
	tipo->annadirEnLugar = &annadirEnLugarI;
	tipo->mostrarLista = &mostrarListaI;
	tipo->borrarElValor = &borrarElValorI;
	tipo->modificarElValor = &modificarElValorI;
}

/**
 * coloca el tipo float en la lista enlazada
 * @param tipo (tipoLista ref): lista en la que se va a colocar el tipo float
 * @return void
 * @example tipoLista tl; inicializarTipoLista(&tl); colocarTipoFloatEnLista(&tl);
 */
void colocarTipoFloatEnLista(tipoLista *tipo)
{
	if(tipo==NULL) return;
	tipo->annadirPPio = &annadirPPioF;
	tipo->annadirFin = &annadirFinF;
	tipo->annadirEnLugar = &annadirEnLugarF;
	tipo->mostrarLista = &mostrarListaF;
	tipo->borrarElValor = &borrarElValorF;
	tipo->modificarElValor = &modificarElValorF;
}

int annadirPPio(tipoLista* tipo, ...)
{
	int retur;
    tipoInfo info;
    va_list fargs;
	va_start(fargs, tipo);
	info = va_arg(fargs, tipoInfo);
	va_end(fargs);
	retur = annadirPrincipio(&(tipo->lst), info);
	if (retur == FALLO) return FALLO;
	tipo->vacia = FALSE;
	tipo->numElementos++;
	return EXITO;
}

int annadirPPio2(tipoLista* tipo, ...)
{
	int retur;
    tipoInfo2 info;
    va_list fargs;
	va_start(fargs, tipo);
	info = va_arg(fargs, tipoInfo2);
	va_end(fargs);
	retur = annadirPrincipio2(&(tipo->lst), info);
	if (retur == FALLO) return FALLO;
	tipo->vacia = FALSE;
	tipo->numElementos++;
	return EXITO;
}

int annadirPPio3(tipoLista* tipo, ...)
{
	int retur;
    tipoInfo3 info;
    va_list fargs;
	va_start(fargs, tipo);
	info = va_arg(fargs, tipoInfo3);
	va_end(fargs);
	retur = annadirPrincipio3(&(tipo->lst), info);
	if (retur == FALLO) return FALLO;
	tipo->vacia = FALSE;
	tipo->numElementos++;
	return EXITO;
}

int annadirPPioI(tipoLista* tipo, ...)
{
	int retur;
    int info;
    va_list fargs;
	va_start(fargs, tipo);
	info = va_arg(fargs, int);
	va_end(fargs);
	retur = annadirPrincipioI(&(tipo->lst), info);
	if (retur == FALLO) return FALLO;
	tipo->vacia = FALSE;
	tipo->numElementos++;
	return EXITO;
}

int annadirPPioF(tipoLista* tipo, ...)
{
	int retur;
    float info;
    va_list fargs;
	va_start(fargs, tipo);
	info = (float) va_arg(fargs, double);
	va_end(fargs);
	retur = annadirPrincipioF(&(tipo->lst), info);
	if (retur == FALLO) return FALLO;
	tipo->vacia = FALSE;
	tipo->numElementos++;
	return EXITO;
}

int annadirFin(tipoLista* tipo, ...)
{
	int retur;
    tipoInfo info;
    va_list fargs;
	va_start(fargs, tipo);
	info = va_arg(fargs, tipoInfo);
	va_end(fargs);
	retur = annadirFinal(&(tipo->lst), info);
	if (retur == FALLO) return FALLO;
	tipo->vacia = FALSE;
	tipo->numElementos++;
	return EXITO;
}

int annadirFin2(tipoLista* tipo, ...)
{
	int retur;
    tipoInfo2 info;
    va_list fargs;
	va_start(fargs, tipo);
	info = va_arg(fargs, tipoInfo2);
	va_end(fargs);
	retur = annadirFinal2(&(tipo->lst), info);
	if (retur == FALLO) return FALLO;
	tipo->vacia = FALSE;
	tipo->numElementos++;
	return EXITO;
}

int annadirFin3(tipoLista* tipo, ...)
{
	int retur;
    tipoInfo3 info;
    va_list fargs;
	va_start(fargs, tipo);
	info = va_arg(fargs, tipoInfo3);
	va_end(fargs);
	retur = annadirFinal3(&(tipo->lst), info);
	if (retur == FALLO) return FALLO;
	tipo->vacia = FALSE;
	tipo->numElementos++;
	return EXITO;
}

int annadirFinI(tipoLista* tipo, ...)
{
	int retur;
    int info;
    va_list fargs;
	va_start(fargs, tipo);
	info = va_arg(fargs, int);
	va_end(fargs);
	retur = annadirFinalI(&(tipo->lst), info);
	if (retur == FALLO) return FALLO;
	tipo->vacia = FALSE;
	tipo->numElementos++;
	return EXITO;
}

int annadirFinF(tipoLista* tipo, ...)
{
	int retur;
    float info;
    va_list fargs;
	va_start(fargs, tipo);
	info = (float) va_arg(fargs, double);
	va_end(fargs);
	retur = annadirFinalF(&(tipo->lst), info);
	if (retur == FALLO) return FALLO;
	tipo->vacia = FALSE;
	tipo->numElementos++;
	return EXITO;
}

int annadirEnLugar(tipoLista* tipo, int lugar, ...)
{
	int retur;
    tipoInfo info;
    va_list fargs;
	va_start(fargs, lugar);
	info = va_arg(fargs, tipoInfo);
	va_end(fargs);
	retur = annadirEnMedio(&(tipo->lst), lugar, info);
	if (retur == FALLO) return FALLO;
	tipo->vacia = FALSE;
	tipo->numElementos++;
	return EXITO;
}

int annadirEnLugar2(tipoLista* tipo, int lugar, ...)
{
	int retur;
    tipoInfo2 info;
    va_list fargs;
	va_start(fargs, lugar);
	info = va_arg(fargs, tipoInfo2);
	va_end(fargs);
	retur = annadirEnMedio2(&(tipo->lst), lugar, info);
	if (retur == FALLO) return FALLO;
	tipo->vacia = FALSE;
	tipo->numElementos++;
	return EXITO;
}

int annadirEnLugar3(tipoLista* tipo, int lugar, ...)
{
	int retur;
    tipoInfo3 info;
    va_list fargs;
	va_start(fargs, lugar);
	info = va_arg(fargs, tipoInfo3);
	va_end(fargs);
	retur = annadirEnMedio3(&(tipo->lst), lugar, info);
	if (retur == FALLO) return FALLO;
	tipo->vacia = FALSE;
	tipo->numElementos++;
	return EXITO;
}

int annadirEnLugarI(tipoLista* tipo, int lugar, ...)
{
	int retur;
    int info;
    va_list fargs;
	va_start(fargs, lugar);
	info = va_arg(fargs, int);
	va_end(fargs);
	retur = annadirEnMedioI(&(tipo->lst), lugar, info);
	if (retur == FALLO) return FALLO;
	tipo->vacia = FALSE;
	tipo->numElementos++;
	return EXITO;
}

int annadirEnLugarF(tipoLista* tipo, int lugar, ...)
{
	int retur;
    float info;
    va_list fargs;
	va_start(fargs, lugar);
	info = (float) va_arg(fargs, double);
	va_end(fargs);
	retur = annadirEnMedioF(&(tipo->lst), lugar, info);
	if (retur == FALLO) return FALLO;
	tipo->vacia = FALSE;
	tipo->numElementos++;
	return EXITO;
}

int borrarPpio(tipoLista* tipo)
{
	int retur;
	retur = borrarPrincipio(&(tipo->lst));
	if (retur == FALLO) return FALLO;
	tipo->numElementos--;
	if (!tipo->numElementos) tipo->vacia = TRUE;
	return EXITO;
}

int borrarFin(tipoLista* tipo) 
{
	int retur;
	retur = borrarFinal(&(tipo->lst));
	if (retur == FALLO) return FALLO;
	tipo->numElementos--;
	if (!tipo->numElementos) tipo->vacia = TRUE;
	return EXITO;
}

int borrarElValor(tipoLista* tipo, ...)
{
	int retur;
    tipoInfo info;
    va_list fargs;
	va_start(fargs, tipo);
	info = va_arg(fargs, tipoInfo);
	va_end(fargs);
	retur = borrarValor(&(tipo->lst), info);
	if (retur == FALLO) return FALLO;
	if (retur == EXITO)
	{
		tipo->numElementos--;
		if (!tipo->numElementos) tipo->vacia = TRUE;
	}
	return EXITO;
}

int borrarElValor2(tipoLista* tipo, ...)
{
	int retur;
    tipoInfo2 info;
    va_list fargs;
	va_start(fargs, tipo);
	info = va_arg(fargs, tipoInfo2);
	va_end(fargs);
	retur = borrarValor2(&(tipo->lst), info);
	if (retur == FALLO) return FALLO;
	if (retur == EXITO)
	{
		tipo->numElementos--;
		if (!tipo->numElementos) tipo->vacia = TRUE;
	}
	return EXITO;
}

int borrarElValor3(tipoLista* tipo, ...)
{
	int retur;
    tipoInfo3 info;
    va_list fargs;
	va_start(fargs, tipo);
	info = va_arg(fargs, tipoInfo3);
	va_end(fargs);
	retur = borrarValor3(&(tipo->lst), info);
	if (retur == FALLO) return FALLO;
	if (retur == EXITO)
	{
		tipo->numElementos--;
		if (!tipo->numElementos) tipo->vacia = TRUE;
	}
	return EXITO;
}

int borrarElValorI(tipoLista* tipo, ...)
{
	int retur;
    int info;
    va_list fargs;
	va_start(fargs, tipo);
	info = va_arg(fargs, int);
	va_end(fargs);
	retur = borrarValorI(&(tipo->lst), info);
	if (retur == FALLO) return FALLO;
	if (retur == EXITO)
	{
		tipo->numElementos--;
		if (!tipo->numElementos) tipo->vacia = TRUE;
	}
	return EXITO;
}

int borrarElValorF(tipoLista* tipo, ...)
{
	int retur;
    float info;
    va_list fargs;
	va_start(fargs, tipo);
	info = (float) va_arg(fargs, double);
	va_end(fargs);
	retur = borrarValorF(&(tipo->lst), info);
	if (retur == FALLO) return FALLO;
	if (retur == EXITO)
	{
		tipo->numElementos--;
		if (!tipo->numElementos) tipo->vacia = TRUE;
	}
	return EXITO;
}

int modificarElValor(tipoLista* tipo, ...)
{
	int retur;
    tipoInfo info1, info2;
    va_list fargs;
	va_start(fargs, tipo);
	info1 = va_arg(fargs, tipoInfo);
	info2 = va_arg(fargs, tipoInfo);
	va_end(fargs);
	retur = modificarValor(&(tipo->lst), info1, info2);
	if (retur != EXITO) return FALLO;
	return EXITO;
}

int modificarElValor2(tipoLista* tipo, ...)
{
	int retur;
    tipoInfo2 info1, info2;
    va_list fargs;
	va_start(fargs, tipo);
	info1 = va_arg(fargs, tipoInfo2);
	info2 = va_arg(fargs, tipoInfo2);
	va_end(fargs);
	retur = modificarValor2(&(tipo->lst), info1, info2);
	if (retur != EXITO) return FALLO;
	return EXITO;
}

int modificarElValor3(tipoLista* tipo, ...)
{
	int retur;
    tipoInfo3 info1, info2;
    va_list fargs;
	va_start(fargs, tipo);
	info1 = va_arg(fargs, tipoInfo3);
	info2 = va_arg(fargs, tipoInfo3);
	va_end(fargs);
	retur = modificarValor3(&(tipo->lst), info1, info2);
	if (retur != EXITO) return FALLO;
	return EXITO;
}

int modificarElValorI(tipoLista* tipo, ...)
{
	int retur;
    int info1, info2;
    va_list fargs;
	va_start(fargs, tipo);
	info1 = va_arg(fargs, int);
	info2 = va_arg(fargs, int);
	va_end(fargs);
	retur = modificarValorI(&(tipo->lst), info1, info2);
	if (retur != EXITO) return FALLO;
	return EXITO;
}

int modificarElValorF(tipoLista* tipo, ...)
{
	int retur;
    float info1, info2;
    va_list fargs;
	va_start(fargs, tipo);
	info1 = (float) va_arg(fargs, double);
	info2 = (float) va_arg(fargs, double);
	va_end(fargs);
	retur = modificarValorF(&(tipo->lst), info1, info2);
	if (retur != EXITO) return FALLO;
	return EXITO;
}

int vaciarLaLista(tipoLista *tipo)
{
	int retur;
	retur = vaciarLista(&(tipo->lst));
	if (retur == FALLO) return FALLO;
	tipo->numElementos = 0;
	tipo->vacia = TRUE;
	return EXITO;
}

/**
 * Abre el fichero con la ruta especificada en el modo especificado de manera atómica y bloqueante
 * @param nombre (string): ruta del fichero que se quiere abrir
 * @param modo (string): valdrá solo '"r"', '"w"', '"a"', '"r+"', '"w+"' o '"a+"'
 * @return NULL si la ruta no existe o si no se puede abrir o bloquear el fichero, y el puntero al fichero abierto en caso contrario
 * @example FILE *f = abrirFpBloq("fichero.txt", "r");
 */
FILE* abrirFpBloq(string nombre, string modo)
{
    return fopen(nombre, modo);
}

/**
 * Cierra el fichero indicado y libera su bloqueo de manera atómica
 * @param f (FILE ref): puntero al fichero abierto
 * @return void
 * @example FILE *f = abrirFpBloq("fichero.txt", "r"); /-*operaciones*-/; cerrarFpBloq(f);
 */
void cerrarFpBloq(FILE* f)
{
    fclose(f);
}


void amplitud(int v_inicio, tipoGrafo *grafo)
{
  int w;
  arco *p;
  Cola c;
  colaCreaVacia(&c);
  colaInserta(v_inicio,&c);
  while (!colaVacia(&c))  {
        w =colaSuprime(&c);
        if (!grafo->directorio[w].alcanzado) {
                printf("%d ",w);
                grafo->directorio[w].alcanzado=1;
                p =grafo->directorio[w].lista;
                while (p!=NULL){
                        w = p->v;
                        colaInserta(w,&c);
                        p = p->sig;
                }
        }
  }

}

void verGrafo(tipoGrafo *g)
{  int i;
   arco *p;

   printf("\nGrafo  (Orden %d)\n\n",g->orden);
   printf("       alc gEnt oTop dist peso ant \n");
   printf("     +----+----+----+----+----+----+\n");

   for(i=1;i<=g->orden;i++)
   {  printf("  %2d | %2d | %2d | %2d |", i, g->directorio[i].alcanzado,
                       g->directorio[i].gradoEntrada, g->directorio[i].ordenTop);
       if (g->directorio[i].distancia == INF) printf("  * |");
       else   printf(" %2d |", g->directorio[i].distancia);
       if (g->directorio[i].peso == INF) printf("  * |");
       else   printf(" %2d |", g->directorio[i].peso);
       printf(" %2d |",g->directorio[i].anterior);
       p = g->directorio[i].lista;
       while (p != NULL)
       {   printf(" ->%2d", p->v);
           p = p->sig;
       }
       printf("\n");
   }
   printf("     +----+----+----+----+----+----+\n\n");
}

void iniciar(tipoGrafo *g){

        int i;
        arco *indice;
        for(i=1;i<=g->orden;i++){
                g->directorio[i].alcanzado = 0;
                g->directorio[i].anterior = 0;
                g->directorio[i].distancia = INF;
                g->directorio[i].peso = INF;
                g->directorio[i].ordenTop = 0;
                g->directorio[i].gradoEntrada = 0;
        }
        for(i=1; i<=g->orden; i++){
                indice = g->directorio[i].lista;
                while(indice != NULL){
                        g->directorio[indice->v].gradoEntrada++;
                        indice = indice->sig;
                }
        }

}
tipoGrafo* creaGrafo28(){
        int i;
        tipoGrafo *g = (tipoGrafo*) malloc(sizeof(tipoGrafo));
        arco *a,*b;
        g->orden = 7;

        for(i=1;i<=g->orden;i++){
                g->directorio[i].alcanzado = 0;
                g->directorio[i].anterior = 0;
                g->directorio[i].distancia = 0;
                g->directorio[i].peso = 0;
                g->directorio[i].ordenTop = 0;
                if(i!=6) g->directorio[i].lista =(arco*) malloc(sizeof(arco));
        }
  //V1
        g->directorio[1].gradoEntrada = 0;
        g->directorio[1].lista->peso = 1;
        g->directorio[1].lista->v = 2;

        a = (arco*)malloc(sizeof(arco));
        a->peso = 1;
        a->v = 3;
        b = (arco*)malloc(sizeof(arco));
        b->peso = 1;
        b->v = 4;
        b->sig = NULL;
        a->sig = b;
        g->directorio[1].lista->sig = a;

  //V2

        g->directorio[2].gradoEntrada = 1;
        g->directorio[2].lista->peso = 1;
        g->directorio[2].lista->v = 4;
        a = (arco*) malloc(sizeof(arco));
        a->peso = 1;
        a->v = 5;

        a->sig = NULL;
        g->directorio[2].lista->sig = a;

  //V3

    g->directorio[3].gradoEntrada = 1;
        g->directorio[3].lista->peso = 1;
        g->directorio[3].lista->v = 6;

        g->directorio[3].lista->sig = NULL;

  //V4

        g->directorio[4].gradoEntrada = 3;
        g->directorio[4].lista->peso = 1;
        g->directorio[4].lista->v = 3;
        a = (arco*) malloc(sizeof(arco));
        a->peso = 1;
        a->v = 6;

        b = (arco*) malloc(sizeof(arco));
        b->peso = 1;
        b->v = 7;

        b->sig = NULL;
        a->sig = b;
        g->directorio[4].lista->sig = a;

  //V5

        g->directorio[5].gradoEntrada = 1;
        g->directorio[5].lista->peso = 1;
        g->directorio[5].lista->v = 4;
        a = (arco*) malloc(sizeof(arco));
        a->peso = 1;
        a->v = 7;

        a->sig = NULL;
        g->directorio[5].lista->sig = a;

  //V6
        g->directorio[6].gradoEntrada = 3;
        g->directorio[6].lista = NULL;

  //V7

        g->directorio[7].gradoEntrada = 2;
        g->directorio[7].lista->peso = 1;
        g->directorio[7].lista->v = 6;

        g->directorio[7].lista->sig = NULL;


        return g;

}
void profundidad(int v_inicio,tipoGrafo *g){

        int w;
        arco *p;
        printf("%2d ",v_inicio);
        g->directorio[v_inicio].alcanzado = 1;
        p = g->directorio[v_inicio].lista;
        while(p != NULL){
                w = p->v;
                if(!g->directorio[w].alcanzado)
                        profundidad(w,g);
                p = p->sig;
        }
}

int ordenTop2(tipoGrafo *g){

        Cola c;
        int i,orden;
        int w;
        arco *p;


        iniciar(g);
        colaCreaVacia(&c);

        for( i = 1 ; i <= g->orden ;  i++)
                if(!g->directorio[i].gradoEntrada)
                                                                        colaInserta(i,&c);

        if(colaVacia(&c)) return -1;

        orden = 1;
        while(!colaVacia(&c)){
                i = colaSuprime(&c);
                g->directorio[i].ordenTop = orden;
                orden++;
                p = g->directorio[i].lista;
                while(p!=NULL){
                        w = p->v;
                        g->directorio[w].gradoEntrada--;
                        if(!g->directorio[w].gradoEntrada) colaInserta(w,&c);
                        p = p->sig;
                }
        }

                if(orden!=g->orden) return -1;

        for(i=1;i<=g->orden;i++)
                printf("%d:%d ",i,g->directorio[i].ordenTop);


        return 0;
}

void profundidadMejorado(int v_inicio, tipoGrafo * grafo)
{
        int i;

        iniciar(grafo);

        profundidad(v_inicio, grafo);

        for(i=1; i <= grafo->orden; i++)
                if(!grafo->directorio[i].alcanzado)
                        profundidad(i, grafo);
}
void amplitudMejorado(int v_inicio,tipoGrafo *grafo){
        int i;

        iniciar(grafo);

        amplitud(v_inicio, grafo);

        for(i=1; i <= grafo->orden; i++)
                if(!grafo->directorio[i].alcanzado)
                        amplitud(i, grafo);
}
int costeyTrayectoria(int vIni, int vFin, tipoGrafo *g){

        int *orden;
        int anterior;
        int i=0;
        int j;

        if(g->directorio[vFin].distancia==INF) return -1;
        if((orden =malloc(sizeof(int)*g->orden))==NULL){
                fprintf(stderr, "Error en reserva de memoria\n");
                return -2;
        }
        anterior = vFin;
        while(anterior!=vIni){
                orden[i] = anterior;
                anterior = g->directorio[anterior].anterior;
                i++;
        }
        orden[i] = anterior;
        printf("Camino: ");
        for(j=i;j>=0;j--) printf("%d ",orden[j]);
        free(orden);
        return g->directorio[vFin].distancia;
}

void todosCaminosMin(int vIni, tipoGrafo *g){
        int i;
        for(i=1;i<=g->orden;i++)
                if(i!=vIni)
                        printf("Distancia a %d desde %d: %d\n",i,vIni,costeyTrayectoria(vIni, i,g));
}

void dijkstra1(int vInicio, tipoGrafo *g){

        arco *p;
        int v,w;
        int i;
        iniciar(g);
        g->directorio[vInicio].distancia = 0;
        g->directorio[vInicio].anterior = 0;
        for(i=1;g->orden>=i;i++){
                v = buscarVerticeDistanciaMinimaNoAlcanzado(g);
                g->directorio[v].alcanzado = 1;
                p = g->directorio[v].lista;
                while(p!=NULL){
                        w = p->v;
                        if(!g->directorio[w].alcanzado){
                                if((g->directorio[v].distancia + p->peso) < (g->directorio[w].distancia)){
                                        g->directorio[w].distancia = g->directorio[v].distancia + p->peso;
                                        g->directorio[w].anterior = v;
                                }
                        }
                        p = p->sig;
                }
        }
}

void dijkstra2(int vInicio, tipoGrafo *g){

        arco *p;
        int v,w;
        Monticulo m;
        tipoElementoMonticulo x;
        int i,coste;
        iniciar(g);
        g->directorio[vInicio].distancia = 0;
        g->directorio[vInicio].anterior = 0;
        iniciaMonticulo(&m);
        x.clave = 0;
        x.informacion = vInicio;
        insertar(x,&m);
        while(!vacioMonticulo(m)){
                eliminarMinimo(&m,&x);
                if(!(g->directorio[x.informacion].alcanzado)){
                        v = x.informacion;
                        g->directorio[v].alcanzado = 1;
                        p = g->directorio[v].lista;
                        while(p!=NULL){
                                w = p->v;
                                if(!(g->directorio[w].alcanzado)){
                                        coste = g->directorio[v].distancia + p->peso;
                                        if(coste < (g->directorio[w].distancia)){
                                                g->directorio[w].distancia = coste;
                                                g->directorio[w].anterior = v;
                                                x.clave = coste;
                                                x.informacion = w;
                                                insertar(x,&m);
                                        }
                                }
                                p = p->sig;
                        }
                }
        }
}

/**
 * Busca el vértice con la distancia mínima no alcanzada en un grafo.
 * @param g Puntero al grafo
 * @return El vértice con la distancia mínima no alcanzada
 */
int buscarVerticeDistanciaMinimaNoAlcanzado(tipoGrafo *g){

        int i;
        int min=INF;
        int ver;

        for(i=1;i<=g->orden;i++)
                if(!g->directorio[i].alcanzado)
                        if(min>g->directorio[i].distancia){
                                min = g->directorio[i].distancia;
                                ver = i;
                                                                }

        return ver;
}

/**
 * Crea un nuevo grafo con los vértices y arcos especificados.
 * @return Puntero al nuevo grafo creado
 */
tipoGrafo* creaGrafo(){

        int i;
  arco  *p; arco *aux;
  tipoGrafo *g;

  g=(tipoGrafo *)calloc(1,sizeof(tipoGrafo));

  g->orden=11;

  // Lista de adyacencia del vértice 1
  p = (arco *)calloc(1,sizeof(arco));
        p->v = 2;
        p->peso = 13;
        g->directorio[1].lista=p;
        aux = p;
  p = (arco *)calloc(1,sizeof(arco));
          p->v = 6;
          p->peso = 2;
          aux->sig = p;
  p->sig=NULL;
  // Lista de adyacencia del vértice 2
  p = (arco *)calloc(1,sizeof(arco));
        p->v = 3;
        p->peso = 15;
        g->directorio[2].lista=p;
    p->sig=NULL;
  // Lista de adyacencia del vértice 3
  p = (arco *)calloc(1,sizeof(arco));
        p->v = 6;
        p->peso = 4;
        g->directorio[3].lista=p;
        aux = p;
  p= (arco *)calloc(1,sizeof(arco));
        p->v = 11;
        p->peso = 5;
        aux->sig=p;
  p->sig=NULL;
  // Lista de adyacencia del vértice 4
  p = (arco *)calloc(1,sizeof(arco));
        p->v = 1;
        p->peso = 25;
        g->directorio[4].lista=p;
        aux = p;
  p= (arco *)calloc(1,sizeof(arco));
        p->v = 5;
        p->peso = 2;
        aux->sig = p;
        aux = aux->sig;
  p = (arco *)calloc(1,sizeof(arco));
        p->v = 8;
        p->peso = 10;
        aux->sig = p;
        aux = aux->sig;
  p = (arco *)calloc(1,sizeof(arco));
        p->v = 9;
        p->peso = 4;
        aux->sig = p;
  p->sig=NULL;
// Lista de adyacencia del vértice 5

        g->directorio[5].lista=NULL;

// Lista de adyacencia del vértice 6
  p= (arco *)calloc(1,sizeof(arco));
        p->v = 2;
        p->peso = 3;
        g->directorio[6].lista=p;
        aux = p;
  p = (arco *)calloc(1,sizeof(arco));
        p->v = 5;
        p->peso = 2;
        aux->sig = p;
        aux = aux->sig;
  p = (arco *)calloc(1,sizeof(arco));
        p->v = 7;
        p->peso = 30;
        aux->sig = p;
        aux = aux->sig;
  p = (arco *)calloc(1,sizeof(arco));
        p->v = 10;
        p->peso = 4;
        aux->sig = p;
  p->sig=NULL;
// Lista de adyacencia del vértice 7
        g->directorio[7].lista=NULL;
// Lista de adyacencia del vértice 8
  p= (arco *)calloc(1,sizeof(arco));
        p->v = 9;
        p->peso = 6;
        g->directorio[8].lista=p;
    p->sig=NULL;
// Lista de adyacencia del vértice 9
  p= (arco *)calloc(1,sizeof(arco));
        p->v = 6;
        p->peso = 13;
        g->directorio[9].lista=p;
        aux = p;
  p = (arco *)calloc(1,sizeof(arco));
        p->v = 10;
        p->peso = 2;
        aux->sig = p;
  p->sig=NULL;
// Lista de adyacencia del vértice 10
  p= (arco *)calloc(1,sizeof(arco));
        p->v = 7;
        p->peso = 1;
        g->directorio[10].lista=p;
        aux = p;
  p = (arco *)calloc(1,sizeof(arco));
        p->v = 11;
        p->peso = 2;
        aux->sig = p;
  p->sig=NULL;
// Lista de adyacencia del vértice 11
        g->directorio[11].lista=NULL;

  return g;
}

/**
 * Inicializa un montículo.
 * @param m Puntero al montículo
 * @return void
 */
void iniciaMonticulo(Monticulo *m){m->tam=0;}

/**
 * Comprueba si un montículo está vacío.
 * @param m Montículo a comprobar
 * @return TRUE si está vacío, FALSE en caso contrario
 */
int vacioMonticulo(Monticulo m){return m.tam == 0;}

/**
 * Filtra un montículo de forma descendente.
 * @param m Puntero al montículo
 * @param i Índice del elemento a filtrar
 * @return void
 */
void filtradoDescendente(Monticulo *m, int i)
{
	int hijo,finFiltrado = 0;
	tipoElementoMonticulo temp;

	while((2*i <= m->tam) && (!finFiltrado)) //Controla que tenga un hijo
	{
		hijo = 2*i;
		if(hijo != m->tam)	// Controla que tenga hijo derecho tambien
		{
			if(m->elemento[hijo+1].clave < m->elemento[hijo].clave)
				hijo = hijo + 1; // Toma el menor de los hijos
		}
		if(m->elemento[i].clave > m->elemento[hijo].clave) // Clave padre > clave hijo
		{
			temp = m->elemento[hijo];
			m->elemento[hijo] = m->elemento[i];
			m->elemento[i] = temp;
			i = hijo;
		}
		else
			finFiltrado = 1;
	}
}

/**
 * Filtra un montículo de forma ascendente.
 * @param m Puntero al montículo
 * @param i Índice del elemento a filtrar
 * @return void
 */
void filtradoAscendente(Monticulo *m, int i)
{
	tipoElementoMonticulo temp;

	while(((m->elemento[i/2]).clave > (m->elemento[i]).clave) && (i >= 1)) // Clave padre > clave hijo
	{
		temp = m->elemento[i];
		m->elemento[i] = m->elemento[i/2];
		m->elemento[i/2] = temp;
		i = i/2; // Posiciona i en la raiz de la raiz
	}
}

/**
 * Inserta un elemento en un montículo.
 * @param x Elemento a insertar
 * @param m Puntero al montículo
 * @return 0 si se inserta correctamente, -1 si el montículo está lleno
 */
int insertar(tipoElementoMonticulo x, Monticulo *m)
{
	int i;

	if(m->tam == NUM_ELEMS_MONT) return -1;
	else
	{
		m->tam = m->tam + 1; // Incrementa el tamaño
		i = m->tam; // Posiciona donde se va a insertar el nuevo elemento
		m->elemento[i] = x; // Introduce en i el nuevo elemento
		filtradoAscendente(m,i); // Ordena el elemento introducido ASCENDENTEMENTE
	}

	return 0;
}

/**
 * Elimina el elemento mínimo de un montículo.
 * @param m Puntero al montículo
 * @param minimo Puntero al elemento mínimo
 * @return 0 si se elimina correctamente, -1 si el montículo está vacío
 */
int eliminarMinimo(Monticulo *m, tipoElementoMonticulo *minimo)
{
	int i;
	if(vacioMonticulo(*m)) return -1;
	else
	{
		*minimo = m->elemento[1]; // Pasa por referencia el valor minimo (el de posicion = 1)
		m->elemento[1] = m->elemento[m->tam];
		m->tam = m->tam - 1;
		i = 1;
		filtradoDescendente(m,i);
	}

	return 0;
}

/**
 * Decrementa la clave de un elemento en un montículo.
 * @param pos Posición del elemento
 * @param cantidad Cantidad a decrementar
 * @param m Puntero al montículo
 * @return void
 */
void decrementarClave(int pos, tipoClaveMonticulo cantidad, Monticulo *m)
{
	m->elemento[pos].clave = m->elemento[pos].clave - cantidad;

	filtradoAscendente(m,pos);
}

/**
 * Incrementa la clave de un elemento en un montículo.
 * @param pos Posición del elemento
 * @param cantidad Cantidad a incrementar
 * @param m Puntero al montículo
 * @return void
 */
void incrementarClave(int pos, tipoClaveMonticulo cantidad, Monticulo *m)
{
	m->elemento[pos].clave = m->elemento[pos].clave + cantidad;

	filtradoDescendente(m,pos);
}

/**
 * Comprueba si un montículo es válido.
 * @param m Montículo a comprobar
 * @return 1 si es válido, 0 en caso contrario
 */
int esMonticulo(Monticulo m)
{
	int i=1, activo=1;

	while(2*i < m.tam)
	{
		if(2*i != m.tam)
		{
			if((m.elemento[i].clave > m.elemento[2*i].clave) || (m.elemento[i].clave > m.elemento[2*i+1].clave)) // Padre mayor que sus dos hijos
				activo=0;
		}
		else
		{
			if(m.elemento[i].clave > m.elemento[2*i].clave)
				activo=0;
		}

		i = i * 2; // Avanza analizar hijo
	}

	return activo;
}

/**
 * Crea un montículo a partir de un vector.
 * @param m Puntero al montículo
 * @return void
 */
void crearMonticulo(Monticulo *m)
{
	int i,n;
	n = m->tam;

	for(i=n/2; i>=1; i--)
		filtradoDescendente(m,i);
}

/**
 * Ordena un montículo usando el algoritmo Heapsort.
 * @param m Puntero al montículo
 * @return void
 */
void heapsort(Monticulo *m)
{
    tipoElementoMonticulo *vector = malloc(m->tam * sizeof(tipoElementoMonticulo));
	int nElementos;
	int i;
	tipoElementoMonticulo elemento;

	nElementos = m->tam;

	crearMonticulo(m);
	
	for(i=0;i<nElementos;i++)
	{
		eliminarMinimo(m,&elemento);
		vector[i]=elemento;
	}
	for(i=0;i<nElementos;i++)
		insertar(vector[i],m);
    free(vector);
}

/**
 * Crea un nuevo nodo de árbol binario con la información dada.
 * @param info Información a almacenar en el nodo
 * @return Puntero al nuevo nodo creado, o NULL si hay error de memoria
 */
Arbol creaArbol(tipoInfoArbol info)
{
	tipoNodo * nuevo;
	if ((nuevo =(tipoNodo *)malloc(sizeof(tipoNodo)))==NULL) return NULL;
	nuevo->info=info;
	nuevo->izq=NULL;
	nuevo->der=NULL;
	return nuevo;
}

/**
 * Recorre un árbol binario en amplitud (por niveles) e imprime los nodos.
 * @param raiz Raíz del árbol a recorrer
 * @return void
 */
void amplitudArbol(Arbol raiz)
{
	ColaArbol c;
	tipoNodo *nodo;
	colaArbolCreaVacia(&c);
	nodo = raiz;
	if (raiz!=NULL) colaArbolInserta(nodo, &c);
	while (!colaArbolVacia(&c))
	{
		nodo = (Arbol) colaArbolSuprime(&c);
		printf(" %c ", nodo->info);
		if (nodo->izq!=NULL) colaArbolInserta(nodo->izq, &c);
		if (nodo->der!=NULL) colaArbolInserta(nodo->der, &c);
	}
}

/**
 * Recorre un árbol binario en preorden e imprime los nodos.
 * @param raiz Raíz del árbol a recorrer
 * @return void
 */
void preOrden(Arbol raiz)
{
	if (raiz!=NULL)
	{
		printf("%c ",raiz->info); // visitar nodo raiz - sacar valor
		preOrden(raiz->izq);
		preOrden(raiz->der);
	}
}

/**
 * Recorre un árbol binario en inorden e imprime los nodos.
 * @param raiz Raíz del árbol a recorrer
 * @return void
 */
void enOrden(Arbol raiz)
{
	if (raiz!=NULL)
	{
		enOrden(raiz->izq);
		printf("%c ",raiz->info);
		enOrden(raiz->der);
	}
}

/**
 * Recorre un árbol binario en postorden e imprime los nodos.
 * @param raiz Raíz del árbol a recorrer
 * @return void
 */
void postOrden(Arbol raiz)
{
	if (raiz!=NULL)
	{
		postOrden(raiz->izq);
		postOrden(raiz->der);
		printf("%c ",raiz->info);
	}
}

/**
 * Calcula la altura de un árbol binario.
 * @param raiz Raíz del árbol
 * @return Altura del árbol (número de niveles)
 */
int altura(Arbol raiz)
{
    int izq = -1, der = -1;
    
	if(raiz == NULL || (raiz->izq == NULL && raiz->der == NULL)) return 0; 
	
	izq = altura(raiz->izq);
	if(izq != -1) izq++;

	der = altura(raiz->der);
	if(der != -1) der++;

	if(der > izq) 	return der;
	else 			return izq;
}

/**
 * Sustituye todas las apariciones de un valor por otro en un árbol binario.
 * @param raiz Raíz del árbol
 * @param x Valor a buscar
 * @param y Valor por el que se sustituye
 * @return Número de sustituciones realizadas
 */
int sustituye(Arbol raiz, tipoInfoArbol x, tipoInfoArbol y)
{
	int sustituciones = 0;

	if(raiz == NULL) return 0;

	sustituciones = sustituciones + sustituye(raiz->izq, x, y);
	sustituciones = sustituciones + sustituye(raiz->der, x, y);

	if(raiz->info == x)
	{
		raiz->info = y;
		sustituciones++;
		return sustituciones;
	}

	return sustituciones;
}

/**
 * Cuenta el número de nodos de un árbol binario.
 * @param raiz Raíz del árbol
 * @return Número de nodos
 */
int numNodos(Arbol raiz)
{
	int nodos=-1; 

	if(raiz == NULL) return 0;
	
	nodos = numNodos(raiz->izq);
	if(nodos != -1) nodos++;
	nodos = nodos + numNodos(raiz->der);

	return nodos; 
}


/**
 * Cuenta el número de nodos hoja de un árbol binario.
 * @param raiz Raíz del árbol
 * @return Número de nodos hoja
 */
int numNodosHoja(Arbol raiz)
{
	int nodosHoja = 0;

	if(raiz == NULL) return 0;

    if(raiz->der == NULL && raiz->izq == NULL) return ++nodosHoja;

	nodosHoja = nodosHoja + numNodosHoja(raiz->der);
	nodosHoja = nodosHoja + numNodosHoja(raiz->izq);

	return nodosHoja;
}

/**
 * Cuenta el número de nodos internos de un árbol binario.
 * @param raiz Raíz del árbol
 * @return Número de nodos internos
 */
int numNodosInternos(Arbol raiz)
{
	int nodosInternos = 0;

    if(raiz == NULL && (raiz->der != NULL || raiz->izq != NULL))
	{
		++nodosInternos;
		nodosInternos = nodosInternos + numNodosInternos(raiz->der);
		nodosInternos = nodosInternos + numNodosInternos(raiz->izq);
	}
	return nodosInternos;
}

/**
 * Cuenta el número de nodos con un solo hijo en un árbol binario.
 * @param raiz Raíz del árbol
 * @return Número de nodos con un solo hijo
 */
int numHijoUnico(Arbol raiz)
{
	int numHijosUnicos = 0;

	if(raiz == NULL) return 0;
    if((raiz->der == NULL && raiz->izq != NULL) || (raiz->der != NULL && raiz->izq == NULL)) return ++numHijosUnicos;

	numHijosUnicos = numHijosUnicos + numHijoUnico(raiz->der);
	numHijosUnicos = numHijosUnicos + numHijoUnico(raiz->izq);

	return numHijosUnicos;
}

/**
 * Busca el nodo con el valor máximo en un árbol binario.
 * @param raiz Raíz del árbol
 * @return Puntero al nodo con el valor máximo, o NULL si el árbol está vacío
 */
Arbol buscarMax(Arbol raiz)
{
	Arbol temp, temp2;
	if(raiz != NULL)
	{
		temp = buscarMax(raiz->der);
		temp2 =	buscarMax(raiz->izq);
		if((temp2==NULL || raiz->info > temp2->info) && (temp==NULL || raiz->info > temp->info)) return raiz;
		return (temp > temp2)? temp:temp2;
	}
	return NULL;
}

/**
 * Busca el nodo con el valor mínimo en un árbol binario de búsqueda.
 * @param raiz Raíz del árbol
 * @return Puntero al nodo con el valor mínimo, o NULL si el árbol está vacío
 */
Arbol buscarMin(Arbol raiz) {
    if (raiz == NULL) return NULL;
    while (raiz->izq != NULL) raiz = raiz->izq;
    return raiz;
}

/**
 * Comprueba si dos árboles binarios son similares en estructura.
 * @param r1 Primer árbol
 * @param r2 Segundo árbol
 * @return TRUE si son similares, FALSE en caso contrario
 */
boolean similares(Arbol r1,Arbol r2)
{
	if(r1 == NULL && r2 == NULL) return TRUE;
	if(r1 != NULL && r2 != NULL) return(similares (r1->izq,r2->izq) && similares (r1->der,r2->der))?TRUE:FALSE;
	return FALSE;
}

/**
 * Comprueba si dos árboles binarios son equivalentes (estructura y valores).
 * @param r1 Primer árbol
 * @param r2 Segundo árbol
 * @return TRUE si son equivalentes, FALSE en caso contrario
 */
boolean equivalentes(Arbol r1,Arbol r2)
{
	if(r1 == NULL && r2 == NULL) return TRUE;
	if ((r1 != NULL && r2 != NULL)) return (r1->info == r2->info && equivalentes (r1->izq,r2->izq) && equivalentes (r1->der,r2->der))?TRUE:FALSE;
	return FALSE;
}

/**
 * Devuelve el árbol especular (espejo) de un árbol binario.
 * @param raiz Raíz del árbol
 * @return Nuevo árbol especular
 */
Arbol especular(Arbol raiz)
{
	if(raiz == NULL) return NULL;
	Arbol nuevoNodo = creaArbol(raiz->info);
	nuevoNodo->der = especular(raiz->izq);
	nuevoNodo->izq = especular(raiz->der);
	return nuevoNodo;
}

/**
 * Inicializa los campos de un grafo (wrapper de iniciar).
 * @param g Puntero al grafo
 * @return void
 */
void iniciarGrafo(tipoGrafo *g) {
    iniciar(g);
}

/**
 * Descompone un número en factores primos.
 * @param n Número a descomponer
 * @param factores Array de salida donde se guardan los factores primos
 * @return Número de factores encontrados
 */
int descomponerFactoresPrimos(int n, int *factores) {
    int count = 0;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            factores[count++] = i;
            n /= i;
        }
    }
    if (n > 1) factores[count++] = n;
    return count;
}

// Devuelve 1 si x es raíz del polinomio de grado n con coeficientes coef[]
static int esRaizPoli(const int *coef, int grado, int x) {
    int res = coef[0];
    for (int i = 1; i <= grado; i++)
        res = res * x + coef[i];
    return res == 0;
}

// Aplica Ruffini y reduce el polinomio en grado
static void ruffini(const int *coef, int grado, int raiz, int *nuevo) {
    nuevo[0] = coef[0];
    for (int i = 1; i < grado; i++)
        nuevo[i] = nuevo[i-1] * raiz + coef[i];
}

/**
 * Descompone un polinomio en raíces enteras usando Ruffini.
 * @param coef Coeficientes del polinomio (grado+1 elementos, mayor a menor)
 * @param grado Grado del polinomio
 * @param raices Array de salida donde se guardan las raíces encontradas
 * @return Número de raíces enteras encontradas
 * @example int raices[100], coef = [6,-3,7,0,-2,4]; descomponerPolinomioRuffini(coef, 5, raices);
 */
int descomponerPolinomioRuffini(const int *coef, int grado, int *raices) {
    int *temp = malloc((grado+1) * sizeof(int));
    int actual_grado = grado;
    int *actual = malloc((grado+1) * sizeof(int));
    for (int i = 0; i <= grado; i++) actual[i] = coef[i];
    int num_raices = 0;
    while (actual_grado > 0) {
        int cte = actual[actual_grado];
        int encontrado = 0;
        for (int d = 1; d <= abs(cte); d++) {
            if (cte % d == 0) {
                for (int signo = -1; signo <= 1; signo += 2) {
                    int r = d * signo;
                    if (esRaizPoli(actual, actual_grado, r)) {
                        raices[num_raices++] = r;
                        ruffini(actual, actual_grado, r, temp);
                        for (int i = 0; i < actual_grado; i++) actual[i] = temp[i];
                        actual_grado--;
                        encontrado = 1;
                        break;
                    }
                }
            }
            if (encontrado) break;
        }
        if (!encontrado) break;
    }
    free(temp);
    free(actual);
    return num_raices;
}

// Función auxiliar para calcular el factorial de un número
static long factorial(int n) {
    if (n < 0) return 0;
    long res = 1;
    for (int i = 2; i <= n; i++) res *= i;
    return res;
}

long combinaciones(int n, int m) {
    if (m < 0 || n < 0 || m > n) return 0;
    return factorial(n) / (factorial(m) * factorial(n - m));
}

long combinacionesConRepeticion(int n, int m) {
    // C'(n, m) = C(n + m - 1, m)
    if (n <= 0 || m < 0) return 0;
    return combinaciones(n + m - 1, m);
}

long variaciones(int n, int m) {
    if (m < 0 || n < 0 || m > n) return 0;
    long res = 1;
    for (int i = 0; i < m; i++) res *= (n - i);
    return res;
}

long variacionesConRepeticion(int n, int m) {
    if (n < 0 || m < 0) return 0;
    long res = 1;
    for (int i = 0; i < m; i++) res *= n;
    return res;
}

long permutaciones(int n) {
    if (n < 0) return 0;
    return factorial(n);
}

/**
 * Calcula permutaciones con repeticiones: P(n; m1, m2, ..., mk)
 * @param n Total de elementos
 * @param ms Array de repeticiones
 * @param k Número de repeticiones (tamaño de ms)
 * @return Número de permutaciones o -1 si suma(ms) > n
 * @example int ms[] = {2, 2, 1}; int result = permutacionesConRepeticion(8, ms, 3)
 */
long permutacionesConRepeticion(int n, const int *ms, int k) {
    int suma = 0;
    for (int i = 0; i < k; i++) suma += ms[i];
    if (suma > n) return -1;
    long res = factorial(n);
    for (int i = 0; i < k; i++) res /= factorial(ms[i]);
    return res;
}

/**
 * Genera un valor aleatorio según una distribución binomial B(n, p)
 * @param n Número de ensayos
 * @param p Probabilidad de éxito en cada ensayo (0 <= p <= 1)
 * @return Número de éxitos
 * @example int x = aleatorioBinomial(10, 0.5); // x entre 0 y 10
 */
int aleatorioBinomial(int n, double p) {
    static int seeded = 0;
    if (!seeded) { srand((unsigned)time(NULL)); seeded = 1; }
    int x = 0;
    for (int i = 0; i < n; i++) {
        if ((double)rand() / RAND_MAX < p) x++;
    }
    return x;
}

/**
 * Genera un valor aleatorio según una distribución normal (Gaussiana) N(mu, sigma^2)
 * @param mu Media
 * @param sigma Desviación estándar
 * @return Valor aleatorio generado
 * @example double x = aleatorioNormal(0, 1); // x ~ N(0,1)
 */
double aleatorioNormal(double mu, double sigma) {
    static int seeded = 0;
    if (!seeded) { srand((unsigned)time(NULL)); seeded = 1; }
    static int hasSpare = 0;
    static double spare;
    if (hasSpare) {
        hasSpare = 0;
        return mu + sigma * spare;
    }
    hasSpare = 1;
    double u, v, s;
    do {
        u = (double)rand() / RAND_MAX * 2.0 - 1.0;
        v = (double)rand() / RAND_MAX * 2.0 - 1.0;
        s = u * u + v * v;
    } while (s >= 1.0 || s == 0.0);
    s = sqrt(-2.0 * log(s) / s);
    spare = v * s;
    return mu + sigma * (u * s);
}

/**
 * Calcula el máximo común divisor (MCD) de dos números enteros usando el algoritmo de Euclides.
 * @param a Primer número
 * @param b Segundo número
 * @return MCD de a y b
 * @example int r = mcd(18, 24); // r = 6
 */
int mcd(int a, int b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

/**
 * Calcula el mínimo común múltiplo (MCM) de dos números enteros.
 * @param a Primer número
 * @param b Segundo número
 * @return MCM de a y b
 * @example int r = mcm(18, 24); // r = 72
 */
int mcm(int a, int b) {
    if (a == 0 || b == 0) return 0;
    int res = mcd(a, b);
    return a * b / res;
}

/**
 * Calcula el máximo común divisor (MCD) de dos números usando la descomposición en factores primos.
 * @param a Primer número
 * @param b Segundo número
 * @return MCD de a y b
 * @example int r = mcd_descp(18, 24); // r = 6
 */
int mcd_descp(int a, int b) {
    if (a == 0 || b == 0) return 0;
    int fa[32], fb[32];
    int na = descomponerFactoresPrimos(a < 0 ? -a : a, fa);
    int nb = descomponerFactoresPrimos(b < 0 ? -b : b, fb);
    int res = 1;
    int i = 0, j = 0;
    while (i < na && j < nb) {
        if (fa[i] == fb[j]) {
            res *= fa[i];
            i++; j++;
        } else if (fa[i] < fb[j]) {
            i++;
        } else {
            j++;
        }
    }
    return res;
}

/**
 * Calcula el mínimo común múltiplo (MCM) de dos números usando la descomposición en factores primos.
 * @param a Primer número
 * @param b Segundo número
 * @return MCM de a y b
 * @example int r = mcm_descp(18, 24); // r = 72
 */
int mcm_descp(int a, int b) {
    if (a == 0 || b == 0) return 0;
    int fa[32], fb[32];
    int na = descomponerFactoresPrimos(a < 0 ? -a : a, fa);
    int nb = descomponerFactoresPrimos(b < 0 ? -b : b, fb);
    int res = 1;
    int i = 0, j = 0;
    while (i < na || j < nb) {
        if (i < na && (j >= nb || fa[i] < fb[j])) {
            res *= fa[i];
            i++;
        } else if (j < nb && (i >= na || fb[j] < fa[i])) {
            res *= fb[j];
            j++;
        } else {
            res *= fa[i];
            i++; j++;
        }
    }
    return res;
}

/**
 * Calcula el máximo común divisor (MCD) de un array de números enteros.
 * Utiliza el algoritmo de Euclides de forma iterativa.
 * @param valores Array de enteros (no debe ser NULL)
 * @param n Número de elementos del array (debe ser mayor que 0)
 * @return MCD de todos los valores del array, o 0 si n <= 0
 * @example int nums[] = {12, 18, 24, 30}; int r = mcd_n(nums, 4); // r = 6
 */
int mcd_n(const int *valores, int n) 
{
    if (valores == NULL || n <= 0) return 0;
    int resultado = valores[0];
    for (int i = 1; i < n; i++) 
	{
        resultado = mcd(resultado, valores[i]);
        if (resultado == 1) break;
    }
    return resultado;
}

/**
 * Calcula el mínimo común múltiplo (MCM) de un array de números enteros.
 * Utiliza la relación mcm(a, b) = |a * b| / mcd(a, b) de forma iterativa.
 * @param valores Array de enteros (no debe ser NULL)
 * @param n Número de elementos del array (debe ser mayor que 0)
 * @return MCM de todos los valores del array, o 0 si n <= 0
 * @example int nums[] = {12, 18, 24, 30}; int r = mcm_n(nums, 4); // r = 120
 */
int mcm_n(const int *valores, int n) 
{
    if (valores == NULL || n <= 0) return 0;
    int resultado = valores[0];
    for (int i = 1; i < n; i++) 
	{
        resultado = mcm(resultado, valores[i]);
        if (resultado == 0) break;
    }
    return resultado;
}

/**
 * Calcula la distancia entre dos letras en el teclado QWERTY (solo letras a-z, case-insensitive)
 * se considera que la distancia vertical es 0.5 y la horizontal es 1
 * @param a Letra origen
 * @param b Letra destino
 * @return Distancia euclídea entre las letras en el teclado
 * @example float d = distanciaTecladoQWERTY('f', 't'); // d = 0.5
 */
float distanciaTecladoQWERTY(char a, char b) {
    static const char *filas[] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
    int pos[2][2];
    char letras[2] = {a, b};
    for (int k = 0; k < 2; k++) 
    {
        char c = tolower(letras[k]);
        int found = 0;
        for (int f = 0; f < 3 && !found; f++) 
        {
            const char *row = filas[f];
            for (int col = 0; row[col]; col++) 
            {
                if (row[col] == c) 
                {
                    pos[k][0] = col;
                    pos[k][1] = f;
                    found = 1;
                    break;
                }
            }
        }
        if (!found) return -1.0f;
    }
    int dx = abs(pos[0][0] - pos[1][0]);
    int dy = abs(pos[0][1] - pos[1][1]);
    float dist = dx * 1.0f + dy * 0.5f;
    return dist;
}
























palabra encriptar(palabra p, codigo c){return NULL;} //throw new UnimplementedError();
palabra desencriptar(palabra p, codigo c){return NULL;} //throw new UnimplementedError();
palabra sindrome(palabra p, codigo c){return NULL;} //throw new UnimplementedError();
codigo generarG_estandar(int a, int b){codigo c; return c;} //throw new UnimplementedError();
int peso(palabra p){return 1;} //throw new UnimplementedError();
void *normalizarG(codigo* c){return NULL;} //throw new UnimplementedError();
int H2G_estandar(codigo* c){return 1;} //throw new UnimplementedError();
int G2H_estandar(codigo* c){return 1;} //throw new UnimplementedError();
int calcularS(codigo* c){return 1;} //throw new UnimplementedError();
int calcularT(codigo* c){return 1;} //throw new UnimplementedError();
int calcularNyM(codigo* c){return 1;} //throw new UnimplementedError();
int calcularD(codigo* c){return 1;} //throw new UnimplementedError();
codigo generarCodigoInicializado(byte_t** b){codigo c; return c;} //throw new UnimplementedError();
codigo generarHamming(int n){codigo c; return c;} //throw new UnimplementedError();
bit_t sacarBit(short int s){return __1;} //throw new UnimplementedError();
boolean bitEsDeInfo(bit_t** b, int i, int j){return FALSE;} //throw new UnimplementedError();



hiperplano leerPlano(int dimension) { hiperplano h; return h; }
void imprimirPlano(hiperplano h) { (void)h; }
hiperplano hijo(hiperplano h, int n) { (void)h; (void)n; hiperplano res; return res; }
hiperplano planoOrtogonal(hiperplano h, int n) { (void)h; (void)n; hiperplano res; return res; }











// --- Algoritmos de planificación de procesos ---

/**
 * Inicializa un proceso con los valores dados.
 * @param p Puntero al proceso a inicializar
 * @param pid Identificador del proceso
 * @param turnoLlegada Instante en el que el proceso comienza a pedir ejecución
 * @param tiempoEjecucion Número de turnos que necesita para ejecutarse
 * @return EXITO si todo va bien, FALLO o SUPERFALLO si hay error
 * @example proceso p; inicializarProcesoPid(&p, 1, 0, 5);
 */
int inicializarProcesoPid(proceso *p, int pid, int turnoLlegada, int tiempoEjecucion) {
    if (!p || tiempoEjecucion < 0 || pid < 0 || turnoLlegada < 0) return SUPERFALLO;
    p->pid = pid;
    p->turnoLlegada = turnoLlegada;
    p->tiempoEjecucion = tiempoEjecucion;
    p->tiempoRestante = tiempoEjecucion;
    p->tiempoEspera = -1;
    p->tiempoRespuesta = -1;
    p->tiempoRetorno = -1;
    return EXITO;
}

/**
 * Planificación First Come First Serve (FCFS).
 * Ejecuta los procesos en orden de llegada, sin interrupciones.
 * Desempata por menor tiempoEjecucion y después por posición en el array.
 * @param sistema Estructura ssoo con los procesos y parámetros inicializados
 * @return ssoo actualizado tras la planificación
 */
ssoo proc_FCFS(ssoo sistema) {
    if (!sistema.procesos || sistema.numProcesos <= 0) { sistema.codigoError = SUPERFALLO; return sistema; }
    int turnos = 0, completados = 0, actual = -1;
    int totalTurnos = 0;
    for (int i = 0; i < sistema.numProcesos; i++)
        totalTurnos += sistema.procesos[i].tiempoEjecucion;
    int tamEjecutados = totalTurnos + 1;
    int *ejecutados = malloc(sizeof(int) * tamEjecutados);
    if (!ejecutados) { sistema.codigoError = SUPERFALLO; return sistema; }
    for (int i = 0; i < sistema.numProcesos; i++)
    {
        sistema.procesos[i].tiempoRestante = sistema.procesos[i].tiempoEjecucion;
        sistema.procesos[i].tiempoEspera = 0;
        sistema.procesos[i].tiempoRetorno = -1;
        sistema.procesos[i].tiempoRespuesta = -1;
    }
    int tiempo = 0;
    while (completados < sistema.numProcesos)
    {
        int elegido = -1;
        for (int i = 0; i < sistema.numProcesos; i++)
        {
            if (sistema.procesos[i].tiempoRestante > 0 && sistema.procesos[i].turnoLlegada <= tiempo)
            {
                if (elegido == -1 ||
                    sistema.procesos[i].turnoLlegada < sistema.procesos[elegido].turnoLlegada ||
                    (sistema.procesos[i].turnoLlegada == sistema.procesos[elegido].turnoLlegada &&
                     (sistema.procesos[i].tiempoEjecucion < sistema.procesos[elegido].tiempoEjecucion ||
                      (sistema.procesos[i].tiempoEjecucion == sistema.procesos[elegido].tiempoEjecucion && i < elegido))))
                {
                    elegido = i;
                }
            }
        }
        if (elegido == -1)
        {
            tiempo++;
            continue;
        }
        actual = elegido;
        while (sistema.procesos[actual].tiempoRestante > 0)
        {
            if (turnos >= tamEjecutados)
            {
                tamEjecutados *= 2;
                int *nuevo = realloc(ejecutados, sizeof(int) * tamEjecutados);
                if (!nuevo) { free(ejecutados); sistema.codigoError = SUPERFALLO; return sistema; }
                ejecutados = nuevo;
            }
            ejecutados[turnos++] = sistema.procesos[actual].pid;
            for (int j = 0; j < sistema.numProcesos; j++)
                if (j != actual && sistema.procesos[j].tiempoRestante > 0 && sistema.procesos[j].turnoLlegada <= tiempo)
                    sistema.procesos[j].tiempoEspera++;
            sistema.procesos[actual].tiempoRestante--;
            tiempo++;
        }
        sistema.procesos[actual].tiempoRetorno = tiempo - sistema.procesos[actual].turnoLlegada;
        sistema.procesos[actual].tiempoRespuesta = (float)(sistema.procesos[actual].tiempoEspera + sistema.procesos[actual].tiempoEjecucion) / sistema.procesos[actual].tiempoEjecucion;
        completados++;
    }
    sistema.numeroTotalTurnos = turnos;
    sistema.pidsTurnos = malloc(sizeof(int) * turnos);
    for (int i = 0; i < turnos; i++) sistema.pidsTurnos[i] = ejecutados[i];
    float suma = 0;
    for (int i = 0; i < sistema.numProcesos; i++) suma += sistema.procesos[i].tiempoRetorno * sistema.procesos[i].tiempoRetorno;
    sistema.tiempoPromedio = suma / sistema.numProcesos;
    float tiempoTotal = sistema.tiempoTurno;
    int ultimoProceso = ejecutados[0];
    for (int i = 1; i < sistema.numeroTotalTurnos; i++) {
        actual = ejecutados[i];
        if (ultimoProceso != actual) {
            tiempoTotal += sistema.tiempoCambioProceso;
        }
        tiempoTotal += sistema.tiempoTurno;
        ultimoProceso = actual;
    }
    sistema.tiempoTotal = tiempoTotal;
    sistema.codigoError = EXITO;
    free(ejecutados);
    return sistema;
}

/**
 * Planificación Round Robin (RR).
 * Ejecuta los procesos en orden de llegada, pero ningún proceso puede estar más de 'cuanto' turnos seguidos.
 * Desempata por menor turnoLlegada, luego menor tiempoEjecucion, luego posición en el array.
 * @param sistema Estructura ssoo con los procesos y parámetros inicializados
 * @return ssoo actualizado tras la planificación
 */
ssoo proc_RR(ssoo sistema) 
{
    if (!sistema.procesos || sistema.numProcesos <= 0 || sistema.cuanto <= 0) { sistema.codigoError = SUPERFALLO; return sistema; }
    int turnos = 0, completados = 0, actual = -1;
    int totalTurnos = 0;
    for (int i = 0; i < sistema.numProcesos; i++) totalTurnos += sistema.procesos[i].tiempoEjecucion;
    int tamEjecutados = totalTurnos + 1;
    int *ejecutados = malloc(sizeof(int) * tamEjecutados);
    if (!ejecutados) { sistema.codigoError = SUPERFALLO; return sistema; }
    Cola cola;
    colaCreaVacia(&cola);
    for (int i = 0; i < sistema.numProcesos; i++) 
	{
        sistema.procesos[i].tiempoRestante = sistema.procesos[i].tiempoEjecucion;
        sistema.procesos[i].tiempoEspera = 0;
        sistema.procesos[i].tiempoRetorno = -1;
        sistema.procesos[i].tiempoRespuesta = -1;
    }
    int tiempo = 0;
    int *enCola = calloc(sistema.numProcesos, sizeof(int));
    while (completados < sistema.numProcesos)
	{
        int *nuevos = malloc(sizeof(int) * sistema.numProcesos);
        int numNuevos = 0;
        for (int i = 0; i < sistema.numProcesos; i++)
            if (!enCola[i] && sistema.procesos[i].turnoLlegada <= tiempo && sistema.procesos[i].tiempoRestante > 0)
                nuevos[numNuevos++] = i;
        if (numNuevos > 1) {
            for (int i = 0; i < numNuevos-1; i++) {
                for (int j = i+1; j < numNuevos; j++) {
                    int a = nuevos[i], b = nuevos[j];
                    if (sistema.procesos[a].turnoLlegada > sistema.procesos[b].turnoLlegada ||
                        (sistema.procesos[a].turnoLlegada == sistema.procesos[b].turnoLlegada &&
                         (sistema.procesos[a].tiempoEjecucion > sistema.procesos[b].tiempoEjecucion ||
                          (sistema.procesos[a].tiempoEjecucion == sistema.procesos[b].tiempoEjecucion && a > b)))) {
                        int tmp = nuevos[i]; nuevos[i] = nuevos[j]; nuevos[j] = tmp;
                    }
                }
            }
        }
        for (int k = 0; k < numNuevos; k++) 
		{
            colaInserta(nuevos[k], &cola);
            enCola[nuevos[k]] = 1;
        }
        free(nuevos);
        if (colaVacia(&cola)) 
		{
            tiempo++;
            continue;
        }
        actual = colaSuprime(&cola);
        int quantum = 0;
        while (sistema.procesos[actual].tiempoRestante > 0 && quantum < sistema.cuanto) 
		{
            if (turnos >= tamEjecutados) 
			{
                tamEjecutados *= 2;
                int *nuevo = realloc(ejecutados, sizeof(int) * tamEjecutados);
                if (!nuevo) { free(ejecutados); sistema.codigoError = SUPERFALLO; return sistema; }
                ejecutados = nuevo;
            }
            ejecutados[turnos++] = sistema.procesos[actual].pid;
            for (int j = 0; j < sistema.numProcesos; j++)
                if (j != actual && sistema.procesos[j].tiempoRestante > 0 && sistema.procesos[j].turnoLlegada <= tiempo)
                    sistema.procesos[j].tiempoEspera++;
            sistema.procesos[actual].tiempoRestante--;
            tiempo++;
            quantum++;
            int *nuevos2 = malloc(sizeof(int) * sistema.numProcesos);
            int numNuevos2 = 0;
            for (int i = 0; i < sistema.numProcesos; i++)
                if (!enCola[i] && sistema.procesos[i].turnoLlegada <= tiempo && sistema.procesos[i].tiempoRestante > 0)
                    nuevos2[numNuevos2++] = i;
            if (numNuevos2 > 1) 
			{
                for (int i = 0; i < numNuevos2-1; i++) 
				{
                    for (int j = i+1; j < numNuevos2; j++) 
					{
                        int a = nuevos2[i], b = nuevos2[j];
                        if (sistema.procesos[a].turnoLlegada > sistema.procesos[b].turnoLlegada ||
                            (sistema.procesos[a].turnoLlegada == sistema.procesos[b].turnoLlegada &&
                             (sistema.procesos[a].tiempoEjecucion > sistema.procesos[b].tiempoEjecucion ||
                              (sistema.procesos[a].tiempoEjecucion == sistema.procesos[b].tiempoEjecucion && a > b)))){
								int tmp = nuevos2[i]; nuevos2[i] = nuevos2[j]; nuevos2[j] = tmp;
							  }
                    }
                }
            }
            for (int k = 0; k < numNuevos2; k++) 
			{
                colaInserta(nuevos2[k], &cola);
                enCola[nuevos2[k]] = 1;
            }
            free(nuevos2);
        }
        if (sistema.procesos[actual].tiempoRestante > 0) 
		{
            colaInserta(actual, &cola);
        } else 
		{
            sistema.procesos[actual].tiempoRetorno = tiempo - sistema.procesos[actual].turnoLlegada;
            sistema.procesos[actual].tiempoRespuesta = (float)(sistema.procesos[actual].tiempoEspera + sistema.procesos[actual].tiempoEjecucion) / sistema.procesos[actual].tiempoEjecucion;
            completados++;
        }
    }
    sistema.numeroTotalTurnos = turnos;
    sistema.pidsTurnos = malloc(sizeof(int) * turnos);
    for (int i = 0; i < turnos; i++) sistema.pidsTurnos[i] = ejecutados[i];
    float suma = 0;
    for (int i = 0; i < sistema.numProcesos; i++) suma += sistema.procesos[i].tiempoRetorno * sistema.procesos[i].tiempoRetorno;
    sistema.tiempoPromedio = suma / sistema.numProcesos;
    float tiempoTotal = sistema.tiempoTurno;
    int ultimoProceso = ejecutados[0];
    for (int i = 1; i < sistema.numeroTotalTurnos; i++) 
	{
        actual = ejecutados[i];
        if (ultimoProceso != actual) tiempoTotal += sistema.tiempoCambioProceso;
        tiempoTotal += sistema.tiempoTurno;
        ultimoProceso = actual;
    }
    sistema.tiempoTotal = tiempoTotal;
    sistema.codigoError = EXITO;
    free(ejecutados); free(enCola);
    return sistema;
}

/**
 * Planificación Shortest Process Next (SPN).
 * Ejecuta el proceso con menor tiempoEjecucion entre los listos. Desempata por llegada y posición.
 * @param sistema Estructura ssoo con los procesos y parámetros inicializados
 * @return ssoo actualizado tras la planificación
 */
ssoo proc_SPN(ssoo sistema) 
{
    if (!sistema.procesos || sistema.numProcesos <= 0) { sistema.codigoError = SUPERFALLO; return sistema; }
    int turnos = 0, completados = 0, actual = -1;
    int totalTurnos = 0;
    for (int i = 0; i < sistema.numProcesos; i++) totalTurnos += sistema.procesos[i].tiempoEjecucion;
    int tamEjecutados = totalTurnos + 1;
    int *ejecutados = malloc(sizeof(int) * tamEjecutados);
    if (!ejecutados) { sistema.codigoError = SUPERFALLO; return sistema; }
    for (int i = 0; i < sistema.numProcesos; i++) 
	{
        sistema.procesos[i].tiempoRestante = sistema.procesos[i].tiempoEjecucion;
        sistema.procesos[i].tiempoEspera = 0;
        sistema.procesos[i].tiempoRetorno = -1;
        sistema.procesos[i].tiempoRespuesta = -1;
    }
    int tiempo = 0;
    while (completados < sistema.numProcesos) 
	{
        int elegido = -1;
        for (int i = 0; i < sistema.numProcesos; i++) 
		{
            if (sistema.procesos[i].tiempoRestante > 0 && sistema.procesos[i].turnoLlegada <= tiempo) 
			{
                if (elegido == -1 ||
                    sistema.procesos[i].tiempoEjecucion < sistema.procesos[elegido].tiempoEjecucion ||
                    (sistema.procesos[i].tiempoEjecucion == sistema.procesos[elegido].tiempoEjecucion &&
                     (sistema.procesos[i].turnoLlegada < sistema.procesos[elegido].turnoLlegada ||
                      (sistema.procesos[i].turnoLlegada == sistema.procesos[elegido].turnoLlegada && i < elegido))))
                    	elegido = i;
            }
        }
        if (elegido == -1) { tiempo++; continue; }
        int actual = elegido;
        while (sistema.procesos[actual].tiempoRestante > 0) 
		{
            if (turnos >= tamEjecutados) 
			{
                tamEjecutados *= 2;
                int *nuevo = realloc(ejecutados, sizeof(int) * tamEjecutados);
                if (!nuevo) { free(ejecutados); sistema.codigoError = SUPERFALLO; return sistema; }
                ejecutados = nuevo;
            }
            ejecutados[turnos++] = sistema.procesos[actual].pid;
            for (int j = 0; j < sistema.numProcesos; j++)
                if (j != actual && sistema.procesos[j].tiempoRestante > 0 && sistema.procesos[j].turnoLlegada <= tiempo)
                    sistema.procesos[j].tiempoEspera++;
            sistema.procesos[actual].tiempoRestante--;
            tiempo++;
        }
        sistema.procesos[actual].tiempoRetorno = tiempo - sistema.procesos[actual].turnoLlegada;
        sistema.procesos[actual].tiempoRespuesta = (float)(sistema.procesos[actual].tiempoEspera + sistema.procesos[actual].tiempoEjecucion) / sistema.procesos[actual].tiempoEjecucion;
        completados++;
    }
    sistema.numeroTotalTurnos = turnos;
    sistema.pidsTurnos = malloc(sizeof(int) * turnos);
    for (int i = 0; i < turnos; i++) sistema.pidsTurnos[i] = ejecutados[i];
    float suma = 0;
    for (int i = 0; i < sistema.numProcesos; i++) suma += sistema.procesos[i].tiempoRetorno * sistema.procesos[i].tiempoRetorno;
    sistema.tiempoPromedio = suma / sistema.numProcesos;
    float tiempoTotal = sistema.tiempoTurno;
    int ultimoProceso = ejecutados[0];
    for (int i = 1; i < sistema.numeroTotalTurnos; i++) 
	{
        actual = ejecutados[i];
        if (ultimoProceso != actual) tiempoTotal += sistema.tiempoCambioProceso;
        tiempoTotal += sistema.tiempoTurno;
        ultimoProceso = actual;
    }
    sistema.tiempoTotal = tiempoTotal;
    sistema.codigoError = EXITO;
    free(ejecutados);
    return sistema;
}

/**
 * Planificación Shortest Remaining Next (SRN).
 * Ejecuta el proceso con menor tiempoRestante entre los listos. Desempata por llegada y posición.
 * @param sistema Estructura ssoo con los procesos y parámetros inicializados
 * @return ssoo actualizado tras la planificación
 */
ssoo proc_SRN(ssoo sistema) 
{
    if (!sistema.procesos || sistema.numProcesos <= 0) { sistema.codigoError = SUPERFALLO; return sistema; }
    int turnos = 0, completados = 0, actual = -1;
    int totalTurnos = 0;
    for (int i = 0; i < sistema.numProcesos; i++) totalTurnos += sistema.procesos[i].tiempoEjecucion;
    int tamEjecutados = totalTurnos + 1;
    int *ejecutados = malloc(sizeof(int) * tamEjecutados);
    if (!ejecutados) { sistema.codigoError = SUPERFALLO; return sistema; }
    for (int i = 0; i < sistema.numProcesos; i++) 
	{
        sistema.procesos[i].tiempoRestante = sistema.procesos[i].tiempoEjecucion;
        sistema.procesos[i].tiempoEspera = 0;
        sistema.procesos[i].tiempoRetorno = -1;
        sistema.procesos[i].tiempoRespuesta = -1;
    }
    int tiempo = 0;
    while (completados < sistema.numProcesos) 
	{
        int elegido = -1;
        for (int i = 0; i < sistema.numProcesos; i++) {
            if (sistema.procesos[i].tiempoRestante > 0 && sistema.procesos[i].turnoLlegada <= tiempo) 
			{
                if (elegido == -1 ||
                    sistema.procesos[i].tiempoRestante < sistema.procesos[elegido].tiempoRestante ||
                    (sistema.procesos[i].tiempoRestante == sistema.procesos[elegido].tiempoRestante &&
                     (sistema.procesos[i].turnoLlegada < sistema.procesos[elegido].turnoLlegada ||
                      (sistema.procesos[i].turnoLlegada == sistema.procesos[elegido].turnoLlegada && i < elegido)))) 
                        elegido = i;
            }
        }
        if (elegido == -1) { tiempo++; continue; }
        int actual = elegido;
        if (turnos >= tamEjecutados) 
		{
            tamEjecutados *= 2;
            int *nuevo = realloc(ejecutados, sizeof(int) * tamEjecutados);
            if (!nuevo) { free(ejecutados); sistema.codigoError = SUPERFALLO; return sistema; }
            ejecutados = nuevo;
        }
        ejecutados[turnos++] = sistema.procesos[actual].pid;
        for (int j = 0; j < sistema.numProcesos; j++)
            if (j != actual && sistema.procesos[j].tiempoRestante > 0 && sistema.procesos[j].turnoLlegada <= tiempo)
                sistema.procesos[j].tiempoEspera++;
        sistema.procesos[actual].tiempoRestante--;
        tiempo++;
        if (sistema.procesos[actual].tiempoRestante == 0) 
		{
            sistema.procesos[actual].tiempoRetorno = tiempo - sistema.procesos[actual].turnoLlegada;
            sistema.procesos[actual].tiempoRespuesta = (float)(sistema.procesos[actual].tiempoEspera + sistema.procesos[actual].tiempoEjecucion) / sistema.procesos[actual].tiempoEjecucion;
            completados++;
        }
    }
    sistema.numeroTotalTurnos = turnos;
    sistema.pidsTurnos = malloc(sizeof(int) * turnos);
    for (int i = 0; i < turnos; i++) sistema.pidsTurnos[i] = ejecutados[i];
    float suma = 0;
    for (int i = 0; i < sistema.numProcesos; i++) suma += sistema.procesos[i].tiempoRetorno * sistema.procesos[i].tiempoRetorno;
    sistema.tiempoPromedio = suma / sistema.numProcesos;
    float tiempoTotal = sistema.tiempoTurno;
    int ultimoProceso = ejecutados[0];
    for (int i = 1; i < sistema.numeroTotalTurnos; i++) 
	{
		actual = ejecutados[i];
        if (ultimoProceso != actual) tiempoTotal += sistema.tiempoCambioProceso;
        tiempoTotal += sistema.tiempoTurno;
        ultimoProceso = actual;
    }
    sistema.tiempoTotal = tiempoTotal;
    sistema.codigoError = EXITO;
    free(ejecutados);
    return sistema;
}

/**
 * Planificación Highest Response Ratio Next (HRRN).
 * Ejecuta el proceso con menor tiempoRespuesta entre los listos. Desempata por llegada y posición.
 * @param sistema Estructura ssoo con los procesos y parámetros inicializados
 * @return ssoo actualizado tras la planificación
 
 */
ssoo proc_HRRN(ssoo sistema) 
{
    if (!sistema.procesos || sistema.numProcesos <= 0) { sistema.codigoError = SUPERFALLO; return sistema; }
    int turnos = 0, completados = 0, actual = -1;
    int totalTurnos = 0;
    for (int i = 0; i < sistema.numProcesos; i++) totalTurnos += sistema.procesos[i].tiempoEjecucion;
    int tamEjecutados = totalTurnos + 1;
    int *ejecutados = malloc(sizeof(int) * tamEjecutados);
    if (!ejecutados) { sistema.codigoError = SUPERFALLO; return sistema; }
    for (int i = 0; i < sistema.numProcesos; i++) 
	{
        sistema.procesos[i].tiempoRestante = sistema.procesos[i].tiempoEjecucion;
        sistema.procesos[i].tiempoEspera = 0;
        sistema.procesos[i].tiempoRetorno = -1;
        sistema.procesos[i].tiempoRespuesta = -1;
    }
    int tiempo = 0;
    while (completados < sistema.numProcesos) 
	{
        int elegido = -1;
        float mejorRespuesta = -1.0f;
        for (int i = 0; i < sistema.numProcesos; i++) 
		{
            if (sistema.procesos[i].tiempoRestante > 0 && sistema.procesos[i].turnoLlegada <= tiempo) 
			{
                float respuesta = (float)(sistema.procesos[i].tiempoEspera + sistema.procesos[i].tiempoEjecucion) / sistema.procesos[i].tiempoEjecucion;
                if (elegido == -1 || respuesta > mejorRespuesta ||
                    (respuesta == mejorRespuesta &&
                     (sistema.procesos[i].turnoLlegada < sistema.procesos[elegido].turnoLlegada ||
                      (sistema.procesos[i].turnoLlegada == sistema.procesos[elegido].turnoLlegada && i < elegido)))) 
						{
							elegido = i;
							mejorRespuesta = respuesta;
						}
            }
        }
        if (elegido == -1) { tiempo++; continue; }
        actual = elegido;
        if (turnos >= tamEjecutados) 
		{
            tamEjecutados *= 2;
            int *nuevo = realloc(ejecutados, sizeof(int) * tamEjecutados);
            if (!nuevo) { free(ejecutados); sistema.codigoError = SUPERFALLO; return sistema; }
            ejecutados = nuevo;
        }
        ejecutados[turnos++] = sistema.procesos[actual].pid;
        for (int j = 0; j < sistema.numProcesos; j++)
            if (j != actual && sistema.procesos[j].tiempoRestante > 0 && sistema.procesos[j].turnoLlegada <= tiempo)
                sistema.procesos[j].tiempoEspera++;
        sistema.procesos[actual].tiempoRestante--;
        tiempo++;
        if (sistema.procesos[actual].tiempoRestante == 0)
		{
            sistema.procesos[actual].tiempoRetorno = tiempo - sistema.procesos[actual].turnoLlegada;
            sistema.procesos[actual].tiempoRespuesta = (float)(sistema.procesos[actual].tiempoEspera + sistema.procesos[actual].tiempoEjecucion) / sistema.procesos[actual].tiempoEjecucion;
            completados++;
        }
    }
    sistema.numeroTotalTurnos = turnos;
    sistema.pidsTurnos = malloc(sizeof(int) * turnos);
    for (int i = 0; i < turnos; i++) sistema.pidsTurnos[i] = ejecutados[i];
    float suma = 0;
    for (int i = 0; i < sistema.numProcesos; i++) suma += sistema.procesos[i].tiempoRetorno * sistema.procesos[i].tiempoRetorno;
    sistema.tiempoPromedio = suma / sistema.numProcesos;
    float tiempoTotal = sistema.tiempoTurno;
    int ultimoProceso = ejecutados[0];
    for (int i = 1; i < sistema.numeroTotalTurnos; i++) 
	{
        actual = ejecutados[i];
        if (ultimoProceso != actual) tiempoTotal += sistema.tiempoCambioProceso;
        tiempoTotal += sistema.tiempoTurno;
        ultimoProceso = actual;
    }
    sistema.tiempoTotal = tiempoTotal;
    sistema.codigoError = EXITO;
    free(ejecutados);
    return sistema;
}

/**
 * Planificación Retroalimentación (RA).
 * Mezcla de HRRN y RR, usando el cuanto para limitar la ejecución continua.
 * @param sistema Estructura ssoo con los procesos y parámetros inicializados
 * @return ssoo actualizado tras la planificación
 */
ssoo proc_RA(ssoo sistema) 
{
    if (!sistema.procesos || sistema.numProcesos <= 0 || sistema.cuanto <= 0) { sistema.codigoError = SUPERFALLO; return sistema; }
    int turnos = 0, completados = 0, actual = -1;
    int totalTurnos = 0;
    for (int i = 0; i < sistema.numProcesos; i++) totalTurnos += sistema.procesos[i].tiempoEjecucion;
    int tamEjecutados = totalTurnos + 1;
    int *ejecutados = malloc(sizeof(int) * tamEjecutados);
    if (!ejecutados) { sistema.codigoError = SUPERFALLO; return sistema; }
    Cola cola;
    colaCreaVacia(&cola);
    for (int i = 0; i < sistema.numProcesos; i++) 
	{
        sistema.procesos[i].tiempoRestante = sistema.procesos[i].tiempoEjecucion;
        sistema.procesos[i].tiempoEspera = 0;
        sistema.procesos[i].tiempoRetorno = -1;
        sistema.procesos[i].tiempoRespuesta = -1;
    }
    int tiempo = 0;
    int *enCola = calloc(sistema.numProcesos, sizeof(int));
    while (completados < sistema.numProcesos) 
	{
        for (int i = 0; i < sistema.numProcesos; i++) 
		{
            if (!enCola[i] && sistema.procesos[i].turnoLlegada <= tiempo && sistema.procesos[i].tiempoRestante > 0) 
			{
                colaInserta(i, &cola);
                enCola[i] = 1;
            }
        }
        if (colaVacia(&cola)) { tiempo++; continue; }
        // Selección del proceso con mayor ratio de respuesta, desempate por llegada y posición
        tipoCeldaC *mejorCelda = cola.frente, *antMejor = NULL, *ant = NULL, *act = cola.frente;
        float mejorResp = -1.0f;
        while (act) 
		{
            int idx = act->elemento;
            float resp = (float)(sistema.procesos[idx].tiempoEspera + sistema.procesos[idx].tiempoEjecucion) / sistema.procesos[idx].tiempoEjecucion;
            if (mejorCelda == NULL || resp > mejorResp || (resp == mejorResp && (sistema.procesos[idx].turnoLlegada < sistema.procesos[mejorCelda->elemento].turnoLlegada || (sistema.procesos[idx].turnoLlegada == sistema.procesos[mejorCelda->elemento].turnoLlegada && idx < mejorCelda->elemento)))) 
			{
                mejorCelda = act;
                mejorResp = resp;
                antMejor = ant;
            }
            ant = act;
            act = act->sig;
        }
        // Sacar el proceso seleccionado de la cola
        if (antMejor) antMejor->sig = mejorCelda->sig;
        else cola.frente = mejorCelda->sig;
        if (mejorCelda == cola.fondo) cola.fondo = antMejor;
        actual = mejorCelda->elemento;
        free(mejorCelda);
        int quantum = 0;
        while (sistema.procesos[actual].tiempoRestante > 0 && quantum < sistema.cuanto) 
		{
            if (turnos >= tamEjecutados)
			{
                tamEjecutados *= 2;
                int *nuevo = realloc(ejecutados, sizeof(int) * tamEjecutados);
                if (!nuevo) { free(ejecutados); sistema.codigoError = SUPERFALLO; return sistema; }
                ejecutados = nuevo;
            }
            ejecutados[turnos++] = sistema.procesos[actual].pid;
            for (int j = 0; j < sistema.numProcesos; j++)
                if (j != actual && sistema.procesos[j].tiempoRestante > 0 && sistema.procesos[j].turnoLlegada <= tiempo)
                    sistema.procesos[j].tiempoEspera++;
            sistema.procesos[actual].tiempoRestante--;
            tiempo++;
            quantum++;
            for (int i = 0; i < sistema.numProcesos; i++) 
			{
                if (!enCola[i] && sistema.procesos[i].turnoLlegada <= tiempo && sistema.procesos[i].tiempoRestante > 0) 
				{
                    colaInserta(i, &cola);
                    enCola[i] = 1;
                }
            }
        }
        if (sistema.procesos[actual].tiempoRestante > 0) 
		{
            colaInserta(actual, &cola);
        } else 
		{
            sistema.procesos[actual].tiempoRetorno = tiempo - sistema.procesos[actual].turnoLlegada;
            sistema.procesos[actual].tiempoRespuesta = (float)(sistema.procesos[actual].tiempoEspera + sistema.procesos[actual].tiempoEjecucion) / sistema.procesos[actual].tiempoEjecucion;
            completados++;
        }
    }
    sistema.numeroTotalTurnos = turnos;
    sistema.pidsTurnos = malloc(sizeof(int) * turnos);
    for (int i = 0; i < turnos; i++) sistema.pidsTurnos[i] = ejecutados[i];
    float suma = 0;
    for (int i = 0; i < sistema.numProcesos; i++) suma += sistema.procesos[i].tiempoRetorno * sistema.procesos[i].tiempoRetorno;
    sistema.tiempoPromedio = suma / sistema.numProcesos;
    float tiempoTotal = sistema.tiempoTurno;
    int ultimoProceso = ejecutados[0];
    for (int i = 1; i < sistema.numeroTotalTurnos; i++) 
	{
        actual = ejecutados[i];
        if (ultimoProceso != actual) tiempoTotal += sistema.tiempoCambioProceso;
        tiempoTotal += sistema.tiempoTurno;
        ultimoProceso = actual;
    }
    sistema.tiempoTotal = tiempoTotal;
    sistema.codigoError = EXITO;
    free(ejecutados); free(enCola);
    return sistema;
}






/**
 * Pausa la ejecución hasta que el usuario pulse Intro.
 * Mensaje fijo: "Pulsa intro para continuar..."
 * No depende del sistema operativo.
 * @return void
 */
void alwaysPause(void) {
    printf("Pulsa intro para continuar...");
    int c;
    do { c = getchar(); } while (c != '\n' && c != EOF);
}



/******************************* ORDENACIÓN CLÁSICA *******************************/

/**
 * Ordena un vector de enteros usando el algoritmo Bubble Sort.
 * @param v Vector de enteros
 * @param n Tamaño del vector
 * @return EXITO, FALLO o SUPERFALLO
 */
int bubbleSortI(int *v, int n)
{
    if (!v || n < 1) return FALLO;
    int i, j, tmp;
    for (i = 0; i < n-1; i++) 
        for (j = 0; j < n-i-1; j++) 
            if (v[j] > v[j+1])
                tmp = v[j]; v[j] = v[j+1]; v[j+1] = tmp;
    return EXITO;
}

/**
 * Ordena un vector de floats usando el algoritmo Bubble Sort.
 * @param v Vector de floats
 * @param n Tamaño del vector
 * @return EXITO, FALLO o SUPERFALLO
 */
int bubbleSortF(float *v, int n) 
{
    if (!v || n < 1) return FALLO;
    int i, j;
    float tmp;
    for (i = 0; i < n-1; i++)
        for (j = 0; j < n-i-1; j++)
            if (v[j] > v[j+1])
                tmp = v[j]; v[j] = v[j+1]; v[j+1] = tmp;
    return EXITO;
}

/**
 * Ordena un vector de enteros usando el algoritmo Selection Sort.
 * @param v Vector de enteros
 * @param n Tamaño del vector
 * @return EXITO, FALLO o SUPERFALLO
 */
int selectionSortI(int *v, int n)
{
    if (!v || n < 1) return FALLO;
    int i, j, min, tmp;
    for (i = 0; i < n-1; i++) 
	{
        min = i;
        for (j = i+1; j < n; j++)
            if (v[j] < v[min]) min = j;
        tmp = v[i]; v[i] = v[min]; v[min] = tmp;
    }
    return EXITO;
}
/**
 * Ordena un vector de floats usando el algoritmo Selection Sort.
 * @param v Vector de floats
 * @param n Tamaño del vector
 * @return EXITO, FALLO o SUPERFALLO
 */
int selectionSortF(float *v, int n) 
{
    if (!v || n < 1) return FALLO;
    int i, j, min;
    float tmp;
    for (i = 0; i < n-1; i++) 
	{
        min = i;
        for (j = i+1; j < n; j++)
            if (v[j] < v[min]) min = j;
        tmp = v[i]; v[i] = v[min]; v[min] = tmp;
    }
    return EXITO;
}

/**
 * Ordena un vector de enteros usando el algoritmo Insertion Sort.
 * @param v Vector de enteros
 * @param n Tamaño del vector
 * @return EXITO, FALLO o SUPERFALLO
 */
int insertionSortI(int *v, int n) 
{
    if (!v || n < 1) return FALLO;
    int i, j, key;
    for (i = 1; i < n; i++) 
	{
        key = v[i];
        j = i - 1;
        while (j >= 0 && v[j] > key)
		{
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = key;
    }
    return EXITO;
}
/**
 * Ordena un vector de floats usando el algoritmo Insertion Sort.
 * @param v Vector de floats
 * @param n Tamaño del vector
 * @return EXITO, FALLO o SUPERFALLO
 */
int insertionSortF(float *v, int n) 
{
    if (!v || n < 1) return FALLO;
    int i, j;
    float key;
    for (i = 1; i < n; i++) 
	{
        key = v[i];
        j = i - 1;
        while (j >= 0 && v[j] > key) 
		{
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = key;
    }
    return EXITO;
}

// --- MERGE SORT AUXILIARES ---
static void mergeI(int *v, int l, int m, int r) 
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));
    for (i = 0; i < n1; i++) L[i] = v[l + i];
    for (j = 0; j < n2; j++) R[j] = v[m + 1 + j];
    i = 0; j = 0; k = l;
    while (i < n1 && j < n2) 
	{
        if (L[i] <= R[j]) v[k++] = L[i++];
        else v[k++] = R[j++];
    }
    while (i < n1) v[k++] = L[i++];
    while (j < n2) v[k++] = R[j++];
    free(L); free(R);
}
static void mergeSortRecI(int *v, int l, int r) 
{
    if (l < r) 
	{
        int m = l + (r - l) / 2;
        mergeSortRecI(v, l, m);
        mergeSortRecI(v, m+1, r);
        mergeI(v, l, m, r);
    }
}
static void mergeF(float *v, int l, int m, int r) 
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    float *L = malloc(n1 * sizeof(float));
    float *R = malloc(n2 * sizeof(float));
    for (i = 0; i < n1; i++) L[i] = v[l + i];
    for (j = 0; j < n2; j++) R[j] = v[m + 1 + j];
    i = 0; j = 0; k = l;
    while (i < n1 && j < n2) 
	{
        if (L[i] <= R[j]) v[k++] = L[i++];
        else v[k++] = R[j++];
    }
    while (i < n1) v[k++] = L[i++];
    while (j < n2) v[k++] = R[j++];
    free(L); free(R);
}
static void mergeSortRecF(float *v, int l, int r) 
{
    if (l < r) 
	{
        int m = l + (r - l) / 2;
        mergeSortRecF(v, l, m);
        mergeSortRecF(v, m+1, r);
        mergeF(v, l, m, r);
    }
}
/**
 * Ordena un vector de enteros usando el algoritmo Merge Sort.
 * @param v Vector de enteros
 * @param n Tamaño del vector
 * @return EXITO, FALLO o SUPERFALLO
 */
int mergeSortI(int *v, int n) 
{
    if (!v || n < 1) return FALLO;
    mergeSortRecI(v, 0, n-1);
    return EXITO;
}
/**
 * Ordena un vector de floats usando el algoritmo Merge Sort.
 * @param v Vector de floats
 * @param n Tamaño del vector
 * @return EXITO, FALLO o SUPERFALLO
 */
int mergeSortF(float *v, int n) 
{
    if (!v || n < 1) return FALLO;
    mergeSortRecF(v, 0, n-1);
    return EXITO;
}

// --- QUICK SORT AUXILIARES ---
static int partitionI(int *v, int low, int high) 
{
    int pivot = v[high];
    int i = (low - 1), tmp;
    for (int j = low; j < high; j++) 
	{
        if (v[j] < pivot) 
		{
            i++;
            tmp = v[i]; v[i] = v[j]; v[j] = tmp;
        }
    }
    tmp = v[i+1]; v[i+1] = v[high]; v[high] = tmp;
    return i+1;
}
static void quickSortRecI(int *v, int low, int high) 
{
    if (low < high) 
	{
        int pi = partitionI(v, low, high);
        quickSortRecI(v, low, pi - 1);
        quickSortRecI(v, pi + 1, high);
    }
}
static int partitionF(float *v, int low, int high) 
{
    float pivot = v[high];
    int i = (low - 1);
    float tmp;
    for (int j = low; j < high; j++) 
	{
        if (v[j] < pivot) 
		{
            i++;
            tmp = v[i]; v[i] = v[j]; v[j] = tmp;
        }
    }
    tmp = v[i+1]; v[i+1] = v[high]; v[high] = tmp;
    return i+1;
}
static void quickSortRecF(float *v, int low, int high) 
{
    if (low < high) 
	{
        int pi = partitionF(v, low, high);
        quickSortRecF(v, low, pi - 1);
        quickSortRecF(v, pi + 1, high);
    }
}
/**
 * Ordena un vector de enteros usando el algoritmo Quick Sort.
 * @param v Vector de enteros
 * @param n Tamaño del vector
 * @return EXITO, FALLO o SUPERFALLO
 */
int quickSortI(int *v, int n) 
{
    if (!v || n < 1) return FALLO;
    quickSortRecI(v, 0, n-1);
    return EXITO;
}
/**
 * Ordena un vector de floats usando el algoritmo Quick Sort.
 * @param v Vector de floats
 * @param n Tamaño del vector
 * @return EXITO, FALLO o SUPERFALLO
 */
int quickSortF(float *v, int n) 
{
    if (!v || n < 1) return FALLO;
    quickSortRecF(v, 0, n-1);
    return EXITO;
}

/**
 * Ordena un vector de enteros usando el algoritmo Shell Sort.
 * @param v Vector de enteros
 * @param n Tamaño del vector
 * @return EXITO, FALLO o SUPERFALLO
 */
int shellSortI(int *v, int n) 
{
    if (!v || n < 1) return FALLO;
    int gap, i, j, temp;
    for (gap = n/2; gap > 0; gap /= 2) 
	{
        for (i = gap; i < n; i++) 
		{
            temp = v[i];
            for (j = i; j >= gap && v[j-gap] > temp; j -= gap)  v[j] = v[j-gap];
            v[j] = temp;
        }
    }
    return EXITO;
}
/**
 * Ordena un vector de floats usando el algoritmo Shell Sort.
 * @param v Vector de floats
 * @param n Tamaño del vector
 * @return EXITO, FALLO o SUPERFALLO
 */
int shellSortF(float *v, int n) 
{
    if (!v || n < 1) return FALLO;
    int gap, i, j;
    float temp;
    for (gap = n/2; gap > 0; gap /= 2) 
	{
        for (i = gap; i < n; i++) 
		{
            temp = v[i];
            for (j = i; j >= gap && v[j-gap] > temp; j -= gap) v[j] = v[j-gap];
            v[j] = temp;
        }
    }
    return EXITO;
}

/**
 * Ordena un vector de enteros usando el algoritmo Gnome Sort.
 * @param v Vector de enteros
 * @param n Tamaño del vector
 * @return EXITO, FALLO o SUPERFALLO
 */
int gnomeSortI(int *v, int n) 
{
    if (!v || n < 1) return FALLO;
    int i = 0, tmp;
    while (i < n) 
	{
        if (i == 0 || v[i-1] <= v[i]) i++;
        else { tmp = v[i]; v[i] = v[i-1]; v[i-1] = tmp; i--; }
    }
    return EXITO;
}

/**
 * Ordena un vector de floats usando el algoritmo Gnome Sort.
 * @param v Vector de floats
 * @param n Tamaño del vector
 * @return EXITO, FALLO o SUPERFALLO
 */
int gnomeSortF(float *v, int n) 
{
    if (!v || n < 1) return FALLO;
    int i = 0;
    float tmp;
    while (i < n) 
	{
        if (i == 0 || v[i-1] <= v[i]) i++;
        else { tmp = v[i]; v[i] = v[i-1]; v[i-1] = tmp; i--; }
    }
    return EXITO;
}

/**
 * Ordena un vector de enteros usando el algoritmo Comb Sort.
 * @param v Vector de enteros
 * @param n Tamaño del vector
 * @return EXITO, FALLO o SUPERFALLO
 */
int combSortI(int *v, int n) 
{
    if (!v || n < 1) return FALLO;
    int gap = n, i, swapped = 1, tmp;
    while (gap > 1 || swapped) 
	{
        if (gap > 1) gap = (gap * 10) / 13;
        swapped = 0;
        for (i = 0; i + gap < n; i++) 
		{
            if (v[i] > v[i+gap]) 
			{
                tmp = v[i]; v[i] = v[i+gap]; v[i+gap] = tmp;
                swapped = 1;
            }
        }
    }
    return EXITO;
}
/**
 * Ordena un vector de floats usando el algoritmo Comb Sort.
 * @param v Vector de floats
 * @param n Tamaño del vector
 * @return EXITO, FALLO o SUPERFALLO
 */
int combSortF(float *v, int n) 
{
    if (!v || n < 1) return FALLO;
    int gap = n, i, swapped = 1;
    float tmp;
    while (gap > 1 || swapped) 
	{
        if (gap > 1) gap = (gap * 10) / 13;
        swapped = 0;
        for (i = 0; i + gap < n; i++) 
		{
            if (v[i] > v[i+gap]) 
			{
                tmp = v[i]; v[i] = v[i+gap]; v[i+gap] = tmp;
                swapped = 1;
            }
        }
    }
    return EXITO;
}

/**
 * Ordena un vector de enteros usando el algoritmo Odd-Even Sort.
 * @param v Vector de enteros
 * @param n Tamaño del vector
 * @return EXITO, FALLO o SUPERFALLO
 */
int oddEvenSortI(int *v, int n) 
{
    if (!v || n < 1) return FALLO;
    int sorted = 0, i, tmp;
    while (!sorted) 
	{
        sorted = 1;
        for (i = 1; i < n-1; i += 2) 
            if (v[i] > v[i+1]) 
                tmp = v[i]; v[i] = v[i+1]; v[i+1] = tmp; sorted = 0;
        for (i = 0; i < n-1; i += 2) 
            if (v[i] > v[i+1]) 
                tmp = v[i]; v[i] = v[i+1]; v[i+1] = tmp; sorted = 0;
    }
    return EXITO;
}
/**
 * Ordena un vector de floats usando el algoritmo Odd-Even Sort.
 * @param v Vector de floats
 * @param n Tamaño del vector
 * @return EXITO, FALLO o SUPERFALLO
 */
int oddEvenSortF(float *v, int n) 
{
    if (!v || n < 1) return FALLO;
    int sorted = 0, i;
    float tmp;
    while (!sorted) 
	{
        sorted = 1;
        for (i = 1; i < n-1; i += 2) 
            if (v[i] > v[i+1]) 
                tmp = v[i]; v[i] = v[i+1]; v[i+1] = tmp; sorted = 0;
        for (i = 0; i < n-1; i += 2) 
            if (v[i] > v[i+1]) 
                tmp = v[i]; v[i] = v[i+1]; v[i+1] = tmp; sorted = 0;
    }
    return EXITO;
}

// --- BITONIC SORT AUXILIARES ---
static void bitonicMergeI(int *v, int low, int cnt, int dir) 
{
    if (cnt > 1) 
	{
        int k = cnt / 2, tmp;
        for (int i = low; i < low + k; i++) 
            if ((dir && v[i] > v[i+k]) || (!dir && v[i] < v[i+k]))
			{
				tmp = v[i]; 
				v[i] = v[i+k]; v[i+k] = tmp;
			}
                
        bitonicMergeI(v, low, k, dir);
        bitonicMergeI(v, low + k, k, dir);
    }
}
static void bitonicSortRecI(int *v, int low, int cnt, int dir) 
{
    if (cnt > 1) 
	{
        int k = cnt / 2;
        bitonicSortRecI(v, low, k, 1);
        bitonicSortRecI(v, low + k, k, 0);
        bitonicMergeI(v, low, cnt, dir);
    }
}
static void bitonicMergeF(float *v, int low, int cnt, int dir) 
{
    if (cnt > 1) 
	{
        int k = cnt / 2;
        float tmp;
        for (int i = low; i < low + k; i++) 
            if ((dir && v[i] > v[i+k]) || (!dir && v[i] < v[i+k])) 
			{
				tmp = v[i]; 
				v[i] = v[i+k]; v[i+k] = tmp;
			}
        bitonicMergeF(v, low, k, dir);
        bitonicMergeF(v, low + k, k, dir);
    }
}
static void bitonicSortRecF(float *v, int low, int cnt, int dir) 
{
    if (cnt > 1) 
	{
        int k = cnt / 2;
        bitonicSortRecF(v, low, k, 1);
        bitonicSortRecF(v, low + k, k, 0);
        bitonicMergeF(v, low, cnt, dir);
    }
}
/**
 * Ordena un vector de enteros usando el algoritmo Bitonic Sort.
 * @param v Vector de enteros
 * @param n Tamaño del vector
 * @return EXITO, FALLO o SUPERFALLO
 */
int bitonicSortI(int *v, int n) 
{
    if (!v || n < 1) return FALLO;
    bitonicSortRecI(v, 0, n, 1);
    return EXITO;
}
/**
 * Ordena un vector de floats usando el algoritmo Bitonic Sort.
 * @param v Vector de floats
 * @param n Tamaño del vector
 * @return EXITO, FALLO o SUPERFALLO
 */
int bitonicSortF(float *v, int n) 
{
    if (!v || n < 1) return FALLO;
    bitonicSortRecF(v, 0, n, 1);
    return EXITO;
}

// --- PANCAKE SORT AUXILIARES ---
static void flipI(int *v, int i) 
{
    int start = 0, tmp;
    while (start < i) 
	{
        tmp = v[start]; v[start] = v[i]; v[i] = tmp;
        start++; i--;
    }
}
static int findMaxI(int *v, int n) 
{
    int mi = 0;
    for (int i = 1; i < n; i++) if (v[i] > v[mi]) mi = i;
    return mi;
}
static void flipF(float *v, int i) 
{
    int start = 0;
    float tmp;
    while (start < i) 
	{
        tmp = v[start]; v[start] = v[i]; v[i] = tmp;
        start++; i--;
    }
}
static int findMaxF(float *v, int n) 
{
    int mi = 0;
    for (int i = 1; i < n; i++) if (v[i] > v[mi]) mi = i;
    return mi;
}
/**
 * Ordena un vector de enteros usando el algoritmo Pancake Sort.
 * @param v Vector de enteros
 * @param n Tamaño del vector
 * @return EXITO, FALLO o SUPERFALLO
 */
int pancakeSortI(int *v, int n) 
{
    if (!v || n < 1) return FALLO;
    for (int curr = n; curr > 1; curr--) 
	{
        int mi = findMaxI(v, curr);
        if (mi != curr-1) 
		{
            flipI(v, mi);
            flipI(v, curr-1);
        }
    }
    return EXITO;
}
/**
 * Ordena un vector de floats usando el algoritmo Pancake Sort.
 * @param v Vector de floats
 * @param n Tamaño del vector
 * @return EXITO, FALLO o SUPERFALLO
 */
int pancakeSortF(float *v, int n) 
{
    if (!v || n < 1) return FALLO;
    for (int curr = n; curr > 1; curr--) 
	{
        int mi = findMaxF(v, curr);
        if (mi != curr-1) 
		{
            flipF(v, mi);
            flipF(v, curr-1);
        }
    }
    return EXITO;
}

// --- STOOGE SORT AUXILIARES ---
static void stoogeSortRecI(int *v, int l, int h) 
{
    if (l >= h) return;
    int tmp;
    if (v[l] > v[h]) { tmp = v[l]; v[l] = v[h]; v[h] = tmp; }
    if (h - l + 1 > 2) 
	{
        int t = (h - l + 1) / 3;
        stoogeSortRecI(v, l, h-t);
        stoogeSortRecI(v, l+t, h);
        stoogeSortRecI(v, l, h-t);
    }
}
static void stoogeSortRecF(float *v, int l, int h) 
{
    if (l >= h) return;
    float tmp;
    if (v[l] > v[h]) { tmp = v[l]; v[l] = v[h]; v[h] = tmp; }
    if (h - l + 1 > 2) 
	{
        int t = (h - l + 1) / 3;
        stoogeSortRecF(v, l, h-t);
        stoogeSortRecF(v, l+t, h);
        stoogeSortRecF(v, l, h-t);
    }
}
/**
 * Ordena un vector de enteros usando el algoritmo Stooge Sort.
 * @param v Vector de enteros
 * @param n Tamaño del vector
 * @return EXITO, FALLO o SUPERFALLO
 */
int stoogeSortI(int *v, int n) 
{
    if (!v || n < 1) return FALLO;
    stoogeSortRecI(v, 0, n-1);
    return EXITO;
}
/**
 * Ordena un vector de floats usando el algoritmo Stooge Sort.
 * @param v Vector de floats
 * @param n Tamaño del vector
 * @return EXITO, FALLO o SUPERFALLO
 */
int stoogeSortF(float *v, int n) 
{
    if (!v || n < 1) return FALLO;
    stoogeSortRecF(v, 0, n-1);
    return EXITO;
}

/**
 * Ordena un vector de enteros usando el algoritmo Bogo Sort.
 */
int bogoSortI(int *v, int n) 
{
    if (!v || n < 1) return FALLO;
    int is_sorted = 0, i, tmp;
    int intentos = 0, max_intentos = 1000000;
    while (!is_sorted && intentos < max_intentos) 
	{
        is_sorted = 1;
        for (i = 1; i < n; i++) if (v[i-1] > v[i]) { is_sorted = 0; break; }
        if (is_sorted) break;
        for (i = 0; i < n; i++) 
		{
            int j = rand() % n;
            tmp = v[i]; v[i] = v[j]; v[j] = tmp;
        }
        intentos++;
    }
    return is_sorted ? EXITO : SUPERFALLO;
}

/**
 * Ordena un vector de floats usando el algoritmo Bogo Sort.
 */
int bogoSortF(float *v, int n) 
{
    if (!v || n < 1) return FALLO;
    int is_sorted = 0, i;
    float tmp;
    int intentos = 0, max_intentos = 1000000;
    while (!is_sorted && intentos < max_intentos) 
	{
        is_sorted = 1;
        for (i = 1; i < n; i++) if (v[i-1] > v[i]) { is_sorted = 0; break; }
        if (is_sorted) break;
        for (i = 0; i < n; i++) 
		{
            int j = rand() % n;
            tmp = v[i]; v[i] = v[j]; v[j] = tmp;
        }
        intentos++;
    }
    return is_sorted ? EXITO : SUPERFALLO;
}

/**
 * Ordena un vector de enteros usando el algoritmo Sleep Sort (simulado, no real).
 */
int sleepSortI(int *v, int n) 
{
    if (!v || n < 1) return FALLO;
    int *out = malloc(n * sizeof(int));
    if (!out) return SUPERFALLO;
    int i, j, min, idx;
    for (i = 0; i < n; i++) out[i] = v[i];
    for (i = 0; i < n; i++) 
	{
        min = 0;
        for (j = 1; j < n-i; j++) if (out[j] < out[min]) min = j;
        v[i] = out[min];
        for (idx = min; idx < n-i-1; idx++) out[idx] = out[idx+1];
    }
    free(out);
    return EXITO;
}

/**
 * Ordena un vector de floats usando el algoritmo Sleep Sort (simulado, no real).
 */
int sleepSortF(float *v, int n) 
{
    if (!v || n < 1) return FALLO;
    float *out = malloc(n * sizeof(float));
    if (!out) return SUPERFALLO;
    int i, j, min, idx;
    for (i = 0; i < n; i++) out[i] = v[i];
    for (i = 0; i < n; i++) 
	{
        min = 0;
        for (j = 1; j < n-i; j++) if (out[j] < out[min]) min = j;
        v[i] = out[min];
        for (idx = min; idx < n-i-1; idx++) out[idx] = out[idx+1];
    }
    free(out);
    return EXITO;
}

/**
 * Ordena un vector de enteros usando el algoritmo Cycle Sort.
 */
int cycleSortI(int *v, int n) 
{
    if (!v || n < 1) return FALLO;
    int writes = 0, i, item, pos, j, tmp;
    for (i = 0; i < n - 1; i++) 
	{
        item = v[i];
        pos = i;
        for (j = i + 1; j < n; j++) if (v[j] < item) pos++;
        if (pos == i) continue;
        while (item == v[pos]) pos++;
        if (pos != i) { tmp = v[pos]; v[pos] = item; item = tmp; writes++; }
        while (pos != i) 
		{
            pos = i;
            for (j = i + 1; j < n; j++) if (v[j] < item) pos++;
            while (item == v[pos]) pos++;
            if (item != v[pos]) { tmp = v[pos]; v[pos] = item; item = tmp; writes++; }
        }
    }
    return EXITO;
}

/**
 * Ordena un vector de floats usando el algoritmo Cycle Sort.
 */
int cycleSortF(float *v, int n) 
{
    if (!v || n < 1) return FALLO;
    int writes = 0, i, pos, j;
    float item, tmp;
    for (i = 0; i < n - 1; i++) 
	{
        item = v[i];
        pos = i;
        for (j = i + 1; j < n; j++) if (v[j] < item) pos++;
        if (pos == i) continue;
        while (item == v[pos]) pos++;
        if (pos != i) { tmp = v[pos]; v[pos] = item; item = tmp; writes++; }
        while (pos != i) 
		{
            pos = i;
            for (j = i + 1; j < n; j++) if (v[j] < item) pos++;
            while (item == v[pos]) pos++;
            if (item != v[pos]) { tmp = v[pos]; v[pos] = item; item = tmp; writes++; }
        }
    }
    return EXITO;
}

/**
 * Ordena un vector de enteros usando el algoritmo Counting Sort.
 */
int countingSort(int *v, int n) 
{
    if (!v || n < 1) return FALLO;
    int i, max = v[0], min = v[0];
    for (i = 1; i < n; i++) 
	{
        if (v[i] > max) max = v[i];
        if (v[i] < min) min = v[i];
    }
    int rango = max - min + 1;
    int *count = malloc(rango * sizeof(int));
    if (!count) return SUPERFALLO;
    for (i = 0; i < rango; i++) count[i] = 0;
    for (i = 0; i < n; i++) count[v[i] - min]++;
    int idx = 0;
    for (i = 0; i < rango; i++) while (count[i]-- > 0) v[idx++] = i + min;
    free(count);
    return EXITO;
}

/**
 * Ordena un vector de enteros usando el algoritmo Radix Sort.
 */
int radixSort(int *v, int n) 
{
    if (!v || n < 1) return FALLO;
    int i, exp, max = v[0];
    for (i = 1; i < n; i++) if (v[i] > max) max = v[i];
    int *output = malloc(n * sizeof(int));
    if (!output) return SUPERFALLO;
    for (exp = 1; max / exp > 0; exp *= 10) 
	{
        int count[10] = {0};
        for (i = 0; i < n; i++) count[(v[i] / exp) % 10]++;
        for (i = 1; i < 10; i++) count[i] += count[i - 1];
        for (i = n - 1; i >= 0; i--) 
		{
            output[count[(v[i] / exp) % 10] - 1] = v[i];
            count[(v[i] / exp) % 10]--;
        }
        for (i = 0; i < n; i++) v[i] = output[i];
    }
    free(output);
    return EXITO;
}

/**
 * Ordena un vector de enteros usando el algoritmo Bucket Sort.
 */
int bucketSort(int *v, int n) 
{
    if (!v || n < 1) return FALLO;
    int i, j, max = v[0], min = v[0];
    for (i = 1; i < n; i++) 
	{
        if (v[i] > max) max = v[i];
        if (v[i] < min) min = v[i];
    }
    int bucketCount = n;
    int bucketRange = (max - min + 1) / bucketCount + 1;
    int **buckets = malloc(bucketCount * sizeof(int*));
    int *bucketSizes = calloc(bucketCount, sizeof(int));
    if (!buckets || !bucketSizes) return SUPERFALLO;
    for (i = 0; i < bucketCount; i++) buckets[i] = malloc(n * sizeof(int));
    for (i = 0; i < n; i++) 
	{
        int idx = (v[i] - min) / bucketRange;
        buckets[idx][bucketSizes[idx]++] = v[i];
    }
    int idx = 0;
    for (i = 0; i < bucketCount; i++) 
	{
        if (bucketSizes[i] > 0) 
		{
            insertionSortI(buckets[i], bucketSizes[i]);
            for (j = 0; j < bucketSizes[i]; j++) v[idx++] = buckets[i][j];
        }
        free(buckets[i]);
    }
    free(buckets);
    free(bucketSizes);
    return EXITO;
}

/**
 * Ordena un vector de enteros usando el algoritmo Pigeonhole Sort.
 */
int pigeonholeSort(int *v, int n) 
{
    if (!v || n < 1) return FALLO;
    int i, min = v[0], max = v[0];
    for (i = 1; i < n; i++) 
	{
        if (v[i] > max) max = v[i];
        if (v[i] < min) min = v[i];
    }
    int size = max - min + 1;
    int *holes = calloc(size, sizeof(int));
    if (!holes) return SUPERFALLO;
    for (i = 0; i < n; i++) holes[v[i] - min]++;
    int idx = 0;
    for (i = 0; i < size; i++) while (holes[i]-- > 0) v[idx++] = i + min;
    free(holes);
    return EXITO;
}

/**
 * @brief Búsqueda lineal en un vector de enteros.
 * @param vector Vector de enteros donde buscar.
 * @param n Número de elementos del vector.
 * @param valorBuscado Valor a buscar.
 * @return Posición del valor encontrado, o -1 si no está o hay error.
 */
int linearSearch(const int *vector, int n, int valorBuscado) 
{
    if (!vector || n <= 0) return -1;
    for (int i = 0; i < n; i++) 
        if (vector[i] == valorBuscado) return i;
    return -1;
}

/**
 * @brief Búsqueda lineal en un vector de floats.
 * @param vector Vector de floats donde buscar.
 * @param n Número de elementos del vector.
 * @param valorBuscado Valor a buscar.
 * @return Posición del valor encontrado, o -1 si no está o hay error.
 */
int linearSearchF(const float *vector, int n, float valorBuscado) 
{
    if (!vector || n <= 0) return -1;
    for (int i = 0; i < n; i++)
        if (vector[i] == valorBuscado) return i;
    return -1;
}

// Función auxiliar para comprobar si un vector de enteros está ordenado ascendentemente
static int estaOrdenadoAscI(const int *vector, int n) 
{
    for (int i = 1; i < n; i++)
        if (vector[i] < vector[i-1]) return 0;
    return 1;
}

// Función auxiliar para comprobar si un vector de floats está ordenado ascendentemente
static int estaOrdenadoAscF(const float *vector, int n) 
{
    for (int i = 1; i < n; i++)
        if (vector[i] < vector[i-1]) return 0;
    return 1;
}

/**
 * @brief Búsqueda binaria en un vector de enteros ordenado ascendentemente.
 * @param vector Vector de enteros ordenado.
 * @param n Número de elementos del vector.
 * @param valorBuscado Valor a buscar.
 * @return Posición del valor encontrado, o -1 si no está o hay error.
 */
int binarySearch(const int *vector, int n, int valorBuscado) 
{
    if (!vector || n <= 0 || !estaOrdenadoAscI(vector, n)) return -1;
    int izq = 0, der = n - 1;
    while (izq <= der) 
	{
        int mid = izq + (der - izq) / 2;
        if (vector[mid] == valorBuscado) return mid;
        if (vector[mid] < valorBuscado) izq = mid + 1;
        else der = mid - 1;
    }
    return -1;
}

/**
 * @brief Búsqueda binaria en un vector de floats ordenado ascendentemente.
 * @param vector Vector de floats ordenado.
 * @param n Número de elementos del vector.
 * @param valorBuscado Valor a buscar.
 * @return Posición del valor encontrado, o -1 si no está o hay error.
 */
int binarySearchF(const float *vector, int n, float valorBuscado) 
{
    if (!vector || n <= 0 || !estaOrdenadoAscF(vector, n)) return -1;
    int izq = 0, der = n - 1;
    while (izq <= der) 
	{
        int mid = izq + (der - izq) / 2;
        if (vector[mid] == valorBuscado) return mid;
        if (vector[mid] < valorBuscado) izq = mid + 1;
        else der = mid - 1;
    }
    return -1;
}

/**
 * @brief Búsqueda ternaria en un vector de enteros ordenado ascendentemente.
 * @param vector Vector de enteros ordenado.
 * @param n Número de elementos del vector.
 * @param valorBuscado Valor a buscar.
 * @return Posición del valor encontrado, o -1 si no está o hay error.
 */
int ternarySearch(const int *vector, int n, int valorBuscado) 
{
    if (!vector || n <= 0 || !estaOrdenadoAscI(vector, n)) return -1;
    int izq = 0, der = n - 1;
    while (izq <= der) 
	{
        int tercio1 = izq + (der - izq) / 3;
        int tercio2 = der - (der - izq) / 3;
        if (vector[tercio1] == valorBuscado) return tercio1;
        if (vector[tercio2] == valorBuscado) return tercio2;
        if (valorBuscado < vector[tercio1]) der = tercio1 - 1;
        else if (valorBuscado > vector[tercio2]) izq = tercio2 + 1;
        else 
		{
            izq = tercio1 + 1;
            der = tercio2 - 1;
        }
    }
    return -1;
}

/**
 * @brief Búsqueda ternaria en un vector de floats ordenado ascendentemente.
 * @param vector Vector de floats ordenado.
 * @param n Número de elementos del vector.
 * @param valorBuscado Valor a buscar.
 * @return Posición del valor encontrado, o -1 si no está o hay error.
 */
int ternarySearchF(const float *vector, int n, float valorBuscado) 
{
    if (!vector || n <= 0 || !estaOrdenadoAscF(vector, n)) return -1;
    int izq = 0, der = n - 1;
    while (izq <= der) 
	{
        int tercio1 = izq + (der - izq) / 3;
        int tercio2 = der - (der - izq) / 3;
        if (vector[tercio1] == valorBuscado) return tercio1;
        if (vector[tercio2] == valorBuscado) return tercio2;
        if (valorBuscado < vector[tercio1]) der = tercio1 - 1;
        else if (valorBuscado > vector[tercio2]) izq = tercio2 + 1;
        else 
		{
            izq = tercio1 + 1;
            der = tercio2 - 1;
        }
    }
    return -1;
}

/**
 * @brief Búsqueda exponencial en un vector de enteros ordenado ascendentemente.
 * @param vector Vector de enteros ordenado.
 * @param n Número de elementos del vector.
 * @param valorBuscado Valor a buscar.
 * @return Posición del valor encontrado, o -1 si no está o hay error.
 */
int exponentialSearch(const int *vector, int n, int valorBuscado) 
{
    if (!vector || n <= 0 || !estaOrdenadoAscI(vector, n)) return -1;
    if (vector[0] == valorBuscado) return 0;
    int i = 1;
    while (i < n && vector[i] <= valorBuscado) i *= 2;
    int izq = i / 2, der = (i < n) ? i : n - 1;
    while (izq <= der) 
	{
        int mid = izq + (der - izq) / 2;
        if (vector[mid] == valorBuscado) return mid;
        if (vector[mid] < valorBuscado) izq = mid + 1;
        else der = mid - 1;
    }
    return -1;
}

/**
 * @brief Búsqueda exponencial en un vector de floats ordenado ascendentemente.
 * @param vector Vector de floats ordenado.
 * @param n Número de elementos del vector.
 * @param valorBuscado Valor a buscar.
 * @return Posición del valor encontrado, o -1 si no está o hay error.
 */
int exponentialSearchF(const float *vector, int n, float valorBuscado) 
{
    if (!vector || n <= 0 || !estaOrdenadoAscF(vector, n)) return -1;
    if (vector[0] == valorBuscado) return 0;
    int i = 1;
    while (i < n && vector[i] <= valorBuscado) i *= 2;
    int izq = i / 2, der = (i < n) ? i : n - 1;
    while (izq <= der) 
	{
        int mid = izq + (der - izq) / 2;
        if (vector[mid] == valorBuscado) return mid;
        if (vector[mid] < valorBuscado) izq = mid + 1;
        else der = mid - 1;
    }
    return -1;
}

/**
 * @brief Búsqueda por saltos (Jump Search) en un vector de enteros ordenado ascendentemente.
 * @param vector Vector de enteros ordenado.
 * @param n Número de elementos del vector.
 * @param valorBuscado Valor a buscar.
 * @return Posición del valor encontrado, o -1 si no está o hay error.
 */
int jumpSearch(const int *vector, int n, int valorBuscado) 
{
    if (!vector || n <= 0 || !estaOrdenadoAscI(vector, n)) return -1;
    int salto = (int)sqrt(n);
    int prev = 0;
    while (prev < n && vector[(salto < n ? salto : n) - 1] < valorBuscado) 
	{
        prev = salto;
        salto += (int)sqrt(n);
        if (prev >= n) return -1;
    }
    for (int i = prev; i < salto && i < n; i++) 
        if (vector[i] == valorBuscado) return i;
    return -1;
}

/**
 * @brief Búsqueda por saltos (Jump Search) en un vector de floats ordenado ascendentemente.
 * @param vector Vector de floats ordenado.
 * @param n Número de elementos del vector.
 * @param valorBuscado Valor a buscar.
 * @return Posición del valor encontrado, o -1 si no está o hay error.
 */
int jumpSearchF(const float *vector, int n, float valorBuscado) 
{
    if (!vector || n <= 0 || !estaOrdenadoAscF(vector, n)) return -1;
    int salto = (int)sqrt(n);
    int prev = 0;
    while (prev < n && vector[(salto < n ? salto : n) - 1] < valorBuscado) 
	{
        prev = salto;
        salto += (int)sqrt(n);
        if (prev >= n) return -1;
    }
    for (int i = prev; i < salto && i < n; i++)
        if (vector[i] == valorBuscado) return i;
    return -1;
}

/**
 * @brief Búsqueda de Fibonacci en un vector de enteros ordenado ascendentemente.
 * @param vector Vector de enteros ordenado.
 * @param n Número de elementos del vector.
 * @param valorBuscado Valor a buscar.
 * @return Posición del valor encontrado, o -1 si no está o hay error.
 */
int fibonacciSearch(const int *vector, int n, int valorBuscado) 
{
    if (!vector || n <= 0 || !estaOrdenadoAscI(vector, n)) return -1;
    int fibMMm2 = 0;
    int fibMMm1 = 1;
    int fibM = fibMMm2 + fibMMm1;
    while (fibM < n) 
	{
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }
    int offset = -1;
    while (fibM > 1) 
	{
        int i = (offset + fibMMm2 < n - 1) ? offset + fibMMm2 : n - 1;
        if (vector[i] < valorBuscado) 
		{
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        } else if (vector[i] > valorBuscado) 
		{
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        } else return i;
    }
    if (fibMMm1 && offset + 1 < n && vector[offset + 1] == valorBuscado) return offset + 1;
    return -1;
}

/**
 * @brief Búsqueda de Fibonacci en un vector de floats ordenado ascendentemente.
 * @param vector Vector de floats ordenado.
 * @param n Número de elementos del vector.
 * @param valorBuscado Valor a buscar.
 * @return Posición del valor encontrado, o -1 si no está o hay error.
 */
int fibonacciSearchF(const float *vector, int n, float valorBuscado) 
{
    if (!vector || n <= 0 || !estaOrdenadoAscF(vector, n)) return -1;
    int fibMMm2 = 0;
    int fibMMm1 = 1;
    int fibM = fibMMm2 + fibMMm1;
    while (fibM < n) 
	{
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }
    int offset = -1;
    while (fibM > 1) 
	{
        int i = (offset + fibMMm2 < n - 1) ? offset + fibMMm2 : n - 1;
        if (vector[i] < valorBuscado) 
		{
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        } else if (vector[i] > valorBuscado) 
		{
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        } else
            return i;
    }
    if (fibMMm1 && offset + 1 < n && vector[offset + 1] == valorBuscado) return offset + 1;
    return -1;
}






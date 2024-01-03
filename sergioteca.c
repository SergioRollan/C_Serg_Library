/*****************************************************************************************************************/
/*****************************************************************************************************************/
/********************************** BIBLIOTECA DE FUNCIONES DE C, CÓDIGO FUENTE **********************************/
/************************************** AUTOR: SERGIO JUAN ROLLÁN MORALEJO ***************************************/
/*****************************************       VERSIÓN NO: 1.0       *******************************************/
/************************************** FECHA DE FINALIZACIÓN: 03-07-2022 ****************************************/
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
	u[j] = '\0';tod
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
	string s=NULL;
	string result=NULL;
	int i=0;
	char c;
	if(cad==NULL || sup>strlen(cad) || inf>sup) return NULL;
	if(NULL==(result=malloc(sizeof(char)*(sup-inf+1)))) return NULL;
	memset(result, '\0', sizeof(result));
	if(inf==sup) return &cad[inf];
	c=siguienteChar(cad);
	while(++i<inf) c=siguienteChar(NULL);
	while(i<=sup)
	{
		c=siguienteChar(NULL);
		meterLetraEnCadena(&result, c);
		i++;
	}
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
	int i=0, j=0;
	char c, cc;
	string sub;
	if(s==NULL || ss==NULL) return FALLO;
	cc=ss[0];
	c=siguienteChar(s);
	while(c!='\0')
	{
		j++;
		if(c==cc)
		{
			sub=substring(s, j-1, j-1+strlen(ss)-1);
			j+=strlen(ss)-1;
			printf("%c, %s\t%s\n", cc, sub, ss);
			if(!strcmp(sub, ss)) i++;
		}
		c=siguienteChar(NULL);
	}
	return i;
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

	if (NULL == (mat = malloc(f * sizeof(vector )))) return NULL;
	for (i = 0; i < f; i++) if (NULL == (mat[i] = malloc(c * sizeof(int)))) return NULL;
    println(s);
	for (i = 0; i < f; i++)
	{
		if (i) printf("Siguiente fila:\n");
		else printf("Primera fila:\n");
		for (j = 0; j < c; j++) mat[i][j] = leer(mat[i][j], "");
	}
	tMat.filas=f;
	tMat.columnas=c;
	tMat.matrix=mat
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

	printf("%s",s);
	for (i = 0; i < f; i++)
	{
		if (i > 0) printf("Siguiente fila:\n");
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
	
	if (NULL == (mat = malloc(f * sizeof(vectorf)))) return NULL;
	for (i = 0; i < f; i++) if (NULL == (mat[i] = malloc(c * sizeof(float)))) return NULL;

	printf("%s",s);
	for (i = 0; i < f; i++)
	{
		if (i > 0) printf("Siguiente fila:\n");
		for (j = 0; j < c; j++) mat[i][j] = leer(mat[i][j], "");
	}
	tMat.filas=f;
	tMat.columnas=c;
	tMat.matrix=mat
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
	tMat.matrix=sumarMatrI(ma,mb,ma.filas,ma.columnas);
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
	tMat.matrix=sumarMatrF(ma,mb,ma.filas,ma.columnas);
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
	tMat.matrix=restarMatrI(ma,mb,ma.filas,ma.columnas);
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
	tMat.matrix=  restarMatrF(ma,mb,ma.filas,ma.columnas);
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
	tipoMatriz tMat;
	if(ma.columnas!=mb.columnas) return ma;
	tMat.filas=ma.filas+mb.filas;
	tMat.columnas=ma.columnas;
	tMat.matrix=concatenarMatricesEnVerticalI(ma.matrix, mb.matrix, ma.filas, mb.filas, mb.columnas);
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
	FILE* f = fopen(nombre, modo);
	if(f==NULL) return NULL;
	if (-1 == flock(fileno(f), LOCK_EX)) return NULL;
	return f;
}

/**
 * Cierra el fichero indicado y libera su bloqueo de manera atómica
 * @param f (FILE ref): puntero al fichero abierto
 * @return void
 * @example FILE *f = abrirFpBloq("fichero.txt", "r"); /-*operaciones*-/; cerrarFpBloq(f);
 */
void cerrarFpBloq(FILE* f)
{
	int fd;
	if (f != NULL)
	{
		fd = fileno(f);
		flock(fd, LOCK_UN);
		close(fd);
	}
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



void iniciaMonticulo(Monticulo *m){m->tam=0;}

int vacioMonticulo(Monticulo m){return m.tam == 0;}

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

void decrementarClave(int pos, tipoClaveMonticulo cantidad, Monticulo *m)
{
	m->elemento[pos].clave = m->elemento[pos].clave - cantidad;

	filtradoAscendente(m,pos);
}

void incrementarClave(int pos, tipoClaveMonticulo cantidad, Monticulo *m)
{
	m->elemento[pos].clave = m->elemento[pos].clave + cantidad;

	filtradoDescendente(m,pos);
}

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

void crearMonticulo(Monticulo *m)
{
	int i,n;
	n = m->tam;

	for(i=n/2; i>=1; i--)
		filtradoDescendente(m,i);
}

void heapsort(Monticulo *m)
{
	tipoElementoMonticulo vector[m->tam];
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
}

//
// Reserva de memoria para un nuevo nodo de árbol binario
//

Arbol creaArbol(tipoInfoArbol info)
{
	tipoNodo * nuevo;
	if ((nuevo =(tipoNodo *)malloc(sizeof(tipoNodo)))==NULL) return NULL;
	nuevo->info=info;
	nuevo->izq=NULL;
	nuevo->der=NULL;
	return nuevo;
}

//
// Recorrido en amplitud o por niveles: necesita una cola de punteros a nodos de árbol binario
//

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

// 
// Recorridos en profundidad "recursivos"
//

void preOrden(Arbol raiz)
{
	if (raiz!=NULL)
	{
		printf("%c ",raiz->info); // visitar nodo raiz - sacar valor
		preOrden(raiz->izq);
		preOrden(raiz->der);
	}
}
void enOrden(Arbol raiz)
{
	if (raiz!=NULL)
	{
		enOrden(raiz->izq);
		printf("%c ",raiz->info);
		enOrden(raiz->der);
	}
}
void postOrden(Arbol raiz)
{
	if (raiz!=NULL)
	{
		postOrden(raiz->izq);
		postOrden(raiz->der);
		printf("%c ",raiz->info);
	}
}

//
// Otras funciones
//

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

int numNodos(Arbol raiz)
{
	int nodos=-1; 

	if(raiz == NULL) return 0;
	
	nodos = numNodos(raiz->izq);
	if(nodos != -1) nodos++;
	nodos = nodos + numNodos(raiz->der);

	return nodos; 
}

int numNodosHoja(Arbol raiz)
{
	int nodosHoja = 0;

	if(raiz == NULL) return 0;

    if(raiz->der == NULL && raiz->izq == NULL) return ++nodosHoja;

	nodosHoja = nodosHoja + numNodosHoja(raiz->der);
	nodosHoja = nodosHoja + numNodosHoja(raiz->izq);

	return nodosHoja;
}

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

int numHijoUnico(Arbol raiz)
{
	int numHijosUnicos = 0;

	if(raiz == NULL) return 0;
    if((raiz->der == NULL && raiz->izq != NULL) || (raiz->der != NULL && raiz->izq == NULL)) return ++numHijosUnicos;

	numHijosUnicos = numHijosUnicos + numHijoUnico(raiz->der);
	numHijosUnicos = numHijosUnicos + numHijoUnico(raiz->izq);

	return numHijosUnicos;
}

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

boolean similares(Arbol r1,Arbol r2)
{
	if(r1 == NULL && r2 == NULL) return TRUE;
	if(r1 != NULL && r2 != NULL) return(similares (r1->izq,r2->izq) && similares (r1->der,r2->der))?TRUE:FALSE;
	return FALSE;
}

boolean equivalentes(Arbol r1,Arbol r2)
{
	if(r1 == NULL && r2 == NULL) return TRUE;
	if ((r1 != NULL && r2 != NULL)) return (r1->info == r2->info && equivalentes (r1->izq,r2->izq) && equivalentes (r1->der,r2->der))?TRUE:FALSE;
	return FALSE;
}

Arbol especular(Arbol raiz)
{
	if(raiz == NULL) return NULL;
	Arbol nuevoNodo = creaArbol(raiz->info);
	nuevoNodo->der = especular(raiz->izq);
	nuevoNodo->izq = especular(raiz->der);
	return nuevoNodo;
}
























palabra encriptar(palabra,codigo){return NULL;} //throw new UnimplementedError();
palabra desencriptar(palabra,codigo){return NULL;} //throw new UnimplementedError();
palabra sindrome(palabra,codigo){return NULL;} //throw new UnimplementedError();
codigo generarG_estandar(int, int){codigo c; return c;} //throw new UnimplementedError();
int peso(palabra){return 1;} //throw new UnimplementedError();
void *normalizarG(codigo*){return NULL;} //throw new UnimplementedError();
int H2G_estandar(codigo*){return 1;} //throw new UnimplementedError();
int G2H_estandar(codigo*){return 1;} //throw new UnimplementedError();
int calcularS(codigo*){return 1;} //throw new UnimplementedError();
int calcularT(codigo*){return 1;} //throw new UnimplementedError();
int calcularNyM(codigo*){return 1;} //throw new UnimplementedError();
int calcularD(codigo*){return 1;} //throw new UnimplementedError();
codigo generarCodigoInicializado(byte_t**){codigo c; return c;} //throw new UnimplementedError();
codigo generarHamming(int){codigo c; return c;} //throw new UnimplementedError();
bit_t sacarBit(short int){return __1;} //throw new UnimplementedError();
boolean bitEsDeInfo(bit_t**,int,int){return FALSE;} //throw new UnimplementedError();



hiperplano leerPlano(dimension){hiperplano h; return h;} //throw new UnimplementedError();
void imprimirPlano(hiperplano){} //throw new UnimplementedError();
hiperplano hijo(hiperplano, int){hiperplano h; return h;} //throw new UnimplementedError();
hiperplano planoOrtogonal(hiperplano, int){hiperplano h; return h;} //throw new UnimplementedError();











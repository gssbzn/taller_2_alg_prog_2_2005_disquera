/*
  Gustavo Bazan
  C.I.:17.777.408
  seccion 22
*/

/* Declaracion de Librerias */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <iostream.h>
#include <fstream.h>

//Constantes
#define LONG 50 
//Punteros
typedef struct nodo_cantante *ptr_nodo_cantante;
typedef struct nodo_cancion *ptr_nodo_cancion;
typedef struct nodo_cd *ptr_nodo_cd;
typedef struct nodo_cantante_cd *ptr_nodo_cantante_cd;
typedef struct nodo_cantante_cancion *ptr_nodo_cantante_cancion;
typedef struct nodo_cancion_cd *ptr_nodo_cancion_cd;

//estructuras
typedef struct info_cantante {
	char nombre[LONG];
	char nacionalidad[LONG];
};

typedef struct info_cd{
	char titulo[LONG];
	char codigo[LONG];
	char disquera[LONG];
	int ano;
};

typedef struct info_cancion{
	char titulo[LONG];
	int duracion;
};

struct nodo_cantante{
	info_cantante info;
	ptr_nodo_cantante prox;
	ptr_nodo_cantante_cd primer_cd;
	ptr_nodo_cantante_cancion primera_cancion;
};

struct nodo_cd{
	info_cd info;
	ptr_nodo_cd prox;
	ptr_nodo_cantante_cd primer_cantante;
	ptr_nodo_cancion_cd primera_cancion;
};

struct nodo_cancion{
	info_cancion info;
	ptr_nodo_cancion prox;
	ptr_nodo_cancion_cd primer_cd;
	ptr_nodo_cantante_cancion primer_cantante;
};

struct nodo_cantante_cd{
	ptr_nodo_cantante_cd sig_fil, sig_col;
	ptr_nodo_cantante cantante;
	ptr_nodo_cd cd;
};


struct nodo_cantante_cancion{
	ptr_nodo_cantante_cancion sig_fil, sig_col;
	ptr_nodo_cantante cantante;
	ptr_nodo_cancion cancion;
};


struct nodo_cancion_cd{
	ptr_nodo_cancion_cd sig_fil, sig_col;
	ptr_nodo_cancion cancion;
	ptr_nodo_cd cd;
};

struct disqueras{
	ptr_nodo_cantante cantantes;
	ptr_nodo_cancion canciones;
	ptr_nodo_cd cds;
};

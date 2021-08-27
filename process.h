#ifndef PROCESS_H_
#define PROCESS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSTRING 200

typedef struct config{
	char *countries_file;
	char *cities_file;
	char mode;
}CONFIG;

typedef struct coordenate{
	int h;
	int m;
	char dir;
}COORDENATE;

typedef struct position{
	COORDENATE lat;
	COORDENATE lon;	
}POSITION;

typedef struct date{
	int y;
	int m;
	int d;
}DATE;

typedef struct data{
	DATE date;
	float temp;
	float error;
	char *country;
	char *city;
	POSITION position;
}DATA;

typedef struct lista_dl{
	DATA data;
	struct lista_dl *next;
	struct lista_dl *prev;
}lista_dl;

typedef struct lista_ct{
	DATA data;
	struct lista_ct *next;
	struct lista_ct *prev;
}lista_ct;

int checkArguments( int _argc, char *_argv[] , CONFIG* _argumentos );
lista_dl* create_node_p(DATA *_data);
lista_ct* create_node_c(DATA *_data);
lista_dl* create_list_p();
lista_ct* create_list_c();
void insert_node_c(lista_ct *_head, DATA *_data);
void print_list_p (lista_dl *_head);
void print_list_c (lista_ct *_head);
lista_dl* readCountriesFile(char *_file, lista_dl *_paises);
lista_ct* readCitiesFile(char *_file, lista_ct *_cidades);
void sortedInsert_p(lista_dl *_head, DATA *_data);
int compare_dates (DATE d1, DATE d2);
void clear_mem(lista_dl **_paises, lista_ct **_cidades);

lista_ct *addFirst(lista_ct *_last, DATA *_data);
lista_ct *addEnd(lista_ct *_last, DATA *_data);
void traverse(lista_ct *_last);

#endif




#ifndef TEXT_H_
#define TEXT_H_

#include <math.h>
#include "process.h"

#define PAGE_ENTRIES 20
#define WORD 50

typedef struct decNum{
	int i;
	int d;
} DEC_NUM;

typedef struct histTemp{
	DEC_NUM t_min;
	DEC_NUM t_max;
	DEC_NUM t_med;
	int t_i;
	int t_f;
} histTemp;

typedef struct tempAno{
	char *q; // mais quentes
	char *f; // mais frios
	char *e; // mais extremos
} tempAno;

typedef struct paisTemp{
	char *p;
	float t;
	float c; // count
	float d; // diferença
} paisTemp;

typedef struct tempMedia{
	float t; // temp
	float s; // soma
	float c; // count
	int y;   // ano
} tempMedia;

int showMenu( lista_dl **_paises, lista_ct **_cidades, char *_countries_file, char *_cities_file );
void showMenuPrincipal();
void showMenuFiltragem();
void showMenuMesesIntervalo();
void showMenuAnoIntervalo();
void showMenuMesInicial();
void showMenuMesFinal();
void showMenuHistTemp();
void showMenuPeriodoTempo();
void showMenuAnoAnalisar();
void showMenuAnaliseTempAno();
void showMenuLerN();
void showMenuLerCidade();
void showMenuLerPais();
histTemp* histTempGlobal( int _n, lista_dl *_paises, int *_c );
void showHistTempData( histTemp *_data, int _n, int _f );
histTemp* histTempPais( int _n, lista_dl *_paises, int *_c, char pais[]);
tempAno* analiseTempAnoPais( int _ano, int _n, lista_dl *_paises);
tempAno* analiseTempAnoCidade( int _ano, int _n, lista_ct *_cidades);
void showTempAnoData( tempAno *dados, int _n );
float* aumTempGlobPlan(lista_dl *_paises, int _m);
float* aumTempGlobPais(lista_dl *_paises, int _m, char *_pais);
float* aumTempGlobCida(lista_ct *_cidades, int _m, char *_cidade);
void showMenuLerM();
float movingAvg(float *_numbers, float *_sum, int _pos, int _len, float _nextNum);
void showTempGlobPlan( float *_dados, int _n );
void remove_mes(int mes_ini, int mes_fim, lista_dl *_paises, lista_ct *_cidades);
void remove_intervalo(int mes, int ano,lista_dl *_paises, lista_ct **_cidades);

#endif





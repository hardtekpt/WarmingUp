#include "text.h"

void showTempGlobPlan( float *_dados, int _n ){
	printf("\x1B[1;1H\x1B[2J");
			
	printf("\n\n\t+----------------------------------------------------+\n"
			"\t+---------------- RESULTADOS OBTIDOS ----------------+\n"
			"\t+----------------------------------------------------+\n");

	for (int i = 0; i < _n; ++i){
		printf("\t|  %-50f|\n", _dados[i]);
	}

	printf(	"\t+----------------------------------------------------+\n"
			"\n\n");

	printf("WarmingUp -> Modo Textual -> Menu Principal -> Análise da Temperatura Global\n\n");	
}

void showTempAnoData( tempAno *dados, int _n ){
	printf("\x1B[1;1H\x1B[2J");
			
	printf("\n\n\t+--------------------------------------------------------------------------------+\n"
			"\t+------------------------------ RESULTADOS OBTIDOS ------------------------------+\n"
			"\t+--------------------------------------------------------------------------------+\n"
			"\t|         QUENTES          |          FRIOS           |         EXTREMOS         |\n"
			"\t+--------------------------------------------------------------------------------+\n");

	for (int i = 0; i < _n; ++i){
		printf("\t| %-25s| %-25s| %-25s|\n", dados[i].q, dados[i].f, dados[i].e);
	}

	printf(	"\t+--------------------------------------------------------------------------------+\n"
			"\n\n");

	printf("WarmingUp -> Modo Textual -> Menu Principal -> Análise da Temperatura Por Ano -> País\n\n");
}

void showHistTempData( histTemp *_data, int _n, int _f ){
	printf("\x1B[1;1H\x1B[2J");
			
	printf("\n\n\t+----------------------------------------------------+\n"
			"\t+---------------- RESULTADOS OBTIDOS ----------------+\n"
			"\t+----------------------------------------------------+\n"
			"\t|   INTERVALO    |    MIN    |    MAX    |   MÉDIA   |\n"
			"\t+----------------------------------------------------+\n");

	for (int i = _n; i < _f; ++i){
		printf("\t|  %d - %d   |  %+03d.%03d  |  %+03d.%03d  |  %+03d.%03d  |\n", _data[i].t_i, _data[i].t_f, _data[i].t_min.i, _data[i].t_min.d, _data[i].t_max.i, _data[i].t_max.d, _data[i].t_med.i, _data[i].t_med.d);
	}

	printf(	"\t+----------------------------------------------------+\n"
			"\n\n");

	printf("WarmingUp -> Modo Textual -> Menu Principal -> Análise da Temperatura Global\n\n");
}

void showMenuLerM(){
	printf("\x1B[1;1H\x1B[2J");
			
	printf("\n\n\t+----------------------------------------------------+\n"
			"\t+---------- ANÁLISE DA TEMPERATURA GLOBAL -----------+\n"
			"\t+----------------------------------------------------+\n"
			"\t|   1 - Insira o valor de M no terminal              |\n"
			"\t|   2 - (Para o cálculo da Moving Average)           |\n"
			"\t+----------------------------------------------------+\n"
			"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

	printf("WarmingUp -> Modo Textual -> Menu Principal -> Análise da Temperatura Global\n\n");
}

void showMenuLerCidade(){
	printf("\x1B[1;1H\x1B[2J");
			
	printf("\n\n\t+----------------------------------------------------+\n"
			"\t+---------- ANÁLISE DA TEMPERATURA GLOBAL -----------+\n"
			"\t+----------------------------------------------------+\n"
			"\t|   1 - Aumento da temperatura global de uma cidade? |\n"
			"\t|   2 - Insira o nome da cidade no terminal          |\n"
			"\t+----------------------------------------------------+\n"
			"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

	printf("WarmingUp -> Modo Textual -> Menu Principal -> Análise da Temperatura Global\n\n");
}

void showMenuLerPais(){
	printf("\x1B[1;1H\x1B[2J");
			
	printf("\n\n\t+----------------------------------------------------+\n"
			"\t+---------- ANÁLISE DA TEMPERATURA GLOBAL -----------+\n"
			"\t+----------------------------------------------------+\n"
			"\t|   1 - Aumento da temperatura global de um país?    |\n"
			"\t|   2 - Insira o nome do país no terminal            |\n"
			"\t+----------------------------------------------------+\n"
			"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

	printf("WarmingUp -> Modo Textual -> Menu Principal -> Análise da Temperatura Global\n\n");
}

void showMenuLerN(){
	printf("\x1B[1;1H\x1B[2J");
			
	printf("\n\n\t+----------------------------------------------------+\n"
			"\t+---------- ANÁLISE DA TEMPERATURA POR ANO ----------+\n"
			"\t+----------------------------------------------------+\n"
			"\t|   1 - Quer ver dados de quantos países/cidades?    |\n"
			"\t|   2 - Insira um número de 1 a 20 no terminal       |\n"
			"\t+----------------------------------------------------+\n"
			"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

	printf("WarmingUp -> Modo Textual -> Menu Principal -> Análise da Temperatura por Ano\n\n");
}

void showMenuAnaliseTempAno(){
	printf("\x1B[1;1H\x1B[2J");
			
	printf("\n\n\t+----------------------------------------------------+\n"
			"\t+---------- ANÁLISE DA TEMPERATURA POR ANO ----------+\n"
			"\t+----------------------------------------------------+\n"
			"\t|   1 - Análise por País                             |\n"
			"\t|   2 - Análise por Cidade                           |\n"
			"\t|   3 - Voltar                                       |\n"
			"\t+----------------------------------------------------+\n"
			"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

	printf("WarmingUp -> Modo Textual -> Menu Principal -> Análise da Temperatura por Ano\n\n");
}

void showMenuAnoAnalisar(){
	printf("\x1B[1;1H\x1B[2J");
			
	printf("\n\n\t+----------------------------------------------------+\n"
			"\t+---------- ANÁLISE DA TEMPERATURA POR ANO ----------+\n"
			"\t+----------------------------------------------------+\n"
			"\t|   1 - Insira o ano que pretende analisar           |\n"
			"\t|   2 - no terminal                                  |\n"
			"\t+----------------------------------------------------+\n"
			"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

	printf("WarmingUp -> Modo Textual -> Menu Principal -> Análise da Temperatura por Ano\n\n");
}

void showMenuHistTemp(){
	printf("\x1B[1;1H\x1B[2J");
			
	printf("\n\n\t+----------------------------------------------------+\n"
			"\t+------------ HISTÓRICO DE TEMPERATURAS -------------+\n"
			"\t+----------------------------------------------------+\n"
			"\t|   1 - Global: aplica-se a todos os países          |\n"
			"\t|   2 - Por país: aplica-se a um único país          |\n"
			"\t|   3 - Por cidade: aplica-se a uma única cidade     |\n"
			"\t|   4 - Voltar                                       |\n"
			"\t+----------------------------------------------------+\n"
			"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

	printf("WarmingUp -> Modo Textual -> Menu Principal -> Histórico de Temperaturas\n\n");
}

void showMenuPeriodoTempo(){
	printf("\x1B[1;1H\x1B[2J");
			
	printf("\n\n\t+----------------------------------------------------+\n"
			"\t+------------ HISTÓRICO DE TEMPERATURAS -------------+\n"
			"\t+----------------------------------------------------+\n"
			"\t|   1 - Insira o período de tempo (em anos)          |\n"
			"\t|   2 - no terminal                                  |\n"
			"\t+----------------------------------------------------+\n"
			"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

	printf("WarmingUp -> Modo Textual -> Menu Principal -> Histórico de Temperaturas\n\n");
}

void showMenuMesInicial(){
	printf("\x1B[1;1H\x1B[2J");
			
	printf("\n\n\t+----------------------------------------------------+\n"
			"\t+-------------------- ESCOLHE MÊS -------------------+\n"
			"\t+----------------------------------------------------+\n"
			"\t|   Escolha o mês inicial                            |\n"
			"\t+----------------------------------------------------+\n"
			"\t|   1 - Janeiro                                      |\n"
			"\t|   2 - Fevereiro                                    |\n"
			"\t|   3 - Março                                        |\n"
			"\t|   4 - Abril                                        |\n"
			"\t|   5 - Maio                                         |\n"
			"\t|   6 - Junho                                        |\n"
			"\t|   7 - Julho                                        |\n"
			"\t|   8 - Agosto                                       |\n"
			"\t|   9 - Setembro                                     |\n"
			"\t|  10 - Outubro                                      |\n"
			"\t|  11 - Novembro                                     |\n"
			"\t|  12 - Dezembro                                     |\n"
			"\t+----------------------------------------------------+\n"
			"\n\n\n\n\n\n\n\n");

	printf("WarmingUp -> Modo Textual -> Menu Principal -> Filtragem de dados -> Escolhe mês para análise\n\n");
}

void showMenuMesFinal(){
	printf("\x1B[1;1H\x1B[2J");
			
	printf("\n\n\t+----------------------------------------------------+\n"
			"\t+------------------- ESCOLHE MÊS --------------------+\n"
			"\t+----------------------------------------------------+\n"
			"\t|   Escolha o mês final                              |\n"
			"\t+----------------------------------------------------+\n"
			"\t|   1 - Janeiro                                      |\n"
			"\t|   2 - Fevereiro                                    |\n"
			"\t|   3 - Março                                        |\n"
			"\t|   4 - Abril                                        |\n"
			"\t|   5 - Maio                                         |\n"
			"\t|   6 - Junho                                        |\n"
			"\t|   7 - Julho                                        |\n"
			"\t|   8 - Agosto                                       |\n"
			"\t|   9 - Setembro                                     |\n"
			"\t|  10 - Outubro                                      |\n"
			"\t|  11 - Novembro                                     |\n"
			"\t|  12 - Dezembro                                     |\n"
			"\t+----------------------------------------------------+\n"
			"\n\n\n\n\n\n\n\n");

	printf("WarmingUp -> Modo Textual -> Menu Principal -> Filtragem de dados -> Escolhe mês para análise\n\n");
}

void showMenuAnoIntervalo(){
	printf("\x1B[1;1H\x1B[2J");
			
	printf("\n\n\t+----------------------------------------------------+\n"
			"\t+------------------ ESCOLHE ANO ---------------------+\n"
			"\t+----------------------------------------------------+\n"
			"\t|   1 - Insira o ano no terminal                     |\n"
			"\t+----------------------------------------------------+\n"
			"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

	printf("WarmingUp -> Modo Textual -> Menu Principal -> Filtragem de dados -> Escolhe intervalo para análise\n\n");
}

void showMenuMesesIntervalo(){
	printf("\x1B[1;1H\x1B[2J");
			
	printf("\n\n\t+----------------------------------------------------+\n"
			"\t+------------------- ESCOLHE MÊS --------------------+\n"
			"\t+----------------------------------------------------+\n"
			"\t|   1 - Janeiro                                      |\n"
			"\t|   2 - Fevereiro                                    |\n"
			"\t|   3 - Março                                        |\n"
			"\t|   4 - Abril                                        |\n"
			"\t|   5 - Maio                                         |\n"
			"\t|   6 - Junho                                        |\n"
			"\t|   7 - Julho                                        |\n"
			"\t|   8 - Agosto                                       |\n"
			"\t|   9 - Setembro                                     |\n"
			"\t|  10 - Outubro                                      |\n"
			"\t|  11 - Novembro                                     |\n"
			"\t|  12 - Dezembro                                     |\n"
			"\t+----------------------------------------------------+\n"
			"\n\n\n\n\n\n\n\n\n\n");

	printf("WarmingUp -> Modo Textual -> Menu Principal -> Filtragem de dados -> Escolhe intervalo para análise\n\n");
}

void showMenuFiltragem(){
	printf("\x1B[1;1H\x1B[2J");
			
	printf("\n\n\t+----------------------------------------------------+\n"
			"\t+--------------- FILTRAGEM DE DADOS -----------------+\n"
			"\t+----------------------------------------------------+\n"
			"\t|   1 - Limpa critérios                              |\n"
			"\t|   2 - Escolhe intervalo para análise               |\n"
			"\t|   3 - Escolhe mês para análise                     |\n"
			"\t|   4 - Voltar                                       |\n"
			"\t+----------------------------------------------------+\n"
			"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

	printf("WarmingUp -> Modo Textual -> Menu Principal -> Filtragem de dados\n\n");
}

void showMenuPrincipal(){
	printf("\x1B[1;1H\x1B[2J");
			
	printf("\n\n\t+----------------------------------------------------+\n"
			"\t+----------------- MENU PRINCIPAL -------------------+\n"
			"\t+----------------------------------------------------+\n"
			"\t|   1 - Filtragem de dados                           |\n"
			"\t|   2 - Histórico de temperaturas                    |\n"
			"\t|   3 - Análise da temperatura por ano               |\n"
			"\t|   4 - Análise da temperatura global                |\n"
			"\t|   5 - Sair                                         |\n"
			"\t+----------------------------------------------------+\n"
			"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

	printf("WarmingUp -> Modo Textual -> Menu Principal\n\n");
}


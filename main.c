/*
	Francisco Velez 90077
	Tiago Santos    90099

	25-05-18
*/

#include "process.h"
#include "graphic.h"
#include "text.h"

int main(int argc, char *argv[]){

	// ----INIT----
	CONFIG argumentos;

	// Verificar os argumentos
	if(checkArguments( argc, argv , &argumentos) == -1) return EXIT_FAILURE;
	// Leitura do ficheiro das cidades
	lista_ct *cidades = NULL;
	cidades = readCitiesFile(argumentos.cities_file, cidades);
	// Leitura do ficheiro dos países
	lista_dl *paises = create_list_p();
	if ((paises = readCountriesFile(argumentos.countries_file, paises)) == NULL) return EXIT_FAILURE;
	

	//print_list_c(cidades);
	//print_list(paises);
	//traverse(cidades);

	switch(argumentos.mode){
		case 't':
			if(showMenu( &paises, &cidades, argumentos.countries_file, argumentos.cities_file ) == -1){
				printf("\x1B[1;1H\x1B[2J");
				break;
			}

		case 'g':
		break;
	}

	clear_mem(&paises, &cidades);

	return EXIT_SUCCESS;
}


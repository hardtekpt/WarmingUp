#include "process.h"

// Verificar o numero de argumentos 
int checkArguments( int _argc, char *_argv[] , CONFIG* _argumentos ){
	int a=0, b=0, c=0;

	if(_argc != 6){
		if(_argc < 6)
			printf("Faltam argumentos!!\n");
		else
			printf("Existem argumentos a mais!!\n");
		return -1;
	}

	for(int i=1; i<_argc; i++){

		if(strcmp("-f1", _argv[i])==0){    
			b=1;   
			_argumentos->countries_file = _argv[i+1];
		}else if(strcmp("-f2", _argv[i])==0){
			c=1;
			_argumentos->cities_file = _argv[i+1];
		}else if(strcmp("-g", _argv[i])==0){
			a=1;
			_argumentos->mode = *(_argv[i]+1);
		}else if(strcmp("-t", _argv[i])==0){
			a=1;
			_argumentos->mode = *(_argv[i]+1);
		}
	}

	if(a==0 || b==0 || c==0){
		printf("insira todos os parametros corretamente!!\n");
		return -1;
	}
	return 0;
}

// Leitura do ficheiro dos paises
lista_dl* readCountriesFile(char *_file, lista_dl *_paises){
	
	FILE *file;
	file = fopen(_file, "r");
	if(file == NULL){
		printf("Erro ao abrir o ficheiro %s\n", _file);
		return NULL;
	}

	char *linha = NULL;
	linha = (char *)malloc(MAXSTRING * sizeof(char));
	DATA aux; // estrutura para guardar a informação da linha atual temporariamente

	(&aux)->country = (char *)malloc(MAXSTRING * sizeof(char));
	//long int n=0;

	while(fgets(linha, MAXSTRING, file)!=NULL){
        linha[strlen(linha)] = '\0';
        if (sscanf(linha, "%d-%d-%d,%f,%f,%[^\n]", &aux.date.y, &aux.date.m, &aux.date.d, &aux.temp, &aux.error, aux.country) == 6){
        	// Inserir os dados na lista
        	sortedInsert_p(_paises, &aux);
        	//insert_node(_paises, &aux);
        	//n++;
        	//printf("\x1B[1;1H\x1B[2J");
        	//printf("%ld\n", n);
        }
    }
    free(linha);
    fclose(file);
    return _paises;
}

// Leitura do ficheiro das cidades
lista_ct* readCitiesFile(char *_file, lista_ct *_cidades){
	
	FILE *file;
	file = fopen(_file, "r");
	if(file == NULL){
		printf("Erro ao abrir o ficheiro %s\n", _file);
		return NULL;
	}

	char *linha = NULL;
	linha = (char *)malloc(MAXSTRING * sizeof(char));
	DATA aux; // estrutura para guardar a informação da linha atual temporariamente

	(&aux)->country = (char *)malloc(MAXSTRING * sizeof(char));
	(&aux)->city = (char *)malloc(MAXSTRING * sizeof(char));

	while(fgets(linha, MAXSTRING, file)!=NULL){
        linha[strlen(linha)] = '\0';
        if (sscanf(linha, "%d-%d-%d,%f,%f,%[^,],%[^,],%d.%d%c,%d.%d%c", &aux.date.y, 
        																&aux.date.m, 
        																&aux.date.d, 
        																&aux.temp, 
        																&aux.error, 
        																aux.city, 
        																aux.country,
        																&aux.position.lat.h, 
        																&aux.position.lat.m, 
        																&aux.position.lat.dir,
        																&aux.position.lon.h,
        																&aux.position.lon.m,
        																&aux.position.lon.dir) == 13){
        	// Inserir os dados na lista
        	//insert_node_c(_cidades, &aux);
        	_cidades = addEnd(_cidades, &aux);
        }
        

    }
    free(linha);
    fclose(file);
    return _cidades;
}


int compare_dates (DATE d1, DATE d2){
    if (d1.y < d2.y)
       return -1;

    else if (d1.y > d2.y)
       return 1;

    if (d1.y == d2.y)
    {
         if (d1.m<d2.m)
              return -1;
         else if (d1.m>d2.m)
              return 1;
         else if (d1.d<d2.d)
              return -1;
         else if(d1.d>d2.d)
              return 1;
         else
              return 0;
    }
    return 2;
    // -1.  d1 e mais cedo que d2
    // 1.   d1 e mais tarde que d2
    // 0.   d1 igual a d2
    // 2.   erro!!!
}


// -------------------> Funções para o funcionamento da lista duplamente ligada para o ficheiro dos paises


// Allocar memória para um novo nó
lista_dl* create_node_p(DATA *_data){
	lista_dl* new_node = NULL;
	new_node = (lista_dl *) malloc(sizeof(lista_dl));
	if(new_node == NULL){
		printf("MEMORY ALLOCATION ERROR\n");
		exit(EXIT_FAILURE);
	}

	new_node->data.country = (char *) malloc((strlen(_data->country)+1)*sizeof(char));
	if(new_node->data.country == NULL){
		printf("MEMORY ALLOCATION ERROR\n");
		exit(EXIT_FAILURE);	
	}

	strcpy(new_node->data.country, _data->country);
	new_node->data.date.y = _data->date.y;
	new_node->data.date.m = _data->date.m;
	new_node->data.date.d = _data->date.d;
	new_node->data.temp = _data->temp;
	new_node->data.error = _data->error;

	new_node->next = NULL;
	new_node->prev = NULL;
	return new_node;
}

lista_dl* create_list_p(){
	DATA empty;
	empty.date.y = 0;
	empty.country = "";
	empty.city = NULL;
	return create_node_p(&empty);
}

void sortedInsert_p(lista_dl *_head, DATA *_data){

	lista_dl *new_node = create_node_p(_data);
    lista_dl *current = NULL;

    if (_head->next == NULL || compare_dates(_head->next->data.date, new_node->data.date) >= 1)
    {
        new_node->next = _head->next;
        _head->next = new_node;
        new_node->prev = _head;
        if(new_node->next != NULL)
        	new_node->next->prev = new_node;
    }
    else
    {
        current = _head->next;
        while (current->next!=NULL && compare_dates(current->next->data.date, new_node->data.date) == -1)
        {
            current = current->next;
        }
        new_node->next = current->next;
        new_node->prev = current;
        current->next = new_node;
        if(new_node->next != NULL)
			new_node->next->prev = new_node;
    }
}

void print_list_p (lista_dl *_head){
	lista_dl *aux = _head->next;
	while( aux != NULL ){
		printf("%d:%d:%d\ttemp: %f  \terror: %f \tpais: %s\n",aux->data.date.y,aux->data.date.m,aux->data.date.d,aux->data.temp,aux->data.error,aux->data.country);
		aux = aux->next;
	}
}

lista_ct *addFirst(lista_ct *_last, DATA *_data){
	lista_ct *new_node = NULL;
	if(_last != NULL)
		return _last;

	new_node = (lista_ct*)malloc(sizeof(lista_ct));
	if( new_node == NULL ){
		printf("MEMORY ALLOCATION ERROR!!\n");
		exit(EXIT_FAILURE);
	}

	new_node->data.country = (char *) malloc((strlen(_data->country)+1)*sizeof(char));
	if(new_node->data.country == NULL){
		printf("MEMORY ALLOCATION ERROR\n");
		exit(EXIT_FAILURE);	
	}

	new_node->data.city = (char *) malloc((strlen(_data->city)+1)*sizeof(char));
	if(new_node->data.city == NULL){
		printf("MEMORY ALLOCATION ERROR\n");
		exit(EXIT_FAILURE);	
	}

	strcpy(new_node->data.country, _data->country);
	strcpy(new_node->data.city, _data->city);
	new_node->data.date.y = _data->date.y;
	new_node->data.date.m = _data->date.m;
	new_node->data.date.d = _data->date.d;
	new_node->data.temp = _data->temp;
	new_node->data.error = _data->error;
	new_node->data.position.lat.h = _data->position.lat.h;
	new_node->data.position.lat.m = _data->position.lat.m;
	new_node->data.position.lat.dir = _data->position.lat.dir;
	new_node->data.position.lon.h = _data->position.lon.h;
	new_node->data.position.lon.m = _data->position.lon.m;
	new_node->data.position.lon.dir = _data->position.lon.dir;

	new_node->next = new_node;
	new_node->prev = new_node;
	return new_node;
}

lista_ct *addEnd(lista_ct *_last, DATA *_data){
	lista_ct *new_node = NULL;
	if(_last == NULL){
		return addFirst(_last, _data);
	}
	new_node = (lista_ct*)malloc(sizeof(lista_ct));
	if( new_node == NULL ){
		printf("MEMORY ALLOCATION ERROR!!\n");
		exit(EXIT_FAILURE);
	}
	new_node->data.country = (char *) malloc((strlen(_data->country)+1)*sizeof(char));
	if(new_node->data.country == NULL){
		printf("MEMORY ALLOCATION ERROR\n");
		exit(EXIT_FAILURE);	
	}

	new_node->data.city = (char *) malloc((strlen(_data->city)+1)*sizeof(char));
	if(new_node->data.city == NULL){
		printf("MEMORY ALLOCATION ERROR\n");
		exit(EXIT_FAILURE);	
	}

	strcpy(new_node->data.country, _data->country);
	strcpy(new_node->data.city, _data->city);
	new_node->data.date.y = _data->date.y;
	new_node->data.date.m = _data->date.m;
	new_node->data.date.d = _data->date.d;
	new_node->data.temp = _data->temp;
	new_node->data.error = _data->error;
	new_node->data.position.lat.h = _data->position.lat.h;
	new_node->data.position.lat.m = _data->position.lat.m;
	new_node->data.position.lat.dir = _data->position.lat.dir;
	new_node->data.position.lon.h = _data->position.lon.h;
	new_node->data.position.lon.m = _data->position.lon.m;
	new_node->data.position.lon.dir = _data->position.lon.dir;

	new_node->next = _last->next;
	new_node->prev = _last;
	_last->next = new_node;
	_last->next->prev = new_node;

	return new_node;
}

void traverse(lista_ct *_last){
	printf("ok\n");
	lista_ct *aux = NULL;

	if(_last == NULL){
		printf("list is empty!!\n");
		return;
	}
	aux = _last->next;

	do{
		printf("%d:%d:%d\ttemp: %f  \terror: %f \tpais: %s  \tcidade: %s  \tlat: %d.%d%c  \tlon %d.%d%c\n",aux->data.date.y,aux->data.date.m,aux->data.date.d,aux->data.temp,aux->data.error,aux->data.country, aux->data.city, aux->data.position.lat.h, aux->data.position.lat.m, aux->data.position.lat.dir, aux->data.position.lon.h, aux->data.position.lon.m, aux->data.position.lon.dir);
		aux = aux->next;
	}while(aux != _last->next);
}

// Funções para a lista das cidades
lista_ct* create_node_c(DATA *_data){
	lista_ct* new_node = NULL;
	new_node = (lista_ct *) malloc(sizeof(lista_ct));
	if(new_node == NULL){
		printf("MEMORY ALLOCATION ERROR\n");
		exit(EXIT_FAILURE);
	}

	new_node->data.country = (char *) malloc((strlen(_data->country)+1)*sizeof(char));
	if(new_node->data.country == NULL){
		printf("MEMORY ALLOCATION ERROR\n");
		exit(EXIT_FAILURE);	
	}

	new_node->data.city = (char *) malloc((strlen(_data->city)+1)*sizeof(char));
	if(new_node->data.city == NULL){
		printf("MEMORY ALLOCATION ERROR\n");
		exit(EXIT_FAILURE);	
	}

	strcpy(new_node->data.country, _data->country);
	strcpy(new_node->data.city, _data->city);
	new_node->data.date.y = _data->date.y;
	new_node->data.date.m = _data->date.m;
	new_node->data.date.d = _data->date.d;
	new_node->data.temp = _data->temp;
	new_node->data.error = _data->error;
	new_node->data.position.lat.h = _data->position.lat.h;
	new_node->data.position.lat.m = _data->position.lat.m;
	new_node->data.position.lat.dir = _data->position.lat.dir;
	new_node->data.position.lon.h = _data->position.lon.h;
	new_node->data.position.lon.m = _data->position.lon.m;
	new_node->data.position.lon.dir = _data->position.lon.dir;

	new_node->next = NULL;
	new_node->prev = NULL;
	return new_node;
}

lista_ct* create_list_c(){
	DATA empty;
	empty.date.y = 0;
	empty.country = "";
	empty.city = "";
	return create_node_c(&empty);
}

void insert_node_c(lista_ct *_head, DATA *_data){
	lista_ct *new_node = create_node_c(_data);
	// inserir na lista sempre apos o dummy node
	new_node->prev = _head;
	new_node->next = _head->next;
	_head->next = new_node;
	if(new_node->next != NULL)
		new_node->next->prev = new_node;
}

void print_list_c (lista_ct *_head){
	lista_ct *aux = _head->next;
	while( aux != NULL ){
		printf("%d:%d:%d\ttemp: %f  \terror: %f \tpais: %s  \tcidade: %s  \tlat: %d.%d%c  \tlon %d.%d%c\n",aux->data.date.y,aux->data.date.m,aux->data.date.d,aux->data.temp,aux->data.error,aux->data.country, aux->data.city, aux->data.position.lat.h, aux->data.position.lat.m, aux->data.position.lat.dir, aux->data.position.lon.h, aux->data.position.lon.m, aux->data.position.lon.dir);
		aux = aux->next;
	}
}

void clear_mem(lista_dl **_paises, lista_ct **_cidades)
{
    lista_dl *aux = (*_paises)->next, *tmp = NULL;
    while (aux != NULL){
        tmp = aux->next;
        free(aux->data.country);
        free(aux);
        aux = tmp;
    }
    (*_paises) = NULL;

    lista_ct *aux2 = NULL;

	do{
		aux2 = (*_cidades)->next;
		(*_cidades)->next = (*_cidades)->next->next;
		free(aux2->data.country);
        free(aux2->data.city);
		free(aux2);
	}while((*_cidades)->next != (*_cidades));
	free((*_cidades)->data.country);
    free((*_cidades)->data.city);
	free(*_cidades);
	
	(*_cidades) = NULL;
}










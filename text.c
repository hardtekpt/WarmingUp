#include "text.h"


int showMenu( lista_dl **_paises, lista_ct **_cidades, char *_countries_file, char *_cities_file ){
	int smp=0;  // switch menu principal
	int sfd=0;  // switch filtragem dados
	int sht=0;  // switch historico de temperaturas
	int sata=0; // switch analise temp por ano

	int mes, ano;

	while (smp == 0){
		while(smp != 1 && smp != 2 && smp != 3 && smp != 4 && smp != 5){
			showMenuPrincipal();
			while (scanf("%d",&smp) != 1) {
		        scanf("%*s"); 
		        smp = 0;
		        break;
		    }
		}
		while (smp == 1){
			while(sfd != 1 && sfd != 2 && sfd != 3 && sfd != 4){
				showMenuFiltragem();
				while (scanf("%d",&sfd) != 1) {
			        scanf("%*s"); 
			        sfd = 0;
			        break;
			    }
			}
			while (sfd == 1){
                clear_mem(_paises, _cidades);
                
                *_cidades = readCitiesFile(_cities_file, *_cidades);
                *_paises = create_list_p();
                readCountriesFile(_countries_file, *_paises);
                
				sfd = 0;
				smp = 0;
				break;
			}
			while (sfd == 2){
				showMenuMesesIntervalo();
				scanf("%d", &mes);
				showMenuAnoIntervalo();
				scanf("%d", &ano);
				remove_intervalo(mes, ano, *_paises, &(*_cidades)->next);
				sfd = 0;
				break;
			}
			while (sfd == 3){
                int mes_ini = 0, mes_fim = 0;
				showMenuMesInicial();
				scanf("%d", &mes_ini);
				showMenuMesFinal();
				scanf("%d", &mes_fim);
				remove_mes(mes_ini, mes_fim, *_paises, *_cidades);
				sfd = 0;
				break;
			}
			while (sfd == 4){
				// Voltar
				sfd = 0;
				smp = 0;
				break;
			}
		}
		while (smp == 2){
			showMenuPeriodoTempo();
			while (scanf("%d",&ano) != 1) {
				showMenuPeriodoTempo();
		        scanf("%*s"); 
		    }
			while(sht != 1 && sht != 2 && sht != 3 && sht != 4){
				showMenuHistTemp();
				while (scanf("%d",&sht) != 1) {
			        scanf("%*s"); 
			        sht = 0;
			        break;
			    }
			}
			while (sht == 1){
				// Calcular dados
				int n=0, f=0, aux=PAGE_ENTRIES;
				char nav = 'o';

				histTemp *dados = histTempGlobal(ano, *_paises, &f);
				// Mostrar dados
				while( nav != 'q' ){
					if( f <= 20 ){
						aux = f;
						showHistTempData(dados, 0, f);
					}else{
						if(aux > f){
							aux = f;

						}
						showHistTempData(dados, n, aux);
					}
					while (scanf("%c", &nav) != 1){
						scanf("%*s");
					}
					if( nav == 'a' ){
						if( aux < f)
							n = n + PAGE_ENTRIES; 
						aux = aux + PAGE_ENTRIES;	
					}
				}
				sht = 0;
				smp = 0;
				break;
			}
			while (sht == 2){
				char pais[100];
				int n=0, f=0, aux=PAGE_ENTRIES;
				char nav = 'o';
				getchar();
				showMenuLerPais();
			    fgets(pais, 100, stdin);
			    while(strlen(pais) == 1){
			    	showMenuLerPais();
			        fgets(pais, 100, stdin);
			    }
			    size_t ln = strlen(pais)-1;
			    if (pais[ln] == '\n')
			        pais[ln] = '\0';

				histTemp *dados = histTempPais(ano, *_paises, &f, pais);

				// Mostrar dados
				while( nav != 'q' ){
					if( f <= 20 ){
						aux = f;
						showHistTempData(dados, 0, f);
					}else{
						if(aux > f){
							aux = f;

						}
						showHistTempData(dados, n, aux);
					}
					while (scanf("%c", &nav) != 1){
						scanf("%*s");
					}
					if( nav == 'a' ){
						if( aux < f)
							n = n + PAGE_ENTRIES; 
						aux = aux + PAGE_ENTRIES;	
					}
				}
				sht = 0;
				smp = 0;
				break;
			}
			while (sht == 3){

				sht = 0;
				smp = 0;
				break;
			}
			while (sht == 4){
				// Voltar
				sht = 0;
				smp = 0;
				break;
			}
		}
		while (smp == 3){
			int n=0;
			showMenuAnoAnalisar();
			scanf("%d", &ano);
			showMenuLerN();
			scanf("%d", &n);
			while(sata != 1 && sata != 2 && sata != 3){
				showMenuAnaliseTempAno();
				while (scanf("%d",&sata) != 1) {
			        scanf("%*s"); 
			        sata = 0;
			        break;
			    }
			}
			while (sata == 1){
				tempAno *dados = analiseTempAnoPais( ano, n, *_paises);
				char nav = '\0';

				// Mostrar dados
				while( nav != 'q' ){
					//mostrar
					showTempAnoData( dados, n );

					while (scanf("%c", &nav) != 1){
						scanf("%*s");
					}
				}

				sata = 0;
				smp = 0;
				break;
			}
			while (sata == 2){
				tempAno *dados = analiseTempAnoCidade( ano, n, *_cidades);
				char nav = '\0';

				// Mostrar dados
				while( nav != 'q' ){
					//mostrar
					showTempAnoData( dados, n );

					while (scanf("%c", &nav) != 1){
						scanf("%*s");
					}
				}

				sata = 0;
				smp = 0;
				break;
			}
			while (sata == 3){
				// Voltar
				sata = 0;
				smp = 0;
				break;
			}
		}
		while (smp == 4){
			// mostrar temp media global
			int m=0;
			char nav = '\0', pais[WORD], cidade[WORD];
			showMenuLerM();
			scanf("%d", &m);
			float *dados = aumTempGlobPlan(*_paises, m);
			// Mostrar dados
			while( nav != 'a' ){
				//mostrar
				showTempGlobPlan(dados, 5);
				while (scanf("%c", &nav) != 1){
					scanf("%*s");
				}
			}
			nav = '\0';
			showMenuLerPais();
			fgets(pais, WORD, stdin);
		    while(strlen(pais) == 1){
		    	showMenuLerPais();
		        fgets(pais, 100, stdin);
		    }
		    size_t ln = strlen(pais)-1;
		    if (pais[ln] == '\n')
		        pais[ln] = '\0';
			// mostrar temp media pais
			float *dadosPais = aumTempGlobPais(*_paises, m, pais);
			// Mostrar dados
			while( nav != 'a' ){
				//mostrar
				showTempGlobPlan(dadosPais, 5);
				while (scanf("%c", &nav) != 1){
					scanf("%*s");
				}
			}
			nav = '\0';
			showMenuLerCidade();
			fgets(cidade, WORD, stdin);
		    while(strlen(cidade) == 1){
		    	showMenuLerCidade();
		        fgets(cidade, 100, stdin);
		    }
		    ln = strlen(cidade)-1;
		    if (cidade[ln] == '\n')
		        cidade[ln] = '\0';
			// mostrar temp media pais
			float *dadosCidade = aumTempGlobCida(*_cidades, m, cidade);
			// Mostrar dados
			while( nav != 'a' ){
				//mostrar
				showTempGlobPlan(dadosCidade, 5);
				while (scanf("%c", &nav) != 1){
					scanf("%*s");
				}
			}
			smp = 0;
		}
		while (smp == 5){
			return -1;
		}
	}
	return 0;
}

histTemp* histTempGlobal( int _n, lista_dl *_paises, int *_c ){
	histTemp *dados = NULL;
	lista_dl *aux = _paises->next;

	int count=0; 
	float som=0;

	int limit = _paises->next->data.date.y + _n;
	aux = _paises->next;	

	float a=0,c=0;
	int b=0,d=0;

	while( aux != NULL ){
		if(*_c==0){
			dados = (histTemp *)malloc(sizeof(histTemp));
		}else{
			dados = (histTemp *)realloc(dados, ((*_c)+1) * sizeof(histTemp));
		}
		a = aux->data.temp;
		b = (int)a;
		c = a - b;
		d = (int)(c * 1000);
		dados[*_c].t_min.i = b;
		dados[*_c].t_min.d = abs(d);
		dados[*_c].t_max.i = 0;
		dados[*_c].t_max.d = 0;
		dados[*_c].t_med.i = 0;
		dados[*_c].t_med.d = 0;
		limit = aux->data.date.y +  _n;
		while( aux != NULL && aux->data.date.y < limit ){

			if(aux->data.temp > (float)(dados[*_c].t_max.i + ((float)dados[*_c].t_max.d / 1000))){
				a = aux->data.temp;
				b = (int)a;
				c = a - b;
				d = (int)(c * 1000);
				dados[*_c].t_max.i = b;
				dados[*_c].t_max.d = abs(d);
			}else if(aux->data.temp < (float)(dados[*_c].t_min.i + ((float)dados[*_c].t_min.d / 1000))){
				a = aux->data.temp;
				b = (int)a;
				c = a - b;
				d = (int)(c * 1000);
				dados[*_c].t_min.i = b;
				dados[*_c].t_min.d = abs(d);
			}
			
			count++;
			som = som + aux->data.temp;
			
				aux = aux->next;
		}
		dados[*_c].t_i = limit - _n;
		dados[*_c].t_f = limit;
		a = som / count;
		b = (int)a;
		c = a - b;
		d = (int)(c * 1000);
		dados[*_c].t_med.i = b;
		dados[*_c].t_med.d = abs(d);
		count = 0;
		som = 0;
			
		(*_c)++;
	}
	return dados;
}

histTemp* histTempPais( int _n, lista_dl *_paises, int *_c, char _pais[]){
	histTemp *dados = NULL;
	lista_dl *aux = _paises->next;
	lista_dl *tmp = _paises->next;

	printf("%d\n", aux->data.date.y);

	int count=0; 
	float som=0;

	int limit = _paises->next->data.date.y + _n;

	float a=0,c=0;
	int b=0,d=0;

	

	while( strcmp(aux->data.country, _pais) != 0)
		aux = aux->next;
	if(strcmp(aux->data.country, _pais) != 0)
		(*_c)--;
	printf("%d\n", aux->data.date.y);

	while( aux != NULL ){
		
		printf("inicio %d\n", *_c);
		if(strcmp(aux->data.country, _pais)==0){
			if(*_c==0){
				dados = (histTemp *)malloc(sizeof(histTemp));
			}else{
				dados = (histTemp *)realloc(dados, ((*_c)+1) * sizeof(histTemp));
			}
			
			a = aux->data.temp;
			b = (int)a;
			c = a - b;
			d = (int)(c * 1000);
			dados[*_c].t_min.i = b;
			dados[*_c].t_min.d = abs(d);
			dados[*_c].t_max.i = 0;
			dados[*_c].t_max.d = 0;
			dados[*_c].t_med.i = 0;
			dados[*_c].t_med.d = 0;
			printf("dentro 3 %d.   %s\n", *_c, aux->data.country);
		}
		if(aux == NULL)
			printf("null\n");
		limit = aux->data.date.y + _n;
		printf("%d\n", limit);

		while( aux != NULL && aux->data.date.y < limit ){
			printf("llllllll\n");
			if(strcmp(aux->data.country, _pais)==0){
				if(aux->data.temp > (float)(dados[*_c].t_max.i + ((float)dados[*_c].t_max.d / 1000))){
					a = aux->data.temp;
					b = (int)a;
					c = a - b;
					d = (int)(c * 1000);
					dados[*_c].t_max.i = b;
					dados[*_c].t_max.d = abs(d);
				}else if(aux->data.temp < (float)(dados[*_c].t_min.i + ((float)dados[*_c].t_min.d / 1000))){
					a = aux->data.temp;
					b = (int)a;
					c = a - b;
					d = (int)(c * 1000);
					dados[*_c].t_min.i = b;
					dados[*_c].t_min.d = abs(d);
				}
				
				count++;
				som = som + aux->data.temp;
				printf("dentro 2 %d.   %s\n", *_c, aux->data.country);
				tmp = aux;
			}
			
			aux = aux->next;
			if (aux == NULL)
			{
				break;
			}
		}
		printf("%s\n", tmp->data.country);

		if(tmp != NULL && strcmp(tmp->data.country, _pais)==0){
			printf("limite final %d\n", limit);
			dados[*_c].t_i = limit - _n;
			dados[*_c].t_f = limit;
			a = som / count;
			b = (int)a;
			c = a - b;
			d = (int)(c * 1000);
			dados[*_c].t_med.i = b;
			dados[*_c].t_med.d = abs(d);
			count = 0;
			som = 0;
				
			printf("dentro 3 %d.   %s\n", *_c, tmp->data.country);
		}

				if(aux == NULL)
			printf("null\n");

		if(aux != NULL && strcmp(aux->data.country, _pais)==0)
			(*_c)++;
		printf("kkkk %d\n", *_c);
		
	}
	(*_c)++;
	printf("teste %d\n", *_c);
	return dados;
}

tempAno* analiseTempAnoPais( int _ano, int _n, lista_dl *_paises){
	tempAno* dados = NULL;
	dados = (tempAno *)malloc(_n * sizeof(tempAno));

	for (int i = 0; i < _n; ++i){
		dados[i].q = (char *)malloc(WORD * sizeof(char));
		dados[i].f = (char *)malloc(WORD * sizeof(char));
		dados[i].e = (char *)malloc(WORD * sizeof(char));
		strcpy(dados[i].q, "empty");
		strcpy(dados[i].f, "empty");
		strcpy(dados[i].e, "empty");
	}

	// vetor auxiliar que guarda cada temp neste ano
	paisTemp *tmp = NULL;
	int a=0;
	float x=0, y=0;

	// variavel auxiliar para percorrer a lista
	lista_dl *aux = _paises->next;

	while(aux != NULL){

		while(aux != NULL && aux->data.date.y == _ano){

			if((a) == 0){
				tmp = (paisTemp *)malloc(sizeof(paisTemp));
				tmp[a].p = (char *)malloc(WORD * sizeof(char));
			}else{
				tmp = (paisTemp *)realloc(tmp, ((a) + 1) * sizeof(paisTemp));
				tmp[a].p = (char *)malloc(WORD * sizeof(char));
			}

			tmp[a].t = aux->data.temp;
			strcpy(tmp[a].p, aux->data.country);

			a++;
			aux = aux->next;
		}

		aux = aux->next;
	}

	for (int i = 0; i < a; i++) {
		tmp[i].c = 1;
		tmp[i].d = 0;
		for (int j = i + 1; j < a;) {
			if (strcmp(tmp[i].p, tmp[j].p) == 0) {
				y = tmp[i].t - tmp[j].t;
				if( fabs(y) > fabs(x) )
					tmp[i].d = fabs(y);
				x = tmp[i].t - tmp[j].t;

				tmp[i].t = tmp[i].t + tmp[j].t;
				(tmp[i].c) ++;
				for (int k = j; k < (a - 1); k++) {
					strcpy(tmp[k].p, tmp[k+1].p);
					tmp[k].t = tmp[k+1].t;
				}
				a--;
			} else{
				j++;
			}
		}
		x=0;
		y=0;
   	}

   	for (int i = 0; i < a; ++i){
		tmp[i].t = tmp[i].t / tmp[i].c;
	}

	if (a < _n)
		_n = a;

	//ordenar e preencher o vetor dados
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < a; j++)
		{
			if (tmp[j].t < tmp[i].t)
			{
				float z = tmp[i].t;
				tmp[i].t = tmp[j].t;
				tmp[j].t = z;
				z = tmp[i].d;
				tmp[i].d = tmp[j].d;
				tmp[j].d = z;
				char *p = tmp[i].p;
				tmp[i].p = tmp[j].p;
				tmp[j].p = p;
			}
		}
	}

	for (int i = 0; i < _n; ++i){
		dados[i].q = tmp[i].p;
	}

	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < a; j++)
		{
			if (tmp[j].t > tmp[i].t)
			{
				float z = tmp[i].t;
				tmp[i].t = tmp[j].t;
				tmp[j].t = z;
				z = tmp[i].d;
				tmp[i].d = tmp[j].d;
				tmp[j].d = z;
				char *p = tmp[i].p;
				tmp[i].p = tmp[j].p;
				tmp[j].p = p;
			}
		}
	}

	for (int i = 0; i < _n; ++i){
		dados[i].f = tmp[i].p;
	}

	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < a; j++)
		{
			if (tmp[j].d < tmp[i].d)
			{
				float z = tmp[i].t;
				tmp[i].t = tmp[j].t;
				tmp[j].t = z;
				z = tmp[i].d;
				tmp[i].d = tmp[j].d;
				tmp[j].d = z;
				char *p = tmp[i].p;
				tmp[i].p = tmp[j].p;
				tmp[j].p = p;
			}
		}
	}

	for (int i = 0; i < _n; ++i){
		dados[i].e = tmp[i].p;
	}

	return dados;
}

tempAno* analiseTempAnoCidade( int _ano, int _n, lista_ct *_cidades){
	tempAno* dados = NULL;
	dados = (tempAno *)malloc(_n * sizeof(tempAno));

	for (int i = 0; i < _n; ++i){
		dados[i].q = (char *)malloc(WORD * sizeof(char));
		dados[i].f = (char *)malloc(WORD * sizeof(char));
		dados[i].e = (char *)malloc(WORD * sizeof(char));
		strcpy(dados[i].q, "empty");
		strcpy(dados[i].f, "empty");
		strcpy(dados[i].e, "empty");
	}

	// vetor auxiliar que guarda cada temp neste ano
	paisTemp *tmp = NULL;
	int a=0;
	float x=0, y=0;

	// variavel auxiliar para percorrer a lista
	lista_ct *aux = _cidades->next;

	do{

		while(aux != _cidades->next && aux->data.date.y == _ano){

			if((a) == 0){
				tmp = (paisTemp *)malloc(sizeof(paisTemp));
				tmp[a].p = (char *)malloc(WORD * sizeof(char));
			}else{
				tmp = (paisTemp *)realloc(tmp, ((a) + 1) * sizeof(paisTemp));
				tmp[a].p = (char *)malloc(WORD * sizeof(char));
			}

			tmp[a].t = aux->data.temp;
			strcpy(tmp[a].p, aux->data.city);

			a++;
			//printf("%d\n", a);
			aux = aux->next;
		}
		//if(aux != _cidades->next)
			aux = aux->next;
	}while(aux != _cidades->next);

	
	for (int i = 0; i < a; i++) {
		tmp[i].c = 1;
		tmp[i].d = 0;
		for (int j = i + 1; j < a;) {
			if (strcmp(tmp[i].p, tmp[j].p) == 0) {
				y = tmp[i].t - tmp[j].t;
				if( fabs(y) > fabs(x) )
					tmp[i].d = fabs(y);
				x = tmp[i].t - tmp[j].t;

				tmp[i].t = tmp[i].t + tmp[j].t;
				(tmp[i].c) ++;
				for (int k = j; k < (a - 1); k++) {
					strcpy(tmp[k].p, tmp[k+1].p);
					tmp[k].t = tmp[k+1].t;
				}
				a--;
			} else{
				j++;
			}
		}
		x=0;
		y=0;
   	}

   	printf("teste\n");


   	for (int i = 0; i < a; ++i){
		tmp[i].t = tmp[i].t / tmp[i].c;
	}

	if (a < _n)
		_n = a;

	//ordenar e preencher o vetor dados
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < a; j++)
		{
			if (tmp[j].t < tmp[i].t)
			{
				float z = tmp[i].t;
				tmp[i].t = tmp[j].t;
				tmp[j].t = z;
				z = tmp[i].d;
				tmp[i].d = tmp[j].d;
				tmp[j].d = z;
				char *p = tmp[i].p;
				tmp[i].p = tmp[j].p;
				tmp[j].p = p;
			}
		}
	}

	for (int i = 0; i < _n; ++i){
		dados[i].q = tmp[i].p;
	}

	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < a; j++)
		{
			if (tmp[j].t > tmp[i].t)
			{
				float z = tmp[i].t;
				tmp[i].t = tmp[j].t;
				tmp[j].t = z;
				z = tmp[i].d;
				tmp[i].d = tmp[j].d;
				tmp[j].d = z;
				char *p = tmp[i].p;
				tmp[i].p = tmp[j].p;
				tmp[j].p = p;
			}
		}
	}

	for (int i = 0; i < _n; ++i){
		dados[i].f = tmp[i].p;
	}

	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < a; j++)
		{
			if (tmp[j].d < tmp[i].d)
			{
				float z = tmp[i].t;
				tmp[i].t = tmp[j].t;
				tmp[j].t = z;
				z = tmp[i].d;
				tmp[i].d = tmp[j].d;
				tmp[j].d = z;
				char *p = tmp[i].p;
				tmp[i].p = tmp[j].p;
				tmp[j].p = p;
			}
		}
	}

	for (int i = 0; i < _n; ++i){
		dados[i].e = tmp[i].p;
	}

	return dados;	
}

float* aumTempGlobPlan(lista_dl *_paises, int _m){
	lista_dl *aux = _paises->next;
	
	tempMedia dados[13][400];
	int base = aux->data.date.y;
	// indices para os anos a calcular 
	int a = 1860;
	int b = 1910;
	int c = 1960;
	int d = 1990;
	int e = 2013;

	float *res = (float *)malloc(5 * sizeof(float));
	float *min = (float *)malloc(5 * sizeof(float));
	float *max = (float *)malloc(5 * sizeof(float));

	// Iniciar o count a 1 e a soma a 0

	for (int i = 0; i < 13; ++i){
		for(int j = 0; j < 400; ++j){
			dados[i][j].c = 1;
			dados[i][j].s = 0;
		}
	}

	// calcular a media de temp para cada mes e ano

	while(aux != NULL){

		dados[aux->data.date.m - 1][aux->data.date.y - base].s += aux->data.temp;
		dados[aux->data.date.m - 1][aux->data.date.y - base].c ++;
		dados[12][aux->data.date.y - base].y = aux->data.date.y;

		aux =  aux->next;
	}

	for (int i = 0; i < 12; ++i){
		for(int j = 0; j < 400; ++j){
			dados[i][j].t = dados[i][j].s / dados[i][j].c;
			//printf("%f\n", dados[i][j].t);
		}
	}


	// calcular a moving average
	int pos = 0;

	float *numbers = (float *)malloc(_m * sizeof(float));
	float sum = 0;

	for(int i = 0; i < 12; ++i){
		for(int j = 0; j < 400; ++j){
			dados[i][j].t = movingAvg(numbers, &sum, pos, _m, dados[i][j].t);
			//printf("%f\n", dados[i][j].t);
			pos++;
			if (pos >= _m){
			  pos = 0;
			}
		}
	}

	// calcular a media de cada ano

	for(int i = 0; i < 400; ++i){
		for(int j = 0; j < 12; ++j){
			dados[12][i].s += dados[j][i].t;
			dados[12][i].c ++;
		}
	}

	for(int i = 0; i < 400; ++i){
		dados[12][i].t = dados[12][i].s / dados[12][i].c;
		//printf("%f\n", dados[12][i].t);
	}

	// calcular o aumento de temp para 1860, 1910, 1960, 1990 e 2013

	for (int i = 0; i < 400; ++i){
		if(dados[12][i].y == a)
			a = i;
		else if(dados[12][i].y == b)
			b = i;
		else if(dados[12][i].y == c)
			c = i;
		else if(dados[12][i].y == d)
			d = i;
		else if(dados[12][i].y == e)
			e = i;
	}

	for (int i = 0; i < 5; ++i){
		min[i] = dados[12][i].t;
		max[i] = 0;
	}

	for (int i = 0; i < a; ++i){
		if( dados[12][i].t > max[0] )
			max[0] = dados[12][i].t;
		else if( dados[12][i].t < min[0] )
			min[0] = dados[12][i].t; 
	}

	for (int i = 0; i < b; ++i){
		if( dados[12][i].t > max[1] )
			max[1] = dados[12][i].t;
		else if( dados[12][i].t < min[1] )
			min[1] = dados[12][i].t; 
	}

	for (int i = 0; i < c; ++i){
		if( dados[12][i].t > max[2] )
			max[2] = dados[12][i].t;
		else if( dados[12][i].t < min[2] )
			min[2] = dados[12][i].t; 
	}

	for (int i = 0; i < d; ++i){
		if( dados[12][i].t > max[3] )
			max[3] = dados[12][i].t;
		else if( dados[12][i].t < min[3] )
			min[3] = dados[12][i].t; 
	}

	for (int i = 0; i < e; ++i){
		if( dados[12][i].t > max[4] )
			max[4] = dados[12][i].t;
		else if( dados[12][i].t < min[4] )
			min[4] = dados[12][i].t; 
	}

	for (int i = 0; i < 5; ++i){
		res[i] = fabs( max[i] - min[i] );
		printf("%f\n", res[i]);
	}

	return res;
}

float* aumTempGlobPais(lista_dl *_paises, int _m, char *_pais){
	lista_dl *aux = _paises->next;
	
	tempMedia dados[13][400];
	int base = aux->data.date.y;
	// indices para os anos a calcular 
	int a = 1860;
	int b = 1910;
	int c = 1960;
	int d = 1990;
	int e = 2013;

	float *res = (float *)malloc(5 * sizeof(float));
	float *min = (float *)malloc(5 * sizeof(float));
	float *max = (float *)malloc(5 * sizeof(float));

	// Iniciar o count a 1 e a soma a 0

	for (int i = 0; i < 13; ++i){
		for(int j = 0; j < 400; ++j){
			dados[i][j].c = 1;
			dados[i][j].s = 0;
		}
	}

	// calcular a media de temp para cada mes e ano

	while(aux != NULL){

		if(strcmp(aux->data.country, _pais) == 0){
			dados[aux->data.date.m - 1][aux->data.date.y - base].s += aux->data.temp;
			dados[aux->data.date.m - 1][aux->data.date.y - base].c ++;
			dados[12][aux->data.date.y - base].y = aux->data.date.y;
		}
		aux =  aux->next;
	}

	for (int i = 0; i < 12; ++i){
		for(int j = 0; j < 400; ++j){
			dados[i][j].t = dados[i][j].s / dados[i][j].c;
			//printf("%f\n", dados[i][j].t);
		}
	}


	// calcular a moving average
	int pos = 0;

	float *numbers = (float *)malloc(_m * sizeof(float));
	float sum = 0;

	for(int i = 0; i < 12; ++i){
		for(int j = 0; j < 400; ++j){
			dados[i][j].t = movingAvg(numbers, &sum, pos, _m, dados[i][j].t);
			//printf("%f\n", dados[i][j].t);
			pos++;
			if (pos >= _m){
			  pos = 0;
			}
		}
	}

	// calcular a media de cada ano

	for(int i = 0; i < 400; ++i){
		for(int j = 0; j < 12; ++j){
			dados[12][i].s += dados[j][i].t;
			dados[12][i].c ++;
		}
	}

	for(int i = 0; i < 400; ++i){
		dados[12][i].t = dados[12][i].s / dados[12][i].c;
		//printf("%f\n", dados[12][i].t);
	}

	// calcular o aumento de temp para 1860, 1910, 1960, 1990 e 2013

	for (int i = 0; i < 400; ++i){
		if(dados[12][i].y == a)
			a = i;
		else if(dados[12][i].y == b)
			b = i;
		else if(dados[12][i].y == c)
			c = i;
		else if(dados[12][i].y == d)
			d = i;
		else if(dados[12][i].y == e)
			e = i;
	}

	for (int i = 0; i < 5; ++i){
		min[i] = dados[12][i].t;
		max[i] = 0;
	}

	for (int i = 0; i < a; ++i){
		if( dados[12][i].t > max[0] )
			max[0] = dados[12][i].t;
		else if( dados[12][i].t < min[0] )
			min[0] = dados[12][i].t; 
	}

	for (int i = 0; i < b; ++i){
		if( dados[12][i].t > max[1] )
			max[1] = dados[12][i].t;
		else if( dados[12][i].t < min[1] )
			min[1] = dados[12][i].t; 
	}

	for (int i = 0; i < c; ++i){
		if( dados[12][i].t > max[2] )
			max[2] = dados[12][i].t;
		else if( dados[12][i].t < min[2] )
			min[2] = dados[12][i].t; 
	}

	for (int i = 0; i < d; ++i){
		if( dados[12][i].t > max[3] )
			max[3] = dados[12][i].t;
		else if( dados[12][i].t < min[3] )
			min[3] = dados[12][i].t; 
	}

	for (int i = 0; i < e; ++i){
		if( dados[12][i].t > max[4] )
			max[4] = dados[12][i].t;
		else if( dados[12][i].t < min[4] )
			min[4] = dados[12][i].t; 
	}

	for (int i = 0; i < 5; ++i){
		res[i] = fabs( max[i] - min[i] );
		printf("%f\n", res[i]);
	}

	return res;
}

float* aumTempGlobCida(lista_ct *_cidades, int _m, char *_cidade){
	lista_ct *aux = _cidades->next;
		
	tempMedia dados[13][400];
	
	do{
		if(strcmp(aux->data.city, _cidade) != 0)
			aux = aux->next;
		else
			break;
	}while(aux != _cidades->next);

	int base = aux->data.date.y;

	// indices para os anos a calcular 
	int a = 1860;
	int b = 1910;
	int c = 1960;
	int d = 1990;
	int e = 2013;

	float *res = (float *)malloc(5 * sizeof(float));
	float *min = (float *)malloc(5 * sizeof(float));
	float *max = (float *)malloc(5 * sizeof(float));

	// Iniciar o count a 1 e a soma a 0

	for (int i = 0; i < 13; ++i){
		for(int j = 0; j < 400; ++j){
			dados[i][j].c = 1;
			dados[i][j].s = 0;
		}
	}

	// calcular a media de temp para cada mes e ano

	do{

		if(strcmp(aux->data.city, _cidade) == 0){
			dados[aux->data.date.m - 1][aux->data.date.y - base].s += aux->data.temp;
			//printf("%d-%d\n", aux->data.date.y, aux->data.date.m);
			dados[aux->data.date.m - 1][aux->data.date.y - base].c ++;
			dados[12][aux->data.date.y - base].y = aux->data.date.y;
		}
		aux =  aux->next;
	}while(aux != _cidades->next);

	for (int i = 0; i < 12; ++i){
		for(int j = 0; j < 400; ++j){
			dados[i][j].t = dados[i][j].s / dados[i][j].c;
			//printf("%f\n", dados[i][j].t);
		}
	}


	// calcular a moving average
	int pos = 0;

	float *numbers = (float *)malloc(_m * sizeof(float));
	float sum = 0;

	for(int i = 0; i < 12; ++i){
		for(int j = 0; j < 400; ++j){
			dados[i][j].t = movingAvg(numbers, &sum, pos, _m, dados[i][j].t);
			//printf("%f\n", dados[i][j].t);
			pos++;
			if (pos >= _m){
			  pos = 0;
			}
		}
	}

	// calcular a media de cada ano

	for(int i = 0; i < 400; ++i){
		for(int j = 0; j < 12; ++j){
			dados[12][i].s += dados[j][i].t;
			dados[12][i].c ++;
		}
	}

	for(int i = 0; i < 400; ++i){
		dados[12][i].t = dados[12][i].s / dados[12][i].c;
		//printf("%f\n", dados[12][i].t);
	}

	// calcular o aumento de temp para 1860, 1910, 1960, 1990 e 2013

	for (int i = 0; i < 400; ++i){
		if(dados[12][i].y == a)
			a = i;
		else if(dados[12][i].y == b)
			b = i;
		else if(dados[12][i].y == c)
			c = i;
		else if(dados[12][i].y == d)
			d = i;
		else if(dados[12][i].y == e)
			e = i;
	}

	for (int i = 0; i < 5; ++i){
		min[i] = dados[12][i].t;
		max[i] = 0;
	}

	for (int i = 0; i < a; ++i){
		if( dados[12][i].t > max[0] )
			max[0] = dados[12][i].t;
		else if( dados[12][i].t < min[0] )
			min[0] = dados[12][i].t; 
	}

	for (int i = 0; i < b; ++i){
		if( dados[12][i].t > max[1] )
			max[1] = dados[12][i].t;
		else if( dados[12][i].t < min[1] )
			min[1] = dados[12][i].t; 
	}

	for (int i = 0; i < c; ++i){
		if( dados[12][i].t > max[2] )
			max[2] = dados[12][i].t;
		else if( dados[12][i].t < min[2] )
			min[2] = dados[12][i].t; 
	}

	for (int i = 0; i < d; ++i){
		if( dados[12][i].t > max[3] )
			max[3] = dados[12][i].t;
		else if( dados[12][i].t < min[3] )
			min[3] = dados[12][i].t; 
	}

	for (int i = 0; i < e; ++i){
		if( dados[12][i].t > max[4] )
			max[4] = dados[12][i].t;
		else if( dados[12][i].t < min[4] )
			min[4] = dados[12][i].t; 
	}

	for (int i = 0; i < 5; ++i){
		res[i] = fabs( max[i] - min[i] );
		printf("%f\n", res[i]);
	}

	return res;
}

float movingAvg(float *_numbers, float *_sum, int _pos, int _len, float _nextNum)
{
  *_sum = *_sum - _numbers[_pos] + _nextNum;
  _numbers[_pos] = _nextNum;
  return *_sum / _len;
}

void remove_mes(int mes_ini, int mes_fim, lista_dl *_paises, lista_ct *_cidades)
{
    lista_dl *aux = _paises->next, *tmp = NULL;
    while (aux != NULL){
        if( aux->data.date.m < mes_ini || aux->data.date.m > mes_fim){
            tmp = aux->next;
            if( aux->next != NULL){
                aux->next->prev = aux->prev;
            }
            aux->prev->next = aux->next;
            free(aux->data.country);
            free(aux);
            aux = tmp;
        }else{
            aux = aux->next;
        }
    }
    //lista_ct *aux2 = _cidades->next, *tmp2 = NULL;
    /*do{
        if( aux2->data.date.m < mes_ini || aux2->data.date.m > mes_fim){
            tmp2 = aux2->next;

            free(aux2->data.country);
            free(aux2->data.city);
            free(aux2);
            aux2 = tmp2;
        }else{
            aux2 = aux2->next;
        }
    }while (aux2 != _cidades->next);*/
}

void remove_intervalo(int mes, int ano,lista_dl *_paises, lista_ct **_cidades)
{
    lista_dl *aux = _paises->next, *tmp = NULL;
    while (aux != NULL){
        if( aux->data.date.y < ano || ( aux->data.date.y == ano && aux->data.date.m < mes) ){
            tmp = aux->next;
            if( aux->next != NULL){
                aux->next->prev = aux->prev;
            }
            aux->prev->next = aux->next;
            free(aux->data.country);
            free(aux);
            aux = tmp;
        }else{
            aux = aux->next;
        }
    }
    /*lista_ct *aux2 = *_cidades;
    do{
        if( aux2->data.date.y < ano || ( aux2->data.date.y == ano && aux2->data.date.m < mes) ){
        	printf("ww\n");
            
		        // create new pointer, points to next of curr node
		        lista_ct *temp = aux2->next;
		 
		        // Adjust the pointers of prev_1 and temp node
		        aux2->prev->next = temp;
		        temp->prev = aux2->prev;
		        free(aux2->data.country);
	            free(aux2->data.city);
	            free(aux2);
	            aux2 = temp;
        }else{
            aux2 = aux2->next;
        }
    }while (aux2 != *_cidades);*/
}


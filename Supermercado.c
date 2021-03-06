#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
// #include <conio.h>

typedef struct {
	int PDV_instalado_tamanho;
    int *PDV_instalado;
	int novos_PDVs_tamanho;
	int *novos_PDVs;
	int medida_de_agilidade;
	int tempos_limites_tamanho;
	int *tempos_limites;
} Setup_sistema;

void PDV_instalado_sistema(Setup_sistema *setup, char *linha){
	setup->PDV_instalado = (int *) malloc(sizeof(int));
	setup->PDV_instalado[0] = (int) linha[0];
	setup->PDV_instalado_tamanho = 1;
	char c = linha[1];
	for(int a = 1; c != '\n'; a++){
		if(c != ' '){
			setup->PDV_instalado = (int *) realloc(setup->PDV_instalado, (a + 1) * sizeof(int));
			setup->PDV_instalado[a] = (int) c;
			setup->PDV_instalado_tamanho++;
		}
		c = linha[a+1];
	}
}

void novos_PDVs_sistema(Setup_sistema *setup, char *linha){
	setup->novos_PDVs = (int *) malloc(sizeof(int));
	setup->novos_PDVs[0] = (int) linha[0];
	setup->novos_PDVs_tamanho = 1;
	char c = linha[1];
	for(int a = 1; c != '\n'; a++){
		if(c != ' '){
			setup->novos_PDVs = (int *) realloc(setup->novos_PDVs, (a + 1) * sizeof(int));
			setup->novos_PDVs[a] = (int) c;
			setup->novos_PDVs_tamanho++;
		}
		c = linha[a+1];
	}
}

void medida_de_agilidade_sistema(Setup_sistema *setup, char *linha){
	setup->medida_de_agilidade = 0;
	for(int i = 0; i < (strlen(linha) - 1); i++){
		setup->medida_de_agilidade = setup->medida_de_agilidade + (linha[i] * pow(10, (double) strlen(linha) -2 - i));
	}
	printf("%d", setup->medida_de_agilidade);
}

// Pontos de Venda (PDVs)
// atende clientes segundo uma polı́tica Primeiro a Chegar é o Primeiro a ser Atendido (fila)
// Os dados disponibilizados são estes:
// O número de PDVs, atualmente instalados;
// O fator de agilidade (FA) de cada operador(a) de caixa, variado entre [1,10]. Um FA igual a 1 indica máxima agilidade;

// TAD AGENDA

// TAD evento

int main(int argc, char const argv[]) {
	Setup_sistema setup;
	FILE *arq;
	char Linha[100];
	char *result;
	int i;

	//clrscr();

	arq = fopen("ent01.in", "rt");

	if (arq != NULL) {
		i = 1;
		while (!feof(arq)) {
			result = fgets(Linha, 50, arq);// o 'fgets' lê até 99 caracteres ou até o '\n'
			if (result){// Se foi possível ler
				if(i == 1){
					PDV_instalado_sistema(&setup, Linha);
				} else if(i == 2){
					novos_PDVs_sistema(&setup, Linha);
				} else if(i == 3){
					medida_de_agilidade_sistema(&setup, Linha);
					//pow(base, expoente);
					//for
					//setup.medida_de_agilidade = ;
				}
				//for(int j = 0; Linha[j] != ' '; j++) printf("%c",Linha[j]);
			}
			i++;
		}
	fclose(arq);
	}
/*
	// code
	agenda = criarAgenda();
	novo = lerDados(ent01.in);

	evento = criarEvento(novo->tipo, novo->tempo, novo);
	agendar(agenda, evento);

	while (!vaziaAgenda(agenda)) {
	evento = proximoevento(agenda);
	relogio = evento->tempo;
	if (evento->tipo == 'C'){
	// acões relacionada ao evento chegada de cliente
	// inserir na fila
	cliente = evento->carga;
	inserirNaFila(clientes, cliente);
	if (tamanhoFila(clientes) == 1)&&(CAIXALIVRE(PDVs)){
	evento = criarEvento('I', relogio, NULL);
	agendar(agenda, evento);
	}
	}else if(evento->tipo == 'S'){
	// acões relacionadas ao evento suspensao de atendimento
	pdv = evento->carga;
	pdv->status = 'S';
	// Precisa completar as ações de suspensão de ATENDIMENTO
	// Agendar quando o caixa retoma o atendimento

	}else if(evento->tipo == 'I'){
	// descobrir o PDV ocioso (RR)
	pdv=proximoPDV(PDV);
	if (pdv!=NULL){
	// retirar cliente;
	cliente = desenfileirar(clientes)

	///agendar o final do atendimento
	tempo = relogio + passarCompras + pagamento;
	evento=criarEvento('F', tempo, pdv);
	agendar(agenda, evento);
	}
	}else if(evento->tipo == 'F'){ // final de atendimento
	// evento de final de atendimento
	/// cliente = desenfileirar(clientes)
	pdv = evento->carga;
	pdv->status = 'L';
	if (!vazia(clientes)){
	evento = criarEvento('I', relogio, NULL);
	agendar(agenda, evento);
	}
	}
	// code 
	}
*/
	return 0;
} 
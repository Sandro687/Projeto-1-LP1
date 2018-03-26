#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Projeto-1.h"

typedef struct {
	int quantPavimentos, quantQuartos;
	double areaTerreno, areaConstruida;
	char logradouro[30], bairro[30], cep[16], cidade[30];
	int numero;
    double valor;
    char disponibilidade[15];
} tCasa;

typedef struct {
	double areaApartamento, valorCondominio;
	int quantQuartos, vagasGaragem;
	char posicao[30];
    char logradouro[30], bairro[30], cep[16], cidade[30];
	int numero;
    double valor;
    char disponibilidade[15];
} tApartamento;

typedef struct {
	double areaTerreno;
    char logradouro[30], bairro[30], cep[16], cidade[30];
	int numero;
    double valor;
    char disponibilidade[15];
} tTerreno;

void LimpaTela(){
	system("clear");
}

void CadastraImoveis(){
	int opcao;

	puts("----------------Cadastro de Imoveis----------------\n");
	printf("\t1 - Cadastrar casa.\n");
	printf("\t2 - Cadastrar apartamento.\n");
	printf("\t3 - Cadastrar terreno.\n");
	printf("\t4 - Voltar ao menu principal.\n\n");

	printf("\t0 - Sair..\n\n");
	puts("---------------------------------------------------\n");

	scanf("%d", &opcao);

	switch(opcao){
		case 1:
            LimpaTela();
			CadastraCasa();
			break;
		case 2:
            LimpaTela();
			CadastraApartamento();
			break;
		case 3:
            LimpaTela();
			CadastraTerreno();
			break;
		case 4:
            LimpaTela();
			Menu();
			break;
		case 0:
			LimpaTela();
			Sair();
			break;
		default:
            LimpaTela();
			puts("Opcao Invalida.\n");
			CadastraImoveis();
	}

}
void CadastraCasa(){
	tCasa casa;
	int s, situacao;

	printf("\tCadastro de casas.\n");

    printf("\tO imovel casa esta disponivel para venda ou aluguel? Digite 1 para compra e 2 para aluguel.\n");
    scanf("%d", &situacao);

    switch(situacao){
        case 1:
            strcpy(casa.disponibilidade, "Aluguel");
            break;
        case 2:
            strcpy(casa.disponibilidade, "Venda");
            break;
        default:
            puts("Opcao invalida.");
        LimpaTela();
        CadastraCasa();
    }

    printf("\tQual o valor do imovel?\n");
    scanf("%lf", &casa.valor);

	printf("\tQual o logradouro?\n");
	fgets(casa.logradouro, 30, stdin);
	s = strlen(casa.logradouro);
	casa.logradouro[s-1] = '\0';

    printf("\tQual o numero da casa?\n");
	scanf("%d", &casa.numero);

	printf("\tQual o bairro?\n");
	fgets(casa.bairro, 30, stdin);
	s = strlen(casa.bairro);
	casa.bairro[s-1] = '\0';

	printf("\tQual o CEP?\n");
	fgets(casa.cep, 16, stdin);
	s = strlen(casa.cep);
	casa.cep[s-1] = '\0';

	printf("\tQual a cidade onde a casa esta localizada?\n");
	fgets(casa.cidade, 30, stdin);
	s = strlen(casa.cidade);
	casa.cidade[s-1] = '\0';

	printf("\tQual a quantidade de pavimentos da casa?\n");
	scanf("%d", &casa.quantPavimentos);

	printf("\tQual a quantidade de quartos?\n ");
	scanf("%d", &casa.quantQuartos);

	printf("\tInsira a area do terreno.\n");
	scanf("%lf", &casa.areaTerreno);

	printf("\tInsira a area construida.\n");
	scanf("%lf", &casa.areaConstruida);
	LimpaTela();
	CadastraImoveis();
}
void CadastraApartamento(){
	tApartamento apartamento;
	int s, situacao;

    printf("\t Qual a situacao do apartamento? Digite 1 para venda ou digite 2 se esta para aluguel.\n");
    scanf("%d", &situacao);


    switch(situacao){
        case 1:
            strcpy(apartamento.disponibilidade, "Venda");
            break;
        case 2:
            strcpy(apartamento.disponibilidade, "Aluguel");
            break;
        default:
            puts("Opcao invalida.");
    }

    printf("\t Quanto custa o imovel?\n");
    scanf("%lf", &apartamento.valor);

    printf("\t Quanto custa o condominio?\n");
    scanf("%lf", &apartamento.valorCondominio);

    printf("\t Qual o logradouro?\n");
    fgets(apartamento.logradouro, 30, stdin);
    s = strlen(apartamento.logradouro);
    apartamento.logradouro[s-1] = '\0';

    printf("\t Qual o numero do apartamento?\n");
    scanf("%d", &apartamento.numero);

    printf("\t Qual o bairro?\n");
    fgets(apartamento.bairro, 30, stdin);
    s = strlen(apartamento.bairro);
    apartamento.bairro[s-1] = '\0';

    printf("\t Qual o CEP?\n");
    fgets(apartamento.cep, 16, stdin);
    s = strlen(apartamento.cep);
    apartamento.cep[s-1] = '\0';

    printf("\t Qual a cidade?\n");
    fgets(apartamento.cidade, 30, stdin);
    s = strlen(apartamento.cidade);
    apartamento.cidade[s-1] = '\0';

    printf("\t Qual a area do apartamento?\n");
    scanf("%lf", &apartamento.areaApartamento);

    printf("\t Quantos quartos?\n");
    scanf("%d", &apartamento.quantQuartos);

    printf("\t Quantas vagas na garagem?\n");
    scanf("%d", &apartamento.vagasGaragem);

    printf("\t Qual a posicao do apartamento?\n");
    fgets(apartamento.posicao, 30, stdin);
    s = strlen(apartamento.posicao);
    apartamento.posicao[s-1] = '\0';

    LimpaTela();
	CadastraImoveis();
}
void CadastraTerreno(){
	tTerreno terreno;
	int s, situacao;

    printf("\t O terreno esta para venda ou aluguel? Digite 1 para venda e 2 para aluguel.\n");
    scanf("%d", &situacao);

    switch(situacao){
        case 1:
            strcpy(terreno.disponibilidade, "Venda");
            break;
        case 2:
            strcpy(terreno.disponibilidade, "Aluguel");
            break;
        default:
            puts("Opcao invalida.");

    }

    printf("\t Quanto custa o terreno?\n");
    scanf("%lf", &terreno.valor);

	printf("\t Qual o logradouro?\n");
	fgets(terreno.logradouro, 30, stdin);
	s = strlen(terreno.logradouro);
	terreno.logradouro[s-1] = '\0';

    printf("\t Qual o numero do terreno?\n ");
	scanf("%d", &terreno.numero);

	printf("\t Qual o bairro?\n ");
	fgets(terreno.bairro, 30, stdin);
	s = strlen(terreno.bairro);
	terreno.bairro[s-1] = '\0';

	printf("\t Qual o CEP?\n");
	fgets(terreno.cep, 16, stdin);
	s = strlen(terreno.cep);
	terreno.cep[s-1] = '\0';

	printf("\t Qual a cidade onde o terreno esta localizado?\n");
	fgets(terreno.cidade, 30, stdin);
	s = strlen(terreno.cidade);
	terreno.cidade[s-1] = '\0';

	printf("\t Qual a area do terreno?\n");
	scanf("%lf", &terreno.areaTerreno);
    LimpaTela();
	CadastraImoveis();
}
void ConsultaImoveis(){
    tCasa casa;
    tApartamento apartamento;
    tTerreno terreno;

    int i;

    printf("----------------Casas Disponiveis----------------\n");
    while(1){

            if(strlen(casa.logradouro) > 1) {
                printf("\t Casa %d\n", i = i + 1);
                printf("\t Disponibilidade: %s\n", casa.disponibilidade);
                printf("\t Valor: R$ %.2lf\n", casa.valor);
                printf("\t Logradouro: %s\n", casa.logradouro);
                printf("\t Bairro: %s\n", casa.bairro);
                printf("\t %d pavimentos.\n", casa.quantPavimentos);
                printf("\t %d quartos.\n", casa.quantQuartos);
                printf("\t Area construida: %.2f metros quadrados.\n", casa.areaConstruida);
            } else
		break;
        }
    }

    void Menu(){
    int opcao;

    printf("\t 1 - Cadastrar imovel.\n");
    printf("\t 2 - Consultar imoveis disponiveis.\n");
    printf("\t 3 - Consultar informacoes sobre todos os imoveis.\n");
    printf("\t 4 - Consultar imoveis disponiveis para vender por tipo.\n");
    printf("\t 5 - Consultar imoveis disponiveis para alugar por bairro.\n");
    printf("\t 6 - Consultar imoveis disponiveis para vender por bairro.\n");
    printf("\t 7 - Consultar todos os imoveis disponiveis em determinada cidade.\n\n");

    printf("\t 0 - Sair. \n\n");

    scanf("%d", &opcao);

    switch(opcao){
        case 1:
            LimpaTela();
            CadastraImoveis();
            break;
        case 2:
            LimpeTela();
            ConsultaImoveis();
            break;
        case 3:
            LimpaTela();
            ConsultaDescricaoImoveis();
            break;
        case 4:
            LimpaTela();
            ConsultaImoveisTipo();
            break;
        case 5:
            LimpaTela();
            ConsultaImoveisBairroAlugar();
            break;
        case 6:
            LimpaTela();
            ConsultaImoveisBairroVender();
            break;
        case 7:
            LimpaTela();
            ConsultaDescricaoCidade();
            break;
        case 0:
            LimpaTela();
            Sair();
            break;
        default:
            LimpaTela();
            printf("Opcao invalida.\n");
            Menu();
            break;
    }
}
int main(void){
CadastraImoveis();
return 0;
}

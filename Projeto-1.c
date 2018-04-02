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
    tCasa casa[30];

typedef struct {
	double areaApartamento, valorCondominio;
	int quantQuartos, vagasGaragem;
	char posicao[30];
    char logradouro[30], bairro[30], cep[16], cidade[30];
	int numero;
    double valor;
    char disponibilidade[15];
} tApartamento;
    tApartamento apartamento[30];

typedef struct {
	double areaTerreno;
    char logradouro[30], bairro[30], cep[16], cidade[30];
	int numero;
    double valor;
    char disponibilidade[15];
} tTerreno;
    tTerreno terreno[30];

typedef struct {
	double areaFlat, valorCondominio;
	int quantQuartos, vagasGaragem;
	char posicao[30];
    char logradouro[30], bairro[30], cep[16], cidade[30];
	int numero;
    double valor;
    char disponibilidade[15];
    int arCondicionado, internet, tvCabo, lavanderia, arrumacaoLimpeza, recepcao24H;
} tFlat;
    tFlat flat[30];

typedef struct {
	double areaStudio, valorCondominio;
	int quantQuartos, vagasGaragem;
	char posicao[30];
    char logradouro[30], bairro[30], cep[16], cidade[30];
	int numero;
    double valor;
    char disponibilidade[15];
    int arCondicionado, internet, tvCabo, lavanderia, arrumacaoLimpeza, recepcao24H;
    int piscina, sauna, salaGinastica;
} tStudio;
    tStudio studio[30];

void LimpaTela(){
	system("clear");
}

void CadastraImoveis(){
	int opcao;

	printf("----------------Cadastro de Imoveis----------------\n");
	printf("1 - Cadastrar casa.\n");
	printf("2 - Cadastrar apartamento.\n");
	printf("3 - Cadastrar terreno.\n");
	printf("4 - Cadastrar flat.\n");
	printf("5 - Cadastrar studio.\n");
	printf("6 - Voltar ao menu principal.\n");

	printf("0 - Sair.\n");
	printf("---------------------------------------------------\n");

	scanf("%d%*c", &opcao);

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
			CadastraFlat();
			break;
		case 5:
            LimpaTela();
			CadastraStudio();
			break;
		case 6:
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

	int s, situacao;
    int i, t;

	printf("----------------Cadastro de casas----------------\n");
    printf("Quantas casas deseja cadastrar?(30 max)\n");
    scanf("%d%*c", &i);

    for (t = 0; t < i; t++){
    printf("O imovel casa esta disponivel para venda ou aluguel? Digite 1 para venda e 2 para aluguel.\n");
    scanf("%d%*c", &situacao);

    switch(situacao){
        case 1:
            strcpy(casa[t].disponibilidade, "Venda");
            break;
        case 2:
            strcpy(casa[t].disponibilidade, "Aluguel");
            break;
        default:
            puts("Opcao invalida.");
        LimpaTela();
        CadastraCasa();
    }

    printf("Qual o valor do imovel?\n");
    scanf("%lf%*c", &casa[t].valor);

	printf("Qual o logradouro?\n");
	fgets(casa[t].logradouro, 30, stdin);
	s = strlen(casa[t].logradouro);
	casa[t].logradouro[s-1] = '\0';

    printf("Qual o numero da casa?\n");
	scanf("%d%*c", &casa[t].numero);

	printf("Qual o bairro?\n");
	fgets(casa[t].bairro, 30, stdin);
	s = strlen(casa[t].bairro);
	casa[t].bairro[s-1] = '\0';

	printf("Qual o CEP?\n");
	fgets(casa[t].cep, 16, stdin);
	s = strlen(casa[t].cep);
	casa[t].cep[s-1] = '\0';

	printf("Qual a cidade onde a casa esta localizada?\n");
	fgets(casa[t].cidade, 30, stdin);
	s = strlen(casa[t].cidade);
	casa[t].cidade[s-1] = '\0';

	printf("Qual a quantidade de pavimentos da casa?\n");
	scanf("%d%*c", &casa[t].quantPavimentos);

	printf("Qual a quantidade de quartos?\n ");
	scanf("%d%*c", &casa[t].quantQuartos);

	printf("Insira a area do terreno.\n");
	scanf("%lf%*c", &casa[t].areaTerreno);

	printf("Insira a area construida.\n");
	scanf("%lf%*c", &casa[t].areaConstruida);
	LimpaTela();
    }
	CadastraImoveis();
}
void CadastraApartamento(){

	int s, situacao;
    int i, t;

    printf("----------------Cadastro de Apartamentos----------------\n");
    printf("Quantos apartamentos deseja cadastrar?(30 max)\n");
    scanf("%d%*c", &i);

    for (t = 0; t < i; t++){
    printf("Qual a situacao do apartamento? Digite 1 para venda ou digite 2 se esta para aluguel.\n");
    scanf("%d%*c", &situacao);


    switch(situacao){
        case 1:
            strcpy(apartamento[t].disponibilidade, "Venda");
            break;
        case 2:
            strcpy(apartamento[t].disponibilidade, "Aluguel");
            break;
        default:
            puts("Opcao invalida.");
    }

    printf("Quanto custa o imovel?\n");
    scanf("%lf%*c", &apartamento[t].valor);

    printf("Quanto custa o condominio?\n");
    scanf("%lf%*c", &apartamento[t].valorCondominio);

    printf("Qual o logradouro?\n");
    fgets(apartamento[t].logradouro, 30, stdin);
    s = strlen(apartamento[t].logradouro);
    apartamento[t].logradouro[s-1] = '\0';

    printf("Qual o numero do apartamento?\n");
    scanf("%d%*c", &apartamento[t].numero);

    printf("Qual o bairro?\n");
    fgets(apartamento[t].bairro, 30, stdin);
    s = strlen(apartamento[t].bairro);
    apartamento[t].bairro[s-1] = '\0';

    printf("Qual o CEP?\n");
    fgets(apartamento[t].cep, 16, stdin);
    s = strlen(apartamento[t].cep);
    apartamento[t].cep[s-1] = '\0';

    printf("Qual a cidade?\n");
    fgets(apartamento[t].cidade, 30, stdin);
    s = strlen(apartamento[t].cidade);
    apartamento[t].cidade[s-1] = '\0';

    printf("Qual a area do apartamento?\n");
    scanf("%lf%*c", &apartamento[t].areaApartamento);

    printf("Quantos quartos?\n");
    scanf("%d%*c", &apartamento[t].quantQuartos);

    printf("Quantas vagas na garagem?\n");
    scanf("%d%*c", &apartamento[t].vagasGaragem);

    printf("Qual a posicao do apartamento?\n");
    fgets(apartamento[t].posicao, 30, stdin);
    s = strlen(apartamento[t].posicao);
    apartamento[t].posicao[s-1] = '\0';

    LimpaTela();
	}
	CadastraImoveis();
}
void CadastraFlat(){

	int s, situacao;
    int i, t;

    printf("----------------Cadastro de Apartamentos Flat----------------\n");
    printf("Quantos apartamentos Flat deseja cadastrar?(30 max)\n");
    scanf("%d%*c", &i);

    for (t = 0; t < i; t++){
    printf("Qual a situacao do apartamento Flat? Digite 1 para venda ou digite 2 se esta para aluguel.\n");
    scanf("%d%*c", &situacao);


    switch(situacao){
        case 1:
            strcpy(flat[t].disponibilidade, "Venda");
            break;
        case 2:
            strcpy(flat[t].disponibilidade, "Aluguel");
            break;
        default:
            puts("Opcao invalida.");
    }

    printf("Quanto custa o imovel?\n");
    scanf("%lf%*c", &flat[t].valor);

    printf("Quanto custa o condominio?\n");
    scanf("%lf%*c", &flat[t].valorCondominio);

    printf("Qual o logradouro?\n");
    fgets(flat[t].logradouro, 30, stdin);
    s = strlen(flat[t].logradouro);
    flat[t].logradouro[s-1] = '\0';

    printf("Qual o numero do apartamento?\n");
    scanf("%d%*c", &flat[t].numero);

    printf("Qual o bairro?\n");
    fgets(flat[t].bairro, 30, stdin);
    s = strlen(flat[t].bairro);
    flat[t].bairro[s-1] = '\0';

    printf("Qual o CEP?\n");
    fgets(flat[t].cep, 16, stdin);
    s = strlen(flat[t].cep);
    flat[t].cep[s-1] = '\0';

    printf("Qual a cidade?\n");
    fgets(flat[t].cidade, 30, stdin);
    s = strlen(flat[t].cidade);
    flat[t].cidade[s-1] = '\0';

    printf("Qual a area do apartamento?\n");
    scanf("%lf%*c", &flat[t].areaFlat);

    printf("Quantos quartos?\n");
    scanf("%d%*c", &flat[t].quantQuartos);

    printf("Quantas vagas na garagem?\n");
    scanf("%d%*c", &flat[t].vagasGaragem);

    printf("Qual a posicao do apartamento?\n");
    fgets(flat[t].posicao, 30, stdin);
    s = strlen(flat[t].posicao);
    flat[t].posicao[s-1] = '\0';

    printf("Dispoe de ar-condicionado? Digite 1 caso sim e 0 caso nao.\n");
    scanf("%d%*c", &flat[t].arCondicionado);

    printf("Possui internet? Digite 1 caso sim e 0 caso nao.\n");
    scanf("%d%*c", &flat[t].internet);

    printf("Possui TV a cabo? Digite 1 caso sim e 0 caso nao.\n");
    scanf("%d%*c", &flat[t].tvCabo);

    printf("Possui servicos de lavanderia? Digite 1 caso sim e 0 caso nao.\n");
    scanf("%d%*c", &flat[t].lavanderia);

    printf("Possui servicos de arrumacao elimpeza? Digite 1 caso sim e 0 caso nao.\n");
    scanf("%d%*c", &flat[t].arrumacaoLimpeza);

    printf("Possui recepcao 24 horas? Digite 1 caso sim e 0 caso nao.\n");
    scanf("%d%*c", &flat[t].recepcao24H);

    LimpaTela();
	}
	CadastraImoveis();
}
void CadastraStudio(){

	int s, situacao;
    int i, t;

    printf("----------------Cadastro de Apartamentos Studio----------------\n");
    printf("Quantos apartamentos Studio deseja cadastrar?(30 max)\n");
    scanf("%d%*c", &i);

    for (t = 0; t < i; t++){
    printf("Qual a situacao do apartamento Studio? Digite 1 para venda ou digite 2 se esta para aluguel.\n");
    scanf("%d%*c", &situacao);


    switch(situacao){
        case 1:
            strcpy(studio[t].disponibilidade, "Venda");
            break;
        case 2:
            strcpy(studio[t].disponibilidade, "Aluguel");
            break;
        default:
            puts("Opcao invalida.");
    }

    printf("Quanto custa o imovel?\n");
    scanf("%lf%*c", &studio[t].valor);

    printf("Quanto custa o condominio?\n");
    scanf("%lf%*c", &studio[t].valorCondominio);

    printf("Qual o logradouro?\n");
    fgets(studio[t].logradouro, 30, stdin);
    s = strlen(studio[t].logradouro);
    studio[t].logradouro[s-1] = '\0';

    printf("Qual o numero do apartamento?\n");
    scanf("%d%*c", &studio[t].numero);

    printf("Qual o bairro?\n");
    fgets(studio[t].bairro, 30, stdin);
    s = strlen(studio[t].bairro);
    studio[t].bairro[s-1] = '\0';

    printf("Qual o CEP?\n");
    fgets(studio[t].cep, 16, stdin);
    s = strlen(studio[t].cep);
    studio[t].cep[s-1] = '\0';

    printf("Qual a cidade?\n");
    fgets(studio[t].cidade, 30, stdin);
    s = strlen(studio[t].cidade);
    studio[t].cidade[s-1] = '\0';

    printf("Qual a area do apartamento?\n");
    scanf("%lf%*c", &studio[t].areaStudio);

    printf("Quantos quartos?\n");
    scanf("%d%*c", &studio[t].quantQuartos);

    printf("Quantas vagas na garagem?\n");
    scanf("%d%*c", &studio[t].vagasGaragem);

    printf("Qual a posicao do apartamento?\n");
    fgets(studio[t].posicao, 30, stdin);
    s = strlen(studio[t].posicao);
    studio[t].posicao[s-1] = '\0';

    printf("Dispoe de ar-condicionado? Digite 1 caso sim e 0 caso nao.\n");
    scanf("%d%*c", &studio[t].arCondicionado);

    printf("Possui internet? Digite 1 caso sim e 0 caso nao.\n");
    scanf("%d%*c", &studio[t].internet);

    printf("Possui TV a cabo? Digite 1 caso sim e 0 caso nao.\n");
    scanf("%d%*c", &studio[t].tvCabo);

    printf("Possui servicos de lavanderia? Digite 1 caso sim e 0 caso nao.\n");
    scanf("%d%*c", &studio[t].lavanderia);

    printf("Possui servicos de arrumacao e limpeza? Digite 1 caso sim e 0 caso nao.\n");
    scanf("%d%*c", &studio[t].arrumacaoLimpeza);

    printf("Possui recepcao 24 horas? Digite 1 caso sim e 0 caso nao.\n");
    scanf("%d%*c", &studio[t].recepcao24H);

    printf("Possui Piscina? Digite 1 caso sim e 0 caso nao.\n");
    scanf("%d%*c", &studio[t].piscina);

    printf("Possui sauna? Digite 1 caso sim e 0 caso nao.\n");
    scanf("%d%*c", &studio[t].sauna);

    printf("Possui sala de ginastica? Digite 1 caso sim e 0 caso nao.\n");
    scanf("%d%*c", &studio[t].salaGinastica);

    LimpaTela();
	}
	CadastraImoveis();
}
void CadastraTerreno(){

	int s, situacao;
    int i, t;

    printf("----------------Cadastro de terrenos-----------------\n");
    printf("Qual a quantidade de terrenos a ser cadastrada?(30 max)\n");
    scanf("%d%*c", &i);

    for (t = 0; t < i; t++){
    printf("O terreno esta para venda ou aluguel? Digite 1 para venda e 2 para aluguel.\n");
    scanf("%d%*c", &situacao);

    switch(situacao){
        case 1:
            strcpy(terreno[t].disponibilidade, "Venda");
            break;
        case 2:
            strcpy(terreno[t].disponibilidade, "Aluguel");
            break;
        default:
            puts("Opcao invalida.");

    }

    printf("Quanto custa o terreno?\n");
    scanf("%lf%*c", &terreno[t].valor);

	printf("Qual o logradouro?\n");
	fgets(terreno[t].logradouro, 30, stdin);
	s = strlen(terreno[t].logradouro);
	terreno[t].logradouro[s-1] = '\0';

    printf("Qual o numero do terreno?\n ");
	scanf("%d%*c", &terreno[t].numero);

	printf("Qual o bairro?\n ");
	fgets(terreno[t].bairro, 30, stdin);
	s = strlen(terreno[t].bairro);
	terreno[t].bairro[s-1] = '\0';

	printf("Qual o CEP?\n");
	fgets(terreno[t].cep, 16, stdin);
	s = strlen(terreno[t].cep);
	terreno[t].cep[s-1] = '\0';

	printf("Qual a cidade onde o terreno esta localizado?\n");
	fgets(terreno[t].cidade, 30, stdin);
	s = strlen(terreno[t].cidade);
	terreno[t].cidade[s-1] = '\0';

	printf("Qual a area do terreno?\n");
	scanf("%lf%*c", &terreno[t].areaTerreno);
    }
    LimpaTela();
	CadastraImoveis();
}
void ConsultaImoveis(){

    int i = 0;
    printf("----------------Disponibilidade de Imoveis----------------\n");
    printf("---------------------Casas Disponiveis--------------------\n");
    while(i < 30){

        if(strlen(casa[i].logradouro) > 1){
            printf("Casa %d esta disponivel.\n", i+1);
        }else
            break;
        i++;
    }
    i = 0;
    printf("---------------------Apartamentos Disponiveis----------------\n");
    while (i < 30){
        if(strlen(apartamento[i].logradouro) > 1){
            printf("Apartamento %d esta disponivel.\n", i+1);
        }else
            break;
        i++;
    }
    i = 0;
    printf("---------------------Apartamentos Flat Disponiveis----------------\n");
    while (i < 30){
        if(strlen(flat[i].logradouro) > 1){
            printf("Apartamento Flat %d esta disponivel.\n", i+1);
        }else
            break;
        i++;
    }
    i = 0;
    printf("---------------------Apartamentos Studio Disponiveis----------------\n");
    while (i < 30){
        if(strlen(studio[i].logradouro) > 1){
            printf("Apartamento Studio %d esta disponivel.\n", i+1);
        }else
            break;
        i++;
    }
    i = 0;
    printf("---------------------Terrenos Disponiveis--------------------\n");
    while (i < 30){
        if(strlen(terreno[i].logradouro) > 1){
            printf("Terreno %d esta disponivel.\n", i+1);
        }else
            break;
        i++;
    }
}
    void Menu(){
    int opcao;

    printf("-----------------Menu------------------\n");
    printf("1 - Cadastrar imovel.\n");
    printf("2 - Consultar imoveis disponiveis.\n");
    printf("3 - Consultar informacoes sobre todos os imoveis.\n");
    printf("4 - Consultar imoveis disponiveis para vender por tipo.\n");
    printf("5 - Consultar imoveis disponiveis para alugar por tipo.\n");
    printf("6 - Consultar imoveis disponiveis para alugar por bairro.\n");
    printf("7 - Consultar imoveis disponiveis para vender por bairro.\n");
    printf("8 - Consultar todos os imoveis disponiveis em determinada cidade.\n\n");

    printf("0 - Sair. \n\n");

    scanf("%d%*c", &opcao);

    switch(opcao){
        case 1:
            LimpaTela();
            CadastraImoveis();
            break;
        case 2:
            LimpaTela();
            ConsultaImoveis();
            printf("Aperte ENTER para continuar.\n");
            scanf("%*c");
            LimpaTela();
            Menu();
            break;
        case 3:
            LimpaTela();
            ConsultaDescricaoImoveis();
            printf("Aperte ENTER para continuar.\n");
            scanf("%*c");
            LimpaTela();
            Menu();
            break;
        case 4:
            LimpaTela();
            ConsultaImoveisTipoVender();
            printf("Aperte ENTER para continuar.\n");
            scanf("%*c");
            LimpaTela();
            Menu();
            break;
        case 5:
            LimpaTela();
            ConsultaImoveisTipoAlugar();
            printf("Aperte ENTER para continuar.\n");
            scanf("%*c");
            LimpaTela();
            Menu();
            break;
        case 6:
            LimpaTela();
            ConsultaImoveisBairroAlugar();
            printf("Aperte ENTER para continuar.\n");
            scanf("%*c");
            LimpaTela();
            Menu();
            break;
        case 7:
            LimpaTela();
            ConsultaImoveisBairroVender();
            printf("Aperte ENTER para continuar.\n");
            scanf("%*c");
            LimpaTela();
            Menu();
            break;
        case 8:
            LimpaTela();
            ConsultaDescricaoCidade();
            printf("Aperte ENTER para continuar.\n");
            scanf("%*c");
            LimpaTela();
            Menu();
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
void ConsultaDescricaoImoveis(){

    int i = 0;
    printf("----------------Disponibilidade de Imoveis----------------\n");
    printf("---------------------Casas Disponiveis--------------------\n");
    while(i < 30){

        if(strlen(casa[i].logradouro) > 1){
            printf("Casa %d\n", i+1);
            printf("Disponibilidade: %s\n", casa[i].disponibilidade);
            printf("Valor: R$ %.2lf\n", casa[i].valor);
            printf("Logradouro: %s\n", casa[i].logradouro);
            printf("Bairro: %s\n", casa[i].bairro);
            printf("%d pavimentos.\n", casa[i].quantPavimentos);
            printf("%d quartos.\n", casa[i].quantQuartos);
            printf("Area construida: %.2f metros quadrados.\n", casa[i].areaConstruida);
            printf("Area do terreno: %lf\n", casa[i].areaTerreno);
            printf("CEP: %s\n", casa[i].cep);
            printf("Numero: %d\n", casa[i].numero);
            printf("Cidade: %s\n", casa[i].cidade);
            printf("\n");
        }else
            break;
        i++;
    }
    i = 0;
    printf("---------------------Apartamentos Disponiveis----------------\n");
    while (i < 30){
        if(strlen(apartamento[i].logradouro) > 1){
            printf("Apartamento %d\n", i+1);
            printf("Disponibilidade: %s\n", apartamento[i].disponibilidade);
            printf("Valor: R$ %.2lf\n", apartamento[i].valor);
            printf("Logradouro: %s\n", apartamento[i].logradouro);
            printf("Bairro: %s\n", apartamento[i].bairro);
            printf("%d quartos.\n", apartamento[i].quantQuartos);
            printf("Area: %.2f metros quadrados.\n", apartamento[i].areaApartamento);
            printf("Custo: %lf\n", apartamento[i].valorCondominio);
            printf("%d vagas de garagem.\n", apartamento[i].vagasGaragem);
            printf("Posicao %s\n", apartamento[i].posicao);
            printf("CEP: %s\n", apartamento[i].cep);
            printf("Cidade: %s\n", apartamento[i].cidade);
            printf("Numero: %d\n", apartamento[i].numero);
            printf("\n");
        }
        else
            break;
        i++;
    }
    i = 0;
    printf("---------------------Apartamentos Flat Disponiveis----------------\n");
    while (i < 30){
        if(strlen(flat[i].logradouro) > 1){
            printf("Apartamento Flat %d\n", i+1);
            printf("Disponibilidade: %s\n", flat[i].disponibilidade);
            printf("Valor: R$ %.2lf\n", flat[i].valor);
            printf("Logradouro: %s\n", flat[i].logradouro);
            printf("Bairro: %s\n", flat[i].bairro);
            printf("%d quartos.\n", flat[i].quantQuartos);
            printf("Area: %.2f metros quadrados.\n", flat[i].areaFlat);
            printf("Custo: %lf\n", flat[i].valorCondominio);
            printf("%d vagas de garagem.\n", flat[i].vagasGaragem);
            printf("Posicao %s\n", flat[i].posicao);
            printf("CEP: %s\n", flat[i].cep);
            printf("Cidade: %s\n", flat[i].cidade);
            printf("Numero: %d\n", flat[i].numero);
            if (flat[i].arCondicionado == 1){
                printf("Dispoe de ar-condicionado.\n");
            }else{
                printf("Nao dispoe de ar-condicionado.\n");
            }
            if (flat[i].internet == 1){
                printf("Dispoe de internet.\n");
            }else{
                printf("Nao dispoe de internet.\n");
            }
            if (flat[i].tvCabo == 1){
                printf("Dispoe de TV a cabo.\n");
            }else{
                printf("Nao dispoe de TV a cabo.\n");
            }
            if (flat[i].lavanderia == 1){
                printf("Dispoe de servicos de lavanderia.\n");
            }else{
                printf("Nao dispoe de servicos de lavanderia.\n");
            }
            if (flat[i].arrumacaoLimpeza == 1){
                printf("Dispoe de servicos de arrumacao e limpeza.\n");
            }else{
                printf("Nao dispoe de servicos de arrumacao e limpeza.\n");
            }
            if (flat[i].recepcao24H == 1){
                printf("Dispoe de recepcao 24h.\n");
            }else{
                printf("Nao dispoe de recepcao 24h.\n");
            }
            printf("\n");
        }
        else
            break;
        i++;
    }
    i = 0;
    printf("---------------------Apartamentos Studio Disponiveis----------------\n");
    while (i < 30){
        if(strlen(studio[i].logradouro) > 1){
            printf("Apartamento Studio %d\n", i+1);
            printf("Disponibilidade: %s\n", studio[i].disponibilidade);
            printf("Valor: R$ %.2lf\n", studio[i].valor);
            printf("Logradouro: %s\n", studio[i].logradouro);
            printf("Bairro: %s\n", studio[i].bairro);
            printf("%d quartos.\n", studio[i].quantQuartos);
            printf("Area: %.2f metros quadrados.\n", studio[i].areaStudio);
            printf("Custo: %lf\n", studio[i].valorCondominio);
            printf("%d vagas de garagem.\n", studio[i].vagasGaragem);
            printf("Posicao %s\n", studio[i].posicao);
            printf("CEP: %s\n", studio[i].cep);
            printf("Cidade: %s\n", studio[i].cidade);
            printf("Numero: %d\n", studio[i].numero);
            if (studio[i].arCondicionado == 1){
                printf("Dispoe de ar-condicionado.\n");
            }else{
                printf("Nao dispoe de ar-condicionado.\n");
            }
            if (studio[i].internet == 1){
                printf("Dispoe de internet.\n");
            }else{
                printf("Nao dispoe de internet.\n");
            }
            if (studio[i].tvCabo == 1){
                printf("Dispoe de TV a cabo.\n");
            }else{
                printf("Nao dispoe de TV a cabo.\n");
            }
            if (studio[i].lavanderia == 1){
                printf("Dispoe de servicos de lavanderia.\n");
            }else{
                printf("Nao dispoe de servicos de lavanderia.\n");
            }
            if (studio[i].arrumacaoLimpeza == 1){
                printf("Dispoe de servicos de arrumacao e limpeza.\n");
            }else{
                printf("Nao dispoe de servicos de arrumacao e limpeza.\n");
            }
            if (studio[i].recepcao24H == 1){
                printf("Dispoe de recepcao 24h.\n");
            }else{
                printf("Nao dispoe de recepcao 24h.\n");
            }
            if (studio[i].piscina == 1){
                printf("Dispoe de piscina.\n");
            }else{
                printf("Nao dispoe de piscina.\n");
            }
            if (studio[i].sauna == 1){
                printf("Dispoe de sauna.\n");
            }else{
                printf("Nao dispoe de sauna.\n");
            }
            if (studio[i].salaGinastica == 1){
                printf("Dispoe de sala de ginastica.\n");
            }else{
                printf("Nao dispoe de sala de ginastica.\n");
            }
            printf("\n");
        }
        else
            break;
        i++;
    }
    i = 0;
    printf("---------------------Terrenos Disponiveis--------------------\n");
    while (i < 30){
        if(strlen(terreno[i].logradouro) > 1){
            printf("Terreno %d\n", i+1);
            printf("Disponibilidade: %s\n", terreno[i].disponibilidade);
            printf("Valor: R$ %.2lf\n", terreno[i].valor);
            printf("Logradouro: %s\n", terreno[i].logradouro);
            printf("Bairro: %s\n", terreno[i].bairro);
            printf("Area do terreno: %lf\n", terreno[i].areaTerreno);
            printf("CEP: %s\n", terreno[i].cep);
            printf("Cidade: %s\n", terreno[i].cidade);
            printf("Numero : %d\n", terreno[i].numero);
            printf("\n");
        }else
            break;
        i++;
    }
}
void Sair(){
    return 0;
}
void ConsultaImoveisTipoVender(){
    char tipoImovel[30], cas[30], apart[30], terr[30], fla[30], stdi[30], dispon[30];
    int s, i = 0;
    strcpy(cas, "casa");
    strcpy(apart, "apartamento");
    strcpy(terr, "terreno");
    strcpy(fla, "flat");
    strcpy(stdi, "studio");
    strcpy(dispon, "Venda");
    printf("----------------Procura de imoveis por tipo----------------\n");
    printf("Qual imovel deseja procurar?\n");
    printf("Digite [casa], [apartamento], [terreno], [flat] ou [studio].\n");
    printf("Todas as letras em menusculo e sem [  ].\n");
    fgets(tipoImovel, 30, stdin);
	s = strlen(tipoImovel);
	tipoImovel[s-1] = '\0';

    if (strcmp(tipoImovel, cas) == 0){
        while (i < 30){
            if (strcmp(dispon, casa[i].disponibilidade) == 0){
                printf("A casa %d esta disponivel para venda.\n", i+1);
            }
            i++;
        }
    }else if (strcmp(tipoImovel, apart) == 0){
        while (i < 30){
            if (strcmp(dispon, apartamento[i].disponibilidade) == 0){
                printf("O apartamento %d esta disponivel para venda.\n", i+1);
            }
            i++;
        }
    }else if (strcmp(tipoImovel, terr) == 0){
        while (i < 30){
            if (strcmp(dispon, terreno[i].disponibilidade) == 0){
                printf("O terreno %d esta disponivel para venda.\n", i+1);
            }
            i++;
        }
    }else if (strcmp(tipoImovel, fla) == 0){
        while (i < 30){
            if (strcmp(dispon, flat[i].disponibilidade) == 0){
                printf("O flat %d esta disponivel para venda.\n", i+1);
            }
            i++;
        }
    }else if (strcmp(tipoImovel, stdi) == 0){
        while (i < 30){
            if (strcmp(dispon, studio[i].disponibilidade) == 0){
                printf("O studio %d esta disponivel para venda.\n", i+1);
            }
            i++;
        }
    }
}
void ConsultaImoveisTipoAlugar(){
    char tipoImovel[30], cas[30], apart[30], terr[30], fla[30], stdi[30], dispon[30];
    int s, i = 0;
    strcpy(cas, "casa");
    strcpy(apart, "apartamento");
    strcpy(terr, "terreno");
    strcpy(fla, "flat");
    strcpy(stdi, "studio");
    strcpy(dispon, "Aluguel");
    printf("----------------Procura de imoveis por tipo----------------\n");
    printf("Qual imovel deseja procurar?\n");
    printf("Digite [casa], [apartamento], [terreno], [flat] ou [studio].\n");
    printf("Todas as letras em menusculo e sem [  ].\n");
    fgets(tipoImovel, 30, stdin);
	s = strlen(tipoImovel);
	tipoImovel[s-1] = '\0';

    if (strcmp(tipoImovel, cas) == 0){
        while (i < 30){
            if (strcmp(dispon, casa[i].disponibilidade) == 0){
                printf("A casa %d esta disponivel para aluguel.\n", i+1);
            }
            i++;
        }
    }else if (strcmp(tipoImovel, apart) == 0){
        while (i < 30){
            if (strcmp(dispon, apartamento[i].disponibilidade) == 0){
                printf("O apartamento %d esta disponivel para aluguel.\n", i+1);
            }
            i++;
        }
    }else if (strcmp(tipoImovel, terr) == 0){
        while (i < 30){
            if (strcmp(dispon, terreno[i].disponibilidade) == 0){
                printf("O terreno %d esta disponivel para aluguel.\n", i+1);
            }
            i++;
        }
    }else if (strcmp(tipoImovel, fla) == 0){
        while (i < 30){
            if (strcmp(dispon, flat[i].disponibilidade) == 0){
                printf("O flat %d esta disponivel para aluguel.\n", i+1);
            }
            i++;
        }
    }else if (strcmp(tipoImovel, stdi) == 0){
        while (i < 30){
            if (strcmp(dispon, studio[i].disponibilidade) == 0){
                printf("O studio %d esta disponivel para aluguel.\n", i+1);
            }
            i++;
        }
    }
}
void ConsultaImoveisBairroAlugar(){
    char bair[30], dispon[30];
    int s, i = 0;
    strcpy(dispon, "Aluguel");
    printf("----------------Procura de imoveis por bairro----------------\n");
    printf("Qual bairro deseja procurar?\n");
    printf("Digite as mesmas letras que digitou no cadastro, sejam elas maiusculas e menusculas.\n");
    fgets(bair, 30, stdin);
	s = strlen(bair);
	bair[s-1] = '\0';

    while (i < 30){
        if (strcmp(bair, casa[i].bairro) == 0){
            if (strcmp(dispon, casa[i].disponibilidade) == 0){
                printf("A casa %d esta disponivel para aluguel.\n", i+1);
            }
        }
        if (strcmp(bair, apartamento[i].bairro) == 0){
            if (strcmp(dispon, apartamento[i].disponibilidade) == 0){
                printf("O apartamento %d esta disponivel para aluguel.\n", i+1);
            }
        }
        if (strcmp(bair, flat[i].bairro) == 0){
            if (strcmp(dispon, flat[i].disponibilidade) == 0){
                printf("O apartamento Flat %d esta disponivel para aluguel.\n", i+1);
            }
        }
        if (strcmp(bair, studio[i].bairro) == 0){
            if (strcmp(dispon, studio[i].disponibilidade) == 0){
                printf("O apartamento Studio %d esta disponivel para aluguel.\n", i+1);
            }
        }
        if (strcmp(bair, terreno[i].bairro) == 0){
            if (strcmp(dispon, terreno[i].disponibilidade) == 0){
                printf("O terreno %d esta disponivel para aluguel.\n", i+1);
            }
        }
        i++;
    }
}
void ConsultaImoveisBairroVender(){
    char bair[30], dispon[30];
    int s, i = 0;
    strcpy(dispon, "Venda");
    printf("----------------Procura de imoveis por bairro----------------\n");
    printf("Qual bairro deseja procurar?\n");
    printf("Digite as mesmas letras que digitou no cadastro, sejam elas maiusculas e menusculas.\n");
    fgets(bair, 30, stdin);
	s = strlen(bair);
	bair[s-1] = '\0';

    while (i < 30){
        if (strcmp(bair, casa[i].bairro) == 0){
            if (strcmp(dispon, casa[i].disponibilidade) == 0){
                printf("A casa %d esta disponivel para aluguel.\n", i+1);
            }
        }
        if (strcmp(bair, apartamento[i].bairro) == 0){
            if (strcmp(dispon, apartamento[i].disponibilidade) == 0){
                printf("O apartamento %d esta disponivel para aluguel.\n", i+1);
            }
        }
        if (strcmp(bair, flat[i].bairro) == 0){
            if (strcmp(dispon, flat[i].disponibilidade) == 0){
                printf("O apartamento Flat %d esta disponivel para aluguel.\n", i+1);
            }
        }
        if (strcmp(bair, studio[i].bairro) == 0){
            if (strcmp(dispon, studio[i].disponibilidade) == 0){
                printf("O apartamento Studio %d esta disponivel para aluguel.\n", i+1);
            }
        }
        if (strcmp(bair, terreno[i].bairro) == 0){
            if (strcmp(dispon, terreno[i].disponibilidade) == 0){
                printf("O terreno %d esta disponivel para aluguel.\n", i+1);
            }
        }
        i++;
    }
}
void ConsultaDescricaoCidade(){
char cidad[30];
    int s, i = 0;
    printf("----------------Procura de imoveis por cidade----------------\n");
    printf("Atencao: todas as descricoes dos imoveis localizados na cidade selecionada serao exibidas!\n");
    printf("Qual cidade deseja procurar?\n");
    printf("Digite as mesmas letras que digitou no cadastro, sejam elas maiusculas e menusculas.\n");
    fgets(cidad, 30, stdin);
	s = strlen(cidad);
	cidad[s-1] = '\0';

    while (i < 30){
        if (strcmp(cidad, casa[i].cidade) == 0){
            printf("Casa %d\n", i+1);
            printf("Disponibilidade: %s\n", casa[i].disponibilidade);
            printf("Valor: R$ %.2lf\n", casa[i].valor);
            printf("Logradouro: %s\n", casa[i].logradouro);
            printf("Bairro: %s\n", casa[i].bairro);
            printf("%d pavimentos.\n", casa[i].quantPavimentos);
            printf("%d quartos.\n", casa[i].quantQuartos);
            printf("Area construida: %.2f metros quadrados.\n", casa[i].areaConstruida);
            printf("Area do terreno: %lf\n", casa[i].areaTerreno);
            printf("CEP: %s\n", casa[i].cep);
            printf("Numero: %d\n", casa[i].numero);
        }
        if (strcmp(cidad, apartamento[i].cidade) == 0){
            printf("\nApartamento %d\n", i+1);
            printf("Disponibilidade: %s\n", apartamento[i].disponibilidade);
            printf("Valor: R$ %.2lf\n", apartamento[i].valor);
            printf("Logradouro: %s\n", apartamento[i].logradouro);
            printf("Bairro: %s\n", apartamento[i].bairro);
            printf("%d quartos.\n", apartamento[i].quantQuartos);
            printf("Area: %.2f metros quadrados.\n", apartamento[i].areaApartamento);
            printf("Custo: %lf\n", apartamento[i].valorCondominio);
            printf("%d vagas de garagem.\n", apartamento[i].vagasGaragem);
            printf("Posicao %s\n", apartamento[i].posicao);
            printf("CEP: %s\n", apartamento[i].cep);
            printf("Numero: %d\n", apartamento[i].numero);
        }
        if (strcmp(cidad, flat[i].cidade) == 0){
            printf("\nApartamento Flat %d\n", i+1);
            printf("Disponibilidade: %s\n", flat[i].disponibilidade);
            printf("Valor: R$ %.2lf\n", flat[i].valor);
            printf("Logradouro: %s\n", flat[i].logradouro);
            printf("Bairro: %s\n", flat[i].bairro);
            printf("%d quartos.\n", flat[i].quantQuartos);
            printf("Area: %.2f metros quadrados.\n", flat[i].areaFlat);
            printf("Custo: %lf\n", flat[i].valorCondominio);
            printf("%d vagas de garagem.\n", flat[i].vagasGaragem);
            printf("Posicao %s\n", flat[i].posicao);
            printf("CEP: %s\n", flat[i].cep);
            printf("Cidade: %s\n", flat[i].cidade);
            printf("Numero: %d\n", flat[i].numero);
            if (flat[i].arCondicionado == 1){
                printf("Dispoe de ar-condicionado.\n");
            }else{
                printf("Nao dispoe de ar-condicionado.\n");
            }
            if (flat[i].internet == 1){
                printf("Dispoe de internet.\n");
            }else{
                printf("Nao dispoe de internet.\n");
            }
            if (flat[i].tvCabo == 1){
                printf("Dispoe de TV a cabo.\n");
            }else{
                printf("Nao dispoe de TV a cabo.\n");
            }
            if (flat[i].lavanderia == 1){
                printf("Dispoe de servicos de lavanderia.\n");
            }else{
                printf("Nao dispoe de servicos de lavanderia.\n");
            }
            if (flat[i].arrumacaoLimpeza == 1){
                printf("Dispoe de servicos de arrumacao e limpeza.\n");
            }else{
                printf("Nao dispoe de servicos de arrumacao e limpeza.\n");
            }
            if (flat[i].recepcao24H == 1){
                printf("Dispoe de recepcao 24h.\n");
            }else{
                printf("Nao dispoe de recepcao 24h.\n");
            }
        }
        if (strcmp(cidad, studio[i].cidade) == 0){
            printf("\nApartamento Studio %d\n", i+1);
            printf("Disponibilidade: %s\n", studio[i].disponibilidade);
            printf("Valor: R$ %.2lf\n", studio[i].valor);
            printf("Logradouro: %s\n", studio[i].logradouro);
            printf("Bairro: %s\n", studio[i].bairro);
            printf("%d quartos.\n", studio[i].quantQuartos);
            printf("Area: %.2f metros quadrados.\n", studio[i].areaStudio);
            printf("Custo: %lf\n", studio[i].valorCondominio);
            printf("%d vagas de garagem.\n", studio[i].vagasGaragem);
            printf("Posicao %s\n", studio[i].posicao);
            printf("CEP: %s\n", studio[i].cep);
            printf("Cidade: %s\n", studio[i].cidade);
            printf("Numero: %d\n", studio[i].numero);
            if (studio[i].arCondicionado == 1){
                printf("Dispoe de ar-condicionado.\n");
            }else{
                printf("Nao dispoe de ar-condicionado.\n");
            }
            if (studio[i].internet == 1){
                printf("Dispoe de internet.\n");
            }else{
                printf("Nao dispoe de internet.\n");
            }
            if (studio[i].tvCabo == 1){
                printf("Dispoe de TV a cabo.\n");
            }else{
                printf("Nao dispoe de TV a cabo.\n");
            }
            if (studio[i].lavanderia == 1){
                printf("Dispoe de servicos de lavanderia.\n");
            }else{
                printf("Nao dispoe de servicos de lavanderia.\n");
            }
            if (studio[i].arrumacaoLimpeza == 1){
                printf("Dispoe de servicos de arrumacao e limpeza.\n");
            }else{
                printf("Nao dispoe de servicos de arrumacao e limpeza.\n");
            }
            if (studio[i].recepcao24H == 1){
                printf("Dispoe de recepcao 24h.\n");
            }else{
                printf("Nao dispoe de recepcao 24h.\n");
            }
            if (studio[i].piscina == 1){
                printf("Dispoe de piscina.\n");
            }else{
                printf("Nao dispoe de piscina.\n");
            }
            if (studio[i].sauna == 1){
                printf("Dispoe de sauna.\n");
            }else{
                printf("Nao dispoe de sauna.\n");
            }
            if (studio[i].salaGinastica == 1){
                printf("Dispoe de sala de ginastica.\n");
            }else{
                printf("Nao dispoe de sala de ginastica.\n");
            }
        }
        if (strcmp(cidad, terreno[i].cidade) == 0){
            printf("\nTerreno %d\n", i+1);
            printf("Disponibilidade: %s\n", terreno[i].disponibilidade);
            printf("Valor: R$ %.2lf\n", terreno[i].valor);
            printf("Logradouro: %s\n", terreno[i].logradouro);
            printf("Bairro: %s\n", terreno[i].bairro);
            printf("Area do terreno: %lf\n", terreno[i].areaTerreno);
            printf("CEP: %s\n", terreno[i].cep);
            printf("Cidade: %s\n", terreno[i].cidade);
            printf("Numero : %d\n\n", terreno[i].numero);
        }
        i++;
    }
}
int main(void){
    Menu();
}

#ifndef INDUSTRIA_H
#define INDUSTRIA_H

typedef struct {
    char nome[100];
    char cnpj[20];
    char razao_social[100];
    char endereco[200];
    char telefone[15];
    char email[50];
    char data_abertura[10];
    char responsavel[100];
    double residuos_tratados;
    double custo_estimado;
} Industria;

void cadastrarIndustria(Industria *industrias, int *numIndustrias);
void atualizarDados(Industria *industrias, int numIndustrias);
void carregarIndustrias(Industria *industrias, int *numIndustrias);
void salvarIndustrias(Industria *industrias, int numIndustrias);

#endif // INDUSTRIA_H

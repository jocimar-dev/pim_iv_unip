#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/industria.h"

void cadastrarIndustria(Industria *industrias, int *numIndustrias) {
    Industria industria;

    printf("Digite o nome da empresa: ");
    fgets(industria.nome, sizeof(industria.nome), stdin);
    printf("Digite o CNPJ: ");
    fgets(industria.cnpj, sizeof(industria.cnpj), stdin);
    printf("Digite a razao social: ");
    fgets(industria.razao_social, sizeof(industria.razao_social), stdin);
    printf("Digite o endereco: ");
    fgets(industria.endereco, sizeof(industria.endereco), stdin);
    printf("Digite o telefone: ");
    fgets(industria.telefone, sizeof(industria.telefone), stdin);
    printf("Digite o email: ");
    fgets(industria.email, sizeof(industria.email), stdin);
    printf("Digite a data de abertura: ");
    fgets(industria.data_abertura, sizeof(industria.data_abertura), stdin);
    printf("Digite o nome do responsavel: ");
    fgets(industria.responsavel, sizeof(industria.responsavel), stdin);

    industria.residuos_tratados = 0;
    industria.custo_estimado = 0;

    industrias[*numIndustrias] = industria;
    (*numIndustrias)++;

    printf("Cadastro realizado com sucesso!\n");
}

void atualizarDados(Industria *industrias, int numIndustrias) {
    char nome[100];
    printf("Digite o nome da empresa para atualizar: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = 0; // Remover o \n no final

    for (int i = 0; i < numIndustrias; i++) {
        if (strcmp(industrias[i].nome, nome) == 0) {
            printf("Digite a quantidade de residuos tratados: ");
            scanf("%lf", &industrias[i].residuos_tratados);
            printf("Digite o valor estimado de custo: ");
            scanf("%lf", &industrias[i].custo_estimado);
            getchar(); // Limpar o buffer do stdin
            printf("Dados atualizados com sucesso!\n");
            return;
        }
    }

    printf("Industria nao encontrada.\n");
}

void salvarIndustrias(Industria *industrias, int numIndustrias) {
    FILE *arquivo = fopen("data/industrias.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    for (int i = 0; i < numIndustrias; i++) {
        fprintf(arquivo, "%s;%s;%s;%s;%s;%s;%s;%s;%.2f;%.2f\n",
                industrias[i].nome, industrias[i].cnpj, industrias[i].razao_social,
                industrias[i].endereco, industrias[i].telefone, industrias[i].email,
                industrias[i].data_abertura, industrias[i].responsavel,
                industrias[i].residuos_tratados, industrias[i].custo_estimado);
    }

    fclose(arquivo);
}

void carregarIndustrias(Industria *industrias, int *numIndustrias) {
    FILE *arquivo = fopen("data/industrias.txt", "r");

    if (arquivo == NULL) {
        printf("Arquivo de industrias nao encontrado.\n");
        return;
    }

    Industria industria;
    while (fscanf(arquivo, "%99[^;];%19[^;];%99[^;];%199[^;];%14[^;];%49[^;];%9[^;];%99[^;];%lf;%lf\n",
                  industria.nome, industria.cnpj, industria.razao_social, industria.endereco,
                  industria.telefone, industria.email, industria.data_abertura,
                  industria.responsavel, &industria.residuos_tratados, &industria.custo_estimado) != EOF) {
        industrias[*numIndustrias] = industria;
        (*numIndustrias)++;
    }

    fclose(arquivo);
}

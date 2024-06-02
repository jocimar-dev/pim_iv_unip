#include <stdio.h>
#include "../include/industria.h"

void gerarRelatorio(Industria *industrias, int numIndustrias) {
    FILE *arquivo = fopen("data/relatorio.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de relatorio!\n");
        return;
    }

    for (int i = 0; i < numIndustrias; i++) {
        fprintf(arquivo, "Nome: %s\nCNPJ: %s\nRazao Social: %s\nEndereco: %s\nTelefone: %s\nEmail: %s\nData de Abertura: %s\nResponsavel: %s\nResiduos Tratados: %.2f\nCusto Estimado: %.2f\n\n",
                industrias[i].nome, industrias[i].cnpj, industrias[i].razao_social,
                industrias[i].endereco, industrias[i].telefone, industrias[i].email,
                industrias[i].data_abertura, industrias[i].responsavel,
                industrias[i].residuos_tratados, industrias[i].custo_estimado);
    }

    fclose(arquivo);
    printf("Relatorio gerado com sucesso!\n");
}

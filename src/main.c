#include <stdio.h>
#include <stdlib.h>
#include "../include/usuario.h"
#include "../include/industria.h"
#include "../include/relatorio.h"

#define MAX_USUARIOS 10
#define MAX_INDUSTRIAS 100

int main() {
    Usuario usuarios[MAX_USUARIOS] = {{"admin", "1234"}, {"Jocimar", "123"}};
    Industria industrias[MAX_INDUSTRIAS];
    int numUsuarios = 2; // Atualize o número de usuários
    int numIndustrias = 0;

    carregarIndustrias(industrias, &numIndustrias);

    if (!login(usuarios, numUsuarios)) {
        return 1;
    }

    int opcao;
    do {
        printf("\n1. Cadastrar Industria\n2. Atualizar Dados\n3. Gerar Relatorio\n4. Sair\nEscolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpar o buffer do stdin

        switch (opcao) {
            case 1:
                cadastrarIndustria(industrias, &numIndustrias);
                salvarIndustrias(industrias, numIndustrias);
                break;
            case 2:
                atualizarDados(industrias, numIndustrias);
                salvarIndustrias(industrias, numIndustrias);
                break;
            case 3:
                gerarRelatorio(industrias, numIndustrias);
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    } while (opcao != 4);

    return 0;
}

#include <stdio.h>
#include <string.h>
#include "../include/industria.h"

// Função de teste para cadastrarIndústria
void test_cadastrarIndustria() {
    Industria industrias[10];
    int numIndustrias = 0;

    // Redirecionar entrada padrão para o arquivo de teste
    FILE *input = freopen("test_input_industria.txt", "r", stdin);

    if (input == NULL) {
        printf("Erro ao abrir o arquivo de teste.\n");
        return;
    }

    cadastrarIndustria(industrias, &numIndustrias);

    // Verificar se a indústria foi cadastrada corretamente
    if (numIndustrias == 1 &&
        strcmp(industrias[0].nome, "Empresa Teste") == 0 &&
        strcmp(industrias[0].cnpj, "12345678901234") == 0 &&
        strcmp(industrias[0].razao_social, "Razao Social Teste") == 0 &&
        strcmp(industrias[0].endereco, "Endereco Teste, 123") == 0 &&
        strcmp(industrias[0].telefone, "123456789") == 0 &&
        strcmp(industrias[0].email, "email@teste.com") == 0 &&
        strcmp(industrias[0].data_abertura, "01/01/2024") == 0 &&
        strcmp(industrias[0].responsavel, "Responsavel Teste") == 0) {
        printf("Teste cadastrarIndustria: PASSOU\n");
    } else {
        printf("Teste cadastrarIndustria: FALHOU\n");
    }

    // Fechar o arquivo de teste e restaurar stdin
    fclose(input);
    freopen("/dev/tty", "r", stdin); // Para sistemas Unix/Linux
    // Para sistemas Windows, use:
    // freopen("CON", "r", stdin);
}

int main() {
    test_cadastrarIndustria();
    return 0;
}

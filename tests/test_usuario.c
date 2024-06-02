#include <stdio.h>
#include <string.h>
#include "../include/usuario.h"

// Função de teste para login
void test_login() {
    Usuario usuarios[2] = {{"admin", "1234"}, {"Jocimar", "123"}};

    // Redirecionar entrada padrão para o arquivo de teste
    FILE *input = freopen("test_input_usuario.txt", "r", stdin);

    if (input == NULL) {
        printf("Erro ao abrir o arquivo de teste.\n");
        return;
    }

    int result = login(usuarios, 2);

    // Verificar se o login foi bem-sucedido
    if (result == 1) {
        printf("Teste login: PASSOU\n");
    } else {
        printf("Teste login: FALHOU\n");
    }

    // Fechar o arquivo de teste e restaurar stdin
    fclose(input);
    freopen("/dev/tty", "r", stdin); // Para sistemas Unix/Linux
    // Para sistemas Windows, use:
    // freopen("CON", "r", stdin);
}

int main() {
    test_login();
    return 0;
}

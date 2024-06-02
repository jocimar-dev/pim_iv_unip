#include <stdio.h>
#include <string.h>
#include "../include/usuario.h"

int login(Usuario *usuarios, int numUsuarios) {
    char nome[50];
    char senha[20];

    printf("Nome de usuario: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = 0; // Remover o \n no final

    printf("Senha: ");
    fgets(senha, sizeof(senha), stdin);
    senha[strcspn(senha, "\n")] = 0; // Remover o \n no final

    for (int i = 0; i < numUsuarios; i++) {
        if (strcmp(usuarios[i].nome, nome) == 0 && strcmp(usuarios[i].senha, senha) == 0) {
            return 1; // Sucesso no login
        }
    }

    printf("Usuario ou senha incorretos.\n");
    return 0; // Falha no login
}

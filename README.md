# Projeto pim_4: Sistema de Cadastro e Gestão de Indústrias

Este projeto implementa um sistema de cadastro e gestão de indústrias utilizando a linguagem de programação C.

## Estrutura do Projeto

- `src/`: Código-fonte principal.
- `include/`: Arquivos de cabeçalho.
- `tests/`: Código-fonte dos testes.
- `doc/`: Documentação adicional.
- `bin/`: Diretório onde os binários compilados serão gerados.
- `CMakeLists.txt`: Arquivo de configuração do CMake.
- `README.md`: Este arquivo.
- `test_input_usuario.txt`, `test_input_industria.txt`: Arquivos de entrada de teste.

## Como Compilar

### Usando CMake

1. Crie um diretório de build:
   ```sh
   mkdir build
   cd build
   ```

2. Execute o CMake:

    ```sh
    cmake ..
    ```
3. Compile o projeto:

    ```sh
    cmake --build .
    ```
### Usando Make

1. Compile o projeto:

    ```sh
    mingw32-make all
    ```

## Executando os Testes
1. Compile os testes e execute-os:
   ```sh
   mingw32-make test
   ```


## Dependências
   * GCC

Certifique-se de que todas as dependências estão instaladas corretamente antes de compilar e executar o projeto.

## Licença

Este projeto está licenciado sob os termos da licença MIT. Veja o arquivo [LICENSE](LICENSE.md) para mais detalhes.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char ** regras;
    int num_regras;
    char* raiz;
} Gramatica;

int classificaNaoTerminal(char c){
    return(c >= 'A' && c <= 'Z');
}

int classificaTerminal(char c){
    return(c >= 'a' && c <= 'z');
}

//Funcao para verificar o lado esquerdo
int valida_ladoEsq(char* str){
    int nao_terminal = 0;

    if(str[0] == '\0') {
        printf("\nErro: Lado esquerdo vazio!");
        return 0;
    }

    for(int i = 0; str[i] != '\0'; i++) {
        if(!classificaNaoTerminal(str[i])) { //se o caractere nao for um nao-terminal
            if(!classificaTerminal(str[i])) {  //se o caractere nao for um terminal
                printf("\nErro: Caractere invalido %c encontrado na cadeia!", str[i]);
                return 0;//encerra a funcao, caractere invalido
            }
        } else {
            nao_terminal = 1;
        }
    }
    return nao_terminal; //deve ter pelo menos um nao terminal
}

//Funcao para verificar o lado direito
int valida_ladoDir(char *str){
    for(int i = 0; str[i] != '\0'; i++) {
        if(!classificaNaoTerminal(str[i])) {
            if(!classificaTerminal(str[i])) {
                return 0; // Caractere invalido
            }
        }
    }
    return 1;
}

char* encontraRaiz(char* string) {
    for (int i = 0; string[i] != '\0'; i++) {
        if (classificaNaoTerminal(string[i])) {
            char* simbolo = malloc(2 * sizeof(char));
            simbolo[0] = string[i];
            simbolo[1] = '\0';
        }
    }
    return NULL;
}

Gramatica* valida_gramatica(char* gramatica_str) {
    Gramatica* gramatica = malloc(sizeof(Gramatica));
    gramatica->regras = NULL;
    gramatica->num_regras = 0;
    gramatica->raiz = NULL;

    // Verifica se termina com $
    if (gramatica_str[strlen(gramatica_str) - 1] != '$') {
        fprintf(stderr, "Erro: A gramatica deve terminar com $\n");
        return gramatica;
    }

    // Remove o $ final
    char* copia = strdup(gramatica_str);
    copia[strlen(copia) - 1] = '\0';

    // Divide as regras pelo separador -
    char* token = strtok(copia, "-");
    while (token != NULL) {
        // Remove espacos em branco
        while (*token == ' ') token++;
        int len = strlen(token);
        while (len > 0 && token[len-1] == ' ') {
            token[--len] = '\0';
        }

        // Divide cada regra em lado esquerdo e direito
        char* seta = strstr(token, ">");
        if (seta == NULL) {
            fprintf(stderr, "Erro: Regra sem '>': %s\n", token);
            free(copia);
            return gramatica;
        }

        // Separa os lados
        *seta = '\0';
        char* lado_esquerdo = token;
        char* lado_direito = seta + 1;

        // Remove espacos
        while (*lado_direito == ' ') lado_direito++;

        // Valida os lados
        if (!valida_ladoEsq(lado_esquerdo)) {
            fprintf(stderr, "Erro: Lado esquerdo invalido: %s\n", lado_esquerdo);
            free(copia);
            return gramatica;
        }

        if (!valida_ladoDir(lado_direito)) {
            fprintf(stderr, "Erro: Lado direito invalido: %s\n", lado_direito);
            free(copia);
            return gramatica;
        }

        // Adiciona a regra a lista
        gramatica->num_regras++;
        gramatica->regras = realloc(gramatica->regras, gramatica->num_regras * sizeof(char*));
        gramatica->regras[gramatica->num_regras - 1] = malloc(strlen(lado_esquerdo) + strlen(lado_direito) + 2);
        sprintf(gramatica->regras[gramatica->num_regras - 1], "%s>%s", lado_esquerdo, lado_direito);

        token = strtok(NULL, "-");
    }

    gramatica->raiz = encontraRaiz(gramatica_str);

    free(copia);
    return gramatica;
}

//liberar memoria
void libera_gramatica(Gramatica* gramatica) {
    if (gramatica == NULL) return;

    for (int i = 0; i < gramatica->num_regras; i++) {
        free(gramatica->regras[i]);
    }
    free(gramatica->regras);
    free(gramatica->raiz);
    free(gramatica);
}


int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Uso: %s <arquivo_gramatica>\n", argv[0]);
        return 1;
    }

    FILE* arquivo = fopen(argv[1], "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir arquivo");
        return 1;
    }

    char linha[MAX_LINE_LENGTH];
    if (fgets(linha, sizeof(linha), arquivo) == NULL) {
        fprintf(stderr, "Erro ao ler arquivo ou arquivo vazio\n");
        fclose(arquivo);
        return 1;
    }

    fclose(arquivo);

    // Remove nova linha se existir
    linha[strcspn(linha, "\n")] = '\0';

    printf("Validando gramatica: %s\n", linha);

    Gramatica* gramatica = valida_gramatica(linha);

    if (gramatica->num_regras > 0) {
        printf("Gramatica valida!\n");
        printf("Raiz: %s\n", gramatica->raiz);
        printf("Regras:\n");
        for (int i = 0; i < gramatica->num_regras; i++) {
            printf("  %s\n", gramatica->regras[i]);
        }
    } else {
        printf("Gramatica invalida!\n");
    }

    printf("\n\n\n");
    system("pause");
    libera_gramatica(gramatica);
    return 0;
}

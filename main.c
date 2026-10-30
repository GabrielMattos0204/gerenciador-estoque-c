#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome[50];
    int quantidade;
    float preco;
} Produto;

void lerLinha(char *destino, int tamanho) {
    if (fgets(destino, tamanho, stdin) == NULL) {
        destino[0] = '\0';
        return;
    }
    destino[strcspn(destino, "\n")] = '\0';
}

int lerInteiro(const char *rotulo) {
    char linha[64];
    int valor;
    while (1) {
        printf("%s", rotulo);
        lerLinha(linha, sizeof(linha));
        if (sscanf(linha, "%d", &valor) == 1) {
            return valor;
        }
        printf("Valor invalido. Tente novamente.\n");
    }
}

float lerFloat(const char *rotulo) {
    char linha[64];
    float valor;
    while (1) {
        printf("%s", rotulo);
        lerLinha(linha, sizeof(linha));
        for (char *c = linha; *c != '\0'; c++) {
            if (*c == ',') *c = '.';
        }
        if (sscanf(linha, "%f", &valor) == 1) {
            return valor;
        }
        printf("Valor invalido. Tente novamente.\n");
    }
}

void adicionarProduto() {
    FILE *arquivo = fopen("estoque.dat", "ab");
    if (arquivo == NULL) {
        printf("\nErro ao abrir oarquivo de estoque!\n");
        return;
    }

    Produto p;
    printf("\n=== Cadastrar novo produto ===\n");
    p.id = lerInteiro("ID: ");
    printf("Nome: ");
    lerLinha(p.nome, sizeof(p.nome));
    p.quantidade = lerInteiro("Quantidade: ");
    p.preco = lerFloat("Preco(R$): ");

    fwrite(&p, sizeof(Produto), 1, arquivo);
    fclose(arquivo);

    printf("\nProduto cadastrado com sucesso!\n");
    
}

void listarProdutos() {
    FILE *arquivo = fopen("estoque.dat", "rb");
    if (arquivo == NULL) {
        printf("\nNemhum produto cadastrado ainda ou erro ao abrir arquivo.\n");
        return;
    }
Produto p;
    printf("\n--- LISTA DE ESTOQUE ---\n");
    printf("%-5s %-30s %-12s %-10s\n", "ID", "Nome", "Quantidade", "Preco");
    printf("------------------------------------------------------------\n");

    while (fread(&p, sizeof(Produto), 1, arquivo)) {
        printf("%-5d %-30s %-12d R$ %-8.2f\n", p.id, p.nome, p.quantidade, p.preco);
    }

    fclose(arquivo);
}

void buscarProduto() {
    FILE *arquivo = fopen("estoque.dat", "rb");
    if (arquivo == NULL) {
        printf("\nNenhum produto cadastrado ainda ou erro ao abrir arquivo.\n");
        return;
    }

    int idBusca;
    printf("\n=== Buscar produto por ID ===\n");
    idBusca = lerInteiro("ID: ");

    Produto p;
    int encontrado = 0;

    while (fread(&p, sizeof(Produto), 1, arquivo)) {
        if (p.id == idBusca) {
            encontrado = 1;
            printf("\n--- PRODUTO ENCONTRADO ---\n");
            printf("ID.........: %d\n", p.id);
            printf("Nome.......: %s\n", p.nome);
            printf("Quantidade.: %d\n", p.quantidade);
            printf("Preco......: R$ %.2f\n", p.preco);
            printf("Valor total: R$ %.2f\n", p.quantidade * p.preco);
            break;
        }
    }

    fclose(arquivo);

    if (!encontrado) {
        printf("\nNenhum produto com o ID %d foi encontrado.\n", idBusca);
    }
}

void exibirMenu() {
    printf("\n=== GERENCIADOR DE ESTOQUE EM C ===\n");
    printf("ESCOLHA UMA DAS OPCOES A SEGUIR:\n");
    printf("\n1. ADICIONAR PRODUTO\n");
    printf("\n2. LISTAR PRODUTOS\n");
    printf("\n3. BUSCAR PRODUTO POR ID\n");
    printf("\n0. SAIR\n");
    
}

int main ()  {
    int opcao = -1;
    
    while (opcao != 0) {
        exibirMenu();
        opcao = lerInteiro("Opcao: "); 

        switch (opcao) {

            case 1: 
                adicionarProduto();
                break;
            case 2:
                listarProdutos();
                break;
            case 3:
                buscarProduto();
                break;
            case 0: 
                printf("\nSAINDO DO SISTEMA..\n");
                break;
            default: 
                printf("\nOPCAO INVALIDA, POR FAVOR SELECIONE UMA DAS OPCOES DO MENU\n");
        }
    }
    return 0; 
}
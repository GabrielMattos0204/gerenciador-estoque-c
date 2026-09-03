#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome[50];
    int quantidade;
    float preco;
} Produto;

void adicionarProduto() {
    FILE *arquivo = fopen("estoque.dat", "ab");
    if (arquivo == NULL) {
        printf("\nErro ao abrir oarquivo de estoque!\n");
        return;
    }

    Produto p;
    printf("\n=== Cadastrar novo produto ===\n");
    printf("ID: ");
    scanf("%d", &p.id);
    getchar(); //Limpa o buffer do teclado

    printf("Nome: ");
    fgets(p.nome, sizeof(p.nome), stdin);
    p.nome[strcspn(p.nome, "\n")] = 0; //Remove a quebra de linha

    printf("Quantidade: ");
    scanf("%d", &p.quantidade);

    printf("Preço(R$): ");
    scanf("%f", &p.preco);

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

void exibirMenu() {
    printf("\n=== GERENCIADOR DE ESTOQUE EM C ===\n");
    printf("ESCOLHA UMA DAS OPCOES A SEGUIR:\n");
    printf("\n1. ADICIONAR PRODUTO\n");
    printf("\n2. LISTAR PRODUTOS\n");
    printf("\n0. SAIR\n");
    
}

int main ()  {
    int opcao = -1;
    
    while (opcao != 0) {
        exibirMenu();
        scanf("%d", &opcao); 

        switch (opcao) {

            case 1: 
                adicionarProduto();
                break;
            case 2:
                listarProdutos();
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
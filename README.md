# Gerenciador de Estoque em C

Sistema de linha de comando (CLI) em C para controle de inventário de produtos, com persistência em arquivo binário. Projeto de estudo do curso de Análise e Desenvolvimento de Sistemas (ADS).

## Sobre o projeto

O programa permite cadastrar, listar e consultar produtos de um estoque. Cada produto tem ID, nome, quantidade e preço. Os dados ficam gravados em `estoque.dat` em formato binário, portanto persistem entre execuções.

O objetivo é praticar, em C: structs, ponteiros, manipulação de arquivos, strings e leitura robusta de entrada.

## Funcionalidades

- [x] Cadastrar produto
- [x] Listar estoque em tabela
- [x] Buscar produto por ID, exibindo o valor total em estoque
- [x] Persistência em arquivo binário
- [x] Tratamento de buffer e separador decimal

## Estrutura

`main.c` concentra o código: o tipo `Produto`, os auxiliares de leitura (`lerLinha`, `lerInteiro`, `lerFloat`), as funções de domínio (`adicionarProduto`, `listarProdutos`, `buscarProduto`) e o menu principal.

`estoque.dat` guarda os registros como structs binárias. A leitura é sequencial com `fread`.

## Como executar

Pré-requisito: gcc ou MinGW instalado.

```
gcc -Wall -o estoque main.c
./estoque
```

## Decisões de implementação

A entrada de texto não usa `scanf`. Cada campo lê a linha inteira com `fgets` e converte depois com `sscanf`. Isso evita que sobras no buffer desalinhem o menu — problema presente na versão anterior, em que o `getchar()` limpava apenas um caractere.

O preço aceita vírgula ou ponto, convertendo a vírgula para ponto antes da conversão numérica.

## Roadmap

- [x] Buscar produto por ID
- [ ] Atualizar quantidade e preço
- [ ] Excluir produto
- [ ] Impedir cadastro com ID duplicado
- [ ] Modularizar em múltiplos arquivos (.h e .c)

## Sobre mim

Gabriel Mattos, estudante de ADS em Limeira, SP. Buscando a primeira oportunidade de estágio em TI.

Contato: gabrielmattos99201@gmail.com
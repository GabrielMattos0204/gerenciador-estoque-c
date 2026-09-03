📦 Gerenciador de Estoque em C
Um sistema em linha de comando (CLI) desenvolvido em Linguagem C para gerenciamento simples e eficiente de inventário de produtos. O projeto utiliza persistência de dados em arquivos binários (.dat), manipulação de ponteiros, alocação de memória e estruturas de dados.

Projetado como parte do meu aprendizado prático no curso de Análise e Desenvolvimento de Sistemas (ADS).

🚀 Funcionalidades
[x] Cadastrar Produto: Insere novos produtos gravando diretamente em arquivo binário (.dat).

[x] Listar Estoque: Exibe a lista completa de itens formatada em colunas (ID, Nome, Quantidade e Preço).

[x] Persistência de Dados: Os dados salvos permanecem armazenados mesmo após fechar o programa.

[x] Tratamento de Buffer: Limpeza de entrada de teclado (stdin) para leitura segura de strings.

🛠️ Tecnologias Utilizadas
Linguagem C (C99)

Manipulação de Arquivos (stdio.h): fopen, fread, fwrite, fclose

Manipulação de Strings (string.h): strcspn

Git & GitHub para controle de versão

💻 Como Executar o Projeto
Pré-requisitos
Ter um compilador C instalado no seu sistema (ex: gcc ou MinGW).

Passo a passo
Clone o repositório:

Bash
git clone [https://github.com/GabrielMattos0204/gerenciador-estoque-c]
Acesse a pasta do projeto:

Bash
cd gerenciador-estoque-c
Compile o código fonte:

Bash
gcc -o estoque main.c
Execute o programa:

Linux / macOS:

Bash
./estoque
Windows:

DOS
estoque.exe

📈 Próximos Passos (Roadmap)
[ ] Adicionar funcionalidade de Buscar Produto por ID

[ ] Implementar Atualização de quantidade/preço de itens existentes

[ ] Implementar Exclusão de produtos do estoque

[ ] Refatorar o código aplicando conceitos de modularização em múltiplos arquivos (.h e .c)

👨‍💻 Sobre Mim
Olá meu nome é Gabriel! Sou estudante do 3º semestre de Análise e Desenvolvimento de Sistemas (ADS), apaixonado por lógica de programação e linguagem C e Java. Busco minha primeira oportunidade como Estagiário de TI / Desenvolvimento.

E-mail: gabrielmattos99201@gmail.com

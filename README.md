# 🧠 Reconhecedor de Gramáticas 📘

Este projeto representa a primeira atividade desenvolvida no âmbito da disciplina de **Linguagens Formais e Autômatos (GRULFAT)**.

## 👥 Integrantes do Grupo
- Carolina Yumi Siroma (GU3042049)  
- Diogo Da Silva Almeida (GU3059995)  
- Celine Galdino da Silva (GU3046354)

---

## 📄 Descrição do Projeto

O objetivo é criar um programa em linguagem C capaz de ler e validar gramáticas formais descritas em um arquivo de texto, verificando se a cadeia de entrada segue corretamente as regras especificadas.

A gramática deve ser representada como uma cadeia de regras separadas por hífens (`-`) e finalizada com o símbolo `$`, utilizando os seguintes caracteres:

- **Não terminais**: Letras maiúsculas (e.g., `A`, `B`, `S`).  
- **Terminais**: Letras minúsculas (e.g., `a`, `b`, `c`).  

A gramática segue o formato `LadoEsquerdo>LadoDireito`, onde:  
- O **lado esquerdo** deve conter pelo menos um símbolo não terminal.  
- O **lado direito** pode conter terminais, não terminais ou ser vazio.

**Exemplo de saída esperada** ao validar uma gramática:  
```
Validando gramatica: S>aSa-S>bSb-S>c-S>$
Gramatica valida!
Raiz: S
Regras:
  S>aSa
  S>bSb
  S>c
  S>
```
---

## 🧰 Bibliotecas Utilizadas
O programa foi implementado em C utilizando as seguintes bibliotecas:  

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
```

Essas bibliotecas são usadas para leitura de arquivos, manipulação de strings e validação de caracteres da gramática.

---

## 🛠️ Configuração do Projeto

### 🖥️ 1. Instalação do GCC no Windows (via MinGW)
Se você utiliza Windows e ainda não possui o compilador GCC, siga os passos para instalar o MinGW:

1. Baixe o instalador do MinGW:  
   [https://sourceforge.net/projects/mingw/](https://sourceforge.net/projects/mingw/)  
2. Execute o `mingw-get-setup.exe` e siga as opções padrão no assistente de instalação.  
3. No *MinGW Installation Manager*, selecione:  
   - `mingw32-base`  
   - `mingw32-gcc-g++`  
4. Clique com o botão direito nas opções marcadas, selecione *Mark for Installation*, e vá em *Installation > Apply Changes*.  
5. Aguarde o download e a instalação.  

**Adicionar o MinGW ao PATH do sistema:**  
1. Pressione `Win + R`, digite `sysdm.cpl` e pressione *Enter*.  
2. Na aba *Avançado*, clique em *Variáveis de Ambiente*.  
3. Em *Variáveis do sistema*, selecione `Path` e clique em *Editar*.  
4. Adicione o caminho: `C:\MinGW\bin`.  
5. Clique em *OK* em todas as janelas.  
6. Verifique a instalação no Prompt de Comando:  
   ```bash
   gcc --version
   ```

### 🐧 2. Instalação no Linux (Ubuntu/Debian)
No Linux, a instalação do GCC é mais simples. Execute no terminal:  

```bash
sudo apt update
sudo apt install build-essential
```

Isso instalará o `gcc`, `g++`, `make` e outras ferramentas essenciais.  

**Verifique a instalação:**  
```bash
gcc --version
```

### ⚙️ 3. Compilação e Execução do Programa
Para executar o programa, siga os passos abaixo:  

1. Abra o Prompt de Comando ou Terminal e navegue até o diretório onde está o arquivo `reconhecedorGramaticas.c`. Exemplo:  
   ```bash
   cd C:\Users\SOLUTION\Desktop\teste
   ```

2. Compile o programa com o GCC:  
   ```bash
   gcc -o reconhecedor.exe reconhecedorGramaticas.c
   ```

   Isso gerará o arquivo executável `reconhecedor.exe`.  

3. Execute o programa, passando o arquivo de gramática como argumento:  
   ```bash
   reconhecedor.exe gramatica.txt
   ```

   Onde `gramatica.txt` é o arquivo de texto contendo a gramática a ser validada.

**Resumo dos comandos:**  
```bash
cd C:\diretório\onde\está\o\arquivo.c
gcc -o reconhecedor.exe reconhecedorGramaticas.c
reconhecedor.exe gramatica.txt
```

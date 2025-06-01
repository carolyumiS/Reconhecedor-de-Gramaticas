<h1 align="center">🧠 Reconhecedor de Gramáticas 📘</h1>

## 📄 Descrição do Projeto
<p align="justify">
 Este código foi desenvolvido para o primeiro projeto da disciplina de Linguagens Formais e Autômatos (GRULFAT), e tem como finalidade desenvolver um programa, em linguagem C, 
capaz de ler e validar gramáticas formais descritas em um arquivo de texto. 
Ele reconhece se a cadeia de entrada segue corretamente as regras e 
as valida.

--------------------------------------------------------------------------

A gramática deve ser representada como uma cadeia formada por regras separadas por hífens e finalizada com o símbolo "$", utilizando os caracteres especificados:

- Não terminais: letras maiúsculas

- Terminais: letras minúsculas

A gramática segue o formato LadoEsquerdo>LadoDireito, onde:

- O lado esquerdo deve conter pelo menos um símbolo não terminal

- O lado direito pode conter terminais, não terminais ou ser vazio

--------------------------------------------------------------------------

## 🧰 Bibliotecas Utilizadas
O código C foi implementado utilizando as seguintes bibliotecas da linguagem C:

>#include <stdio.h> <br>
>#include <stdlib.h> <br>
>#include <string.h> <br>
>#include <ctype.h>

Essas bibliotecas foram usadas para realizar a leitura de arquivos, manipulação de strings e validação dos caracteres da gramática.


--------------------------------------------------------------------------

##  🛠️ Configuração do Projeto

### 🖥️ 1. Instale o GCC no Windows (via MinGW)
Se você ainda não possui o compilador GCC instalado no seu sistema Windows, será necessário instalá-lo. Recomendamos usar o MinGW:

🔽 Passos para instalar o MinGW:
1. Baixe o instalador do MinGW:
> https://sourceforge.net/projects/mingw/

2. Execute o instalador `mingw-get-setup.exe`
3. No assistente de instalação, deixe todas as opções padrão e avance
4. Na janela do *MinGW Installation Manager*, marque as opções:
   - `mingw32-base`
   - `mingw32-gcc-g++`

5. Clique com o botão direito sobre as opções marcadas e selecione "*Mark for Installation*", depois vá em Installation > *Apply Changes*
6. Aguarde o download e a instalação
<br>
➕ Adicione o MinGW ao PATH do sistema:

1. Pressione `Win + R`, digite `sysdm.cpl` e pressione *Enter*

2. Vá até a aba "*Avançado*" e clique em "*Variáveis de Ambiente*"

3. Em "*Variáveis do sistema*", selecione `Path` e clique em *Editar*

4. Clique em "Novo" e adicione o caminho: ` C:\MinGW\bin`

5. Clique em OK em todas as janelas

6. Para testar se está funcionando, abra o Prompt de Comando e digite:
   > gcc --version

<br> 

### 🐧 2. Instalação no Linux (Ubuntu/Debian)
Se você utiliza *Linux*, o processo é mais direto. Basta instalar o compilador GCC com o gerenciador de pacotes do sistema.

📦 Instalando o GCC no terminal:
> sudo apt update
> sudo apt install build-essential

Isso instalará o `gcc`, `g++`, `make` e outras ferramentas essenciais para desenvolvimento em C/C++.

✅ Verifique a instalação com:
> gcc --version

<br> 

### ⚙️ 3. Compilação e Execução do Programa

Para fazer a execução do programa, deve-se, primeiramente, abrir o prompt de comando, onde será 
feito o uso do compilador GCC. É importante, antes, mudar o diretório para a 
pasta onde está contido o arquivo baixado. Por exemplo:

> cd C:\Users\SOLUTION\Desktop\teste

No caso acima, o reconhecedorGramaticas.c está na pasta "teste".

Em seguida, para compilar, o seguinte comando deverá ser executado:

> gcc -o reconhecedor.exe reconhecedorGramaticas.c

Esse comando cria o arquivo executável reconhecedor.exe. Depois disso,
pra rodar o programa, digita-se:

> reconhecedor.exe gramatica.txt

Sendo "gramatica.txt" o arquivo a ser lido e avaliado pelo programa.

O resultado deverá ser parecido com isso:

Validando gramatica: S>aSa-S>bSb-S>c-S>$
Gramatica valida!
Raiz: S
Regras:
  S>aSa
  S>bSb
  S>c
  S>
 
--------------------------------------------------------------------------

## RESUMO:

> cd C:\diretório da pasta onde está o arquivo.c

> gcc -o reconhecedor.exe reconhecedorGramaticas.c

> reconhecedor.exe gramatica.txt

</p>

## Integrantes do grupo:  
Carolina Yumi Siroma GU3042049  
Diogo Da Silva Almeida GU3059995  
Celine Galdino da Silva GU3046354

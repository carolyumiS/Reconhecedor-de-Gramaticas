<h1 align="center"> Reconhecedor de Gramáticas </h1>

## Descrição do Projeto
<p align="justify">
 Este código foi desenvolvido para o primeiro projeto da disciplina de Linguagens Formais e Autômatos (GRULFAT), e tem como finalidade desenvolver um programa, em linguagem C, 
capaz de ler e validar gramáticas formais descritas em um arquivo de texto. 
Ele reconhece se a cadeia de entrada segue corretamente as regras e 
as valida.


 A gramática deve ser representada como uma cadeia formada por regras
 separadas por hífens e finalizada com o símbolo "$", e utilizará dos 
caracteres informados na especificação, sendo os Não terminias em maísculo e
Terminais em minúsculo.A gramática segue o formato "LadoEsquerdo>LadoDireito",
onde o lado esquerdo deve conter pelo menos um símbolo
não terminal, e o lado direito pode conter terminais (letras minúsculas), 
não terminais ou ser vazio.

Para fazer a execução do programa, deve-se, primeiramente, abrir o prompt de comando, onde será 
feito o uso do compilador GCC. É importante, antes, mudar o diretório para a 
pasta onde está contido o arquivo baixado. Por exemplo:

> cd C:\Users\SOLUTION\Desktop\teste

No caso acima, o reconhecedorGramaticas.c está na pasta "teste".

Em seguida, para compilar, o seguinte comando deverá ser executado:

gcc -o reconhecedor.exe reconhecedorGramaticas.c

Esse comando cria o arquivo executável reconhecedor.exe. Depois disso,
pra rodar o programa, digita-se:

reconhecedor.exe gramatica.txt

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

RESUMO:

cd C:\diretório da pasta onde está o arquivo.c

gcc -o reconhecedor.exe reconhecedorGramaticas.c

reconhecedor.exe gramatica.txt


 
</p>

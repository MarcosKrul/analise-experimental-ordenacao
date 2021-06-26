# Análise experimental para comparação entre métodos de ordenação

## Sobre

Engenharia de Computação, UEPG - 4º período

Projeto realizado para a disciplina de Análise de Algoritmos

Marcos Renan Krul

## Métodos de ordenação comparados

1. [Quick sort](https://www.ime.usp.br/~pf/algoritmos/aulas/quick.html)
2. [Ordenação digital](https://www.ime.usp.br/~pf/algoritmos/aulas/radix.html)
3. [Bubble sort](https://medium.com/@henriquebraga_18075/algoritmos-de-ordenação-i-bubble-sort-c162a67261ef)

## Tecnologias

* [Linguagem C](https://docs.microsoft.com/pt-br/cpp/c-language/organization-of-the-c-language-reference?view=msvc-160)
Implementação dos algoritmos de ordenação e da execução da comparação entre eles
* [Python 3.9.2](https://www.python.org)
Script para automatização dos testes de comparação entre os métodos e geração de gráficos (pyplot)

## Instalação

* Clonar o projeto

```
    mkdir teste-ordenacao
    cd teste-ordenacao
    git clone https://github.com/MarcosKrul/analise-experimental-ordenacao.git .
```

* Criacão e ativação do ambiente virtual

Windows

```
    python -m venv venv
    cmd: .\venv\Scripts\activate.bat
    PowerShell: .\venv\Scripts\activate.ps1
```

Linux

```
    python3 -m venv venv
    source venv/bin/activate
```

* Instalação das bibliotecas necessárias

```
    pip install -r requirements.txt
```

* Execução

```
    cd src/scripts
    python index.py
```

## Alterações

Caso haja mudanças no código em C, a dll deve ser gerada novamente.
Na raíz do projeto, execute:
```
    gcc -shared -o ./src/lib/execute.dll -fPIC ./src/execute.c
```

## Resultados

* Interface principal

![Interface principal](https://github.com/MarcosKrul/analise-experimental-ordenacao/blob/main/tmp/images/interface.png)

* Comparação entre quicksort e ordenação digital para 5 dígitos

![Quicksort e ordenação digital para 5 dígitos](https://github.com/MarcosKrul/analise-experimental-ordenacao/blob/main/tmp/images/quick-digital-5d.png)

* Comparação entre quicksort e ordenação digital para 10 dígitos

![Quicksort e ordenação digital para 10 dígitos](https://github.com/MarcosKrul/analise-experimental-ordenacao/blob/main/tmp/images/quick-digital-10d.png)

* Comparação entre quicksort e ordenação digital para 15 dígitos

![Quicksort e ordenação digital para 15 dígitos](https://github.com/MarcosKrul/analise-experimental-ordenacao/blob/main/tmp/images/quick-digital-15d.png)

### Para visualizar os mesmos gráficos (para 5, 10 ou 15 dígitos)

Tamanho inicial: 10000

Tamanho final: 500000

Incremento/passo: 10000

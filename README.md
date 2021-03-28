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
    python script.py
```

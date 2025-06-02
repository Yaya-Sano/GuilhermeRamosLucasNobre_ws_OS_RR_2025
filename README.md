# Cálculo Paralelo de Matrizes com Multithreading

Este projeto implementa a multiplicação de matrizes em linguagem C, com duas versões:

- ✅ Versão **Sequencial**: processamento tradicional usando laços `for`.
- ⚡ Versão **Paralela**: utilização de múltiplas threads (`pthread`) para dividir o trabalho e acelerar a execução.

## 🧠 Objetivo

Demonstrar os ganhos de desempenho ao utilizar programação paralela para realizar multiplicações de matrizes grandes, comparando o tempo de execução entre as abordagens sequencial e paralela.

## 🛠️ Tecnologias e Ferramentas

- Linguagem: **C**
- Biblioteca de threads: `pthread.h`
- Sistema operacional alvo: Windows/Linux
- Compilador: `gcc`

## 📁 Estrutura do Projeto

```
├── src/
│   ├── sequencial.c         # Multiplicação sequencial
│   ├── paralelo.c           # Multiplicação com threads
│   ├── util.c / util.h      # Funções auxiliares: gerar matrizes, comparar, etc.
│   ├── benchmark.py         # Script para testes automatizados
│
├── slides/
│   └── apresentacao.pptx     # Slides da apresentação
│
├── README.md
```

## 📌 Compilação

Compilando manualmente:

```bash
gcc -o sequencial src/sequencial.c src/util.c -O2
gcc -o paralelo src/paralelo.c src/util.c -lpthread -O2
```

## ▶️ Execução

### Geração e multiplicação de matrizes 500x500:

```bash
./sequencial 500 500 500
./paralelo 500 500 500 4    # 4 threads
```

### Parâmetros:

- `linhas_A colunas_A colunas_B [n_threads]`

## 🚀 Benchmark

O script de benchmark está disponível em `benchmark.py` (mesmo diretório dos arquivos C). Ele executa os programas `sequencial` e `paralelo` automaticamente, medindo os tempos de execução para diferentes tamanhos de matrizes.

O script utiliza a biblioteca `subprocess` para executar os binários e a função `time.perf_counter()` para medir o tempo decorrido.

### Como executar o benchmark

Certifique-se de que os arquivos `sequencial` e `paralelo` já estejam compilados (ver seção **Compilação**), e então execute:

```bash
python benchmark.py

## 📊 Resultados

Os tempos de execução (em segundos) serão comparados ao final dos testes, demonstrando a performance da abordagem paralela em relação à sequencial.

## 📎 Slides da Apresentação

Os slides estão disponíveis em `slides/apresentacao.pptx`.

## 🧠 Autores

- Nome: Guilherme Ramos e Lucas Nobre
- Curso: Ciência da Computação
- Disciplina: Sistemas Operacionais

---

**Repositório acadêmico para fins educacionais.**

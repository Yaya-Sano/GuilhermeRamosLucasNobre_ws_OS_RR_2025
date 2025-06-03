# Cálculo Paralelo de Matrizes com Multithreading

Este projeto implementa a multiplicação de matrizes em linguagem C, com duas versões:

- ✅ Versão **Sequencial**: processamento tradicional usando laços `for`.
- ⚡ Versão **Paralela**: utilização de múltiplas threads (`pthread`) para dividir o trabalho e acelerar a execução.

Em ambos os casos, **as matrizes A e B são geradas apenas uma vez e salvas em arquivos `A.txt` e `B.txt`**. Dessa forma, tanto a versão sequencial quanto a paralela usam exatamente os mesmos dados, garantindo uma comparação justa de desempenho.

---

## 🧠 Objetivo

Demonstrar os ganhos de desempenho ao utilizar programação paralela para realizar multiplicações de matrizes grandes, comparando o tempo de execução entre as abordagens sequencial e paralela, sempre trabalhando sobre a mesma entrada.

---

## 🛠️ Tecnologias e Ferramentas

- Linguagem: **C**
- Biblioteca de threads: `pthread.h`
- Sistema operacional alvo: Windows / Linux
- Compilador: `gcc`
- Benchmark e plotagem: **Python 3** + `matplotlib`

---

## 📁 Estrutura do Projeto

```
.
├── slides/
│   └── apresentacao.pdf    # Slides da apresentação
│
├── src/
│   ├── sequencial.c         # Multiplicação sequencial (lê A.txt e B.txt)
│   ├── paralelo.c           # Multiplicação com threads (lê A.txt e B.txt)
│   ├── util.c               # Funções auxiliares: alocar, salvar, carregar, liberar
│   ├── util.h               # Protótipos das funções auxiliares
│   ├── A.txt                # Arquivo gerado pelo benchmark com matriz A
│   ├── B.txt                # Arquivo gerado pelo benchmark com matriz B
│   └── benchmark.py         # Script Python para gerar matrizes, executar testes e plotar gráficos
│
└── README.md
```

---

## 📌 Compilação

Entre na pasta raiz do projeto (onde estão `src/`, `A.txt`, `B.txt` e `benchmark.py`) e digite:

```bash
# Compila a versão sequencial
gcc -o sequencial src/sequencial.c src/util.c -O2

# Compila a versão paralela (com pthread)
gcc -o paralelo src/paralelo.c src/util.c -lpthread -O2
```

Após esses comandos, você terá dois executáveis na raiz:

- `sequencial`  → multiplica matrizes sem threads
- `paralelo`    → multiplica matrizes com múltiplas threads

---

## ▶️ Execução

### 1. Geração das Matrizes (Feito automaticamente pelo benchmark)  
O próprio script `benchmark.py` gera matrizes aleatórias A e B de tamanho especificado (e salva em `A.txt` e `B.txt`). Assim, **os executáveis `sequencial` e `paralelo` sempre lerão as mesmas matrizes** para comparação.

### 2. Multiplicação Manual (opcional)  
Se desejar rodar manualmente sem o benchmark:

1. Gere manualmente seus próprios arquivos `A.txt` e `B.txt`, com números inteiros, formato:
   ```
   a11 a12 … a1n
   a21 a22 … a2n
   …
   an1 an2 … ann
   ```

2. Execute:
   ```bash
   ./sequencial 3000      # Onde 3000 é o tamanho das matrizes (n)
   ./paralelo 3000        # O programa paralelo usará THREADS = MAX_THREADS definido em código
   ```

   - Ambos os executáveis lerão `A.txt` e `B.txt` automaticamente.

---

## 🚀 Benchmark em Python

O arquivo `benchmark.py` está no mesmo diretório dos executáveis. Ele realiza os seguintes passos:

1. **Gera matrizes aleatórias** A e B de tamanho especificado (e salva em `A.txt` e `B.txt`).
2. **Executa** o executável sequencial (`./sequencial n`) e captura o tempo interno impresso.
3. **Executa** o executável paralelo (`./paralelo n`) e captura o tempo interno impresso.
4. **Gera** um gráfico comparativo usando `matplotlib` para mostrar visualmente o ganho de desempenho.

### 1. Instalação de Dependências Python

Certifique-se de ter Python 3 instalado e, no terminal do sistema operacional, rode:

```bash
pip install matplotlib
```

### 2. Como Executar

No terminal, estando na pasta raiz do projeto:

```bash
python benchmark.py
```
- Será gerado `A.txt` e `B.txt` com dimensões \(n 	imes n\).
- O `sequencial` e o `paralelo` rodarão, imprimindo:
  ```
  Tempo sequencial: XX.XXXXXX segundos
  Tempo paralelo (8 threads): YY.YYYYYY segundos
  ```
- Por fim, o `benchmark.py` exibirá um gráfico de barras comparando esses dois valores.

---

## 📊 Resultados

Após rodar `benchmark.py`, a janela do gráfico mostrará algo como:

| Método      | Tempo (s) |
|-------------|-----------|
| Sequencial  | 155.90    |
| Paralelo    |  33.96    |

Os valores exatos dependem do hardware, mas você verá claramente que a versão paralela leva menos tempo.

---

## 📎 Slides da Apresentação

Os slides de apoio estão em `slides/apresentacao.pdf`. Eles detalham:

---

## 🧠 Autores

- **Guilherme Ramos**  
- **Lucas Nobre**  
Curso: Ciência da Computação  
Disciplina: Sistemas Operacionais

---

**Repositório acadêmico para fins educacionais.**

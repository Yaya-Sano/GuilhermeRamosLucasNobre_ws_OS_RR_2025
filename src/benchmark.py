import subprocess
import re
import matplotlib.pyplot as plt
import numpy as np

def salvar_matriz_txt(filename, matriz):
    with open(filename, 'w') as f:
        for linha in matriz:
            f.write(' '.join(map(str, linha)) + '\n')

def gerar_matrizes(n):
    A = np.random.randint(0, 10, size=(n, n))
    B = np.random.randint(0, 10, size=(n, n))
    salvar_matriz_txt("A.txt", A)
    salvar_matriz_txt("B.txt", B)

def run_program(cmd):
    result = subprocess.run(cmd, capture_output=True, text=True)
    print(result.stdout.strip())
    return result.stdout.strip()

def extrair_tempo(texto):
    match = re.search(r'Tempo .*: ([0-9.]+) segundos', texto)
    if match:
        return float(match.group(1))
    return None

def main():
    tamanho = 1000
    gerar_matrizes(tamanho)

    print(f"\n=== Benchmark Multiplicacao de Matrizes ({tamanho}x{tamanho}) ===\n")

    out_seq = run_program(["./sequencial", str(tamanho)])
    tempo_seq = extrair_tempo(out_seq)

    out_par = run_program(["./paralelo", str(tamanho)])
    tempo_par = extrair_tempo(out_par)

    metodos = ['Sequencial', 'Paralelo (8 threads)']
    tempos = [tempo_seq, tempo_par]

    plt.figure(figsize=(8, 5))
    plt.bar(metodos, tempos, color=['blue', 'green'])
    plt.ylabel('Tempo (segundos)')
    plt.title(f'Benchmark Multiplicação de Matrizes {tamanho}x{tamanho}')
    for i, v in enumerate(tempos):
        plt.text(i, v + max(tempos) * 0.01, f"{v:.2f}s", ha='center', fontweight='bold')
    plt.show()

if __name__ == "__main__":
    main()

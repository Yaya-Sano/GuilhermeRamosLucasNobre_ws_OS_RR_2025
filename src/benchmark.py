import subprocess
import re
import matplotlib.pyplot as plt

def run_program(cmd):
    result = subprocess.run(cmd, capture_output=True, text=True)
    return result.stdout.strip()

def extrair_tempo(texto):
    match = re.search(r'Tempo .*: ([0-9.]+) segundos', texto)
    if match:
        return float(match.group(1))
    else:
        return None

def main():
    tamanho = 3000

    print(f"\n=== Benchmark Multiplicacao de Matrizes ({tamanho}x{tamanho}) ===\n")

    print("Versao Sequencial:")
    out_seq = run_program(["./sequencial", str(tamanho)])
    print(out_seq)
    tempo_seq = extrair_tempo(out_seq)

    print("\nVersao Paralela (8 threads):")
    out_par = run_program(["./paralelo", str(tamanho)])
    print(out_par)
    tempo_par = extrair_tempo(out_par)

    metodos = ['Sequencial', 'Paralelo (8 threads)']
    tempos = [tempo_seq, tempo_par]

    plt.figure(figsize=(8,5))
    plt.bar(metodos, tempos, color=['blue', 'green'])
    plt.ylabel('Tempo (segundos)')
    plt.title(f'Benchmark Multiplicação de Matrizes {tamanho}x{tamanho}')
    for i, v in enumerate(tempos):
        plt.text(i, v + max(tempos)*0.01, f"{v:.2f}s", ha='center', fontweight='bold')
    plt.show()

if __name__ == "__main__":
    main()

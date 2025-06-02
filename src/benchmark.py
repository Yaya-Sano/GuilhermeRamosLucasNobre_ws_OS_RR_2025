import subprocess
import time

def run_program(command):
    start = time.time()
    result = subprocess.run(command, capture_output=True, text=True)
    end = time.time()
    elapsed = end - start
    return elapsed, result.stdout, result.stderr

def main():
    tamanho = 4000
    threads = 8

    print(f"=== Benchmark Multiplicação de Matrizes ({tamanho}x{tamanho}) ===\n")

    print("Versão Sequencial:")
    elapsed, out, err = run_program(["./sequencial", str(tamanho)])
    print(out)
    if err:
        print("Erro:", err)
    print(f"Tempo: {elapsed:.4f} segundos\n")

    print(f"Versão Paralela ({threads} threads):")
    elapsed, out, err = run_program(["./paralelo", str(tamanho), str(threads)])
    print(out)
    if err:
        print("Erro:", err)
    print(f"Tempo: {elapsed:.4f} segundos\n")

if __name__ == "__main__":
    main()

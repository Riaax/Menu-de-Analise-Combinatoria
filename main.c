#include <stdio.h>

int calcularFatorial(int numero) {
    int fatorial = 1;
    for (int contador = 1; contador <= numero; contador++) {
        fatorial *= contador;
    }
    return fatorial;
}

int main() {
    int opcao = 0;
    int totalElementos, elementosAgrupados;

    while (opcao != 5) {
        printf("\n--- MENU DE ANALISE COMBINATORIA ---\n\n");
        printf("1. Permutacao Simples\n");
        printf("2. Arranjo Simples\n");
        printf("3. Combinacao Simples\n");
        printf("4. Triangulo de Pascal\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao >= 1 && opcao <= 3) {
            
            if (opcao == 1) {
                printf("Digite o valor de n: ");
                scanf("%d", &totalElementos);
            } else {
                printf("Digite os valores de n e k: ");
                scanf("%d %d", &totalElementos, &elementosAgrupados);
            }

            if (totalElementos < 0 || (opcao > 1 && (elementosAgrupados < 0 || elementosAgrupados > totalElementos))) {
                printf("Erro: Verifique se n >= k >= 0.\n");
                continue;
            }

            if (opcao == 1) {
                printf("Resultado = %d\n", calcularFatorial(totalElementos));
            } 
            else if (opcao == 2) {
                int resultado = calcularFatorial(totalElementos) / calcularFatorial(totalElementos - elementosAgrupados);
                printf("Resultado = %d\n", resultado);
            } 
            else if (opcao == 3) {
                int resultado = calcularFatorial(totalElementos) / (calcularFatorial(elementosAgrupados) * calcularFatorial(totalElementos - elementosAgrupados));
                printf("Resultado = %d\n", resultado);
            }
            
        } 
        
        else if (opcao == 4) {
            int linhas;
            printf("Digite o numero de linhas (maximo 12): ");
            scanf("%d", &linhas);
            
            if (linhas > 12) { 
                linhas = 12; 
                printf("Maximo é 12 AMIGÃO!\n"); 
            }

            int matrizPascal[12][12];
            printf("\nTriangulo de Pascal:\n");
            
            for (int contador1 = 0; contador1 < linhas; contador1++) {
                for (int contador2 = 0; contador2 <= contador1; contador2++) {
                    
                    if (contador2 == 0 || contador2 == contador1) {
                        matrizPascal[contador1][contador2] = 1;
                    } else {
                        matrizPascal[contador1][contador2] = matrizPascal[contador1 - 1][contador2 - 1] + matrizPascal[contador1 - 1][contador2];
                    }

                    printf("%d ", matrizPascal[contador1][contador2]);
                }
                printf("\n");
            }
        } 
        
        else if (opcao == 5) {
            printf("Saindo do programa...\n");
        } 

        else {
            printf("Opcao invalida! Tente novamente.\n");
        }
    }
    
    return 0;
}

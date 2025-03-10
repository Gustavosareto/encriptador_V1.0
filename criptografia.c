#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    
    char cripto[100], confimacao, confirmastring = ';';
    int contador;

    do
    {
        // Limpa o console antes de cada nova entrada
        #ifdef _WIN32
            system("cls");  // Windows
        #else
            system("clear"); // Linux/macOS
        #endif


        contador = 0; // Coloquei dentro do loop pois nao estava contando quando reiniciava o loop
        
        //Loop de checagem se tem o ';' no final para poder enviar.
        do
        {
            printf("\nInforme a mensagem que deseja enviar codificada: ");
            scanf( "%99[^\n]", cripto); //%99[^\n] Coloquei para contar os espaços na String
            getchar(); // Limpa o \n do buffer
            
            int tamanho = strlen(cripto); // Responsavel por verificar se o ultimo caracter é o ';'
            if (cripto[tamanho -1] != confirmastring)
            {
                printf("ERRO, Por favor a mensagem deve terminar com o caracter %c para ser enviada", confirmastring);
            }else {
                // Remove o caractere especial da string antes da codificação
                cripto[tamanho - 1] = '\0';
                break;
            }

        } while (1);
        
        // Laço para contar cada caracter da String e checar a quantidade
        for (int i = 0; i < strlen(cripto); i++)
        {
            contador++; // Cada novo for acresenta uma nova contagem de caracter
        }

        printf("Texto com %d caracteres\n\n", contador); // Mostra quantidade de caracteres acumulado na String

        // Faço para passar cada letra e criptografar as mesmas
        for (int i = 0; i < strlen(cripto); i++)
        {
            cripto[i] = (5 * cripto[i] + 100) % 256; // Parte onde faz a criptografia da String
        }
        
        printf("Texto codificado: %s\n", cripto); // Resultado da criptografia
        
        printf("\nContinuar? (S/N)"); // Pede ao usuario se dejesa continuar
        scanf(" %c", &confimacao); // Recebe a informação
        getchar(); 
    
    } while (confimacao == 's' || confimacao == 'S');  // Checagem se o usuario colocar maiuscula e minuscula
    
    return 0;
}

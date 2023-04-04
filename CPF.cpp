#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool validar_cpf(char* cpf) {
    int a, b, soma, resto;
    char digitoUm, digitoDois;
    char cpfSemPontos[11];
    
    for (a = 0, b = 0; a < strlen(cpf); a++) {
        if (isdigit(cpf[a])) {
            cpfSemPontos[b++] = cpf[a];
        }
    }
    
    cpfSemPontos[b] = '\0';
    
    if (strlen(cpfSemPontos) != 11) {
        return false;
    }
    
    for (a = 1; a < 11; a++) {
        if (cpfSemPontos[a] != cpfSemPontos[0]) {
            break;
        }
    }
    
    if (a == 11) {
        return false;
    }
    
    soma = 0;
    
    for (a = 0, b = 10; a < 9; a++, b--) {
        soma += (cpfSemPontos[a] - '0') * b;
    }
    
    resto = soma % 11;
    
    if (resto < 2) {
        digitoUm = '0';
    } else {
        digitoUm = (11 - resto) + '0';
    }

    if (cpfSemPontos[9] != digitoUm) {
        return false;
    }
    
    soma = 0;
    
    for (a = 0, b = 11; a < 10; a++, b--) {
        soma += (cpfSemPontos[a] - '0') * b;
    }
    
    resto = soma % 11;
    
    if (resto < 2) {
        digitoDois = '0';
    } else {
        digitoDois = (11 - resto) + '0';
    }
    
    if (cpfSemPontos[10] != digitoDois) {
        return false;
    }
    
    return true;
}

int main() {
    char cpf[15];
    
    printf("Digite um CPF: ");
    scanf("%s", cpf);
    
    if (validar_cpf(cpf)) {
        printf("CPF valido\n");
    } else {
        printf("CPF invalido\n");
    }
    
    return 0;
}

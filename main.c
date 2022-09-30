#include <stdio.h>
#include <stdlib.h>

int multiplier(char *vector, int factor);
int verifyDigit(int digitAfterBar, char *vector);
int verifyData(char *vector, int size, int total);

int main()
{
    printf("Digite seu CPF! (xxx.xxx.xxx-xx)\n");
    static int cpfLength = 11;
    static int totalSymbols = 3;
    char data[cpfLength + totalSymbols + 1];
    int size = cpfLength + totalSymbols + 1;
    scanf("%s", data);

    if (verifyData(data, size, totalSymbols))
    {
        if (verifyDigit(1, data) && verifyDigit(2, data))
        {
            printf("\n\tO cpf %s é um cpf válido!\n", &data);
            return 0;
        }

        printf("\n\tCPF invalido!\n");
        return -1;
    }
    else
    {
        printf("\n\tERROR!\n");
        return -1;
    }
}

/**
 * @brief verifies specified digit of cpf, values are hard coded
 *
 * @param digitAfterBar
 * @param vector
 * @return 0 if the digit is invalid, otherwise returns 1
 */
int verifyDigit(int digitAfterBar, char *vector)
{
    if (digitAfterBar >= 3 || digitAfterBar <= 0)
    {
        return 0;
    }

    int sum = multiplier(vector, 10 + digitAfterBar - 1);
    int digit = 11 + digitAfterBar;
    int div = sum % 11;
    if (div < 2)
    {
        if (vector[digit] - 48 != 0)
        {
            return 0;
        }
    }
    else
    {
        if (vector[digit] - 48 != 11 - div)
        {
            return 0;
        }
    }
    return 1;
}

/**
 * @brief Verifies if the passed vector has the specified total of symbols (anything other than numbers) in a given string
 *
 * @param vector The given string
 * @param size The size of the given string
 * @param total The total of symbols that will be checked
 * @return 0 if there are less or more symbols than speficied, else returns 1
 */
int verifyData(char *vector, int size, int total)
{
    int sum = 0;
    size--;
    for (int i = 0; i < size; i++)
    {
        if ((int)vector[i] < 48 || (int)vector[i] > 57)
        {
            sum++;
        }
    }
    if (sum != total)
    {
        printf("ERROR: expected  %d symbols on input, got %d!\n", total, sum);
        return 0;
    }
    return 1;
}

int multiplier(char *vector, int factor)
{
    int sum = 0;
    int cont = 0;
    while (factor >= 2)
    {
        if ((int)vector[cont] >= 48 && (int)vector[cont] <= 57)
        {
            sum += (vector[cont] - 48) * factor;
            factor--;
        }
        cont++;
    }
    return sum;
}
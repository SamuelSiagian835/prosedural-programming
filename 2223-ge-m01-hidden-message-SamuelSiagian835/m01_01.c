// 12S21035 - Silviana Siagian
// 12S21042 - Samuel Siagian

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <length>\n", argv[0]);
        return 1;
    }

    int length = atoi(argv[1]);

    char str[100];
    fgets(str, 100, stdin);
    str[strcspn(str, "\r\n")] = '\0';

    int n = strlen(str) % length == 0 ? strlen(str) / length : strlen(str) / length + 1;
    if (strlen(str) % length == 0)
    {
        n--;
    }

    char result[n][length + 1];
    int i, j;
    for (i = 0; i < n; i++) 
    {
        for (j = 0; j < length; j++)
        {
            if (i * length + j < strlen(str)){
                result[i][j] = str[i * length + j];
            } else {
                result[i][j] = '#';
            }
        }
        result[i][length] = '\0';
    }
    i = 0;
    do {
        printf("%s\n", result[i]);
        i++;
    } while (i < n);

    char hidden[length * n + 1];
    hidden[length * n] = '\0';
    int k = 0;
    for (j = 0; j < length; j++)
    {
        for (i = 0; i < n; i++)
        {
            hidden[k++] = result[i][j];
        }
    }
    printf("%s\n", hidden);

    return 0;
}
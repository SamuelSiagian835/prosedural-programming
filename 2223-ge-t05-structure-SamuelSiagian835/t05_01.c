// 12S21035 - Silviana Siagian
// 12S21042 - Samuel Siagian

#include <stdio.h>
#include <string.h>

#define MAX_KATA 5
#define MAX_PANJANG_KATA 20
#define MAX_PANJANG_ARTI 80

void getString(char str[])
{
    int c = 0;
    while (1)
    {
        char x = getchar();
        if (x == '\r')
        {
            continue;
        }
        if (x == '\n')
        {
            break;
        }
        str[c] = x;
        str[++c] = '\0';
    }
}

struct Word
{
    char kata[MAX_PANJANG_KATA + 1];
    char arti[MAX_PANJANG_ARTI + 1];
};

void findMeaning(struct Word dict[], int numWords, char kata[])
{
    int i;
    for (i = 0; i < numWords; i++)
    {
        if (strcmp(dict[i].kata, kata) == 0)
        {
            printf("%s#%s\n", dict[i].kata, dict[i].arti);
            return;
        }
    }
}

int main()
{
    char command[MAX_PANJANG_KATA + 1], kata[MAX_PANJANG_KATA + 1], arti[MAX_PANJANG_ARTI + 1];
    struct Word dict[MAX_KATA];
    int numWords = 0;

    do
    {
        getString(command);
        if (strcmp(command, "register") == 0)
        {
            if (numWords == MAX_KATA)
            {
                getString(kata);
                getString(arti);
                continue;
            }
            getString(kata);
            getString(arti);
            strcpy(dict[numWords].kata, kata);
            strcpy(dict[numWords].arti, arti);
            numWords++;
        }
        else if (strcmp(command, "find") == 0)
        {
            getString(kata);
            findMeaning(dict, numWords, kata);
        }
        else if (strcmp(command, "---") == 0)
        {
            break;
        }
    } while (1);

    return 0;
}
// NIM - Name
// NIM - Name

#include <stdio.h>

int main(int _argc, char **_argv)
{
    int ucok, butet;
    scanf("%d", &ucok);
    scanf("%d", &butet);
    int waktu1, waktu2;
    int time1, time2;
    waktu1 = 0;
    waktu2 = 0;
    time1 = 0;
    time2 = 0;

    // ucokcok
    if (ucok > 0)
    {
        waktu1 = (ucok / 3) * 3;
        if (ucok % 3 != 0)
        {
            time1 = (ucok / 3) + 1;
        }
    }

    if (butet > 0)
    {
        waktu2 = (butet / 3) * 3;
        if (butet % 3 != 0)
        {
            time2 = (butet / 3) + 1;
        }
    }

    int total_time = time1 + time2;

    for (int j = 0; j < total_time; j++)
    {
        if (j % 2 != 0 && time1 != 0)
        {

            waktu1 = waktu1 + 3;
        }
        else if (j % 2 == 0 && time2 != 0)
        {
            waktu2 = waktu2 + 3;
        }
    }

    int total = waktu1 + waktu2;

    printf("%d\n", waktu1);
    printf("%d\n", waktu2);
    printf("%d\n", total);

    return 0;
}

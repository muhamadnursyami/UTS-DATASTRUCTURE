#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Nama : Muhamad Nur Syami
// Nim : 2101020005
char *string, temp;
int stringindex = 0;

int push(char input)
{
    if (string == NULL)
    {
        string = (char *)malloc(sizeof(char));
    }
    else
    {
        string = (char *)realloc(string, sizeof(char) * ++stringindex);
    }
    string[stringindex] = input;
    return 1;
}

void sortdesending(char *string, int stringindex)
{
    for (int i = 0; i < stringindex; i++)
    {

        for (int j = 0; j < stringindex; j++)
        {
            if (string[j] > string[j + 1])
            {

                temp = string[j];
                string[j] = string[j + 1];
                string[j + 1] = temp;
            }
        }
    }
}

char pop()
{
    return string[stringindex--];
}

void tampil(char *string, int stringindex)
{
    for (int i = stringindex; i >= 0; i--)
    {
        pop();
        sortdesending(string, stringindex);
        printf("%c", string[i]);
    }
}

int main(int argc, char **argv)
{

    for (int i = 1; i < argc; i++)
    {
        int k = strlen(argv[i]);
        for (int j = 0; j < k; j++)
        {
            char input = argv[i][j];
            push(input);
        }
        if (i < argc - 1)
            push(' ');
    }
    sortdesending(string, stringindex);
    tampil(string, stringindex);

    return 0;
}
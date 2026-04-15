#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void MostrarPersonas(char *nombres[])
{
    for (int i = 0; i < 5; i++)
    {
        printf(" \nNombre %d: %s",i+1,nombres[i]);
    }
    
}
void LiberarMemoria(char *nombres[])
{
    for (int i = 0; i < 5; i++)
    {
        free(nombres[i]);
    }
    
}
int main()
{
    char *nombres[5];
    for (int i = 0; i < 5; i++)
    {
        char buff[50];
        printf("\nEscriba un nombre:");
        scanf("%s",buff);
        int tama = strlen(buff);
        nombres[i] = (char *)malloc(tama * sizeof(char)+1);
        strcpy(nombres[i],buff);
    }
    MostrarPersonas(nombres);
    LiberarMemoria(nombres);
}
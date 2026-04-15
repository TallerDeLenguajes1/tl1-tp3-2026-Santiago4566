#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int BuscarNombre(char *nombres[],char *palabra)
{
    for (int i = 0; i < 5; i++)
    {
        if(strstr(nombres[i],palabra)!=NULL)
        {
            return i;
        }
    }
    return -1;
}
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
    char palabra[50];
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
    printf("\ningrese una palabra para buscar un nombre: ");
    scanf("%s",palabra);
    if (BuscarNombre(nombres,palabra)!=-1)
    {
        printf("\nNombre encontrado: %s",nombres[BuscarNombre(nombres,palabra)]);
    }else
    {
        printf("\nNo se encontraron nombres similares");
    }
    
    LiberarMemoria(nombres);
}
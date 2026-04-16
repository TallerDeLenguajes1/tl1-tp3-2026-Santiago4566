#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void BuscarNombrePorID(char *nombre[])
{
    int id;
    printf("\nIngrese una ID para buscar :");
    scanf("%d",&id);
    if (id<1 || id >5)
    {
        printf("No se encontró el valor buscado");
    }else
    {
        printf("\nNombre encontrado: %s",nombre[id-1]);   
    }
}
int BuscarNombrePorPalabra(char *nombres[],char *palabra)
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
void Interfaz(char *nombre[])
{
    int busqueda = 1;
    do
    {
        int dato;
        printf("\nSistema De busqueda");
        printf("\nIngrese 1 para busqueda por ID, 2 para busqueda por Palabra :");
        scanf("%d",&dato);
        if (dato == 1)
        {
            (BuscarNombrePorID(nombre));
        }else if (dato == 2)
        {
            char palabra[50];
            int resultado;
            printf("\ningrese una palabra para buscar: ");
            scanf("%s",palabra);
            resultado = BuscarNombrePorPalabra(nombre,palabra);
            if (resultado!=-1)
            {
                printf("\nNombre encontrado: %s",nombre[resultado]);
            }else
            {
                printf("\nNo se encontraron nombres");
            }
        }else
        {
            printf("\nnumero incorrecto");
        }
        printf("\nDesea Realisar otra Busqueda?");
        printf("\n Si: 1 , No: otro numero : ");
        scanf("%d",&busqueda);
    } while (busqueda ==1);
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
    Interfaz(nombres);
    LiberarMemoria(nombres);
}
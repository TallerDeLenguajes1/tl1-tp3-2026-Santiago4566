#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
typedef struct
{
    int ProductoID;
    int Cantidad;
    char *TipoProducto;
    float PrecioUnitario;
}Producto;
typedef struct 
{
    int ClienteID;
    char *NombreCliente;
    int CantidadProductosApedir;
    Producto *Productos;
}Cliente;
int costoproducto(Producto item)
{
    float resultado;
    resultado = item.Cantidad * item.PrecioUnitario;
    return resultado;
}
int LiberarMemoria(char **nombre, int cantidad, Cliente *clientes)
{
    for (int i = 0; i < cantidad; i++)
    { 
        free(clientes[i].Productos);
        free(nombre[i]);
    }
    free(nombre);
    free(clientes);
}
void asignarNombres(char **nombre, int cantidad, Cliente *clientes, char **tipos)
{
    for (int i = 0; i < cantidad; i++)
    {
        char buff[50];
        printf("Nombre %d:",i+1);
        scanf("%s",buff);
        int tama;
        tama = strlen(buff);
        nombre[i] = (char *)malloc(tama * sizeof(char)+1);
        strcpy(nombre[i],buff);
        clientes[i].NombreCliente = nombre[i];
        clientes[i].ClienteID = i+1;
        clientes[i].CantidadProductosApedir = 1+rand()%5;
        clientes[i].Productos = (Producto *)malloc(clientes[i].CantidadProductosApedir * sizeof(Producto));
        for (int j = 0; j < clientes[i].CantidadProductosApedir; j++)
        {
            clientes[i].Productos[j].TipoProducto = tipos[rand()%5];
            clientes[i].Productos[j].Cantidad = 1+rand()%10;
            clientes[i].Productos[j].PrecioUnitario = 10+rand()%91;
            clientes[i].Productos[j].ProductoID = j+1;
        }
    }
}
void cargarDatos(Cliente *clientes,int cantidad)
{
    printf("\n ~ Datos de los clientes ~");
    for (int i = 0; i < cantidad; i++)
    {
        printf("\nCliente ID:%d",clientes[i].ClienteID);
        printf("\nNombre :%s",clientes[i].NombreCliente);
        printf("\nCantidad De Productos :%d",clientes[i].CantidadProductosApedir);
        for (int j = 0; j < clientes[i].CantidadProductosApedir; j++)
        {
            float total = costoproducto(clientes[i].Productos[j]);
            printf("\nProducto ID:%d",clientes[i].Productos[j].ProductoID);
            printf("\nTipo:%s",clientes[i].Productos[j].TipoProducto);
            printf("\nCantidad:%d",clientes[i].Productos[j].Cantidad);
            printf("\nPrecio Unitario:%.2f",clientes[i].Productos[j].PrecioUnitario);
            printf("\nPrecio Total:%.2f",total);
        }
    }
}
int main()
{
    char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};
    int cantidad;
    Cliente *clientes;
    char **nombres;
    srand(time(NULL));
    printf("ingrese cuantos nombres desea ingresar: ");
    scanf("%d",&cantidad);
    nombres = (char **)malloc(cantidad * sizeof(char*));
    clientes = (Cliente *)malloc(cantidad * sizeof(Cliente));
    asignarNombres(nombres,cantidad,clientes,TiposProductos);
    cargarDatos(clientes,cantidad); 
    LiberarMemoria(nombres,cantidad,clientes);
}
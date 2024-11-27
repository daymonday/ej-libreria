/* Una conocida librer�a de Bs. As. cuenta con vendedores/as identificados con un c�digo que atienden
la tienda, recibiendo una comisi�n del 3% sobre el importe de las ventas realizadas. Los clientes pueden solicitar a los
vendedores/as los libros disponibles en la librer�a, donde cada vendedor/a atiende una secci�n espec�fica.
Por cada venta se solicita:( validar los ignresos por teclado con funci�n)
- Cod vendedor (int, 201 a 220, finaliza 200)
-Nro factura, int mayor a 0
-Tpo de libro vendido (char, F-N-I-O)
- Cant vendida
- Precio unitario (real mayor a 0)

Se considera que cada venta incluye solo un tipo de ibro y que un vendedor/a puede atender
muchas secciones o ninguna (si estuvo ausente ese d�a). La carga finaliza con un codigo de vendedor igual a 200.
Se pide:

Al finalizar la jornada, indicar el nro de factura con el mayor importe de venta -> FUNCI�N MAYOR
El promedio de ventas en importe de cada uno de los vendedores que estuvieron presentes -> Pasamos INT a FLOAT, y es cant total de importe / cant vendedores pres
Informar el procentaje vendido de cada uno del os tipos de libro -> Pasamos INT  a FLOAT, y es (cant total de libros vendidos de cada tipo * 100) / cant total vendidos ?
Listar el cod vendedor, cant vendida, importe cobrado y comision del vendedor*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int ValidarDato(int lim_inf,int lim_sup);
int ValidarPositivo(int num1);
float ValidarNroReal(float num1,int lim);
char ValidarCaracter(char char1,char char2, char char3, char char4);
/*int REHACER  NroMayor(int num1,int num2); vector o no??*/

int main()
{
    int i=0,cant_vendedor=0,nro_factura,cod_vendedor,cant_vendida,cant_total_vendida,cantF,cantN,cantI,cantO;
    int vec_cantventas[20]={0}; /* no deberias poner 20 pq quedarian espacios libres, resolver*/
    float importeXunidad,importeXventa,importes_sumas,vec_cantimporte[20]={0};
    char tipoDeLibro;

    printf("\nIngrese codigo de vendedor -201 a 210- 200 para finalizar:\n");
    cod_vendedor=ValidarDato(200,210);

    while(cod_vendedor!=200 && cant_vendedor<20)
    {
        printf("\nIngrese codigo de factura (Entero > 0):\n");
        nro_factura=ValidarPositivo(nro_factura);

        printf("\nIngrese tipo de libro [F - Ficcion, N- No Ficcion, I- Infantil, O- Otros] \n");
        tipoDeLibro=ValidarCaracter('F','N','I','O');

        printf("\nIngrese cantidad de libros vendida (Entero > 0) :\n");
        cant_vendida=ValidarPositivo(cant_vendida);

        printf("\nIngrese importe (Real > 0):\n");
        importeXunidad=ValidarNroReal(importeXunidad,0);

        cant_total_vendida=+cant_vendida;
        importeXventa=+importeXunidad*cant_vendida;
        /* puede ser q hayas entendido mal esta parte*/

        vec_cantventas[cod_vendedor-200]=+cant_vendida; /* guarda la cantidad vendida segun el indice*/
        vec_cantimporte[cod_vendedor-200]=+importeXventa; /* guarda el importe vendido sgun el indice*/




        switch(tipoDeLibro)
        {
        case 'F':
            cantF=+cant_vendida;
            break;
        case 'N':
            cantN=+cant_vendida;
            break;
        case 'I':
            cantI=+cant_vendida;
            break;
        case 'O':
            cantO=+cant_vendida;
            break;
        }




        /* funcion mayor de la factura*/

        cant_vendedor++;
        cod_vendedor=ValidarDato(200,210);
    }

    if(cant_vendedor>0)
    {
        /*2*/
        printf("\nCOD. VENDEDOR\tPROMEDIO DE VENTAS\n");
        for(i=0; i<cant_vendedor; i++)
        {
            printf("\n%d\t%d\t%.2f\t%.2f\n",i+200,vec_cantventas[i]/cant_total_vendida); /* se muestra el cod vendedor, y el proemdio de la suma de sus ventas*/
        }
        /*3*/
        printf("\n TIPO DE LIBRO: \t \t \t PORCENTAJE:");
        printf("Ficcion \t\t\t %.2f",(float) cantF*100/ (float) cant_total_vendida);
        printf("No Ficcion \t\t\t %.2f",(float) cantN*100/ (float) cant_total_vendida);
        printf("Infantil \t\t\t %.2f",(float) cantI*100/ (float) cant_total_vendida);
        printf("Otros \t\t\t %.2f",(float) cantO*100/ (float) cant_total_vendida);

        /*4*/

        printf("\nCOD. VENDEDOR\tCANT. VENDIDAS\tSUMA DE IMPORTES\tCOMISION\n");
        for(i=0; i<cant_vendedor; i++) /* se deberia mostrar el cod vendedor, la suma de ventas (estos 2 del mismo vec), el importe (otro vec pero mismo indice) y la comision*/
        {
            printf("\n%d\t%d\t%.2f\t%.2f\n",i+200,vec_cantventas[i],vec_cantimporte[i],vec_cantimporte[i]*0,03);
        }

    }
    else
    {
        printf("\n No se han ingresado datos.\n");
    }

    system("pause");
    return 0;
}
/* int NroMayor(int num1,int num2)
{
    int num_mayor=num1;
    if(num1!=0&&num2!=0)
    {
        if(num2>=num1)
            num_mayor=num2;
    }
    return num_mayor;
}
*/
int ValidarDato(int lim_inf,int lim_sup)
{
    int dato;
    do
    {
        scanf("\n%d",&dato);
    }
    while((dato<lim_inf)||(dato>lim_sup));
    return dato;
}

int ValidarPositivo(int num1)
{
    do
    {
        scanf("\n%d",&num1);
    }
    while(num1<0);
    return num1;
}

float ValidarNroReal(float num1, int lim)
{  int band=0;
    do
    { if(band==0)
        {scanf("\n%f",&num1);
        band=1;}
        else{printf("VALOR INCORRECTO. Reingrese nro. mayor a %d:\n",lim);
        scanf("\n%f",&num1);}
    }
    while(num1<=lim);
    return num1;
}

char ValidarCaracter(char char1,char char2, char char3, char char4)
{
    char caractervalido;
    do
    {

        scanf("\n%c",&caractervalido);
        fflush(stdin);
        caractervalido=toupper(caractervalido);

    }
    while(caractervalido!=char1&&caractervalido!=char2&&caractervalido!=char3&&caractervalido!=char4);

    return caractervalido;
}

#include <stdio.h>
#include <stdlib.h>
#define n 3
struct pila
{
    int p[n];
    int tope;
};



int main()
{
    int x;
    struct pila p;
    p.tope=0;
    printf("\tPROYECTO DE PILA\n\n");
    do{

        x=Menu(&p);

    }while(x!=-1);

    return 0;
}

int Menu(struct pila *p)//El menu de mi programa.
{
    int a,d;
    int x=1;int y=0;int z=0;
    int i=0;
    printf("Que es lo que quieres hacer:");
    printf("\n\nOpcion 1: Ingresa valor.");
    printf("\nOpcion 2: Sacar un valor.");
    printf("\nOpcion 3: Ver el ultimo valor.");
    printf("\nOpcion 4: Salir.\n");scanf("%d",&a);
    if(a>0&&a<5){
        switch(a){ //Opciones para entrar en el programa
            case 1:
                x=push(p->p,p->tope);
                if(x==1){
                    for(i=0;i<p->tope;i++)
                    {
                    printf("\n\tLos datos en la pila son: %c%d%c \n",221,p->p[i],221);
                    printf("\t\t\t\t   %c\n",238);
                    }

                }
                else
                {
                    printf("\tLa pila ya se encuentra llena.\nQuita un valor.\n\n");
                }

            break;
            case 2:
                y=pop(p->p,p->tope);
                if(y==(p->p[p->tope]))//Solo si Y es igual a el lugar en la pila entonces esta decicion se cumple.
                {
                    printf("El dato fue sacado correctamente de la pila\nDesea imprimir la Pila actual:\n1.-Si\n2.-No.\n");
                    scanf("%d",&d);
                    if(d==1)
                    {
                        for(i=0;i<p->tope;i++)
                        {
                            printf("\t\t\t%c%d%c",221,p->p[i],221);
                            printf("\n\t\t\t - \n");
                            //printf("\n");
                        }
                    }
                }
                else
                {
                    printf("\tNo se puede sacar valores, la pila esta vacia.\n\n");
                }
            break;
            case 3:
                z=peek(p->p,p->tope);
                if(z==p->p[p->tope-1])
                {
                    printf("\n\tEste es el ultimo valor de la pila:%c%d%c\n\n",221,p->p[p->tope-1],221);
                }
                else
                {
                    printf("\n\tLa Pila esta vacia.\n\n");
                }
            break;
            case 4:
                printf("\nGracias por usar el programa. :)\n\n");
                return-1;
            break;
        }
    }
    else
    {
        printf("\nSelecciono un valor no establecido.\nVuelva a seleccionar una opcion.\n");
        return 1;
    }
}

int push(struct pila *p) //Es un push
{
    int val;
    if((p->tope)>=n)return 0;//Ya no puede ingresar valores porque la pila esta llena.
    printf("Ingrese el valor: ");
    scanf("%d",&val);
    p->p[p->tope]=val;

    p->tope=p->tope+1;

    return 1;//La pila aun tiene espacios para seguirla llenando.
}

int pop(struct pila *p)
{
    if(p->tope==0)return -1;//Esto quire decir que la pila no tiene valores.

    p->tope = p->tope -1;

    return p->p[p->tope];//Muestra el valor que se va a eliminar.
}

int peek(struct pila *p)//te no es nesesario modificar.
{
    if(p->tope==0)return -1;//indica que la pila no tiene valores para mostrar.
    return p->p[p->tope-1];
}

#include<stdio.h>
#include<string.h>

typedef struct
{
    int elemento[1000];
    int contadorElementos;
}ListaTimes;

typedef struct
{
    int elemento[1000000];
    int contadorElementos;
}ListaQueue;


void deQueue(ListaQueue *lista) //o team queue eu nao removo
{
    printf("%d\n", lista->elemento[0]);
    for(int i=0; i<lista->contadorElementos-1;i++)
    lista->elemento[i]=lista->elemento[i+1];
    lista->contadorElementos-=1;
}

/*
void enQueue(ListaQueue *lista, int valor)
{
    for(int z=0;z<= lista->contadorElementos;z++)
    {
        if (z==0 && lista->contadorElementos==0) //primeiro elemento adicionado
        {
            lista->elemento[z]=valor;
            lista->contadorElementos++;
            break;
        }

        else if (lista->contadorElementos==1 && valor > lista->elemento[0]) //so cai aqui quando tem 1 elemento e 
        {                                                                        //valor é maior que elemento[0]
            lista->elemento[1]=valor;
            lista->contadorElementos++;
            break;
        }
        
        else if (lista->contadorElementos==1 && valor < lista->elemento[0]) //so cai aqui quando tem 1 elemento e
        {                                                                           //valor é menor que elemento[0]
            
            
            lista->elemento[1]=lista->elemento[0];
            lista->elemento[0]= valor;
            lista->contadorElementos++;
            break;
        }

        else if (lista->contadorElementos>=2 && valor>=lista->elemento[z] && valor<lista->elemento[z+1] && z<=lista->contadorElementos-2) 
        {                                                         //so cai aqui quando tem 2 elementos ou mais,  x <= valor < y

            for (int f=lista->contadorElementos; f > z+1;f--) //acho que seria f> z+1
            {
                printf("contador de elementos antes de entrar no loop: %d\n", lista->contadorElementos);
                lista->elemento[f] = lista->elemento[f-1];
                break;
            }
            lista->elemento[z+1] = valor;
            lista->contadorElementos++;
            //break;
        }
        
        else if(lista->contadorElementos>=2 && valor<lista->elemento[0])//menor dq o primeiro elemento
        {
            for(int f=lista->contadorElementos; f>1; f--)
            {
                lista->elemento[f]=lista->elemento[f-1];
            }
            lista->elemento[0]=valor;
        }
        
        else
        {
            lista->elemento[lista->contadorElementos]=valor;
            lista->contadorElementos++;
        }
    }
    //lista->elemento[lista->contadorElementos]=valor; //por enquanto adiciona no final da lista
    //lista->contadorElementos++;
    //return;
}*/

void enQueue(ListaQueue *lista, int valor)
{
    if (lista->contadorElementos == 0)  //primeira adicao
    {
        lista->elemento[0]=valor;
        lista->contadorElementos++;
        return;
    }

    else if(valor<=lista->elemento[lista->contadorElementos-1]) //caso valor seja menor ou igual ao ultimo elemento
    {
        
        for(int i=0;i<lista->contadorElementos;i++)
        {

            if(valor <= lista->elemento[i])
            {
                for(int j=lista->contadorElementos;j>=i+1;j--)
                {
                    lista->elemento[j]=lista->elemento[j-1];
                }
                lista->elemento[i]=valor;
                lista->contadorElementos++;
                return;
            }
        }
        
    }
    else        //caso valor seja maior dq o ultimo elemento
    {
        lista->elemento[lista->contadorElementos]= valor;
        lista->contadorElementos++;
        return;
    }

}

void addQueue(ListaTimes *time, int x) //adiciono sempre no final da TEAM QUEUE
{
    time->elemento[time->contadorElementos] =x;
    time->contadorElementos++;
    
}




int main()
{
    int numerodeTimes;                 //Numeros de times 

    scanf("%d", &numerodeTimes);
    int cenario=1;
    while(1)                            //roda enquanto numero de times estiver entre 1 e 1000
    {
        
        if(numerodeTimes>=1 && numerodeTimes<=1000)     //numero de times deve estar entre 1 e 1000
        {
            
            printf("Scenario #%d\n", cenario++);
            ListaTimes times[numerodeTimes];
            ListaQueue lista;
            lista.contadorElementos=0;  //essa lista só é alterada com enqueue e dequeue
            for (int i=0; i< numerodeTimes;i++)times[i].contadorElementos=0; //zera o contador de elementos de todos os times
            
            int elementoN;
                              
            for(int j=0;j<numerodeTimes;j++) //contador do time
            {
                int elementosT;
                scanf("%d", &elementosT);   //Numero de elementos do time

                for(int i=0; i< elementosT;i++) //contador elemento do time
                {
                    
                    scanf("%d", &elementoN);
                    addQueue(&times[j], elementoN); //time j recebe o elemento inserido.
                    
                }

            }   //terminei de inserir os elementos nos times
            
            //agora recebe os comandos de enqueue e dequeue;
            char comando[8];
            //temos que ter um loop aqui para receber os comandos
            scanf("%s", comando);
            while(1)
            {
                
                if (strcmp(comando, "0")==0) //encerra o loop
                {
                    numerodeTimes=0;
                    break;
                }

                else if (strcmp(comando, "STOP")== 0) //termina o ciclo
                {
                    
                    printf("\n");
                    scanf("%d", &numerodeTimes);
                    break;
                }

                else if (strcmp(comando, "ENQUEUE")== 0) //adiciona na lista
                {
                    scanf("%d", &elementoN);
                    enQueue(&lista, elementoN);
                    
                }

                else if (strcmp(comando, "DEQUEUE")== 0) //remove o primeiro elemento da lista
                {
                    deQueue(&lista);
                }
                
                scanf("%s", comando);
            }
            
        }
        else break;
    }
    
    return 0;
}
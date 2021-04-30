#include<stdio.h>
#include<string.h>
#include<stdlib.h>

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
    lista->contadorElementos=lista->contadorElementos - 1;
    return;
}



void enQueue(ListaQueue *lista, ListaTimes *times, int valor, int numerodeTimes)
{
    

    if (lista->contadorElementos == 0)  //primeira adicao
    {
        lista->elemento[0]=valor;
        lista->contadorElementos++;
        return;
    }

    
   else if(lista->contadorElementos>=1)
   {
        int indexNum=0, maiorIndex=0, indexTime, achouElem=0;
        for(int i=0; i< numerodeTimes;i++)
        {
            for(int j=0;j<times[i].contadorElementos;j++)
            {
                if(valor == times[i].elemento[j])
                {
                    indexTime=i;
                    break;
                    //if (indexNum>=maiorIndex)maiorIndex=indexNum;
                }
            }
        }
        for(int q=0;q<lista->contadorElementos;q++)
        {
            for(int t=0;t<times[indexTime].contadorElementos;t++)
            {
                if(lista->elemento[q]== times[indexTime].elemento[t])
                {
                    achouElem++;
                    indexNum=q;
                    if (indexNum>=maiorIndex)maiorIndex=indexNum;
                }
            }
        }

        if(achouElem>0)
        {
            for(int p=lista->contadorElementos;p>maiorIndex+1;p--)
            {
                lista->elemento[p]=lista->elemento[p-1];
            }
            lista->elemento[maiorIndex+1]=valor;
            lista->contadorElementos++;
            return;
        }
        else
        {
            lista->elemento[lista->contadorElementos]=valor;
            lista->contadorElementos++;
            return;
        }
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
                    enQueue(&lista, &times, elementoN, numerodeTimes);
                    
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
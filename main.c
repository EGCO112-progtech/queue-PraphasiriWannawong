#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Node.h"

#include "Queue.h"

int main(int argc , char **argv) {
  NodePtr headPtr=NULL;
   NodePtr tailPtr=NULL;
/* For struct Queue*/
  Queue  q;
   q. headPtr=NULL;
   q.tailPtr=NULL;
   q.size=0;

   int i,x,cash,cus=0;


 for(i=1;i<argc;i++){
        if(strcmp(argv[i],"x")==0){
          printf("Customer No. %d\n",cus+1);
          cus++;
            x=dequeue_struct(&q);
            if(x>0)
            {
                //x=dequeue(&headPtr,&tailPtr);
              printf("You have to pay %d\n",x);
              do{
                //รับค่าราคา
                printf("Cash : ");
                scanf("%d",&cash);
              }while(cash<x);
                printf("Thank you\n");
                if(cash>x)
                {
                  printf("Change is : %d\n",cash-x);
                }  
            }
          }
        else {
       enqueue_struct(&q, atoi(argv[i]), atoi(argv[i+1]));
          i++;
        //enqueue(&headPtr,&tailPtr, atoi(argv[i]));
           
        }

   }
  printf("========================================\n");
  if(q.size<=1) printf("There is %d people left in the queue\n",q.size);
  else printf("There are %d people left in the queue\n",q.size);
  printf("==========Clearing queue==========\n");
  while(q.size>0)
    dequeue_struct(&q);
  return 0; 

  }

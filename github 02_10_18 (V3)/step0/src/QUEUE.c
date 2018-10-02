#include<stdio.h>
#include<stdlib.h>
#include "QUEUE.h"

/*Crée une file vide */
QUEUE create_queue(void){
  QUEUE q=NULL;
  return q;
}
/* ajoute un élément en fin de file*/
QUEUE queue_pull_on(QUEUE q, void* pdata){
  QUEUE queue=calloc(1,sizeof(*queue));
  queue->pdata=pdata;
  if (q==NULL){
    queue->next=queue;
    return queue;
  }
  queue->next=q->next;
  q->next=queue;
  return queue;
}
/* permet de visualiser la file */
void visualize_int_queue(QUEUE q){
  if (q==NULL)
    printf("[]");
  else{
    printf("[");
    QUEUE queue=q->next;
    for(;queue!=q;queue=queue->next){
      if(queue==NULL){
        puts("Error: input isn't a queue.]");
        return;
      }
      printf("%d",*((int*)queue->pdata));
      if (queue!=q)
        printf(", ");
      }
    printf("%d]",*((int*)queue->pdata));
  }
}

/* transforme la file en liste */
LIST queue_to_list(QUEUE q){
  if (q==NULL){
    return (LIST)q;
  }
  QUEUE l=q->next;
  q->next=NULL;
  return (LIST)l;

}

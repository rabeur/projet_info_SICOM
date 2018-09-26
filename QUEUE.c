#include<stdio.h>
#include<stdlib.h>
#include "QUEUE.h"


QUEUE create_queue(void){
  QUEUE q=NULL;
  return q;
}

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

LIST queue_to_list(QUEUE q){
  if (q==NULL){
    return (LIST)q;
  }
  QUEUE l=q->next;
  q->next=NULL;
  return (LIST)l;

}

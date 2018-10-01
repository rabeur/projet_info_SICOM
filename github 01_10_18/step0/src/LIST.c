#include<stdio.h>
#include<stdlib.h>
#include "LIST.h"


LIST create_list(void){
  LIST l=NULL;
  return l;
}

LIST head_insert_list(LIST l, void* pdata){
  LIST ppair=calloc(1,sizeof(*ppair));
  ppair->next=l;
  ppair->pdata=pdata;
  return ppair;
}

LIST head_delete_list(LIST l){
	if(!list_empty(l)){
		LIST p=NULL;
		p=l->next;
		free(l);
		return p;
	}
	else return l;
}

int list_empty(LIST l){
  return (l==NULL);
}

void free_list(LIST* pl){
  while(!list_empty(*pl)){
	  *pl=head_delete_list(*pl);
    }
    free(*pl);
}

void visualize_int_list(LIST l){
	LIST p=NULL;
	printf("[");
	for (p=l; !list_empty(p); p=p->next){
    printf("%d",*((int*)p->pdata));
		if (!list_empty(p->next))printf(", ");
    }
    puts("]");
}



/*
void* first_list(LIST l){
  if (list_empty(l))
    return NULL;
  return l->pdata;
}

LIST next_list(LIST l){
  if (list_empty(l))
    return NULL;
  return l->next;
}

typedef int(*action)(void*);

int list_visit(LIST l, action f){
  while(!list_empty(l))
    {
    f(first_list(l));
    l=next_list(l);
    }
}
*/

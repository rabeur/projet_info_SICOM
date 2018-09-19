#include<stdio.h>
#include<stdlib.h>
#include "LIST.h"


LIST create_list(void){
  LIST l=calloc(1,sizeof(*l));
  return l;
}

void* first(LIST l){
  return l->pdata;
}

LIST next(LIST l){
  return l->next;
}

LIST head_insert(LIST l, void* pdata){
  LIST ppair=calloc(1,sizeof(*ppair));
  ppair->next=l;
  ppair->pdata=pdata;
  return ppair;
}

LIST head_delete(LIST l){
	if(!list_empty(l)){
		LIST p=NULL;
		p=l->next;
		free(l);
		return p;
	}
	else return NULL;
}

int list_empty(LIST l){
  return (l==NULL);
}

void free_list(LIST l){
  while(!list_empty(l)){
	  l=head_delete(l);
    }
	free(l);
}

typedef int(*action)(void*);

int list_visit(LIST l, action f){
  while(!list_empty(l))
    {
    f(first(l));
    l=next(l);
    }
}
/*
int action_display(void* p){
  printf("%d, ", *p);
  return 0;
}

void display_list(LIST l){
  list_visit(l,action_display;
}
*/
void visualize(LIST l,char format[3]){
	LIST p, p2;
	printf("[");
	for (p=l; !list_empty(p); p=p->next){
    p2=p->pdata;
		printf(format,*p2);
		if (!list_empty(p->next))printf(", ");
    }
    puts("]");
}

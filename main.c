#include<stdio.h>
#include<stdlib.h>
#include"QUEUE.h"
#include "LIST.h"
/*
struct lexem_t;
typedef struct lexem_t *lexem;

int lexem_print( void*ptr ) {
  lexem lex = ptr;
  printf( "%d", lex->nline );
}
*/


main(){
int a=2,b=4,c=0;
LIST l=create_list();

l=head_insert_list(l,&c);
l=head_insert_list(l,&b);
l=head_insert_list(l,&b);

visualize_int_list(l);
/*
l=head_delete_list(l);
l=head_delete_list(l);
l=head_delete_list(l);
*/
free_list(&l);
visualize_int_list(l);

l=head_insert_list(l,&b);
l=head_insert_list(l,&c);
free_list(&l);
visualize_int_list(l);
}

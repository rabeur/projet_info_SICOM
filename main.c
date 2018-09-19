#include<stdio.h>
#include<stdlib.h>
#include"LIST.h"


main(){
int a=2,b=4,c=0;
char s[512]="salut";

printf("%s\n", s);

LIST l=create_list();
l=head_insert(l,&a);
l=head_insert(l,&b);
l=head_insert(l,&c);
//visualize(l,"%d");
void* p =l->pdata;
printf("%d\n",*p);

}

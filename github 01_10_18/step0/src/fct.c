#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <strings.h>

#include <global.h>
#include <notify.h>
#include <lex.h>



int ischiffre(char c){
switch(c)
{
case '0', '1', '2', '3', '4', '5', '6', '7', '8', '9':
return 1;
break;
default:
return 0;
break;
}
}

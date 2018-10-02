#include<stdio.h>
#include<stdlib.h>
#include <string.h>

void test_commentaire(LEXEM* plex){plex->type=[COMMENT];}
void test_coma(LEXEM*){plex->type=[COMA];}
void test_parentc(LEXEM*){plex->type=[CARACTERE];}
void test_parento(LEXEM*){plex->type=[CARACTERE];}
void test_mots(LEXEM*){plex->type=[STRING];}
void test_NL(LEXEM*){plex->type=[NL];}

void test_FT(LEXEM*){plex->type=[FT];}
void test_guil(LEXEM*){plex->type=[GUIL];}

void test_dot(LEXEM* plex){plex->type=[DOT];}

void test_registre(LEXEM* plex){
  char regAvail[31]={'0','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31'};
  char* s=plex->content;
  if (s[1]!='\0' && is_in(s[1],regAvail,31)){
    plex->type=[REGISTRE];
  }
  else if(c[2]!='\0'){
    char dest[512]="Register doesn't exist - Lign ";
   strcat(dest,(char)plex->lign);
   strcpy(plex->error, dest);
   plex->type=[ERROR];

  }
  else if (s[2]!='\0'){
    int i;
    char str[3];str[0]=*s;str[1]=*(s+1);str[2]='\0'
      for(i=0;i<n;i++){
        if (strcmp(str,regAvail[i])==0)
            plex->type=[REGISTRE];
            return;
      }
      char dest[512]="Register doesn't exist - Lign ";
      strcat(dest,(char)plex->lign);
      strcpy(plex->error, dest);
      plex->type=[ERROR];
  }
  else{
    char dest[512]="Register doesn't exist - Lign ";
    strcat(dest,(char)plex->lign);
    strcpy(plex->error, dest);
    plex->type=[ERROR];
  }
}


void test_nombre(LEXEM* plex){
  char digit[10]={'0','1','2','3','4','5','6','7','8','9'};
  char digithexa[16]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};

  char* pc=plex->content;
  int testdeci=1;
  int testhexa=1;

  // Si le s commence par 0x on verifie que ce qui suit est bien un nombre hexa
  if (*pc=='0' && *(pc+1)=='x'){
      pc+=2;
      do{
        testhexa=testhexa && is_in(*pc,digithexa,16);
        pc++;
      } while (*pc!='\0');
      if (testhexa==1)
        plex->type=[VAL_HEXA];
      else {
        char dest[512]="Hexadecimal doesn't exist - Lign ";
        strcat(dest,(char)plex->lign);
        strcpy(plex->error, dest);
        plex->type=[ERROR];
      }
  }

  // On verifie que ce qui suit est bien un nombre decimal
  if (*pc=='-' || *pc=='+'){
      pc++;
      while(*pc==' ') pc++; //on passe les blancs entre les signes et les chiffres
      do{
        testdeci=testdeci && is_in(*pc,digit,10);
        pc++;
      }while (*pc!='\0');
      if (testdeci==1)
        plex->type=[VAL_DECIMAL];
      else {
        char dest[512]="Number doesn't exist - Lign ";
        strcat(dest,(char)plex->lign);
        strcpy(plex->error, dest);
        plex->type=[ERROR];
      }
  }
  else {
    char dest[512]="Number doesn't exist - Lign ";
    strcat(dest,(char)plex->lign);
    strcpy(plex->error, dest);
    plex->type=[ERROR];
  }
}

int is_in(char c,char* tab,int n){  //test si le caractere c appartient au tableau tab
  int i;
  if (n==0) {return 0;}
  for (i=0;i<n;i++){
    if (tab[i]==c) return 1;
    }
  return 0;
}
/*
LIST fill_list_number(int min, int max){
  if (min>max) return NULL;
  LIST l=create_list();
  char* tab =calloc(max-min+1,sizeof(*tab));
  int i;
  for (i=max;i>=min;i--){
    tab[i-1]=(char)i;
    printf("%c, ", tab[i-1]);
    l=head_insert_list(l,tab+i-1);
    }

}
*/

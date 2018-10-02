
/**
 * @file lex.c
 * @author François Portet <francois.portet@imag.fr>
 * @brief Lexical analysis routines for MIPS assembly syntax.
 *
 * These routines perform the analysis of the lexeme of an assembly source code file.
 */

#define _POSIX_C_SOURCE 200112L
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <strings.h>
#include <LEXEM.h>
#include <QUEUE.h>
#include <TEST_FUNCTIONS.h>
#include <LIST.h>

#include <global.h>
#include <notify.h>
#include <lex.h>



/* ATTENTION: getNextToken est juste un exemple -> il est à recoder completement !!! */
/**
 * @param token The pointeur to the lexeme to be extracted.
 * @param current_line The address from which the analysis must be performed.
 * @return the address at which the analysis stopped or NULL if the analysis is terminated.
 * @brief This function get an input line, extracts a token from it and return the pointeur to the next place where the analysis should continue.
 */

/* note that MIPS assembly supports distinctions between lower and upper case*/
char* getNextToken(char** token, char* current_line)
{
    char* start = current_line;
    char* end=NULL;
    int token_size=0;

    /* check input parameter*/
    if (current_line == NULL) return NULL;

    /* eats any blanks,  before the token*/
    while ((*start!='\0'|| *start!='\n') && (isblank(*start)))
    {
	     start++;
    }
    /* go till next blank or end*/
    end=start;
    /* si le lexem commence par un hastag alors jusqu'à la fin de la ligne, tout les mots font partie du meme commentaire, on finit donc le mots qu'en présence d'une fin de ligne ou de texte*/
    if (*end== '#')
    {
      while((*end!='\0' || *end!='\n'))
        {
          end++;
        }
    }
    /* si le caractère est un caractère spécifique qui permet d'identifier un type de lexem, il est isolé*/
    else if(*end == ',' || *end == '('|| *end==')' || *end == ':' || *end =='"' || *end =='\n' || *end =='\"' || *end =='.')
    {
      end++;
    }
    /*Si le caractère est quelconque alors le "lexem" sera crée jusqu'à atteindre un caractère de séparation caratère si dessus + espace */
    else
    {
        while ((*end!='\0' || *end!='\n') && ((!isblank(*end))|| *end!=',' || *end!='('|| *end!=')' || *end!=':'|| *end!='"' || *end=='#' || *end =='.' ))
        {
	         end++;
        }
    }
    /*compute size : if zero there is no more token to extract*/
    token_size=end-start;
    if (token_size>0)
    {
	     *token 	= calloc(token_size+1,sizeof(*start));
	      strncpy(*token,start,token_size);
	       (*token)[token_size]='\0';
	        return end;
    }
    return NULL;
}

/*test de chaque lexem afin de le classer dans une liste de type définit au préalable dans LEXEM.h*/
void type_lexem(LEXEM* lexem){
  switch (*(lexem->content)){
    case '#':
          test_commentaire(lexem);
          break;
    case '.':
           test_dot(lexem);
          break;
    case '$':
          test_registre(lexem);
          break;
    case ',':
          test_coma(lexem);
          break;
    case '(':
          test_parento(lexem);
          break;
    case ')':
          test_parentc(lexem);
          break;
    case '0':
           test_nombre(lexem);
          break;
    case '1':
          test_nombre(lexem);
          break;
    case '2':
          test_nombre(lexem);
          break;
    case '3':
          test_nombre(lexem);
          break;
    case '4':
          test_nombre(lexem);
          break;
    case '5':
          test_nombre(lexem);
          break;
    case '6':
          test_nombre(lexem);
          break;
    case '7':
          test_nombre(lexem);
          break;
    case '8':
          test_nombre(lexem);
          break;
    case '9':
          test_nombre(lexem);
          break;
    case '-':
          test_nombre(lexem);
          break;
    case '+':
          test_nombre(lexem);
          break;
    case '\n':
          test_NL(lexem);
          break;
    case'\0':
          test_FT(lexem);
          break;
    case '\"':
          test_guil(lexem);
          break;
    /*rajouté le cas '\' cependant nous ne savons pas encore l'implémenter correctement*/
    default:
          test_mots(lexem);
          break;
  }
}


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
    while ((*start!='\0'|| *start!='\n') && (isblank(*start))
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
    elif(*end == ',' || *end == '('|| *end==')' || *end == ':' || *end =='"' || *end =='\n' || *end =='\"')
    {
      end++;
    }
    /*Si le caractère est quelconque alors le "lexem" sera crée jusqu'à atteindre un caractère de séparation caratère si dessus + espace */
    else
    {
        while ((*end!='\0' || *end!='\n') && (!isblank(*end)|| *end!=',' || *end!='('|| *end!=')' || *end!=':'|| *end!='"' || *end='#' )
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
char* type_lexem(LEXEM* lexem){
  switch (*(lexem->comment)){
    case '#':
      return test_commentaire((lexem);
      break;
    case '.':
          return test_directive((lexem));
          break;
    case '$':
          return test_registre((lexem));
          break;
    case ',':
          return test_nombre((lexem));
          break;
    case '(':
          return test_nombre((lexem));
          break;
    case ')':
          return test_nombre((lexem));
          break;
    case '0', '1', '2', '3', '4', '5', '6', '7', '8', '9','-','+':
          return test_nombre((lexem));
          break;
    case '\n':
          return test_NL(lexem);
          break;
    case'\0':
          return test_FT(lexem);
          break;
    case '\"':
          return test_guil(lexem);
          break;
    // rajouté le cas '\' cependant nous ne savons pas encore l'implémenter correctement
    default:
          return test_mot(lexem);
          break;
  }
}

/**
 * @param line String of the line of source code to be analysed.
 * @param nline the line number in the source code.
 * @return should return the collection of lexemes that represent the input line of source code.
 * @brief This function performs lexical analysis of one standardized line.
 *
 */

/*void lex_read_line( char *line, int nline) {
    char* token = NULL;
    char* current_address=line;


    /* TODO : faire l'analyse lexical de chaque token ici et les ajouter dans une collection*/
    /* ATTENTION: getNextToken est à recoder completement*/
  /*  while( (current_address= getNextToken(&token, current_address)) != NULL){

        puts(token);
    }

    return;
} */

/**
 * @param file Assembly source code file name.
 * @param nlines Pointer to the number of lines in the file.
 * @return should return the collection of lexemes
 * @brief This function loads an assembly code from a file into memory.
 *
 */
/*void lex_load_file( char *file, unsigned int *nlines ) {

    FILE        *fp   = NULL;
    char         line[STRLEN]; /* original source line */



/*    fp = fopen( file, "r" );
    if ( NULL == fp ) {
        /*macro ERROR_MSG : message d'erreur puis fin de programme ! */
/*        ERROR_MSG("Error while trying to open %s file --- Aborts",file);
    }
commentaire
    *nlines = 0;

    while(!feof(fp)) {

        /*read source code line-by-line */
/*        if ( NULL != fgets( line, STRLEN-1, fp ) ) {
            line[strlen(line)-1] = '\0';  /* eat final '\n' */
/*            (*nlines)++;

            if ( 0 != strlen(line) ) {
                lex_read_line(line,*nlines);
            }
        }
    }

    fclose(fp);
    return;
}*/

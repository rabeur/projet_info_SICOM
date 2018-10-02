
/**
 * @file main.c
 * @author François Portet <francois.portet@imag.fr> from François Cayre
 * @brief Main entry point for MIPS assembler.
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>


#include <global.h>
#include <notify.h>
#include <lex.h>

#include <LEXEM.h>
#include <QUEUE.h>
#include <TEST_FUNCTIONS.h>
#include <LIST.h>
/**
 * @param exec Name of executable.
 * @return Nothing.
 * @brief Print usage.
 *
 */
/*void print_usage( char *exec ) {
    fprintf(stderr, "Usage: %s file.s\n",
            exec);
}*/



/**
 * @param argc Number of arguments on the command line.
 * @param argv Value of arguments on the command line.
 * @return Whether this was a success or not.
 * @brief Main entry point for MIPS assembler.
 *
*/


int main()
{
    FILE *f1 ;
    f1 = fopen("miam_sujet.s","r");
    char* token;
    char s[200];
    char* flag;
    char* endline;
    QUEUE q; /*future liste contenant les lexem*/
    int i=1;/* indicateur de la ligne du lexem*/
    LEXEM lexnl;
    lexnl.type =NL;/* permet le test suivant : savoir quand nous changeons de ligne */
    q = create_queue(); /* file qui contient tout les pointeur sur les lexems étudiés*/
    flag = fgets(s,200,f1); /* Permet de savoir si on arrive a lire le fichier*/
    if (flag != NULL);
    /* On découpe les lexem lignes par lignes*/
    do
    {

        do
        {
          endline = getNextToken(&token,s );
          LEXEM* lex=calloc(1,sizeof(LEXEM));
          lex->lign=0;
          lex->type=EMPTY;
          *(lex->error)="";
        *(lex->content)=*token;
          /*ici ajout du lexem contenu dans token dans la file*/
          q = queue_pull_on(q,lex);
        }while(endline != NULL);
        flag = fgets(s,200,f1);
    }while (flag !=NULL);
    /* on ferme le fichier .s ouvert auparavant*/
    fclose(f1);
    /* On ajoute le LEXEM "fin de texte" : '\0' à notre file afin de la compléter */
    LEXEM* lex=calloc(1,sizeof(*lex));
    lex->lign=0;
    lex->type=EMPTY;
    *(lex->error)="";
    *(lex->content)='\0';
    q = queue_pull_on(q,lex);
    /*après avoir fini de récolter chaque potentiel lexem du code, on les test*/
    q = queue_to_list(q);
    LIST l;
    l=q;
    /*chaque lexem est analysé afin de déterminer son type ainsi que les erreurs ou warnings */
    while (l->next != NULL)
    {
          do
          {char carac =*((char*)(q->pdata->content));
          type_lexem(carac);
          l->pdata->lign = i;
          l=l->next;
        }while(l->pdata->type != lexnl.type);
        /* on change de ligne donc i est incrémenté de 1 */
        i++;
    }
    /*affichage de la liste des lexem ainsi que leur type + erreur*/
    l=q;
    while (l->next != NULL )
    {
          /* on affiche pour par lexem sa ligne sur le fichier .s, son type et son message d'erreur si il en a un */
          printf("[%d]    %s   [%s]  %s\n", ((l)->pdata)->lign,*(l->pdata->comment),*(l->pdata->type),*(l->pdata->error));
          l=l->next;
    }
/*ON libère la mémoire affecter à tout les lexems*/
    while (q->next != NULL)
    {
      free(q->pdata);
      q=q->next;
    }
  return EXIT_SUCCESS;
}

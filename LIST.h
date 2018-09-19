#ifndef _LIST
#define _LIST




typedef struct pair {
  void* pdata;
  struct pair * next;
}* LIST;
LIST create_list(void);
void* first(LIST l);
LIST next(LIST l);
LIST head_insert(LIST l, void* pdata);
LIST head_delete(LIST l);
int list_empty(LIST l);
void free_list(LIST l);
typedef int(*action)(void*);
int list_visit(LIST l, action f);
//void display_list(LIST l);
//  void action_display(void*);
void visualize(LIST l,char format[3]);


/*
void visualiser(Liste L);
Liste ajout_queue(int c, Liste l);
Liste copie(Liste l);
Liste concat(Liste l1, Liste l2);
Liste supprimen(int n, Liste l);
*/
#endif

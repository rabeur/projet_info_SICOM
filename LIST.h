#ifndef _LIST
#define _LIST


typedef struct pair {
  void* pdata;
  struct pair * next;
}* LIST;

LIST create_list(void);
LIST head_insert_list(LIST l, void* pdata);
LIST head_delete_list(LIST l);
int list_empty(LIST l);
void free_list(LIST* pl);
void visualize_int_list(LIST l);

#endif

/*
void* first_list(LIST l);
LIST next_list(LIST l);
typedef int(*action)(void*);
int list_visit(LIST l, action f);
*/
/*
void visualiser(Liste L);
Liste ajout_queue(int c, Liste l);
Liste copie(Liste l);
Liste concat(Liste l1, Liste l2);
Liste supprimen(int n, Liste l);
*/

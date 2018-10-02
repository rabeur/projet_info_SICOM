#ifndef _QUEUE
#define _QUEUE
#include "LIST.h"

typedef LIST QUEUE;

QUEUE create_queue(void);
QUEUE queue_pull_on(QUEUE, void*);
void visualize_int_queue(QUEUE);
LIST queue_to_list(QUEUE);


#endif

#ifndef PROCESS_H
#define PROCESS_H

typedef struct 
{
   unsigned   pid;
   unsigned  burst;
   unsigned  arrival;
   unsigned  priority;
   unsigned start_time, complete_time, wait_time, turn_around;
   unsigned seq;


} Info;


typedef struct st_node
{

   Info* info;
   struct st_node* next;
   struct st_node* prev;
} Node;

typedef struct 
{
   size_t size;
   Node* head;
   Node* tail;
   

}List;




List* create_l();
List* destroy_l(List*);

int empty(List*);
int insert_n(Info*, List*);
int remove_n(List*);
int show_l(List*, const char*);
int size(List*);
List* deserialize(const char* file);
int serialize(List* L, const char* file);

#endif
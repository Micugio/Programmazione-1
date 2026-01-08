#include <cstdlib>

using namespace std;

#define MAXSIZE 100

struct Message{
    int id;
    char message[MAXSIZE+1];
};

typedef struct _Stack * Stack;

Stack init_stack();
void push(Stack q, Message & m);
Message pop(Stack q);
bool stack_is_empty(Stack q);
void delete_stack(Stack & q);
void print_stack(Stack q);
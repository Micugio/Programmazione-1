
typedef struct __stack__ __stack_s__;
typedef struct Stack_ {
  __stack_s__ * _stack;
} Stack;


Stack StackInit(const unsigned dim = 10);
void StackDeinit(Stack & s);
bool StackIsEmpty(const Stack & p);
bool StackIsFull(const Stack & p);
bool Push(Stack & p, const char t);
bool Pop(Stack & p);
bool Top(Stack &p, char & t);
void Print(const Stack & p);

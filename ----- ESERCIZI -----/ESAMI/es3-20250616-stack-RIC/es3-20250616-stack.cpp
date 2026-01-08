#include "es3-20250616-stack.h"
#include <iostream>

struct _Stack {
    struct _Node {
        Message m;
        struct _Node * next;
    };
    struct _Node * top;
};

Stack init_stack() {
    Stack s = new _Stack;
    s->top = nullptr;
    return s;
}

void push(Stack s, Message & m) {
    struct _Stack::_Node * n = new struct _Stack::_Node;
    n->m = m;
    n->next = s->top;
    s->top = n;
}

Message pop(Stack s) {
    struct _Stack::_Node * n = s->top;
    Message m = n->m;
    s->top = n->next;
    delete n;
    return m;
}

bool stack_is_empty(Stack s) {
    return s->top == NULL;
}

void delete_stack(Stack & s) {
    while (!stack_is_empty(s)) {
        pop(s);
    }
    delete s;
}

void print_stack(Stack s) {
    struct _Stack::_Node * n = s->top;
    while (n != nullptr) {
        std::cout << n->m.id << ": " << n->m.message << std::endl;
        n = n->next;
    }
}
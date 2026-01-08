#include <iostream>
#include <cstdlib>
#include <cstring>
#include "es3-20250616-stack.h"

void mystrrevcat(char * dest, char * src) {
    int srclen = strlen(src);
    int destlen = strlen(dest);
    int i = destlen-1;
    dest[destlen + srclen] = '\0';
    while (i >= 0) {
        dest[srclen + i] = dest[i];
        i--;
    }
    i = 0;
    while (i < srclen) {
        dest[i] = src[srclen - 1 - i];
        i++;
    }
}

void mystrcat(char * dest, char * src) {
    strcat(dest, src);
}

// Inserire qui sott la dichiarazione della funzione estrai_messaggio

void estrai_messaggio(Stack & s, int id, char * & messaggio, int size = 0);

// Inserire qui sopra la dichiarazione della funzione estrai_messaggio

int main(int argc, char * argv[]) {
    if (argc != 1) {
        std::cerr << "Usage: " << argv[0] << std::endl;
        return 1;
    }

    Stack s = init_stack();
    Message m;

    m.id = 1;
    strcpy(m.message, "Hello ");
    push(s, m);

    m.id = 3;
    strcpy(m.message, "Esame ");
    push(s, m);

    m.id = 2;
    strcpy(m.message, "Il ");
    push(s, m);

    m.id = 1;
    strcpy(m.message, "World");
    push(s, m);

    m.id = 3;
    strcpy(m.message, "molto ");
    push(s, m);

    m.id = 2;
    strcpy(m.message, "professore ");
    push(s, m);

    m.id = 1;
    strcpy(m.message, "!");
    push(s, m);

    m.id = 3;
    strcpy(m.message, "Difficile!");
    push(s, m);

    m.id = 2;
    strcpy(m.message, "ha molta ");
    push(s, m);

    m.id = 2;
    strcpy(m.message, "fantasia!");
    push(s, m);

    char * messaggio;
    std::cout << "Messaggio: 2" << std::endl;
    estrai_messaggio(s, 2, messaggio);
    std::cout << "\t" << messaggio << std::endl;
    delete [] messaggio;

    std::cout << "Messaggio: 1" << std::endl;
    estrai_messaggio(s, 1, messaggio);
    std::cout << "\t" << messaggio << std::endl;
    delete [] messaggio;

    std::cout << "Messaggio: 4" << std::endl;
    estrai_messaggio(s, 4, messaggio);
    std::cout << "\t" << messaggio << std::endl;
    delete [] messaggio;

    std::cout << "Stack -- " << std::endl;
    print_stack(s);
    delete_stack(s);
    return 0;
}


// Inserire qui sotto la definizione della funzione estrai_messaggio

/*
void estrai_messaggio(Stack & s, int id, char * & message, int size) {
    if (stack_is_empty(s)) {
        message = new char[size + 1];
        message[0] = '\0';
    } else {
        Message m = pop(s);
        if (m.id == id) {
            estrai_messaggio(s, id, message, size + strlen(m.message));
            mystrcat(message, m.message);
        } else {
            estrai_messaggio(s, id, message, size);
            push(s, m);
        }
    }
}
*/


void estrai_messaggio(Stack & s, int id, char * & messaggio, int size) {
    Stack tmp_keep = init_stack();     // elementi NON estratti
    Stack tmp_msg  = init_stack();     // elementi estratti (id giusto)
    Message m;
    int total_len = 0;

    // 1) Svuoto lo stack originale
    while (!stack_is_empty(s)) {
        m = pop(s);
        if (m.id == id) {
            total_len += strlen(m.message);
            push(tmp_msg, m);
        } else {
            push(tmp_keep, m);
        }
    }

    // 2) Alloco la stringa risultato
    messaggio = new char[total_len + 1];
    messaggio[0] = '\0';

    // 3) Ricostruisco il messaggio (ordine corretto)
    while (!stack_is_empty(tmp_msg)) {
        m = pop(tmp_msg);
        mystrcat(messaggio, m.message); // NOTA: usare mystrrevcat se voglio stringa inversa
    }

    // 4) Ripristino lo stack originale (solo i NON estratti)
    while (!stack_is_empty(tmp_keep)) {
        m = pop(tmp_keep);
        push(s, m);
    }

    delete_stack(tmp_keep);
    delete_stack(tmp_msg);
}


// Inserire qui sopra la definizione della funzione estrai_messaggio

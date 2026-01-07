#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <ctime>
//using namespace std;

typedef struct List {
		int info;
		struct List * next;
		List() {
			info = -1;
			next = nullptr;
		};
		List(int i, List * n) {
			info = i;
			next = n;
		};
} List;

const int MAXNUM = 50;

void do_print(const List *l);
void stampa_list(const List * l, const char * prefix);
List * create_random_list(int i = 0);
void dealloca(List * & l);

// ---------------------------------------------------------------
// Inserire qui sotto la dichiarazione della funzione compute_list

void insert_last (List *& s, int d);

void compute_list (List * l, List * & s1, List * & s2);

// Inserire qui sopra la dichiarazione della funzione compute_list
// ---------------------------------------------------------------

// NON modificare il main
int main(int argc, char ** argv) {
		// Non modificare il main
		if (argc != 1) {
				std::cerr << "Usage: " << argv[0] << std::endl;
				exit(1);
		}

		int seed = 0;
		// Inizializzare random_seed a true per un comportamento random
		bool random_seed = false;
		if (random_seed)
				seed = time(NULL);

		srand(seed);
		List * l = create_random_list();
		stampa_list(l, "Lista iniziale");
		List * l1, *l2;
		compute_list(l, l1, l2);
		stampa_list(l1, "Lista l1");
		stampa_list(l2, "Lista l2");
		dealloca(l);
		dealloca(l1);
		dealloca(l2);
}

// ---------------------------------------------------------------
// Inserire qui sotto la definizione della funzione compute_list

void insert_last (List * & s, int d) {
  // caso base: lista vuota → inserisco qui
  if (s == NULL) {
    s = new List;
    s->info = d;
    s->next = NULL;
    return;
  }

  // caso ricorsivo: avanzo verso la coda
  insert_last(s->next, d);
}

// NOTA: manca contare elementi della lista s1 e s2

void compute_list_aux (List * l, List * & s1, List * & s2, int i, int j){
	if (l == NULL) {
		insert_last(s1, i);
		insert_last(s2, j);
		return;
	}
	else {
		if (((l->info % 2) == 0) && ((l->info % 3) != 0)) {
			insert_last(s1, l->info);
			++i;
		}
		if ((l->info % 3) == 0) {
			insert_last(s2, l->info);
			++j;
		}
		compute_list_aux(l->next, s1, s2, i, j);
	}
}

void compute_list (List * l, List * & s1, List * & s2){
	s1=nullptr;
	s2=nullptr;
	
	compute_list_aux(l, s1, s2, 0, 0);
}

// Inserire qui sopra la definizione della funzione compute_list
// ---------------------------------------------------------------

// ---------------------------------------------------------------
// NON MODIFICARE IL CODICE SOTTOSTANTE
// ---------------------------------------------------------------
// Non modificare questa funzione
void do_print(const List *l) {
		if (l != NULL) {
				std::cout << " \"" << l->info << "\"";
				do_print(l->next);
		}
}
// Non modificare questa funzione
void stampa_list(const List * l, const char * prefix) {
		std::cout << prefix << " :";
		do_print(l);
		std::cout << std::endl;
}

// Non modificare questa funzione
List * create_random_list(int i) {
		List * res = NULL;
		if (i < MAXNUM) {
				res = new List{rand() % MAXNUM, create_random_list(++i)};
		}
		return res;
}

// Non modificare questa funzione
void dealloca(List * & l) {
		if (l != NULL) {
				List * n = l;
				dealloca(l->next);
				delete n;
		}
}




// void compute_list(List *s, List *&s1, List *&s2);

/*
void compute_list_aux(List *s, List *&s1, List *&s2, int i1, int i2) {
  if (s == nullptr) {
	  List *n1 = new List{i1, nullptr};
	  List *n2 = new List{i2, nullptr};
	  s1 = n1;
	  s2 = n2;
	  return;
  }
  if (s->info % 2 == 0 && s->info % 3 != 0) {
	  List *n1 = new List{s->info, nullptr};
	  s1 = n1;
	  compute_list_aux(s->next, s1->next, s2, ++i1, i2);
	  return;
  }
  if (s->info % 3 == 0) {
	  List *n2 = new List{s->info, nullptr};
	  s2 = n2;
	  compute_list_aux(s->next, s1, s2->next, i1, i2+1);
	  return;
  }
  compute_list_aux(s->next, s1, s2, i1, i2);
}

void compute_list(List *s, List *&s1, List *&s2) {
	s1 = nullptr;
	s2 = nullptr;
	compute_list_aux(s, s1, s2, 0, 0);
}
*/
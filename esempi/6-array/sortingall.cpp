#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

// Dimensione massima dell'array da ordinare. Notare che la dimesione
// massima occupata dal programma in questo caso puo' essere maggiore
// a 2Gb. Infatti solo per memorizzare array da ordinare occorrono
// maxN * sizeof(int) bytes ovvero: 268435456*4/(1024*1024*1024) =
// 1Gb.  Nel caso di mergesort, un secondo array di dimensione pari a
// maxN e' necessario.

const unsigned long maxN = 268435456;

using namespace std;

// Abilitano diversi print
// #define PRINT_ARRAY
// Simulazione dell'algoritmo (per numeri < 30 output leggibile)
// #define PRINT_HISTOGRAMS

// Variabili globali
int N=0;

// Usato nel merge sort come array di supporto
int * aux = NULL;


// Dichiarazione delle funzioni/procedure usate nel programma
void print_array(int A[], int N, const char * str);
void print_array_graph(int A[], int N, const char * str);
void swap(int & x, int & y);
void selectionsort(int A[], int N);
void insertionsort(int A[], int N);
void bubblesort(int A[], int N);
void merge(int a[], int l, int m, int r);
void mergesortrecur(int A[], int l, int r);
void mergesort(int A[], int N);
void shellsortaux(int A[], int l, int r);
void shellsort(int A[], int N);
void quicksortaux(int A[], int l, int r);
void quicksort(int A[], int N);
int  *gen_array(int n);
int  partition(int A[], int l, int r);


// Generazione di un array di numeri random compresi tra 0 e n-1
int * gen_array(int n) {
  int * r = new int [n];

  cout << "Generato un array di " << n << " elementi" << endl;
  for(int i = 0 ; i < n ; i++) r[i] = (rand() % n);
  return r;
}

// stampa dell'array come funzione f(i) = A[i]. Ovvero stampa A[i]
// asterischi.
void print_array_graph(int A[], int N, const char * str) {
#ifdef PRINT_HISTOGRAMS
  system("clear");
  cout << "========================================" << endl;
  cout << str << endl;
  cout << "========================================" << endl;
  char c = '*';

  for(int i = 0; i < N; i++) {
    if (i < 10)
      cout << "A[0" << i << "] = " ;
    else
      cout << "A[" << i << "] = " ;
    for (int j = 0; j <= A[i]; j++) cout << c;
    cout << endl;
  }
  cout << "========================================" << endl;
  system("sleep 1");
#endif
}

// Stampa dei valori memorizzati nell'array
void print_array(int A[], int N, const char * str) {
#ifdef PRINT_ARRAY
  cout << "========================================" << endl;
  cout << str << endl;
  cout << "========================================" << endl;

  for(int i = 0; i < N; i++)
    cout << "A[" << i << "] = " << A[i] << endl;

  cout << "========================================" << endl;
#endif
}

// Scambia due interi
void swap(int & x, int & y) {
  int z = x;
  x = y;
  y = z;
}


// Selection Sort
void selectionsort(int A[], int N) {
  for(int i = 0; i < N - 1; i++ ){
    print_array_graph(A, N, "Selection Sort");
    int min = i;
    for(int j = i+1; j < N; j++)
      if (A[j] < A[min]) min = j;
    swap(A[i],A[min]);
  }
}


// Insertion Sort
void insertionsort(int A[], int N) {
  for(int i = N -1; i > 0; i--)
    if (A[i] < A[i-1]) {
      swap(A[i],A[i-1]);
      print_array_graph(A, N, "Insertion Sort");
    }

  for(int i = 2; i <= N-1; i++) {
    int j = i;
    int v = A[i];
    print_array_graph(A, N, "Insertion Sort");
    while(v < A[j-1]) {
      A[j] = A[j-1]; j--;
      print_array_graph(A, N, "Insertion Sort");
    }
    A[j] = v;
  }
}


// Bubble Sort
void bubblesort(int A[], int N) {
  for(int i = 0; i < N -1; i++) {
    print_array_graph(A, N, "Bubble Sort");
    for(int j = N-1; j > i; j--) {
      print_array_graph(A, N, "Bubble Sort");
      if(A[j] < A[j-1])
        swap(A[j], A[j-1]);
    }
  }
}


// Merge Sort
void mergesort(int A[], int N) {
  mergesortrecur(A, 0, N-1);
}

void mergesortrecur(int A[], int l, int r) {
  if (r <= l) return;
  int m = (l+r) / 2;
  mergesortrecur(A, l, m);
  print_array_graph(A, N, "Merge Sort 1");
  mergesortrecur(A, m+1, r);
  print_array_graph(A, N, "Merge Sort 2");
  merge(A, l, m, r);
  print_array_graph(A, N, "Merge Sort Merge");
}

void merge(int a[], int l, int m, int r) {
  int i, j;

  // trucco per allocare array una sola volta con una dimensione pari
  // alla dimensione dell'array da ordinare.
  if (aux == NULL) aux = new int[N];

  for(i = m +1; i > l; i--) aux[i-1] = a[i-1];
  for(j = m; j < r; j++)    aux[m+(r-j)] = a[j+1];
  for(int k = l; k <= r; k++)
    if (aux[j] < aux[i])
      a[k] = aux[j--];
    else
      a[k] = aux[i++];
}


// Shell sort
void shellsort(int A[], int N) {
  shellsortaux(A, 0, N-1);
}

void shellsortaux(int A[], int l, int r) {
  int h;
  for(h = 1; h <= (r-1)/9; h = 3*h+1);
  for( ; h > 0; h /= 3) {
    print_array_graph(A, N, "Shell Sort");
    for(int i = l+h; i <= r; i++) {
      int j = i;
      int v = A[i];
      print_array_graph(A, N, "Shell Sort (For)");
      while((j >= l + h) && (v < A[j-h])) {
        print_array_graph(A, N, "Shell Sort (While)");
        A[j] = A[j-h];
        j = j - h;
      }
      A[j] = v;
    }
  }
}



// Quick Sort
void quicksort(int A[], int N) {
  quicksortaux(A, 0, N-1);
}

void quicksortaux(int A[], int l, int r) {

  if (r <= l) return;
  int i = partition(A, l, r);
  quicksortaux(A, l, i-1);
  print_array_graph(A, N, "Quick Sort 1");
  quicksortaux(A, i+1, r);
  print_array_graph(A, N, "Quick Sort 2");
}

int partition(int A[], int l, int r) {
  int i = l-1;
  int j = r;
  int v = A[r];
  while(true) {
    while(A[++i] < v);
    while(v < A[--j]) if (j == l) break;
    if(i >= j) break;
    swap(A[i],A[j]);
  }
  swap(A[i],A[r]);
  return i;
}




void usage(const char * str) {
    cerr << "Use: " << str << " 1|2|3|4|5|6 <n>" << endl;
    cerr << "<n> must be greater than 1" << endl;
    cerr << "    1 : Selection Sort" << endl;
    cerr << "    2 : Insertion Sort" << endl;
    cerr << "    3 : Bubble Sort" << endl;
    cerr << "    4 : Merge Sort" << endl;
    cerr << "    5 : Shell Sort" << endl;
    cerr << "    6 : Quick Sort" << endl;
    cerr << "<n> must be less than " << maxN << endl;
}

int main(int argc, char ** argv) {

  if ((argc <= 1) || (argc > 3)) {
    usage(argv[0]);
    exit(1);
  }

  N = atoi(argv[2]);

  if ((N <= 1) || (N >= maxN))  {
    usage(argv[0]);
    exit(1);

  }

  int algo = atoi(argv[1]);


  if ((algo < 1) || (algo > 6))  {
    usage(argv[0]);
    exit(1);

  }

  int * A = gen_array(N);

  print_array(A, N, "Array disordinato");
  print_array_graph(A, N, "Array Disordinato");

  cout << "========================================" << endl;

  typedef std::chrono::high_resolution_clock Clock;
  typedef std::chrono::milliseconds milliseconds;
  Clock::time_point ct0 = Clock::now();
  time_t t1 = time(NULL);

  switch (algo) {
  case 1: {
    cout << "Selection sort" << endl;
    selectionsort(A, N);
    break;
  }
  case 2: {
    cout << "Insertion sort" << endl;
    insertionsort(A, N);
    break;
  }
  case 3: {
    cout << "Bubblesort sort" << endl;
    bubblesort(A, N);
    break;
  }
  case 4: {
    cout << "Shellsort sort" << endl;
    shellsort(A, N);
    break;
  }
  case 5: {
    cout << "Mergesort sort" << endl;
    mergesort(A, N);
    break;
  }
  case 6: {
    cout << "Quick sort" << endl;
    quicksort(A, N);
    break;
  }
  default:
    cerr << "Unknown ordering algorithm" << endl;
    break;
  }

  time_t t2 = time(NULL);
  Clock::time_point ct1 = Clock::now();
  milliseconds ms = std::chrono::duration_cast<milliseconds>(ct1 - ct0);
  cout << "========================================" << endl;
  print_array(A, N, "Array ordinato");
  print_array_graph(A, N, "Array Ordinato");
  cout << "========================================" << endl;
  cout << "Tempo richiesto ordinamento = " << (double)difftime(t2,t1) << " secondi" << endl;
  cout << "Tempo richiesto ordinamento = " <<  ms.count() << "ms" << endl;
  cout << "========================================" << endl;

  delete [] A;

  // se abbiamo usato merge sort, aux e' diverso da NULL e occorre
  // deallocare memoria.
  if (aux != NULL) delete [] aux;
}

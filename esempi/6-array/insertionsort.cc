void insertionsort(int A[], int N) {
  for(int i = N-1; i > 0; i--)
    if (A[i] < A[i-1]) {
      swap(A[i],A[i-1]);
    }

  for(int i = 2; i <= N-1; i++) {
    int j = i;
    int v = A[i];
    while(v < A[j-1]) {
      A[j] = A[j-1]; j--;
    }
    A[j] = v;
  }
}

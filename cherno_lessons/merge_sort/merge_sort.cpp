#include <iostream>
using namespace std;

void merge(int A[], int p, int q, int r) {
  int nL = q - p + 1;
  int nR = r - q;
  int L[nL], R[nR];
  
  for (int i = 0; i < nL; i++) {
    L[i] = A[p + i];
  }
  
  for (int j = 0; j < nR; j++) {
    R[j] = A[q + j + 1];
  }
  
  int i = 0;
  int j = 0;
  int k = p;
 
  while (i < nL && j < nR) {
    if (L[i] <= R[j]) {
      A[k] = L[i];
      i += 1;
    }
    else {
      A[k] = R[j];
      j += 1;
    }
    k += 1;
  }
  
  while (i < nL) {
    A[k] = L[i];
    i += 1;
    k += 1;
  }
  
  while (j < nR) {
    A[k] = R[j];
    j += 1;
    k += 1;
  }
}

void merge_sort(int A[], int p, int r) {
  if (p < r) {
    int q = p + (r - p) / 2;
    merge_sort(A, p, q);
    merge_sort(A, q + 1, r);

    merge(A, p, q, r);
  }
}

int main() {
  int A[] = {13, 43, 12, 0, 2, 4, 4, 12, 9, 10, 10, 23, 7, 6, 8, 5, 10, 13};
  int A_size = sizeof(A) / sizeof(A[0]);
  
  cout << "input unsorted A: " << endl;
  for (int i = 0; i < A_size; i++) {
    cout << A[i] << ", ";
  }
  
  cout << endl;
  merge_sort(A, 0, A_size - 1);
  
  cout << "output sorted A: " << endl;
  for (int i = 0; i < A_size; i++) {
    cout << A[i] << ", ";
  }
  
  return 0;
}

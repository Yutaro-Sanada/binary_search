#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m){
    int i = 0;
    int x = 1;
    int y = 0;
    for (i = 0; i < n; i++){
      if (A[i] > m) return 0;
      y = y + A[i];
      if (y > m){
        y = A[i];
        x = x + 1;
      }
    }
    return x <= k;
}


int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  
  lb = 0;
  ub = 1000000000;
  while(ub - lb > 1){
      unsigned int m = (lb + ub) / 2;
      if (p(m)) ub = m;
      else lb = m;
  }
  printf("%d\n", ub);
  return 0;
}

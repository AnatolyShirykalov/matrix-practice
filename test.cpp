#include "vstv.h"
int main(int argc, char** argv){
  matrix*A,*AT, *G; int m,n;
  if (argc<3){printf("%s <m> <n>\n", argv[0]); return 0;}
  m = atoi(argv[1]);
  n = atoi(argv[2]);
  A=new_matrix(atoi(argv[1]),atoi(argv[2]));
  print_matrix(fill_matrix(A));
  printf("\n");
  AT=trans_matrix(A);
  print_matrix(AT); 
  printf("\n");
  G=multi_matrix(A,AT);
  print_matrix(G); 
  printf("\n");
  print_matrix(gauss_matrix(G));
  printf("\n");
  kill_matrix(G);
  kill_matrix(AT);
  kill_matrix(A);
  return 0;
}

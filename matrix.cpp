#include "vstv.h"
#define inside int m,n; double*A;  n=(b->n);  m=(b->m);  A=(b->a);
matrix* new_matrix(int m, int n){
  matrix*mat;
  mat=(matrix*)malloc(sizeof(matrix));
  mat->a=(double*)malloc(m*n*sizeof(double));
  mat->m=m;  
  mat->n=n;  
  return mat;
}
matrix* kill_matrix(matrix*b){
  free(b->a);
  free(b);
  return NULL;
}
int print_matrix(matrix*A){
  int i,j;
  for (i=0;i<(A->m);i++){
    for (j=0;j<(A->n);j++){
      printf("%e",(A->a)[i*(A->n)+j]);
      if (j!=(A->n)-1) printf(",");
    }
    printf("\n");
  }
  return 0;
}


matrix* fill_matrix(matrix*b){
  int i,j;
  inside
  srand(time(0));
  for (i=0;i<m*n;i++){
  A[i] = (double)rand()/RAND_MAX;
  }
  return b;
}

matrix* trans_matrix(matrix*b){
  int i,j;
  matrix* bt;
  inside
  bt = new_matrix(n,m);
  for (i=0;i<n;i++)
    for (j=0;j<m;j++)
      (bt->a)[i*m+j]=A[j*n+i];
  return bt;
}

matrix* multi_matrix(matrix*a,matrix*b){
  int i,j,k;
  matrix*c;
  if ((a->n)!=(b->m)) return NULL;
  c = new_matrix(a->m,b->n);
  for (i=0;i<(c->m);i++)
    for (j=0;j<(c->n);j++)
      for (k=0,(c->a)[i*(c->n)+j]=0;k<(a->n);k++)
	(c->a)[i*(c->n)+j]+=(a->a)[i*(a->n)+k]*(b->a)[k*(b->n)+j];
  return c;  
}

matrix *swap_matrix(matrix *b,int i,int j){
  int k;
  inside
  for(k=0;k<n;k++){
    A[i*n+k]-=A[j*n+k];
    A[j*n+k]+=A[i*n+k];
    A[i*n+k]=A[j*n+k] - A[i*n+k];
  }
 return b;
}

matrix *elem1_matrix(matrix *b,int i,int j,double x){// a_i+=a_j*x
  int k;
  inside
  for (k=0;k<n; k++) A[i*n+k] += A[j*n+k] * x;
  return b;
}
matrix *elem2_matrix(matrix *b,int i,double x){
  int k;
  inside
  for (k=0;k<n;k++) A[i*n+k] *= x;
  return b;
}

matrix *gauss_matrix(matrix *b){
  int i,j,k,l,i_max; double max;
  inside
  for (k=0,l=0; k<n && l<m; k++){
    for (i=l,max=0; i<m;i++)
      if (fabs(A[i*n+k])>max ){
	max = fabs(A[i*n+k]); 
	i_max = i;
      }
    if (max<EVK_MIN)  continue;
    if (i_max!=l) swap_matrix(b,l,i_max);
    elem2_matrix(b,l,1/A[l*n+k]);
    for (i=l+1;i<m;i++){
      elem1_matrix(b,i,l,-A[i*n+k]);
    }
    l++;
  }
  return b;
}

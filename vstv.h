#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define EVK_MIN 1e-15
typedef struct matrix_{
int m,n;
double *a;
}matrix;
matrix* new_matrix(int m, int n);
matrix* kill_matrix(matrix*b);
int print_matrix(matrix*A);
matrix* fill_matrix(matrix*b);
matrix* trans_matrix(matrix*b);
matrix* multi_matrix(matrix*a,matrix*b);
matrix *swap_matrix(matrix *b,int i,int j);
matrix *elem1_matrix(matrix *b,int i,int j,double x);
matrix *elem2_matrix(matrix *b,int i,double x);
matrix *gauss_matrix(matrix *b);

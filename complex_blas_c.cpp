#include<cblas.h>
#include<complex.h>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<cstdlib>
#include<gc.h>
#define VR_MALLOC(x) GC_MALLOC(x)
#define VR_FREE(x) GC_FREE(x)
typedef double complex double_complex;

char* testC(int iter) {
const int m = 1000;
const int n = 1000;
const int k = 500;
char str[100];
double sum=0;
for(int j = 0; j < 10; j++) {
clock_t t1 = clock();
for(int  i = 0; i < iter; i++) {
double_complex *arr1 =  (double_complex*)VR_MALLOC(sizeof(double_complex)*m*k);
double_complex *arr2 =  (double_complex*)VR_MALLOC(sizeof(double_complex)*k*n);
double_complex *arr3 =  (double_complex*)VR_MALLOC(sizeof(double_complex)*m*n);
	for(int i=0;i<m;i++){
		for(int j = 0;  j< k; j++) {
				arr1[j*m +i] = 1 + 0*I;	
				arr2[j*k +i] = 1+ 0*I;	
				arr3[j*k +i] = 0;	
		}
	}
//VR_FREE(arr1);
//VR_FREE(arr2);
//VR_FREE(arr3);
}
t1 =  clock() - t1;
sum += (double)t1/CLOCKS_PER_SEC;
}
printf(" gc time = %f \n",sum/10);
sum=0;
for(int j = 0; j < 10; j++) {
clock_t t1 = clock();
for(int  i = 0; i < iter; i++) {
double_complex *arr1 =  (double_complex*)malloc(sizeof(double_complex)*m*k);
double_complex *arr2 =  (double_complex*)malloc(sizeof(double_complex)*k*n);
double_complex *arr3 =  (double_complex*)malloc(sizeof(double_complex)*m*n);
	for(int i=0;i<m;i++){
		for(int j = 0;  j< k; j++) {
				arr1[j*m +i] = 1 + 0*I;	
				arr2[j*k +i] = 1+ 0*I;	
				arr3[j*k +i] = 0;	
		}
	}
free(arr1);
free(arr1);
free(arr2);
//VR_FREE(arr3);
//VR_FREE(arr2);
//VR_FREE(arr3);
}
t1 =  clock() - t1;
sum += (double)t1/CLOCKS_PER_SEC;
}
printf(" malloc time = %f \n",sum/10);
}
int main(int argc , char*argv[]){
int iter = atoi(argv[1]);
char * str =testC(iter);
/*printf("\n");
for(int i=0;i<k;i++){
	for(int j = 0;  j< n; j++) {
		//new (&arr5[2*(j*m +i)])double(i+j);	
		//new (&arr5[2*(j*m+i)+1])double(j+i);
		//printf("%.3f + %.3fi ",std::real(arr2[j*m +i]),std::imag(arr2[j*m + i]));
	}
}
for(int i=0;i<k;i++){
	for(int j = 0;  j< n; j++) {
	//	new (&arr6[2*(j*m +i)])double(1);	
	//	new (&arr6[2*(j*m+i)+1])double(1);
	//	printf("%.3f + %.3fi ",std::real(arr1[j*m +i]),std::imag(arr1[j*m + i]));
	}
}
double a[2] ={1,0};
double b[2] = {0,0};
//cblas_zgemm(CblasColMajor,CblasNoTrans,CblasNoTrans,m,n,l,reinterpret_cast<double*>( new double_complex(1,0)),reinterpret_cast<double*>(arr1),m,reinterpret_cast<double*>(arr2),l,reinterpret_cast<double*>( new double_complex(0,0)),reinterpret_cast<double*>(arr3),m);
printf("starting clock\n");
clock_t t1 = clock();
for(int i =0; i <iter; i++) {
cblas_zgemm(CblasColMajor,CblasNoTrans,CblasNoTrans,m,n,k,a,reinterpret_cast<double*>(arr1),m,reinterpret_cast<double*>(arr2),k,b,reinterpret_cast<double*>(arr3),m);
}
t1 =  clock() - t1;
printf("time = %f \n",(double)t1/CLOCKS_PER_SEC);
*/
  /*for(int i=0;i<m;i++){
		printf("\n");
   for(int j = 0; j < n; j++) { 
    	//printf("%.3f + %.3fi ",arr6[2*(i + j*m)],arr6[2*(i+ j*m)+1]);
    	//printf("%.3f + %.3fi ",std::real(arr3[(i + j*m)]),std::imag(arr3[(i+ j*m)]));
	}
  }
*/
}

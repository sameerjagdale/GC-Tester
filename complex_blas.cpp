#include<cblas.h>
#include<complex>
#include<complex.h>
#include<stdio.h>
#include<stdlib.h>
#include<cstdlib>
#include<gc.h>
#include "vr_data.hpp"
#include<boost/shared_array.hpp>
using boost::shared_array;
#define VR_MALLOC(x) GC_MALLOC(x)
#define VR_FREE(x) GC_FREE(x)
//#define VR_MALLOC(x) malloc(x)
//#define VR_FREE(x) free(x)
typedef std::complex<double> double_complex;

const int m = 1000;
const int n = 1000;
const int k = 500;
void testGC(int iter) {
double sum = 0;
double_complex *arr =  (double_complex*)VR_MALLOC(sizeof(double_complex)*(m*k));
double_complex *arr2 =  (double_complex*)VR_MALLOC(sizeof(double_complex)*(k*n));
double_complex *arr3 =  (double_complex*)VR_MALLOC(sizeof(double_complex)*(m*n));
for(int j = 0; j < 10;j++) {
clock_t t1 = clock();
for(int  i = 0; i < iter; i++) {
//shared_array<double_complex> arr(new double_complex[m*k]);
//shared_array<double_complex> arr2(new double_complex[(k*n)]);
//shared_array<double_complex> arr3(new double_complex[(m*n)]);
//double_complex *arr3 =  (double_complex*)VR_MALLOC(sizeof(double_complex)*(m*n));
for(int i=0;i<m;i++){
	for(int j = 0;  j< k; j++) {
		arr2[j*m +i] = double_complex(1,0);	
		arr[j*m +i] = double_complex(1,0);	
		arr3[j*m +i] = double_complex(1,0);	
		//printf("%.3f + %.3fi ",std::real(arr2[j*m +i]),std::imag(arr2[j*m + i]));
	}
}
//VR_FREE(arr);
//VR_FREE(arr2);
//VR_FREE(arr3);
}
t1 =  clock() - t1;
sum += (double)t1/CLOCKS_PER_SEC;
}
printf("GC time = %f \n",sum/10);
}

void testShared(int iter) {
double sum = 0;
shared_array<double_complex> arr(new double_complex[m*k]);
shared_array<double_complex> arr2(new double_complex[(k*n)]);
shared_array<double_complex> arr3(new double_complex[(m*n)]);
for(int j = 0; j < 10; j++) {
clock_t t1 = clock();
for(int  i = 0; i < iter; i++) {
//double_complex *arr =  (double_complex*)VR_MALLOC(sizeof(double_complex)*(m*k));
//double_complex *arr2 =  (double_complex*)VR_MALLOC(sizeof(double_complex)*(k*n));
//double_complex *arr3 =  (double_complex*)VR_MALLOC(sizeof(double_complex)*(m*n));
//double_complex *arr3 =  (double_complex*)VR_MALLOC(sizeof(double_complex)*(m*n));
for(int i=0;i<m;i++){
	for(int j = 0;  j< k; j++) {
		arr2[j*m +i] = double_complex(1,0);	
		arr[j*m +i] = double_complex(1,0);	
		arr3[j*m +i] = double_complex(1,0);	
		//printf("%.3f + %.3fi ",std::real(arr2[j*m +i]),std::imag(arr2[j*m + i]));
	}
}
//free(arr1);
//free(arr2);
//free(arr3);
}
t1 =  clock() - t1;
sum += (double)t1/CLOCKS_PER_SEC;
}
printf("Shared Array time = %f \n",sum/10);
}
VrArrayF64 testStruct(int iter) {
	const int numel = 1000000;
	double *data = static_cast<double*>(GC_MALLOC(sizeof(double)*numel));
	int * dims = static_cast<int*>(GC_MALLOC(sizeof(int)*2));
	dims[0] = 1000;
	dims[1] = 1000;
	VrArrayF64 A(data,dims,2);
	VrArrayF64 B(A);
	for(int i = 0; i < 100; i++) {
		A.data[i] = rand();	
		B.data[i] = rand();
	} 	
	VrArrayF64 E;
	clock_t t1 = clock();
	for(int i = 0; i < iter; i++) { 
		VrArrayF64 C = A*B;	
		VrArrayF64 D = C + B;
		E = A - D;
		A = B-C;
		B = D+B;
	}
	t1 = clock() - t1;
	printf("time  = %f\n", (double) t1/CLOCKS_PER_SEC);
	return E;	
}
int main(int argc, char*argv[]){
	if(argc < 2) {
		printf("number of iterations not provided");
		exit(0);
	}
	//testGC(atoi(argv[1]));
	//testShared(atoi(argv[1]));
	int iter = atoi(argv[1]);
VrArrayF64 X;
	for(int i = 0; i < 10; i++) {
		 X = testStruct(iter);
	}
	for(int i = 0; i < 100; i++) {
		//printf("%f\n", X.data[i]);
	} 
}

#ifndef __VR_DATA_H__
#define __VR_DATA_H__
#include "string.h"
#include <complex>
#include<cstdlib>
#include<boost/shared_array.hpp>
using boost::shared_array;
using namespace std;
typedef int dim_type;
typedef enum Layout{
  COLUMN_MAJOR,ROW_MAJOR
}Layout;

 class VrArrayF64{
public:
  shared_array<double> data;
  shared_array<int> dims;  
  int ndims;
  VrArrayF64(){
    //data=NULL;
    //dims=NULL;
    ndims=0;
  }
  int getNumel(const VrArrayF64 & A) {
		int numel = 1;
		for(int i = 0; i < A.ndims; i++) {
			numel *= A.dims[i];
		}
		return numel;
  } 
  VrArrayF64(const VrArrayF64& A) {
		int numel = getNumel(A);
		this->data = shared_array<double>(new double[numel]);
		memcpy(this->data.get(),A.data.get(),sizeof(double)*numel);
		this->dims  = shared_array<int>(new int [numel]);
		memcpy(this->dims.get(),A.dims.get(),sizeof(int)*A.ndims);
		ndims = A.ndims;
  }

  VrArrayF64(shared_array<double> data, shared_array<int> dims, int ndims ):data(data),dims(dims),ndims(ndims) {
  }

  VrArrayF64(double scal) :ndims(2) {
  	/*data = static_cast<double*>(malloc(sizeof(double)));
	*data = scal;
	dims  = static_cast<dim_type*>(malloc(sizeof(dim_type)*2));
	dims[0] = 1;
	dims[1] = 1;
	*/
  }
  VrArrayF64 operator+(VrArrayF64 A) {
		VrArrayF64 X(A);
		for(int i = 0; i < getNumel(A); i++) {
			X.data[i] = A.data[i] + data[i];
		}
		return X;
  }
  VrArrayF64 operator-(VrArrayF64 A) {
		VrArrayF64 X(A);
		for(int i = 0; i < getNumel(A); i++) {
			X.data[i] = A.data[i] - data[i];
		}
		return X;
  }
  VrArrayF64 operator*(VrArrayF64 A) {
		VrArrayF64 X(A);
		for(int i = 0; i < getNumel(A); i++) {
			X.data[i] = A.data[i] *  data[i];
		}
		return X;
  }
  VrArrayF64 operator/(VrArrayF64 A) {
		VrArrayF64 X(A);
		for(int i = 0; i < getNumel(A); i++) {
			X.data[i] =  data[i] / A.data[i];
		}
		return X;
  }
};
#endif

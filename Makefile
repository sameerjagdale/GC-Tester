all: cpp c 
cpp :
	g++  -ocomplex_cpp complex_blas.cpp -I /home/sable/sjagda/open_blas/include/ -I ~/boehmgc/include/ ~/open_blas/lib/libopenblas.so ~/boehmgc/lib/libgc.so -std=c++0x
c :
	g++ -ocomplex_c complex_blas_c.cpp -I /home/sable/sjagda/open_blas/include/ -I ~/boehmgc/include/ ~/open_blas/lib/libopenblas.so ~/boehmgc/lib/libgc.so

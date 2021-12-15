#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <omp.h>
#include <random>
#include <iostream>
#include <chrono>

using namespace std;


int main(int argc, char *argv[]){

	int rank, size; 
	MPI_Status status;
	MPI_Init(&argc, &argv);
  	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	
	int arr_len = atoi(argv[1]);
	
	srand(time(0));
	double resul_arr[arr_len][arr_len];
	double d;
	int m;
	double input_arr[arr_len+2][arr_len+2];	
	
	for(int i=0; i<arr_len+2; i++){// add two extra row and two extra column in border
		for(int j=0; j<arr_len+2; j++){
			if(i==0 || i==arr_len+1 || j==0 || j==arr_len+1 ){
				input_arr[i][j] = 0;//fill borders with zero	
			}else{
				input_arr[i][j] = rand()%10+1;	
			}
		}	
	}
	
	for (int i = 0; i < arr_len+2; i++){
                for (int j = 0; j < arr_len+2; j++)
                {
                    cout << input_arr[i][j] << " ";
                }
                cout <<endl;
            }
        
	
	
	MPI_Bcast(&(input_arr[0][0]), arr_len*arr_len, MPI_FLOAT, 0, MPI_COMM_WORLD);
	auto start = std::chrono::high_resolution_clock::now();
	//divide rule
	/*int up,down,right,left;
	if(){
		
	}
	else if{
	
	}
	else{
	
	}*/
	
		//MPI_Bcast(&(input_array[0][0]), arr_len*arr_len, MPI_FLOAT, 0, 0, MPI_COMM_WORLD, &status);
	
	
	MPI_Barrier(MPI_COMM_WORLD);
	 
	

//#pragma omp parallel for
	//logic


	//MPI_Barrier(MPI_COMM_WORLD);
	
	


	
	
	MPI_Finalize(); 
	return 0;
}
	



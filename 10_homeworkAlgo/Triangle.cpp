//parts of code copied from https://www.geeksforgeeks.org/program-to-print-sum-arrangle-for-a-given-array/

#include <iostream>
using namespace std;
#define N 3
int MPS(int arr[N][N], int x);
int main(){
	int arr[N][N] = {   {1, 0, 0}, {4, 8, 0}, {1, 5, 3} };
	cout << MPS(arr, 2);
	return 0;
}

int MPS(int arr[N][N], int x){
	int Fpath [N][N]; //used to find the path

	//intialzation
	for (int i = 0; i < N; i++){
		for (int j =0; j < N; j++){
			Fpath[i][j]=arr[i][j];
		}
	}

	for (int i=x-1; i>=0; i--){
		for (int j=0; j<=i; j++){
			//finding the path fromeother the top right or the top left
			if (Fpath[i+1][j] > Fpath[i+1][j+1]){
				Fpath[i][j] += Fpath[i+1][j];
			} else {
				Fpath[i][j] += Fpath[i+1][j+1];
			}
		}
	}
	int j = 0;
	for (int i = 0; i < N; i++){
		//arr is used or printing purposes only
		cout<<arr[i][j]<<" ";
		if (Fpath[i+1][j] <  Fpath[i+1][j+1]){
			j++;
		}
	}

	cout<<endl;

	return Fpath[0][0];
}

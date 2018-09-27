//inspired from https://www.geeksforgeeks.org/construction-of-longest-increasing-subsequence-using-dynamic-programming/

#include <iostream>
#include <vector>

using namespace std;
void print(vector<int> arr);
void LOS(vector <int> arr, int n);

int main(){
	vector <int> arr;
	int x;
	cin>>x;
	//continue to read numbers as long as it is not negative
	while(x>0){
		//receive inputs till negative number is inputed.
		arr.push_back(x);
		cin>>x;
	}
	int n = arr.size();
	LOS(arr, n);
	return 0;
}

//printing function to print the vector which contains the subarray.
void print(vector<int> arr){
	for (auto x = arr.begin(); x != arr.end(); x++){
		cout << *x << " ";
	}
}

void LOS(vector <int> arr, int n)
{
	//vector of vectors
	vector<vector<int> > L(n);

	//using Tabulation to produce the LOS values in bottom up manner
	L[0].push_back(arr[0]);

	for (int i = 1; i < n; i++){
		for (int j = 0; j < i; j++){
			if ((arr[i] > arr[j]) && (L[i].size() < L[j].size() + 1)){
				L[i] = L[j];
			}
		}
		L[i].push_back(arr[i]);
	}
	vector<int> max = L[0];

	// LOS will be max of all increasing subsequences of arr
	for (vector<int> x : L){
	if (x.size() > max.size())
	max = x;
}
// max will contain LOS
print(max);
}

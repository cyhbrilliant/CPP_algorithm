#include <iostream>
using namespace std;

int Matrix[7] = {50, 10, 40, 30, 5, 20, 15};
int Save[6][6];
int Solution[6][6];


int MM(int begin, int end) {
	int low = 10000000;
	int index = 0;
 	for (int i = begin; i < end; i++) {
 		int F, B;
 		if (Save[begin][i] < 0) {
 			F = MM(begin, i);
 		}else {
 			F = Save[begin][i];
 		}
 		if (Save[i+1][end] < 0) {
 			B = MM(i+1, end);
 		}else {
 			B = Save[i+1][end];
 		}
 		
 		if (F+B+Matrix[begin]*Matrix[i+1]*Matrix[end+1] < low) {
 			low = F+B+Matrix[begin]*Matrix[i+1]*Matrix[end+1];
 			index = i;
 		} 
 		
 	}
 	Solution[begin][end] = index;
 	Save[begin][end] = low;
 	return low;
}

void getSolve(int begin, int end) {
	int index = Solution[begin][end];
	// cout << index << endl;
	if (begin != end) {
		cout << index << endl;
		getSolve(begin, index);
		getSolve(index+1, end);
	}

}

int main() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (i == j) {
				Save[i][j] = 0;

			}else {
				Save[i][j] = -1;
			}
			Solution[i][j] = 0;
		}  		
 	} 
	cout << MM(0, 5) << endl;
	getSolve(0, 5);
	// for (int i = 0; i < 6; i++) {
	// 	for (int j = 0; j < 6; j++) {
	// 		cout << Solution[i][j] << " ";

	// 	}  		
	// 	cout << endl;
 // 	} 


	return 0;
}
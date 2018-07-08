#include <iostream>
#include <vector>
using namespace std;

int X[5] = {1, 2, 3, 4, 5}; 
vector<int> list(X, X+5);
void Perm(vector<int> Tlist, int mid) {
	if (mid == Tlist.size()) {
		for (vector<int>::iterator it = Tlist.begin(); it != Tlist.end(); it++) {
			cout << *it << " ";
		}
		cout << endl;
	}
	for (int i = mid; i < Tlist.size(); i++) {
		vector<int> CTlist(Tlist);
		swap(CTlist[mid], CTlist[i]);
		// cout << i;
		Perm(CTlist, mid+1);
	}
}

int main() {
	Perm(list, 0);

	return 0;
}
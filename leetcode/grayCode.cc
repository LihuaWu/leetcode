#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

vector<int> grayCode(int n) {
	vector<int> result;
	result.reserve(1<<n);
	result.push_back(0);
	for(int i = 0; i < n; ++i) {
		const int high = 1 << i;
		for(int j = result.size() - 1; j >= 0; --j) {
			result.push_back(high | result[j]);
		}
	}
	return result;
}

int main() {
	vector<int> v = grayCode(4);
	for(int i = 0; i < v.size(); ++i) {
		int num = v[i];
		for(int j = 3; j >= 0; --j){
			bool digit = num>>j&0x1;
			cout<<digit<<"\t";
		}
		cout<<endl;
	}
	return 0;
}


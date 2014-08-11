#include <vector>
#include <algorithm>

#include <gtest/gtest.h>

using namespace std;

void rotateImage(vector<vector<int> >& v) {
	const int n = v.size();
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n-i; ++j) {
			//swap in terms of counter-diagnoal
			swap(v[i][j], v[n - 1 - j][n - 1 - i]);
		}
	}
	for(int i = 0; i < n/2; ++i) {
		for (int j = 0; j < n; ++j) {
			//swap in terms of horizon 
			swap(v[i][j], v[n - 1 - i][j]);
		}
	}
}

TEST (rotateImage, NormalCase) {
	int A[][2] = {1, 2, 3, 4}; 
	vector<vector<int> > v(2, vector<int>(2, 0));
	for(int i = 0; i < 2; ++i) {
		for(int j = 0; j < 2; ++j) {
			v[i][j] = A[i][j];
		}
	}
	rotateImage(v);
	for(int i = 0; i < v.size(); ++i) {
		for(int j = 0; j < v.size(); ++j) {
			cout<<v[i][j]<<" ";
		}
	}
	cout<<endl;
	EXPECT_EQ(1, 1);
}

int main(int argc, char** argv){
	
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

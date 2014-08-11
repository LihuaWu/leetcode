#include <algorithm>

#include <gtest/gtest.h>

using namespace std;

bool check(char c, vector<bool>& used) {
	if (c == '.') return true;
	if(used[c - '1']) return false;
	return used[c - '1'] = true;
}

bool validSudoku(const vector<vector<int> >&board){
	vector<bool> used(9, false);
	for(int i = 0; i < 9; ++i){
		//row
		for(int j = 0; j < 9; ++j){
			if(!check(board[i][j], used)) return false;
		}
		//column
		fill(used.begin(), used.end(), false);
		for(int j = 0; j < 9; ++j) {
			if(!check(board[j][i], used)) return false;
		}
	}
	for(int r = 0; r < 3; ++r) {
		for(int c = 0; c < 3; ++c) {
			fill(used.begin(), used.end(), false);
			for(int i = r * 3; i < r * 3 + 3; ++i) {
				for(int j = c * 3; j < c * 3 + 3; ++j) {
					if(!check(board[j][i], used)) return false;
				}
			}
		}
	}
	return true;
}

int main(int argc, char** argv){
	
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

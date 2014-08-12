#include <iostream>

using namespace std;

void setZeros(vector<vector<int> >& matrix) {
	const int row_len = matrix.size();
	const int col_len = matrix[0].size();

	bool row_zero = false, col_zero = false;

	for(int i = 0; i < row_len; ++i) {
		if (0 == matrix[i][0]) {
			row_zero = true;
			break;
		} 
	}

	for(int i = 0; i < col_len; ++i) {
		if (0 == matrix[0][i]) {
			col_zero = true;
			break;
		}
	}

	for(int i = 1; i < row_len; ++i) {
		for(int j = 1; j < col_len; ++j) {
			if (0 == matrix[i][j]) {
				matrix[i][0] = matrix[0][j] = 0;
			}
		}
	}

	for(int i = 1; i < row_len; ++i) {
		for(int j = 1; j < col_len; ++j) {
			if(matrix[i][0] == 0 || matrix[0][j] == 0) {
				matrix[i][j] = 0;
			}
		}
	}
	if(row_zero) {
		for(int i = 0; i < row_len; ++i) {
			matrix[0][i] = 0;
		}
	}
	if(col_zero) {
		for(int i = 0; i < col_len; ++i) {
			matrix[i][0] = 0;
		}
	}
}

int main(int argc, char** argv) {
	return 0;
}

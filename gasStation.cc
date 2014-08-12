#include <vector>

#include <gtest/gtest.h>

using namespace std;

int gasStation(const vector<int>& gas, const vector<int>& cost) {
	int total = 0;
	int start = -1;
	for(int i = 0, sum = 0; i < gas.size(); ++i) {
		sum += gas[i] - cost[i];
		total += gas[i] - cost[i];
		if(sum < 0) {
			start = i; 
			sum = 0;
		}
	}
	return total >= 0 ? start + 1 : -1;
}

TEST (gasStation, NormalCase) {
	int A[] = {2, 3, 4, 5, 3, 3};
	int B[] = {1, 2, 5, 3, 5, 3};
	vector<int> gas(A, A + sizeof(A)/sizeof(int));
	vector<int> cost(B, B + sizeof(B)/sizeof(int));

	int ret = gasStation(gas, cost);
	EXPECT_EQ(0, ret);
}

TEST (gasStation, NCase) {
	int A[] = {2, 3, 4, 5, 3, 3};
	int B[] = {1, 2, 7, 2, 5, 3};
	vector<int> gas(A, A + sizeof(A)/sizeof(int));
	vector<int> cost(B, B + sizeof(B)/sizeof(int));

	int ret = gasStation(gas, cost);
	EXPECT_EQ(3, ret);
}

TEST (gasStation, 3Case) {
	int A[] = {2, 3, 4, 4, 3, 3};
	int B[] = {1, 2, 7, 2, 5, 3};
	vector<int> gas(A, A + sizeof(A)/sizeof(int));
	vector<int> cost(B, B + sizeof(B)/sizeof(int));

	int ret = gasStation(gas, cost);
	EXPECT_EQ(-1, ret);
}

int main(int argc, char** argv){
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

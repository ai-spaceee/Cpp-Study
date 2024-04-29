#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
int main() {
	int N, K;
	cin >> N >> K;
	vector<int> arr;
	arr.reserve(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	vector<int> price;
	price.reserve(N-1);
	for (int i = 0; i < N - 1; i++) {
		price.push_back(arr[i + 1] - arr[i]);
	}
	int sum = accumulate(price.begin(), price.end(), 0);
	sort(price.rbegin(), price.rend());
	for (int i = 0; i < K-1; i++) {
		sum = sum - price[i];
	}
	cout << sum;
	//벨류를 전체 차이에서 뺀다!
}
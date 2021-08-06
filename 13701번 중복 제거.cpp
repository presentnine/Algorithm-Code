#include <iostream>

using namespace std;

int check[1 << 20] = { 0, };

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int A, index, value;

	while (cin >> A) {
		index = A / 32;
		value = 1 << (A % 32);

		if (!(check[index] & value)) {
			check[index] |= value;
			cout << A << " ";
		}
	}

	return 0;
}
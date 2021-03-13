#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {
	long long N, K;
	long long count = 0;
	long long quotient, remainder;
	long long start;
	int ans;

	cin >> N >> K;

	while (K>(long long)9*pow(10, count)*(count+1)) {
		K -= 9 * pow(10, count) * (count + 1);
		count++;
	}

	quotient = K / (count + 1);
	remainder = K - quotient * (count + 1);
	start = pow(10, count);

	if (remainder == 0) {//나머지가 0인 경우
		start += quotient - 1;
		if (N < start)
			ans = -1;
		else
			ans = start - (start / 10) * 10;
			
	}
	else {//나머지가 0이 아닌 경우
		start += quotient;
		if (N < start)
			ans = -1;
		else {
			string num = to_string(start);
			ans = num[remainder - 1] - '0';
		}
	}

	cout << ans;

	return 0;
}
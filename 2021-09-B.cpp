#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 5e5 + 10;
int arr[maxn];
int update[maxn];
int sum[maxn];
int main()
{
	int t = 0;
	cin >> t;
	int start = 0;
	memset(arr, 0, sizeof(arr));
	memset(update, 0, sizeof(update));
	memset(sum, 0, sizeof(sum));
	for (int i = 1; i <= t; ++i)
	{
		cin >> arr[i];
		if (arr[i] <= 0 && arr[i - 1] > 0)
			++start;
	}

	if (arr[t] > 0)
		++start;

	for (int i = 1; i <= t; ++i)
	{
		if (0 == arr[i])
			continue;
		if (arr[i] < arr[i - 1] && arr[i + 1] > arr[i])
			++update[arr[i] + 1];
		if (arr[i] < arr[i - 1] && arr[i + 1] == arr[i])
		{
			while (arr[i + 1] == arr[i])
				++i;
			if (arr[i + 1] > arr[i])
				++update[arr[i] + 1];
		}
		if (arr[i] > arr[i - 1] && arr[i + 1] < arr[i])
			--update[arr[i] + 1];
		if (arr[i] > arr[i - 1] && arr[i + 1] == arr[i])
		{
			while (arr[i + 1] == arr[i])
				++i;
			if (arr[i + 1] < arr[i])
				--update[arr[i] + 1];
		}
	}

	int res = 0;
	for (int i = 2; i <= 1e4; ++i)
	{
		sum[i] = sum[i - 1] + update[i];
		res = max(sum[i], res);
	}

	cout << res + start;

	return 0;
}

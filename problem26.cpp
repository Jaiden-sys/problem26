#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int* generatearray(int n)
{
	int* arr = new int [n];
	

	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % n;
	}
	cout << "\n";
	return arr;
}

void deletearr(int* arr)
{
	delete [] arr;
	cout << "Array deleted" << "\n";
}


int* merge_sort(int* up, int* down, unsigned left, unsigned right)
{
	if (left == right) { down[left] = up[left]; return down; }

	unsigned int middle = left + (right - left) / 2;

	int* l_buff = merge_sort(up, down, left, middle);
	int* r_buff = merge_sort(up, down, middle + 1, right);

	int* target = (l_buff == up) ? down : up;

	unsigned int l_cur = left, r_cur = middle + 1;
	for (unsigned int i = left; i <= right; i++)
	{
		if (l_cur <= middle && r_cur <= right) {
			if (l_buff[l_cur] < r_buff[r_cur]) {
				target[i] = l_buff[l_cur];
				l_cur++;
			}
			else {
				target[i] = r_buff[r_cur];
				r_cur++;
			}
		}
		else if (l_cur <= middle) {
			target[i] = l_buff[l_cur];
			l_cur++;
		}
		else {
			target[i] = r_buff[r_cur];
			r_cur++;
		}
	}
	return target;

}


int* findmax(int* arr, int n) {
	int* sort_arr = new int[n];
	for (int i = 0; i < n; ++i) {
		sort_arr[i] = arr[i];
	}

	int* buffer = new int[n];
	merge_sort(sort_arr, buffer, 0, n - 1);
	delete[] buffer;

	int* result = new int[n];

	for (int i = n - 1; i > 0; --i) {
		if (sort_arr[i] == sort_arr[i - 1]) {
			result[i] = sort_arr[i];
			break;
		}
	}

	/*if (result != -1) {
		cout << "Max repeating element: " << result << endl;
	}
	else {
		cout << "No repeating elements found." << endl;
	}
	*/
	delete[] sort_arr;
	return result;
}

int main()
{
	int seed = time(NULL);
	srand(seed);
	int n;
	cin >> n;
	int* arr = new int [n];
	arr = generatearray(n);
	findmax(arr, n);
	deletearr(arr);

}
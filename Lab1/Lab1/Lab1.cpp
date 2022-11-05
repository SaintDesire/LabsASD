#include <stdio.h>
#include <iostream>
using namespace std;

void hanoi(int n, int i, int k);

int main() {
	setlocale(LC_ALL, "rus");
	int N;
	int K;
	cout << "Введите кол-во колец: "; cin >> N;
	if (N <= 0) {
		cout << "Ошибка ввода!" << endl;
		return 1;
	}
	cout << "Введите на какой стержень будет перекинут первый диск (2-3): "; cin >> K;
	if (K < 2 || K >3) {
		cout << "Ошибка ввода!" << endl;
		return 1;
	}
	hanoi(N, 1, K);

	return 0;
}

void hanoi(int n, int i, int k) {
	if (n == 1)
		printf("Переместить диск 1 с %d на %d стержень.\n", i, k);
	else {
		int tmp = 6 - i - k;
		hanoi(n - 1, i, tmp);
		printf("Переместить диск %d с %d на %d стержень.\n", n, i, k);
		hanoi(n - 1, tmp, k);
	}
}
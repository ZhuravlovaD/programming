#include <iostream>
using namespace std;

void sort(int* massive, int howmany) {
	int counter = 0;
	for(int i = 1; i < howmany; i++) {
		for (int j = i; j > 0 && massive[j - 1] > massive[j]; j--) {
			counter++;
			int tmp = massive[j - 1];
			massive[j - 1] = massive[j];
			massive[j] = tmp;
		}
	}
}

int* create(int howmany, int startingElem, int stepIn) {
	int* massive = new int[howmany];
	*massive = startingElem;
	for (int i = 1; i < howmany; i++)
	{
		massive[i] = massive[i - 1] + stepIn;
	}
	sort(massive, howmany);
	return massive;
}

void print(int* massive, int howmany) {
	cout << "array = ";
	for (int count = 0; count < howmany; count++)
		cout << massive[count] << "    ";
}

int main() {
	setlocale(LC_ALL, "Rus");
	int howmany, startingElem = 0, stepIn = 0;

	cout << "Введите колличество элементов массива: ";
	cin >> howmany;

	cout << "Введите начальныый элемент массива: ";
	cin >> startingElem;

	cout << "Введите шаг прогрессии: ";
	cin >> stepIn;

	int* newArray = create(howmany, startingElem, stepIn);
	print(newArray, howmany);
	delete[] newArray;
}
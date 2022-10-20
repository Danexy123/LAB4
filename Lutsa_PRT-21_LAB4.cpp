#include <iostream>
#include<ctime>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	const int SIZE = 100;

	static int arr1[SIZE], arr2[SIZE];
	int k, n;

	bool Yslovie;

	cout << "Введите длину массива: ";
	cin >> n;

	for (int i = 0; i < n; )
	{
		Yslovie = false;
		int newRand = rand() % 50;

		for (int j = 0; j < i; j++)
		{
			if (arr1[j] == newRand)
			{
				Yslovie = true;
				break;
			}
		}

		if (!Yslovie)
		{
			arr1[i] = newRand;
			i++;
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << arr1[i] << "\t";
	}

	cout << "\n\nВведите элемент, котрый нужно удалить: ";
	cin >> k;

	k--;
	bool vixod = false;

	for (int i = 0; i < n; i++)
	{
		if (k > i)
		{
			arr2[i] = arr1[i];
			cout << arr2[i] << "\t";
		}
		else
		{
			for (int j = k; j < n; j++)
			{
				if (j != (n - 1))
				{
					arr2[j] = arr1[j + 1];
					cout << arr2[j] << "\t";
				}
				else
				{
					vixod = true;
					break;
				}
			}
		}

		if (vixod)
		{
			break;
		}
	}
	cout << "\n\nМассив без четных элементов:\n";
	for (int i = 0; i < n; i++)
	{
		if (arr2[i] % 2 == 0)
		{
			arr2[i] = 0;
		}
		if (i == (n - 1))
		{
			break;
		}
		cout << arr2[i] << "\t";

	}
	return 0;
}
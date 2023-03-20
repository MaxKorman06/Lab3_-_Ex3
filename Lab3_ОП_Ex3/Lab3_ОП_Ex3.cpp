#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

void let_arr(char*);
int num_arr(char*);
void del_arr_wrd(char*);

int main()
{
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "ru");
	int wrd = 0;
	char arr_c[100];
	cout << "Введіть текстовий рядок довжиною не більше 100 символів\n";
	cin.get(arr_c, 100); // Оператор cin бачить лише символи до першого enter або пробілу тому використовуєм метод get функції cin 
	cout << "\nКількість цифр у набраному вище рядку: " << num_arr(arr_c) << "\n\n";
	cout << "Слова що починаються з приголосних літер: \n";
	let_arr(arr_c);
	for (size_t i = 0; i < strlen(arr_c); i++)
	{
		if ((arr_c[i] == ' ') && (arr_c[i + 1] != ' '))
		{
			wrd +=1;
		}
		if ((arr_c[i] == ' ') && ((int(arr_c[i + 1]) >= 66 && int(arr_c[i + 1]) <= 68) || (int(arr_c[i + 1]) >= 74 && int(arr_c[i + 1]) <= 78) || (int(arr_c[i + 1]) >= 80 && int(arr_c[i + 1]) <= 84) || (int(arr_c[i + 1]) >= 86 && int(arr_c[i + 1]) <= 90) || (int(arr_c[i + 1]) >= 98 && int(arr_c[i + 1]) <= 100) || (int(arr_c[i + 1]) >= 102 && int(arr_c[i + 1]) <= 104) || (int(arr_c[i + 1]) >= 106 && int(arr_c[i + 1]) <= 110) || (int(arr_c[i + 1]) >= 112 && int(arr_c[i + 1]) <= 116) || (int(arr_c[i + 1]) >= 118 && int(arr_c[i + 1]) <= 122)))
		{
			int p = i;
			for (; arr_c[i + 1] != ' '; i++)
			{
				if (arr_c[i + 1] == '\0')
				{
					break;
				}
				cout << arr_c[i + 1];
			}
			i = p;
			cout << ' ';
		}
	}
	if (arr_c[0] != ' ')
	{
		wrd += 1;
	}
	cout << "\n\nВведена строка тексту: \n" << arr_c;
	del_arr_wrd(arr_c);
	cout << "\n\nВідредагована за умовою завдання строка тексту: \n" << arr_c;
	cout << "\n\nКількість введених слів: " << wrd << '\n';

}

void let_arr(char arr_c[])
{
	if ((int(arr_c[0]) >= 66 && int(arr_c[0]) <= 68) || (int(arr_c[0]) >= 70 && int(arr_c[0]) <= 72) || (int(arr_c[0]) >= 74 && int(arr_c[0]) <= 78) || (int(arr_c[0]) >= 80 && int(arr_c[0]) <= 84) || (int(arr_c[0]) >= 86 && int(arr_c[0]) <= 90) || (int(arr_c[0]) >= 98 && int(arr_c[0]) <= 100) || (int(arr_c[0]) >= 102 && int(arr_c[0]) <= 104) || (int(arr_c[0]) >= 106 && int(arr_c[0]) <= 110) || (int(arr_c[0]) >= 112 && int(arr_c[0]) <= 116) || (int(arr_c[0]) >= 118 && int(arr_c[0]) <= 122))
	{
		int help = 0;
		for (size_t i = 0; i < strlen(arr_c) - 1; i++)
		{
			if (arr_c[i] == ' ')
			{
				help++;
			}
		}
		if (help > 0)
		{
			for (size_t i = 0; arr_c[i] != ' '; i++)
			{
				cout << arr_c[i];
			}
		}
		else
		{
			for (size_t i = 0; arr_c[i] != '\0'; i++)
			{
				cout << arr_c[i];
			}
		}
		cout << ' ';
	}
}

int num_arr(char arr_c[])
{
	int num = 0;
	for (size_t i = 0; arr_c[i] != '\0'; i++)
	{
		if (arr_c[i] <= 57 && arr_c[i] >= 48)
		{
			++num;
		}
	}
	return num;
}

void del_arr_wrd(char arr_c[])
{
	for (size_t i = 0; i < strlen(arr_c); i++)
	{
		int wrd_h = 0;
		if (arr_c[i] == ' ')
		{
			int l, p = i;
			for (; arr_c[i + 1] != ' '; i++)
			{
				wrd_h++;
				if (arr_c[i + 2] == '\0')
				{
					wrd_h--;
					break;
				}

			}
			i = p;
			if ((arr_c[i] == ' ') && (arr_c[i + 1] == arr_c[i + wrd_h]))
			{
				int k = i;
				for (; arr_c[i + 1] != ' '; i++)
				{
					arr_c[i + 1] = ' ';
				}
				i = k;
			}
		}
	}
}
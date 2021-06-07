// Напишите программу - игру типа угадай число

#include <iostream>
#include <ctime>

using namespace std;

int GetRandomNumber() // генерируем случайное число от 1 до 100
{
	srand(time(0));

	int value = 1 + rand() % + 100;

	return value;
}

int GetUserNumber() // проверка ввода
{
	int buf = 0;

	cin >> buf;

	if (buf < 1 || buf > 100 || cin.fail())
	{
		cin.clear();
		cin.ignore(32767, '\n');

		cout << "Некорректный ввод. Повторите попытку" << endl;
		cin >> buf;
	}

	return buf;
}

bool PlayAgain()// Продолжить/завершить игру
{
	char answer = 0;

	cout << "Хотите сыграть еще раз?" << endl;
	cout << "Нажмите Y, если да" << endl;
	cout << "Нажмите N, если нет" << endl;

	cin >> answer;

	if (answer != 'y' && answer != 'Y' && answer != 'n' && answer != 'N')
	{
		cin.clear();
		cin.ignore(32767, '\n');

		cout << "Некорректный ввод. Повторите попытку" << endl;

		cin >> answer;
	}

	if (answer == 'y' || answer == 'Y') return true;
	if (answer == 'n' || answer == 'N') return false;
	
}

int main()
{
	setlocale(LC_ALL, "ru");

	int randomNumber = 0; // случайное число, "загаданное" компьютером
	int userNumber = 0; // для записи числа пользователя

	cout << "Давай сыграем в игру. Я загадал число от 1 до 100. У тебя есть 7 попыток его отгадать" << endl;

	do
	{
		cout << "Какое число я загадал?" << endl<< endl;
		randomNumber = GetRandomNumber();

		for (int i = 0; i < 7; i++)
		{

			cout << "Попытка №" << i + 1 << ": " << "\t";
			userNumber = GetUserNumber();

			if (userNumber > randomNumber)
			{
				cout <<"Ваше число больше задуманного" << endl<<endl;
			}
			else if (userNumber < randomNumber)
			{
				cout << "Ваше число меньше задуманного" << endl<<endl;
			}

			else if (userNumber == randomNumber)
			{
				cout << "Вы угадали!!!" << endl<< endl;
				break;
			}

			if (i == 6) cout << "==============================================" << endl;
		}

	} while (PlayAgain());

}
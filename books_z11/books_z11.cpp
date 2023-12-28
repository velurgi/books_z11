#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;

struct book {
	string name;
	string author;
	string publishing;
	string year;
	string cost;
};

int dataCheckInt(int integer, int max) { //Проверка на int
	while (std::cin.fail() || integer < 0 || integer > max) {
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << "Ошибка, вы должны ввести целое неотрицательное число." << std::endl << "Введите число ещё раз: " << std::endl;
		std::cin >> integer;
	}
	return integer;
}

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int answer = 0;
	bool fileExistance = false;
	std::vector <book> books;
	string fileLocation = "D:/books.txt";
	std::ifstream in(fileLocation);
	

	do {
		fileLocation = "D:/books.txt";
		cout << "Укажите расположение файла с данными на компьютере (0 - выбрать заготовленное место: ";
		cin >> fileLocation;
		if (fileLocation == "0") {
			fileLocation = "D:/books.txt";
		}
		std::ifstream in(fileLocation);
		if (in.is_open()) {
			system("cls");
			fileExistance = true;
		}
		else {
			cout << "Файл не найден." << endl << "Попробуйте ещё раз." << endl;
		}
	} while (!fileExistance);

	int counter = 0;
	string tempData;
	book anna;

	while (in >> tempData) {
		switch (counter)
		{
		case 0:
			anna.name = tempData;
			break;
		case 1:
			anna.author = tempData;
			break;
		case 2:
			anna.publishing = tempData;
			break;
		case 3:
			anna.year = tempData;
			break;
		case 4:
			anna.cost = tempData;
			break;
		}
		counter++;
		if (counter == 5) {
			books.push_back(anna);
			counter = 0;
		}
	}

	cout << "Название \t \t \t \t Автор \t \t \t \t Издательство \t \t \t \t Год \t \t \t \t Цена" << endl << endl;

	for (int i = 0; i < books.size(); i++) {
		cout << books[i].name << " \t \t \t \t" << books[i].author << " \t \t \t \t" << books[i].publishing << " \t \t \t \t" << books[i].year << " \t \t \t \t" << books[i].cost << endl;
	}

	do {
		cout << "Что вы хотите сделать?" << endl;
		cout << "1 - Добавить новую строку \t 2 - Удалить строку \t 3 - Добавить строки из другого формата \t 4 - Выйти из программы" << endl;
		cin >> answer;
		answer = dataCheckInt(answer, 4);
		switch (answer) {
		case 1:
			cout << "aboba";
			break;
		}
	} while (answer != 4);


	cout << "Спасибо, за использование программы." << endl << "Досвидания." << endl;

	return 0;
}
#include <iostream>							
#include <fstream>					
#include <string>					
					



using namespace std;

int overwrite(string path, string str);


int main() {
	setlocale(LC_ALL, "Russian");

	//Задача 1
//Запись в файл
	cout << "Задача 1\n";
	string path = "file.txt";
	ofstream out;
	out.open(path, ios::app);
	string str;
	cout << "Файл открыт для записи!\n";
	cout << "Справка: чтобы прекратить ввод, введите 'end'\n";
	while (str != "end") {
		cout << "Введите строку:\n ";
		getline(cin, str);
		out << str << "\n";
	}
	out.close();

	//Чтение из файла
	ifstream in;
	in.open("file.txt");
	if (in.is_open()) {
		cout << "Файл открыт для чтения:\n";
		string str;
		char sym;
		while (in.get(sym))
			str += sym;
		cout << str << endl;
	}
	in.close();
	//Удаление файла
	if (remove("file.txt") == 0)
		cout << "Файл удален!\n\n";
	else
		cout << "Ошибка удаления файла\n\n";


	//Задача 2
	cout << " задача2\n";
	string path1 = "overwrite.txt";
	ofstream out1;
	out1.open(path1, ios::app);
	string str2;
	string str1 = " Ожидаем внесения изменений!";
	cout << "Содержимое файла!-->>"<< str1 <<endl;
	cout << "Внесите изменения: ";
	getline(cin, str2);
	out << str2 << "\n";
	out.close();
	cout << overwrite(path1, str2) << endl << endl;


	return 0;
}

int overwrite(string path, string str) {
	ofstream out;
	out.open(path, ios::out);
	if (out.is_open()) {
		out << str << "\n";
		out.close();
		return true;
	}
	return false;
}
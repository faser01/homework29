#include <iostream>							
#include <fstream>					
#include <string>					
					



using namespace std;

int overwrite(string path, string str);


int main() {
	setlocale(LC_ALL, "Russian");

	//������ 1
//������ � ����
	cout << "������ 1\n";
	string path = "file.txt";
	ofstream out;
	out.open(path, ios::app);
	string str;
	cout << "���� ������ ��� ������!\n";
	cout << "�������: ����� ���������� ����, ������� 'end'\n";
	while (str != "end") {
		cout << "������� ������:\n ";
		getline(cin, str);
		out << str << "\n";
	}
	out.close();

	//������ �� �����
	ifstream in;
	in.open("file.txt");
	if (in.is_open()) {
		cout << "���� ������ ��� ������:\n";
		string str;
		char sym;
		while (in.get(sym))
			str += sym;
		cout << str << endl;
	}
	in.close();
	//�������� �����
	if (remove("file.txt") == 0)
		cout << "���� ������!\n\n";
	else
		cout << "������ �������� �����\n\n";


	//������ 2
	cout << " ������2\n";
	string path1 = "overwrite.txt";
	ofstream out1;
	out1.open(path1, ios::app);
	string str2;
	string str1 = " ������� �������� ���������!";
	cout << "���������� �����!-->>"<< str1 <<endl;
	cout << "������� ���������: ";
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
#include <iostream>
#include <string>
#include "book.h"
using namespace std;

//������

//����� �����
void Book::ShowBook() const{
	cout << "�����: " << author << endl;
	cout << "��������: " << name << endl;
	cout << "�������: " << publish << endl;
	cout << "���: " << year << endl;
	cout << "����������: " << count << endl;
	cout << "��������: " << page << endl;
}

//����� ����� �� ������
void Book::PrintBookFromAuthor(const Book book[], int size, const string& author) const{
	for (int i = 0; i < size; i++) {
		if (book[i].getAuthor() == author) {
			book[i].ShowBook();
			cout << endl;
		}
	}
}

//����� ����� �� ������������
void Book::PrintBookFromPublish(const Book book[], int size, const string& publish) const {
	for (int i = 0; i < size; i++) {
		if (book[i].getPublish() == publish) {
			book[i].ShowBook();
			cout << endl;
		}
	}
}	

//����� ����� ����� ������������� ���
void Book::PrintBookFromYear(const Book book[], int size, int year) const {
	for (int i = 0; i < size; i++) {
		if (book[i].getYear() >= year) {
			book[i].ShowBook();
			cout << endl;
		}
	}
}
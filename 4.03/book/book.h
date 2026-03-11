#pragma once
#include <iostream>
#include <string>
using namespace std;

//Класс
class Book {
	string author;
	string name;
	string publish; //������������
	int year;
	int count;		
	int page;

public:
	//����������� explicit (����� �� ���� ������� ��������������)
	explicit Book(const string& Bookauthor = "", const string& Bookname = "", const string& Bookpublish = "", const int& Bookyear = 0, const int& Bookcount = 0, const int& Bookpage = 0)
		: author(Bookauthor), name(Bookname), publish(Bookpublish), year(Bookyear), count(Bookcount), page(Bookpage){}

	//�������
	string getAuthor() const { return author; }
	string getName() const { return name; }
	string getPublish() const { return publish; }
	int getYear() const { return year; }
	int getCount() const { return count; }
	int getPage() const { return page; }

	//������

	//����� �����
	void ShowBook() const;

	//����� ����� �� ������
	void PrintBookFromAuthor(const Book book[], int size, const string& author) const;

	//����� ����� �� ������������
	void PrintBookFromPublish(const Book book[], int size, const string& publish) const;

	//������ ���� ����� ������������� ����
	void PrintBookFromYear(const Book book[], int size, int year) const;
};

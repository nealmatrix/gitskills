// test.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <unordered_map>

using namespace std;

/*
class Data {
public:
	int a[10][6];
	int b[10]; //��¼ÿ�������ж��ٸ���
	int lineNum = 0; //��¼һ���м���
	void readData();
};
void Data::readData() {
	for (int line = 0; line < lineNum; line++) {
		cout << "line " << line << ": ";
		for (int num = 0; num < b[line]; num++) {
			cout << a[line][num] << " ";
		}
		cout << endl;
	}
	cout << "lineNum" << lineNum << "; ";
	for (int line = 0; line < lineNum; line++) {
		cout << b[line] << " ";
	}
	cout << endl;
}
*/

int main()
{
	//test �����������
    /*double n = 2;
	int m = sizeof(n);
	cout << n << endl;
	cout << "size n: " << m << endl;
	*/

	//�ַ�����ķָ� �൱��python��split����
	/*char s[] = "1,2,3,4,5";
	char *p;
    p=strtok(s, ",");
	while (p != NULL) {
		cout << p << endl;
		p = strtok(NULL, ",");
	}
	*/

	//test �ļ�����������
	/*int a[10];
	int total = 0;
	ifstream inFile("test_input1.txt", ios::in);
	if (!inFile) {
		cout << "error opening" << endl;
		return 0;
	}
	int x;
	while (inFile >> x)
		a[total++] = x;
	for(int i=0; i<total; i++)
    	cout << a[i] << endl;
	inFile.close();
	*/

	//test ���ļ��ж�ȡn�������ֱ����������
    /*Data data;
	ifstream inFile("test_input2.txt", ios::in);
	if (!inFile) {
		cout << "error opening" << endl;
		return 0;
	}
	int bufSize=20;
	char buf[20];
	int num;
	char *p;
	while (inFile.getline(buf, bufSize)) {
		p = strtok(buf, " ");
		num = 0;
		while (p != NULL) {
			data.a[data.lineNum][num++] = atoi(p);
			p = strtok(NULL, " ");
		}
		data.b[data.lineNum] = num;
		data.lineNum++;
	}
	inFile.close();
	data.readData();
	*/

	//test ��ַ��ֵ
	/*int m = 1, n = 2;
	int *a, *b;
	b = &m;
	a = b;
	cout << *a<<endl;
	b = &n;
	cout << *a << endl;
	*/

	//test �ַ�������Ĵ�С
	/*int a[] = { 1,2,3,4 };
	int *b;
	char c[] = "abcdefg";
	string d = "abcdefg";
	string e = "abc";
	cout << "a: " << sizeof(a)<<endl;
	cout << "*b:" << sizeof(b)<<endl;
	cout << "c: " << sizeof(c)<<endl;
	cout << "d size: " << d.size() << endl;
	cout << "d: " << sizeof(d) << endl;
	cout << "e: " << sizeof(e) << endl;
	cout << d.at(1) << endl;*/

	//unordered_map ������Ƕ�������ָ�룿
	/*unordered_map<char, int> m;
	pair<char, int> p1 = make_pair('a', 2);
	m.insert(p1);
	m['a'] = 3;
	cout << m['a'] << endl << p1.second << endl;*/

	//test substr
	string s = "abcd";
	cout << s.substr(0, 2)<<endl;
	cout << s.substr(0, 0)<<endl;
	cout << s.substr(2)<<endl;
	cout << s.substr(4)<<endl;
    return 0;
}


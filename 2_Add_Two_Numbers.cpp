// 0002 Add Two Numbers.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
using namespace std;
class Data {
public:
	int a[50][100]; //ÿ�м�¼��һ����������
	int b[50];
	int lineNum;
	void readData();
	void readDataLine(int line);
};
void Data::readData() {
	for (int i = 0; i < lineNum; i++) {
		for (int j = 0; j < b[i]; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << lineNum << "; ";
	for (int i = 0; i < lineNum; i++) {
		cout << b[i] << " ";
	}
	cout << endl;
}
void Data::readDataLine(int line) {
	for (int j = 0; j < b[line]; j++) {
		cout << a[line][j] << " ";
	}
	cout << endl;
}

int inputData(char* filename, Data& data) {
	ifstream inFile(filename, ios::in);
	if (!inFile) {
		cout << "error opening" << endl;
		return 0;
	}
	char buf[200];
	int bufSize = 200;
	int lineNum = 0; //һ��������
	int num; //ÿ���ж���data
	char*p;
	while (inFile.getline(buf, bufSize)) {
		p = strtok(buf, ", ");
		num = 0;
		while (p != NULL) {
			data.a[lineNum][num++] = atoi(p);
			p = strtok(NULL, ", ");
		}
		data.b[lineNum] = num;
		lineNum++;
	}
	data.lineNum = lineNum;
	inFile.close();
	return 1;
}

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
ListNode* makeList(int* a, int num) {
	ListNode* first= new ListNode(a[0]);
	ListNode* p1, * p2;
	p1 = first;
	for (int i = 1; i < num; i++) {
		p2 = new ListNode(a[i]);
		p1->next = p2;
		p1 = p2;
	}
	return first;
}
void outputList(ListNode* p) {
	if (p != NULL) {
		cout << p->val;
		p = p->next;
		while (p != NULL) {
			cout <<" -> "<< p->val;
			p = p->next;
		}
		cout << endl;
	}
}

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		//����д���Ľ���
		//1.��һ�������ֱ�����鹹�ģ���ʵ�ʵ�һ����Ϊ�ڶ����㣬���������ظ�
		//2.�ڶ���ѭ���͵�һ��ѭ�����Ժϲ���ֻҪ���õ�NULL�󣬼ӵ���ֵΪ0���ɣ���������ظ�
		//
		/*int tmp,i=0; //tmp��ÿλ��ӵĽ����i�ж��Ƿ���Ҫ��λ
		tmp = l1->val + l2->val + i;
		i = tmp / 10;
		tmp %= 10;
		l1 = l1->next;
		l2 = l2->next;
		ListNode* first = new ListNode(tmp);
		ListNode* p1, *p2;
		p1 = first;
		while (l1 != NULL &&l2 != NULL) {
			tmp = l1->val + l2->val + i;
			i = tmp / 10;
			tmp %= 10;
			p2 = new ListNode(tmp);
			p1->next = p2;
			p1 = p2;
			l1 = l1->next;
			l2 = l2->next;
		}
		if (l2 == NULL) {
			l2 = l1;
			l1 = NULL;
		}
		while (l1 == NULL &&l2 != NULL) {
			tmp = l2->val + i;
			i = tmp / 10;
			tmp %= 10;
			p2 = new ListNode(tmp);
			p1->next = p2;
			p1 = p2;
			l2 = l2->next;
		}
		if (i != 0) {
			p2 = new ListNode(i);
			p1->next = p2;
			return first;
		}
		return first;
		*/
		ListNode* prefirst = new ListNode(0); //��һ����Ϊ�鹹�ġ�
		ListNode* p = prefirst;
		ListNode* p1 = l1, *p2 = l2; //��Ҫֱ���޸Ľ����Ĳ�������
		int i=0, tmp; //i��¼��λ��tmp��¼��ӽ��
		while (p1 != NULL || p2 != NULL) {
			int n1 = (p1 != NULL) ? p1->val : 0;
			int n2 = (p2 != NULL) ? p2->val : 0;
			tmp = n1 + n2 + i;
			i = tmp / 10;
			tmp %= 10;
			p->next = new ListNode(tmp);
			p = p->next;
			if (p1 != NULL) p1 = p1->next;
			if (p2 != NULL) p2 = p2->next;
		}
		if (i != 0) {
			p->next = new ListNode(i);
		}
		return prefirst->next;
	}
};

int main()
{
	Data data;
	char filename[] = "test.txt";
	inputData(filename, data);
	data.readData();
	Solution solution;
	cout << endl << "result: " << endl;
	for (int i = 0; i < data.lineNum / 2; i++) {
		ListNode* p1 = makeList(data.a[2 * i], data.b[2 * i]);
		ListNode* p2 = makeList(data.a[2 * i + 1], data.b[2 * i + 1]);
		outputList(p1);
		outputList(p2);
		ListNode* result = solution.addTwoNumbers(p1, p2);
		outputList(result);
	}
    return 0;
}


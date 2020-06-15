// 0006 ZigZag Conversion.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1)
			return s;
		int n = s.size();
		char* zS = new char[n+1]; //���һλ����'\0'
		int k = 0; //k��zS�����
		int kS; //kS��s�����
		for (int i = 0; i < numRows; i++) { //i���к�
			int j = 0; //j��ÿ�е����
			bool nCSign = true; // nCSign��need change sign
			int sign = 1;
			if (i == 0 || i == numRows - 1)
				nCSign = false;
			while (true) {
				kS = (2 * numRows - 2)*j + sign*i;
				if (kS < n) {
					zS[k] = s[kS];
					k++;
					if (nCSign) {
						if (sign == 1)
							j++, sign = -1;
						else
							sign = 1;
					}
					else {
						j++;
					}
				}
				else
					break;
			}
		}
		zS[k] = '\0';
		string result = zS;
		delete zS;
		return result;
	}
};

int main()
{
	string s;
	int numRows;
	//test1 return "PAHNAPLSIIGYIR"
	s = "PAYPALISHIRING";
	numRows = 3;

    //test2 return "PINALSIGYAHRPI"
	s = "PAYPALISHIRING";
	numRows = 4;

	//test3 return "agbfced"
	/*s = "abcdefg";
	numRows = 4;*/

	//test4 return "aebdfcg"
	/*s = "abcdefg";
	numRows = 3;*/

	//test5 return "A"
	s = "A";
	numRows = 1;

	Solution solu;
	cout << solu.convert(s, numRows)<<endl;

	/*char s[10] = "abc";
	string a = s;
	cout << s<<","<<a << endl;*/
    return 0;
}


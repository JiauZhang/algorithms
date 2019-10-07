/*
* Copyright(c) 2019 Jiau Zhang
* For more information see <https://github.com/JiauZhang/algorithms>
* 
* This repo is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation
*
* It is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with THIS repo. If not, see <http://www.gnu.org/licenses/>.
*/

#include <iostream>
//#include <string.h>
#include <string>

using namespace std;

int getFirstNotRepeatChar(char *str)
{
	if (!str)
		return -1;

	int chars[256];
	char *pChar = str;

	for (int i=0; i<256; i++)
		chars[i] = 0;
	//这里的index不用减去 'a'，因为字符还可能是数子字符～
	while (*pChar != '0') {
		int index = *pChar - 'a';
		chars[index]++;
		pChar++;
	}

	pChar = str;
	while (*pChar != '0') {
		int index = *pChar - 'a';
		if (chars[index] == 1)
			return *pChar;
		pChar++;
	}
}

int main(int argc, char **argv)
{
	//string *str = "ddbscagds";
	//string str("ddbscagds");
	char str[] = "dd0bscagds";
	
	char firstNotRepeatChar = getFirstNotRepeatChar(str);
	cout << firstNotRepeatChar << endl;

	return 0;
}

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

using namespace std;

int kmp_bs(string &tpl, string &str)
{
	if (!tpl.size() || !str.size())
		return -1;
		
	int i = 0, j = 0;
	while (i<str.size() && j<tpl.size()) {
		if (str[i] == tpl[j]) {
			i++;
			j++;
		} else {
			i = i - j + 1;
			j = 0;
		}
	}
	
	if (j == tpl.size())
		return i - j;
	
	return -1;
}

int main()
{
	string tpl = "template";
	string str = "string tme plate template tt";
	
	cout << kmp_bs(tpl, str);	
	
	return 0;
} 

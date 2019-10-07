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

void reverse(char *start, char *end)
{
	if (!start || !end)
		return;
		
	while (start < end) {
		char temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
}

void reverse_sentence(char *str)
{
	if (!str)
		return;
		
	char *start = str;
	char *end = str;
	
	while (*end != '\0') {
		end++;
	}
	
	end--;
	cout << "step 1" << endl;
	reverse(start, end);
	
	start = end = str;
	cout << "step 2" << endl;
	int count = 0;
	while (*start != '\0' && count < 50) {
		if (*start == ' ') {
			start++;
			end++;
		} else if (*end == ' ' || *end == '\0') {
			end--;
			reverse(start, end);
			end++;
			start = end;
		} else {
			end++;
		}	
		
		count++;	
	}
	
	if (count >= 50)
		cout << "failed" << endl;
}

int main(int argc, char **argv)
{
	char sentence[] = "I am a student. ";
	reverse_sentence(sentence);
	cout << sentence << endl;
	
	return 0;
}

#include <iostream>
#include <string> 

using namespace std;

void util_print(int row, int col, std::string text)
{
    std::string str = "\x1b[" + std::to_string(row) + ";" + std::to_string(col) + "H" + text;
	printf(str.c_str());
}
#include <iostream>
#include <vector>
#include <string.h>

#include "libxl.h"

using namespace std; 
using namespace libxl;

int main() {
	Book* book = xlCreateBook();
	book->setKey(L"GCCG", L"windows-282123090cc0e6036db16b60a1o3p0h9");
	Sheet* sheet = book->addSheet(L"Sheet1");
	vector<string> moves;
	string str;
	cin >> str;

	while (str != "0-0" && str != "1-0" && str != "0-1") {
		moves.push_back(str);
		cin >> str;
	}

	for (int i = 0; i < moves.size(); i++) {
		wstring widestr = std::wstring(moves[i].begin(), moves[i].end());
		sheet->writeStr(i / 3, i % 3, widestr.c_str());
	}

	book->save(L"example.xls");
	book->release();
}
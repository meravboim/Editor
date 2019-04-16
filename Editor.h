/* Merav Boim 206489155 */
#pragma once
using namespace std;
#include <iostream>
#include<sstream>
#include "Document.h"

class Editor
{
private:
	Document * my_doc;
public:
	Editor();
	~Editor();

	void loop();
	bool is_number(const string &s);
};


/* Merav Boim 206489155 */
#include "Editor.h"



Editor::Editor()
{
	 my_doc=new Document();
}


Editor::~Editor()
{
	delete my_doc;
}

void Editor::loop() 
{


	void change_current(int index); // 7 - makes line #7 the current line  
	

	string input;
	while (1) {
		getline(cin, input);
		if (input.compare("p") == 0) 
			my_doc->print_current_line();
		if (input.compare("n") == 0) 
			my_doc->print_index_current_line();
		if (input.compare("%p") == 0) 
			my_doc->prints_all_lines();
		if (is_number(input)) {
			int num;
			stringstream ss;
			ss << input;
			ss >> num;
			my_doc->change_current(num);
		}
		if (input.compare("a") == 0) 
			my_doc->appends_after();
		if (input.compare("i") == 0) 
			my_doc->inserts_before();
		if (input.compare("c") == 0) 
			my_doc->changes_current_to_the_follows();
		if (input.compare("d") == 0)
			my_doc->delete_current_line();
		if (input[0] == '/') 
			my_doc->search(input.substr(1));
		if (input[0] == 's' && input[1] == '/')
			my_doc->replaces_old_new(input);
		if (input.compare("Q") == 0) 
			exit(0);
	}
}

bool Editor::is_number(const string &s) {
	return (atoi(s.c_str()));
}




/* Merav Boim 206489155 */
#include "Document.h"



Document::Document()
{
	vector<string> temp(0);
	my_document = temp;
	current_line = 0;
}

void Document::print_current_line()
{
	if(current_line==0)
		cout << "empty document" << endl;
	else
		cout << my_document[current_line-1] << endl;
}

void Document::print_index_current_line()
{
	if (current_line == 0)
		cout << "empty document" << endl;
	else
		cout << current_line << "	"<< my_document[current_line-1] << endl;
}

void Document::prints_all_lines() {
	for (int i = 0; i < my_document.size(); i++) {
		cout << my_document[i] << endl;
	}
}

void Document::change_current(int index)
{
	if (index <= my_document.size()) {
		current_line = index;
		print_current_line();
	}
}

void Document::appends_after()
{
	string line;
	while (getline(cin, line) && line != ".") {
		if (current_line < my_document.size())
			my_document.insert(my_document.begin() + current_line, line);
		else 
			my_document.push_back(line);
		current_line++;
	}
}

void Document::inserts_before()
{
	current_line--;
	appends_after();
	current_line++;

}

void Document::changes_current_to_the_follows()
{
	string line;
	while (getline(cin, line) && (line.compare(".") != 0)) {
		my_document[current_line - 1] = line;
	}
}

void Document::delete_current_line()
{
	my_document.erase(my_document.begin() + current_line - 1);
	current_line--;

}

void Document::search(string text)
{

	for (int i = current_line - 1; i < my_document.size(); i++) {
		if (my_document[i].find(text) != string::npos) {
			current_line = i + 1;
			cout << my_document[i] << endl;
			return;
		}
	}
	for (int i = 0; i < current_line; i++) {
		if (my_document[i].find(text) != string::npos) {
			current_line = i + 1;
			cout << my_document[i] << endl;
			return;
		}
	}
}

void Document::replaces_old_new(string s_o_n_string)
{/*
	help from-https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
*/
	vector<string>separate_strings(0);
	string delimiter = "/";
	size_t pos = 0;
	string token, temp;
	while ((pos = s_o_n_string.find(delimiter)) != string::npos) {
		token = s_o_n_string.substr(0, pos);
		separate_strings.push_back(token);
		s_o_n_string.erase(0, pos + delimiter.length());
	}
	separate_strings.push_back(token);

	for (int i = 0; i < my_document.size(); i++) {
		if ((pos = my_document[i].find(separate_strings[1])) != string::npos) {
			my_document[i] = my_document[i].substr(0, pos) + separate_strings[2] + " " + my_document[i].substr(pos + separate_strings[1].length());
		}
	}
}


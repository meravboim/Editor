/* Merav Boim 206489155 */
#pragma once
using namespace std;
#include <iostream>
#include<string>
#include <vector>

class Document
{
private:
	vector <string> my_document;
	int current_line;
public:
	Document();

	void print_current_line();   // p - prints the current line
	void print_index_current_line();   // n - prints line number of current line
	void prints_all_lines();   // %p - prints all lines
	void change_current(int index); // 7 - makes line #7 the current line
	void appends_after();   // a - appends new text after the current line
	void inserts_before();  // i - inserts new text before the current line
	void changes_current_to_the_follows();   // c - changes the current line for text that follows
	void delete_current_line();   // d - deletes the current line
	void search(string text);// /text - searches forward after current line for the specified text.
	void replaces_old_new(string s_o_n_string);   // s/old/new/ - replaces old string with new in current line	
};


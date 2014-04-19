#include <iostream>
#include "Snippet.h" //INclude the snippet class definition
using namespace std;

//constructor
Snippet::Snippet(const string &text) :  snippetText(text)
{
	//empty body
} // end Snippet constructor

Snippet::~Snippet()
{
    
}

//set text
void Snippet::setText(const string &text)
{
	snippetText = text;
}//end setSnippetText

//get text
string Snippet::getText() const
{
	return snippetText;
}// end function getText


// print Snippet information
string Snippet::print() const
{
	return  getText();
}// end function print

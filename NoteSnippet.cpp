//
//  NoteSnippet.cpp
//  Final
//
//  Created by Justin on 12/9/13.
//  Copyright (c) 2013 Justin. All rights reserved.
//
#include <sstream>
#define SSTR( x ) dynamic_cast< std::ostringstream & >(( std::ostringstream() << std::dec << x ) ).str()
#include "NoteSnippet.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

//constructor
NoteSnippet::NoteSnippet(const string &text, double importance) : Snippet(text)
{
	setImportance(importance);
	
}// end CodeSnippet constructor

NoteSnippet::~NoteSnippet()
{
    cout << "Note " << getText() << "destroyed.\n";
}
//set importance
void NoteSnippet::setImportance(double importance)
{
    noteSnippetImportance = importance;
    noteSnippetImportance = (importance < 0.0) ? 0.0 : importance;
}// end setImportance

//return importance
double NoteSnippet::getImportance() const
{
	return noteSnippetImportance;
}

//Calculate importance
// override pure virtual function importance in Snippet
double NoteSnippet::importance() const
{
    return getImportance() + 10;
}//end function get importance


//Print CodeSnippetInformation
string NoteSnippet::print() const
{
   
	return  getText() + "~" + SSTR(importance()) + "~";
    
	//Snippet::print(); //reuse snippet base-class print function
	cout << '\n'  << '\n';
    
}// end function print
#include <iostream>
#include "TodoSnippet.h"
#include <sstream>
#define SSTR( x ) dynamic_cast< std::ostringstream & >(( std::ostringstream() << std::dec << x ) ).str()
using namespace std;

//constructor
TodoSnippet::TodoSnippet(const string &text, const string &date, double importance) : Snippet(text)
{
	setImportance(importance);
	setDate(date);
}// end CodeSnippet constructor

TodoSnippet::~TodoSnippet()
{
    cout << "ToDo " << getText() << "destroyed\n";
}
//set importance
void TodoSnippet::setImportance(double importance)
{
todoSnippetImportance = importance;
todoSnippetImportance = (importance < 0.0) ? 0.0 : importance;
}// end setImportance

//return importance
double TodoSnippet::getImportance() const
{
	return todoSnippetImportance;
}

//Calculate importance
// override pure virtual function importance in Snippet
double TodoSnippet::importance() const
{
    return getImportance() + 100;
}//end function get importance

 void TodoSnippet::setDate(const string &date)
 {
 	todoSnippetDate = date;
 }

 string TodoSnippet::getDate() const
 {
 	return todoSnippetDate;
 }
//Print CodeSnippetInformation
string TodoSnippet::print() const
{
	return  getText() + "~" + SSTR(importance()) + "~" + getDate() + "~";
}// end function print
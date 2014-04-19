#ifndef SNIPPET_H //prevent double declaration of any identifiers
#define SNIPPET_H //prevent double declaration of any identifiers

#include <string> //C++ string class

using namespace std; //Declare a namespace so I don't have to use std::

class Snippet{
public:
	Snippet(const string &); //Constructor
    
	void setText(const string &); //set snippet text
	string getText() const; //return snippet text
    
	virtual ~Snippet();
	// Pure virtual functions here makes this abstract base class
	// http://stackoverflow.com/questions/2652198/difference-between-a-virtual-function-and-a-pure-virtual-function
	virtual double importance() const = 0; //pure virtual
	virtual string print() const; //virtual
    
private:

	string snippetText;
    
}; //end class snippet

#endif

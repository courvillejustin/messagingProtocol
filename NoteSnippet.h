//
//  NoteSnippet.h
//  Final
//Justin Courville

#ifndef Final_NoteSnippet_h
#define Final_NoteSnippet_h

#include "Snippet.h" //Snippet class definition

class NoteSnippet : public Snippet
{
public:
	NoteSnippet(const string &, double = 0.0);
    
	void setImportance(double); //set importance
	double getImportance() const; //return importance
    
	virtual ~NoteSnippet();
	//Keyword virtual signals intent to override
	virtual double importance() const; //calculate importance
	virtual string print() const; //print CodeSnippet object
    
private:
	double noteSnippetImportance;
};
#endif

#ifndef TODOSNIPPET_H
#define TODOSNIPPET_H

#include "Snippet.h" //Snippet class definition

class TodoSnippet : public Snippet
{
public:
	TodoSnippet(const string &,const string &, double = 0.0);
    
	void setDate(const string &);
	string getDate() const;
    
	void setImportance(double); //set importance
	double getImportance() const; //return importance
    
	virtual ~TodoSnippet();
	//Keyword virtual signals intent to override
	virtual double importance() const; //calculate importance
	virtual string print() const; //print CodeSnippet object
    
private:
	double todoSnippetImportance;
	string todoSnippetDate;
};

#endif
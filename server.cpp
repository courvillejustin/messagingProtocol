#include <sstream>
// Define a macro to allow for conversions from numeric to string type, this is needed for the odd OSX problems 
//http://rootdirectory.de/wiki/SSTR()
#define SSTR( x ) dynamic_cast< std::ostringstream & >(( std::ostringstream() << std::dec << x ) ).str()
#include "ServerSocket.h"
#include "SocketException.h"
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <vector>
#include <xlocale.h>
#include <stdlib.h>

using namespace std;

vector<string> snippetVector(1); 

void writeMessage(const char *buffer);
void refreshSnippets();
void updateDesktopFile();

int main ( int argc, char **argv )
{
  std::cout << "running....\n"; //Indicate that the server is running
  refreshSnippets(); //refresh the snippets to make sure everything is running properly
  //Error handling for creating the sockets
  try
    {
      // Create the socket
      ServerSocket server (7777);
      while (true)
		{
		  ServerSocket serverSocket; //Create the server socket 
		  server.accept (serverSocket);
		  //Error handling for receiving the data
		  try { while(true)
			{
			  string input; //Input variable from the client
			  serverSocket > input; //Direct the input from the socket to the variable
			  //Check for a certain flag
			  if(input == "-i")
			  {
			  	// Write the reply back to the client
			  	serverSocket << "Snippet inserted";
			  	while(1) //While true
			  	{
				  	string snippetIn; //String variable for incoming snippet
				  	serverSocket > snippetIn; //Redirect the socket data to the variable
				  	if(snippetIn == "\0") break; //Check to see if we have a terminating character
				  	writeMessage(snippetIn.c_str()); //If not, write the serialized data to a file
				  	updateDesktopFile(); //Refresh the desktop file
			  	}
			  };
			  //Check for certain flags
			  if(input == "-c")
			  {
			  	serverSocket << "Snippets Cleared"; //Let the client know the server was cleared
			  	ofstream myfile ("snippet.txt"); //Open file without append flags
			  	myfile << "\n"; 
			  	myfile.close(); // Close file
			  	updateDesktopFile(); //Update desktop file
			  };
			}// end while(true)
		    }
		   //Catch any exception thrown by the socket 
		  catch ( SocketException& ){}
		}//Close the top while(true)
    }// close try
  //Catch any exception thrown by the socket while exiting
  catch ( SocketException& e ) {std::cout << "Exception " << e.description() << "\n while the socket was Exiting.\n";};

  return 0;
}

void refreshSnippets()
{
	//Clear the global snippetVector
	snippetVector.clear();
	string line;
	ifstream myfile("snippet.txt"); //open file as input stream
	if (myfile.is_open())
	{
		//push serialized snippet data into a vector in memory
		while (getline (myfile,line)) snippetVector.push_back(line);  
		myfile.close();
	}
}
void updateDesktopFile()
{
	refreshSnippets(); //refresh snippets in memory
	int limit = snippetVector.size();
  	ofstream myfileDesktop ("/tmp/snippet.txt"); //open file as an output stream
  	if (myfileDesktop.is_open())
  	{
	 for(int j = 0; j < limit; ++j) 
		for (int i = 0; i < snippetVector[j].length(); ++i)
		    {
		    const char test2 = snippetVector[j][i];
		       if (test2 == '~') myfileDesktop << "\n";
		        else myfileDesktop << snippetVector[j][i];
		   }
	 	myfileDesktop.close();
	}
}
void writeMessage(const char *buffer)
{
	ofstream myfile ("snippet.txt", ios::out | ios::app);
	if (myfile.is_open())
     {
		myfile << buffer; 
		myfile.close();
	}
}

#include <sstream>
// Define a macro to allow for conversions from numeric to string type, this is needed for the odd OSX problems 
//http://rootdirectory.de/wiki/SSTR()
#define SSTR( x ) dynamic_cast< std::ostringstream & >(( std::ostringstream() << std::dec << x ) ).str()
#include "ClientSocket.h"
#include "SocketException.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "TodoSnippet.h"
#include "NoteSnippet.h"
#include "Snippet.h"

using namespace std;

int main ( int argc, char **argv )
{
   string inputCommand;
  try
    {
      ClientSocket client_socket ( "localhost", 7777 );
      std::string reply;
      string sendString;
      try
    	{
        //Too few arguments, try again =(
        if(argc < 2)
        {
          cout << "Error: need arguments try " << *(argv + 0) << " -note {text|importance} or -todo {text|date|importance} \n"; //Output to console
          return 0;
        }
        if(argc >= 2)
        {
          inputCommand = *(argv + 1); //set the output file to the third command line argument --Use of pointer
              
              if (inputCommand == "-g") client_socket << "-g";
              
              if (inputCommand == "-c")
              {
                  client_socket << "-c";
                  client_socket >> reply;
              };

              if (inputCommand == "-note" && argc == 4)
              {
                  string text = *(argv + 2);
                  string importance = *(argv + 3);
                  double imp = atof(importance.c_str());
                  NoteSnippet noteSnippet(text, imp);
                  sendString = noteSnippet.getText() + "~Priority " + SSTR(noteSnippet.importance()) + "~~";
                  client_socket << "-i";
                  client_socket >> reply;
                  client_socket << sendString;
                 
              };
              if (inputCommand == "-todo" && argc == 5)
              {
                  string text = *(argv + 2);
                  string date = *(argv + 3);
                  string importance = *(argv + 4);
                  double imp = atof(importance.c_str());
                  TodoSnippet tSnippet(text, date, imp);
                  sendString = tSnippet.getText() +  + "~Due " + tSnippet.getDate() + "~Priority " + SSTR(tSnippet.importance()) + "~~";
                  client_socket << "-i";
                  client_socket >> reply;
                  client_socket << sendString;
              };
        }// Close if(argc >= 2)
    	}//Close try

      //Catch any exception thrown by the socket
      catch ( SocketException& ) {}
      std::cout << "We received this response from the server:\n\"" << reply << "\"\n";;

    }
    //Catch any exception thrown by the socket
  catch ( SocketException& e )
    {
      std::cout << "Exception was caught:" << e.description() << "\n";
    }

  return 0;
}

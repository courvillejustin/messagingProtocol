#include "ServerSocket.h"
//#include "SocketException.h"
#include <string>
#include <iostream>

int main ( int argc, char **argv )
{
  std::cout << "running....\n";

  
      // Create the socket
      ServerSocket server ( 6666 );

      while ( true )
	{

	  ServerSocket new_sock;
	  server.accept ( new_sock );

	
	      while ( true )
		{
		  std::string data;
		  new_sock >> data;
		  new_sock << data;
		}
	    
	  // catch ( SocketException& ) {}

	}
 //    }
 //  catch ( SocketException& e )
 //    {
 //      std::cout << "Exception was caught:" << e.description() << "\nExiting.\n";
 //    }

  return 0;
}
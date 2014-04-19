// Definition of the ServerSocket class
//Original Source http://tldp.org/LDP/LG/issue74/tougher.html#4
//Modified by Justin Courville

#ifndef ServerSocket_class
#define ServerSocket_class
#include "Socket.h"

class ServerSocket : private Socket
{
 public:
  ServerSocket ( int port );
  ServerSocket (){};
  //Destructor for ServerSocket
  virtual ~ServerSocket();

  //Operator overloading, the redirection >> and << 
  const ServerSocket& operator << ( const std::string& ) const;
  const ServerSocket& operator >> ( std::string& ) const;

  //Operator overloading, the redirection > and < 
  const ServerSocket& operator < ( const std::string& ) const;
  const ServerSocket& operator > ( std::string& ) const;

  void accept ( ServerSocket& );
};
#endif

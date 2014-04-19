// Implementation of the ServerSocket class
//Original Source http://tldp.org/LDP/LG/issue74/tougher.html#4
//Modified by Justin Courville

#include "ServerSocket.h"
#include "SocketException.h"
#include <iostream>

ServerSocket::ServerSocket ( int port )
{
  if ( ! Socket::create() ) throw SocketException ( "Could not create server socket." );

  if ( ! Socket::bind ( port ) ) throw SocketException ( "Could not bind to port." );

  if ( ! Socket::listen() )  throw SocketException ( "Could not listen to socket." );
}
//Destructor for the ServerSocket object
ServerSocket::~ServerSocket()
{
  std::cout << "Killing the socket now....";
}

//Operator overloading
const ServerSocket& ServerSocket::operator << ( const std::string& s ) const
{
  if (!Socket::send(s)) throw SocketException ( "Could not write " + s + " to socket." );

  return *this;
}
//Operator overloading
const ServerSocket& ServerSocket::operator < ( const std::string& s ) const
{
  if (!Socket::send(s)) throw SocketException ( "Could not write " + s + " to socket." );

  return *this;

}
//Operator overloading
const ServerSocket& ServerSocket::operator >> ( std::string& s ) const
{
  if ( ! Socket::recv ( s ) ) throw SocketException ( "Could not read " + s + " from socket." );
  return *this;
}
//Operator overloading
const ServerSocket& ServerSocket::operator > (std::string& s) const
{
  if (!Socket::recv(s)) throw SocketException ( "Could not read "+ s +" from socket." );
  return *this;
}
void ServerSocket::accept ( ServerSocket& sock )
{
  //Accept Exception handler
  if (!Socket::accept (sock)) throw SocketException ( "Could not accept socket." );
}

// Implementation of the ClientSocket class
//Original Source http://tldp.org/LDP/LG/issue74/tougher.html#4
//Modified by Justin Courville

#include "ClientSocket.h"
#include "SocketException.h"
#include <iostream>


ClientSocket::ClientSocket ( std::string host, int port )
{
  if ( ! Socket::create() ) throw SocketException ( "Could not create client socket." );

  if ( ! Socket::connect ( host, port ) ) throw SocketException ( "Could not bind to port." );
}


const ClientSocket& ClientSocket::operator << ( const std::string& s ) const
{
  if ( ! Socket::send ( s ) ) throw SocketException ( "Could not write " + s + " to socket." );

  return *this;
}

const ClientSocket& ClientSocket::operator >> ( std::string& s ) const
{
  if (!Socket::recv (s)) throw SocketException ( "Could not read " + s + " from socket." );

  return *this;
}

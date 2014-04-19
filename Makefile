# Makefile for final project
# Justin Courville

server_objects = ServerSocket.o Socket.o server.o Snippet.o TodoSnippet.o NoteSnippet.o
client_objects = ClientSocket.o Socket.o Snippet.o TodoSnippet.o NoteSnippet.o client.o


all : server client

server: $(server_objects)
	g++ -o snippetServer $(server_objects)


client: $(client_objects)
	g++ -o snippet $(client_objects)


Socket: Socket.cpp
ServerSocket: ServerSocket.cpp
ClientSocket: ClientSocket.cpp
server: server.cpp
Snippet: Snippet.cpp
TodoSnippet: TodoSnippet.cpp
NoteSnippet: SnoteSnippet.cpp
client: client.cpp


clean:
	rm -f *.o server client Snippet TodoSnippet NoteSnippet
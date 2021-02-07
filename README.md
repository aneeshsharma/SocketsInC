# TCP and UDP sockets in C
A very basic TCP and UDP socket implementation in C. The server programs listen to TCP/UDP connections indefinitely and respond with a message when a message is received from a client. The client programs connect to the TCP/UDP server, send a message and then receive a response.

## Prerequisites
To run these programs, you need -
- A Linux system
- `gcc` compiler

## Usage
### TCP
To compile the TCP programs, run -
```
$ gcc tcp_server.c -o tcp_server.o
$ gcc tcp_client.c -o tcp_client.o
```

Now, run the server first with -
```
$ ./tcp_server.o
```

The server will now listen to connections indefinitely.
Now, run the client with -
```
$ ./tcp_client.o
```

This would send a message to the server and print the response received.

### UDP
To compile the UDP programs, run -
```
$ gcc udp_server.c -o udp_server.o
$ gcc udp_client.c -o udp_client.o
```

Now, run the server first with -
```
$ ./udp_server.o
```

The server will now listen to connections indefinitely.
Now, run the client with -
```
$ ./udp_client.o
```

This would send a message to the server and print the response received.

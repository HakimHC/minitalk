# MINITALK

## Server - client communication with UNIX signals.

This project is a short introduction to signals.

There are 2 main components (which are separate programs): the client and the server.

### The main objective is the following:
* The server must be initialized first, and at startup the server must print is PID.
* After initializing the server, the client must be able to send a string to the server, by sending signals to it.
* The communication must be done exclusively with signals.
* The only allowed signals are: SIGUSR1 and SIGUSR2 (which are user-defined signals).

### My approach

The challange of this project is that communication between processes, when there is actual data being sent, is not optimal with signals.

A signal is only contains an integer (the type of the signal), and can not withhold more information. (Communicating with pipes or sockets would make much more sense).

My solution is based on a binary system, where a SIGUSR1 represents a 1 and a SIGUSR2 represents a 0.

With this approach, the client can send the string, bit by bit, through signals. (It's up to the server to process the bits and frame them into bytes).

This project was definitely fun, I'm looking forward to more UNIX projects.

### Usage

First, compile the binaries of the client and the server program, with a simple ```make```.

After that, you can run:

#### Server
```./server```

#### Client
```./client pid_of_server string_to_send```

Thank you for reading, see you soon!

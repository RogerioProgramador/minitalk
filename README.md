# MINITALK

Objective: create a communication program in form of a client and server.

## **Compile and run**

```
make
```
```
./server
```
```
./client PID "Message you want to send to server"
```

To compile, use the command make.  
After that, run the server side with ./server. The server will display it's PID, which you will need to run the client.  
To run the client, you will use ./client SERVER_PID "MESSAGE".  
Server will receive this message and display it.  
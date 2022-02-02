# **MINITALK**

Objective: create a communication program in form of a client and server.

## Compile and run

- To compile, go to the project directory use the command make.  
```
$ make
```
- Run the server side with ./server. The server will display it's PID, which you will need to run the client. Afther that, the server will wait for messages.
```
$ ./server
PID: 12345
```
- **In another terminal** run the client. The command is ./client SERVER_PID "MESSAGE". 
```
$ ./client 12345 "Testing"
```
- Server will receive this message and display it.  
```
$ ./server
PID: 12345
Testing
```
- Client will display a message indicating if everything went well.  
```
$ ./client 12345 "Testing"
Message sent successfully
```
### **Server side won't exit, you can send as many messages as you want.**
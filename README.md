# 2016-Spring-CS4461-HW2
Small modifications to existing program

6. (20) Go to http://www.beej.us/guide/bgnet/output/html/singlepage/bgnet.
html and refer to section 6.3 of the fine network programming guide there. Note that
there are two files in that section you can download: talker.c and listener.c.
Download these, compile them and run them. You’ll notice that the talker will
send whatever command-line argument you provide to the listener. Also note that
using localhost as the hostname argument to the talker doesn’t work; you need
to use 127.0.0.1. If you want to send a multi-word message, put it in quotations
(e.g., ./talker 127.0.0.1 "Protect This House"). Make two small changes to
this program:

(a) The current listener program quits once it has received a single message. Modify
it so that it will run forever, constantly listening for new packets. The talker
program can still execute once and exit.

(b) Parse the command line message into individual words. Count the number
of words. The talker should then send that as the first message. Send each
individual word as a separate packet.

A sample run of the talker might look like this:
>> ./talker 127.0.0.1 "Protect This House"
talker: sending a 3 word message
talker: sent 1 bytes to 127.0.0.1
talker: sent 7 bytes to 127.0.0.1
talker: sent 4 bytes to 127.0.0.1
talker: sent 5 bytes to 127.0.0.1
talker: done sending message
The first 1 byte message is the ASCII character 3, indicating the number of words in
the whole message.
A sample run of the listener might look like this:
>> ./listener
listener: waiting to recvfrom...
listener: got packet from 127.0.0.1
listener: packet is 1 bytes long
listener: packet contains "3"
listener: expecting 3 word message
listener: waiting to recvfrom...
listener: got packet from 127.0.0.1
listener: packet is 7 bytes long
listener: packet contains "Protect"
listener: waiting to recvfrom...
listener: got packet from 127.0.0.1
listener: packet is 4 bytes long
listener: packet contains "This"
listener: waiting to recvfrom...
listener: got packet from 127.0.0.1
listener: packet is 5 bytes long
listener: packet contains "House"
listener: waiting to recvfrom...
2It is not necessary to concatenate the individual words to recreate the original mes-
sage.
Programs should compile on the MTU Linux machines or a Mac to make it easy for
me to test them. Submit your source code to Canvas as well as any makefiles you
may create.

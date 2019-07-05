

CLASS_PATH_BIN=../out/production/network/
CLASS_PATH_C = ../c
CLASS_PATH_SRC = ../src
CLASS_PATH_JNI = ../jni

CFLAGS = -fPIC -I "/usr/lib/jvm/java-1.11.0-openjdk-amd64/include/" -I "/usr/lib/jvm/java-1.11.0-openjdk-amd64/include/linux/"


all : socket.so protocols.so types.so domains.so options.so interfaces.so

clean : rm $(CLASS_PATH_JNI)/socket_Socket.h $(CLASS_PATH_JNI)/socket.so $(CLASS_PATH_JNI)/exceptions.o $(CLASS_PATH_JNI)/socket_extlib.o $(CLASS_PATH_JNI)/socket_Domains.h $(CLASS_PATH_JNI)/socket_Types.h $(CLASS_PATH_JNI)/socket_Interfaces.h $(CLASS_PATH_JNI)/socket_Options.h $(CLASS_PATH_JNI)/socket_Protocols.h



socket.so : exceptions.o socket_extlib.o socket_Socket.h
					gcc $(CFLAGS) -shared -o socket.so $(CLASS_PATH_C)/socket.c exceptions.o socket_extlib.o
					
exceptions.o : $(CLASS_PATH_C)/exceptions.c $(CLASS_PATH_C)/exceptions.h
				gcc $(CFLAGS) -c $(CLASS_PATH_C)/exceptions.c
				
socket_extlib.o : $(CLASS_PATH_C)/socket_extlib.c $(CLASS_PATH_C)/socket_extlib.h
					gcc $(CFLAGS) -c $(CLASS_PATH_C)/socket_extlib.c


protocols.so : socket_Protocols.h
	gcc $(CFLAGS) -shared -o protocols.so $(CLASS_PATH_C)/protocols.c

types.so : socket_Types.h
	gcc $(CFLAGS) -shared -o types.so $(CLASS_PATH_C)/types.c

domains.so : socket_Domains.h
	gcc $(CFLAGS) -shared -o domains.so $(CLASS_PATH_C)/domains.c

options.so : socket_Options.h
	gcc $(CFLAGS) -shared -o options.so $(CLASS_PATH_C)/options.c

interfaces.so : socket_Interfaces.h
	gcc $(CFLAGS) -shared -o interfaces.so $(CLASS_PATH_C)/interfaces.c


					
socket_Socket.h : $(CLASS_PATH_BIN)/socket/Socket.class
			javac -d $(CLASS_PATH_BIN) -classpath $(CLASS_PATH_BIN)/ -h $(CLASS_PATH_JNI) $(CLASS_PATH_SRC)/socket/Socket.java
					
socket_Domains.h : $(CLASS_PATH_BIN)/socket/Domains.class
			javac -d $(CLASS_PATH_BIN) -classpath $(CLASS_PATH_BIN)/ -h $(CLASS_PATH_JNI) $(CLASS_PATH_SRC)/socket/Domains.java
			
socket_Interfaces.h : $(CLASS_PATH_BIN)/socket/Interfaces.class
			javac -d $(CLASS_PATH_BIN) -classpath $(CLASS_PATH_BIN)/ -h $(CLASS_PATH_JNI) $(CLASS_PATH_SRC)/socket/Interfaces.java

socket_Options.h : $(CLASS_PATH_BIN)/socket/Options.class
			javac -d $(CLASS_PATH_BIN) -classpath $(CLASS_PATH_BIN)/ -h $(CLASS_PATH_JNI) $(CLASS_PATH_SRC)/socket/Options.java
				
socket_Protocols.h : $(CLASS_PATH_BIN)/socket/Protocols.class
			javac -d $(CLASS_PATH_BIN) -classpath $(CLASS_PATH_BIN)/ -h $(CLASS_PATH_JNI) $(CLASS_PATH_SRC)/socket/Protocols.java
			
socket_Types.h : $(CLASS_PATH_BIN)/socket/Types.class
			javac -d $(CLASS_PATH_BIN) -classpath $(CLASS_PATH_BIN)/ -h $(CLASS_PATH_JNI) $(CLASS_PATH_SRC)/socket/Types.java
					
	

package test;

import jdk.jfr.Unsigned;
import primitives.Int;
import primitives.LongLongInt;
import primitives.ShortInt;
import sockaddr.sockaddr_in;
import socket.*;
import template.*;

import javax.xml.crypto.Data;
import java.io.Console;
import java.nio.ByteOrder;
import java.sql.Time;
import java.util.Scanner;


public class Main {


    public static void main(String [] args) throws Exception {

        Scanner in = new Scanner(System.in);

        System.out.println("Digita 1 se desideri aprire un server, 2 se desideri connetterti");

        int choice ;

        if ((choice = in.nextInt()) == 1) {

            JSocket server = new JSocket(Domains.AF_INET, Types.SOCK_STREAM, Protocols.DEFAULT);

            JSocket client;

            sockaddr_in addr = new sockaddr_in();

            addr.setVar("sin_family", new ShortInt((short)Domains.AF_INET.getDomain()));

            addr.setVar("sin_port", new ShortInt((short)Socket.htons(1600)));

            addr.setVar("in_addr", new sockaddr_in.in_addr( new Int((int)Interfaces.INADDR_ANY.getInterface()) ));

            try(Pointer pointer = new Pointer(DataTypes.len(addr))) {

                pointer.setValue(addr, ByteOrder.LITTLE_ENDIAN);

                if (server.bind(pointer))

                    System.out.println("Socket correttamente bindata");


                System.out.println("I'm waiting ... ");

                server.listen(1);

                client = server.accept(pointer);

            }

            client.send("ciao bello, siamo connessi!!",0);

            server.close();

        }

        else if (choice == 2){

            JSocket client = new JSocket(Domains.AF_INET, Types.SOCK_STREAM, Protocols.DEFAULT);

            sockaddr_in addr = new sockaddr_in();

            addr.setVar("sin_family", new ShortInt((short)Domains.AF_INET.getDomain()));

            addr.setVar("sin_port", new ShortInt((short) Socket.htons(1600)));

            byte[] ip = Socket.inet_pton(Domains.AF_INET.getDomain(), "192.168.1.34", DataTypes.len(addr.getVar("in_addr")));

            sockaddr_in.in_addr in_addr = new sockaddr_in.in_addr();

            DataTypes.cast(ip, in_addr);

            addr.setVar("in_addr", in_addr);

            try(Pointer pointer = new Pointer(DataTypes.len(addr))){

                pointer.setValue(addr, ByteOrder.LITTLE_ENDIAN);

                client.connect(pointer);

            }

            while(true) {

                byte[] msg = client.recv(40, 0);

                System.out.println(new String(msg));

                Thread.sleep(100);

                break;

            }

            client.close();

        }



    }
}

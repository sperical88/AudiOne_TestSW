#!/bin/bash

function  usage {
   echo "USAGE: $0 param..";
   echo "f  : build All";
   echo "s  : build TC_Server";
   echo "s  : build TC_Client";
   echo "a  : build TC_Audio";
   echo "x  : execute Services and Client";
   echo "sl : add shared lib. path to conf file";
   exit 0;
}
#add shared lib.
function add_shared_lib {
    echo "add_shared_lib";
    sudo echo "/home/worker/test_workspace/tc_demo_01/qt5-libs" | sudo tee /etc/ld.so.conf.d/tc_demo.conf
    sudo ldconfig -v | grep libQt
    echo "done";
}

#build TC_Server
function  build_server {
    echo "build_server";
    #g++ -c -fPIC -I/usr/include/x86_64-linux-gnu/qt5/ -I./include/ -o ./TC_Server/TC_Server.o ./TC_Server/TC_Server.cpp
    #./utils/moc -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtDBus -I/usr/include/x86_64-linux-gnu/qt5/QtCore ./TC_Server/TC_Server.h -o ./TC_Server/moc_TC_Server.cpp
    #g++ -c -fPIC -I/usr/include/x86_64-linux-gnu/qt5/ -o ./TC_Server/moc_TC_Server.o ./TC_Server/moc_TC_Server.cpp
    #g++ -fPIC -o ./TC_Server/TC_Server TC_Server/TC_Server.o ./TC_Server/moc_TC_Server.o -L/usr/lib/x86_64-linux-gnu/  -lQt5DBus -lQt5Core
    ./utils/moc -I./qt5-include//qt5 -I./qt5-include/qt5/QtDBus -I./qt5-include/qt5/QtCore ./TC_Server/TC_Server.h -o ./TC_Server/moc_TC_Server.cpp
    ./utils/moc -I./qt5-include//qt5 -I./qt5-include/qt5/QtDBus -I./qt5-include/qt5/QtCore ./TC_Thread/TC_Thread.h -o ./TC_Thread/moc_TC_Thread.cpp
    g++ -c -fPIC -I./qt5-include/qt5/ -I./include/ -o ./TC_Server/TC_Server.o ./TC_Server/TC_Server.cpp
    g++ -c -fPIC -I./qt5-include/qt5/ -I./include/ -o ./TC_Thread/TC_Thread.o ./TC_Thread/TC_Thread.cpp
    g++ -c -fPIC -I./qt5-include/qt5/ -I./include/ -o ./TC_Server/moc_TC_Server.o ./TC_Server/moc_TC_Server.cpp
    g++ -c -fPIC -I./qt5-include/qt5/ -I./include/ -o ./TC_Thread/moc_TC_Thread.o ./TC_Thread/moc_TC_Thread.cpp
    g++ -fPIC -o ./TC_Server/TC_Server TC_Server/TC_Server.o ./TC_Thread/TC_Thread.o \
            ./TC_Server/moc_TC_Server.o ./TC_Thread/moc_TC_Thread.o -L./qt5-libs -lQt5DBus -lQt5Core
    
    echo "done.";
}

#build TC_Client
function  build_client {
    echo "build_client";
    #g++ -fPIC -o ./TC_Client/TC_Client ./TC_Client/TC_Client.o -L/usr/lib/x86_64-linux-gnu/  -lQt5DBus -lQt5Core
    #g++ -c -fPIC -I/usr/include/x86_64-linux-gnu/qt5/ -I./include/ -o ./TC_Client/TC_Client.o ./TC_Client/TC_Client.cpp
    ./utils/moc -I./qt5-include/qt5 -I./qt5-include/qt5/QtDBus -I./qt5-include/qt5/QtCore ./TC_Client/TC_Client.h -o ./TC_Client/moc_TC_Client.cpp
    ./utils/moc -I./qt5-include/qt5 -I./qt5-include/qt5/QtDBus -I./qt5-include/qt5/QtCore ./TC_Thread/TC_Thread.h -o ./TC_Thread/moc_TC_Thread.cpp
	./utils/moc -I./qt5-include/qt5 -I./qt5-include/qt5/QtDBus -I./qt5-include/qt5/QtCore ./TC_Client/TC_ClientAdaptor.h -o ./TC_Client/moc_TC_ClientAdaptor.cpp
    g++ -c -fPIC -I./qt5-include/qt5/ -I./include/ -o ./TC_Client/TC_Client.o ./TC_Client/TC_Client.cpp
	g++ -c -fPIC -I./qt5-include/qt5/ -I./include/ -o ./TC_Client/TC_ClientAdaptor.o ./TC_Client/TC_ClientAdaptor.cpp
    g++ -c -fPIC -I./qt5-include/qt5/ -I./include/ -o ./TC_Thread/TC_Thread.o ./TC_Thread/TC_Thread.cpp
    g++ -c -fPIC -I./qt5-include/qt5/ -I./include/ -o ./TC_Client/moc_TC_Client.o ./TC_Client/moc_TC_Client.cpp
	g++ -c -fPIC -I./qt5-include/qt5/ -I./include/ -o ./TC_Client/moc_TC_ClientAdaptor.o ./TC_Client/moc_TC_ClientAdaptor.cpp
    g++ -c -fPIC -I./qt5-include/qt5/ -I./include/ -o ./TC_Thread/moc_TC_Thread.o ./TC_Thread/moc_TC_Thread.cpp
    g++ -fPIC -o ./TC_Client/TC_Client ./TC_Client/TC_Client.o ./TC_Client/moc_TC_Client.o ./TC_Thread/TC_Thread.o \
            ./TC_Thread/moc_TC_Thread.o -L./qt5-libs/  \
			./TC_Client/TC_ClientAdaptor.o ./TC_Client/moc_TC_ClientAdaptor.o -lQt5DBus -lQt5Core
    echo "done.";
}

#build TC_AudioService
function  build_audio {
    echo "build_audio";
    #./utils/moc -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtDBus -I/usr/include/x86_64-linux-gnu/qt5/QtCore ./TC_Audio/TC_AudioService.h -o ./TC_Audio/moc_TC_AudioService.cpp
    #g++ -c -fPIC -I/usr/include/x86_64-linux-gnu/qt5/ -I./include/ -o ./TC_Audio/TC_AudioService.o ./TC_Audio/TC_AudioService.cpp
    #g++ -c -fPIC -I/usr/include/x86_64-linux-gnu/qt5/ -o ./TC_Audio/moc_TC_AudioService.o ./TC_Audio/moc_TC_AudioService.cpp
    #g++ -fPIC -o ./TC_Audio/TC_AudioService ./TC_Audio/TC_AudioService.o ./TC_Audio/moc_TC_AudioService.o -L/usr/lib/x86_64-linux-gnu/  -lQt5DBus -lQt5Core
    ./utils/moc -I./qt5-include/qt5 -I./qt5-include/qt5/QtDBus -I./qt5-include/qt5/QtCore ./TC_Audio/TC_AudioService.h -o ./TC_Audio/moc_TC_AudioService.cpp
    g++ -c -fPIC -I./qt5-include/qt5/ -I./include/ -o ./TC_Audio/TC_AudioService.o ./TC_Audio/TC_AudioService.cpp
    g++ -c -fPIC -I./qt5-include/qt5/ -o ./TC_Audio/moc_TC_AudioService.o ./TC_Audio/moc_TC_AudioService.cpp
    g++ -fPIC -o ./TC_Audio/TC_AudioService ./TC_Audio/TC_AudioService.o ./TC_Audio/moc_TC_AudioService.o -L./qt5-libs/  -lQt5DBus -lQt5Core
    echo "done.";
}

#execute 
function  execute_default {
    echo "execute";
    ./TC_Server/TC_Server &
    #./TC_Audio/TC_AudioService &
    ./TC_Client/TC_Client
    echo "done.";
}

function  remove_all {
    echo "remove_all";
    rm -f ./TC_Server/*.o
    rm -f ./TC_Server/moc_*.*
    rm -f ./TC_Server/TC_Server
    rm -f ./TC_Client/*.o
    rm -f ./TC_Client/moc_*.*
    rm -f ./TC_Client/TC_Client
    rm -f ./TC_Audio/*.o
    rm -f ./TC_Audio/moc_*.*
    rm -f ./TC_Audio/TC_AudioService
    echo "done.";
}

function  remove_server {
    echo "remove_server";
    rm -f ./TC_Server/*.o
    rm -f ./TC_Server/moc_*.*
    rm -f ./TC_Server/TC_Server
    echo "done.";
}

function  remove_client {
    echo "remove_client";
    rm -f ./TC_Client/*.o
    rm -f ./TC_Client/moc_*.*
    rm -f ./TC_Client/TC_Client
    echo "done.";
}

function  remove_audio {
    echo "remove_audio";
    rm -f ./TC_Audio/*.o
    rm -f ./TC_Audio/moc_*.*
    rm -f ./TC_Audio/TC_AudioService
    echo "done.";
}


echo "Total Param= $#,  PROG: $0, param1 = $1";

#PARAM="f:c:a:x:h:rc:rf:rs:ra";

#getopts $PARAM opt;
#  echo "opt : $opt";
#  case $opt in
  echo "opt : $1";
  case $1 in
    f)
        build_server
        build_client
        build_audio
        exit 1;
        ;;
    s)
        build_server;
        exit 1;
        ;;
    c)
        build_client;
        exit 1;
        ;;
    a)
        build_audio;
        exit 1;
        ;;
    x)
        echo "x param";
        execute_default;
        exit 1;
        ;;
    rf)
        remove_all;
        exit 1;
        ;;
    rs)
        remove_server;
        exit 1;
        ;;
    rc)
        remove_client;
        exit 1;
        ;;
    ra)
        remove_audio;
        exit 1;
        ;;
    sl)
        add_shared_lib;
        exit 1;
        ;;
    h)
        usage;
         ;;
    *)
         ## default
         usage;
         exit 1;
         
  esac


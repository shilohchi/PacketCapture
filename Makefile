#############################################################################
# Makefile for building: PacketCapture
# Generated by qmake (2.01a) (Qt 4.8.4) on: Sat May 25 10:29:34 2013
# Project:  PacketCapture.pro
# Template: app
# Command: /usr/lib/i386-linux-gnu/qt4/bin/qmake -o Makefile PacketCapture.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_SQL_LIB -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -std=c++11 -include glog/logging.h -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4/QtSql -I/usr/include/qt4 -I. -Igui -Ithreads -Icxxpcap -Iutils -Idb -I. -I.
LINK          = g++
LFLAGS        = -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib/i386-linux-gnu -ltinyxpath -lglog -lpcap -lQtSql -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/lib/i386-linux-gnu/qt4/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		cxxpcap/DatalinkInfo.cpp \
		cxxpcap/InetPacket.cpp \
		cxxpcap/IPPacket.cpp \
		cxxpcap/Packet.cpp \
		cxxpcap/PacketCapture.cpp \
		cxxpcap/PacketFactory.cpp \
		cxxpcap/TCPPacket.cpp \
		cxxpcap/UDPPacket.cpp \
		db/MysqlPacketDetailDAO.cpp \
		db/PacketDetailDAOFactory.cpp \
		gui/MainWindow.cpp \
		threads/PacketConsumerThread.cpp \
		threads/PacketPool.cpp \
		threads/PacketProducerThread.cpp \
		utils/ConfigParser.cpp \
		utils/errors.cpp moc_MainWindow.cpp \
		moc_PacketConsumerThread.cpp \
		moc_PacketProducerThread.cpp \
		moc_TrafficCounter.cpp
OBJECTS       = main.o \
		DatalinkInfo.o \
		InetPacket.o \
		IPPacket.o \
		Packet.o \
		PacketCapture.o \
		PacketFactory.o \
		TCPPacket.o \
		UDPPacket.o \
		MysqlPacketDetailDAO.o \
		PacketDetailDAOFactory.o \
		MainWindow.o \
		PacketConsumerThread.o \
		PacketPool.o \
		PacketProducerThread.o \
		ConfigParser.o \
		errors.o \
		moc_MainWindow.o \
		moc_PacketConsumerThread.o \
		moc_PacketProducerThread.o \
		moc_TrafficCounter.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		PacketCapture.pro
QMAKE_TARGET  = PacketCapture
DESTDIR       = 
TARGET        = PacketCapture

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_MainWindow.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: PacketCapture.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/i386-linux-gnu/libQtSql.prl \
		/usr/lib/i386-linux-gnu/libQtGui.prl \
		/usr/lib/i386-linux-gnu/libQtCore.prl
	$(QMAKE) -o Makefile PacketCapture.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/i386-linux-gnu/libQtSql.prl:
/usr/lib/i386-linux-gnu/libQtGui.prl:
/usr/lib/i386-linux-gnu/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile PacketCapture.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/PacketCapture1.0.0 || $(MKDIR) .tmp/PacketCapture1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/PacketCapture1.0.0/ && $(COPY_FILE) --parents cxxpcap/cxxpcap.h cxxpcap/DatalinkInfo.h cxxpcap/InetPacket.h cxxpcap/IPPacket.h cxxpcap/Packet.h cxxpcap/PacketCapture.h cxxpcap/PacketFactory.h cxxpcap/TCPPacket.h cxxpcap/UDPPacket.h cxxpcap/utils.h db/IPacketDetailDAO.h db/MysqlPacketDetailDAO.h db/PacketDetail.h db/PacketDetailDAOFactory.h gui/MainWindow.h threads/PacketConsumerThread.h threads/PacketPool.h threads/PacketProducerThread.h threads/PoolWriter.h threads/TrafficCounter.h utils/ConfigParser.h utils/errors.h .tmp/PacketCapture1.0.0/ && $(COPY_FILE) --parents main.cpp cxxpcap/DatalinkInfo.cpp cxxpcap/InetPacket.cpp cxxpcap/IPPacket.cpp cxxpcap/Packet.cpp cxxpcap/PacketCapture.cpp cxxpcap/PacketFactory.cpp cxxpcap/TCPPacket.cpp cxxpcap/UDPPacket.cpp db/MysqlPacketDetailDAO.cpp db/PacketDetailDAOFactory.cpp gui/MainWindow.cpp threads/PacketConsumerThread.cpp threads/PacketPool.cpp threads/PacketProducerThread.cpp utils/ConfigParser.cpp utils/errors.cpp .tmp/PacketCapture1.0.0/ && $(COPY_FILE) --parents gui/MainWindow.ui .tmp/PacketCapture1.0.0/ && (cd `dirname .tmp/PacketCapture1.0.0` && $(TAR) PacketCapture1.0.0.tar PacketCapture1.0.0 && $(COMPRESS) PacketCapture1.0.0.tar) && $(MOVE) `dirname .tmp/PacketCapture1.0.0`/PacketCapture1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/PacketCapture1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_MainWindow.cpp moc_PacketConsumerThread.cpp moc_PacketProducerThread.cpp moc_TrafficCounter.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_MainWindow.cpp moc_PacketConsumerThread.cpp moc_PacketProducerThread.cpp moc_TrafficCounter.cpp
moc_MainWindow.cpp: ui_MainWindow.h \
		threads/PacketProducerThread.h \
		cxxpcap/cxxpcap.h \
		cxxpcap/PacketCapture.h \
		cxxpcap/utils.h \
		cxxpcap/Packet.h \
		cxxpcap/PacketFactory.h \
		cxxpcap/IPPacket.h \
		cxxpcap/InetPacket.h \
		cxxpcap/DatalinkInfo.h \
		cxxpcap/TCPPacket.h \
		cxxpcap/UDPPacket.h \
		threads/PacketPool.h \
		threads/TrafficCounter.h \
		threads/PoolWriter.h \
		threads/PacketConsumerThread.h \
		utils/ConfigParser.h \
		gui/MainWindow.h
	/usr/lib/i386-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) gui/MainWindow.h -o moc_MainWindow.cpp

moc_PacketConsumerThread.cpp: threads/PacketPool.h \
		cxxpcap/Packet.h \
		threads/PacketConsumerThread.h
	/usr/lib/i386-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) threads/PacketConsumerThread.h -o moc_PacketConsumerThread.cpp

moc_PacketProducerThread.cpp: cxxpcap/cxxpcap.h \
		cxxpcap/PacketCapture.h \
		cxxpcap/utils.h \
		cxxpcap/Packet.h \
		cxxpcap/PacketFactory.h \
		cxxpcap/IPPacket.h \
		cxxpcap/InetPacket.h \
		cxxpcap/DatalinkInfo.h \
		cxxpcap/TCPPacket.h \
		cxxpcap/UDPPacket.h \
		threads/PacketPool.h \
		threads/TrafficCounter.h \
		threads/PoolWriter.h \
		threads/PacketProducerThread.h
	/usr/lib/i386-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) threads/PacketProducerThread.h -o moc_PacketProducerThread.cpp

moc_TrafficCounter.cpp: cxxpcap/cxxpcap.h \
		cxxpcap/PacketCapture.h \
		cxxpcap/utils.h \
		cxxpcap/Packet.h \
		cxxpcap/PacketFactory.h \
		cxxpcap/IPPacket.h \
		cxxpcap/InetPacket.h \
		cxxpcap/DatalinkInfo.h \
		cxxpcap/TCPPacket.h \
		cxxpcap/UDPPacket.h \
		threads/TrafficCounter.h
	/usr/lib/i386-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) threads/TrafficCounter.h -o moc_TrafficCounter.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_MainWindow.h
compiler_uic_clean:
	-$(DEL_FILE) ui_MainWindow.h
ui_MainWindow.h: gui/MainWindow.ui
	/usr/lib/i386-linux-gnu/qt4/bin/uic gui/MainWindow.ui -o ui_MainWindow.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

main.o: main.cpp gui/MainWindow.h \
		ui_MainWindow.h \
		threads/PacketProducerThread.h \
		cxxpcap/cxxpcap.h \
		cxxpcap/PacketCapture.h \
		cxxpcap/utils.h \
		cxxpcap/Packet.h \
		cxxpcap/PacketFactory.h \
		cxxpcap/IPPacket.h \
		cxxpcap/InetPacket.h \
		cxxpcap/DatalinkInfo.h \
		cxxpcap/TCPPacket.h \
		cxxpcap/UDPPacket.h \
		threads/PacketPool.h \
		threads/TrafficCounter.h \
		threads/PoolWriter.h \
		threads/PacketConsumerThread.h \
		utils/ConfigParser.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

DatalinkInfo.o: cxxpcap/DatalinkInfo.cpp cxxpcap/DatalinkInfo.h \
		cxxpcap/utils.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o DatalinkInfo.o cxxpcap/DatalinkInfo.cpp

InetPacket.o: cxxpcap/InetPacket.cpp cxxpcap/InetPacket.h \
		cxxpcap/Packet.h \
		cxxpcap/utils.h \
		cxxpcap/DatalinkInfo.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o InetPacket.o cxxpcap/InetPacket.cpp

IPPacket.o: cxxpcap/IPPacket.cpp cxxpcap/IPPacket.h \
		cxxpcap/InetPacket.h \
		cxxpcap/Packet.h \
		cxxpcap/utils.h \
		cxxpcap/DatalinkInfo.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o IPPacket.o cxxpcap/IPPacket.cpp

Packet.o: cxxpcap/Packet.cpp cxxpcap/Packet.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Packet.o cxxpcap/Packet.cpp

PacketCapture.o: cxxpcap/PacketCapture.cpp cxxpcap/PacketCapture.h \
		cxxpcap/utils.h \
		cxxpcap/Packet.h \
		cxxpcap/PacketFactory.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o PacketCapture.o cxxpcap/PacketCapture.cpp

PacketFactory.o: cxxpcap/PacketFactory.cpp cxxpcap/PacketFactory.h \
		cxxpcap/utils.h \
		cxxpcap/Packet.h \
		cxxpcap/InetPacket.h \
		cxxpcap/DatalinkInfo.h \
		cxxpcap/IPPacket.h \
		cxxpcap/UDPPacket.h \
		cxxpcap/TCPPacket.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o PacketFactory.o cxxpcap/PacketFactory.cpp

TCPPacket.o: cxxpcap/TCPPacket.cpp cxxpcap/TCPPacket.h \
		cxxpcap/IPPacket.h \
		cxxpcap/InetPacket.h \
		cxxpcap/Packet.h \
		cxxpcap/utils.h \
		cxxpcap/DatalinkInfo.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o TCPPacket.o cxxpcap/TCPPacket.cpp

UDPPacket.o: cxxpcap/UDPPacket.cpp cxxpcap/UDPPacket.h \
		cxxpcap/IPPacket.h \
		cxxpcap/InetPacket.h \
		cxxpcap/Packet.h \
		cxxpcap/utils.h \
		cxxpcap/DatalinkInfo.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o UDPPacket.o cxxpcap/UDPPacket.cpp

MysqlPacketDetailDAO.o: db/MysqlPacketDetailDAO.cpp db/MysqlPacketDetailDAO.h \
		db/IPacketDetailDAO.h \
		db/PacketDetail.h \
		utils/errors.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o MysqlPacketDetailDAO.o db/MysqlPacketDetailDAO.cpp

PacketDetailDAOFactory.o: db/PacketDetailDAOFactory.cpp db/PacketDetailDAOFactory.h \
		db/IPacketDetailDAO.h \
		db/PacketDetail.h \
		db/MysqlPacketDetailDAO.h \
		utils/errors.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o PacketDetailDAOFactory.o db/PacketDetailDAOFactory.cpp

MainWindow.o: gui/MainWindow.cpp gui/MainWindow.h \
		ui_MainWindow.h \
		threads/PacketProducerThread.h \
		cxxpcap/cxxpcap.h \
		cxxpcap/PacketCapture.h \
		cxxpcap/utils.h \
		cxxpcap/Packet.h \
		cxxpcap/PacketFactory.h \
		cxxpcap/IPPacket.h \
		cxxpcap/InetPacket.h \
		cxxpcap/DatalinkInfo.h \
		cxxpcap/TCPPacket.h \
		cxxpcap/UDPPacket.h \
		threads/PacketPool.h \
		threads/TrafficCounter.h \
		threads/PoolWriter.h \
		threads/PacketConsumerThread.h \
		utils/ConfigParser.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o MainWindow.o gui/MainWindow.cpp

PacketConsumerThread.o: threads/PacketConsumerThread.cpp cxxpcap/cxxpcap.h \
		cxxpcap/PacketCapture.h \
		cxxpcap/utils.h \
		cxxpcap/Packet.h \
		cxxpcap/PacketFactory.h \
		cxxpcap/IPPacket.h \
		cxxpcap/InetPacket.h \
		cxxpcap/DatalinkInfo.h \
		cxxpcap/TCPPacket.h \
		cxxpcap/UDPPacket.h \
		threads/PacketConsumerThread.h \
		threads/PacketPool.h \
		db/PacketDetailDAOFactory.h \
		db/IPacketDetailDAO.h \
		db/PacketDetail.h \
		db/MysqlPacketDetailDAO.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o PacketConsumerThread.o threads/PacketConsumerThread.cpp

PacketPool.o: threads/PacketPool.cpp threads/PacketPool.h \
		cxxpcap/Packet.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o PacketPool.o threads/PacketPool.cpp

PacketProducerThread.o: threads/PacketProducerThread.cpp threads/PacketProducerThread.h \
		cxxpcap/cxxpcap.h \
		cxxpcap/PacketCapture.h \
		cxxpcap/utils.h \
		cxxpcap/Packet.h \
		cxxpcap/PacketFactory.h \
		cxxpcap/IPPacket.h \
		cxxpcap/InetPacket.h \
		cxxpcap/DatalinkInfo.h \
		cxxpcap/TCPPacket.h \
		cxxpcap/UDPPacket.h \
		threads/PacketPool.h \
		threads/TrafficCounter.h \
		threads/PoolWriter.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o PacketProducerThread.o threads/PacketProducerThread.cpp

ConfigParser.o: utils/ConfigParser.cpp utils/ConfigParser.h \
		utils/errors.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ConfigParser.o utils/ConfigParser.cpp

errors.o: utils/errors.cpp utils/errors.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o errors.o utils/errors.cpp

moc_MainWindow.o: moc_MainWindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_MainWindow.o moc_MainWindow.cpp

moc_PacketConsumerThread.o: moc_PacketConsumerThread.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_PacketConsumerThread.o moc_PacketConsumerThread.cpp

moc_PacketProducerThread.o: moc_PacketProducerThread.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_PacketProducerThread.o moc_PacketProducerThread.cpp

moc_TrafficCounter.o: moc_TrafficCounter.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_TrafficCounter.o moc_TrafficCounter.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:


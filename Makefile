# default target

.DEFAULT_GOAL := build

# compiler

GCC = gcc

# linker flags

LF1 = -Wall
LF2 = -Werror
LF3 = -fPIC

# libsodium(dev) required

CMP = -c

LIB = /usr/local

build:
	@echo "compiling and building shared object file"
	
	@${GCC} ${CMP} ${LF1} ${LF2} ${LF3} -lsodium lib-jmgeneral.c
	@${GCC} ${CMP} ${LF1} ${LF2} ${LF3} lib-jmstring.c
	@${GCC} ${CMP} ${LF1} ${LF2} ${LF3} lib-jmfileprocess.c
	@${GCC} -shared -o lib-jmgeneral.so *.o
	
	@echo "shared object file built"
  
install:
	# make include directory as needed then copy header into place
	@echo "installing header file"
	@[ -d ${LIB}/include ] || mkdir -p ${LIB}/include
	@cp lib-jmgeneral.h ${LIB}/include/
	# make lib directory as needed then copy .so into place
	@echo "installing share object file"
	@[ -d ${LIB}/lib ] || mkdir -p ${LIB}/lib
	@cp lib-jmgeneral.so ${LIB}/lib/
	
	@echo "you may need to export LD_LIBRARY_PATH=${LIB} via bashrc or profile"

uninstall:
	@rm ${LIB}/include/lib-jmgeneral.h
	@rm ${LIB}/lib/lib-jmgeneral.so
	@echo "installed files removed"
  
clean:
	@rm ./*.o
	@rm ./*.so
	@echo "directory cleaned for next compilation"

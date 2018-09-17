CXX = g++
FLAG = -std=c++11 -g

SRC  = ${wildcard *.cpp} 
EXEC = ${patsubst %.cpp, %, ${SRC}} 

.PHONY: test

.PHONY: clean


all: ${EXEC}

%: %.cpp
	${CXX} $^ -o $@ ${FLAG}

test:
	@echo ${SRC}
	@echo ${EXEC}

clean:
	rm -f ${EXEC}

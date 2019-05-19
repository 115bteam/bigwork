all:main
main:main.o nfunc.o OnePara.o TwoPara.o ThreePara.o calculation.o makefile
	g++ -o main main.o nfunc.o OnePara.o TwoPara.o ThreePara.o calculation.o -std=c++14
main.o:main.cpp
	g++ -c main.cpp -std=c++14
nfunc.o:nfunc.cpp nfunc.h
	g++ -c nfunc.cpp -std=c++14
OnePara.o:OnePara.cpp OnePara.h
	g++ -c OnePara.cpp -std=c++14
TwoPara.o:TwoPara.cpp TwoPara.h
	g++ -c TwoPara.cpp -std=c++14
ThreePara.o:ThreePara.cpp ThreePara.h
	g++ -c ThreePara.cpp -std=c++14
calculation.o:calculation.cpp calculation.h
	g++ -c calculation.cpp -std=c++14
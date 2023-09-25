CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS=-g $(shell root-config --cflags)
LDFLAGS=-g $(shell root-config --ldflags)
LDLIBS=$(shell root-config --libs)

main: neuralNetwork.o vectors.o

neuralNetwork.o : neuralNetwork.hpp pbPlots.hpp supportLib.hpp vectors.hpp
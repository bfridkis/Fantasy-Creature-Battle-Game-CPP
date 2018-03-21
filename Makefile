##########################################################
## Program name: Makefile
## Author: Benjamin Fridkis
## Date: 5/17/17
## Description: Makefile for Project 4 (Fantasy Creature
##				Battle Tournament)
##########################################################

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
#CXXFLAGS += Werror
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#CXXFLAGS+= -03
#LDFLAGS = -lboost_date_time

OBJS = Creature.o Vampire.o Barbarian.o BlueMen.o Medusa.o HarryPotter.o battle.o InputValidation.o MenuInputValidation.o Menu.o CreatureMenu.o mainProject4.o CreatureQueue.o LoserStack.o battleTournament.o

SRCS = Creature.cpp Vampire.cpp Barbarian.cpp BlueMen.cpp Medusa.cpp HarryPotter.cpp battle.cpp InputValidation.cpp MenuInputValidation.cpp Menu.cpp CreatureMenu.cpp mainProject4.cpp CreatureQueue.cpp LoserStack.cpp battleTournament.cpp

HEADERS = Creature.hpp Vampire.hpp Barbarian.hpp BlueMen.hpp Medusa.hpp HarryPotter.hpp battle.hpp InputValidation.hpp MenuInputValidation.hpp Menu.hpp CreatureMenu.cpp mainProject4.hpp CreatureQueue.hpp LoserStack.hpp battleTournament.hpp 

PROGRAM_NAME = mainProject4

${PROGRAM_NAME}: ${OBJS}
	${CXX} ${LDFLAGS} ${OBJS} -o ${PROGRAM_NAME}

Creature.o : Creature.cpp
	${CXX} ${CXXFLAGS} -c Creature.cpp
Vampire.o : Vampire.cpp
	${CXX} ${CXXFLAGS} -c Vampire.cpp 
Barbarian.o : Barbarian.cpp
	${CXX} ${CXXFLAGS} -c Barbarian.cpp 
BlueMen.o : BlueMen.cpp
	${CXX} ${CXXFLAGS} -c BlueMen.cpp 
Medusa.o : Medusa.cpp
	${CXX} ${CXXFLAGS} -c Medusa.cpp 
HarryPotter.o : HarryPotter.cpp
	${CXX} ${CXXFLAGS} -c HarryPotter.cpp 
battle.o : battle.cpp
	${CXX} ${CXXFLAGS} -c battle.cpp 
InputValidation.o : InputValidation.cpp
	${CXX} ${CXXFLAGS} -c InputValidation.cpp 
MenuInputValidation.o : MenuInputValidation.cpp
	${CXX} ${CXXFLAGS} -c MenuInputValidation.cpp 
Menu.o : Menu.cpp
	${CXX} ${CXXFLAGS} -c Menu.cpp 
CreatureMenu.o : CreatureMenu.cpp
	${CXX} ${CXXFLAGS} -c CreatureMenu.cpp 
mainProject4.o : mainProject4.cpp
	${CXX} ${CXXFLAGS} -c mainProject4.cpp 
CreatureQueue.o : CreatureQueue.cpp
	${CXX} ${CXXFLAGS} -c CreatureQueue.cpp 
LoserStack.o : LoserStack.cpp
	${CXX} ${CXXFLAGS} -c LoserStack.cpp 
battleTournament.o : battleTournament.cpp
	${CXX} ${CXXFLAGS} -c battleTournament.cpp 		
	
run:
	./${PROGRAM_NAME}
	
clean:
	rm *.o ${PROGRAM_NAME}

# Usage:
# make        # compile all binary
# make clean  # remove ALL binaries and objects

.PHONY = all clean

CPP = g++			# compiler to use

LINKERFLAG = -lm

SRCDINVEN := driver/DriverAbility.cpp
LIBIMPLEMENTATION := implementation/*.cpp
LIBCARD := ../../Cards/implementation/Card.cpp
LIBPLAYER := ../../Player/implementation/Player.cpp
OUTPUTINVEN := ../../../bin/Ability

All: runAbility cleanAbility

compileAbility:
	@echo "Makefile: compiling Ability driver.."
	$(CPP) $(SRCDINVEN) $(LIBIMPLEMENTATION) $(LIBPCARD) $(LIBPLAYER) -o $(OUTPUTINVEN)

runAbility: compileAbility
	@echo "Makefile: Running Ability driver.."
	$(OUTPUTINVEN)

cleanAbility:
	@echo "Makefile: Cleaning up inventory..."
	rm -rvf $(OUTPUTINVEN)
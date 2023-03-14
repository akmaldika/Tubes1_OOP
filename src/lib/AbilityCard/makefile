# Usage:
# make        # compile all binary
# make clean  # remove ALL binaries and objects

.PHONY = all clean

# compiler to use
CPP = g++

LINKERFLAG = -lm

# src
SRCABILITYCARD := driver/DriverAbilityCard.cpp

# lib
LIBIMPLEMENTATION := implementation/*.cpp
LIBINVENTORYHOLDER := ../InventoryHolder/implementation/*.cpp
LIBCARDS := ../Cards/implementation/*.cpp

LIBCARD := ../Cards/implementation/Card.cpp
LIBDECKCARD := ../InventoryHolder/implementation/DeckCard.cpp
LIBPLAYERCARD := ../InventoryHolder/implementation/PlayerCard.cpp
LIBPLAYER := ../Player/implementation/Player.cpp
LIBGAMESTATE := ../GameState/implementation/GameState.cpp

# out
OUTPUTABILITYCARD := ../../../bin/AbilityCard

# color; must using echo before
ccred := "\e\033[0;31m"
ccgreen := "\e\033[32;1m"
ccend := "\e\033[0m"


All: compile run clean

compile:
	@echo $(ccgreen)"Makefile: compiling Ability driver.." $(ccend)
	$(CPP) $(LINKERFLAG) $(SRCABILITYCARD) $(LIBIMPLEMENTATION) $(LIBCARDS) $(LIBINVENTORYHOLDER) $(LIBPLAYER) $(LIBGAMESTATE) -o $(OUTPUTABILITYCARD)

run: 
	@echo $(ccgreen)"Makefile: Running Ability driver.." $(ccend)
	@echo
	$(OUTPUTABILITYCARD)

clean:
	@echo
	@echo $(ccgreen)"Makefile: Cleaning up inventory..." $(ccend)
	@rm -rvf $(OUTPUTABILITYCARD)
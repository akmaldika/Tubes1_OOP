# Usage:
# make        # compile all binary
# make clean  # remove ALL binaries and objects

.PHONY = all clean

CPP = g++			# compiler to use

LINKERFLAG = -lm

SRCDP := driver/driverPlayer.cpp
LIBPLAYER := implementation/StandardPlayer.cpp
LIBCARD := ../Cards/implementation/Card.cpp
LIBPCARD := ../InventoryHolder/implementation/PlayerCard.cpp
LIBDCARD := ../InventoryHolder/implementation/DeckCard.cpp
LIBDCOMB := ../Cards/implementation/Combo.cpp
# LIBTCARD := ../InventoryHolder/implementation/TableCard.cpp
LIBP := implementation/Player.cpp
OUTPUTP := ../../../bin/player

player: 
	@echo "Compiling player driver.."
	$(CPP) $(SRCDP) $(LIBPLAYER) $(LIBCARD) $(LIBPCARD) $(LIBDCARD) $(LIBP) $(LIBDCOMB) -o $(OUTPUTP)

runPlayer:
	$(OUTPUTP)

cleanPlayer:
	@echo "Cleaning up player..."
	rm -rvf $(OUTPUTP)
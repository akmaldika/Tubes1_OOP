# Usage:
# make        # compile all binary
# make clean  # remove ALL binaries and objects

.PHONY = all clean

CPP = g++			# compiler to use

LINKERFLAG = -lm

SRCDINVEN := driver/DriverInventoryHolder.cpp
LIBCARD := ../Cards/implementation/Card.cpp
LIBPCARD := implementation/PlayerCard.cpp
LIBDCARD := implementation/DeckCard.cpp
LIBTCARD := implementation/TableCard.cpp
OUTPUTINVEN := ../../../bin/inventoryholder

inventory: 
	@echo "Compiling inventory driver.."
	$(CPP) $(SRCDINVEN) $(LIBCARD) $(LIBPCARD) $(LIBDCARD) $(LIBTCARD) -o $(OUTPUTINVEN)

runInventory:
	$(OUTPUTINVEN)

cleanInventory:
	@echo "Cleaning up inventory..."
	rm -rvf $(OUTPUTINVEN)
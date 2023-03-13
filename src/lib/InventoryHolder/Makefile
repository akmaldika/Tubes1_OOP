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
LIBDACARD := implementation/DeckAbilityCard.cpp
LIBTCARD := implementation/TableCard.cpp
LIBA1 := ../AbilityCard/AbilityCard.cpp
LIBA2 := ../AbilityCard/Abilityless.cpp
LIBA3 := ../AbilityCard/Quadruple.cpp
LIBA4 := ../AbilityCard/Quarter.cpp
LIBA5 := ../AbilityCard/Reroll.cpp
LIBA6 := ../AbilityCard/ReverseDirection.cpp
LIBA7 := ../AbilityCard/SwapCard.cpp
LIBA8 := ../AbilityCard/Switch.cpp
OUTPUTINVEN := ../../../bin/inventoryholder

inventory: 
	@echo "Compiling inventory driver.."
	$(CPP) $(SRCDINVEN) $(LIBCARD) $(LIBPCARD) $(LIBDCARD) $(LIBDACARD) $(LIBTCARD) $(LIBA1) $(LIBA2) $(LIBA3) $(LIBA4) $(LIBA5) $(LIBA6) $(LIBA7) $(LIBA8) -o $(OUTPUTINVEN)

runInventory:
	$(OUTPUTINVEN)

cleanInventory:
	@echo "Cleaning up inventory..."
	rm -rvf $(OUTPUTINVEN)
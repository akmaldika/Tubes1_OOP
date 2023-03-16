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
LIBA1 := ../AbilityCard/implementation/AbilityCard.cpp
LIBA2 := ../AbilityCard/implementation/Abilityless.cpp
LIBA3 := ../AbilityCard/implementation/Quadruple.cpp
LIBA4 := ../AbilityCard/implementation/Quarter.cpp
LIBA5 := ../AbilityCard/implementation/Reroll.cpp
LIBA6 := ../AbilityCard/implementation/ReverseDirection.cpp
LIBA7 := ../AbilityCard/implementation/SwapCard.cpp
LIBA8 := ../AbilityCard/implementation/Switch.cpp
LIBEXC := ../Exceptions/implementation/Exceptions.cpp
OUTPUTINVEN := ../../../bin/inventoryholder

SRCPCAPSA := driver/DriverPlayerCapsaCard.cpp
LIBPCAPSA := implementation/PlayerCapsaCard.cpp
LIBCARDC := ../Cards/implementation/CapsaCard.cpp
LIBCOMBO := ../Cards/implementation/Combo.cpp
OUTPUTPCAPSA := ../../../bin/playercapsacard

all: inventory runInventory

inventory: 
	@echo "Compiling inventory driver.."
	$(CPP) $(SRCDINVEN) $(LIBCARD) $(LIBPCARD) $(LIBDCARD) $(LIBDACARD) $(LIBTCARD) $(LIBA1) $(LIBA2) $(LIBA3) $(LIBA4) $(LIBA5) $(LIBA6) $(LIBA7) $(LIBA8) $(LIBEXC) -o $(OUTPUTINVEN)

playerCapsa:
	@echo "Compiling player capsa.."
	$(CPP) $(SRCPCAPSA) $(LIBCARD) $(LIBPCAPSA) $(LIBCARDC) $(LIBCOMBO) -o $(OUTPUTPCAPSA)

runInventory:
	$(OUTPUTINVEN)

runPlayerCapsa:
	$(OUTPUTPCAPSA)

cleanInventory:
	@echo "Cleaning up inventory..."
	rm -rvf $(OUTPUTINVEN)
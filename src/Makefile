CPP := g++

SRCTES := tes.cpp

SRCMAIN := main.cpp
LIBSTATE := lib/GameState/implementation/GameState.cpp
LIBPLAYER := lib/Player/implementation/Player.cpp
LIBCARD := lib/Cards/implementation/Card.cpp
LIBCOMBO := lib/Cards/implementation/Combo.cpp
LIBPCARD := lib/InventoryHolder/implementation/PlayerCard.cpp
LIBDCARD := lib/InventoryHolder/implementation/DeckCard.cpp
LIBDACARD := lib/InventoryHolder/implementation/DeckAbilityCard.cpp
LIBTCARD := lib/InventoryHolder/implementation/TableCard.cpp

LIBA1 := lib/AbilityCard/implementation/AbilityCard.cpp
LIBA2 := lib/AbilityCard/implementation/Abilityless.cpp
LIBA3 := lib/AbilityCard/implementation/Quadruple.cpp
LIBA4 := lib/AbilityCard/implementation/Quarter.cpp
LIBA5 := lib/AbilityCard/implementation/Reroll.cpp
LIBA6 := lib/AbilityCard/implementation/ReverseDirection.cpp
LIBA7 := lib/AbilityCard/implementation/SwapCard.cpp
LIBA8 := lib/AbilityCard/implementation/Switch.cpp
OUTPUT := ../bin/main

main: 
	@echo "Compiling main.."
	$(CPP) $(SRCMAIN) $(LIBSTATE) $(LIBPLAYER) $(LIBCARD) $(LIBCOMBO) $(LIBPCARD) $(LIBDCARD) $(LIBDACARD) $(LIBTCARD) $(LIBA1) $(LIBA2) $(LIBA3) $(LIBA4) $(LIBA5) $(LIBA6) $(LIBA7) $(LIBA8) -o $(OUTPUTINVEN)

tes:
	@echo "Compiling main.."
	$(CPP) $(SRCTES) $(LIBSTATE) $(LIBPLAYER) $(LIBCARD) $(LIBCOMBO) $(LIBPCARD) $(LIBDCARD) $(LIBDACARD) $(LIBTCARD) $(LIBA1) $(LIBA2) $(LIBA3) $(LIBA4) $(LIBA5) $(LIBA6) $(LIBA7) $(LIBA8) -o $(OUTPUTINVEN)

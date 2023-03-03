

SRC := DriverGameState.cpp
LIB := implementation/GameState.cpp
LIBPLAYER := ../Player/Player.cpp
LIBTABLECARD := ../InventoryHolder/header/TableCard.hpp
LIBDECKCARD := ../InventoryHolder/header/DeckCard.hpp
LIBPLAYERCARD := ../InventoryHolder/header/PlayerCard.hpp
OUTPUT:= ../../../bin/gamestate

run:
	@echo "Compiling gamestate driver"
	g++ $(SRC) $(LIB) $(LIBPLAYER) $(LIBTABLECARD) $(LIBDECKCARD) $(LIBPLAYERCARD) -o $(OUTPUT)
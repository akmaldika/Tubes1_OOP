# Usage:
# make        # compile all binary
# make clean  # remove ALL binaries and objects

.PHONY = all clean

CPP = g++			# compiler to use

LINKERFLAG = -lm

SRCDCARD := driver/driverCard.cpp
LIBDCARD := implementation/Card.cpp
LIBDCOMB := implementation/Combo.cpp
SRCDCOMB := driver/driverCombo.cpp
OUTPUTCARD := ../../../bin/card
OUTPUTCOMB := ../../../bin/combo

card: 
	@echo "Compiling card driver.."
	$(CPP) $(SRCDCARD) $(LIBDCARD) -o $(OUTPUTCARD)
combo: 
	@echo "Compiling combination driver.."
	$(CPP) $(SRCDCOMB) $(LIBDCOMB) $(LIBDCARD) -o $(OUTPUTCOMB)

runcard:
	$(OUTPUTCARD)
runcombo:
	$(OUTPUTCOMB)

cleanCard:
	@echo "Cleaning up card..."
	rm -rvf $(OUTPUTCARD)
cleanCombination:
	@echo "Cleaning up combination..."
	rm -rvf $(OUTPUTCOMB)
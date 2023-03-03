# Usage:
# make        # compile all binary
# make clean  # remove ALL binaries and objects

.PHONY = all clean

CPP = g++			# compiler to use

LINKERFLAG = -lm

SRCDCARD := driver/driverCard.cpp
LIBDCARD := implementation/Card.cpp
LIBDCOMB := implementation/Combination.cpp
SRCDCOMB := driver/driverCombination.cpp
OUTPUTCARD := ../../../bin/card
OUTPUTCOMB := ../../../bin/combination 

card: 
	@echo "Compiling card driver.."
	$(CPP) $(SRCDCARD) $(LIBDCARD) -o $(OUTPUTCARD)
combination: 
	@echo "Compiling combination driver.."
	$(CPP) $(SRCDCOMB) $(LIBDCOMB) -o $(OUTPUTCOMB)

runcard:
	$(OUTPUTCARD)
runcombination:
	$(OUTPUTCOMB)

cleanCard:
	@echo "Cleaning up card..."
	rm -rvf $(OUTPUTCARD)
cleanCombination:
	@echo "Cleaning up combination..."
	rm -rvf $(OUTPUTCOMB)
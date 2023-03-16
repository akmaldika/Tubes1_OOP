# Usage:
# make        # compile all binary
# make clean  # remove ALL binaries and objects

.PHONY = all clean

CPP = g++			# compiler to use

LINKERFLAG = -lm

SRCDCARD := driver/driverCard.cpp
SRCDCAPCARD := driver/driverCapsaCard.cpp
LIBDCARD := implementation/Card.cpp
LIBDCOMB := implementation/Combo.cpp
LIBDCAPCARD := implementation/CapsaCard.cpp
SRCDCOMB := driver/driverCombo.cpp
OUTPUTCARD := ../../../bin/card
OUTPUTCAPCARD := ../../../bin/capsaCard
OUTPUTCOMB := ../../../bin/combo

card: 
	@echo "Compiling card driver.."
	$(CPP) $(SRCDCARD) $(LIBDCARD) -o $(OUTPUTCARD)
combo: 
	@echo "Compiling combo driver.."
	$(CPP) $(SRCDCOMB) $(LIBDCOMB) $(LIBDCARD) -o $(OUTPUTCOMB)
capsa:
	@echo "Compiling capsa driver.."
	$(CPP) $(SRCDCAPCARD) $(LIBDCAPCARD) -o $(OUTPUTCAPCARD)

runcard:
	$(OUTPUTCARD)
runcombo:
	$(OUTPUTCOMB)
runcapsa:
	$(OUTPUTCAPCARD)

cleanCard:
	@echo "Cleaning up card..."
	rm -rvf $(OUTPUTCARD)
cleanCombination:
	@echo "Cleaning up combination..."
	rm -rvf $(OUTPUTCOMB)
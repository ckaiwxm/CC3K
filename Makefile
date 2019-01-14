CXX=g++
CXXFLAGS=-std=c++14 -Wextra -Wpedantic -Wall -Werror=vla -MMD -g
OBJECTS=main.o Blank.o Door.o Floor.o Tile.o HWall.o VWall.o Object.o Passage.o Space.o Stair.o TextDisplay.o DragonHoard.o Gold.o MerchantHoard.o Normal.o Small.o BoostAtk.o BoostDef.o PoisonHP.o Potion.o RestoreHP.o WoundAtk.o WoundDef.o Character.o Drow.o Goblin.o Player.o Shade.o Troll.o Vampire.o Dwarf.o Elf.o Enemy.o Halfling.o Human.o Merchant.o Orcs.o Dragon.o 
DEPENDS=${OBJECTS:.o=.d}
EXEC=cc3k

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}
.PHONY: clean

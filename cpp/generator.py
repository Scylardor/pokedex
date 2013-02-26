#!/usr/bin/python

def printQRCLine(num, dirName, extension, appendZeros):
    fileName = ""
    if appendZeros:
        if num < 10:
            fileName = "00"
        elif num > 9 and num < 100:
            fileName = "0"
    fileName += str(num) + extension
    line = "\t<file alias=\"" + dirName + "/" + fileName + "\">"
    line += "../resources/Images/" + dirName + "/" + fileName + "</file>"
    print line
    

def main():
    for i in range(1, 494):
        printQRCLine(i, "Miniatures", ".gif", True)
    for i in range(1, 494):
        printQRCLine(i, "Pokemons", ".png", False)
    types = ["None", "Fire", "Water", "Grass", "Bug", "Electric", "Flying", "Poison", "Dragon", "Ice", "Normal", "Rock", "Ground", "Fighting", "Psychic", "Ghost", "Steel", "Dark"]
    for oneType in types:
        printQRCLine(oneType, "Types", ".png", False)
    return 0

if __name__ == "__main__":
    main()

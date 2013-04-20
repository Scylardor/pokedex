import os
import sys

from PyQt4 import QtGui, QtCore

import PokedexResources
from QPokedex import QPokedex

def main():
    app = QtGui.QApplication(sys.argv)
    pokedex = QPokedex(745, 540, ":/PokedexOff.png")     
    pokedex.show()

    sys.exit(app.exec_())


if __name__ == "__main__":
    main()

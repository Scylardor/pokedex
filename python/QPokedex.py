from PyQt4 import QtGui
from PyQt4.QtGui import QMainWindow, QPushButton, QPalette, QPixmap, QBrush

import helpers
import PokedexResources

class   QPokedex(QMainWindow):
    """The main class of the project. It is used to render the Pokedex at screen,
    and contains all the needed other parts (left screen, right screen, button, etc.).
    It also handles the connection to the 'database', which is for the moment populated
    by two XML files.

    """

    POKEDEX_ON_IMG =            ":/PokedexOn.png"
    POKEDEX_OFF_IMG =           ":/PokedexOff.png"
    POKEDEX_ON_BTN_IMG =        ":/boutonON.png"
    
    def __init__(self, width, height, backgroundImg):
        super(QPokedex, self).__init__()

        # Initialize the window itself.
        self.resize(width, height)
        self.setBackgroundImage(self.POKEDEX_OFF_IMG)
        self.setWindowTitle('Pokedex')

        # Initialize the buttons.
        self.onOff = False        
        self.onOffButton = QPushButton("START", self)
        self.onOffButton.setGeometry(448, 446, 120, 62)
        helpers.makeButtonTransparent(self.onOffButton)
        self.onOffButton.setStyleSheet("background-image: url(" + self.POKEDEX_ON_BTN_IMG + "); font: bold 12px;")
        self.onOffButton.clicked.connect(self.toggleOnOff)
        
        self.listButton = QPushButton("LIST", self)
        self.listButton.setGeometry(470, 287, 35, 25)
        helpers.makeButtonTransparent(self.listButton)
        self.listButton.setStyleSheet("font: bold italic 10px;");
        # connect to showTheList goes here
        
        self.prevButton = QPushButton(self)
        self.prevButton.setGeometry(468, 392, 37, 37)
        helpers.makeButtonTransparent(self.prevButton)
        # connect to showPrevPokemon goes here

        self.nextButton = QPushButton(self)
        self.nextButton.setGeometry(507, 390, 37, 37)
        helpers.makeButtonTransparent(self.nextButton)
        # connect to showNextPokemon goes here

  
    def toggleOnOff(self):
        if self.onOff:
            self.setBackgroundImage(self.POKEDEX_OFF_IMG)
            self.hideEverything()
        else:
            self.setBackgroundImage(self.POKEDEX_ON_IMG)
        self.onOff = not self.onOff
            
    def setBackgroundImage(self, backgroundImg):
        palette = QPalette()
        pixmap = QPixmap(backgroundImg)
        brush = QBrush(pixmap)
        palette.setBrush(QtGui.QPalette.Background, brush)
        self.setPalette(palette)

    def hideEverything(self):
        pass

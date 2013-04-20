from PyQt4 import QtGui, QtCore
from PyQt4.QtGui import QPushButton

def makeButtonTransparent(button):
    """ Helper function out of any class"""
    button.setFocusPolicy(QtCore.Qt.NoFocus)
    button.setFlat(True)

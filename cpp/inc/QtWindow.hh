//
// QtWindow.hh for pokedex in /home/baron_a/Projects/pokemon/cpp
//
// Made by Alexandre Baron
// Login   <baron_a@epitech.net>
//
// Started on  Sat Jan 19 21:54:06 2013 Alexandre Baron
// Last update Sun Jan 20 04:18:21 2013 Alexandre Baron
//

#ifndef	QTWINDOW_HH_
# define QTWINDOW_HH_

# include <QtGui>

# define	POKEDEX_OFF_IMG	"/home/baron_a/Projects/pokemon/resources/Images/PokedexOff.png"
# define	POKEDEX_ON_IMG	"/home/baron_a/Projects/pokemon/resources/Images/PokedexOn.png"
# define	ON_BUTTON_IMG	"/home/baron_a/Projects/pokemon/resources/Images/boutonON.png"

class	QtWindow : public QMainWindow
{
  Q_OBJECT

  QPushButton	*onOffButton_;
  QWidget	*homeMenu_;
  bool	OnOff_;

public:
  QtWindow();
  ~QtWindow() {}

  void	initialize();
  void	setBackgroundImage(const char *filename);
  void	blockResize(size_t width, size_t height);
  void	makeButtonTransparent(QPushButton *);

  void	createHomeMenu();

private slots:
  void	toggleOnOff();
// protected:
//   void closeEvent(QCloseEvent *event);

// private slots:
//   void newFile();
//   void open();
//   bool save();
//   bool saveAs();
//   void about();
//   void documentWasModified();

// private:
//   void createActions();
//   void createMenus();
//   void createToolBars();
//   void createStatusBar();
//   void readSettings();
//   void writeSettings();
//   bool maybeSave();
//   void loadFile(const QString &fileName);
//   bool saveFile(const QString &fileName);
//   void setCurrentFile(const QString &fileName);
//   QString strippedName(const QString &fullFileName);

//   QPlainTextEdit *textEdit;
//   QString curFile;

//   QMenu *fileMenu;
//   QMenu *editMenu;
//   QMenu *helpMenu;
//   QToolBar *fileToolBar;
//   QToolBar *editToolBar;
//   QAction *newAct;
//   QAction *openAct;
//   QAction *saveAct;
//   QAction *saveAsAct;
//   QAction *exitAct;
//   QAction *cutAct;
//   QAction *copyAct;
//   QAction *pasteAct;
//   QAction *aboutAct;
//   QAction *aboutQtAct;
};

#endif

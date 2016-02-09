#ifndef CONTROLMODULE_H
#define CONTROLMODULE_H

//== Qt Includes
#include <QDesktopWidget>
#include <QMainWindow>
#include <QMenuBar>
#include <QGridLayout>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGroupBox>
#include <QLabel>
#include <QComboBox>
#include <QHash>
#include <QPushButton>
#include <QCheckBox>
#include <QMessageBox>

//== Defines
#define CM_MODE_STAND   "Stand"
#define CM_MODE_BLOCK   "Block"
#define CM_MODE_CROUCH  "Crouch"
#define CM_MODE_JUMP    "Jump"
#define CM_MODE_SCRIPT  "Scripted"
#define CM_MODE_CPU     "CPU"


//== Class declarations
namespace Ui {
class ControlModule;
}

class ControlModule : public QMainWindow
{
    Q_OBJECT

public:
    explicit ControlModule(QWidget *parent = 0);
    ~ControlModule();

private:
    void createLayout();
    void createRecordingPanel();
    void createSetupPanel();
    void createMenu();

    //== Window elements
    QMenuBar *menuBar;

    QHBoxLayout *layout;

    QGraphicsScene *recordScene;
    QGraphicsView *recordView;

    QGroupBox *setupPanel;
    QLabel *modeLabel;
    QComboBox *modeBox;
    QHash<QString, QGroupBox*> *modePanels;
    QGroupBox *activeModePanel;
    QPushButton **buttons;

    Ui::ControlModule *ui;

    //== Const declaration
    static unsigned short const controlModuleWidth;
    static unsigned short const controlModuleHeight;

private slots:
    void handleChangePanels(int);
};

#endif // CONTROLMODULE_H

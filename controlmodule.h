#ifndef CONTROLMODULE_H
#define CONTROLMODULE_H

#include <QMainWindow>

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
    Ui::ControlModule *ui;
};

#endif // CONTROLMODULE_H

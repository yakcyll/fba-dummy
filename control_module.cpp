#include "control_module.h"
#include "ui_controlmodule.h"

//== Const definition
unsigned short const ControlModule::controlModuleWidth = 275;
unsigned short const ControlModule::controlModuleHeight = 500;


//== Method definition
ControlModule::ControlModule(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ControlModule)
{
    ui->setupUi(this);

    //== Set up elements
    this->createLayout();
    this->createRecordingPanel();
    this->createSetupPanel();
    this->createMenu();

    //== Window geometry
    QRect screenRect = QApplication::desktop()->screenGeometry();

    this->setGeometry((screenRect.width() - controlModuleWidth) / 2,
                      (screenRect.height() - controlModuleHeight) / 2,
                      controlModuleWidth,
                      controlModuleHeight);

    this->menuWidget()->hide();
    this->statusBar()->hide();
}

ControlModule::~ControlModule()
{
    delete ui;
}

void ControlModule::createLayout()
{
    this->layout = new QHBoxLayout();
    this->centralWidget()->setLayout(this->layout);
}

void ControlModule::createRecordingPanel()
{
    this->recordView = new QGraphicsView();
    this->recordView->setFrameShape(QFrame::Panel);
    this->recordView->setFrameShadow(QFrame::Sunken);
    this->recordView->setLineWidth(3);
    this->recordView->setMaximumWidth(75);

    this->recordScene = new QGraphicsScene();
    this->recordView->setScene(this->recordScene);
    this->recordScene->setBackgroundBrush(QBrush(Qt::gray, Qt::SolidPattern));

    this->layout->addWidget(this->recordView);
}

void ControlModule::createSetupPanel()
{
    this->setupPanel = new QGroupBox();
    this->setupPanel->setLayout(new QVBoxLayout());
    this->setupPanel->layout()->setAlignment(Qt::AlignTop);

    this->modeLabel = new QLabel("Dummy mode");

    this->modeBox = new QComboBox();

    QStringList ql;
    ql.append(CM_MODE_STAND);
    ql.append(CM_MODE_BLOCK);
    ql.append(CM_MODE_CROUCH);
    ql.append(CM_MODE_JUMP);
    ql.append(CM_MODE_SCRIPT);
    ql.append(CM_MODE_CPU);

    this->modeBox->addItems(ql);

    this->modePanels = new QHash<QString, QGroupBox*>();

    QGroupBox* inactiveBox = new QGroupBox("");
    QLabel* testLabel = new QLabel("Test filler");
    inactiveBox->setLayout(new QVBoxLayout());
    inactiveBox->layout()->addWidget(testLabel);
    inactiveBox->show();
    this->activeModePanel = inactiveBox;
    this->modePanels->insert(CM_MODE_STAND, inactiveBox);

    QGroupBox* blockBox = new QGroupBox("");
    QButtonGroup* blockTypeGroup = new QButtonGroup();
    QCheckBox* crouchBlock = new QCheckBox("Block crouching");
    QCheckBox* mixupBlock = new QCheckBox("Block high/low\nrandomly");
    blockTypeGroup->addButton(crouchBlock);
    blockTypeGroup->addButton(mixupBlock);
    blockTypeGroup->setExclusive(true);
    blockBox->setLayout(new QVBoxLayout());
    blockBox->layout()->addWidget(crouchBlock);
    blockBox->layout()->addWidget(mixupBlock);
    blockBox->hide();
    void (QButtonGroup:: *rbp)(QAbstractButton *) = &QButtonGroup::buttonPressed;
    void (QButtonGroup:: *rbr)(QAbstractButton *) = &QButtonGroup::buttonReleased;
    connect(blockTypeGroup, rbp, [=](QAbstractButton *button) { if (button->isChecked()) {blockTypeGroup->setExclusive(false); button->setChecked(false); button->setEnabled(false); blockTypeGroup->setExclusive(true);}});
    connect(blockTypeGroup, rbr, [=](QAbstractButton *button) { button->setEnabled(true); });
    this->modePanels->insert(CM_MODE_BLOCK, blockBox);

    connect(this->modeBox, SIGNAL(currentIndexChanged(int)), this, SLOT(handleChangePanels(int)));

    this->setupPanel->layout()->addWidget(this->modeLabel);
    this->setupPanel->layout()->addWidget(this->modeBox);
    foreach (QGroupBox* p, *this->modePanels) {
        this->setupPanel->layout()->addWidget(p);
    }
    this->layout->addWidget(this->setupPanel);
}

void ControlModule::createMenu()
{

}

void ControlModule::handleChangePanels(int index)
{
    if (!this->modePanels->contains(this->modeBox->itemText(index))) return; // TODO: patchwork
    this->activeModePanel->hide();
    this->activeModePanel = (*this->modePanels)[this->modeBox->itemText(index)];
    this->activeModePanel->show();
}

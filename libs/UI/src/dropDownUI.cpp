#include "WaypointUI.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>

WaypointUI::WaypointUI(QWidget *parent)
    : QWidget(parent),
      inputDialog(nullptr)
{
    // Create the main "Add Waypoint" button
    addWaypointButton = new QPushButton("Add Waypoint", this);
    addWaypointButton->setGeometry(10, 10, 120, 30);  // top-left corner

    connect(addWaypointButton, &QPushButton::clicked,
            this, &WaypointUI::OpenInputDialog);
}

void WaypointUI::OpenInputDialog()
{
    inputDialog = new QDialog(this);
    inputDialog->setWindowTitle("Add Waypoint");

    // Create form inputs
    idInput = new QLineEdit(inputDialog);
    xInput = new QLineEdit(inputDialog);
    yInput = new QLineEdit(inputDialog);
    zInput = new QLineEdit(inputDialog);

    QFormLayout *formLayout = new QFormLayout;
    formLayout->addRow("ID:", idInput);
    formLayout->addRow("X:", xInput);
    formLayout->addRow("Y:", yInput);
    formLayout->addRow("Z:", zInput);

    doneButton = new QPushButton("Done", inputDialog);
    connect(doneButton, &QPushButton::clicked,
            this, &WaypointUI::OnDoneClicked);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(formLayout);
    mainLayout->addWidget(doneButton);

    inputDialog->setLayout(mainLayout);
    inputDialog->exec();
}

void WaypointUI::OnDoneClicked()
{
    // You can later extract data here:
    // QString id = idInput->text();
    // double x = xInput->text().toDouble();
    // double y = yInput->text().toDouble();
    // double z = zInput->text().toDouble();

    OnWaypointAdded(); // currently empty

    inputDialog->accept(); // close dialog
}

void WaypointUI::OnWaypointAdded()
{
    // TODO: implement what happens after clicking "Done"
}

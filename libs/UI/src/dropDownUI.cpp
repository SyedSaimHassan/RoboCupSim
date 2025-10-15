#include "dropDownUI.h"
#include "systemConfig.h"
#include <QBrush>
#include <QFont>
#include <QPen>
#include <QLabel>
#include <QList>
#include <iostream>

void DropDownUI::Draw(QPainter &painter)
{
    painter.setRenderHint(QPainter::Antialiasing, true);

    if (!showInputs)
    {
        // --- Draw "Add Waypoint" button ---
        painter.setBrush(QColor(220, 220, 220));
        painter.setPen(QColor(100, 100, 100));
        painter.drawRoundedRect(buttonRect, 8, 8);

        painter.setPen(Qt::black);
        painter.setFont(QFont("Arial", 12, QFont::Bold));
        painter.drawText(buttonRect, Qt::AlignCenter, "Add Waypoint");
    }
    else
    {
        // --- When inputs are active ---
        painter.setPen(Qt::black);
        painter.setFont(QFont("Arial", 10));
        painter.drawText(10, 60, "Enter Waypoint Data:");
    }
}

bool DropDownUI::HandleClick(QWidget *parent, int x, int y)
{
    if (!showInputs && buttonRect.contains(x, y))
    {
        showInputs = true;
        CreateInputs(parent);
        return true;
    }
    return false;
}

void DropDownUI::HideInputs()
{
    showInputs = false;

    // --- Read values from the input boxes ---
    bool okX, okY, okZ;
    int id = inputBoxes[0]->text().toInt() - 1;  // Waypoint ID
    double x = inputBoxes[1]->text().toDouble(&okX);
    double y = inputBoxes[2]->text().toDouble(&okY);
    double z = inputBoxes[3]->text().toDouble(&okZ);

    if (okX && okY && okZ)
    {
        // --- Store in your waypoint vector ---
        cfg::SystemConfig::teamOneWayPoints[id].push_back(Eigen::Vector3d(x, y, z));
        std::cout << "[UI] Added Waypoint (ID=" << id << "): "
                  << x << ", " << y << ", " << z << std::endl;
    }
    else
    {
        std::cerr << "[UI] Invalid numeric input for X, Y, or Z." << std::endl;
    }

    // --- Clean up ---
    DestroyInputs();
}


void DropDownUI::CreateInputs(QWidget *parent)
{
    // --- Create 4 labeled QLineEdit fields ---
    int startY = 80;
    for (int i = 0; i < 4; ++i)
    {
        QLabel *label = new QLabel(labels[i] + ":", parent);
        label->setGeometry(10, startY + i * 40, 50, 25);
        label->show();

        inputBoxes[i] = new QLineEdit(parent);
        inputBoxes[i]->setGeometry(60, startY + i * 40, 100, 25);
        inputBoxes[i]->show();
    }

    // --- Create Done button ---
    doneButton = new QPushButton("Done", parent);
    doneButton->setGeometry(10, startY + 4 * 40 + 10, 150, 30);
    doneButton->show();

    QObject::connect(doneButton, &QPushButton::clicked, [parent]() {
        std::cout << "[UI] Done clicked!" << std::endl;
        for (int i = 0; i < 4; ++i)
        {
            std::cout << DropDownUI::labels[i].toStdString()
                      << " = " << DropDownUI::inputBoxes[i]->text().toStdString() << std::endl;
        }

        HideInputs();
        parent->update();
    });
}

void DropDownUI::DestroyInputs()
{
    QWidget *parentWidget = nullptr;
    if (doneButton)
        parentWidget = doneButton->parentWidget();
    else if (inputBoxes[0])
        parentWidget = inputBoxes[0]->parentWidget();

    // --- Safely delete input boxes ---
    for (int i = 0; i < 4; ++i)
    {
        if (inputBoxes[i])
        {
            delete inputBoxes[i];
            inputBoxes[i] = nullptr;
        }
    }

    // --- Safely delete Done button ---
    if (doneButton)
    {
        delete doneButton;
        doneButton = nullptr;
    }

    // --- Delete the labels ---
    if (parentWidget)
    {
        QList<QLabel *> labelList = parentWidget->findChildren<QLabel *>();
        for (QLabel *label : labelList)
        {
            QString text = label->text().replace(":", "");
            for (const auto &lbl : labels)
            {
                if (lbl == text)
                {
                    delete label;
                    break;
                }
            }
        }
    }
}

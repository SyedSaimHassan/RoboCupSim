#ifndef DROPDOWNUI_H
#define DROPDOWNUI_H

#include <QWidget>
#include <QPainter>
#include <QRect>
#include <QLineEdit>
#include <QPushButton>
#include <array>

class DropDownUI : public QObject
{
    Q_OBJECT
public:
    static void Draw(QPainter &painter);
    static bool HandleClick(QWidget *parent, int x, int y);
    static void HideInputs();

private:
    static inline bool showInputs = false;
    static inline QRect buttonRect{10, 10, 130, 40};
    static inline QRect doneButtonRect{10, 230, 130, 35};
    static inline std::array<QString, 4> labels{"ID", "X", "Y", "Z"};
    static inline std::array<QLineEdit*, 4> inputBoxes{};
    static inline QPushButton* doneButton = nullptr;

    static void CreateInputs(QWidget *parent);
    static void DestroyInputs();
};

#endif // DROPDOWNUI_H

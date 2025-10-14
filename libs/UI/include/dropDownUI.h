#ifndef WAYPOINTUI_H
#define WAYPOINTUI_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QDialog>

class WaypointUI : public QWidget
{
    Q_OBJECT

public:
    explicit WaypointUI(QWidget *parent = nullptr);

private slots:
    void OpenInputDialog();
    void OnDoneClicked();

private:
    QPushButton *addWaypointButton;

    // The input dialog
    QDialog *inputDialog;
    QLineEdit *idInput;
    QLineEdit *xInput;
    QLineEdit *yInput;
    QLineEdit *zInput;
    QPushButton *doneButton;

    void OnWaypointAdded();  // Empty function for you to fill later
};

#endif // WAYPOINTUI_H
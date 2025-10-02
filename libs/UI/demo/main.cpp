#include "players.h"
#include <QApplication>


int main(int argc, char *argv[]){
    QApplication app(argc, argv);
    Players p1;
    p1.setWindowTitle("Brush");
    p1.resize(1920,1080);
    p1.show();    
    return app.exec();
}
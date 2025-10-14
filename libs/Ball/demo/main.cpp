#include "ball.h"
#include <QApplication>

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);
  Ball a;
  a.showFullScreen();
  return app.exec();
}

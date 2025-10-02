#include "ball.h"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  Ball w;
  w.showFullScreen();
  return app.exec();
}

#ifndef GAME_H
#define GAME_H
#include <QApplication>
#include <QWidget>
#include <QPainterPath>
#include <QPainter>
#include <QScreen>
#include <QTimer>
#include <QKeyEvent>
#include <iostream>
#include <vector>
#include "dimensions.h"

#define To_Be_Implemented int

namespace Controller {
enum class State { Kickoff, Playing, Paused, Foul, Finished };
class Game : public QWidget {
 private:
  State gameState = State::Kickoff;

  void drawField(QPainter *painter);
  void drawPlayers(QPainter *painter);
  void drawBall(QPainter *painter);
  void paintEvent(QPaintEvent *) override;

 public:
  Game(QWidget *parent = nullptr);
};

}  // namespace Controller

#endif
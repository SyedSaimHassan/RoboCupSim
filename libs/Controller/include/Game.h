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
#include <Eigen/Dense>
#include <cmath>
#include "dimensions.h"
#include "players.h"
#include "transformation.h"
#include "ball.h"
#include "playingField.h"
#define To_Be_Implemented int
#define dt 1/60

namespace Controller {
enum class State { Kickoff, Playing, Paused, Foul, Finished };
class Game : public QWidget {
 private:
  State gameState = State::Kickoff;
  Players Players_;
  Ball::Ball Ball_;
  UI Field; 
  void drawField(QPainter *painter);
  void drawPlayers(QPainter *painter);
  void drawBall(QPainter *painter);
  void paintEvent(QPaintEvent *) override;
  void keyPressEvent(QKeyEvent *event) override;
  void keyReleaseEvent(QKeyEvent *event) override;
  void handleInsertKey(int Key);
  void handleRemoveKey(int Key);
  void keyControls();
  void handlePlayer();
  QSet<int> PlayerKeys;
  int SelectedPlayerId = 0;

 public:
  Game(QWidget *parent = nullptr);
};

}  // namespace Controller



#endif
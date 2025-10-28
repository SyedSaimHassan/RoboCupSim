#include <players.h>
#include <iostream>
void Players::Render(QPainter* painter) {
  painter->setBrush(Qt::blue);
  painter->setPen(QPen(Qt::black, 0.05));
  for (int i = 1; i <= int(cfg::SystemConfig::numRobots / 2); i++) {
    painter->save();
    QPointF pos = QPointF(cfg::SystemConfig::teamOnePlayerPos[i - 1].x(),
                          cfg::SystemConfig::teamOnePlayerPos[i - 1].y());
    painter->translate(pos);
    painter->rotate(cfg::SystemConfig::teamOnePlayerPos[i - 1].z());

    Players::drawPlayers(painter, i);
    painter->restore();
  }
}

void Players::drawPlayers(QPainter* painter, int playerNumber) {
  painter->drawEllipse(QPointF(0, 0), cfg::SystemConfig::robotRadius,
                       cfg::SystemConfig::robotRadius);
  QPointF start = QPointF(0, 0);
  qreal r = cfg::SystemConfig::robotRadius;
  qreal angle = cfg::SystemConfig::teamOnePlayerPos[playerNumber - 1].z();

  QPointF end(start.x() + r * cos(angle), start.y() + r * sin(angle));

  painter->drawLine(start, end);
}

void Players::setPose(Eigen::Vector3d pose, int playerID = 0) {
  if (!playerID) {
    return;
  }

  cfg::SystemConfig::teamOnePlayerPos[playerID - 1].x() = (pose.x());
  cfg::SystemConfig::teamOnePlayerPos[playerID - 1].y() = (pose.y());
  cfg::SystemConfig::teamOnePlayerPos[playerID - 1].z() = pose.z();
}

Eigen::Vector3d Players::getPose(int playerID) {
  return Eigen::Vector3d(cfg::SystemConfig::teamOnePlayerPos[playerID - 1].x(),
                         cfg::SystemConfig::teamOnePlayerPos[playerID - 1].y(),
                         cfg::SystemConfig::teamOnePlayerPos[playerID - 1].z());
}

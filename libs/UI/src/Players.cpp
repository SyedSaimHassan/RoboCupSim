#include <Players.h>

double euclideanDistance(QPointF p1,QPointF p2){
    return pow(pow(p1.x()-p2.x(),2)+pow(p1.y()-p2.y(),2),0.5);
}

void Players::Render(QPainter *painter){
    painter->setBrush(Qt::blue);
    painter->setPen(QPen(Qt::black,0.05));
    for (int i = 1;i <= 4;i++){
        painter->save();
        painter->rotate(playerGyroAngle[i-1]);
        Players::drawPlayers(painter,i);
        painter->restore();
    }
}

void Players::drawPlayers(QPainter *painter, int playerNumber){
    painter->drawEllipse(playerPositions[playerNumber-1],0.09,0.09);

    painter->drawLine(playerPositions[playerNumber-1],QPointF(playerPositions[playerNumber-1].x()*cos(playerGyroAngle[playerNumber-1]),playerPositions[playerNumber-1].y()*sin(playerGyroAngle[playerNumber-1])));
}


QPointF Players::withinRadius(double x,double y, int id = 0){
    if (id == 0){
        for (int i = 1;i <=4;i++){
            if (euclideanDistance(QPointF(x,y),playerPositions[i-1]) <= 0.5){
                return playerPositions[i-1];
            }
            return QPointF(-1,-1);
        }
    }
    else{
        if (euclideanDistance(QPointF(x,y),playerPositions[id-1]) <= 0.5){
            return playerPositions[id-1];
        }
        return QPointF(-1,-1);
    }
}
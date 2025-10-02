#include <players.h>

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
    painter->drawEllipse(playerPositions[playerNumber-1],10,10);

    painter->drawLine(playerPositions[playerNumber-1],QPointF(playerPositions[playerNumber-1].x()*cos(playerGyroAngle[playerNumber-1]),playerPositions[playerNumber-1].y()*sin(playerGyroAngle[playerNumber-1])));
}


void Players::drawBackground(QPainter *painter) {
    QRectF worldRect(0,0,1920,1080);

    painter->fillRect(rect(), Qt::gray);  
    painter->fillRect(worldRect, Qt::white);    
}

void Players::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    drawBackground(&painter);
    Render(&painter);
}
#include <Players.h>

void Players::Render(QPainter *painter){
    painter->setBrush(Qt::blue);
    painter->setPen(QPen(Qt::black,0.05));
    for (int i = 1;i <= 4;i++){
        Players::drawPlayers(painter);
    }
}

void Players::drawPlayers(QPainter *painter){

}
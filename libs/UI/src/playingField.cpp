#include "playingField.h"

void UI::CreateField(QPainter *painter){
    
    painter->setPen(QPen(Qt::black,0.03));
    painter->drawRect(QRectF(-cfg::Dimensions::fieldWidth/2,cfg::Dimensions::fieldHeight/2,cfg::Dimensions::fieldWidth,-cfg::Dimensions::fieldHeight));
    
    painter->setPen(QPen(Qt::red,0.02));
    painter->drawRect(QRectF((-cfg::Dimensions::fieldPlayingAreaWidth/2)-(cfg::Dimensions::fieldGoalWidth),cfg::Dimensions::fieldGoalHeight/2,cfg::Dimensions::fieldGoalWidth,-cfg::Dimensions::fieldGoalHeight));
    painter->drawRect(QRectF((cfg::Dimensions::fieldPlayingAreaWidth/2)+(cfg::Dimensions::fieldGoalWidth),cfg::Dimensions::fieldGoalHeight/2,-cfg::Dimensions::fieldGoalWidth,-cfg::Dimensions::fieldGoalHeight));
    
    
    painter->setPen(QPen(Qt::white,0.02));
    painter->drawRect(QRectF((-cfg::Dimensions::fieldPlayingAreaWidth/2),(cfg::Dimensions::fieldPlayingAreaHeight/2),cfg::Dimensions::fieldPlayingAreaWidth,-cfg::Dimensions::fieldPlayingAreaHeight));

    painter->drawRect(QRectF(-(cfg::Dimensions::fieldPlayingAreaWidth/2),cfg::Dimensions::fieldPenaltyAreaHeight/2,cfg::Dimensions::fieldPenaltyAreaWidth,-cfg::Dimensions::fieldPenaltyAreaHeight));
    painter->drawRect(QRectF((cfg::Dimensions::fieldPlayingAreaWidth/2),cfg::Dimensions::fieldPenaltyAreaHeight/2,-cfg::Dimensions::fieldPenaltyAreaWidth,-cfg::Dimensions::fieldPenaltyAreaHeight));


    painter->drawLine(QLineF((-cfg::Dimensions::fieldPlayingAreaWidth/2),0,(cfg::Dimensions::fieldPlayingAreaWidth/2),0));
    painter->drawLine(QLineF(0,(cfg::Dimensions::fieldPlayingAreaHeight/2),0,(-cfg::Dimensions::fieldPlayingAreaHeight/2)));


    painter->drawEllipse(QRectF(-0.5,-0.5,cfg::Dimensions::fieldCentralCircleRadius*2,cfg::Dimensions::fieldCentralCircleRadius*2));    

    
}


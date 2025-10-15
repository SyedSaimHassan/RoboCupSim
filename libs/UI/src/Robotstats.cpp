#include "Robotstats.h"

void RbSt::drawStats(QPainter *painter){
    QFont font("Arial",1);  
    painter->scale(0.1,-0.1);
    painter->setFont(font);  
    painter->drawText(cfg::Dimensions::outerFieldWidth*5.8,-cfg::Dimensions::outerFieldHeight*5, QString("Selected Player: %1").arg(PLayerID));
    painter->drawText(cfg::Dimensions::outerFieldWidth*5.8,(-cfg::Dimensions::outerFieldHeight*5)+0.01, QString("Player X Position: %1").arg(cfg::SystemConfig::teamOnePlayerPos[PLayerID - 1].x()));
    painter->drawText(cfg::Dimensions::outerFieldWidth*5.8,(-cfg::Dimensions::outerFieldHeight*4.7), QString("Player Y Position: %1").arg(cfg::SystemConfig::teamOnePlayerPos[PLayerID - 1].y()));
    painter->drawText(cfg::Dimensions::outerFieldWidth*5.8,(-cfg::Dimensions::outerFieldHeight*4.6), QString("Player X Velocity %1").arg(cfg::SystemConfig::teamOnePlayerVel[PLayerID - 1].x()));
    painter->drawText(cfg::Dimensions::outerFieldWidth*5.8,(-cfg::Dimensions::outerFieldHeight*4.5)+0.01, QString("Player Y  Velocity %1").arg(cfg::SystemConfig::teamOnePlayerVel[PLayerID - 1].y()));
    switch (cfg::SystemConfig::PlayerStates[PLayerID-1])
    {
        case cfg::SystemConfig::RobotState::Autonomous:
        painter->drawText(cfg::Dimensions::outerFieldWidth*5.8,(-cfg::Dimensions::outerFieldHeight*4.3), QString("Robot Status: Autonomous"));
        
        break;
        
        case cfg::SystemConfig::RobotState::Manual:
        painter->drawText(cfg::Dimensions::outerFieldWidth*5.8,(-cfg::Dimensions::outerFieldHeight*4.3), QString("Robot Status: Manual"));
        
        break;
    }
    QPen pen(Qt::black,0.1);
    painter->setBrush(Qt::NoBrush);
    painter->setPen(pen);
    painter->drawRect(QRectF(cfg::Dimensions::outerFieldWidth*5.6,-cfg::Dimensions::outerFieldHeight*5.2,15,6.8));

}
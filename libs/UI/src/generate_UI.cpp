#include "generate_UI.h"

void UI::CreateField(QPainter *painter){
    painter->setBackground(QBrush(Qt::green));
    painter->eraseRect(rect());
    // Transformation Transform;
    
    // painter->setPen(QPen(Qt::black,4));
    // painter->drawRect(QRectF(Transform.meterToPixel(0.04,0.04,width(),height()),Transform.meterToPixel(Transform.worldX-0.04,Transform.worldY-0.04,width(),height())));
    
    // painter->setPen(QPen(Qt::red,2));
    // painter->drawRect(QRectF(Transform.meterToPixel(0.52,3.2,width(),height()),Transform.meterToPixel(0.7,4.2,width(),height())));
    // painter->drawRect(QRectF(Transform.meterToPixel(Transform.worldX-0.52,Transform.worldY-3.2,width(),height()),Transform.meterToPixel(Transform.worldX-0.7,Transform.worldY-4.2,width(),height())));
    
    
    // painter->setPen(QPen(Qt::white,2));
    // painter->drawRect(QRectF(Transform.meterToPixel(0.7,0.7,width(),height()),Transform.meterToPixel(Transform.worldX-0.7,Transform.worldY-0.7,width(),height())));

    // painter->drawRect(QRectF(Transform.meterToPixel(0.7,2.7,width(),height()),Transform.meterToPixel(1.7,4.7,width(),height())));
    // painter->drawRect(QRectF(Transform.meterToPixel(Transform.worldX-0.7,Transform.worldY-2.7,width(),height()),Transform.meterToPixel(Transform.worldX-1.7,Transform.worldY-4.7,width(),height())));

    // painter->drawLine(QLineF(Transform.meterToPixel(0.7,3.7,width(),height()),Transform.meterToPixel(Transform.worldX-0.7,3.7,width(),height())));
    // painter->drawRect(QRectF(Transform.meterToPixel(5.2,0.7,width(),height()),Transform.meterToPixel(5.2,Transform.worldY-0.7,width(),height())));

    // QPointF center=Transform.meterToPixel((Transform.worldX/2),(Transform.worldY/2),width(),height());
    // QPointF radius=Transform.meterToPixel(0.5,0.5,width(),height());
    // painter->drawEllipse(center,std::min(radius.x(),radius.y()),std::min(radius.x(),radius.y()));    

    
}
void UI::paintEvent(QPaintEvent *){
    QPainter painter(this);
    CreateField(& painter);
}

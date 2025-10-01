#include <QWidget>

using namespace std;

class Transformation : public QWidget
{
    public:

        // World dimensions
        double worldX = 10.4;
        double worldY = 7.4;

        // Parameters needed for player
        double playerRadius = 0.09;
        int playerNumber;
        int numberOfRobots = 1;

        // Transformation variables
        double offSetX, offSetY, scale;
    
        // Finds the scale of pixels per meter, and also screen offset on X-axis and Y-axis
        void transformation()
        {
            double ratioX = width() / worldX;
            double ratioY = height() / worldY;

            if (ratioX > ratioY) 
            {
                offSetX = ((ratioX - ratioY) * worldX) / 2;
                scale = ratioY;
                offSetY = 0.0;
            }
            
            else 
            {
                offSetY = ((ratioY - ratioX) * worldY) / 2;
                scale = ratioX;
                offSetX = 0.0;
            }
        }

        // Converts a coordinated in meters to pixels
        QPointF meterToPixel(double mx, double my)
        {
            transformation();

            double x = offSetX + (mx * scale);
            double y = offSetY + (my * scale);
            return QPointF(x, y);
        }

        // Converts a coordinated in pixels to meters
        QPointF pixelToMeter(double px, double py)
        {
            transformation();

            double x = (px - offSetX) / scale;
            double y = (py - offSetY) / scale;
            return QPointF(x, y);
        }
};
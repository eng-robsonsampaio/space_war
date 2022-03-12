#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>

class Health: public QGraphicsTextItem {
public:
    Health(QGraphicsItem *parent=nullptr);
    void decrease();
    void increase();
    void changeText();
private:
    int life;
};

#endif // HEALTH_H

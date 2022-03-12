#include "health.h"
#include <QFont>

Health::Health(QGraphicsItem *parent):QGraphicsTextItem(parent) {
    this->life = 100;

    setPlainText(QString("Life: ") + QString::number(this->life));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 16));
    setPos(0,20);
}

void Health::increase() {
    life += 30;
}

void Health::decrease() {
    life -= 20;
}

void Health::changeText(){
    setPlainText(QString("Life: ") + QString::number(this->life));
}


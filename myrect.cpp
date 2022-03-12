#include "myrect.h"
#include "bullet.h"
#include "enemy.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>
#include <QKeyEvent>

MyRect::MyRect(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/assets/images/spaceship_small.png"));
}

void MyRect::keyPressEvent(QKeyEvent *event)
{

    if (event->key() == Qt::Key_Left){
        if(x()>0){
            setPos(x()-10, y());
        }
    }
    else if (event->key() == Qt::Key_Right){
        if(x() + 100 < 980){
            setPos(x()+10, y());
        }
    }
    else if (event->key() == Qt::Key_Space){
        Bullet *bullet = new Bullet();
        bullet->setPos(x() + 100/2, y());
        scene()->addItem(bullet);
    }
}

void MyRect::createEnemy()
{
    Enemy *enemy = new Enemy();
    scene()->addItem(enemy);
}

#include "bullet.h"
#include "enemy.h"
#include "game.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QGraphicsItem>

extern Game *game;

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    // draw the graphics
    setPixmap(QPixmap("/home/robson/projetos/space_war/assets/images/beam.png"));
    setPos(x(), y());
    // connect
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    game->playSound("lasershot.mp3");
    timer->start(30);
}

void Bullet::move(){
    QList<QGraphicsItem *> colliding_items = collidingItems();
    int n = colliding_items.size();
    for (int i=0; i < n; ++i){
        if(typeid(*(colliding_items[i])) == typeid(Enemy)){
            game->playSound("explosion.wav");
            game->score->increaseScore();
            game->score->changeScore();
            scene()->removeItem(colliding_items[i]); // remove enemy
            scene()->removeItem(this); // remove bullet

            delete colliding_items[i];
            delete this;
            return;
        }
    }


    setPos(x(), y()-10);
    if (pos().y()< 0){
        scene()->removeItem(this);
        delete this;
        qDebug() << "Bullet deleted";
    }
}

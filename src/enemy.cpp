#include "enemy.h"
#include "game.h"
#include <time.h>
#include <stdlib.h>
#include <QTimer>
#include <QGraphicsScene>

extern Game *game;

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent) {

    srand(time(NULL));
    int min = 40;
    int max = 940;
    setPixmap(QPixmap("/home/robson/projetos/space_war/assets/images/enemy.png"));
    setPos(rand()%(max-min + 1) + min, -300);
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(moveEnemy()));

    timer->start(100);
}

void Enemy::moveEnemy(){
    setPos(x(), y()+10);
    if (pos().y() > 1000){
        game->life->decrease();
        game->life->changeText();
        scene()->removeItem(this);
        delete this;
    }
}

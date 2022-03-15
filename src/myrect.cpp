#include "myrect.h"
#include "bullet.h"
#include "enemy.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>
#include <QKeyEvent>

QSet<int> key;

MyRect::MyRect(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    setPixmap(QPixmap("/home/robson/projetos/space_war/assets/images/spaceship_small.png"));    
}

void MyRect::keyReleaseEvent(QKeyEvent *event) {
    key.remove(event->key());
    qDebug() << key.size();        
}

void MyRect::keyPressEvent(QKeyEvent *event) {    
    key.insert(event->key());
    qDebug() << key.size();
    
    // while(key.size() > 0){
        if (key.contains(Qt::Key_Left)){
            if (key.contains(Qt::Key_Space)){
                Bullet *bullet = new Bullet();
                bullet->setPos(x() + 100/2, y());
                scene()->addItem(bullet);
            }            
            if (x()>0){
                setPos(x()-10, y());
            }
        }
        else if (key.contains(Qt::Key_Right)){
            if (key.contains(Qt::Key_Space)){
                Bullet *bullet = new Bullet();
                bullet->setPos(x() + 100/2, y());
                scene()->addItem(bullet);
            }            
            if (x()>0){
                setPos(x()+10, y());
            }
        }      
        else if (key.contains(Qt::Key_Space)){
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

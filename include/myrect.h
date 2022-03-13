#ifndef MYRECT_H
#define MYRECT_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class MyRect:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    MyRect(QGraphicsItem *parent=nullptr);
    void keyPressEvent(QKeyEvent *event);
public slots:
    void createEnemy();
};

#endif // MYRECT_H

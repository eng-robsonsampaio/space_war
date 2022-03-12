#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include "myrect.h"
#include "score.h"
#include "health.h"
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QAudioOutput>


class Game: public QGraphicsView {
public:
    Game();
    void playSound(QString sound);
    QGraphicsScene *scene;
    Score *score;
    Health *life;
    MyRect *rect;
    QMediaPlayer *player;
    QAudioOutput *audioOutput;
};

#endif // GAME_H

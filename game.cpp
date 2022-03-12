#include "game.h"
#include "enemy.h"
#include "score.h"
#include <QTimer>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QImage>

Game::Game(){

    // create a scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setBackgroundBrush(QBrush(QImage(":/assets/images/background.jpg")));

    // create an item
    rect = new MyRect();
    rect->setPos(500,800);

    // add the item to the scene
    scene->addItem(rect);

    // create score
    score = new Score();
    scene->addItem(score);

    // create life
    life = new Health();
    scene->addItem(life);

    // make rect focusable
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();

    // create Enemies
    QTimer *timer = new QTimer();
    QTimer::connect(timer, SIGNAL(timeout()), rect, SLOT(createEnemy()));
    timer->start(2000);

//    QGraphicsView *view = new QGraphicsView();
    setScene(scene);

    setFixedSize(1000, 1000);
    setSceneRect(0,0,1000,1000);

    playSound("backgroundMusic.mp3");
    show();
}

void Game::playSound(QString sound) {
    player = new QMediaPlayer();
    audioOutput = new QAudioOutput;
    player->setAudioOutput(audioOutput);
    //connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
    player->setSource(QUrl("qrc:/assets/sounds/" + sound));
    audioOutput->setVolume(0.1);
    player->play();
}

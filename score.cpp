#include "score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
    this->scorePoints = 0;

    // draw the text
    setPlainText(QString("Score: ") + QString::number(this->scorePoints));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times", 16));
}

void Score::increaseScore() {
    this->scorePoints += 10;
}

int Score::getScorePoints() {
    return this->scorePoints;
}

void Score::changeScore() {
    setPlainText(QString("Score: ") + QString::number(this->scorePoints));
}

#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class Score: public QGraphicsTextItem {
public:
    Score(QGraphicsItem *parent=nullptr);
    void increaseScore();
    int getScorePoints();
    void changeScore();
private:
    int scorePoints;
};

#endif // SCORE_H

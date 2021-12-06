#ifndef MINEGENERATOR_H
#define MINEGENERATOR_H

#include <vector>
#include <QObject>

class MineGenerator : public QObject
{
    Q_OBJECT

    // used to map a CPP attribute to QML (can be bi-directional READ-WRITE)
    Q_PROPERTY(int score READ getScore NOTIFY scoreChanged)

private:
    std::vector<int> mines;
    int score = 0;

public:
    explicit MineGenerator(QObject *parent = nullptr);

    // used to call CPP method from QML (and possibly return some data)
    Q_INVOKABLE int getMineCount(int index);

    int getScore();

signals:
    // used to update QML from C++
    void scoreChanged();

public slots:
    // used to call a CPP method from QML
    void increaseScore(int number);
};

#endif // MINEGENERATOR_H

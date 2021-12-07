#ifndef MINESGAME_H
#define MINESGAME_H

#include <QObject>
#include <vector>
#include "filemanager.h"

class MinesGame : public QObject
{
    Q_OBJECT
public:
    explicit MinesGame(QObject *parent = nullptr);
    Q_INVOKABLE int getMineCount(int index);

signals:

private:
    std::vector<int> m_mines;
};

#endif // MINESGAME_H

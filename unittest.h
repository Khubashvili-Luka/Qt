#ifndef UNITTEST_H
#define UNITTEST_H

#include <QObject>

class UnitTest : public QObject
{
    Q_OBJECT
public:
    explicit  UnitTest(QObject *parent = 0);

private slots:
    void TestCountGenreDrama();

};

#endif // UNITTEST_H

#ifndef UNITTEST_H
#define UNITTEST_H

#include <QObject>

class UnitTest : public QObject
{
    Q_OBJECT
public:
    explicit  UnitTest(QObject *parent = 0);

private slots:
    void TestCountGenreAnimation();
    void TestCountGenreWestern();
    void TestCountGenreBiography();
    void TestCountGenreSport();
    void TestCountGenreTriller();
    void TestCountGenreRomance();
    void TestCountGenreMusic();
    void TestCountGenreCrime();
    void TestCountGenreAction();
    void TestCountGenreHorror();

};

#endif // UNITTEST_H

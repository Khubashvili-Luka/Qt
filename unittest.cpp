#include "unittest.h"
#include <QTest>
#include <filmdb.h>


UnitTest::UnitTest(QObject *parent) :
    QObject(parent) {
}

void UnitTest::TestCountGenreWestern(){
    FilmDb db;
    QVERIFY(db.count_genre("Western") == 1);
}
void UnitTest::TestCountGenreTriller(){
    FilmDb db;
    QVERIFY(db.count_genre("Thriller") == 2);
}
void UnitTest::TestCountGenreSport(){
    FilmDb db;
    QVERIFY(db.count_genre("Sport") == 1);
}
void UnitTest::TestCountGenreMusic(){
    FilmDb db;
    QVERIFY(db.count_genre("Music") == 1);
}
void UnitTest::TestCountGenreHorror(){
    FilmDb db;
    QVERIFY(db.count_genre("Horror") == 2);
}
void UnitTest::TestCountGenreCrime(){
    FilmDb db;
    QVERIFY(db.count_genre("Crime") == 2);
}
void UnitTest::TestCountGenreAnimation(){
    FilmDb db;
    QVERIFY(db.count_genre("Animation") == 3);
}
void UnitTest::TestCountGenreRomance(){
    FilmDb db;
    QVERIFY(db.count_genre("Romance") == 2);
}
void UnitTest::TestCountGenreBiography(){
    FilmDb db;
    QVERIFY(db.count_genre("Biography") == 3);
}
void UnitTest::TestCountGenreAction(){
    FilmDb db;
    QVERIFY(db.count_genre("Action") == 3);
}

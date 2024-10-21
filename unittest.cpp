#include "unittest.h"
#include <QTest>
#include <filmdb.h>


UnitTest::UnitTest(QObject *parent) :
    QObject(parent) {

}

void UnitTest::TestCountGenreDrama(){
    FilmDb db;
    QVERIFY(db.count_genre("Drama") == 1);
}




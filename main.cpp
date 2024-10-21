#include <QCoreApplication>
#include <QTest>
#include <unittest.h>
#include <QDebug>
#include <filmdb.h>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTest::qExec(new UnitTest, argc, argv);
    qDebug() << "\n";


    return a.exec();
}

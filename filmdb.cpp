#include "filmdb.h"
#include <QDebug>
#include <QMap>
#include <QVariant>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include <QList>

FilmDb::FilmDb() {
    openDatabase();
}

FilmDb::~FilmDb() {
    closeDatabase();
}

void FilmDb::openDatabase() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(DATABASE_PATH);

    if (!db.open()) {
        qDebug() << "Ошибка открытия базы:" << db.lastError().text();
    }
    else{
         qDebug() << "База открыта:";

    }
}

void FilmDb::closeDatabase() {
    if (db.isOpen()) {
        db.close();
    }
}

QList<QString> FilmDb::executeQuery(const QString &queryString, const QMap<QString, QVariant> &params) {
    QList<QString> result;
    QSqlQuery query(db);
    query.prepare(queryString);

    for (auto it = params.constBegin(); it != params.constEnd(); ++it) {
        query.bindValue(it.key(), it.value());
    }

    if (query.exec()) {
        while (query.next()) {
            result.append(query.value(0).toString());
        }
    } else {
        qDebug() << "Ошибка выполнения запроса 1 :" << query.lastError().text();
    }

    return result;
}


int FilmDb::executeScalarQuery(const QString &queryString, const QMap<QString, QVariant> &params) {
    QSqlQuery query(db);
    query.prepare(queryString);

    return 1;


   // query.exec("SELECT * FROM genre ;");


    // while (query.next()) {
    //     qDebug() << "Таблица:" << query.value(0).toString();
    // }


    // query.prepare("SELECT COUNT(*) FROM genre");
    // if (query.exec()) {
    //     if (query.next()) {
    //         qDebug() << "Result:" << query.value(0).toInt();
    //     } else {
    //         qDebug() << "No results";
    //     }
    // } else {
    //     qDebug() << "Ошибка выполнения запроса:" << query.lastError().text();
    // }




    // qDebug() << "Выполняется запрос:" << queryString;


    // qDebug() << "Параметры:";
    // for (auto it = params.constBegin(); it != params.constEnd(); ++it) {
    //     qDebug() << it.key() << ":" << it.value();
    //     query.bindValue(it.key(), it.value());
    // }


    // if (!query.exec()) {
    //     qDebug() << "Ошибка выполнения запроса:" << query.lastError().text();
    //     return 0;
    // } else {
    //     qDebug() << "Запрос выполнен успешно.";
    // }


    // if (!query.next()) {
    //     qDebug() << "Нет данных в результате запроса.";
    //     return 0;
    // }


    // int result = query.value(0).toInt();
    // qDebug() << "Результат запроса:" << result;
    // return result;

}


QList<QString> FilmDb::get_good_films_of_genre(int rating, QString genre) {
    QString queryString = R"(
        SELECT IMDB.Title
        FROM IMDB
        JOIN genre ON IMDB.Movie_id = genre.Movie_id
        WHERE genre.genre = :genre AND IMDB.Rating >= :rating
    )";
    QMap<QString, QVariant> params;
    params[":genre"] = genre;
    params[":rating"] = rating;

    return executeQuery(queryString, params);
}


QList<QString> FilmDb::get_films_of_genre_less_than(int time, QString genre) {
    QString queryString = R"(
        SELECT IMDB.Title
        FROM IMDB
        JOIN genre ON IMDB.Movie_id = genre.Movie_id
        WHERE genre.genre = :genre AND CAST(SUBSTR(IMDB.Runtime, 1, INSTR(IMDB.Runtime, ' ') - 1) AS INTEGER) <= :time
    )";
    QMap<QString, QVariant> params;
    params[":genre"] = genre;
    params[":time"] = time;

    return executeQuery(queryString, params);
}

QList<QString> FilmDb::get_films_less_than(int time) {
    QString queryString = R"(
        SELECT Title
        FROM IMDB
        WHERE CAST(SUBSTR(Runtime, 1, INSTR(Runtime, ' ') - 1) AS INTEGER) <= :time
    )";
    QMap<QString, QVariant> params;
    params[":time"] = time;

    return executeQuery(queryString, params);
}

int FilmDb::count_genre(QString genre) {
    QString queryString = R"(
        SELECT COUNT(*)
        FROM genre
        WHERE genre = :genre
    )";
    QMap<QString, QVariant> params;
    params[":genre"] = genre;

    return executeScalarQuery(queryString, params);
}




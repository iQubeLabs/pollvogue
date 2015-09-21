#ifndef SQL_H
#define SQL_H
#include <QtSql>
#include <QStringList>

class Model;

class sql
{
public:
    sql();
    ~sql();

    bool createTable(Model *model);
    bool dropTable(Model *model);
    bool insert(Model* model, QStringList fields, QStringList values);
    QMap<QString, QVariant> findById(Model* model, QString id);
    QMap<QString, QVariant> findByField(Model* model, QString fieldName, QString value);
    QMap<QString, QVariant> findFirst(Model* model);
//    void update(QStringList fields, QStringList values, QString where);
//    void delete(QString where);

    static sql *getInstance();

private:
    QString concatList(QStringList items, QString delimiter = ",", bool quote = true);

    QSqlDatabase db;
    QSqlQuery sqlQuery;

    static sql *_sql;
};

#endif // SQL_H

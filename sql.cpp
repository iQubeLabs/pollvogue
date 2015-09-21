#include "sql.h"
#include "models/model.h"

#include <QDebug>
#include <QException>

sql::sql()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("fileName.db");

    if(db.open())
    {
        qDebug() << "Database open successful";
        sqlQuery = QSqlQuery();
    }
    else
    {
        qDebug() << "Error opening database";
    }
}

sql::~sql()
{

}

bool sql::createTable(Model* model){
    if(!sqlQuery.exec(model->getCreateCmd()))
    {
        qDebug() << "Error creating table: " << sqlQuery.lastError();
        return false;
    }
    else
        return true;
}

bool sql::dropTable(Model *model)
{
    QString dropQuery = QString("DROP TABLE %1;")
            .arg(model->getTableName());
    if(!sqlQuery.exec(dropQuery))
    {
        qDebug() << "Error droping table: " << sqlQuery.lastError();
        return false;
    }
    else
        return true;
}

bool sql::insert(Model *model, QStringList fields, QStringList values)
{
    QString query = "INSERT INTO %1(%2) VALUES(%3);";

    int fieldsLength = fields.length();
    int valuesLength = values.length();

    if(fieldsLength != valuesLength)
    {
        qDebug() << "fields.length() != values.length()";
        return false;
    }

    QString fieldsQuery = concatList(fields, ",", false);
    QString valuesQuery = concatList(values);

    query = query.arg(model->getTableName(), fieldsQuery, valuesQuery);

    qDebug() << "Insert query: " <<query;

    if(!sqlQuery.exec(query))
    {
        qDebug() << "Error inserting: " << sqlQuery.lastError();
    }
    else
        return true;

}

QMap<QString, QVariant> sql::findById(Model *model, QString id)
{
    return findByField(model, "id", id);
}

QMap<QString, QVariant> sql::findByField(Model *model, QString fieldName, QString value)
{
    QString query = QString("SELECT * FROM %1 WHERE %2 = '%3';")
            .arg(model->getTableName()).arg(fieldName).arg(value);

    QMap<QString, QVariant> resultMap;
    qDebug() << "Query is: " << query;
    if(!sqlQuery.exec(query))
    {
        qDebug() << "Error: " << sqlQuery.lastError().text();
    }
    else
    {
        QSqlRecord record = sqlQuery.record();

        while(sqlQuery.next())
        {
            for(int i = 0; i < record.count(); i++)
            {
                resultMap.insert(record.fieldName(i), sqlQuery.value(record.fieldName(i)));
            }

        }
    }
    return resultMap;
}

QMap<QString, QVariant> sql::findFirst(Model *model)
{
    QString query = QString("SELECT * FROM %1;")
            .arg(model->getTableName());

    QMap<QString, QVariant> resultMap;
    if(!sqlQuery.exec(query))
    {
        qDebug() << "Error: " << sqlQuery.lastError().text();
    }
    else
    {
        QSqlRecord record = sqlQuery.record();

        if(sqlQuery.next())
        {
            for(int i = 0; i < record.count(); i++)
            {
                resultMap.insert(record.fieldName(i), sqlQuery.value(record.fieldName(i)));
            }

        }
    }
    return resultMap;
}

sql *sql::_sql = 0;

sql *sql::getInstance()
{
    if(_sql == 0)
        _sql = new sql();

    return _sql;
}

QString sql::concatList(QStringList items, QString delimiter, bool quote)
{
    int itemsLength = items.length();
    QString result = "";

    for(int i = 0; i < itemsLength; i++)
    {
        if(quote)
            result += "\""+items.at(i)+"\"";
        else
            result += items.at(i);

        if(i != itemsLength-1)
            result += delimiter;
    }

    return result;
}

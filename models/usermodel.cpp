#include "usermodel.h"

UserModel::UserModel()
{

}

UserModel::~UserModel()
{

}

QString UserModel::getTableName()
{
    return "users";
}

QString UserModel::getCreateCmd()
{
    Field f;

    return QString("CREATE TABLE IF NOT EXISTS %6("
               "%1 INT NOT NULL,"
               "%2 VARCHAR (20) NOT NULL,"
               "%3 VARCHAR (50) NOT NULL,"
               "%4 VARCHAR (50),"
               "PRIMARY KEY (ID)"
            ");").arg(f.ID)
            .arg(f.NICKNAME)
            .arg(f.PHONE)
            .arg(f.TOKEN)
            .arg(getTableName());
}


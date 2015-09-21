#ifndef USERMODEL_H
#define USERMODEL_H

#include <QString>

#include "model.h"

class UserModel : public Model
{
public:    
    UserModel();
    ~UserModel();

    virtual QString getCreateCmd();
    virtual QString getTableName();

    class Field{
    public:
        //Todo change this fields to static
        const QString ID = "id";
        const QString NICKNAME = "nickname";
        const QString PHONE = "phonenumber";
        const QString TOKEN = "token";
    };
};

#endif // USERMODEL_H

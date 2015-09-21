#ifndef MODEL_H
#define MODEL_H

#include <QString>

class Model
{
public:
    Model();
    ~Model();

    virtual QString getCreateCmd() = 0;
    virtual QString getTableName() = 0;
};

#endif // MODEL_H

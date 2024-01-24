#ifndef PROJECT_H
#define PROJECT_H

#include "team.h"
#include "user.h"
#include <QMainWindow>
#include <QString>
#include <QVector>
#include "task.h"
class project {
private:
    QString username_of_creator;
    QString name_of_project;
    QVector<QString> task_of_project;
    QVector<QString> users_of_project;
    QVector<QString> teams_of_project;

public:
    project();
    project(QString _name);
    void set_name_of_project(QString n);
    QString get_name_of_project();
    void add_task_to_project(QString t);
    bool operator==(project pro);
    void set_username_of_creator(QString _user){
        username_of_creator = _user;
    }
QString get_usrname_of_creator();
};

#endif // PROJECT_H

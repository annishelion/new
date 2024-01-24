#include "user.h"
#include <QString>
#include <QVector>
#include "team.h"
#include "project.h"
#include "organization.h"


QString organization::get_name_of_organ(){
    return name_of_organ;

}
void organization::add_member_to_organ(QString _user){
    member_of_organ.push_back(_user);
}

void organization::set_name_of_organ(QString s){
    name_of_organ = s;
}

void organization::add_team_organ(QString _team){
    team_of_organ.push_back(_team);
}
void organization::set_head_of_organ(QString _user){
    head_of_organ = _user;
}
QString organization::get_head_of_organ(){return head_of_organ;

}
void organization::delete_member_of_organ(QString _user){
    for(int i=0 ; i<member_of_organ.size() ; i++ ){
        if(member_of_organ[i] == _user ){
            member_of_organ.erase(member_of_organ.begin()+i);

        }
}
}
void organization::delete_team_of_organ(QString _team){
    for(int i=0 ; i<team_of_organ.size() ; i++ ){
        if(team_of_organ[i] == _team ){
            member_of_organ.erase(member_of_organ.begin()+i);

        }
}

}

void organization::delete_project_from_organ(QString pro){
    for(int i=0 ; i<projects_of_organ.size() ; i++ ){
        if(projects_of_organ[i] == pro ){
            projects_of_organ.erase(projects_of_organ.begin()+i);

        }
}
}
void organization::add_project_to_organ(QString pro){
    this->projects_of_organ.push_back(pro);
}

organization::organization(QString creator_organ , QString _name_of_organ):head_of_organ(creator_organ){
    member_of_organ.push_back(creator_organ);
    name_of_organ = _name_of_organ;


}

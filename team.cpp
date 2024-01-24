#include "user.h"
#include <QString>
#include <QVector>
#include "team.h"

QVector<QString> get_members_of_team();

void team::set_name_of_team(QString _new_team_name){
    name_of_team = _new_team_name;

}
void team::add_member(QString new_member){
    members.append(new_member);
}
void team::delete_member(QString _member){
    for(int i=0 ; i<members.size() ; i++ ){
        if(members[i] == _member ){
            members.erase(members.begin()+i);

        }
    }

}
QString team::get_name_of_team(){
    return name_of_team;
}

bool team::operator==(team t){
    if(this->get_name_of_team() == t.get_name_of_team() )
        return 1;

    else return 0;

}

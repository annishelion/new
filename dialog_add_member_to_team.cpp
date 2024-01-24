#include "dialog_add_member_to_team.h"
#include "ui_dialog_add_member_to_team.h"
#include "data.h"
#include "QMessageBox"
Dialog_add_member_to_team::Dialog_add_member_to_team(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_add_member_to_team)
{
    ui->setupUi(this);
}

Dialog_add_member_to_team::~Dialog_add_member_to_team()
{
    delete ui;
}

void Dialog_add_member_to_team::on_show_teams_btn_clicked()
{
    ui->listWidget->clear();
     for (int i = 0; i < Data::get_teams().size(); i++) {

            if(Data::get_teams()[i].get_head_of_team() == Data::get_onlineId())
 ui->listWidget->addItem(Data::get_teams()[i].get_name_of_team());


         }
}


void Dialog_add_member_to_team::on_add_user_to_team_btn_clicked()
{

    if(ui->name_of_tam_input->text().isEmpty() || ui->name_of_user_input->text().isEmpty())
    {
        QMessageBox::warning(this, "تذکر", " فیلد باید پر شود!");
    return;
    }
 int flag =0 ;
    for (int a =0 ; Data::get_players().size() > a ;a++){
        if(Data::get_players()[a].get_username() == ui->name_of_user_input->text())
                flag = 1;
}
    if(flag == 0 ){
        QMessageBox::warning(this, "تذکر", " شخصی بااین نام یافت نشد!");
        return;

    }

    int flag2 =0 ;
       for (int a =0 ; Data::get_teams().size() > a ;a++){
           if(Data::get_teams()[a].get_name_of_team() == ui->name_of_tam_input->text())
                   flag2 = 1;
   }
       if(flag2 == 0 ){
           QMessageBox::warning(this, "تذکر", " تیمی با این نام یافت نشد!");
           return;

       }





     for (int i = 0; i < Data::get_teams().size(); i++) {

            if(Data::get_teams()[i].get_head_of_team() == Data::get_onlineId() && Data::get_teams()[i] == ui->name_of_tam_input->text()){
                for(int a =0 ; Data::get_teams()[i].get_members_of_team().size() > a ; a++){
                    if(Data::get_teams()[i].get_members_of_team()[a] == ui->name_of_user_input->text()){
                        QMessageBox::warning(this, "تذکر", " این شخص در این تیم عضو است!");
                        return;
                    }
                }

                Data::get_teams()[i].add_member(ui->name_of_user_input->text());

                return;
            }



         }


}


#include "dialog_delete_team.h"
#include "ui_dialog_delete_team.h"
#include "data.h"
#include "QMessageBox"
Dialog_delete_team::Dialog_delete_team(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_delete_team)
{
    ui->setupUi(this);
}

Dialog_delete_team::~Dialog_delete_team()
{
    delete ui;
}

void Dialog_delete_team::on_show_my_teams_btn_clicked()
{
    ui->listWidget->clear();
     for (int i = 0; i < Data::get_teams().size(); i++) {

            if(Data::get_teams()[i].get_head_of_team() == Data::get_onlineId())
 ui->listWidget->addItem(Data::get_teams()[i].get_name_of_team());


         }
}



void Dialog_delete_team::on_buttonBox_accepted()
{
    ui->listWidget->clear();
     for (int i = 0; i < Data::get_teams().size(); i++) {
            if(Data::get_teams()[i].get_head_of_team() == Data::get_onlineId()){
                Data::get_teams().erase(Data::get_teams().begin()+i);
                return;

}
}
 QMessageBox::warning(this, "تذکر", " شما تیمی بااین اسم ایجاد نکرده اید!");
}


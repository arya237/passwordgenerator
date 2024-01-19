#include "password.h"
#include "ui_password.h"
#include <bits/stdc++.h>
#include <fstream>

using namespace std;

password::password(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::password)
{
    ui->setupUi(this);
    ui->le_site->hide();
    ui->le_username->hide();
    ui->btn_generate->setDisabled(1);
    ui->le_password->hide();
    ui->le_user->hide();
    ui->btn_search->hide();
    ui->lb_password->hide();
    ui->lb_username->hide();
    ui->pass_length->setGeometry(75,180,141,31);
    ui->lcdNumber->setGeometry(350, 180, 80, 31);
    ui->horizontalSlider->setGeometry(75, 220, 360, 22);
    ui->btn_generate->setGeometry(75, 270, 360,35);
    ui->pass->setGeometry(75, 350, 360, 31);

}

void password::generatepass()
{
    this->pass = "";

    srand(time(0));

    std::string lower{"qwertyuiopasdfghjklzxcvbnm"};
    std::string upper{"QWERTYUIOPASDFGHJKLZXCVBNM"};
    std::string character{"!@#$%^&*()?"};
    std::string number{"0123456789"};

    int size = ui->horizontalSlider->value();

    for(int i = 0; i < (size - 5) / 2; i++)
    {
        this->pass += lower[rand() % 26];
    }

    for(int i = 0; i < ((size - 5) / 2 + 1 * (size % 2 == 0) ); i++)
    {
        this->pass += upper[rand() % 26];
    }

    for(int i = 0; i < 2; i++)
    {
        this->pass += character[rand() % 11];
    }

    for(int i = 0; i <= 2; i++)
    {
        this->pass += number[rand() % 10];
    }

    random_shuffle(pass.begin(), pass.end());
    ui->pass->setText(QString::fromStdString(this->pass));
}

void password::pass_for_site()
{
    fstream passwords;
    passwords.open("pass.txt", ios::app);

    string site = ui->le_site->text().toStdString();
    string password = ui->le_username->text().toStdString();

    passwords << site << '\n' << password << '\n' << pass << '\n';

    passwords.close();
}

void password::search_in_file(std::string  key)
{
    fstream file;
    file.open("pass.txt", ios::in);

    string site, username, password;

    while(file >> site >> username >> password)
    {
        if(site == key)
        {
            ui->le_password->setText(QString::fromStdString(password));
            ui->le_user->setText(QString::fromStdString(username));
            break;
        }
    }
}

password::~password()
{
    delete ui;
}


void password::on_btn_generate_clicked()
{
    if(ui->radio_site->isChecked())
    {
        generatepass();
        pass_for_site();
    }

    else generatepass();
}


void password::on_radio_pass_clicked()
{
    ui->btn_generate->setEnabled(1);
    ui->le_site->hide();
    ui->le_username->hide();
    ui->le_password->hide();
    ui->le_user->hide();
    ui->btn_search->hide();
    ui->lb_password->hide();
    ui->lb_username->hide();
    ui->btn_generate->show();
    ui->horizontalSlider->show();
    ui->pass_length->show();
    ui->lcdNumber->show();
    ui->pass_length->setGeometry(75,180,141,31);
    ui->lcdNumber->setGeometry(350, 180, 80, 31);
    ui->horizontalSlider->setGeometry(75, 220, 360, 22);
    ui->btn_generate->setGeometry(75, 270, 360,35);
    ui->pass->setGeometry(75, 350, 360, 31);
}


void password::on_radio_site_clicked()
{
    ui->btn_generate->setEnabled(1);
    ui->le_password->hide();
    ui->le_user->hide();
    ui->btn_search->hide();
    ui->lb_password->hide();
    ui->lb_username->hide();
    ui->btn_generate->show();
    ui->horizontalSlider->show();
    ui->pass_length->show();
    ui->lcdNumber->show();
    ui->pass_length->setGeometry(75,260,141,31);
    ui->lcdNumber->setGeometry(350, 260, 80, 31);
    ui->horizontalSlider->setGeometry(75, 310, 360, 22);
    ui->btn_generate->setGeometry(75, 350, 360,35);
    ui->pass->setGeometry(75, 400, 360, 31);
}



void password::on_radio_search_clicked()
{
    ui->pass_length->hide();
    ui->btn_generate->hide();
    ui->lcdNumber->hide();
    ui->horizontalSlider->hide();
    ui->lb_password->setGeometry(3, 255, 71, 16);
    ui->lb_username->setGeometry(3,295,71,16);
    ui->btn_search->setGeometry(75, 190, 360, 35);
    ui->le_user->setGeometry(75, 250, 361, 31);
    ui->le_password->setGeometry(75,290,361,31);
}


void password::on_btn_search_clicked()
{
    search_in_file(ui->le_site->text().toStdString());
}


#ifndef PASSWORD_H
#define PASSWORD_H

#include <QMainWindow>
#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui { class password; }
QT_END_NAMESPACE

class password : public QMainWindow
{
    Q_OBJECT

public:
    password(QWidget *parent = nullptr);
    void generatepass();
    void pass_for_site();
    void search_in_file(std::string site);
    ~password();

private slots:
    void on_btn_generate_clicked();

    void on_radio_pass_clicked();

    void on_radio_site_clicked();

    void on_radio_search_clicked();

    void on_btn_search_clicked();

private:
    Ui::password *ui;
    std::string pass;
};
#endif // PASSWORD_H

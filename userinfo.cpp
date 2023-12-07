#include "userinfo.h"
#include "ui_userinfo.h"
#include <QmessageBox>

UserInfo::UserInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserInfo)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/Irfan Rahman/OneDrive/Desktop/HP image/b2.jpg");
    int w = ui->B2->width();
    int h = ui->B2->height();
    ui->B2->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

UserInfo::~UserInfo()
{
    delete ui;
}

void UserInfo::on_Enter_clicked()
{
    // Get user's name and age from the input fields
    QString name = ui->lineEdit_name->text();
    QString ageString = ui->lineEdit_age->text();

    // Convert age to integer
    bool conversionOk;
    int age = ageString.toInt(&conversionOk);

    // Check if the conversion was successful
    if (!conversionOk || age < 0 || age > 150) {
        // Handle the case where the conversion fails or the age is outside the valid range
        QMessageBox::warning(this, "Invalid Age", "Please enter a valid integer for age between 0 and 150.");
        return;  // Don't proceed to the next page if validation fails
    }

    // Proceed to the next page
    hide();
    HealthChecker *healthChecker = new HealthChecker(this);
    healthChecker->show();
}

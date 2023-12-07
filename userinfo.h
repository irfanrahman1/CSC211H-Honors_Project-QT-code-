#ifndef USERINFO_H
#define USERINFO_H

#include <QDialog>
#include "healthchecker.h"

namespace Ui {
class UserInfo;
}

class UserInfo : public QDialog
{
    Q_OBJECT

public:
    explicit UserInfo(QWidget *parent = nullptr);
    ~UserInfo();

private slots:
    void on_Enter_clicked();

private:
    Ui::UserInfo *ui;
    HealthChecker *healthChecker;
};

#endif // USERINFO_H

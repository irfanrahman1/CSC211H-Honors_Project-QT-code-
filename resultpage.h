#ifndef RESULTPAGE_H
#define RESULTPAGE_H

#include <QDialog>


namespace Ui {
class ResultPage;
}

class ResultPage : public QDialog
{
    Q_OBJECT

public:
    explicit ResultPage(QWidget *parent = nullptr);
    ~ResultPage();
    void setResult(const QString &result, bool diabetesFlag, bool lowBloodPressureFlag, bool highBloodPressureFlag, bool ldlCholesterolFlag, bool hdlCholesterolFlag);

private:
    Ui::ResultPage *ui;
};

#endif // RESULTPAGE_H

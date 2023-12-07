#ifndef HEALTHCHECKER_H
#define HEALTHCHECKER_H

#include <QDialog>
#include "resultpage.h"

namespace Ui {
class HealthChecker;
}

class HealthChecker : public QDialog
{
    Q_OBJECT

public:
    explicit HealthChecker(QWidget *parent = nullptr);
    ~HealthChecker();
    HealthChecker();
    void checkBloodPressure();
    void checkDiabetes();
    void checkCholesterol();
    void checkHealth();

private slots:
    void on_Submit_clicked();
    bool validateHealthInfo(int systolicBP, int diastolicBP, int fastingGlucose, int hba1c, int ldlCholesterol, int hdlCholesterol, QString &validationMessage);

private:
    Ui::HealthChecker *ui;
    bool diabetesFlag;
    bool lowBloodPressureFlag;
    bool highBloodPressureFlag;
    bool ldlCholesterolFlag;
    bool hdlCholesterolFlag;
    int systolicBP;
    int diastolicBP;
    int fastingGlucose;
    int hba1c;
    int ldlCholesterol;
    int hdlCholesterol;

    QString healthMessage;
    ResultPage *resultPage;

};

#endif // HEALTHCHECKER_H

#include "healthchecker.h"
#include "ui_healthchecker.h"
#include <QMessageBox>
#include <QString>

HealthChecker::HealthChecker(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HealthChecker)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/Irfan Rahman/OneDrive/Desktop/HP image/b3.jpg");
    int w = ui->B3->width();
    int h = ui->B3->height();
    ui->B3->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

    // Initialize result page
    resultPage = new ResultPage(this);
}


HealthChecker::~HealthChecker()
{
    delete ui;
}

HealthChecker::HealthChecker() {
    diabetesFlag = false;
    lowBloodPressureFlag = false;
    highBloodPressureFlag = false;
    ldlCholesterolFlag = false;
    hdlCholesterolFlag = false;
}

void HealthChecker::on_Submit_clicked()
{
    // Reset flags before checking health
    diabetesFlag = false;
    lowBloodPressureFlag = false;
    highBloodPressureFlag = false;
    ldlCholesterolFlag = false;
    hdlCholesterolFlag = false;

    // Get health values from the QLineEdit widgets
    systolicBP = ui->systolicBP->text().toInt();
    diastolicBP = ui->diastolicBP->text().toInt();
    fastingGlucose = ui->fastingGlucose->text().toInt();
    hba1c = ui->hba1c->text().toInt();
    ldlCholesterol = ui->ldlCholesterol->text().toInt();
    hdlCholesterol = ui->hdlCholesterol->text().toInt();

    qDebug() << "Diabetes Flag: " << diabetesFlag;
    qDebug() << "Low BP Flag: " << lowBloodPressureFlag;
    qDebug() << "High BP Flag: " << highBloodPressureFlag;
    qDebug() << "LDL Flag: " << ldlCholesterolFlag;
    qDebug() << "HDL Flag: " << hdlCholesterolFlag;


    // Validate health info
    QString validationMessage;
    bool isValid = validateHealthInfo(systolicBP, diastolicBP, fastingGlucose, hba1c, ldlCholesterol, hdlCholesterol, validationMessage);

    // Display the validation result
    if (!isValid) {
//        QMessageBox::information(this, "Validation Successful", "");
        QMessageBox::warning(this, "Validation Failed", validationMessage);
    }
    else {
        checkHealth();
        // Print flags for debugging
        qDebug() << "Diabetes Flag: " << diabetesFlag;
        qDebug() << "Low BP Flag: " << lowBloodPressureFlag;
        qDebug() << "High BP Flag: " << highBloodPressureFlag;
        qDebug() << "LDL Flag: " << ldlCholesterolFlag;
        qDebug() << "HDL Flag: " << hdlCholesterolFlag;
        // Set the result on the result page
        resultPage->setResult(healthMessage, diabetesFlag, lowBloodPressureFlag, highBloodPressureFlag, ldlCholesterolFlag, hdlCholesterolFlag);

        // Show the result page
        resultPage->exec();
    }
}

bool HealthChecker::validateHealthInfo(int systolicBP, int diastolicBP, int fastingGlucose, int hba1c, int ldlCholesterol, int hdlCholesterol, QString &validationMessage)
{
    // Initialize the validation message
    validationMessage.clear();

    // Add your validation logic here
    // For example, check if the values are within certain ranges for each metric
    if (!(systolicBP >= 60 && systolicBP <= 220)) {
        validationMessage += "Invalid Systolic BP. ";
    }
    if (!(diastolicBP >= 40 && diastolicBP <= 160)) {
        validationMessage += "Invalid Diastolic BP. ";
    }
    if (!(fastingGlucose >= 40 && fastingGlucose <= 300)) {
        validationMessage += "Invalid Fasting Glucose. ";
    }
    if (!(hba1c >= 4 && hba1c <= 15)) {
        validationMessage += "Invalid HbA1c. ";
    }
    if (!(ldlCholesterol >= 50 && ldlCholesterol <= 250)) {
        validationMessage += "Invalid LDL Cholesterol. ";
    }
    if (!(hdlCholesterol >= 20 && hdlCholesterol <= 100)) {
        validationMessage += "Invalid HDL Cholesterol. ";
    }

    // Return true if all metrics are valid, otherwise false
    return validationMessage.isEmpty();
}

void HealthChecker::checkBloodPressure() {
    if (systolicBP >= 140 || diastolicBP >= 90) {
//        QMessageBox::information(this, "High Blood Pressure", "You might have high blood pressure. Immediate medication: Antihypertensive medication.");
        highBloodPressureFlag = true;
    }
    else if (systolicBP < 90 || diastolicBP < 60) {
//        QMessageBox::information(this, "Low Blood Pressure", "You might have low blood pressure. Consider increasing your salt intake and staying hydrated.");
        lowBloodPressureFlag = true;
    }
    else {
//        QMessageBox::information(this, "Normal Blood Pressure", "Your blood pressure is within the normal range.");
    }
}

void HealthChecker::checkDiabetes() {
    if (fastingGlucose >= 126 || hba1c >= 6.5) {
//        QMessageBox::information(this, "Possible Diabetes", "You might have diabetes. Immediate medication: Insulin or oral antidiabetic medication.");
        diabetesFlag = true;
    }
}

void HealthChecker::checkCholesterol() {
    if (ldlCholesterol >= 130) {
//        QMessageBox::information(this, "High LDL Cholesterol", "You might have high LDL cholesterol. Immediate medication: Statins or other cholesterol-lowering medications.");
        ldlCholesterolFlag = true;
    }

    if (hdlCholesterol < 40) {
//        QMessageBox::information(this, "Low HDL Cholesterol", "You might have low HDL cholesterol. Consider lifestyle changes and consult a healthcare professional.");
        hdlCholesterolFlag = true;
    }
}

void HealthChecker::checkHealth() {
    checkDiabetes();
    checkBloodPressure();
    checkCholesterol();


    if (diabetesFlag || lowBloodPressureFlag ||highBloodPressureFlag || ldlCholesterolFlag || hdlCholesterolFlag) {
        healthMessage = "Your overall health condition is not optimal. ";
        if (diabetesFlag && lowBloodPressureFlag && highBloodPressureFlag && ldlCholesterolFlag && hdlCholesterolFlag) {
            healthMessage += "You have multiple health issues. ";
        }
        healthMessage += "Schedule an appointment with your doctor.";
    }
    else {
        healthMessage = "Your health condition seems manageable. Consider taking some rest and rechecking later.";
    }

//    QMessageBox::information(this, "Health Check Result", healthMessage);
}


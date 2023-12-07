#include "resultpage.h"
#include "ui_resultpage.h"

ResultPage::ResultPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ResultPage)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/Irfan Rahman/OneDrive/Desktop/HP image/b6.jpg");
    int w = ui->B4->width();
    int h = ui->B4->height();
    ui->B4->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

ResultPage::~ResultPage()
{
    delete ui;
}

void ResultPage::setResult(const QString &result, bool diabetesFlag, bool lowBloodPressureFlag, bool highBloodPressureFlag, bool ldlCholesterolFlag, bool hdlCholesterolFlag)
{
    // Set the result text
    QString resultText;

    // Additional logic to customize the message based on flags
    if (diabetesFlag) {
        resultText += "Possible Diabetes: Immediate medication - Insulin or oral antidiabetic medication.\n\n";
    }

    if (lowBloodPressureFlag) {
        resultText += "You might have low Blood Pressure: Immediate action - Consult a healthcare professional.\n\n";
    }

    if (highBloodPressureFlag) {
        resultText += "You might have high Blood Pressure: Immediate action - Consult a healthcare professional.\n\n";
    }

    if (ldlCholesterolFlag) {
        resultText += "You might have high Ldl Cholesterol: Immediate action - Consider lifestyle changes and medication.\n\n";
    }

    if (hdlCholesterolFlag) {
        resultText += "You might have low Hdl Cholesterol: Immediate action - Consider lifestyle changes and medication.\n\n";
    }

    // Check if any flags are set indicating a potential health issue
    if (diabetesFlag || lowBloodPressureFlag || highBloodPressureFlag || ldlCholesterolFlag || hdlCholesterolFlag) {
        resultText = result + "\n\n" + resultText;
    } else {
        // No flags set, indicating good health
        resultText = "Your overall health condition is good. Keep up the healthy lifestyle!\n\n" + result;
    }

    // Set the font size
    QFont font = ui->B4->font();
    font.setPointSize(10);  // Adjust the size as needed
    ui->label_result->setFont(font);

    // Set the result text to the label
    ui->label_result->setText(resultText);
}

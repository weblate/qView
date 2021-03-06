#ifndef QVOPTIONSDIALOG_H
#define QVOPTIONSDIALOG_H

#include "qvshortcutdialog.h"
#include "settingsmanager.h"

#include <QDialog>
#include <QCheckBox>
#include <QRadioButton>
#include <QComboBox>
#include <QSpinBox>

namespace Ui {
class QVOptionsDialog;
}

class QVOptionsDialog : public QDialog
{
    Q_OBJECT

public:

    explicit QVOptionsDialog(QWidget *parent = nullptr);
    ~QVOptionsDialog() override;


protected:
    void closeEvent(QCloseEvent *event) override;

    void modifySetting(QString key, QVariant value);
    void saveSettings();
    void syncSettings(bool defaults = false, bool makeConnections = false);
    void syncCheckbox(QCheckBox *checkbox, const QString &key, bool defaults = false, bool makeConnection = false);
    void syncRadioButtons(QList<QRadioButton*> buttons, const QString &key, bool defaults = false, bool makeConnection = false);
    void syncComboBox(QComboBox *comboBox, const QString &key, bool defaults = false, bool makeConnection = false);
    void syncSpinBox(QSpinBox *spinBox, const QString &key, bool defaults = false, bool makeConnection = false);
    void syncDoubleSpinBox(QDoubleSpinBox *doubleSpinBox, const QString &key, bool defaults = false, bool makeConnection = false);
    void syncShortcuts(bool defaults = false);
    void updateShortcutsTable();
    void updateButtonBox();
    void bgColorButtonClicked();
    void updateBgColorButton();

private slots:
    void shortcutCellDoubleClicked(int row, int column);

    void buttonBoxClicked(QAbstractButton *button);

    void bgColorCheckboxStateChanged(int arg1);

    void scalingCheckboxStateChanged(int arg1);

    void windowResizeComboBoxCurrentIndexChanged(int index);

private:
    Ui::QVOptionsDialog *ui;

    QHash<QString, QVariant> transientSettings;

    QList<QStringList> transientShortcuts;
};


#endif // QVOPTIONSDIALOG_H

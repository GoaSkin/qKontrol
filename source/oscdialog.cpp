#include <QDialog>
#include <QDir>
#include <QSettings>
#include "oscdialog.h"

oscDialog::oscDialog(QWidget* parent /* = 0 */, Qt::WindowFlags flags /* = 0 */) : QDialog(parent, flags)
{
	setupUi(this);

	// restore settings from INI file if it exists and update values
	if(QFile(QDir::homePath() + "/.qkontrol/osc.ini").exists())
		{
		QSettings* settings = new QSettings(QDir::homePath() + "/.qkontrol/osc.ini", QSettings::IniFormat);
		checkBoxOSC->setChecked(settings->value("enabled").toBool());
		hostname->setText(settings->value("hostname").toString());
		spinBoxLocalport->setValue(settings->value("local").toInt());
		spinBoxRemoteport->setValue(settings->value("remote").toInt());
		}
		
	connect(applyButton, SIGNAL(clicked()), this, SLOT(saveAndClose()));
}

// write dialog settings into INI file and close the dialog
void oscDialog::saveAndClose()
{
	QSettings* settings = new QSettings(QDir::homePath() + "/.qkontrol/osc.ini", QSettings::IniFormat);
	settings->setValue("enabled", checkBoxOSC->isChecked()); 
	settings->setValue("hostname", hostname->text());
	settings->setValue("local", spinBoxLocalport->value());
	settings->setValue("remote", spinBoxRemoteport->value());
	accept();
}

oscDialog::~oscDialog()
{

}


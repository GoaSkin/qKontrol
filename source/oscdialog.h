#ifndef _OSCDIALOG_H_
#define _OSCDIALOG_H_

#include "ui_oscdialog.h"

class oscDialog : public QDialog, public Ui_oscDialog
{
	Q_OBJECT

	public:
		oscDialog(QWidget *parent = 0, Qt::WindowFlags flags = 0);
		~oscDialog();

	private:

	private slots:
		void saveAndClose();

	protected slots:

	public slots:
};

#endif /*_OSCDIALOG_H_*/

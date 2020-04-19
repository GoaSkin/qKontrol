#ifndef _QKONTROLWINDOW_H_
#define _QKONTROLWINDOW_H_

#include <QDir>
#include <QTemporaryFile>
#include <QTimer>
#include <QUdpSocket>
#ifdef Q_OS_MACOS
#include "/usr/local/Cellar/hidapi/0.9.0/include/hidapi/hidapi.h"
#else
#include <hidapi/hidapi.h>
#endif
#include "dropgraphicsview.h"
#include "ui_qkontrol.h"

class qkontrolWindow : public QMainWindow , protected Ui_mainwindow
{
	Q_OBJECT

	public:
		qkontrolWindow(QWidget *parent = 0, Qt::WindowFlags flags = 0);
		~qkontrolWindow();

	private:
		bool pluginMode; // false = MIDI mode; true = plugin mode
		bool oscEnabled; // true if OSC is in use
	        bool changeTrackinfo; // true if displays should update the track info
		int res;
		int pid;
		unsigned int bPage, kPage, kontrolPage, dirCount, dirPosition;
		hid_device *handle; // USB HID socket
		QByteArray lightArray, knobsButtons;
		QByteArray oldButtonArray;
		QMap<QString,QColor> allColors; // array containing all color settings
		QTemporaryFile leftScreen, rightScreen; // image files to be displayed on the screens
		QTimer *hid_data;
		QString getControlName(uint8_t CC);
		QStringList paramName;
		QDir dirName;
		bool load(QString filename); // function to load a preset
		QUdpSocket *udpSocket; // UDP socket to be used on OSC
		QString trackname; // trackname to be displayed if OSC is active
		QString devicename; // devicename to be displayed if OSC is active
		QString beatstring; // beat position to be displayed if OSC is active
		QString timestring; // song position to be displayed if OSC is active
		QString hostname; // hostname or IP to connect to the DAW via OSC
		unsigned int localPort, remotePort; // UDP ports to be used on OSC

	private slots:
		bool save(); // function to save a preset
		void getFileName();

	protected slots:
                void drawImage(uint8_t screen, QPixmap *pixmap, ushort x = 0, ushort y = 0);
		void b_goLeft();
		void b_goRight();
		void b_setPage(int page);
		void k_goLeft();
		void k_goRight();
		void k_setPage(int page);
		void oscConfig();
		void setKontrolpage(unsigned int page);
		void selectColor(QString target);
		void setSlidertextcolor();
		void setDividercolor();
		void setCCtextcolor();
		void setParametertextcolor();
		void setValuetextcolor();
		void setButtons();
		void setKeyzones();
		void showOSCDialog();
		void updateValues();
		void updateBacklights();
		void updateColors();
		void updateOSCInfo();
		void updatePedalview();
		void updateWidgets();
		void zapPreset(bool direction);

	public slots:
};

#endif /*_QKONTROLWINDOW_H_*/

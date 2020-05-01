CONFIG += release
TEMPLATE += app
TARGET = qkontrol 
DEPENDPATH += . widgets
INCLUDEPATH += . widgets

QT += network widgets gui testlib xml

FORMS += qkontrol.ui oscdialog.ui
HEADERS += qkontrol.h widgets/qxtstringspinbox.h widgets/qxtspanslider.h widgets/qxtspanslider_p.h dropgraphicsscene.h dropgraphicsview.h oscdialog.h
SOURCES += main.cpp qkontrol.cpp widgets/qxtstringspinbox.cpp widgets/qxtspanslider.cpp dropgraphicsscene.cpp dropgraphicsview.cpp oscdialog.cpp
RESOURCES += qkontrol.qrc

RC_ICONS = qkontrol.ico

unix:!macx: LIBS += -lhidapi-libusb -lusb-1.0

macx: LIBS += -L/usr/local/Cellar/hidapi/0.9.0/lib/ -lhidapi -L/usr/local/Cellar/libusb/1.0.22/lib/ -lusb-1.0
macx: INCLUDEPATH += /usr/local/Cellar/hidapi/0.9.0/include/hidapi /usr/local/Cellar/libusb/1.0.22/include/libusb-1.0/
macx: DEPENDPATH += /usr/local/Cellar/hidapi/0.9.0/include/hidapi /usr/local/Cellar/libusb/1.0.22/include/libusb-1.0/
macx: PRE_TARGETDEPS += /usr/local/Cellar/hidapi/0.9.0/lib/libhidapi.a /usr/local/Cellar/libusb/1.0.22/lib/libusb-1.0.a

win32: DEFINES += QXT_STATIC
win32: LIBS += -LC:/msys64/mingw64/lib/ -lhidapi -llibusb-1.0
win32: INCLUDEPATH += C:/msys64/mingw64/include
win32: DEPENDPATH += C:/msys64/mingw64/include
win32: PRE_TARGETDEPS += C:/msys64/mingw64/lib/libhidapi.a C:/msys64/mingw64/lib/libusb-1.0.a

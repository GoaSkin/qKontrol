qKontrol is a Linux / macOS application to configure Native Instruments Komplete Kontrol MK2 keyboards.

With this software it is possible to configure MIDI CCs assigned to all knobs, buttons, sliders, wheels and pedals, to split the keyboard into zones and to display assignments, CC values and custom images on the two displays. Furthermore, it offers a possibility to communicate with Bitwig Studio (incl. the Linux version) and maybe other DAWs the start and stop playback and recording, to turn on and of looping and the metronome and to fetch and display information about the currently selected track and plugin names as well as the song position.

![Device LCDs](https://raw.githubusercontent.com/GoaSkin/qKontrol/master/images/lcd.png)

qKontrol is an open 3rd party application. It does not depend on any drivers or software provided by Native Instruments
and comes with it's completely own codebase.

Native Instruments is not responsible for this software in any way. If you need to get support, please ask the community!


SYSTEM REQUIREMENTS:
====================

To run this program on Linux, the following dependencies need to be installed:

- the QT toolkit
- parts of libQXT (included)
- libusb
- libhidapi

On Ubuntu, Debian and Raspbian, run 'apt-get install libqt5gui5 libqt5test5 libhidapi-libusb0 libusb-1.0' to install all the dependencies!

The Mac version comes as application bundle which includes all dependencies. There is no additional software required.


BUILD INSTRUCTIONS:
===================

Ubuntu Linux:

1.) install the following packages from the repositories:

sudo apt-get install qtbase5-dev-tools qtbase5-dev build-essential libhidapi-dev:amd64 libhidapi-libusb0 libusb-1.0-0-dev

2.) dive into the source directory of the program and execute the following commands:

/usr/lib/x86_64-linux-gnu/qt5/bin/qmake
make
strip qkontrol


Mac OS X:

1.) install the developer tools from apple using the app store

2.) download the QT open source edition from https://www.qt.io/ and install it

3.) open a terminal to install libhidapi and libusb using brew:

ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)" < /dev/null 2> /dev/null
brew install libusb
brew install libhidapi

4.) start the program "QT creator" from your recently installed QT distribution, open the .pro file from the qkontrol source
    and build the program using the menus

5.) (optionally) if you want to give your build to others which don't have QT installed theirselves, then locate the tool
    'macdeployqt' from your QT installation. When found, then open a terminal and go into the folder where QT creator placedi
    the executable app bundle. Execute /the/folder/where/you/can/find/macdeployqt qkontrol.app. 

Windows:

1.) De-install the Komplete Kontrol Software and the NI Host Agent if installed. This software cannot coexist on Windows.

2.) Visit https://www.native-instruments.com/de/support/downloads/drivers-other-files/ , download and install the Komplete
    Kontrol MK2 drivers.

3.) Download ZADIG from https://zadig.akeo.ie/ and start this tool. Research for USB devices and select
    "Komplete Kontrol MK2 BD". When selected, replace the driver! This is necessary because we cannot interact with the
    original Native Instruments driver. The prior installation is only necessary for MIDI.

4.) Visit https://www.msys2.org/ . There, download and install MSYS2. After the installation,
    a shell opens and we need to    install  the dependencies by typing in these commands:

- pacman -S mingw-w64-x86_64-hidapi
- pacman -S mingw-w64-x86_64-libusb

5.) download the QT open source edition from https://www.qt.io/ and install it

6.) start the program "QT creator" from your recently installed QT distribution, open the .pro file from the qkontrol source
    and build the program using the menus. Use minGW 64 bit as toolchain because others won't work. After the program has been
    compiled, it doesn't start through the QT creator. That is normal at this point. Ignore this!

7.) Locate the place of your freshly compiled qkontrol.exe and run the program!
    It does just list a lot of missing DLLs. Notice the names, locate them on your harddisk and copy them all into this directory.

8.) run the program again to check if it works now.

9.) if you want to redistribute the compiled windows vesion, it is a good idea to pack all the DLLs into the archive and maybe also the driver you created with ZADIG.
    
   
KNOWN ISSUES:
=============

- On Linux, this program only runs with root permissions because the Linux kernel does not grant any device permissions
  to normal users. If you want to use the program as normal user, move the file '79-udev-komplete.rules' into the directory
  /etc/udev/rules.d/ and reboot!

- On macOS, three system services need to be terminated before this program can access the device properly.
  The software asks on startup, if it should do it for you.

- The current CC values are only displayed while a MIDI application is opened which receives MIDI data from the
  Komplete Kontrol. This is because the keyboard does only send the HID messages containing the CC values while
  MIDI data is beeing requested

- At last, this software is usable with the Komplete Kontrol MK2 only. This includes all Komplete Kontrol keyboards
  with two displays on it. Like the first edition of the Komplete Kontrol keyboards, the models M32, A25, A49 and A61
  are also different hardware and not compatible.

- Sometimes, the left and right key send their key codes continously instead of one time per touch.

LICENSE:
========

You are permitted to use, modify and distribute this software under the terms and conditions of the LGPL license.
Please read the LICENSE file for more details! LGPL was chosen because some dependencies of this software are
also released under the terms and conditions of the LGPL license. I would really prefer to waive the copyright
protection but that is not possible.

This software comes with the source code of two 3rd party widgets from the libQXT project. The source files you
will find in the widget/ subdirectory. These widgets, you may also use under the terms and conditions of the 
CPL license. For more details, read the LICENSE file in the widgets/ subdirectory!

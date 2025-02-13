# Serial Port Repeater

Arduino serial port repeater used for configuring common bluetooth modules such as the HC-05 or the HM-10.

HM-10 BLE module official website (orignal, no clone): http://www.jnhuamao.cn

## Notes

The code has been implemented and tested on an Arduino Pro Mini clone board based on the ATmega328P microcontroller.

This project uses Git submodules. In order to get its full source code, please clone this Git repository to your local workspace, then execute the follwoing command from within the repository's root directory: `git submodule update --init`.

The following dependencies should to be installed:

* `pip install pyserial`

This project can be compiled from command line using a makefile. Following are the available make commands:

* Compile the project: `make`
* Remove compiled artefacts: `make clean`
* Upload to Arduino board: `make upload`

Prior to uploading the firmware, please ensure that the following parameaters are configured correctly in `Makefile`:

* `BOARD_TAG`: Device type as listed in `boards.txt` or `make show_boards` (e.g.: pro, uno).
* `BOARD_SUB`: Submenu as listed in `boards.txt` or `make show_submenu` (e.g.: 16MHzatmega328, atmega168)
* `MONITOR_BAUDRATE`: Serial port Baud rate (possible values: 4800, 9600, 14400, 19200, 28800, 38400, 57600, 115200)
* `MONITOR_PORT`: Serial port device (e.g.: /dev/tty.usbserial-00000000)

For more information, please refer to [Arduino-Makefile on GitHub](https://github.com/sudar/Arduino-Makefile).
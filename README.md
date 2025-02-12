# Serial Port Repeater

Arduino serial port repeater used for configuring common bluetooth modules such as the HC-05 or the HM-10.


## Notes

The code has been implemented and tested on an Arduino Pro Mini clone board based on the ATmega328P microcontroller with an 8 MHz crystal.

This project uses Git submodules. In order to get its full source code, please clone this Git repository to your local workspace, then execute the follwoing command from within the repository's root directory: `git submodule update --init`.

The following dependencies should to be installed:
* `pip install pyserial`

This project can be compiled from command line using the via makefile using the following commands:

* Compile: `make`
* Remove compiled artefacts: `make clean`
* Upload to Arduino board: `make upload`
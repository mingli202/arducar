# define all the targets that are not files (will run its recipe regardless of whether a file with name exists)
# .PHONY: all say_hello generate clean

PORT = /dev/cu.usbmodem11101
PATH = /Users/vincentliu/phys-project/Main

all: compile upload

compile:
	arduino-cli compile -b arduino:avr:uno ${PATH} --build-path build --libraries libraries

upload:
	arduino-cli upload ${PATH} -p ${PORT} -b arduino:avr:uno --input-dir build

monitor:
	arduino-cli monitor -p ${PORT}


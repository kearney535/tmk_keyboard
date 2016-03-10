SMK-104 keyboard firmware
=========================

Sam's keyboard.

## Build
Move to this directory then just run `make` like:

    $ make


## Keymap
To define your own keymap create file named `keymap_<name>.c` and see keymap document(you can find in top README.md) and existent keymap files.

To build firmware binary hex file with a certain keymap just do `make` with `KEYMAP` option like:

    $ make KEYMAP=[<name>]


### 1  Standard
[keymap_standard.c](keymap_standard.c) is a map for a standard 104-key keyboard with no Fn key.


## Hardware

Teensy GPIO hookups:

| Column | Input | Row | Output | Led | Output |
|:------:|:-----:|:---:|:------:|:---:|:------:|
| 0 | PTB0 | 0 | PTF0 | Caps Lock | PTB4 |
| 1 | PTB1 | 1 | PTF1 | Scroll Lock | PTD7 |
| 2 | PTB2 | 2 | PTF4 | Num Lock | PTD6 |
| 3 | PTB3 | 3 | PTF5 | | |
| 4 | PTB7 | 4 | PTF6 | | |
| 5 | PTD0 | 5 | PTF7 | | |
| 6 | PTD1 | 6 | PTB6 | | |
| 7 | PTD2 | 7 | PTB5 | | |
| 8 | PTD3 | | | | |
| 9 | PTC6 | | | | |
| 10 | PTC7 | | | | |
| 11 | PTD5 | | | | |
| 12 | PTD4 | | | | |

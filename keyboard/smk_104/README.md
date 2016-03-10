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

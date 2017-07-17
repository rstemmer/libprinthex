# libPrintHex

## Installation

You should check the `install.sh` script before executing.
The default installation path is _/usr/local/{lib,include}_

```bash
./build.sh
sudo ./install.sh
```

## Usage

```c
int printhex(void* buffer, int size, int bytesperline, ... );
```

This function prints the bytes of a buffer as a typical hex-view to the screen.

##### void* buffer

_buffer_ points to the bytes that will be printed by `printhex`.
This can be anything as long as there is read access to _size_ bytes started at the address
_buffer_ points to. 

##### int size

The _size_ is the number of bytes that will be printed in total.
It should be less or equal to the buffer _buffer_ points to.

##### int bytesperline

This parameter determines how many bytes will be printed in each line.
A good argment would be `16`.

##### ...

The optional arguments are in alternating _offset_ and _color_.
There can be as many pairs of _offset_ and _color_ as there are bytes in the _buffer_.
When the internal index to the values inside the buffer reached _offset_, the new text _color_ gets read from the argument list.
Furthermore the next _offset_ will be read. So the algorithm expects an infinit list of offsets and colors.
The last value has to be an offset that will never be reached (a good value is `-1`).

The _offset_ must be an integer between `0` and `bytesperline - 1`.
Furthermore it must be greater than the previous offset given in the list or arguments.
It determines the offset from which a new color will be used to print the values of the _buffer_.

The _color_ is the ANSI escape sequence for the color that will be used to print the values of the _buffer_ after the _offset_ related to that color is reached.

##### return value

This function always returns 0

## Example

```c
// Display Hello World, with World in green letters
char *helloworld = "Hello World";
printhex(helloworld, strlen(helloworld), 16, 
        6, "\e[1;32m",   // Green World
        -1);             // (end of offset/color list)
printf("\n");
```

You will find a real example in the _test.c_ file.


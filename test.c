#include <stdlib.h>
#include <stdio.h>
#include <printhex.h>

int main()
{
    unsigned char *bitmap = (unsigned char*)
        "\x42\x4D\x3A\x00" "\x00\x00\x00\x00"  "\x00\x00\x36\x00" "\x00\x00\x28\x00"
        "\x00\x00\x01\x00" "\x00\x00\x01\x00"  "\x00\x00\x01\x00" "\x18\x00\x00\x00"
        "\x00\x00\x04\x00" "\x00\x00\xC4\x0E"  "\x00\x00\xC4\x0E" "\x00\x00\x00\x00"
        "\x00\x00\x00\x00" "\x00\x00\xFF\xFF"  "\xFF\x00"
        ;
	
	printhex(bitmap, 0x3A, 16, 
             0, "\e[1;35m",         // Magic Number
             2, "\e[1;36m",         // BMP size
             6, "\e[1;30m",         // reserved section
            10, "\e[1;34m",         // Offset of image data
            14, "\e[1;36m",         // Info block size
            18, "\e[1;34m",         // Size of Image in Px
            26, "\e[1;30m",         // Irrelevant for BMP
            28, "\e[1;34m",         // Bits per pixel
            30, "\e[0;34m",         // Compression mode
            34, "\e[1;30m",         // Pixels per meter
            46, "\e[0;34m",         // Color table related
            54, "\e[1;37m\e[44m",   // Blue Value of first Pixel
            55, "\e[1;37m\e[42m",   // Green Value of first Pixel
            56, "\e[1;37m\e[41m",   // Red Value of first Pixel
            57, "\e[0;31m",         // Padding byte
            -1);                    // (no further color changes)
	printf("\n");

	return EXIT_SUCCESS;
}


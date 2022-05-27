# Improved MarkDown reader ( IMD )

The IMD is a markdown reader designed to look good and be useful.

IMD is written in C and must be recompiled for configuration.


# Requirements

- [(GNU) LibC](https://www.gnu.org/software/libc/)
- [(MAKE) GCC](https://gcc.gnu.org/)
- [(MAKE) Git](https://git-scm.com/)
- [(MAKE) Python](https://www.python.org/)
- [(MAKE) (GNU) Make](https://www.gnu.org/software/make/)
- [(MAKE) BinUtils](https://www.gnu.org/software/binutils/)
- [(MAKE) GZip](https://www.gnu.org/software/gzip/)


# To Know

Development is shown is the file `./TODO.md`.

A unchecked box means it's no implemented.

A slashed box means it's partiality implemented.

A checked box means it's fully implemented.


Known bugs are in the `./BUGS.md` file.


# Configuration

Run `make configure` to configure the program.

***Configuration files not fully implemented***
***Edit `./confs/default.json` to change styling***


# Install

Run `sudo make install` it will

 - Clean previous build
 - Rebuild all files
 - Strip and zip files
 - Install binaries and data


# Uninstall

Run `sudo make uninstall`.


# Build

Run `make build` to build and strip.

Run `make clean` to clean previous build.

Run `make configure` to configure and generate necessary files for build process.

Run `make all` to build on a development build. ***This will run the built program with test file***

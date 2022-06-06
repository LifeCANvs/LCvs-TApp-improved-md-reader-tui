# Improved MarkDown reader ( IMD )

The IMD is a markdown reader designed to look good and be useful.

IMD is written in C and must be recompiled for configuration.


# Examples

![top](/img/top.png)
![bottom](/img/bottom.png)


# Requirements

- [(GNU) LibC](https://www.gnu.org/software/libc/)
- C Compiler
  - [GCC](https://gcc.gnu.org/)
  - [CLANG](https://clang.org/)
- [(GNU) Make](https://www.gnu.org/software/make/)
- [BinUtils](https://www.gnu.org/software/binutils/)
- [(MAKE) Git](https://git-scm.com/)
- [(MAKE) Python](https://www.python.org/)
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


# AUR

IMD is on the AUR at https://aur.archlinux.org/packages/imd-git.

I Recommend using [Trizen](https://github.com/trizen/trizen) to download. ***Yay doesn't work***


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

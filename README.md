# BetterLighting

Backlight controller. Might not be better, but does what I need it to do.
Somehow all of the offerings out there didn't work for me. 
*This was written on a late night and does therefore not come with any guarantees of working at all.*

*tl;dr: YMMV...*

## Build

Requires cmake, some buildsystem that runs under cmake (e.g. GNU Make or Ninja), and a C++17 compliant compiler (for std::filesystem). The most recent g++/clang++ in your standard package repo will probably do. 

```sh
$ cmake -B build .
$ make -C build
```

## install

The following will install the program system wide. 

```
# make -C build install
```

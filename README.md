# VisualSort
Simple sorting algorithm visualiser in C++ with ncurses.\
I made this project to play around with modules.

## Building and Running
* [Install ``xmake``](https://xmake.io/#/getting_started?id=installation)
* As of writing this, following command is required to get C++ standard library modules to work. Replace ``<sdk>`` with a path to your llvm >=18 installation. (for example ``/usr/bin/llvm-19/``)\
```xmake f --toolchain=clang --runtimes=c++_shared --sdk=<sdk>```
* ``xmake build``
* ``xmake run``
KiVM
=============
[![Build Status](https://travis-ci.org/imkiva/KiVM.svg?branch=master)](https://travis-ci.org/imkiva/KiVM)
[![GitHub top language](https://img.shields.io/github/languages/top/imkiva/KiVM.svg)](https://github.com/imkiva/KiVM)
[![license](https://img.shields.io/github/license/imkiva/KiVM.svg?colorB=000000)](https://github.com/imkiva/KiVM)

Kiva's Java Virtual Machine.

### Features
- JNI Support
- JAR Class Loading Support (libzip needed)
- Full OracleJDK/OpenJDK compatibility
- Copying Garbage Collector

### Build
1. Requirements
    * Linux or macOS. **Windows is not supported yet.**
    * JDK (OpenJDK or OracleJDK) (>= 8)
    * CMake (>= 3.2)
    * libzip (>= 1.5.1) (to support JAR Class Loading)

2. Build instructions
    * Clone this repo.
    * `cd` into your directory that contains KiVM source code.
    * Type `cmake . && make` in your terminal app.
    * Enjoy it!

### Run
```bash
$ export CLASSPATH=</path/to/rt.jar>:</path/to/charsets.jar>:...
$ ./java <main-class-name> [args...]
```

### Credit
* Inspired by [wind_jvm](https://github.com/wind2412/wind_jvm)
* Modified version of [libzippp](https://github.com/ctabin/libzippp)

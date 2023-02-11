# Gui Test C++ Linux

## Tools

- XLib11
  - make sure you have this installed on your machine

## How To Build

### Release

```
cd ./tools
make
make run
```

### Debug

```
cd ./tools
make debug
make run
```

Make sure to call `make clean` if you want to build debug after release, as `make run` checks for release first
Debug mode will also build assembly files that can be used to track down performance issues

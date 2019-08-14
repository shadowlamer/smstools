## Usage
```
sendsms <number> <test>
	One of smstools example scripts

ussd.sh <ussd>
viewsms.sh <smsd incoming file>
sms2utf8.sh <smsd incoming file>
	Will produce <file>.utf8
```

## Make DEB package with CMake

```
cmake .
make package
```

## Make package for ARM64

```
cmake -DCMAKE_TOOLCHAIN_FILE=cmake_toolchains/ubuntu-arm64.cmake .
make package
```
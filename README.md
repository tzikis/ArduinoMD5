This is an MD5 library for the Arduino, based on tzikis's MD5 library, which you can find here:
https://github.com/tzikis/arduino.
Tzikis library was based on scottmac`s library, which you can find here: 
https://github.com/scottmac/arduino

This library provides an easy way of using md5 for both arduino and Raspberyy Pi.

It includes MD5 and HMAC-MD5.

### Installation
Create a folder named _MD5_ in the _libraries_ folder inside your Arduino sketch folder. If the
libraries folder doesn't exist, create it. Then copy everything inside. (re)launch the Arduino IDE.

You're done. Time for a mojito

### Usage

If you create md5 Hashes in a loop you must give the Memory back to the System 
```
unsigned char* hash=MD5::make_hash("hello world");
//generate the digest (hex encoding) of our hash
char *md5str = MD5::make_digest(hash, 16);
//print it on our serial monitor
Serial.println(md5str);
//Give the Memory back to the System if you run the md5 Hash generation in a loop
free(md5str);
```

### Raspberry  pi
install
```
sudo make install
cd examples_Rpi
make
```

What to do after changes to the library
```
sudo make clean
sudo make install
cd examples_Rpi
make clean
make
```

What to do after changes to a sketch
```
cd examples_Rpi
make <sketch>

or 
make clean
make
```

How to start a sketch
```
cd examples_Rpi
sudo ./<sketch>
```

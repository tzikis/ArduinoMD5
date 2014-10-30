This is an MD5 library for the Arduino, based on scottmac's MD5 library, which you can find here:
https://github.com/scottmac/arduino

I created this because I was having a really hard time finding an easy-to-install and use libray for the Arduino,
so I decided to make my own. There is an example on how to use it.

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

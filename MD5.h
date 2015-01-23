#ifndef MD5_h
#define MD5_h

/**
 * @file MD5.h
 *
 * Class declaration for MD5 and helper enums
 */

#include "MD5_config.h"
/*
 * This is an OpenSSL-compatible implementation of the RSA Data Security,
 * Inc. MD5 Message-Digest Algorithm (RFC 1321).
 *
 * Written by Solar Designer <solar at openwall.com> in 2001, and placed
 * in the public domain.  There's absolutely no warranty.
 *
 * This differs from Colin Plumb's older public domain implementation in
 * that no 32-bit integer data type is required, there's no compile-time
 * endianness configuration, and the function prototypes match OpenSSL's.
 * The primary goals are portability and ease of use.
 *
 * This implementation is meant to be fast, but not as fast as possible.
 * Some known optimizations are not included to reduce source code size
 * and avoid compile-time configuration.
 */

/*
 * Updated by Scott MacVicar for arduino
 * <scott@macvicar.net>
 */

typedef unsigned long MD5_u32plus;

typedef struct {
	MD5_u32plus lo, hi;
	MD5_u32plus a, b, c, d;
	unsigned char buffer[64];
	MD5_u32plus block[16];
} MD5_CTX;/**< MD5 context */

class MD5
{
public:
	/**
	 * class constructor.
	 * Does nothing.
	 */
	MD5();
	
	/** Created the MD5 hash from a string of characters on hex encoding.
	 * 
	 * 	It is one of the main function of this class.
	 *  Gets an pointer to a string, and hash it to MD5.
	 * 
	 *  @param *arg pointer to the string or array of characters.
	 *  @return a pointer containing the MD5digest
	 * 
	 */
	unsigned char* make_hash(const void *arg);
	
	/** Converts a digest to a string.
	 * 
	 * 	In order for tedigest to be readable and printed easyly, we need to conver it.
	 * 
	 * 	@param *digest pointer to the array that holds the digest
	 *  @param len integer defining the lengs of the output, usually 16 for MD5
	 *  @return poiner to the string that holds the String of the converted digest
	 */
	char* make_digest(const unsigned char *digest, int len);
	
	/** Automation function.
	 *  Gets a pointer to sequence of chars,
	 *  Then Hashes it, and converts it to a readable form,
	 * 
	 *  @param *arg pointer to the string that will be hashed.
	 *  @return pointer to the string that holds the string of the converted digest.
	 */
	char* md5(const void *arg);
	
	/** Main function of the HMAC-MD5.
	 *  gets the key and the text, and creates the HMAC-MD5 digest function.
	 *  in order to be pronted, it is required for the make_digest function to be called.
	 *  @code make_digest(digest,BLOCK_SIZE); @endcode
	 *  
	 *  @param *text pointer to the text that will be hashed.
	 *  @param text_len integet value of the length of the text.
	 *  @param *key pointer to the key that will be used in the HMAC process.
	 *  @param key_len integer value of the key length.
	 *  @param *digest pointer to the array that will hold the digest of this process
	 *  @return the digest in the memory block that the *digest is pointing.
	 */
	void hmac_md5(const void *text, int text_len,void *key, int key_len, unsigned char *digest);
	
	/** Main function of the HMAC-MD5.
	 *  gets the key and the text, and creates the HMAC-MD5 digest function in a readable format.
	 *  
	 *  @param *text pointer to the text that will be hashed.
	 *  @param text_len integet value of the length of the text.
	 *  @param *key pointer to the key that will be used in the HMAC process.
	 *  @param key_len integer value of the key length.
	 *  @return pointer that points to the digest in a readable format.
	 */
	char* hmac_md5(const void *text, int text_len,void *key, int key_len);
	
	/** This processes one or more 64-byte data blocks, but does NOT update the bit counters.  
	 *  There are no alignment requirements.
	 * 
	 *  @param *ctxBuf the ctx buffer that will be used
	 *  @param *data pointer to the data that will be processed
	 *  @param size size_t type, that hold the size
	 */
 	static const void *body(void *ctxBuf, const void *data, size_t size);
 	
 	/** Initialized the MD5 hashing process.
 	 *  this function must be called before MD5Update or MD5Final
	 * 
	 *  @param *ctxBuf the ctx buffer that will be used
	 */
	static void MD5Init(void *ctxBuf);
	
	
 	/** MD5Final finilized the Hashing process and creates the diggest.
	 *  This function must be called after MD5Init and MD5Update
	 *  @param *result pointer that will hold the digest.
	 *  @param *ctxBuf the ctx buffer that will be used
	 *  @return no return, the result is storesin the *result pointer
	 */
	static void MD5Final(unsigned char *result, void *ctxBuf);
	
	/** MD5Update adds data in the buffers.
	 *  This function can be used as many times as we want in the hashing process.
	 *  Examples on hmac_md5 functions.
	 * 
	 *  @param *ctxBuf the ctx buffer that will be used
	 *  @param *data the actual data that will be used in the hashing process.
	 *  @param size size_t type, indicated the side of the data pointer.
	 */
	static void MD5Update(void *ctxBuf, const void *data, size_t size);
	#if defined(MD5_LINUX)
			/**
			 * used in linux in order to retrieve the time in milliseconds.
			 *
			 * @return returns the milliseconds in a double format.
			 */
			double millis();
	#endif
private:
	#if defined(MD5_LINUX)
			timeval tv;/**< holds the time value on linux */
	#endif
};
extern MD5 hashMD5;
#endif

/**
 * @example MD5_Hash.ino
 * <b>For Arduino</b><br>
 * <b>Updated: spaniakos 2015 </b><br>
 *
 * This is en example of how to use my MD5 library.<br />
 * It provides two easy-to-use methods, one for generating the MD5 hash, and the second
 * one to generate the hex encoding of the hash, which is frequently used.
 * 
 * <b>UPDATE:<b> Now only md5 function is used that return only the hex encoding directlly.<br />
*/
 
 /**
 * @example MD5_Hash.cpp
 * <b>For Rasberry Pi</b><br>
 * <b>Updated: spaniakos 2015 </b><br>
 *
 * This is en example of how to use MD5 library. <br />
 * It provides two easy-to-use methods, one for generating the MD5 hash, and the second
 * one to generate the hex encoding of the hash, which is frequently used.
 * 
 * <b>UPDATE:<b> Now only md5 function is used that return only the hex encoding directlly.<br />
*/

/**
 * @example HMAC_MD5.ino
 * <b>For Arduino</b><br>
 * <b>Updated: spaniakos 2015 </b><br>
 *
 * This is an example of how to use HMAC of this MD5 library.<br />
 * The text and keys can be either in HEX or String format.<br />
 * The examples are from the RFC2202 Test Vectors
 */
 
 /**
 * @example HMAC_MD5.cpp
 * <b>For Rasberry pi</b><br>
 * <b>Updated: spaniakos 2015 </b><br>
 *
 * This is an example of how to use HMAC of this MD5 library.<br />
 * The text and keys can be either in HEX or String format.<br />
 * The examples are from the RFC2202 Test Vectors
 */

/**
 * @mainpage MD5 and HMAC-MD5 library for Arduino and Raspberry pi.
 *
 * @section Goals Design Goals
 *
 * This library is designed to be...
 * @li Fast and efficient
 * @li Able to effectivelly hash any size of string
 * @li Able to use any format of key for HMAC (hex or string)
 * @li Easy for the user to use in his programms
 * @li to hash using MD5
 * @li to hash using HMAC-MD5
 *
 * @section Acknowlegments Acknowlegments
 * This is an MD5 library for the Arduino, based on tzikis's MD5 library, which you can find <a href= "https://github.com/tzikis/arduino">here:</a>.<br />
 * Tzikis library was based on scottmac`s library, which you can find <a href="https://github.com/scottmac/arduino">here:</a><br /> 
 * 
 * @section Installation Installation
 * <h3>Arduino</h3>
 * Create a folder named _MD5_ in the _libraries_ folder inside your Arduino sketch folder. If the 
 * libraries folder doesn't exist, create it. Then copy everything inside. (re)launch the Arduino IDE.<br />
 * You're done. Time for a mojito
 * 
 * <h3>Raspberry  pi</h3>
 * <b>install</b><br /><br />
 * 
 * sudo make install<br />
 * cd examples_Rpi<br />
 * make<br /><br />
 * 
 * <b>What to do after changes to the library</b><br /><br />
 * sudo make clean<br />
 * sudo make install<br />
 * cd examples_Rpi<br />
 * make clean<br />
 * make<br /><br />
 * <b>What to do after changes to a sketch</b><br /><br />
 * cd examples_Rpi<br />
 * make <sketch><br /><br />
 * or <br />
 * make clean<br />
 * make<br /><br /><br />
 * <b>How to start a sketch</b><br /><br />
 * cd examples_Rpi<br />
 * sudo ./<sketch><br /><br />
 * 
 * @section News News
 *
 * If issues are discovered with the documentation, please report them <a href="https://github.com/spaniakos/spaniakos.github.io/issues"> here</a>
 * @section Useful Useful References
 *
 * Please refer to:
 *
 * @li <a href="http://spaniakos.github.io/ArduinoMD5/classMD5.html"><b>MD5</b> Class Documentation</a>
 * @li <a href="https://github.com/spaniakos/ArduinoMD5/archive/master.zip"><b>Download</b></a>
 * @li <a href="https://github.com/spaniakos/ArduinoMD5/"><b>Source Code</b></a>
 * @li <a href="http://spaniakos.github.io/">All spaniakos Documentation Main Page</a>
 *
 * @section Board_Support Board Support
 *
 * Most standard Arduino based boards are supported:
 * - Arduino
 * - Intel Galileo support
 * - Raspberry Pi Support
 * 
 * - The library has not been tested to other boards, but it should suppport ATMega 328 based boards,Mega Boards,Arduino Due,ATTiny board
 */

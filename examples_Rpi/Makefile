#############################################################################
#
# Makefile for MD5 examples on Raspberry Pi
#
# License: GPL (General Public License)
# Author:  spaniakos <spaniakos@gmail.com>
# Date:    01/12/2014 (version 1.0)
#
# Description:
# ------------
# use make all and make install to install the examples
# You can change the install directory by editing the prefix line
#
prefix := /usr/local

# The recommended compiler flags for the Raspberry Pi
CCFLAGS=-Ofast -mfpu=vfp -mfloat-abi=hard -march=armv6zk -mtune=arm1176jzf-s
#CCFLAGS=

# define all programs
PROGRAMS = MD5_Hash HMAC_MD5
SOURCES = ${PROGRAMS:=.cpp}

all: ${PROGRAMS}

${PROGRAMS}: ${SOURCES}
	g++ ${CCFLAGS} -Wall -I../ -lMD5 $@.cpp -o $@

clean:
	rm -rf $(PROGRAMS)

install: all
	test -d $(prefix) || mkdir $(prefix)
	test -d $(prefix)/bin || mkdir $(prefix)/bin
	for prog in $(PROGRAMS); do \
	  install -m 0755 $$prog $(prefix)/bin; \
	done

.PHONY: install

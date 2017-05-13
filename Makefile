
libs := libusb-1.0
bin := req retr reset runseq run testfile

CC ?= cc
CFLAGS := -Wall -ggdb $(shell pkg-config --cflags $(libs))
LDFLAGS := $(shell pkg-config --libs $(libs)) -lreadline -O0

all: ${bin}

%: %.c
	 ${CC} $< ${CFLAGS} ${LDFLAGS} -o $@

clean:
	rm -vf ${bin}

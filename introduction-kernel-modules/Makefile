obj-m += slide-20.o
obj-m += slide-33.o
obj-m += slide-45.o
obj-m += slide-51.o
obj-m += slide-57.o
obj-m += slide-59.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

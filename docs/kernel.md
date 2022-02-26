# make a module driver

    make -C $(KDIR) M=$(PWD) modules
    生成.ko
    depmod
    modprobe module_name
    lsmod
    insmod
    rmmod
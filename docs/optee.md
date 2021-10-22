# secure os

安全存储：
OP-TEE Secure Storage目前采用REE FS Secure Storage的方式。
即SECURE OS 将数据进行加密，然后保存到文件系统/data/tee目录下

TA程序:
Trusted Apps,在SECURE OS下执行的应用程序,存放在文件系统的
/lib/optee_armtz/目录下

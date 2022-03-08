#!/usr/bin/env python

import socket
import time

s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.connect(('127.0.0.1',30000))

def protocol_crc_check(data,len):
    factor= 0x107 & 0xff
    crc = 0x00
    for i in range(len):
        crc ^= data[i]
        print('crc:%d' % crc)
        for j in range(8):
            if crc & 0x80 > 0:
                crc = (crc << 1) ^ factor
            else:
                crc <= 1
        print('i:%d' % i)
        print('crc:%d' % crc)
    return crc


def send_packet(cmd):
    dle = 0x0d
    som = 0x05
    dom_send = 0x2a
    dom_recv = 0x46
    len = [0x00,0x01]
    data = [0x01]
    eof = 0x0a
    print(dle)
    crc_check_data = [0x00,0x01,0x00]
    crc = protocol_crc_check(crc_check_data,3)
    print('crc:%d' % crc)

    data_packet = [dle,som,dom_send,cmd,crc,dle,eof]
    data_packet[4:4] = iter(len)
    data_packet[5:5] = iter(data)
    
    print(data_packet)
    s.sendall(bytes(data_packet))

send_packet(0x01)

    #data=s.recv(1024)     #把接收的数据定义为变量
    #print('recv:',data)         #输出变量
time.sleep(1)
s.close()   #关闭连接
#!/usr/bin/env python3
import argparse
import subprocess
import time
import os
from pathlib import Path
import re


def adb_env_setup():
    subprocess.run('adb forward tcp:30000 tcp:30000')
    subprocess.run('adb forward tcp:30021 tcp:30021')
    subprocess.run('adb forward tcp:17525 tcp:17525')

    subprocess.run('./cli_client.exe toggle_adb_shell')
    subprocess.run('./cli_client.exe toggle_ftp')
    subprocess.run('./cli_client.exe set_bmp_lift --state 0')

def check_adb_device():
    res=subprocess.getoutput("adb devices")
    match_result=re.search(r'\bdevice\b',res)
    if match_result is None:
        print('adb device not found')
        return False
    else:
        print('adb device found')
        return True

def ftp_test(folder):
    adb_env_setup()
    subprocess.run("adb shell rm -r /mnt/UDISK/%s" % folder)
    ftp_passwd=subprocess.getoutput(''' adb shell "ps -w | grep ftp | grep -v grep" ''')
    ftp_passwd=ftp_passwd.split(' ')
    ftp_passwd=ftp_passwd[-1].split('\n')
    ftp_passwd=ftp_passwd[0]
    print(ftp_passwd)

    time_start=time.time()
    size=os.path.getsize(folder)
    print(size)
    paths=os.walk(folder)
    for path,dir_list,file_list in paths:
        for file_name in file_list:
            file_path_foramt=Path(os.path.join(path, file_name)).as_posix()
            print("file path:",file_path_foramt)

            size += os.path.getsize(file_path_foramt)

            subprocess.run("curl.exe -u %s --ftp-create-dirs -T %s ftp://127.0.0.1:30021/%s" % (ftp_passwd,file_path_foramt,file_path_foramt))
    time_end=time.time()
    time_spend=time_end - time_start
    print('size is:',size/1024)

    print('use time',time_end - time_start)
    print('speed:%dKB/s(%dKB in %ds)' % (int(size/1024/time_spend),int(size/1024),int(time_spend)))
    return ('speed:%dKB/s(%dKB in %ds)' % (int(size/1024/time_spend),int(size/1024),int(time_spend)))




def ftp_pressure_test_handler(args):
    print('folder path:%s' % args.folder)
    print('ftp pressure testing...')
    ftp_test(args.folder)


def update_pressure_test_handler(args):
    print(args.update_file)
    print('update file path:%s' % args.update_file)
    print('update pressure testing...')


parser = argparse.ArgumentParser(prog='nccd_test')
subparsers = parser.add_subparsers(title='Available commands',
                                   metavar='commands')
ftp_pressure_test_parser = subparsers.add_parser('ftp_pressure_test',
                                                 help='run ftp pressure_test')
ftp_pressure_test_parser.add_argument('--folder', '-f',
                           help='ftp pressure test folder path',
                           metavar='folder',
                           required=True, dest='folder')

ftp_pressure_test_parser.set_defaults(handler=ftp_pressure_test_handler)

# commit
update_pressure_test = subparsers.add_parser('update_pressure_test',
                                      help='run update pressure test')
update_pressure_test.add_argument('--update_file', '-f',
                           help='update test file path',
                           metavar='update_file',
                           required=True, dest='update_file')

update_pressure_test.set_defaults(handler=update_pressure_test_handler)

args = parser.parse_args()
#print(args)
if hasattr(args, 'handler'):
    args.handler(args)
else:
    parser.print_help()
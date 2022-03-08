#!/usr/bin/python3

import argparse
from unicodedata import name
parser = argparse.ArgumentParser()
parser.add_argument('--foo', help='foo help')
parser.add_argument('-cmd', help='cmd')
parser.add_argument('-cmd2', help='cmd2')

subparsers = parser.add_subparsers(title='submodule',description='valid subcommands')
subparsers.add_parser('foo')
subparsers.add_parser('bar')
args = parser.parse_args()

print(args)

if 'foo' in args:
    print(args.foo)
    print('foo handler')

if 'cmd' in args:
    print('cmd handler') 


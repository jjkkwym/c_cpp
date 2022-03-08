#!/usr/bin/env python

import logging
import sys
FORMAT = '[%(asctime)s] %(message)s'

# d = {'clientip': '192.168.0.1', 'user': 'fbloggs'}
# logger = logging.getLogger('tcpserver')
# logger.warning('Protocol problem: %s', 'connection reset', extra=d)

# FORMAT = '[%(asctime)s]'
# logging.basicConfig(format=FORMAT)
# d = {'clientip': '192.168.0.1', 'user': 'fbloggs'}
# logger = logging.getLogger('tcpserver')
# 
# logger.warning('Protocol problem: %s', 'connection reset', extra=d)
#stdout_handler=logging.StreamHandler(sys.stdout)

logging.basicConfig(level=logging.DEBUG,format=FORMAT)

log=logging.getLogger('123')
log_file=logging.FileHandler("test.log")
log_file.setFormatter(logging.Formatter("[%(asctime)s] [%(levelname)s] %(message)s",datefmt="%Y-%m-%d %H:%M:%S"))
log.addHandler(log_file)

log.info('123')
log.info('123')
log.info('123')
log.info('123')
log.info('1234')
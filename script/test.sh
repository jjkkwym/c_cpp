#!/bin/bash
set -x  #show raw cmd
set -e  #exit when failed

cli_client=cli_client.exe
adb=adb.exe

${adb} forward tcp:30000 tcp:30000  #pctool and nccd_server communication port
${adb} forward tcp:17525 tcp:17525  #ftp data port
${adb} forward tcp:30021 tcp:30021  #ftp cmd port

${cli_client} toggle_adb_shell
${cli_client} query_device_info --data_id 1
${cli_client} query_device_info --data_id 2
${cli_client} query_device_info --data_id 3
${cli_client} query_device_info --data_id 4
${cli_client} query_device_info --data_id 5
${cli_client} query_device_info --data_id 6
${cli_client} query_device_info --data_id 7
${cli_client} query_device_info --data_id 8
${cli_client} query_device_info --data_id 9
${cli_client} query_device_info --data_id A
${cli_client} query_device_info --data_id B
${cli_client} query_device_info --data_id C
#${cli_client} query_device_info --data_id D
${cli_client} query_device_info --data_id E
${cli_client} query_device_info --data_id F
${cli_client} query_device_info --data_id 10
${cli_client} query_device_info --data_id 11


${cli_client} toggle_test_mode --on 1
${cli_client} run_loopback_test --on 0
${cli_client} run_loopback_test --on 1
${cli_client} toggle_tone_test --on 0
${cli_client} toggle_tone_test --on 1
${cli_client} toggle_flash_test --on 0
${cli_client} toggle_flash_test --on 1
${cli_client} toggle_aging_test -o 0
${cli_client} toggle_aging_test -o 1
${cli_client} toggle_aging_test -o 2
${cli_client} toggle_test_mode --on 0
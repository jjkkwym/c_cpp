#!/bin/bash

set -v on
adb.exe forward tcp:17525 tcp:17525
adb.exe forward tcp:30021 tcp:30021
adb.exe forward tcp:30000 tcp:30000

cli_client="./cli_client.exe"

function device_info_pause ()
{
    $1
    read -p "Press enter to continue"    
}

$(cli_client) toggle_adb_shell

echo "auth"
${cli_client} --host localhost --port 30000 auth
read -p "Press enter to continue"

echo "partnumber"
${cli_client} --host localhost --port 30000 query_device_info --data_id 1
read -p "Press enter to continue"

echo "unique serial number"
${cli_client} --host localhost --port 30000 query_device_info --data_id 2
read -p "Press enter to continue"

echo "model"
${cli_client} --host localhost --port 30000 query_device_info --data_id 3
read -p "Press enter to continue"

echo "hardware version"
${cli_client} --host localhost --port 30000 query_device_info --data_id 4
read -p "Press enter to continue"

echo "data pack version"
${cli_client} --host localhost --port 30000 query_device_info --data_id 5
read -p "Press enter to continue"

echo "maker"
${cli_client} --host localhost --port 30000 query_device_info --data_id 6
read -p "Press enter to continue"

echo "fcc"
${cli_client} --host localhost --port 30000 query_device_info --data_id 7
read -p "Press enter to continue"

echo "manufacture data"
${cli_client} --host localhost --port 30000 query_device_info --data_id 8
read -p "Press enter to continue"

echo "project id"
${cli_client} --host localhost --port 30000 query_device_info --data_id 9
read -p "Press enter to continue"

echo "mb number"
${cli_client} --host localhost --port 30000 query_device_info --data_id A
read -p "Press enter to continue"

echo "fw version"
${cli_client} --host localhost --port 30000 query_device_info --data_id B
read -p "Press enter to continue"

echo "device type"
${cli_client} --host localhost --port 30000 query_device_info --data_id C
read -p "Press enter to continue"

echo "provison status"
${cli_client} --host localhost --port 30000 query_device_info --data_id D
read -p "Press enter to continue"

echo "hcd type"
${cli_client} --host localhost --port 30000 query_device_info --data_id E
read -p "Press enter to continue"

echo "root metadata version"
${cli_client} --host localhost --port 30000 query_device_info --data_id F
read -p "Press enter to continue"

echo "app version"
${cli_client} --host localhost --port 30000 query_device_info --data_id 10
read -p "Press enter to continue"

echo "linux"
${cli_client} --host localhost --port 30000 query_device_info --data_id 11
read -p "Press enter to continue"

echo "query provison status"
${cli_client} --host localhost --port 30000 query_provision_status
read -p "Press enter to continue"

echo "set provison status"
${cli_client} --host localhost --port 30000 set_provision_status --status 1
${cli_client} --host localhost --port 30000 query_provision_status
read -p "Press enter to continue"

#test ftp server
${cli_client} --host localhost --port 30000 toggle_ftp --on 0
read -p "Press enter to continue"

#curl.exe -u"CCD_Device:VePgI0+hKVtxZMsUntw9AA==" "ftp://127.0.0.1:30021"
read -p "Press enter to continue"

${cli_client} --host localhost --port 30000 toggle_ftp --on 1
read -p "Press enter to continue"

${cli_client} --host localhost --port 30000 set_volume --volume 3
read -p "Press enter to continue"
${cli_client} --host localhost --port 30000 query_volume
read -p "Press enter to continue"

${cli_client} --host localhost --port 30000 toggle_test_mode --on 0
read -p "Press enter to continue"

${cli_client} --host localhost --port 30000 run_loopback_test --on 0
${cli_client} --host localhost --port 30000 run_loopback_test --on 1
${cli_client} --host localhost --port 30000 toggle_tone_test --on 0
${cli_client} --host localhost --port 30000 toggle_tone_test --on 1
${cli_client} --host localhost --port 30000 toggle_flash_test --on 0
${cli_client} --host localhost --port 30000 toggle_flash_test --on 1
${cli_client} --host localhost --port 30000 toggle_aging_test -o 0
${cli_client} --host localhost --port 30000 toggle_aging_test -o 1
${cli_client} --host localhost --port 30000 toggle_aging_test -o 2

${cli_client} --host localhost --port 30000 toggle_test_mode --on 1
read -p "Press enter to continue"


${cli_client} --host localhost --port 30000 text --text 1234
read -p "Press enter to continue"

${cli_client} --host localhost --port 30000 trigger_generate_keypair
read -p "Press enter to continue"

${cli_client} --host localhost --port 30000 trigger_generate_csr
read -p "Press enter to continue"

${cli_client} --host localhost --port 30000 check_private_key
read -p "Press enter to continue"
#${cli_client} --host localhost --port 30000 install_private_key --path /mnt/UDISK
${cli_client} --host localhost --port 30000 trouble_code
read -p "Press enter to continue"

${cli_client} --host localhost --port 30000 query_firmware_upgrade_status
read -p "Press enter to continue"

${cli_client} --host localhost --port 30000 query_firmware_version
read -p "Press enter to continue"

${cli_client} --host localhost --port 30000 set_bmp_lift --state 0
read -p "Press enter to continue"

${cli_client} --host localhost --port 30000 set_bmp_lift --state 1
read -p "Press enter to continue"

${cli_client} --host localhost --port 30000 sync_time
read -p "Press enter to continue"

${cli_client} --host localhost --port 30000 reset_power
read -p "Press enter to continue"
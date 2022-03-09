# serial permision

    sudo gpasswd --add wym dialout
    groups wym
    gpasswd --del uxdb dialout
## ubuntu 20.04

serial port group belong to plugin-dev group

## wsl 2

serial port belong to root,and there is a unkonwn solution for it


## setting
- sudo chmod 666 /dev/ttyUSB0 - This is required since cu changes it's uid which drops 
- capabilities even when running as root. Not all serial programs have the same behavior.

- stty -F /dev/ttyS5 -a . Optionally check your current serial settings before updating.
Set your serial settings, depending on your application this usually will be raw or sane.

Either one seems to work fine with cu:
- stty -F /dev/ttyS5 sane 115200
- stty -F /dev/ttyS5 raw 115200 -echo -echoe -echok -echoctl -echoke -iexten -onlcr cs8 crtscts
- cu -l /dev/ttyS5 -s 112500
Hit enter to refresh the cu console
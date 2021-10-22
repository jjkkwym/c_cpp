# linux

## mount -o sync and async

using the 'async' mount option might not be the best idea if you have a mount that is constantly being
written to (ex. valuable logs, security camera recordings, etc.) and you are not protected from sudden power
outages. It might result in missing records or incomplete (useless) data.
Not-so-smart example: imagine a thief getting into a store and immediately cutting the camera power cable.
The video recording of the break-in was recorded but might not have been flushed/synced to the disk since it
(or parts of it) might have been buffered in memory instead, thus got lost when the camera lost power.

## serial

sudo screen /dev/ttyUSB0 115200  exit:(ctrl + a) and d or (ctrl + a) and (ctrl + d)

## alternative

sudo update-alternatives --install /usr/bin/cmake cmake ~/cmake-3.21.3-linux-x86_64/bin/cmake 60

delete software
sudo update-alternatives --remove cmake /home/flc/cmake-3.21.3-linux-x86_64/bin/cmake

## ubuntu

apt list --installed

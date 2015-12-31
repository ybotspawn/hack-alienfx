#!/bin/sh

TOGGLE=$HOME/.toggle

if [[ $# > 0 ]]; then
  if [ "$1" = "on" ]; then
    echo "Turning lights On"
    touch $TOGGLE
    fx /usr/fx/snooze
  else
    if [ -e $TOGGLE ]; then
      rm $TOGGLE
    fi
    echo "Turning lights Off"
    fx /usr/fx/battery
  fi
else
  echo "No";
  if [ ! -e $TOGGLE ]; then
      touch $TOGGLE
      echo "Turning lights On"
      fx /usr/fx/snooze
  else
      rm $TOGGLE
      echo "Turning lights Off"
      fx /usr/fx/battery
  fi
fi
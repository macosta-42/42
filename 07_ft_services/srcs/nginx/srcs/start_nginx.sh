#!/bin/bash

openrc
touch /run/openrc/softlevel
service nginx start
rc-service telegraf start
tail -f /dev/null

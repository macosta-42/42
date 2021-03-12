#!/bin/sh

telegraf --config /etc/telegraf/telegraf.conf &
grafana-server

#!/bin/bash

sms=$1
decoded=$sms.utf8
decode="$(dirname "$0")/sms2utf8.sh"

[ -f "$decoded" ] || "$decode" "$sms"

cat "$decoded"
echo

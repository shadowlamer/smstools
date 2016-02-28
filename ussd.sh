#!/bin/bash

modem=/dev/modem
encode=$(dirname $0)/ussd7bit/encode

echo -e 'AT+CUSD=1,"'$($encode $1)'",15\r' > "$modem"
#	---------------------------------------------------
#	Or:
# echo -e 'AT+CUSD=1,"'$(echo $1 | recode utf8..ucs2 | hexdump -e '"%02X"')'",72\r' > "$modem"
#	Or:
# echo -e 'AT+CSCS=GSM\r' > "$modem"
# echo -e 'AT+CUSD=1,"'"$1"'",72\r' > "$modem"
# -----------------------------------------------------

#/bin/sh
echo "Obase=13; ibase=5; $FT_NBR1 + $FT_NBR2" | tr 'mrdoc' '01234' | tr "\'" "0" | tr '\\\"?!' '1234' | tr 'O' 'o' | bc | tr '0123456789ABC' 'gtaio luSnemf'

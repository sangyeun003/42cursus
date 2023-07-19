a=$(echo "$FT_NBR1" | tr "\'\\\?\!" "0134" | tr '\"' '2')
b=$(echo "$FT_NBR2" | tr "mrdoc" "01234")
echo "obase=13; ibase=5; $a+$b" | bc | tr "0123456789ABC" "gtaio luSnemf"

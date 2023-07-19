cat /etc/passwd | grep -v '#'  | awk "NR%2==0" | cut -f 1 -d ':'| rev | sort -r | awk "NR>=${FT_LINE1} && NR<=${FT_LINE2}" | tr '\n' ',' | sed 's/,/, /g' | sed 's/, $/./' | tr -d '\n'
# grep -v: ''안에 있는 문자열을 포함한 행 제외하고 출력
# awk으로 변수1행부터 변수2행까지 출력하면 될듯	
# sed, cut
# grep

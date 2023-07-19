ifconfig | colrm 1 8  | grep '^[ether]' | colrm 1 6 | colrm 18  #1열부터 8열 삭제
# ifconfig | colrm 1 8  | grep "ether " | colrm 1 6 | colrm 18 결과 동일

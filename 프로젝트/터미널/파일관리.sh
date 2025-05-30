#모든 파일 합치기
cat *.txt > merged.txt

#개행을 추가하면서 모든 파일 합치기
awk 'FNR==1 && NR>1 {print ""} {print}' *.txt > merged.txt

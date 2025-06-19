#!/bin/bash

clear;

# 설정
TARGET_DIR="$HOME/dev"   # 기준 폴더 (예: ~/dev)
THRESHOLD=4              # 최소 표시 비율 (%)
MAXDEPTH=1               # 하위 탐색 깊이

# 경로 유효성 검사
if [ ! -d "$TARGET_DIR" ]; then
  echo "❌ 폴더가 존재하지 않습니다: $TARGET_DIR"
  exit 1
fi

echo
echo "📁 기준 폴더: $TARGET_DIR"

# 기준 폴더 내 전체 파일 수 계산
total_files=$(find "$TARGET_DIR" -type f | wc -l)

echo "📦 총 파일 수: ${total_files}개"
echo "📊 하위 폴더 파일 개수 비율 (깊이 $MAXDEPTH, ${THRESHOLD}% 이상 표시):"
echo

# 하위 폴더별 파일 개수 수집
find "$TARGET_DIR" -mindepth 1 -maxdepth "$MAXDEPTH" -type d | while read -r dir; do
    count=$(find "$dir" -type f | wc -l)
    printf "%d\t%s\n" "$count" "$dir"
done > /tmp/filecount_relative.txt

# 출력 헤더
printf "%-60s %20s\n" "폴더 경로" "파일 수"
echo "------------------------------------------------------------------------------------------"

# 결과 출력
awk -v total="$total_files" -v threshold="$THRESHOLD" '
BEGIN { FS="\t" }
{
    percent = ($1 / total) * 100
    if (percent >= threshold)
        printf "%-60s %8d개 (%.2f%%)\n", $2, $1, percent
}
' /tmp/filecount_relative.txt

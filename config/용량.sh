#!/bin/bash

clear;

# 설정
TARGET_DIR="$HOME/dev"   # 기준 폴더 (예: ~/dev)
THRESHOLD=1              # 최소 표시 비율 (%)
MAXDEPTH=2               # 하위 탐색 깊이

# 경로 유효성 검사
if [ ! -d "$TARGET_DIR" ]; then
  echo "❌ 폴더가 존재하지 않습니다: $TARGET_DIR"
  exit 1
fi

echo
echo "📁 기준 폴더: $TARGET_DIR"

# 기준 폴더 총 용량 (바이트 및 GB)
total_bytes=$(du -s --block-size=1 "$TARGET_DIR" | cut -f1)
total_gb=$(awk -v b="$total_bytes" 'BEGIN { printf "%.2f", b / (1024*1024*1024) }')

echo "📦 총 용량: ${total_gb}GB"
echo "📊 하위 폴더 용량 비율 (깊이 $MAXDEPTH, ${THRESHOLD}% 이상 표시):"
echo

# 하위 폴더 용량 수집
find "$TARGET_DIR" -mindepth 1 -maxdepth "$MAXDEPTH" -type d | while read -r dir; do
    size=$(du -s --block-size=1 "$dir" | cut -f1)
    printf "%d\t%s\n" "$size" "$dir"
done > /tmp/usage_relative.txt

# 출력 헤더
printf "%-60s %20s\n" "폴더 경로" "용량"
echo "------------------------------------------------------------------------------------------"

# 결과 출력
awk -v total="$total_bytes" -v threshold="$THRESHOLD" '
BEGIN { FS="\t" }
{
    gb = $1 / (1024*1024*1024)
    percent = ($1 / total) * 100
    if (percent >= threshold)
        printf "%-60s %8.2fGB (%.2f%%)\n", $2, gb, percent
}
' /tmp/usage_relative.txt
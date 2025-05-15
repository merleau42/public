import csv
import json
import re

def parse_related_forms(related_forms_str):
    items = related_forms_str.split(', ')
    result = []
    for item in items:
        match = re.match(r'(.+?) \((\d+)\)', item)
        if match:
            word, freq = match.groups()
            result.append({
                "form": word,
                "frequency": int(freq)
            })
    return result

# tsv_path = "./원형/_RAW.tsv"
# json_path = "./원형/_RAW.json"

data = []

with open(tsv_path, encoding="utf-8-sig") as f:  # <- BOM 제거
    reader = csv.DictReader(f, delimiter='\t')
    print("헤더 확인:", reader.fieldnames)  # <- 디버깅용

    for row in reader:
        entry = {
            "list": row["List"],
            "headword": row["Headword"],
            "related_forms": parse_related_forms(row["Related forms"]),
            # "total_frequency": int(row["Total frequency"])
        }
        data.append(entry)

with open(json_path, "w", encoding="utf-8") as f:
    json.dump(data, f, ensure_ascii=False, indent=2)

print(f"✅ {len(data)}개 항목이 저장되었습니다 → {json_path}")

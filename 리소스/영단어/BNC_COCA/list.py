import json

최소빈도 = 50
input_path = "_RAW.json"
output_path = f"빈도{최소빈도}+.txt"

with open(input_path, "r", encoding="utf-8") as f:
    data = json.load(f)

with open(output_path, "w", encoding="utf-8") as f:
    for entry in data:
        for form in entry['related_forms']:
            if form["frequency"] >= 최소빈도:
                f.write(f"{form['form']}\n")

print(f"frequency ≥ {최소빈도} 항목만 {output_path} 로 저장되었습니다.")

import json

students = [
    {"name": "Иванов И.И.", "group": "Э-01", "grade": 4.8},
    {"name": "Петров П.П.", "group": "Э-01", "grade": 4.2},
    {"name": "Сидоров С.С.", "group": "М-02", "grade": 4.6}
]

with open("students.json", "w", encoding="utf-8") as f:
    json.dump(students, f, ensure_ascii=False)

with open("students.json", "r", encoding="utf-8") as f:
    data = json.load(f)

best = max(data, key=lambda x: x["grade"])
filtered = [x for x in data if x["grade"] > 4.5]

print("Лучший:", best)

with open("filtered.json", "w", encoding="utf-8") as f:
    json.dump(filtered, f, ensure_ascii=False)

from collections import Counter

text = "мама мыла раму мама"
words = text.lower().split()

counts = Counter(words)
print("Частота слов:", dict(counts))

top_3 = counts.most_common(3)
print("3 самых частых:", top_3)

unique_sorted = sorted(set(words))
print("По алфавиту:", unique_sorted)

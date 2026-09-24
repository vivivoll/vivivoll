# 1

def solve_duplicates(nums):
    unique_elements = set(nums)
    
    count_unique = len(unique_elements)
    
    duplicates = set()
    seen = set()
    for num in nums:
        if num in seen:
            duplicates.add(num)
        else:
            seen.add(num)
            
    return count_unique, list(duplicates)

nums = [3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5]
unique_cnt, dups = solve_duplicates(nums)
print(f"Уникальных: {unique_cnt}")
print(f"Повторяются: {dups}")

# 2
def solve_friends(user1, user2):
    set1 = set(user1)
    set2 = set(user2)
    
    common = set1.intersection(set2)  
    only_first = set1.difference(set2)  
    all_people = set1.union(set2)  
    return common, only_first, all_people

ani = {10, 20, 30, 40}
bori = {30, 40, 50, 60}
print(solve_friends(ani, bori))

# 3
def is_anagram(word1, word2):
    return sorted(word1) == sorted(word2)

print(is_anagram("listen", "silent")) 
print(is_anagram("hello", "world"))   

# 4
m = {"Иванов", "Петров", "Сидоров", "Кузнецов"}
f = {"Петров", "Сидоров", "Смирнов"}
i = {"Сидоров", "Кузнецов", "Смирнов", "Волков"}

all_three = m & f & i  
at_least_one = m | f | i
exactly_two = ((m & f) | (f & i) | (m & i)) - all_three  
only_math = m - f - i  

# 5
p1 = "мама мыла раму".split()
p2 = "папа мыла раму".split()

set1 = set(p1)
set2 = set(p2)

all_words = p1 + p2
unique_words = set(all_words)

seen = set()
duplicates = set()
for w in all_words:
    if w in seen:
        duplicates.add(w)
    else:
        seen.add(w)

only_in_p1 = set1 - set2  

# 6
def analyze_number(n):
    digits_str = str(n)
    unique_digits = set(digits_str)
    
    count_unique = len(unique_digits)
    
    once = [d for d in unique_digits if digits_str.count(d) == 1]
    
    is_pancifrad = len(unique_digits) == 10 and '0' in unique_digits
    
    return count_unique, once, is_pancifrad

print(analyze_number(1122334455))
print(analyze_number(1234567890))

# 7



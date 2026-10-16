import sys

print("ЗАДАЧА 6")
original = [1, 2, 3]
copy1 = original
copy2 = original[:]
original[0] = 99
print("original:", original)
print("copy1:   ", copy1)
print("copy2:   ", copy2)

print()
print()
#################################################
print("ЗАДАЧА 7")
def add_prefix(strings):
    for i in range(len(strings)):
        strings[i] = "ITEM_" + strings[i]

my_list = ["test", "tester", "ttt"]
print("До: ", my_list)
add_prefix(my_list)
print("После: ", my_list)

print()
print()
#################################################
print("ЗАДАЧА 8")

original = [10, 20, 30]
print(f"ID: {id(original)}, Ссылки: {sys.getrefcount(original) - 1}")

link1 = original
print(f"ID: {id(link1)}, Ссылки: {sys.getrefcount(original) - 1}")

del link1
print(f"ID: {id(original)}, Ссылки: {sys.getrefcount(original) - 1}")

def process_data():
    local_list = ["a", "b", "c"]
    print(f"ID: {id(local_list)}, Ссылки: {sys.getrefcount(original) - 1}")
    
process_data()

print()
print()
#################################################
print("ЗАДАЧА 9")


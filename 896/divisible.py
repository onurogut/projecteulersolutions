def is_divisible(arr):
    return all(arr[i] % (i + 1) == 0 for i in range(len(arr)))

def generate_permutations(arr, l, r, perms):
    if l == r:
        if is_divisible(arr):
            perms.append(arr.copy())
    else:
        for i in range(l, r + 1):
            arr[l], arr[i] = arr[i], arr[l]
            generate_permutations(arr, l + 1, r, perms)
            arr[l], arr[i] = arr[i], arr[l]

def find_divisible_range(length, target_index):
    count = 0
    start = 1

    while True:
        current_range = list(range(start, start + length))
        perms = []
        generate_permutations(current_range, 0, length - 1, perms)
        
        if perms:
            count += 1
            if count == target_index:
                return current_range
        
        start += 1

length = 4
target_index = 4
result = find_divisible_range(length, target_index)
print(result)

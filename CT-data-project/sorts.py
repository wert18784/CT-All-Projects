from random import randrange

def quicksort(list, start, end, comparison_function):
    if start >= end:
        return

    p_idx = randrange(start, end + 1)
    p_el = list[p_idx]
    list[end], list[p_idx] = list[p_idx], list[end]
    less_than = start

    for i in range(start, end):
        if comparison_function(list[i], p_el):
            list[i], list[less_than] = list[less_than], list[i]
            less_than += 1
    list[end], list[less_than] = list[less_than], list[end]

    quicksort(list, start, less_than - 1, comparison_function)
    quicksort(list, less_than + 1, end, comparison_function)

def linear_search(data, key1, key2, value1, value2):
    list = []
    for i in data:
        if i[key1] == value1 and i[key2] == value2:
            list.append(i.values())
    if not list:
        print("No results found")
        return
    return list

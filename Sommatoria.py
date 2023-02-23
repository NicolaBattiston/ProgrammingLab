def sum_list(list):
    if(len(list) == 0):
        return None
    
    somma = 0
    for num in list:
        somma += num

    return somma

somma = sum_list([])
print(somma)
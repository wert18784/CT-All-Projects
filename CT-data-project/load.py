import csv

def load_data(filename):
    dataset = []
    with open(filename) as file:
        data = csv.DictReader(file)
        for i in data:
            i['first_name_lower'] = i['first_name'].lower()
            i['last_name_lower'] = i['last_name'].lower()
            dataset.append(i)
    return dataset
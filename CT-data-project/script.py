import sorts
import load

data = load.load_data('data.csv')
data_2 = data.copy()
data_3 = data.copy()
data_4 = data.copy()

#comparison functions
def age_sort(a, b):
    return a['age'] > b['age']

def salary_sort(a, b):
    return a['salary'] > b['salary']

def alphabet_sort_by_state(a, b):
    return a['state'] > b['state']

#EXPORTING ALHPABETICAL ORDER BY STATE IN OUT.txt
sorts.quicksort(data_3, 0, len(data_2)-1, alphabet_sort_by_state)
with open('out.txt', 'w') as f:
    string = ""
    for i in data_3:
        for x in i.values():
            string += str(x) + ','
        string += '\n'
    f.write(string)
print("alphabetical order by state saved in out.txt\n")

#FINDING THE YOUNGEST MANAGERS
sorts.quicksort(data_2, 0, len(data_2)-1, age_sort)
#print(data_2)
lowest_ages = [str(i.values()) for i in reversed(data_2) if i['position'] == 'Manager'][0:5]
print("DATA FOR THE 5 YOUNGEST MANAGERS:")
for i in lowest_ages:
    print('\t'+ str(i))

#SEARCHING FOR JACK AGE 52
print("\n\nFINDING DATA FOR JACK: ")
print('\t' + str(sorts.linear_search(data, 'last_name', 'age', 'Jack', '52')) + "\n\n")

#COMPARING AVERAGE SALARIES
print("EDUCATION VS AVERAGE SALARY:")
Master_lst = [int(i['salary']) for i in data if i['education'] == 'Master']
Bachlor_list = [int(i['salary']) for i in data if i['education'] == 'Bachelor']
Master_average = sum(Master_lst) / len(Master_lst)
Bachlor_average = sum(Bachlor_list) / len(Bachlor_list)
print("\t The MASTER AVERAGE:  {} \n\t The BACHLOR AVERAGE: {}".format(Master_average, Bachlor_average))

input("Press Any Key to Close")

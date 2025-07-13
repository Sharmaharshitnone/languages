ages = { 
    "Harshit":10,
    'Ansh': 5
}

print(ages["Ansh"])

new_dict = {} 


# NOTE: To create an ordered dictionary i can use 
from collections import OrderedDict

ages = OrderedDict()

ages["Akanksha"] = 12
ages["Susan"] = 10
ages["Marks"] = 4

for key, value in ages.items():
    print(key, value)

# NOTE: We can loop through the nested dictionary using a nested loop 

students = {
    "Peter": {"age": 10, "address": "Lisbon"},
    "Isabel": {"age": 11, "address": "Sesimbra"},
    "Anna": {"age": 9, "address": "Lisbon"},
}

for p_id, p_info in students.items():
    print("\nPerson Name:", p_id)
    for key in p_info:
        print(key + ':', p_info[key])


def calculateAverageAge(students):
    add_age = 0 
    for info in students.values():
        age = info['age']
        add_age = add_age + age

    return (add_age /len(students.keys()))

def find_students(students, address):
    names = []
    for key,value in students.items():
        if value['address'] == address:
            names.append(key)
    return sorted(names)

   

from sys import argv, exit
import csv

if len(argv) != 3:
    print("Usage: python dna.py data.csv sequence.txt")
    exit(1)

csv_name = argv[1]
txt_name = argv[2]
data = {}

with open(csv_name) as file:
    reader = csv.DictReader(file)
    dna_parts = reader.fieldnames
dna_parts.pop(0)

f = open(txt_name)
dna = f.read()

for part in dna_parts:
    data[part] = 0

for key in dna_parts:
    len_of_key = len(key)
    temp = 0
    i = 0

    while i < (len(dna) - len_of_key):
        while dna[i:i + len_of_key] == key and i < (len(dna) - len_of_key):
            temp += 1
            i += len_of_key

        if data[key] < temp:
            data[key] = temp

        temp = 0
        i +=1

with open(csv_name) as file:
    reader = csv.DictReader(file)
    for person in reader:
        match = 0
        for part in data:
            if data[part] == int(person[part]):
                match += 1
        if match == len(data):
            print(person['name'])
            exit()

    print("No match")
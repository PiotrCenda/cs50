from sys import argv, exit
import csv
from cs50 import SQL

if (len(argv) != 2):
    print("Usage: python roster.py data.csv")
    exit(1)

house_name = argv[1]

db = SQL("sqlite:///students.db")

students = db.execute("SELECT * FROM students WHERE house = ? ORDER BY last, first", house_name)

for i in students:
    first_name = i["first"]
    middle_name = i["middle"]
    last_name = i["last"]
    year = str(i["birth"])

    if (middle_name == None):
        print(first_name, last_name + ", born " + year)

    else:
        print(first_name, middle_name, last_name + ", born " + year)

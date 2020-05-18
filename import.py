from sys import argv, exit
import csv
from cs50 import SQL

if len(argv) != 2:
    print("Usage: python import.py data.csv")
    exit(1)

csv_name = argv[1]

db = SQL("sqlite:///students.db")

with open(csv_name, "r") as file:
    reader = csv.DictReader(file)

    for row in reader:
        year = int(row["birth"])
        full_name = row["name"].split()
        house = row["house"]

        if (len(full_name) == 3):
            first_name = full_name[0]
            middle_name = full_name[1]
            last_name = full_name[2]
            db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES (?, ?, ?, ?, ?)",
                       first_name, middle_name, last_name, house, year)

        else:
            first_name = full_name[0]
            middle_name = None
            last_name = full_name[1]
            db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES (?, ?, ?, ?, ?)",
                       first_name, middle_name, last_name, house, year)


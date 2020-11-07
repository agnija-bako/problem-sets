from sys import argv
from cs50 import SQL
import csv

# Task: Implement a solution that imports student data into a database, and then produce class rosters

# SOLUTION

# Only one command line argument is accepted
if len(argv) != 2:
    print("Error")
    exit()

# Define db
db = SQL("sqlite:///students.db")


# Open csv file
characters = open(argv[1], newline='')
reader = csv.reader(characters)

# Find labels in the file (first element of the file)
row1 = next(reader)

# Parse file and insert all values on the db
for row in reader:
    for j in range(len(row1)):
        # parse name
        if j == 0:
            separated_name = row[j].split()
            first = separated_name[0]

            # Check if middle name exists
            if len(separated_name) == 3:
                middle = separated_name[1]
                last = separated_name[2]

            else:
                middle = None
                last = separated_name[1]

        elif j == 1:
            house = row[j]
        elif j == 2:
            birth = row[j]

    # Insert each row into db
    db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES (?, ?, ?, ?, ?);", first, middle, last, house, birth)
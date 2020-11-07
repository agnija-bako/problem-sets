from sys import argv
from cs50 import SQL

# Produce class rosters

# SOLUTION

# Check if correct number of arguments is provided
if len(argv) != 2:
    print("Error")
    exit()


# Define db
db = SQL("sqlite:///students.db")

# query student list from the database where the house equals the house provided in the command line
students_list = db.execute(
    "SELECT first, middle, last, birth FROM students WHERE house = :house ORDER BY last ASC, first ASC;", house=argv[1])

# print the result of the given house
for row in students_list:
    if row["middle"] != None:
        name = row["first"] + " " + row["middle"] + " " + row["last"]
    else:
        name = row["first"] + " " + row["last"]

    birth = "born" + " " + str(row["birth"])

    print(name + ", " + birth)
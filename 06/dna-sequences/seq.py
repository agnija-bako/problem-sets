from sys import argv
import csv

# Implement a solution that finds a person based on their DNA using the STRs provided

# SOLUTION

# Print an error if an incorect number of command line arguments are executed
if(len(argv) != 3):
    print("Error")

DNA = {}

# Open the CSV file and read its' contents into memory
csvfile = open(argv[1], newline='')
reader = csv.reader(csvfile)
row1 = next(reader)


# Open sequence file and read its' contents into memory
f = open(argv[2], "r")
reader_text = f.read()

# Identify a person based on their DNA


def main():
    findsequence(row1, reader_text)
    findmatch(reader, row1)

# Find DNA sequnces and save them to the DNA dictionary


def findsequence(row, file):
    # Find the STRs to look for in the provided db file
    for i in range(len(row)-1):
        STR = row[i+1]
        end = len(STR)
        highest = 0
        count = 0
        # Loop through the file and find any sequences matching with provided STRs
        for j in range(len(file)):
            # Move one character at a time in the lenght of the provided STR to find matches
            placeholder = file[j:end]
            # When a match found, check if the previous STR matches the current one
            if placeholder == STR:
                prev_start = j - len(STR)
                prev_end = end - len(STR)
                if file[prev_start:prev_end] == STR:
                    count = count + 1
                    # If sequence count is higher than recorded "highest" change highest value to count
                    if count > highest:
                        highest = count
                # If previous sequence doesn't match with current, start counting from beginning
                else:
                    count = 1
                    # If highest has not been recorded so far for this sequence set it to count
                    if highest < count:
                        highest = count
            end = end + 1
        # Record highest value of the matching STR in the DNA dict
        DNA[STR] = highest


# Find a DNA match in the provided db file


def findmatch(file, row):
    # Match is by default "No match"
    match = "No match"
    # Loop through the db file, one person at a time
    for i in file:
        # Loop through the lenght of all possible STRs to compare their values
        for j in range(len(row)-1):
            STR = row[j+1]
            db = int(i[j+1])
            # Check if the db value of an STR matches the same value of that STR in the DNA dictionary, if yes - record the person's name as a match
            if db == DNA[STR]:
                match = i[0]
            else:
                # If for the given person that has already had a match we find a "No match", set match back to "No match" and break the loop
                if match == i[0]:
                    match = "No match"
                break
        # If we found a person who's all STRs match, no need to continue searching, break the loop
        if match == i[0]:
            break
    print(match)


main()


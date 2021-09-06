import sys
import csv

if len(sys.argv) != 2:
    print("invalid ammount of command-line arguments for dna.py")
    sys.exit(1)

file_db = open(argv[0], "r")
reader_db = csv.reader(file_db)
next(reader_db)

STRs = []


file_seq = open(argv[1], "r")
file_seq.read()

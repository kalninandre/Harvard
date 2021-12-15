import sys
import csv


def main():

    # Proper usage of the program
    if len(sys.argv) != 3:
        print('Usage: python dna.py data.csv sequence.txt')
        sys.exit(1)

    persons = {}

    # Gets the persons dictionary
    with open(sys.argv[1], 'r') as file:
        reader = csv.reader(file)

        # Gets the STRS list
        STRS = next(reader)[1:]

        for row in reader:
            persons[row[0]] = row[1:]

    # Gets the text sample
    with open(sys.argv[2], 'r') as file:
        reader = csv.reader(file)
        for row in reader:
            sequence = row[0]

    temporary = {i: 0 for i in STRS}

    for STR in STRS:
        i = 0
        counter = 0
        maximum = []

        while (i + len(min(STRS))) < len(sequence):
            sample = sequence[i:i + len(STR)]
            if sample == STR:
                counter += 1
                i += len(STR)
            else:
                maximum.append(counter)
                counter = 0
                i += 1
        temporary[STR] += max(maximum)

    # Transform the dictionary into a list
    temporary = list(temporary.values())
    temporary = [str(i) for i in temporary]

    match = 0
    for name in persons:
        if persons[name] == temporary:
            match = 1
            print('{}'.format(name))
            break

    if match == 0:
        print('No match')


if __name__ == '__main__':
    main()
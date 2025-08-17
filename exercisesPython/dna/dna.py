import csv
import sys


def main():

    # TODO: Check for command-line usage
    args = sys.argv
    
    if len(args) != 3:
        print("Usage: python dna.py data.csv sequence.txt")         #check input format
    
    if ".csv" in args[1] :
        fcsv = open(args[1],"r")                                    #check data.csv format
    else:
        print("Invalid csv File. Argument 1")
    
    if ".txt" in args[2] :
        ftxt = open(args[2],"r")                                    #check sequence.txt format
    else:
        print("Invalid txt File. Argument 2")

    # TODO: Read database file into a variable
    
    databaseDict = {}
    csv_reader = csv.reader(fcsv, delimiter=",")
    
    firstRow = False
    strNames = []
    for row in csv_reader :
        if(firstRow == False) :
            strNames = list(name for name in row[1:])           # create a list with each name of STR in csv file
            firstRow = True
            
        key = tuple(value for value in row[1:])                 #set a tuple as key with each value for each person. for each value in row, starting after first row(row[0] = name)
        databaseDict[key] = row[0]                              # add in dictionary the person, on key of STR values
        
    # TODO: Read DNA sequence file into a variable
    
    dna = ftxt.read()
    
    # TODO: Find longest match of each STR in DNA sequence     
    
    results = []       
    for name in strNames :                                      # search longestMatch for each STR name(string)
        results.append(longestMatch(name,dna))                  # and append into results
        
    
    # TODO: Check database for matching profiles
    
    key = tuple(str(STRs) for STRs in results)                      # get a tuple as key to use in dict and found (or not) the match
                                                                    #   was necessary to convert in string bcs dictionary only accept str as key value                                       
    
    if key in databaseDict :
        matchPerson = databaseDict[key]
    else:                                                           # if found set person name on databaseDict as matchPerson
        matchPerson = "No Match"                                    # else set "not found" to matchperson
    
    # print(databaseDict)
    # print(strNames)
    # print(results)                                                # just to debug
    # print(key)   (in theory will be equal to results, but as a tuple, instead of a list)
    # print(matchPerson)
    
    
    print(matchPerson)
    

    return

def longestMatch(Str,dna):
    strSize = len(Str)                                      # get len from STR type to atribute to "string" in line 62
    counter = 0                                             # (the purpose for this is to make a general function, to fit in each STR type)
    
    for i in range(len(dna)) :
        if i+strSize < len(dna):                            # check if checking substring exceed dna size
            
            string = ""
            for x in range(strSize) : string += dna[i+x]    # get the substring sizeof(Str param) in index "i" in dna
            
            if string == Str :

                tmp = sequence(Str, dna, i)                 # call sequence vector, where will get the sequence of same STR (or return 1 if is only 1)
                if(tmp > counter) :
                    counter = tmp                           # if actual sequence is bigger than previous, add to counter
    
    return counter                                          # return biggest sequence

def sequence(Str, dna, index):
    strSize = len(Str)
    
    string = ""
    if(index + strSize) > len(dna) : return 0
    for x in range(strSize) : string += dna[index + x]      # actual string (with STR size) in dna, starting in index
    
    if string == Str :
        return 1 + sequence(Str,dna,(index + strSize))      
    else:                                                   # recursive calling while next substring was == STR
        return 0
    
            
def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()

# Programme translates inputted code into basic coding

import json

string = input('Input a code: ')

dictionary = {}

for key in range (len(string)) :
    dictionary[string[key]] = 1

codeLength = 0
while 2**codeLength < len(dictionary) :
    codeLength += 1

i = 0
for key in dictionary.keys():
    dictionary[key] = ('0')*(codeLength-len(bin(i))+2) + bin(i)[2:]
    i += 1

print (json.dumps(dictionary, indent=4))

for i in range(len(string)) :
    print (dictionary[string[i]], end="")

print()

# Programme translates inputted string into Huffman Code

import operator
import json

string = input('Input a string: ')

dictionary = {}

for key in range (len(string)) :
    if string[key] in dictionary :
        dictionary[string[key]] += 1
    else :
        dictionary[string[key]] = 1

dictionary = dict(sorted(dictionary.items(), key=operator.itemgetter(1), reverse=True))

i = 0
for key in dictionary :
    if i+1 == len(dictionary) :
        dictionary[key] = i*'1'
    else :
        dictionary[key] = i*'1' + '0'
    i += 1

print (json.dumps(dictionary, indent=4))

for i in range(len(string)) :
    print (dictionary[string[i]], end="")

print()

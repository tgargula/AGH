# Programme translates inputted string into Huffman Code

import operator

string = input('Input a string: ')

table = {}

for key in range (len(string)) :
    if string[key] in table :
        table[string[key]] += 1
    else :
        table[string[key]] = 1

table = dict(sorted(table.items(), key=operator.itemgetter(1), reverse=True))

i = 0
for key in table :
    if i+1 == len(table) :
        table[key] = i*'1'
    else :
        table[key] = i*'1' + '0'
    i += 1

print (table)

for i in range(len(string)) :
    print (table[string[i]], end="")

print()

# Programme translates inputted code into basic coding

string = input('Input a code: ')

table = {}

for key in range (len(string)) :
    table[string[key]] = 1

codeLength = 0
while 2**codeLength < len(table) :
    codeLength += 1

i = 0
for key in table.keys():
    table[key] = ('0')*(codeLength-len(bin(i))+2) + bin(i)[2:]
    i += 1

print (table)

for i in range(len(string)) :
    print (table[string[i]], end="")

print()

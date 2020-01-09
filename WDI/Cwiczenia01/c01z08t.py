from math import sqrt

def Prime(n):
	if n < 2 : return False
	if n == 2 or n == 3 : return True
	if n % 2 == 0 or n % 3 == 0 : return False
	i = 5
	while i <= math.sqrt(n) :
		if n % i == 0 : return False
		if n+2 % i == 0 : return False
		i += 6
	return True

a = input('Input a number: ')
print('YES' if Prime(int(a)) else 'NO')

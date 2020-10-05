#!/usr/bin/python2

a = int(input('Enter a number: '))
b = int(input('Enter another number: '))

c = input('Enter an operator (+, -, *, /): ')

if (c == '+'):
    print('Sum is: ' + (a + b))
elif (c == '-'):
    print('Difference is: ' + (a - b))
elif (c == '*'):
    print('Product is: ' + (a * b))
elif (c == '/'):
    print('Quotient is: ' + (a / b))
else:
    print('Operator invalid!')

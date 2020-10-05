#!/usr/bin/python2

a = int(input('Enter a number: '))
b = int(input('Enter another number: '))

c = raw_input('Enter an operator (+, -, *, /): ')

if (c == '+'):
    print('Sum is: ' + str(a + b))
elif (c == '-'):
    print('Difference is: ' + str(a - b))
elif (c == '*'):
    print('Product is: ' + str(a * b))
elif (c == '/'):
    print('Quotient is: ' + str(a / b))
else:
    print('Operator invalid!')

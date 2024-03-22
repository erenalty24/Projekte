def calculator():
    num1 = int(input("Enter the first number: "))
    num2 = int(input("Enter the second number: "))
    operator = input("Choose an operator (+, -, *, /): ")

    if operator =='+':
        result = num1 + num2
    elif operator =='-':
        result = num1 - num2
    elif operator == '*':
        result = num1 * num2
    elif operator =='/':
        result = num1 / num2
    else: 
        print("Siktir git!!!")
        return
    
    print("The Result is: ", result)

calculator()



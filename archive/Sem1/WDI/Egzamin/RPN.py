import json

class ReversePolishNotation:
    def __init__(self, equation):
        self.equation = equation
        self.priority = {
            "(": 0,
            "+": 1,
            "-": 1,
            ")": 1,
            "*": 2,
            "/": 2,
            "%": 2,
            "^": 3 
        }        

    def assertIn(self, key, dictionary):
        for i in dictionary:
            if i == key:
                return True
        return False

    def conversion(self):
        result = ""
        stack = ""
        x = ""
        print(self.equation)

        for i in self.equation:
            print(i)
            if ord(i) <= 57 and ord(i) >= 48:
                x += i

            elif ord(i) < 123 and ord(i) > 96:
                result += f"{i} "

            elif self.assertIn(i, self.priority):
                if x != "":
                    result += f"{x} "
                    x = ""
                    
                if i == "(":
                    stack += i
                elif i == ")":
                    while stack[-1:] != "(":
                        result += f"{stack[-1:]} "
                        stack = stack[:-1]
                    stack = stack[:-1]

                elif stack == "" or self.priority[stack[-1:]] < self.priority[i]:
                    stack += i
                    # print("1warunek", i)
                else:
                    # print("2warunek",  i)
                    while self.priority[stack[-1:]] >= self.priority[i]:
                        result += f"{stack[-1:]} "
                        stack = stack[:-1]

                    stack += i

            print("stack: ", stack)
            print("result: ", result)

        if x != "":
            result += f"{x} "
            x = ""
        while stack != "":
            result += f"{stack[-1:]} "
            stack = stack[:-1]

        return result

        
equa = ReversePolishNotation(input("Input equation: "))
# eq = "3+4*2/(1-5)^2"
# equa = ReversePolishNotation(eq)
rpn = equa.conversion()
print(rpn)
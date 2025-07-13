# NOTE: Classes OOP , a class is a structure that allows you to group together set of properties and methods (funcitons) that are related to a specific object.

class Person:
    def __init__(self, name, age):# class constructor, it is called when an object of the class is created
        self.name = name
        self.age = age

    def greet(self):
        print("Hello ,my name is %s!" % self.name)

a = Person("Alice", 30)  # create an object of the class Person
b = Person("Bob", 25)      # create another object of the class Person
b.greet()
a.greet()

#NOTE: The __init__ method is a special method that is called when an object of the class is created. It initializes the object's properties.

class Rectangle:
    def __init__(self, x1, y1, x2, y2):
        if(x1 < x2 and y1 > y2):
            self.x1 = x1
            self.y1 = y1
            self.x2 = x2
            self.y2 = y2
        else:
            print("Invalid coordinates for rectangle")
    def width(self):
        return self.x2 - self.x1
    def height(self):
        return self.y1 - self.y2
    def area(self):
        return self.width() * self.height()
    def perimeter(self):
        return 2 * (self.width() + self.height())

    def __str__(self):
        return "Rectangle: (x1: %d, y1: %d, x2: %d, y2: %d)" % (self.x1, self.y1, self.x2, self.y2)

    # NOTE: using __repr__ method to return a string representation of the object
    def __repr__(self):
         return(str(self.x1) + ', ' + str(self.y1) + ', ' + str(self.x2) + ', '+str(self.y2))
  
# test your code
r = Rectangle (2, 7, 8, 4)
print (r)


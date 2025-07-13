#NOTE: Super Method

"""Super is used to return a proxy object that delegates method calls to a parent or sibling class of type. This is useful for accessing inherited methods that have been overridden in a class.


class Person(object): # Super class
  def __init__(self, name):
    self.name = name
  def greet(self):
    print ("Hi, I'm " + self.name + ".") # Super class does something

class Student(Person): # Subclass inheriting from the super class
  def __init__(self, name, degree):
    self.name = name
    self.degree = degree
    Person.__init__(self, name) # calls constructor of super class
  def greet(self):
    Person.greet(self) # calls method of super class
    print ("I am a " + self.degree + " student.")
  
student = Student("Ali", "PhD") # Create an object of the subclass
student.greet()
"""

class Person(object): # Super class
  def __init__(self, name):
    self.name = name
  def greet(self):
    print ("Hi, I'm " + self.name + ".") # Super class does something

class Student(Person): # Subclass inheriting from the super class
  def __init__(self, name, degree):
    self.name = name
    self.degree = degree
    super().__init__(name) # calls constructor of super class
  def greet(self):
    super().greet() # calls method of super class
    print ("I am a " + self.degree + " student.")
  
student = Student("Ali", "PhD") # Create an object of the subclass
student.greet()

# NOTE: This Shows that WE can create Hierarchical classes in Python, where a class can inherit
class Animal():
    def __init__(self, name, food, characteristic):
        self.name = name
        self.characteristic = characteristic
        self.food = food
        print("I am a " + str(self.name) + ".")

class Mammal(Animal):
    def __init__(self, name, food):
        Animal.__init__(self, name, food, "warm-blooded")
        print("I am warm blooded.")

dog = Mammal("Dog", "Meat")



#NOTE: The sublcass can not oly acess the methods of its parents but also can override them.


#NOTE: MULTIPLE INHERITANCE, A class can inherit from multiple classes. 


class Person:
    def __init__(self, name):
        self.name = name

    def greet(self):
        print("Hi, I am "+ self.name + ".")

class Studnet(Person):
    def __init__(self, name, rollNumber):
        self.name = name
        self.rollNumber = rollNumber
        Person.__init__(self, name)

        def report(self):
            print("I am a student with roll number " + str(self.rollNumber) + ".")

class Teacher(Person):
    def __init__(self, name, subject):
        self.name = name
        self.subject = subject
        Person.__init__(self, name)

    def Introduce(self):
        print("I am a teacher of " + self.subject + ".")

class TeachingAssistant(Studnet, Teacher):
    def __init__(self, name, rollNumber, subject):
        self.name = name
        self.rollNumber = rollNumber
        self.subject = subject

        Studnet.__init__(self, name, rollNumber)
        Teacher.__init__(self, name, subject)

    def report(self):
        Studnet.report(self)
        Teacher.report(self)

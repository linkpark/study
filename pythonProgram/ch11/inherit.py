# !/usr/bin/pyton
#Filename: inherit.py

class SchollMember:
	'''Represents any school member.'''
	def __init__(self,name,age):
		self.name = name;
		self.age = age;
		print '(Initialized SchoolMember:%s)' % self.name;
	
	def tell(self):
		'''Tell my details.'''
		print 'Name:"%s" Age:"%s"' % (self.name,self.age);
	
class Teacher(SchollMember):
	'''Represents a teacher.'''
	def __init__(self,name,age,salary):
		SchollMember.__init__(self,name,age);
		self.salary = salary;
		print '(Initialized Teacher: %s)' % self.name;
	
	def tell(self):
		SchoolMemberl.tell(self);
		print 'Salary:"%d"' % self.salary;
	
class Student(SchollMember):
	'''Represents a students.'''
	def __init__(self,name,age,marks):
		SchoolMemberl.__init__(self,name,age);
		self.marks = marks;
		print '(Initialized Student: %s)' % self.name;

	def tell(self):
		SchoolMemberl.tell(self);
		print 'Marks: "%d"' % self.marks;
	
t = Teacher('Mrs. Shrividya', 40 , 3000);
s = Student('Swaroop',22,75);

members = [t,s];
for member in members:
	member.tell();



	

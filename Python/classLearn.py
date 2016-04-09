class table(object):
     height = 0
     weight = 0
     def __init__(self):
             self.height = 1
             self.weigth = 1
     def return_hw(self, weigth):
             return [self.height, self.weight]
t1 = table()
print t1.return_hw()


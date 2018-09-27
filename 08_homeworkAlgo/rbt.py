import os
import sys

#enum function to give RED = 0 and BLACK = 1
Color = ("RED", "BLACK")

class Node:
    data = None
    parent = None
    color = None
    left = None
    right = None
    #node constructor
    #none allows for method overloading meaning that a right and left do not needto be inputed
    def __init__(self, data, parent = None, color=1, left = None, right = None):
        self.data = data
        self.parent = parent
        self.color = color
        self.left = left
        self.right = right

class RedBlackTree:
    #main red black tree class conatining all necessary functions to hold the propeties of a RedBlackTree
    __root = None
    NIL_Sentinel = Node(data=None, color=1) #created a NIL Sentinel that is black

    def __init__(self, __root = None):
        self.__root = Node(data= None, parent=None, color= 1, left = self.NIL_Sentinel, right = self.NIL_Sentinel)

    def _rotateLeft(self, x):
        y = x.right
        x.right = y.left
        if(y.left != self.NIL_Sentinel):
            y.left.parent = x
        y.parent = x.parent
        if(x.parent == self.NIL_Sentinel):
            self.__root = y
        elif(x == x.parent.left):
            x.parent.left = y
        else:
            x.parent.right = y
        y.left = x
        x.parent = y

    def _rotateRight(self, x):
        y = x.left
        x.left = y.right
        if (y.right != self.NIL_Sentinel):
            y.right.parent = x
        y.parent = x.parent
        if (x.parent == self.NIL_Sentinel):
            self.__root = y
        elif (x == x.parent.right):
            x.parent.left = y
        else:
            x.parent.left = y
        y.right = x
        x.parent = y

    def insert(self, a):
        z = Node(0, a)
        y = self.NIL_Sentinel
        x = self.__root
        while (x.data != None):
            y = x
            if (z.data < x.data):
                x = x.left
            else:
                x = x.right
        z.parent = y
        if (y.data == None):
            self.__root = z
        elif (z.data < y.data):
            y.left = z
        else:
            y.right = z
        z.left = self.NIL_Sentinel
        z.right = self.NIL_Sentinel
        z.color = self.NIL_Sentinel
        self.RB_Insert_Fixup (z)

    def RB_Insert_Fixup (self, z):
        while (z.parent.color == 0):
            if (z.parent == z.parent.parent.left):
                y = z.parent.parent.right
                if (y.color == 0):
                    z.parent.color = 1
                    y.color = 1
                    z.parent.parent.color = 0
                    z = z.parent.parent
                elif (z == z.parent.right):
                    z = z.parent
                    _rotateLeft(self, z)
                    z.parent.color = 1
                    z.parent.parent.color = 0
                    _rotateRight(self, z.parent.parent)
                else:
                    y = z.parent.parent.left
                    if (y.color == 0):
                        z.parent.color = 1
                        y.color = 1
                        z.parent.parent.color = 0
                        z = z.parent.parent
                    elif (z == z.parent.left):
                        z = z.parent
                        _rotateRight(self, z)
                        z.parent.color = 1
                        z.parent.parent.color = 0
                        _rotateLeft(self, z.parent.parent)
        self.__root.color = 1

    def deleteNode(self, z):
        y = z
        y_original_color = y.color
        if (z.left is self.NIL_Sentinel):
            x = z.right
            RB_transplant(self, y, y.right)
        else:
            y = TreeMinimum(z.right)
            x = y.right
            if (y.parent == z):
                x.parent = y
            else:
                RB_transplant(self, y, y.right)
                y.right = z.right
                y.right.parent = y
            RB_transplant(self, z, y)
            y.left = z.left
            y.left.parent = y
            y.color = z.color
        if (y_original_color == 1):
            RB_Delete_Fixup(self, x)

    def RB_Delete_Fixup(self, x):
        if (x == x.parent.right):
            w = x.parent.right
            if (w.color == 0):
                w.color = 1
                x.parent.color = 0
                _rotateLeft(self, x.parent)
                w = x.parent.right
            if (w.left.color == 1 and w.right.color == 1):
                w.color = 0
                x = x.parent
            elif (w.right.color == 1):
                w.left.color = 1
                w.color = 0
                _rotateRight(self, w)
                w = x.parent.color
            w.color = x.parent.color
            x.parent.color = 1
            w.right.color = 1
            _rotateLeft (self, x.parent)
            x=self.__root
        else:
            w = x.parent.left
            if (w.color == 0):
                w.color = 1
                x.parent.color = 0
                _rotateLeft(self, x.parent)
                w = x.parent.left
            if (w.right.color == 1 and w.left.color == 1):
                w.color = 0
                x = x.parent
            elif (w.left.color == 1):
                w.right.color = 1
                w.color = 0
                _rotateRight(self, w)
                w = x.parent.color
            w.color = x.parent.color
            x.parent.color = 1
            w.left.color = 1
            _rotateLeft (self, x.parent)
            x=self.__root
        x.color = 1

    def RB_transplant(self, u, v):
        if (u.parent is self.NIL_Sentinel):
            self.root = v
        elif (u == u.parent.left):
            u.parent.left = v
        else:
            u.parent.right = v
            v.parent = u.parent

    def TreeMinimum(x):
        current = x
        while(current.left is not self.NIL_Sentinel):
            current = current.left
        return current.data

    def getMinimum(self):
        x = self.__root
        while (x.left.data is not None):
            x = x.left
        return x.data

    def getMaximum(self):
        x = self.__root
        while (x.right.data is not None):
            x = x.right
        return x.data

    def predecessor(self, key):
        temp = self.root
        prev = None
        if (temp.left is not self.NIL_Sentinel):
            temp  = temp.left
            while (temp.right is not self.NIL_Sentinel):
                temp = temp.right
            prev = temp
        elif (temp.right is not self.NIL_Sentinel):
            temp = temp.right
            while (temp.left is not self.NIL_Sentinel):
                temp = temp.left
            prev = temp
        else:
            return None
        return prev.data

    def successor(self, key):
        temp = self.root
        prev = None
        if (temp.right is not self.NIL_Sentinel):
            temp  = temp.right
            while (temp.left is not self.NIL_Sentinel):
                temp = temp.left
            prev = temp
        elif temp.left is not self.NIL_Sentinel:
            temp = temp.left
            while (temp.right is not self.NIL_Sentinel):
                temp = temp.right
            prev = temp
        else:
            return None
        return prev.data


    def search(self,key):
        x = self.__root
        if (x.data == key):
            return x
        elif x.data < key:
            return search(x.right,key)
        return search(x.left,key)
    def inorder (self, x = None):
        if (x is None):
            x = self.__root
        x = self.getMinimum
        while x:
            yield x.data
            x = self.successor(x)

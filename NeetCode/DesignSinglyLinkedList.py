"""
Design a Singly Linked List class.

Your LinkedList class should support the following operations:

LinkedList() will initialize an empty linked list.
int get(int i) will return the value of the ith node (0-indexed). If the index is out of bounds, return -1.
void insertHead(int val) will insert a node with val at the head of the list.
void insertTail(int val) will insert a node with val at the tail of the list.
bool remove(int i) will remove the ith node (0-indexed). If the index is out of bounds, return false, otherwise return true.
int[] getValues() return an array of all the values in the linked list, ordered from head to tail.

Example 1:
    Input: 
    ["insertHead", 1, "insertTail", 2, "insertHead", 0, "remove", 1, "getValues"]
    Output:
    [null, null, null, true, [0, 2]]

Example 2:
    Input:
    ["insertHead", 1, "insertHead", 2, "get", 5]
    Output:
    [null, null, -1]

Note:
    The index int i provided to get(int i) and remove(int i) is guaranteed to be greater than or equal to 0.
"""
class Node:
    def __init__(self, data, next_node=None):
        self.data = data
        self.next_node = next_node

class LinkedList:
    
    def __init__(self):
        self.head = Node(-1)
        self.tail = self.head 
    
    def get(self, index: int) -> int:
        temp = self.head.next_node
        i = 0
        while temp:
            if i == index:
                return temp.data
            i += 1
            temp = temp.next_node
        return -1

    def insertHead(self, val: int) -> None:
        new_node = Node(val)
        new_node.next_node = self.head.next_node
        self.head.next_node = new_node
        if not new_node.next_node:
            self.tail = new_node

    def insertTail(self, val: int) -> None:
        self.tail.next_node = Node(val)
        self.tail = self.tail.next_node

    def remove(self, index: int) -> bool:
        i = 0
        temp = self.head
        while i < index and temp:
            i += 1
            temp = temp.next_node

        if temp and temp.next_node:
            if temp.next_node == self.tail:
                self.tail = temp
            temp.next_node = temp.next_node.next_node
            return True
        return False

    def getValues(self) -> List[int]:
        temp = self.head.next_node
        result = []
        while temp:
            result.append(temp.data)
            temp = temp.next_node
        return result

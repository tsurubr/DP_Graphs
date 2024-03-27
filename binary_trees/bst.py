class node:
    def __init__(self, info):
        self.left = None
        self.right = None
        self.info = info
    
    def insert(self, info):
        if info < self.info:
            if self.left:
                self.left.insert(info)
            else:
                self.left = node(info)
                return
        else:
            if self.right:
                self.right.insert(info)
            else:
                self.right = node(info)
                return

    def print_tree(self, d = 0):
        if(self):
            for i in range(d):
                print(" ", end="")
            print(self.info)
            node.print_tree(self.left, d+2)
            node.print_tree(self.right, d+2)
        else:
            return

    def search(self, key):
        if(not self):
            return
        if(key == self.info):
            return True
        if(key < self.info):
            return node.search(self.left, key)
        else:
            return node.search(self.right, key)


def main():
    root = node(20)
    root.insert(15)
    root.insert(24)
    root.insert(17)
    root.insert(22)
    root.insert(12)
    root.insert(26)
    root.insert(10)
    node.print_tree(root)
    n = int(input("Node:"))
    if(node.search(root, n)):
        print("It exists")
    else:
        print("It don't exists")
main()

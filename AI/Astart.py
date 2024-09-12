'''
Dùng thuật toán A* để giải quyết bài toán tìm đường đi trong mê cung
Heuristic được sử dụng là Diagonal/Chebyshev Heuristic:http://www.sfu.ca/~arashr/warren.pdf
Heuristic này tỏ ra hiệu quả khi di chuyển được cả 8 hướng
Tham khảo search02.py của thầy
'''

import pyamaze
from pyamaze import *
import time


class Node:
    '''
    Gồm các thông tin:
    position: vị trí của node hiện tại trong Maze
    Parent: Node cha của node hiện tại
    f: chi phí ước lượng từ node start đến node goal khi qua node hiện tại
    g: chi phí từ node start đến node hiện tại
    h: chi phí ước ược lượng node hiện tại đến goal
    '''

    def __init__(self, position, parent=None, g=0, h=0, f=0):
        self.position = position
        self.parent = parent
        self.g = g
        self.h = h
        self.f = f

    def __eq__(self, other):
        # Kiểm tra xem hai node có bằng nhau hay không
        return self.position == other.position

    def ChildExpand(self, maze):
        '''
        Hàm tạo danh sách các child được mở rộng từ node hiện tại
        '''
        children = []
        # Các hướng node có thể di chuyển - 4 hướng
        actions = [(0, -1), (-1, 0), (1, 0), (0, 1)]
        direc = {(0, -1): 'W', (-1, 0): 'N', (1, 0): 'S', (0, 1): 'E'}
        for act in actions:
            new_position = (self.position[0]+act[0], self.position[1]+act[1])
            # Kiểm tra xem vị trí có hợp lệ trong maze hay không
            if new_position[0] < 1 or new_position[0] > (maze.rows) or new_position[1] < 1 or new_position[1] > (maze.cols):
                continue
            # Kiểm tra xem vị trí có bị trúng vật cản hay không
            if maze.maze_map[self.position][direc[act]] == 0:
                continue
            # Thêm node mới
            new_node = Node(position=new_position, parent=self)
            children.append(new_node)

        return children


def astar(start, end, maze):
    '''
    Trả về đường đi từ start tới end trong maze, xử lí bằng thuật toán A* search
    '''
    start_node = Node(position=start)
    #start_node.g = start_node.h = start_node.f = 0
    end_node = Node(position=end)
    #end_node.g = end_node.h = end_node.f = 0

    # Tạo open_list và closed_list
    open_list = []
    closed_list = []

    open_list.append(start_node)

    while len(open_list):

        current_node = open_list[0]
        current_index = 0

        # Tìm node có g nhỏ nhất
        for index, item in enumerate(open_list):
            if item.f < current_node.f:
                current_node = item
                current_index = index

        open_list.pop(current_index)
        closed_list.append(current_node)

        # Kiểm tra xem node hiện tại có phải goal không
        if current_node == end_node:
            path = []
            current = current_node
            # Trả về đường đi
            while current is not None:
                #if current.parent!=None:
                path.append(current.position)
                current = current.parent
            return path[::-1]

        children = current_node.ChildExpand(maze)
        for child in children:
            child.g = current_node.g+1
            # Tính heuristic dựa trên Chebyshev Heuristic
            x_distance = abs(child.position[0]-end_node.position[0])
            y_distance = abs(child.position[1]-end_node.position[1])
            child.h = x_distance+y_distance

            child.f = child.g+child.h

        # Hàm kiểm tra xem child vừa tạo có trong open_list hay closed_list hay chưa
        # Nếu có thì xem node nào có g nhỏ hơn thì giữ lại
            def checklist(list):
                for index, item in enumerate(list):
                    if item == child and child.g < item.g:
                        list.pop(index)
                        open_list.append(child)
                        return

            if child not in open_list and child not in closed_list:
                open_list.append(child)
            elif child in open_list:
                checklist(open_list)
            elif child in closed_list:
                checklist(closed_list)
            else:
                continue


if __name__ == '__main__':

    m = maze(20,20)
    

    start = (5, 4)
    goal = (18, 12)
    m.CreateMaze( goal[0], goal[1],loopPercent=100)
    starttime=time.time()
    path = astar(start, goal, m)
    a = agent(m,start[0],start[1], footprints=True)
    endtime=time.time()
    print(path)
    print(endtime-starttime)
    m.tracePath({a: path})
    m.run()


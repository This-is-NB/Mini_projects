import random
from os import system
import numpy as np


grid = np.array([[0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0]])
rand_list = [2, 2, 2, 2, 4]
# grid = [[0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0]]


def printGrid():
    for line in grid:
        for ele in line:
            print(ele, end="  ")
        print()


def generate():
    rand_no = random.choices(rand_list)
    x = random.randrange(4)
    y = random.randrange(4)
    while grid[x][y] != 0:
        x = random.randrange(4)
        y = random.randrange(4)
    grid[x][y] = rand_no[0]


def shift(g):
    ind = 0
    for col in g:
        new_col = [0, 0, 0, 0]
        j = 0
        pre = None
        for i in range(4):
            if col[i] != 0:
                if pre == None:
                    pre = col[i]
                else:
                    if pre == col[i]:
                        new_col[j] = 2*col[i]

                        if new_col[j] == 64:
                            win()
                        j += 1
                        pre = None
                    else:
                        new_col[j] = pre
                        j += 1
                        pre = col[i]
        if pre != None:
            new_col[j] = pre
        # return new_col
        g[ind] = new_col
        ind += 1
    # final = shift(g)
    return g


def move(grid, dir):
    # 0 : left , 1 : up , 2 : right , 3 : down
    rotated_grid = np.rot90(grid, dir)
    cols = [rotated_grid[i, :] for i in range(4)]
    # new_board = np.array
    grid = np.rot90(shift(rotated_grid), -dir)


def check(grid):
    for row in grid:
        for ele in row:
            if ele == 32:
                print("!!!YOU WIN!!!!")
                exit()


def win():
    print("!!!YOU WIN!!!!")
    exit()


def gameloop():
    while True:
        flag = False
        local_grid = grid
        m = input().lower()
        if m == "w":
            move(grid, 1)       # shiftUp
        elif m == "a":
            move(grid, 0)       # shiftLeft
        elif m == "s":
            move(grid, 3)       # shiftDown
        elif m == "d":
            move(grid, 2)       # shiftRight
        else:
            print("Wrong Input")
            flag = True
        # if local_grid.all() == grid.all() and not flag:
        #     print("!!!!!!!!!!!YOU LOSE!!!!!!!!!")
        #     break

        check(grid)
        generate()
        system("cls")
        printGrid()


if __name__ == "__main__":
    generate()
    generate()
    printGrid()
    gameloop()
# print(shift(shift(np.array([[2, 4, 4, 8]]))))

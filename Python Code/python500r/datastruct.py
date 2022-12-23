from collections import defaultdict


class dataStruct:
    mainDish = {}
    sideDish = {}
    number = 0
    mainDishPrice = defaultdict(list)  # 默认值为空列表形式
    sideDishPrice = defaultdict(list)  # 默认值为空列表形式

    def countNumber(self):
        self.number = 0
        for eachPrice in self.mainDishPrice.keys():
            self.number += len(self.sideDishPrice[15 - eachPrice]) * len(self.mainDishPrice[eachPrice])

    def addNewMainDish(self, name, price):
        把{name:price}插入到AVL1树中
        self.mainDish[name] = price  # 添加
        self.mainDishPrice[price].append(name)  # {“key”: [value1]}
        self.countNumber()

    def addNewSideDish(self, name, price):
        把{name:price}插入到AVL2树中
        self.sideDish[name] = price  # 添加
        self.sideDishPrice[price].append(name)  # {“key”: [value1]}
        self.countNumber()

    def removeMainDish(self, name):
        deletePrice=从AVL1中根据name得到price
        把{name:price}从AVL1树中删除
        del self.mainDish[name]  # 删除
        self.mainDishPrice[deletePrice].remove(name)
        self.countNumber()

    def removeSideDish(self, name):
        deletePrice = 从AVL1中根据name得到price
        把name从AVL2树中删除
        del self.sideDish[name]  # 删除
        self.sideDishPrice[deletePrice].remove(name)
        self.countNumber()

    def countCombinations(self):
        return self.number


if __name__ == '__main__':
    ds = dataStruct()

    ds.addNewMainDish('main1', 10)
    ds.addNewMainDish('main2', 10)
    ds.addNewMainDish('main3', 8)
    ds.addNewSideDish('side1', 5)
    ds.addNewSideDish('side2', 5)
    ds.addNewSideDish('side3', 7)
    ds.addNewSideDish('side4', 7)

    print(ds.mainDish)
    print(ds.sideDish)
    print(ds.mainDishPrice)
    print(ds.sideDishPrice)
    print(ds.countCombinations())

from xlwt import *


def write(data):
    file = Workbook(encoding='utf-8')
    table = file.add_sheet('data')
    # 字典数据
    ldata = []
    num = [a for a in data]
    # for循环指定取出key值存入num中
    num.sort()
    # 字典数据取出后无需，需要先排序
    for x in num:
        # for循环将data字典中的键和值分批的保存在ldata中
        t = [int(x)]
        for a in data[x]:
            t.append(a)
        ldata.append(t)

    for i, p in enumerate(ldata):
        # 将数据写入文件,i是enumerate()函数返回的序号数
        for j, q in enumerate(p):
            # print i,j,q
            table.write(i, j, q)
    file.save('data.xls')

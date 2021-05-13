import ask
import read
import write
from Bio import Entrez

if __name__ == '__main__':
    meshList = read.read()
    dirAll = {}
    # recordAll = [[] for i in range(20)]
    years = ['2000', '2001', '2002', '2003', '2004', '2005', '2006', '2007', '2008', '2009',
             '2010', '2011', '2012', '2013', '2014', '2015', '2016', '2017', '2018', '2019']
    # years = ['2000', '2001', '2002', '2003']
    i = 0
    print('meshList: ', meshList)
    print('meshList lengths: ', len(meshList))
    length = len(meshList)
    start = 0  #255  # 改这里,0:2对应字典里的1-3,140--260，
    meshList = meshList[start:start + 100]
    j = 0
    for each in meshList:
        recordEach = []
        recordEach.clear()
        recordEach.append(each)
        for year in years:
            recordEach.append(ask.ask(each, year))
            print('recordEach: ', recordEach)
        dirAll[str(i + 1 + start)] = recordEach
        print('dirAll', dirAll)
        i += 1
    write.write(dirAll)
    # recordAll[i].append(recordEach)
    # print('recordAll: ', recordAll)
    # 写入excel中
    # print(type(meshList[0]))
    # print('recordAll: ', recordAll)
    # for eachRecord in record:
    #     print(each['Count'])
    write.write(dirAll)

import xlrd


def read():
    workbook = xlrd.open_workbook('1279个mesh词.xlsx')
    # print(workbook.sheet_names())
    sheet1_name = workbook.sheet_names()[0]
    # print(sheet1_name)
    sheet1 = workbook.sheet_by_name(sheet1_name)
    # print(sheet1.name, sheet1.nrows, sheet1.ncols)
    result = sheet1.col_values(sheet1.ncols-1)
    del (result[0])
    return result


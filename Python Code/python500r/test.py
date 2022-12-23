from collections import defaultdict

dd = defaultdict(list)  # 默认值为空列表形式
dd['key'].append(1)  # {“key”: [value1]}
dd['key'].append(2)  # {“key”: [value1, value2]} , 一个键值可以对应多个value
print(dd)

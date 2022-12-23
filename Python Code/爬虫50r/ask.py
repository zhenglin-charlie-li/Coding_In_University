from Bio import Entrez


def ask(item, year):
    item = item + "[Majr:NoExp]"  # limit to major and no narrower
    Entrez.email = '1125806272@qq.com'
    handle = Entrez.esearch(db='pubmed', term=item, mindate=year+'/01', maxdate=year+'/12')
    record = Entrez.read(handle)
    count = record['Count']
    print(count)
    return count

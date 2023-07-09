def delete(str , path):
    str = str[len(path):]
    return str


def check(str , path):
    for i in range(len(path)):
        if path[i] != str[i]:
            return False
    return True


def Dp(mystr , paths , Dic):
    if(mystr in Dic):
        return Dic[mystr]
    
    if mystr =='':
        return True
    
    for i in range(len(paths)):

        if(check(mystr , paths[i])):
            newStr = delete(mystr , paths[i])

            if Dp(newStr , paths , Dic):
                Dic[mystr] = True
                return True
            
    Dic[mystr] = False
    return False      
Dic = {}

x = "abcdef"
x2 = "kabsfbiiubsdiuiuiuvggisduaiuaiidapiosiudbviusbviubsiubvuabsbivubsdiubvsidbvasbvsdudoi"

paths = ["ab" , "abc" , "cd" , "def" , "abcd"]
paths2 =["skjn", "kabsfbiiubsd" , "ubsiubvu" , "slihsia", "sidbv" , "sksan" , "iuiuiuvggisdua"]



print(Dp(x , paths , Dic))
Dic.clear()
print(Dp(x2 , paths2 , Dic))
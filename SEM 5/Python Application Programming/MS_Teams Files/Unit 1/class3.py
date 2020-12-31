def english(func):
    def inner():
        str1=func()
        #print(str1)
        d={str1:"what is your name"}
        return d[str1]
    return inner
@english
def french():
    return "comment vous appelez-vous"
print(french())
#d=english(french)
#print(d())





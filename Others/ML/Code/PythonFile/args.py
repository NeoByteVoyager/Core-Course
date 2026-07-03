
class Foobar:
    def __init__(self):
        pass
    def __call__(self, *args, **kwargs):
        print("hello"+str(args[0]))


foobar=Foobar()
foobar(1,2,3)

def fun(*args,**kwargs):
    print(args)
    print(kwargs)

fun(1,2,3,4,x=1,y=2)
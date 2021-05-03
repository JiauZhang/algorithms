def decorator_func(func):
    def do_decorate(*args, **kargs):
        print('decorator_func')
        print('args: {}, kargs: {}'.format(args, kargs))
        func(*args, **kargs)
        print('do_decorate done!')

    return do_decorate

class decorator_clazz():
    def __init__(self, func):
        print('decorator_clazz')
        self._func = func
        print('decorator_clazz __init__ done!')

    def __call__(self, *args, **kargs):
        print('__call__')
        print('args: {}, kargs: {}'.format(args, kargs))
        self._func(*args, **kargs)
        print('__call__ done!')

@decorator_clazz
@decorator_func
def hello(*args, **kargs):
    print('original hello func')
    print('args: {}, kargs: {}'.format(args, kargs))
    print('original hello func done!')

hello('xxx')
hello('yyy', key='zzz')
hello('yyy', 'mmm', key='zzz', value='nnn')

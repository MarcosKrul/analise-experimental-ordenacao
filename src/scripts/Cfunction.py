from ctypes import cdll
from ctypes import c_int


class Cfunction:
    def __init__(self):
        self.__lib = cdll.LoadLibrary("./../lib/execute.dll")
        self.execute = self.__lib.execute
        self.execute.restype = None
        self.execute.argtypes = [c_int, c_int, c_int]

"""
Copyright(c) 2019 Jiau Zhang
For more information see <https://github.com/JiauZhang/algorithms>

This repo is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation

It is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with THIS repo. If not, see <http://www.gnu.org/licenses/>.
"""

# https://github.com/python/cpython/blob/master/Lib/threading.py
import threading, time

class HelloThread(threading.Thread):
    def __init__(self, thread_name):
        threading.Thread.__init__(self, name=thread_name)
        self.count = 0
        
    def run(self):
        print ('HelloThread>>> thread name: {} start runing...\n'.format(self.getName()))

        while self.count < 10:
            self.count += 1
            print ('HelloThread>>> {} >>> {}'.format(self.getName(), self.count))
            time.sleep(0.5)

        print ('HelloThread>>> {} stopped!'.format(self.getName()))

if __name__ == '__main__':
    td = HelloThread("HelloThread")
    print ('main Thread>>> start HelloTread...')
    td.start()
    print ('main Thread>>> wait HelloThread exit...')
    td.join()
    print ('main Thread>>> HelloTread and the main Thread exit...')

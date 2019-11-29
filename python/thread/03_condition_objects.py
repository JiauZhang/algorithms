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

import threading, time

def condition_thread(ident):
    con.acquire()
    print ('thread {} get the lock'.format(ident))
    print ('thread {} notify another thread'.format(ident))
    con.notify()
    print ('thread {} wait lock'.format(ident))
    # release the lock and block itself until be notified
    con.wait()

if __name__ == '__main__':
    lock = threading.Lock()
    con = threading.Condition(lock = lock)
    
    for i in xrange(0, 5):
        threading._start_new_thread(condition_thread, (i, ))

    time.sleep(1)
    print ('main thread exit...')

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

import thread, time

def thread_lock(ident):
    print ('thread {} acquire lock\n'.format(ident))
    lk.acquire()
    print ('thread {} get the lock'.format(ident))
    print ('thread {} release the lock'.format(ident))
    lk.release()

if __name__ == '__main__':
    # https://docs.python.org/2/library/thread.html#module-thread
    lk = thread.allocate_lock()
    for i in xrange(0, 5):
        thread.start_new_thread(thread_lock, (i, ))

    time.sleep(1)
    print ('main thread exit...')

import time
import threading
import multiprocessing

def do_something(t=1):
	print("(inside) Name of the current thread : ", threading.current_thread().name)
	time.sleep(t)


# Note the initial time
start = time.time()



########### DO HERE ###########
pgm1 = threading.Thread(target=do_something, args=[2], name="program one")
pgm2 = threading.Thread(target=do_something, args=(3,), name="program two")
pgm1.start()
pgm2.start()
print('current thread count',threading.active_count())
print("state thread 1 : ", pgm1.is_alive())
print("state thread 2 : ", pgm2.is_alive())

print("Name of the current thread : ", threading.current_thread().name)
print("Main thread is : ", threading.main_thread().name)
print("The thread 1 is : ", pgm1.getName())
print("The thread 2 is : ", pgm2.getName())

pgm1.join()

print("\n\nstate thread 1 : ", pgm1.is_alive())
print("state thread 2 : ", pgm2.is_alive())


pgm2.join()

print("(2) state thread 1 : ", pgm1.is_alive())
print("(2) state thread 2 : ", pgm2.is_alive())


########### STOP DOiNG ###########



# Finished, Now find Time
finish = time.time()
print("Finished in ", round(finish-start,3)," second(s)")

# print(dir(threading))

print(dir(multiprocessing))
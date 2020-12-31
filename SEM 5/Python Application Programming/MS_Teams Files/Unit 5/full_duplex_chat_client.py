
"""
TCP Full-Duplex Chat Client.
"""

from socket import *
from time import ctime
from threading import Event
from chatthreads import ReceiverThread, SenderThread
class ChatClient:
    def __init__(self, host, port):
        self.ADDR = (host, port)
        self.threads = []
        self._stop = Event()
    def __call__(self):
        # Make a TCP cliet socket
        with socket(AF_INET, SOCK_STREAM) as client_socket:
            # Connect to a remote (server) address
            try:
                client_socket.connect(self.ADDR)
            except ConnectionRefusedError:
                print('!!! Can\'t connect to the Chat Server...')
                return
            else:
                print('*** Connection whit the Chat Server is established...\n***',
                      ctime())
            # Spawn threads for a receiving and sending messages
            for thrd in [ReceiverThread, SenderThread]:
                self.threads.append(thrd(client_socket, self._stop))
            # Trigger the spawned threads
            for thrd in self.threads:
                thrd.start()
            # Wait for all threads to finish
            try:
                for thrd in self.threads:
                    thrd.join()
            except KeyboardInterrupt:
                # Exit from the Chat
                print('\nGood bye all!')


if __name__ == '__main__':
    HOST = "localhost"
    PORT = 21567

    chat_client = ChatClient(HOST, PORT)
    chat_client()

#TCP Full-Duplex Chat Server Client.
from socket import *
from time import ctime
from threading import Event
from chatthreads import ReceiverThread, SenderThread
class ChatServer:
    def __init__(self, host, port):
        self.ADDR = (host, port)
        self.threads = []
        self._stop = Event()
    def __call__(self):
        # Make a TCP server socket
        with socket(AF_INET, SOCK_STREAM) as server_socket:
            server_socket.bind(self.ADDR)
            # Accept only one cliet
            server_socket.listen(1)
            print('\n*** Chat Server is started!\n***', ctime())
            try:
                while True:
                    print('\nWaiting for a connection...\n')
                    conn, addr = server_socket.accept()
                    print('Connection accepted from', addr)
                    with conn as client_socket:
                        # Spawn threads for a receiving and sending messages
                        for thrd in [ReceiverThread, SenderThread]:
                            self.threads.append(thrd(client_socket, self._stop))
                        # Trigger the spawned threads
                        for thrd in self.threads:
                            thrd.start()
                        # Wait for all threads to finish
                        for thrd in self.threads:
                            thrd.join()
                        print("Client", addr, "has leaved the chat.")
                        # Empty list with thread and wait for a next client
                        self.threads.clear()
                        self._stop = Event()
            except KeyboardInterrupt:
                print('\n*** Chat Server is closed!\n***', ctime())
if __name__ == '__main__':
    HOST = ""
    PORT = 21567

    chat_server = ChatServer(HOST, PORT)
    chat_server()

import bluetooth
import threading

addr = "00:4b:12:33:39:7e"
port = 1
sock = bluetooth.BluetoothSocket(bluetooth.RFCOMM)
sock.connect((addr, port))

print("Pidklucheno")
def receive():
    while True:
        try:
            data = sock.recv(1024).decode().strip()
            if data:
                print("otrymano vid esp", data)

        except:
            break
threading.Thread(target=receive, daemon=True).start()

try:
    while True:
        msg = input("Vi: ")
        sock.send(msg)

except KeyboardInterrupt:
    print("vyhid")
    sock.close()
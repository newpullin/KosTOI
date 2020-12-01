from bluepy import btle
import struct


class MyDelegate(btle.DefaultDelegate):
    def __init__(self, params):
        btle.DefaultDelegate.__init__(self)

    def handleNotification(self, cHandle, data):
        ##        print(self)
        ##        print(cHandle)
        # print(struct.unpack("b",data))
        print(str(data))


p = btle.Peripheral('C8:FD:19:13:A0:76')
p.setDelegate(MyDelegate(0))

# services=p.getServices()

# displays all services
# for service in services:
#   print (service)


# get uuid

chList = p.getCharacteristics()
print("Handle   UUID                                Properties")
print("-------------------------------------------------------")
for ch in chList:
    print("  0x" + format(ch.getHandle(), '02X') + "   " + str(ch.uuid) + " " + ch.propertiesToString())

"""
Handle   UUID                                Properties
-------------------------------------------------------
  0x03   00002a00-0000-1000-8000-00805f9b34fb READ 
  0x05   00002a01-0000-1000-8000-00805f9b34fb READ 
  0x07   00002a02-0000-1000-8000-00805f9b34fb READ WRITE 
  0x09   00002a03-0000-1000-8000-00805f9b34fb WRITE 
  0x0B   00002a04-0000-1000-8000-00805f9b34fb READ 
  0x0E   00002a05-0000-1000-8000-00805f9b34fb INDICATE 
  0x12   0000ffe1-0000-1000-8000-00805f9b34fb READ WRITE NO RESPONSE WRITE NOTIF
"""

"""

#get name

dev_name_uuid = btle.UUID(0x2A00)
ch = p.getCharacteristics(uuid=dev_name_uuid)[0];
if(ch.supportsRead()):
	print(ch.read())

b'arduiono'
"""
dev_write_uuid = btle.UUID(0x2A03)
wirte_service = p.getServiceByUUID(dev_write_uuid)
print(wirte_service)

while True:
    if p.waitForNotifications(1.0):
        continue
    print("waiting...")

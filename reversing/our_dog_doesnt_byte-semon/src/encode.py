import dis

target = ""

def encode1(data):
    data = list(data)
    for i in range(len(data)):
        data[i] = chr((ord(data[i]) << 4 | ord(data[i]) >> 4 ) & 0xFF)
    
    return data

def encode2(data):
    key = "woof"
    result = ""

    for i in range(len(data)):
        result += chr(ord(data[i]) ^ ord(key[i % len(key)]))
    result = ''.join(f"{ord(i):02x}" for i in result)
    return result

def main():
    user_input = input('Input: ')
    encoded_data = encode1(user_input)
    result = encode2(encoded_data)

    if result == "d30b5ad1936c289353f8283082cb3851049a4b7050d93c7465b8":
        print("Correct!")
    else:
        print("Wrong..")
    
#main()
dis.dis(encode1)
dis.dis(encode2)
dis.dis(main)

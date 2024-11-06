def encode(input_data, key):
    return (''.join(f"{ord(input_data[i]) ^ ord(key[i % len(key)]):02x}" for i in range(len(input_data))))

def main():
    flag = "JFS{***terminated***}"
    key = input('Input key: ')
    encoded_data = encode(flag, key)
    if len(key) == 5:
        if encoded_data == "7e14144b667b0d0271666d0d157563710014797b7373661148" :
            print("Correct!!")
        else :
            print("Wrong..")
    else:
        print("Invalid Key length")

main()

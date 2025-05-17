# The given string
flag = "JFS{ant!_u9x_un9ack!ng@@}"

# XOR each character with 0x77 and store the results
xor_result = [ord(c) ^ 0x77 for c in flag]

# Format the result as a C array
c_array = ', '.join(f'0x{val:02X}' for val in xor_result)

# Print the final C code
print(f"unsigned char encoded_flag[] = {{ {c_array} }};")

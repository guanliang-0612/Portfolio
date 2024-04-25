from Crypto.PublicKey import RSA
from Crypto.Cipher import PKCS1_OAEP
from Crypto.Cipher import AES
from Crypto.Util.Padding import unpad
import os

def choose_private_key():
    print("Choose a private key:")
    print("1. firstprivate.pem")
    print("2. secprivate.pem")
    choice = input("Enter the number of the private key you want to use (1 or 2): ")
    if choice in {'1', '2'}:
        return choice
    else:
        print("Error: Please enter either '1' or '2'.")

def decrypt_message(private_key_path, input_file, output_file):
    try:
        # Read the encrypted message and key from the input file
        with open(input_file, 'rb') as file:
            encrypted_data = file.read()

        # Import the private key
        private_key = RSA.import_key(open(private_key_path).read())

        # Decrypt the AES key with RSA
        cipher_rsa = PKCS1_OAEP.new(private_key)
        aes_key = cipher_rsa.decrypt(encrypted_data[:private_key.size_in_bytes()])

        # Decrypt the message with AES
        iv = encrypted_data[private_key.size_in_bytes():private_key.size_in_bytes() + 16]
        ciphertext = encrypted_data[private_key.size_in_bytes() + 16:]
        cipher_aes = AES.new(aes_key, AES.MODE_CBC, iv)
        decrypted_data = unpad(cipher_aes.decrypt(ciphertext), AES.block_size)

        # Save the decrypted message to the output file
        with open(output_file, "wb") as f:
            f.write(decrypted_data)

        print(f"Message from '{input_file}' decrypted successfully to '{output_file}'.")
    except ValueError:
        print(f"Error: Incorrect decryption for '{input_file}'. The provided private key might not match the encryption key.")

if __name__ == "__main__":
    # Choose a private key
    private_choice = choose_private_key()
    private_key_path = "firstprivate.pem" if private_choice == '1' else "secprivate.pem"

    # Decrypt messages using the chosen key pair
    for i in range(1, 4):
        input_file = f"encrypted_message{i}.bin"
        output_file = f"decrypted_message{i}.txt"
        decrypt_message(private_key_path, input_file, output_file)


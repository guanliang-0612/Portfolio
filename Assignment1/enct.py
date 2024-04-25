from Crypto.PublicKey import RSA
from Crypto.Cipher import PKCS1_OAEP
from Crypto.Cipher import AES
from Crypto.Util.Padding import pad
import os

def generate_key_pair(filename_prefix):
    private_key_path = filename_prefix + "private.pem"
    public_key_path = filename_prefix + "public.pem"

    # Check if keys already exist
    if os.path.exists(private_key_path) or os.path.exists(public_key_path):
        print("Keys already exist. Skipping key generation.")
        return public_key_path, private_key_path

    # Generate RSA key pair
    key = RSA.generate(2048)

    # Save private key
    with open(private_key_path, 'wb') as f:
        f.write(key.export_key())

    # Save public key
    with open(public_key_path, 'wb') as f:
        f.write(key.publickey().export_key())

    return public_key_path, private_key_path

def choose_public_key():
    while True:
        print("Choose a public key:")
        print("1. firstpublic.pem")
        print("2. secpublic.pem")
        choice = input("Enter the number of the public key you want to use (1 or 2): ")
        if choice in {'1', '2'}:
            return choice
        else:
            print("Error: Please enter either '1' or '2'.")

def encrypt_message(public_key_path, output_file, input_file):
    # Read the message from the input file
    with open(input_file, 'rb') as file:
        message = file.read()

    # Generate a random AES key
    aes_key = os.urandom(16)

    # Import the public key
    public_key = RSA.import_key(open(public_key_path).read())

    # Encrypt the AES key with RSA
    cipher_rsa = PKCS1_OAEP.new(public_key)
    encrypted_aes_key = cipher_rsa.encrypt(aes_key)

    # Encrypt the message with AES
    cipher_aes = AES.new(aes_key, AES.MODE_CBC)
    ciphertext = cipher_aes.encrypt(pad(message, AES.block_size))

    # Save the encrypted message and key to the output file
    with open(output_file, "wb") as f:
        f.write(encrypted_aes_key + cipher_aes.iv + ciphertext)

    print(f"Message from '{input_file}' encrypted successfully to '{output_file}'.")

if __name__ == "__main__":
    # Generate two key pairs
    first_public, first_private = generate_key_pair("first")
    sec_public, sec_private = generate_key_pair("sec")

    # Choose a public key
    public_choice = choose_public_key()
    public_key_path = "firstpublic.pem" if public_choice == '1' else "secpublic.pem"

    # Encrypt messages using the chosen key pair
    for i in range(1, 4):
        input_file = f"text{i}.txt"
        output_file = f"encrypted_message{i}.bin"
        encrypt_message(public_key_path, output_file, input_file)


password = ""
invalid_attempts = 0

while password != "python123":
    password = input("Enter the password: ")
    
    if password != "python123":
        invalid_attempts += 1

print(f"Number of invalid attempts: {invalid_attempts}")

try:
    with open("fahrenheit.txt", "r") as infile, open("celsius.txt", "w") as outfile:
        for line in infile:
            fahrenheit = float(line)
            celsius = (fahrenheit - 32) * 5 / 9
            outfile.write(f"{celsius:.2f}\n")

except FileNotFoundError:
    print("File not found")

except ValueError:
    print("Invalid data")

negative_sum = 0
negative_count = 0
positive_sum = 0
positive_count = 0

with open("numbers.txt", "r") as infile:
    for line in infile:
        number = float(line)

        if number < 0:
            negative_sum += number
            negative_count += 1
        elif number > 0:
            positive_sum += number
            positive_count += 1

if negative_count > 0:
    print(negative_sum / negative_count)
else:
    print("NaN")

if positive_count > 0:
    print(positive_sum / positive_count)
else:
    print("NaN")

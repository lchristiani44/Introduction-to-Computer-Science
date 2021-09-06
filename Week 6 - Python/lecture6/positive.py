import cs50

def main():
    i = get_positive_int()
    print(i)

def get_positive_int():
    # Python does not have the do while loop
    while True:
        n = get_int("Positive integer: ")
        if n > 0:
            break
    # return to the original indentation!
    return n
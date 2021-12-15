def main():
    
    # Gets the pyramid height
    height = get_height()

    # Sets the value of some important variables
    counter = 1
    spaces = height - 1

    for i in range(height):
        print(' ' * int(spaces), end='')
        print('#' * int(height - spaces), end='')

        print('  ', end='')

        print('#' * counter, end='')

        counter += 1
        spaces -= 1
        print()


def get_height():
    
    while True:
        n = input('Height: ')
        
        if n.isnumeric():
            n = int(n)
            if n > 0 and n < 9:
                break
    return n


if __name__ == '__main__':
    main()
from typing import List
# DO NOT IMPORT ANY OTHER PACKAGES
# Please delete the "pass" lines then fill your answers


def sum_of_prime_factors(n: int) -> int:
    """problem # 1: return sum of the prime factors of a given n

    :param n: integer (0 < n < 1e+12)
    :return: sum of prime factors of n
    """
    prime_factor = []
    i = 2

    if n == 1:
        return print('1')

    while n != 1:
        if n % i == 0:
            n = n / i
            prime_factor.append(i)
            return

        else:
            i = i + 1
            return
            
    sum_of_prime_factors = sum(prime_factor)
    print(sum_of_prime_factors)
    return 
    


def even_occurred_number(li: List[int]) -> int:
    """problem # 2: return the single number
    which occurs even times in the list

    :param li: list of integer (0 < len(li) < 1e+6)
    :return: single integer which occurs even times
    """
    for i in range(len(li)):
        a = li[i]
        number = li.count(a)
        if number % 2 == 0:
            print (a)
            li.remove(a)
        else:            
            continue
        break

    
if __name__ == "__main__":
    """sample inputs
    below codes do not execute in the "main.py"
    """

    """problem # 1
    sample inputs
    """
    print(sum_of_prime_factors(1))  # correct answer is 1
    print(sum_of_prime_factors(124))  # correct answer is 35

    """problem # 2
    sample inputs
    """
    print(even_occurred_number([1, 1]))  # correct answer is 1
    print(even_occurred_number([2, 2, 3, 3, 3, 4, 4, 4]))  # correct answer is 2

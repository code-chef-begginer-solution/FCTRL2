#include <bits/stdc++.h>

/* function prototype */
void multiply(std::vector<size_t>& digits, size_t number);
void factorial(ssize_t number);

int main(int argc, char* argv[]) {
    /* get the test_case */
    size_t test_case;
    std::cin >> test_case;

    /* navigate through each test_case */
    while (test_case--) {

        /* get the number */
        ssize_t number;
        std::cin >> number;

        /* find out the factorial of number */
        factorial(number);
    }
    return 0;
}

/* a function to find out the factorial of number */
void factorial(ssize_t number) {

    /* define a vector to store factorial */
    std::vector<size_t> digits{1};

    if (number > 0) {

        /* factorial value of number greater than or equal to 1 */
        for(size_t j{1}; j <= number; j++) {
            multiply(digits, j);
        }

        /* print the factorial of number */
        for (auto it{digits.rbegin()};it != digits.rend();++it) {
            std::cout << *it;
        }

        /* traverse the cursor to the next line */
        std::cout << std::endl;
    } else if (number == 0){
        /* -----* value of 0! = 1 *------ */
        int zero_factorial{1};
        std::cout << zero_factorial << std::endl;
    } else {
        /* factorial value is not defined for negative numbers */
        std::cout << "factorial value isn't defined!" << std::endl;
    }
}

/* multiply the obtained number with provided value */
void multiply(std::vector<size_t>& digits, size_t number) {
    /* define temp and carry */
    size_t temp, carry{0};

    /* multiply the provided number with
     * each digit in the factorial array */
    for(size_t k {0}; k < digits.size(); k++) {
        temp = number * digits.at(k) + carry;

        /* extract the last digit of temp */
        digits.at(k) = temp % 10;

        /* reduce temp by eliminating the
         * last digit i.e. processed digit */
        carry = temp / 10;
    }

    /* after multiplying with each digits
     * push the digits left in carry */
    while (carry != 0) {
        /* extract the last digit of carry */
        digits.push_back(carry % 10);

        /* reduce carry by eliminating the
         * last digit i.e. processed digit */
        carry /= 10;
    }
}
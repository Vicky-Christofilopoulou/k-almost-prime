# k-almost-prime
This C code is a program that checks for semiprime numbers and k-almost prime numbers within a specified range. It also generates and checks 20 random numbers for their "k-almost prime" property. 
For each number n in the specified range, the code checks for the number of divisors it has. If a number has exactly two divisors, it is considered a semiprime. If it has more than two divisors but no more than MAXK divisors, it is considered a k-almost prime.

The code then generates 20 random numbers and checks whether they are k-almost prime. It uses a simple method to generate random numbers and counts their divisors, similar to the approach used for the range of numbers.

Note: A k-almost prime is a number that has k prime factors (not necessarily distinct). A semiprime is a natural number that is the product of two prime numbers.

It's worth noting that the term "interesting semiprime" is used when the difference between the larger prime factor and the smaller prime factor is less than 1% of the larger prime factor.

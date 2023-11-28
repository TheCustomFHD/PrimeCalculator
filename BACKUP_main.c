#include <stdio.h>

#define NUMBER_OF_PRIMES 8192

int checkIfPrime(int numberToTest)
{
    //Create Variables needed for Testing if Number is Prime
    int counter = 2; //And Restless Divider Incrementer

    //run the Test if the Number is Prime
    for (counter = 2; counter < numberToTest; counter = counter + 1)
    {
        if ((numberToTest % counter) == 0)
        {
            //"numberToTest is not a Prime. Escape the for-loop asap, and set
            //"counter" higher then numberToTest, to tell the evaluation the result.
            counter = numberToTest;
        }
    }

    //Evaluation of the "for-loop"
    if (counter <= numberToTest)
    {
        //Prime
        //printf("PRIME\n");
        return 0;
    }
    else
    {
        //Not Prime
        //printf("NOT PRIME\n");
        return 1;
    }
}

int main(void)
{
    printf("PrimeCalculator + Verifyer by TCF\n");

    //Array for storing the Primes
    int primes[NUMBER_OF_PRIMES] = {0};

    //Variables for the for-loop until the Array is filled
    int currentArraySpot = 0;
    int numberToTest = 0;

    //Do this for every Spot in the Array
    for (currentArraySpot = 0; currentArraySpot < NUMBER_OF_PRIMES; currentArraySpot = currentArraySpot + 1)
    {
        //Increment "numberToTest" until we found a Prime
        while (checkIfPrime(numberToTest) != 0)
        {
            numberToTest = numberToTest + 1;
        }
        //We found a Prime, add it to the Array, and increment to check for the next one
        primes[currentArraySpot] = numberToTest;
        numberToTest = numberToTest + 1;
    }
    

    //Outputting Calculated Primes
    for (int counter = 0; counter < NUMBER_OF_PRIMES; counter = counter + 1)
    {
        printf("%d ", primes[counter]);
    }

    printf("\n\nExiting..\n\n");
    return 0;
}

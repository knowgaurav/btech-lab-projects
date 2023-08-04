/*You're working on a secret team solving coded transmissions.

Your team is scrambling to decipher a recent message, worried it's a plot to break into a major European National Cake Vault. The message has been mostly deciphered, but all the words are backward! Your colleagues have handed off the last step to you.

Write a function reverseWords() that takes a message as a string and reverses the order of the words in place. ↴

For example:

  string message = "cake pound steal";

reverseWords(message);

cout << message << endl;
// prints: "steal pound cake"

C++
When writing your function, assume the message contains only letters and spaces, and all words are separated by one space.

Gotchas
We can do this in O(1)O(1) space. Remember, in place. ↴

We can do this in O(n)O(n) time.

If you're swapping individual words one at a time, consider what happens when the words are different lengths. Isn't each swap O(n)O(n) time in the worst case?

Breakdown
Let’s start with a simpler problem. What if we wanted to reverse all the characters in the message?

Well, we could swap the first character with the last character, then the second character with the second to last character, and so on, moving towards the middle. Can you implement this in code?

  void reverseCharacters(string& message)
{
    size_t leftIndex = 0;
    size_t rightIndex = message.length() - 1;

    // walk towards the middle, from both sides
    while (leftIndex < rightIndex) {

        // swap the left char and right char
        swap(message[leftIndex], message[rightIndex]);
        ++leftIndex;
        --rightIndex;
    }
}

C++
We're using a cute one-liner to do the swap. In other languages you might need to do the swap by hand, recording one of the values in a temp variable.

Ok, looks good. Does this help us?

Can we use the same concept but apply it to words instead of characters?

Probably. We'll have to figure out a couple things:

How do we figure out where words begin and end?
Once we know the start and end indices of two words, how do we swap those two words?
We could attack either of those first, but I'm already seeing a potential problem in terms of runtime. Can you guess what it is?

What happens when you swap two words that aren't the same length?

  "the eagle has landed"

C++
Supposing we already knew the start and end indices of 'the' and 'landed', how long would it take to swap them?

O(n)O(n) time, where nn is the total length of the message!

Why? Notice that in addition to moving 'the' to the back and moving 'landed' to the front, we have to "scoot over" everything in between, since 'landed' is longer than 'the'.

So what'll be the total time cost with this approach? Assume we'll be able to learn the start and end indices of all of our words in just one pass (O(n)O(n) time).

O(n^2)O(n 
2
 ) total time. Why? In the worst case we have almost as many words as we have characters, and we're always swapping words of different lengths. For example:

  "a bb c dd e ff g hh"

C++
We take O(n)O(n) time to swap the first and last words (we have to move all nn characters):

  "a bb c dd e ff g hh"  // input
"hh bb c dd e ff g a"  // first swap

C++
Then for the second swap:

  "a bb c dd e ff g hh"  // input
"hh bb c dd e ff g a"  // first swap
"hh g c dd e ff bb a"  // second swap

C++
We have to move all nn characters except the first and last words, and a couple spaces. So we move n-5n−5 characters in total.

For the third swap, we have another 55 characters we don't have to move. So we move n-10n−10 in total. We'll end up with a series like this:

n + (n-5) + (n-10) + (n-15) + ... + 6 + 1n+(n−5)+(n−10)+(n−15)+...+6+1
This is a subsection of the common triangular series. ↴ We're just skipping 4 terms between each term!

So we have the sum of "every fifth number" from that triangular series. That means our sum will be about a fifth the sum of the original series! But in big O notation dividing by 5 is a constant, so we can throw it out. The original triangular series is O(n^2)O(n 
2
 ), and so is our series with every fifth element!

Okay, so O(n^2)O(n 
2
 ) time. That's pretty bad. It's possible that's the best we can do...but maybe we can do better?

Let's try manipulating a sample input by hand.

And remember what we did for our character-level reversal...

Look what happens when we do a character-level reversal:

  "the eagle has landed"  // input
"dednal sah elgae eht"  // character-reversed

C++
Notice anything?

What if we put it up against the desired output:

  "the eagle has landed"  // input
"dednal sah elgae eht"  // character-reversed
"landed has eagle the"  // word-reversed (desired output)

C++
The character reversal reverses the words! It's a great first step. From there, we just have to "unscramble" each word.

More precisely, we just have to re-reverse each word!

Solution
We'll write a helper function reverseCharacters() that reverses all the characters between a leftIndex and rightIndex. We use it to:

Reverse all the characters in the entire message, giving us the correct word order but with each word backward.
Reverse the characters in each individual word.
  void reverseCharacters(string& str, size_t leftIndex, size_t rightIndex)
{
    // walk towards the middle, from both sides
    while (leftIndex < rightIndex) {

        // swap the left char and right char
        swap(str[leftIndex], str[rightIndex]);
        ++leftIndex;
        --rightIndex;
    }
}

void reverseWords(string& message)
{
    // handle empty message
    if (message.empty()) {
        return;
    }

    // first we reverse all the characters in the entire message
    reverseCharacters(message, 0, message.length() - 1);
    // this gives us the right word order
    // but with each word backward

    // now we'll make the words forward again
    // by reversing each word's characters

    // we hold the index of the *start* of the current word
    // as we look for the *end* of the current word
    size_t currentWordStartIndex = 0;
    for (size_t i = 0; i <= message.length(); ++i) {

        // found the end of the current word!
        if (i == message.length() || message[i] == ' ') {

            // if we haven't exhausted the string our
            // next word's start is one character ahead
            reverseCharacters(message, currentWordStartIndex, i - 1);
            currentWordStartIndex = i + 1;
        }
    }
}

C++
Complexity
O(n)O(n) time and O(1)O(1) space!

Hmm, the team used your function to finish deciphering the message. There definitely seems to be a heist brewing, but no specifics on where. Any ideas?

Bonus
How would you handle punctuation?

What We Learned
The naive solution of reversing the words one at a time had a worst-case O(n^2)O(n 
2
 ) runtime. That's because swapping words with different lengths required "scooting over" all the other characters to make room.

To get around this "scooting over" issue, we reversed all the characters in the message first. This put all the words in the correct spots, but with the characters in each word backward. So to get the final answer, we reversed the characters in each word. This all takes two passes through the message, so O(n)O(n) time total.

This might seem like a blind insight, but we derived it by using a clear strategy:

Solve a simpler version of the problem (in this case, reversing the characters instead of the words), and see if that gets us closer to a solution for the original problem.*/

#include <assert.h>
#include <stdio.h>

// Interview Cake C Unit Test Framework, based on CuTest
//#include "Cake/UnitTest.h"

void reverseString(char *message, int i, int j)
{
    while (i < j)
    {
        char temp = message[i];
        message[i] = message[j];
        message[j] = temp;
        i++;
        j--;
    }
}

void reverseWords(char *message)
{
    // decode the message by reversing the words
    int i = 0, j = strlen(message) - 1, k = 0;
    reverseString(message, i, j);
    while (message[k] != '\0')
    {

        if (message[k + 1] == ' ' || message[k + 1] == '\0')
        {
            reverseString(message, i, k);
            i = k + 2;
        }
        k++;
    }
}

// tests

void oneWordTest(Test *tc)
{
    const char *expected = "vault";
    char actual[] = "vault";
    reverseWords(actual);
    AssertStrEquals(tc, expected, actual);
}

void twoWordsTest(Test *tc)
{
    const char *expected = "cake thief";
    char actual[] = "thief cake";
    reverseWords(actual);
    AssertStrEquals(tc, expected, actual);
}

void threeWordsTest(Test *tc)
{
    const char *expected = "get another one";
    char actual[] = "one another get";
    reverseWords(actual);
    AssertStrEquals(tc, expected, actual);
}

void multipleWordsSameLengthTest(Test *tc)
{
    const char *expected = "hh g c dd e ff bb a";
    char actual[] = "a bb c dd e ff g hh";
    reverseWords(actual);
    AssertStrEquals(tc, expected, actual);
}

void multipleWordsDifferentLengthsTest(Test *tc)
{
    const char *expected = "chocolate bundt cake is yummy";
    char actual[] = "yummy is cake bundt chocolate";
    reverseWords(actual);
    AssertStrEquals(tc, expected, actual);
}

void emptyStringTest(Test *tc)
{
    const char *expected = "";
    char actual[] = "";
    reverseWords(actual);
    AssertStrEquals(tc, expected, actual);
}

int main()
{
    TestSuite *tests = TestSuiteNew();

    SUITE_ADD_TEST(tests, oneWordTest);
    SUITE_ADD_TEST(tests, twoWordsTest);
    SUITE_ADD_TEST(tests, threeWordsTest);
    SUITE_ADD_TEST(tests, multipleWordsSameLengthTest);
    SUITE_ADD_TEST(tests, multipleWordsDifferentLengthsTest);
    SUITE_ADD_TEST(tests, emptyStringTest);

    TestSuiteRun(tests);
    TestSuiteDelete(tests);

    return 0;
}
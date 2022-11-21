# Failure-links-array (Kunth-Morris-Pratt-Algorithm)
Program that does the following :
* Create a function that constructs the failure links array of a given patten.

* Create a function that searches for occurrences of this pattern (exact matching) within another text string using KMP algorithm. Use the failure links array of the above function.

* Test the function in main() on the example in lecture and make sure it outputs the exact (ti, tj) and Rep(). Let the function output all these information.

* comments explaining the code before each code line, the test case, and following the CodingStyle.pdf file.

* The Knuth-Morris-Pratt (KMP) algorithm allows efficient searching for patterns in non-indexed strings. The first step in the KMP algorithm is to construct the failure links automaton for the pattern that we need to search for then apply the search technique.

# Functions
* getPrefix
```
Function to calculate each iteration prefix.
```
* getPropersuffix
```
 Function to calculate proper suffixes of each iteration.
```
* preprocessing
```
Function to calculate failure link of pattern.
```
* Search
```
Function to report the match between pattern and text.
```
* KMP
```
 Main function of KMP.
```





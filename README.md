![](https://github.com/lille-boy/alphabet_soup/workflows/alphaci/badge.svg)

# Goal
Sorts the letters of a string in alphabetical order

# Description
Take the string parameter being passed and return the string with the letters in alphabetical order (i.e. `hello` becomes `ehllo`).

Assume numbers and punctuation symbols will not be included in the string.
Make sorting case-independent. For example `Sensitive` becomes `eeiinSstv`.

# Solution
The program uses qsort.

# Usage
## Build

`make`

## Execute

### Options

#### Option -t
Runs the tests: `./alphabet -t`

Returns the number of tests passed, failed and executed.

#### Option -f
Ignores casing (sorts in ascending ASCII values): `./alphabet -f cbaBAC`

Returns `ABCabc`

#### No option
By default, case-independent sorting: `./alphabet cbaBAC`

Returns `AaBbCc`

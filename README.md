# far
C program to find and replace contents of a file.

Note: This software is currently in development.  Future updates will include more features and
automatic Linux installation features.


## Installation
### Automatic
No method of automatic installation comes with the current version.  Future versions will contain this feature.

### Manual
Compile source with GNU C Compiler and move executable to /bin directory.
```bash
 gcc far.c -o far
 sudo mv far /bin
```

## Usage

### Syntax
Replace all instances of a pattern in a file with a replacement string.
```bash
far [filepath] "[pattern]" "[replacement]"
```

Create a new file and replace all instances of a pattern in a file with a replacement string. 
```bash
far [source path] [destination path] "[pattern]" "[replacement]"
```

### Example
Replaces all instances of the word `hello` with the word `howdy` in a file named `greeting.txt`.
```bash
far greeting.txt "hello" "howdy"
```


## Contributing
This project is currently in the early stages of development and is lacking many features and is not well optimized.
Please, no pull requests at this time.  However, feature ideas and optimization techniques are gladly appreciated and will be 
taken into consideration.  Thank you! ~

## Licence

[GNU General Public Licence v2.0](https://www.gnu.org/licenses/old-licenses/gpl-2.0.en.html)

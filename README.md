# far
Linux Terminal C program to find and replace contents of a file.

Note: This software is currently in development.  Future updates will include more features and
automatic Linux installation features.


## Installation
### Automatic 
Automatic installation to `usr/bin/` directory.  Make sure to be inside of the project directory.
```bash
make install
```

### Manual
Compile source with GNU C Compiler and move executable to /bin directory.
```bash
 gcc far.c -o far
 sudo mv far /usr/bin
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


## Updates
This is an ongoing project.  The following features are planned to be added to this program:
- Regex support (currently in development)
- Multi-file operations
- Better support for autotools
- Standard input support


## Contributing
This project is currently in the early stages of development and is lacking many features and is not well optimized.
Please, no pull requests at this time.  However, feature ideas and optimization techniques are gladly appreciated and will be 
taken into consideration.  Thank you! ~

## Licence

[GNU General Public Licence v2.0](https://www.gnu.org/licenses/old-licenses/gpl-2.0.en.html)

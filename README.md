# BigInt library

BigInt is a C library for dealing with huge numbers.

## Installation

Use the package manager [pip](https://pip.pypa.io/en/stable/) to install foobar.

```bash
pip install foobar~
```

## Usage
Sample use in main.c
```c
int main() {

    BigInt* a = newBigIntFromString("1237854691872354698172346589716234598716327896");
    BigInt* b = newBigIntFromString("-1342059804135670179486501673450164501647350105347");

    infoBigInt(a);
    infoBigInt(b);

    printBigInt(add(a, b));
    printBigInt(subtract(a, b));
    printBigInt(multiply(a, b));

    return 0;
}
```

## List of implemented functions
1. Parsing from string
2. Output to string
3. Addition
4. Subtraction
5. Multiplication
6. Comparision

## Contribute
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## Support
If you are having issues, please let us know.
We have a mailing list located at: mail@mail.mail

## License
[MIT](https://choosealicense.com/licenses/mit/)

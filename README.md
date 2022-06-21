# Keyboard Macro

Create macros for expressions you use the most.

Tired of typing in your email, phone number or even your name in every form that doesn't support autofill? You can write them in the self.cpp file in the format given. The self.cpp file is just a template.

Currently, the macros evoke when you press INSERT after typing the macro. You can modify this so that it directly evokes each time a complete macro is typed.

The current way of pressing `INSERT` to evoke the macro is
1. So it doesn't randomly replace the word you genuinely meant to type.
2. It is also capable of replacing words even when you did not completely type the macro, as it understands when theres only one replacement for the part of the macro typed. (i.e. no other replacement starts with the part you have written) 

---

<br><br>

# Usage
After you have written your macro and replacements in the self.cpp file and built the program and it's running, type the macro and press insert. For the example file give,

### Type

<br>

> mail

<br>

press `INSERT`

<br>

### It turns to 

<br>

> MyMailAddress@example.com

<br>

and the entered expression gets selected.

This also workd if you type `na` instead of `name` and press `INSERT` as the code understands there is only one macro that begins with `na`, i.e. considering the example file. If you have another macro as `name2`, then it won't replace `na` with the corresponding expression.

---

<br><br>

# Installation / Building

To use as-is, you don't need to modify any .cpp file (except the self.cpp where you would define your own macros).

So you can just:

```
g++ input_module.o output_module.o tree.o self.cpp core.cpp -o core.exe
```

If you modify the other .cpp files, build the out files first, or directly include their .cpp instead of corresponding .o, whatever.

---

<br><br>

# Future Plans

Add an option to directly substitute instead of pressning `INSERT` every time. This can help in:

- Making a text formalizer that directly substitutes `"I don't know"` in place of `"idk"` or deletes `"lol"` etc. directly as you type.
- Making form filling easier using `TAB`s. For example to write such that na:ma:addr gets replaced by the corresponding expressions seperated by `TAB` keys for different fields.
- Stop `BACKSPACE`ing the macro, to build an emojifier, to insert various emojis determined from what you type, as you type without deleting stuff.

These are speculated. You can make the changes on your own (mostly in tree.cpp and core.cpp... you might have to add a few more elements in `struct node` to facilitate these extra functionalities.)

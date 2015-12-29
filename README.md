# WoW game bot

Used for disenchanting a lot of items without manually pressing the macro key. But you can use it for any task where you have to press the same key many times. The bot uses random pauses between 2 and 4 seconds to allow looting.

Example:

Given that you have the following disenchanting macro in game:

```
/cast disenchant
/use item:54473
```

bound to F1 key, then run the bot like this:

```
C:\> bot F1 100
```

where "F1" is the function key to which the macro is bound and "100" is the number of items you need to disenchant. If you run it without any command line arguments then the default key is F1 and the default number of items is 100. Use only keys from F1 to F12.

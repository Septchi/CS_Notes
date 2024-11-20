# Hashing
A process where you map large amounts of unrelated data to an index of a table.

## String to Int Functinos

### Option 1
```c
int option1(char key[]){
    int ans = 0;
    for(int i = 0; i < strlen(key); i++){
        ans += key[i];
    }

    return ans;
}
```

### Option 2
```c
int option2(char key[]){
    int ans = 0;
    int pow = 1;
    for(int i = 0; i < strlen(key); i++){
        ans += key[i] * pow;
        pow *= 27;
    }
}
```

### Option 3
```c
int option3(char key[]){
    int ans = 0;
    int pow = 1;
    int prime = 7;
    int len = strlen(key);
    for(int i = 0; i < len; i++){
        ans += key[len - 1 - i] * pow;
        pow *= prime;
    }

    return ans;
}
```

## Hash Functions

### Truncation

```c
int truncation(int key, int n){
    return key % power(10, n);
}
```

### Folding 
```c
int folding(int key){
    int digit = 0;
    int tkey = key;
    while(tkey != 0){
        tkey /= 10;
        digit++;
    }
    int tdigit = digit/2;
    int first = key / power(10, tdigit);
    int second = key % power(10, digit - tdigit);
    return first + second;
}
```

### Radix
```c
int radix(int key, int radix){
    int rad = 0;
    int tkey = key;
    int n = 0;
    while(tkey != 0){
        rad += (tkey%radix)*power(10, n);
        n++;
        tkey /= radix;
    }
    return rad;
}
```

### Mid-Square
```c
int midSquare(int key){
    int tkey = key * key;
    int digit = 0;

    while(tkey != 0){
        tkey /= 10;
        digit++;
    }
    tkey = key * key;
    digit /= 2;
    int res;
    res = tkey / power(10, digit - 1);
    res = res % power(10, 3);

    return res;
}
```

## Collision

### Linear Probing
```c
int LProbing(int index){
    return (1 + index)%SIZE;
}
```

### Double Hashing
```c
int DHashing(int index, int key){
    int INCR = 7; // must be les than size
    int increment = 1 + key % INCR;
    return (index + increment) % SIZE;
}
```

### Separate Chaining

Confusing so ill put it here.

#### [Link List Hash](LL_Hash.md)

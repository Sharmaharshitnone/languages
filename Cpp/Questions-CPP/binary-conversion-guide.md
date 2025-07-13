# Binary Conversion Guide

## 🔢 **Quick Reference: Converting Numbers to Binary**

### **The Key Insight**

- Each bit position represents a power of 2
- Position 0 = 2^0 = 1
- Position 1 = 2^1 = 2
- Position 2 = 2^2 = 4
- Position 3 = 2^3 = 8
- And so on...

### **Example: 56 in Binary**

**Method 1: Division by 2**

```
56 ÷ 2 = 28 remainder 0
28 ÷ 2 = 14 remainder 0
14 ÷ 2 = 7  remainder 0
7  ÷ 2 = 3  remainder 1
3  ÷ 2 = 1  remainder 1
1  ÷ 2 = 0  remainder 1

Reading from bottom to top: 111000
```

**Method 2: Powers of 2**

```
56 = 32 + 16 + 8 = 2^5 + 2^4 + 2^3

Bit positions: 7 6 5 4 3 2 1 0
Binary:        0 0 1 1 1 0 0 0
```

### **In Context of Our Algorithm**

**String "def" → Bitmask 56:**

- 'd' = bit 3 (since 'd' - 'a' = 3)
- 'e' = bit 4 (since 'e' - 'a' = 4)
- 'f' = bit 5 (since 'f' - 'a' = 5)

**Bitmask calculation:**

```
mask = 0
mask |= (1 << 3)  // Set bit 3 → mask = 8
mask |= (1 << 4)  // Set bit 4 → mask = 8 + 16 = 24
mask |= (1 << 5)  // Set bit 5 → mask = 24 + 32 = 56
```

**Visual representation:**

```
Positions: 7 6 5 4 3 2 1 0
Binary:    0 0 1 1 1 0 0 0
Letters:     f e d
```

### **Common Examples**

| String | Characters | Bit Positions | Bitmask  | Binary                     |
| ------ | ---------- | ------------- | -------- | -------------------------- |
| "a"    | a          | 0             | 1        | 00000001                   |
| "abc"  | a,b,c      | 0,1,2         | 7        | 00000111                   |
| "def"  | d,e,f      | 3,4,5         | 56       | 00111000                   |
| "z"    | z          | 25            | 33554432 | 10000000000000000000000000 |

### **Checking for Conflicts**

**Example: "abc" vs "def"**

- "abc" → bitmask = 7 (binary: 00000111)
- "def" → bitmask = 56 (binary: 00111000)
- Conflict check: 7 & 56 = 0 ✓ (no common bits = no common characters)

**Example: "abc" vs "axe"**

- "abc" → bitmask = 7 (binary: 00000111)
- "axe" → bitmask = 145 (binary: 10010001)
- Conflict check: 7 & 145 = 1 ≠ 0 ❌ (common bit = 'a' appears in both)

### **Quick Conversion Tips**

1. **Powers of 2 to memorize:**

   - 2^0 = 1, 2^1 = 2, 2^2 = 4, 2^3 = 8
   - 2^4 = 16, 2^5 = 32, 2^6 = 64, 2^7 = 128
   - 2^8 = 256, 2^9 = 512, 2^10 = 1024

2. **Character to bit position:**

   - 'a' = 0, 'b' = 1, 'c' = 2, ..., 'z' = 25
   - Formula: bit_position = character - 'a'

3. **Setting a bit:**

   - `mask |= (1 << bit_position)`

4. **Checking if bit is set:**

   - `mask & (1 << bit_position)`

5. **Checking for conflicts:**
   - `mask1 & mask2 == 0` means no conflicts

### **Visual Binary Calculator**

You can use the `binary-converter.cpp` program to convert any number:

```bash
g++ -o binary-converter binary-converter.cpp
./binary-converter
```

This helps you understand the bit manipulation magic happening in our algorithm! 🎯

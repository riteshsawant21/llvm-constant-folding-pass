# LLVM Constant Folding Pass

This project demonstrates a custom LLVM pass that performs constant folding on LLVM IR. It simplifies constant expressions like `add i32 10, 12` into a single constant `22`.

## 🛠️ Project Structure

## 📂 Files

- `passes/ConstantFoldingPass.cpp`: The main LLVM pass source code.
- `input/test.ll`: A test LLVM IR file to be optimized.
- `out/folded.ll`: The optimized IR output after running the pass.

## 🚀 How to Run

```bash
# 1. Build the pass
cd build
ninja

# 2. Run the pass
opt -load-pass-plugin ./libMyFirstPass.so \
    -passes=constant-folding-pass \
    -o out/folded.ll input/test.ll

# 3. Execute original and optimized IR
lli input/test.ll
lli out/folded.ll
Original: 0m0.111s
Optimized: 0m0.032s

Run this to create it:
```bash
nano README.md
# or use your VS Code from WSL2
code README.md



# ⚙️ LLVM Constant Folding Pass

This project demonstrates a custom **LLVM optimization pass** that performs **constant folding** on LLVM Intermediate Representation (IR). It simplifies expressions like `add i32 10, 12` into a single constant `22`, reducing runtime computation and improving performance.

---

## 📁 Project Structure

```bash
llvm-opt-project/
├── passes/
│   └── ConstantFoldingPass.cpp     # LLVM pass source code
├── input/
│   └── test.ll                     # Sample LLVM IR input
├── out/
│   └── folded.ll                  # Optimized IR output
├── llvm_dashboard.py              # Streamlit-based visual dashboard
├── CMakeLists.txt                 # CMake configuration
└── README.md                      # Project documentation
```

---

## 🚀 How to Build & Run

### ✅ 1. Build the LLVM Pass

```bash
cd build
ninja
```

> 🔧 Make sure LLVM (≥ 14) is installed and accessible via `llvm-config`.

---

### ✅ 2. Run the Pass on Sample IR

```bash
opt -load-pass-plugin ./libMyFirstPass.so \
    -passes=constant-folding-pass \
    -o out/folded.ll input/test.ll
```

This generates an optimized IR file (`folded.ll`) by folding constant expressions.

---

### ✅ 3. Compare Execution (Before vs After)

```bash
time lli input/test.ll     # Original
time lli out/folded.ll     # Optimized
```

📉 **Performance Report Example**

| Metric        | Original IR | Optimized IR |
|---------------|-------------|--------------|
| Output        |     `22`    |     `22`     |
| Real Time     |   0.111s    |    0.032s    |
| File Size     |   325B      |   1452B      |

> 🧠 The optimized IR includes metadata and folded constants.

---

### ✅ 4. Visual Dashboard (Optional but Cool 😎)

Run the interactive Python dashboard for a GUI-like experience:

```bash
streamlit run llvm_dashboard.py
```

#### 🎨 Sample Output (Streamlit GUI)

- IR File Size Table
- Execution Time Table
- Speedup Metric Display (e.g., `3.47x faster`)
- Side-by-side Bar Chart Comparison

> ✨ The dashboard offers a simple and clean visual interface for presenting your LLVM optimization results. Built using Python + Streamlit.

---

## 💡 Why This Matters

Constant folding is a fundamental compiler optimization. This pass mimics what modern compilers do under the hood. By writing it from scratch, you:

- Understand LLVM's internal architecture
- Practice IR transformations
- Get hands-on with pass development

This project can be a stepping stone to more complex LLVM transformations or compiler-based research.

---

## 📌 Requirements

- LLVM ≥ 14 with `opt` and `lli`
- Clang or GCC
- CMake + Ninja
- Python 3 (for dashboard)
- `streamlit`, `pandas` (install via `pip install streamlit pandas`)

---

## 📬 Author

**Ritesh Sawant**  
B.Tech | Embedded Systems & Compilers Enthusiast  
[GitHub](https://github.com/riteshsawant21) • [LinkedIn](https://linkedin.com/in/riteshsawant21)

---

> 🎯 *“Compilers don't just compile code, they compile your thinking.”*


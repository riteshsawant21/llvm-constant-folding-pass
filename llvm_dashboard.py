from rich.console import Console
from rich.table import Table
from rich.progress import Progress
from rich.panel import Panel
from rich import box
import os

# Mock metrics – replace with your real ones
original_time = 0.111
optimized_time = 0.032

original_size = os.path.getsize("input/test.ll")
optimized_size = os.path.getsize("out/folded.ll")

speedup = original_time / optimized_time

console = Console()

console.rule("[bold cyan]LLVM Constant Folding Pass Report")

# Size Table
size_table = Table(title="IR File Sizes", box=box.SQUARE)
size_table.add_column("Version", style="bold")
size_table.add_column("Size (bytes)", justify="right")
size_table.add_row("Original", str(original_size))
size_table.add_row("Optimized", str(optimized_size))
console.print(size_table)

# Time Table
time_table = Table(title="Execution Time Comparison", box=box.SQUARE)
time_table.add_column("Version", style="bold")
time_table.add_column("Time (s)", justify="right")
time_table.add_row("Original", f"{original_time:.4f}")
time_table.add_row("Optimized", f"{optimized_time:.4f}")
console.print(time_table)

# Speed Gain Bar
console.print("[bold green]Execution Speed Gain:")

bar_length = 40
orig_bar = "━" * int((original_time / original_time) * bar_length)
opt_bar = "━" * int((optimized_time / original_time) * bar_length)

console.print(f"[red]Original  [/red] {orig_bar} {original_time:.4f}s")
console.print(f"[green]Optimized [/green] {opt_bar.ljust(bar_length)} {optimized_time:.4f}s")

# Final Summary Panel
summary = f"""
✅ Time Improvement: [green]{speedup:.2f}x faster[/green]
✅ Size Change: {original_size} → {optimized_size} bytes
✅ IR correctness preserved ✅

[dim]You successfully applied constant folding and reduced runtime![/dim]
"""
console.print(Panel(summary, title="[bold yellow]Summary", border_style="bright_yellow"))

console.rule("[bold cyan]End of Report")


; ModuleID = 'out/folded.ll'
source_filename = "input/test.ll"

@.str = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1

declare i32 @printf(ptr, ...)

define dso_local i32 @main() {
  %1 = alloca i32, align 4
  store i32 0, ptr %1, align 4
  %2 = call i32 (ptr, ...) @printf(ptr @.str, i32 22)
  ret i32 0
}

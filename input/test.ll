@.str = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1

declare i32 @printf(ptr, ...)

define dso_local i32 @main() #0 {
entry:
  %1 = alloca i32, align 4
  store i32 0, ptr %1, align 4

  ; Will be folded to 22
  %val = add i32 10, 12
  %2 = call i32 (ptr, ...) @printf(ptr @.str, i32 %val)

  ; Will be folded to 21
  %val2 = mul i32 3, 7
  %3 = call i32 (ptr, ...) @printf(ptr @.str, i32 %val2)

  ; Will be folded to 50
  %val3 = sub i32 100, 50
  %4 = call i32 (ptr, ...) @printf(ptr @.str, i32 %val3)

  ret i32 0
}


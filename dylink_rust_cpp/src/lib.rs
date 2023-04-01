#[no_mangle]
extern "C" fn foo(i: i32) -> i32 {
    i * 12
}

#[no_mangle]
extern "C" fn fib(i: i32) -> i32 {
    if i < 2 {
	i
    } else {
	fib(i - 2) + fib(i - 1)
    }
}

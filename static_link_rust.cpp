// C++からrustの呼び出しFFI
// cppをstatic linkする場合
// rust側
// main.rs
extern "C" {
  #[link_name = "mangle_function_name"]
  pub fn foo() -> i32;
}

fn main() {
  unsafe {
    let a = foo();
    println!("{:?}", a);
  }
}

// cpp側
// test.cpp
int foo() {
  return 42;
}

// コンパイル, リンク方法
// g++ -c test.cpp -o a.o  -> a.o
// nm a.oでmangleされたc++関数をrust側で明示する
// ar crs liba.a a.o -> liba.a (頭をlibにしないとstatic link時にリンカが認識してくれない。Windowsだとならないのはなぜ)
// rustc main.rs -L. -la -> main

// rustをstatic linkする場合
// rust側
// lib.rs
#[no_mangle]
extern "C" fn foo() ->i32 {
  let a = 42;
  a
}

// rustc lib.rs --crate-type="staticlib" -> liblib.a

// cpp側
// main.cpp
#include <bits/stdc++.h>
using namespace std;

extern "C" int foo();

int main() {
  int a = foo();
  cout << a << endl;
}

// g++ -o main main.cpp -L. -llib

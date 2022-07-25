int main() {
  // register変数はレジスタに変数を配置して高速に処理できる
  // レジスタに配置できない場合は単純に
  // register修飾のない変数として処理される

  int a = 12;

  // メモリに配置しないので下のような書き方は違法
  // int *b = &a;
  // printf("%p\n", &a);
}
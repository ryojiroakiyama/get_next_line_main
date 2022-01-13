基本的にnewにあるmainとtest_caseにあるファイルでテストする
oldにmallocの回数を数えるやつ入ってるから, 時間ある時に編集して, mallco失敗ケースとも入れてnewに持ってくる

### compile
```
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files> -I <headerdir>
```

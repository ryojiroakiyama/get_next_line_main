基本的にnewにあるmainとtest_caseにあるファイルでテストする
oldにmallocを失敗させたり回数数えたりするの入れているから時間ある時にnewに持ってくる

### compile
```
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files> -I <headerdir>
```

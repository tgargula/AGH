# AGH Computer Science

## Rules
1. The repository is publicly available. If you want to be able to commit [contact me](https://www.messenger.com/t/tomasz.gargula.12).

2. If you use this repo, give a star :star:

3. We work on the branch *toCode*. We clean code there. Every once in a while we merge it into master.

4. If you would like to improve code that was written by someone else, use comments or review in pull request.

5. The code and commit messages can be written both in English and in Polish. We just try to use the same language in one file.

6. Rules can be changed.

## Tips

### Git
Clone repository:
```sh
git clone https://github.com/tgargula/AGH.git
```
Download current repository from a branch:
```sh
git pull origin toCode
```
Change branch or add it if it doesn't exist:
```sh
git checkout toCode
```
Check git status:
```sh
git status
```
Add to staging area:
```sh
git add <filename>
```
Commit with message:
```sh
git commit -m "Commit message"
```
Update branch on GitHub:
```sh
git push origin toCode
```
PS. I have changed username recently, so if old settings do not work anymore, go to your local repository and type:
```sh
git remote set-url origin https://github.com/tgargula/AGH.git
```
More commands you could find eg. [on this page](https://confluence.atlassian.com/bitbucketserver/basic-git-commands-776639767.html).

### Software
It completely does not matter, which software you use, but here are some recommendations:
* [VS Code](https://code.visualstudio.com/) – C/C++, Python, other
* [Jupyter Notebook](https://jupyter.org/try) – Python, C/C++, R, Julia, other
* Vim – Python, bash, other
* JetBrains:
    * [PyCharm](https://www.jetbrains.com/pycharm/) – Python
    * [IntelliJ](https://www.jetbrains.com/idea/) – Java, Kotlin
    * [Other](https://www.jetbrains.com)

### C/C++ compilation
To compile C file with all warnings, use:
```sh
gcc -std=c11 -O2 -Wall -Wextra -Wpedantic -Werror=implicit-function-declaration -ftrapv -ggdb3 -o [filenameWithoutExtention].out [filename] -lm
```
To compile C++ file with all warnings, use:
```sh
g++ -std=c++11 -O2 -Wall -Wextra -Wpedantic -ftrapv -ggdb3 -o [filenameWithoutExtention].out [filename] -lm
```
To check possible memory leaks, run:
```sh
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes [program].out
```
You can also use compile and memcheck scripts located in: ./archive/Sem1/UNIX or write your own script
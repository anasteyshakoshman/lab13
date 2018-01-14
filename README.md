Лабораторная работа №13

```ShellSession

$ git clone https://github.com/anasteyshakoshman/lab13

$ cmake -H. -B_builds

$ cmake --build _builds

$ cd _builds

$ ./pack person1.yml

Enter data to fields of the Person structure.
First name:
Petr↵
Last name:
Ivanov↵
Email:
ivanov_petr_97@gmail.com
Age(optional):
29↵
Phone (optional):
+7(900) 000 12-34↵

$ cat person1.yml
person:
  firstname: Ivan
  lastname: Petrov
  email: petrov_ivan_98@ya.ru
  age: 19
  phone: +7(900) 000 12-34

$ yamllint person1.yml
$
```
Если yamllint не установлен, то
```ShellSession
$ sudo apt install yamllint
```

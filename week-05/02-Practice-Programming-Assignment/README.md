#### Тренировочное задание по программированию: Отправка уведомлений ####


В этой задаче вам нужно разработать классы *SmsNotifier* и *EmailNotifier*, отправляющие уведомления в виде SMS и *e-mail* соответственно, а также абстрактный базовый класс для них.

Вам даны функции *SendSms* и *SendEmail*, которые моделируют отправку SMS и *e-mail*.

```objectivec
void SendSms(const string& number, const string& message);
void SendEmail(const string& email, const string& message);
```

Разработайте:

1. Абстрактный базовый класс *INotifier*, у которого будет один чисто виртуальный метод *void Notify(const string& message)*.
2. Класс *SmsNotifier*, который:
* является потомком класса *INotifier*;
* в конструкторе принимает один параметр типа string — номер телефона;
* переопределяет метод *Notify* и вызывает из него функцию *SendSms*.
3. Класс *EmailNotifier*, который;
* является потомком класса *INotifier*;
* в конструкторе принимает один параметр типа string — адрес электронной почты;
* переопределяет метод *Notify* и вызывает из него функцию *SendEmail*.

Пример кода для проверки:
```objectivec
#include <iostream>
#include <string>

using namespace std;

void SendSms(const string& number, const string& message) {
  cout << "Send '" << message << "' to number " << number << endl;
}

void SendEmail(const string& email, const string& message) {
  cout << "Send '" << message << "' to e-mail "  << email << endl;
}

/*
 Реализуйте здесь классы INotifier, SmsNotifier, EmailNotifier
 */

void Notify(INotifier& notifier, const string& message) {
  notifier.Notify(message);
}


int main() {
  SmsNotifier sms{"+7-495-777-77-77"};
  EmailNotifier email{"na-derevnyu@dedushke.ru"};

  Notify(sms, "I have White belt in C++");
  Notify(email, "And want a Yellow one");
  return 0;
}
```
Когда вы реализуете нужные классы, программа выше должна вывести:
```commandline
Send 'I have White belt in C++' to number +7-495-777-77-77
Send 'And want a Yellow one' to e-mail na-derevnyu@dedushke.ru
```
Уточним ещё раз, что файл, отправляемый на проверку, должен содержать реализации классов *INotifier*, *SmsNotifier*, *EmailNotifier* и не должен содержать функцию *main*.
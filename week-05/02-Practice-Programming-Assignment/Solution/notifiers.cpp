#include <iostream>
#include <string>

using namespace std;

void SendSms(const string& number, const string& message) {
  cout << "Send '" << message << "' to number " << number << endl;
}

void SendEmail(const string& email, const string& message) {
  cout << "Send '" << message << "' to e-mail " << email << endl;
}

class INotifier {
public:
  virtual void Notify(const string& message) const = 0;
};

class SmsNotifier : public INotifier {
public:
  SmsNotifier(const string& number)
    : Number(number)
  {
  }
  virtual void Notify(const string& message) const override {
    SendSms(Number, message);
  }

private:
  const string Number;
};

class EmailNotifier : public INotifier {
public:
  EmailNotifier(const string& email)
    : Email(email)
  {
  }
  virtual void Notify(const string& message) const override {
    SendEmail(Email, message);
  }

private:
  const string Email;
};

void Notify(const INotifier& notifier, const string& message) {
  notifier.Notify(message);
}

int main() {
  SmsNotifier sms{"+7-495-777-77-77"};
  EmailNotifier email{"na-derevnyu@dedushke.ru"};

  Notify(sms, "I have White belt in C++");
  Notify(email, "And want a Yellow one");
  return 0;
}

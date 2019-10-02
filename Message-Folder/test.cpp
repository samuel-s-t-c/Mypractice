#include <iostream>
#include "Message.h"

int main()
{
  Message m1("hello");
  Message m2("world");
  Folder mailbox;

  m1.print();
  m1.save(mailbox);
  mailbox.print();
  std::cout << std::endl;

  m2.print();
  m2.save(mailbox);
  mailbox.print();
  std::cout << std::endl;

  m1 = Message("bye");
  m1.print();
  mailbox.print();
}

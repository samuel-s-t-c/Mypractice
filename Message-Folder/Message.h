#ifndef MESSAGEH
#define MESSAGEH

#include <iostream>
#include <string>
#include <set>
#include "Folder.h"

class Message {
  friend class Folder;
  friend void swap(Message &lhs, Message &rhs);
public:
  //constructor
  explicit Message(const std::string &s = std::string()) : content(s) { }
  Message(const Message &rhs);
  Message(Message &&rhs);

  //destructor
  ~Message();

  //operator
  Message &operator=(const Message &rhs);
  Message &operator=(Message &&rhs);

  //
  void remove(Folder &f);
  void save(Folder &f);
  void print() {std::cout << content;}

private:
  std::string content;
  std::set<Folder*> set_ptr_folder;

  void add_to_Folders(const Message&);
  void remove_from_Folders();
  void moveFolders(Message *rhs);
  void addFolder(Folder *f) {set_ptr_folder.insert(f);}
  void remFolder(Folder *f) {set_ptr_folder.erase(f);}

};

//constructor
Message::Message(const Message &rhs)
  : content(rhs.content), set_ptr_folder(rhs.set_ptr_folder)
{
  add_to_Folders(rhs);
}

Message::Message(Message &&rhs)
  : content(std::move(rhs.content))
{
  moveFolders(&rhs);
}

//destructor
Message::~Message()
{
  remove_from_Folders();
}

//operator
Message &Message::operator=(const Message &rhs)
{
  remove_from_Folders();
  content = rhs.content;
  set_ptr_folder = rhs.set_ptr_folder;
  add_to_Folders(rhs);
  return *this;
}

Message &Message::operator=(Message &&rhs)
{
  if (this != &rhs) {
    remove_from_Folders();
    content = std::move(rhs.content);
    moveFolders(&rhs);
  }
  return *this;
}

//memberfunction
void Message::save(Folder &f)
{
  set_ptr_folder.insert(&f);
  f.addMsg(this);
}

void Message::remove(Folder &f)
{
  set_ptr_folder.erase(&f);
  f.remMsg(this);
}

void Message::moveFolders(Message *rhs)
{
  set_ptr_folder = std::move(rhs->set_ptr_folder);
  for (auto f : set_ptr_folder) {
    f->remMsg(rhs);
    f->addMsg(this);
  }
  rhs->set_ptr_folder.clear();
}

void Message::add_to_Folders(const Message &m)
{
  for (auto f : m.set_ptr_folder)
    f->addMsg(this);
}

void Message::remove_from_Folders()
{
  for (auto f : set_ptr_folder)
    f->remMsg(this);
}

//friend function
void swap(Message &lhs, Message &rhs)
{
  using std::swap;
  for (auto f : lhs.set_ptr_folder)
    f->remMsg(&lhs);
  for (auto f : rhs.set_ptr_folder)
    f->remMsg(&rhs);
  swap(lhs.set_ptr_folder, rhs.set_ptr_folder);
  swap(lhs.content, rhs.content);
  for (auto f : lhs.set_ptr_folder)
    f->addMsg(&lhs);
  for (auto f : rhs.set_ptr_folder)
    f->addMsg(&rhs);
}

//Folder class implement
//constructor
Folder::Folder(const Folder &f)
  : set_ptr_msg(f.set_ptr_msg)
{
  for (auto m : set_ptr_msg)
    m->addFolder(this);
}
//destructor
Folder::~Folder()
{
  for (auto m : set_ptr_msg)
    m->remFolder(this);
}
//member function
void Folder::add(Message &m)
{
  addMsg(&m);
  m.addFolder(this);
}

void Folder::remove(Message &m)
{
  remMsg(&m);
  m.remFolder(this);
}

void Folder::add_Messages(const Folder &f)
{
  for (auto m : f.set_ptr_msg)
    m->addFolder(this);
}

void Folder::remove_Messages()
{
  for (auto m : set_ptr_msg)
    m->remFolder(this);
}

void Folder::print()
{
  for (auto m : set_ptr_msg)
    m->print();
}

#endif

#ifndef CDRAGON_STRINGS_H
#define CDRAGON_STRINGS_H

class String {
 public:
  String(const char *str = "");

  String(const String &other);

  String(String &&other) noexcept;

  String &operator=(const String &other);

  String &operator=(String &&other) noexcept;

  ~String();

 private:
  char *m_data;
};

#endif  // CDRAGON_STRINGS_H

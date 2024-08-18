In the file `src/Misc/EmbeddedPython.ccp` line 459 was changed from

&#160;&#160;&#160;&#160;&#160;`res = QVariant(QString::fromLatin1(reinterpret_cast<const char *>PyUnicode_1BYTE_DATA(po), -1));`

to

&#160;&#160;&#160;&#160;&#160;`res = QVariant(QString::fromLatin1(reinterpret_cast<const char *>(PyUnicode_1BYTE_DATA(po)), -1));`

ie extra brackets around `PyUnicode_1BYTE_DATA(po)`

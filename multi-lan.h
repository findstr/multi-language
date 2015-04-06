#ifndef _MULTI_LAN_H
#define _MULTI_LAN_H

int multi_lang_init(const char *locale);
int multi_lang_exit();

const char *multi_get(const char *sz);

#endif

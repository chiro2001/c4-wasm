#include "c4-wasm.h"

EFILE *_out_ = NULL;

EMSCRIPTEN_KEEPALIVE
void save_file(char *filename, char *data) {
  if (!filename || !data || !*filename || !*data) return;
  // efiles_init();
  EFILE *writer = efopen(filename, "w");
  // printf("filename=%d data=%d *filename=%d *data=%d", !filename, !data,
  //        *filename, *data);
  
  if (!writer) {
    printf("save_file: could not open %s!\n", filename);
  }
  efprintf(writer, "%s", data);
  // puts("file content:");
  // puts(data);
  efclose(writer);
}

EMSCRIPTEN_KEEPALIVE
char *get_file(char *filename) {
  // efiles_init();
  EFILE *reader = efopen(filename, "r");
  if (!reader) {
    // puts("get_file: could not open file!");
    // puts(filename);
    return NULL;
  }
  // 忘记实现fseek了...
  // 先读一遍吧
  int size = 0;
  char c;
  while ((c = efgetchar(reader)) >= 0) size++;
  efclose(reader);
  // printf("size = %d\n", size);
  reader = efopen(filename, "r");
  if (!reader) return NULL;
  // 不要读取太多次...这里貌似没法free
  char *data = (char *)malloc(sizeof(char) * size);
  char *p = data;
  while ((c = efgetchar(reader)) >= 0) {
    if (c == 0) continue;
    *(p++) = c;
  }
  // while ((c = efgetchar(reader)) >= 0) *(p++) = c;
  *p = 0;
  efclose(reader);
  return data;
}

// 注意，因为暂时不能对同一个文件读写，这个只能最后读取，读取之后就会清空
EMSCRIPTEN_KEEPALIVE
char *get_out_() {
  // efiles_init();
  int c = 0;
  efiles_write(_out_, &c, sizeof(char));
  efclose(_out_);
  char *data = get_file("_out_");
  // puts("_out_:");
  // puts(data);
  // _out_ = efopen("_out_", "r");
  // efiles_delete(_out_);
  // efiles_delete("_out_");
  _out_ = efopen("_out_", "w");
  return data;
}
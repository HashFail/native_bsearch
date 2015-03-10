#include <ruby.h>

#ifndef RARRAY_PTR
#define RARRAY_PTR(ary) RARRAY(ary)->ptr
#endif
#ifndef RARRAY_LEN
#define RARRAY_LEN(ary) RARRAY(ary)->len
#endif

static ID id_cmp;

static VALUE rb_array_binary_index(int argc, VALUE* argv, VALUE self) {
  int lower = 0;
  int upper = RARRAY_LEN(self) - 1;
  if(argc == 2){
	lower = argv[0];
	upper = argv[1];
  }else if(argc == 3){
	lower = argv[1];
	upper = argv[2];
  }
  
  int i, comp;

  while(lower <= upper) {
    i = lower + (upper - lower) / 2;
    if(argc == 1 || argc == 3)
    {
      comp = NUM2INT(rb_funcall(argv[0], id_cmp, 1, rb_ary_entry(self, i)));
    }
    else
    {
      comp = NUM2INT(rb_yield_values(1, rb_ary_entry(self, i)));
    }

    if(comp == 0) {
      return LONG2NUM(i);
    } else if(comp > 0) {
      lower = i + 1;
    } else {
      upper = i - 1;
    };
  }
  return Qnil;
}

static VALUE rb_array_binary_search(int argc, VALUE* argv, VALUE self) {
  int lower = 0;
  int upper = RARRAY_LEN(self) - 1;
  if(argc == 2){
	lower = argv[0];
	upper = argv[1];
  }else if(argc == 3){
	lower = argv[1];
	upper = argv[2];
  }
  
  int i, comp;

  while(lower <= upper) {
    i = lower + (upper - lower) / 2;
    if(argc == 1)
    {
      comp = NUM2INT(rb_funcall(argv[0], id_cmp, 1, rb_ary_entry(self, i)));
    }
    else
    {
      comp = NUM2INT(rb_yield_values(1, rb_ary_entry(self, i)));
    }

    if(comp == 0) {
      return rb_ary_entry(self, i);
    } else if(comp > 0) {
      lower = i + 1;
    } else {
      upper = i - 1;
    };
  }
  return Qnil;
}

void Init_native_bsearch() {
  id_cmp = rb_intern("<=>");
  rb_define_method(rb_cArray, "native_bindex", rb_array_binary_index, -1);
  rb_define_method(rb_cArray, "native_bsearch", rb_array_binary_search, -1);
}

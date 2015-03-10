#include <ruby.h>

#ifndef RARRAY_PTR
#define RARRAY_PTR(ary) RARRAY(ary)->ptr
#endif
#ifndef RARRAY_LEN
#define RARRAY_LEN(ary) RARRAY(ary)->len
#endif

static ID id_cmp;

static int search(int argc, VALUE* argv, VALUE self) {
  int lower = 0;
  int upper = RARRAY_LEN(self) - 1;
  int i, comp;
  
  if(argc == 2){
	lower = NUM2INT(argv[0]);
	upper = NUM2INT(argv[1]);
  }else if(argc == 3){
	lower = NUM2INT(argv[1]);
	upper = NUM2INT(argv[2]);
  }

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
      return i;
    } else if(comp > 0) {
      lower = i + 1;
    } else {
      upper = i - 1;
    }
  }
  return -1;
}

static VALUE rb_array_binary_index(int argc, VALUE* argv, VALUE self) {
  return LONG2NUM(search(argc, argv, self));
}

static VALUE rb_array_binary_search(int argc, VALUE* argv, VALUE self) {
  int index = search(argc, argv, self);
  if(index == -1){
	return Qnil;  
  }
  return rb_ary_entry(self, index);
}

void Init_native_bsearch() {
  id_cmp = rb_intern("<=>");
  rb_define_method(rb_cArray, "native_bindex", rb_array_binary_index, -1);
  rb_define_method(rb_cArray, "native_bsearch", rb_array_binary_search, -1);
}

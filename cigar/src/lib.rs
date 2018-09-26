#![crate_type = "staticlib"]
#![no_std]

use core::panic::PanicInfo;
#[panic_implementation]
fn my_panic(pi: &PanicInfo) {
}

#[no_mangle]
pub extern "C" fn hello_world() {
  // this should be called from C
}

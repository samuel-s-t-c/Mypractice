global_asm!(include_str!("boot/entry64.asm"));

#[no_mangle]
extern "C" fn rust_main() -> ! {
    // console_putchar(b'O');
    // console_putchar(b'K');
    // console_putchar(b'\n');
    loop {}
}

use crate::context::TrapFrame;
use crate::timer::{clock_set_next_event, TICKS};
use riscv::register::{
    scause::{self, Exception, Interrupt, Trap},
    sepc, sscratch, sstatus, stvec,
};

global_asm!(include_str!("trap/trap.asm"));

pub fn init() {
    unsafe {
        extern "C" {
            fn __alltraps();
        }
        sscratch::write(0);
        stvec::write(__alltraps as usize, stvec::TrapMode::Direct);
        sstatus::set_sie();
    }
    println!("++++ setup interrupt! ++++");
}

#[no_mangle]
pub fn rust_trap(tf: &mut TrapFrame) {
    match tf.scause.cause() {
        Trap::Exception(Exception::Breakpoint) => breakpoint(&mut tf.sepc),
        Trap::Interrupt(Interrupt::SupervisorTimer) => super_timer(),
        _ => panic!("undefined trap!"),
    }
}

fn breakpoint(sepc: &mut usize) {
    println!("a breakpoint set @0x{:x}", sepc);
    *sepc += 2;
}

fn super_timer() {
    clock_set_next_event();
    unsafe {
        TICKS += 1;
        if (TICKS == 100) {
            TICKS = 0;
            println!("* 100 ticks *");
        }
    }
}

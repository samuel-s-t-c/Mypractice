use adder;

mod hi;

#[test]
fn it_adds_two() {
    hi::setup();
    assert_eq!(4, adder::add_two(2));
}

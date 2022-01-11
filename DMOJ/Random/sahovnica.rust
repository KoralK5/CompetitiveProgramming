#[macro_use] extern crate dmoj;
use std::io;
fn main() {
	let mut line = String::new();
	io::stdin().read_line(&mut line).expect("input");
	let a = line.trim().split(' ').flat_map(str::parse::<i32>).collect::<Vec<_>>();
	let mut line = String::new();
	io::stdin().read_line(&mut line).expect("input");
	let b = line.trim().split(' ').flat_map(str::parse::<i32>).collect::<Vec<_>>();
	for i in 0..a[0] {
		for x in 0..b[0] {
			for j in 0..a[1] {
				if (i+j)%2 == 0 {
					for r in 0..b[1] {
						print!("X");
					}
				}
				else {
					for r in 0..b[1] {
						print!(".");
					}
				}
			}
			println!();
		}
	}
}

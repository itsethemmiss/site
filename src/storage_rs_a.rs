use std::collections::HashMap;
use std::f64;

const SIZE: usize = 10000;
const THRESHOLD: f64 = 0.5;

struct DataSet {
    data: Vec<f64>,
}

impl DataSet {
    fn new(size: usize) -> Self {
        let data: Vec<f64> = (0..size)
            .map(|i| (i as f64).sin() * (i as f64).cos())
            .collect();
        DataSet { data }
    }

    fn analyze(&mut self) {
        for value in &mut self.data {
            if *value > THRESHOLD {
                *value = value.sqrt();
            } else {
                *value = value.abs().ln() + 1.0;
            }
        }
    }

    fn print_analysis(&self) {
        for (i, value) in self.data.iter().enumerate() {
            println!("Data[{}]: {:.4}", i, value);
        }
    }
}

fn main() {
    let mut ds = DataSet::new(SIZE);
    ds.analyze();
    ds.print_analysis();
}

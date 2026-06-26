fn main() {
    let mut str: String = String::new();
    println!("Enter any string from Σ={{0,1}}: ");
    std::io::stdin()
        .read_line(&mut str)
        .expect("Failed to read user input.");
    let str: String = str.trim().to_string();
    let validation: bool = str_01_validation(&str);
    match validation {
        true => {
            string_processor(&str);
            println!("The string \"{str}\" is accepted by NFA.");
        }
        false => {
            string_processor(&str);
            println!("The string \"{str}\" is not accepted by the NFA.");
        }
    };
}

fn str_01_validation(str: &str) -> bool {
    if str.len() < 2 {
        println!("Cannot accept string less than lenght 2");
        std::process::exit(1);
    }
    let mut i: usize = 0;
    while i < str.len() {
        if i != 0 {
            if (i == str.len() - 1) || (i == str.len() - 2) {
                let current_symbol: &str = &str[i..i + 1];
                let previous_symbol: &str = &str[i - 1..i];
                match (previous_symbol, current_symbol) {
                    ("0", "1") | ("1", "0") => {}
                    ("0", "0") | ("1", "1") => {
                        return false;
                    }
                    _ => {
                        println!("Cannot process string outside of Σ={{0,1}}.");
                        std::process::exit(1);
                    }
                };
            }
        } else {
            let current_symbol: &str = &str[i..i + 1];
            match current_symbol {
                "0" | "1" => {}
                _ => {
                    println!("Cannot process string outside of Σ={{0,1}}.");
                    std::process::exit(1);
                }
            };
        }
        i += 1;
    }
    return true;
}

fn string_processor(str: &str) {
    println!("Initial state: ->q0");
    println!("Final states:*q2");
    let mut current_state: &str = "->q0";
    let mut i: usize = 0;
    while i < str.len() {
        let current_symbol: &str = &str[i..i + 1];
        if (i != str.len() - 1) && (i != str.len() - 2) {
            let next_state: &str = match (current_state, current_symbol) {
                ("->q0", "0") => "->q0",
                ("->q0", "1") => "->q0",
                ("q1", "1") => "Φ",
                ("*q2", "0") | ("*q2", "1") => "Φ",
                ("q3", "0") => "Φ",
                _ => "Φ",
            };
            println!("{current_state} --- ({current_symbol}) ---> {next_state}");
            current_state = next_state;
        } else {
            let next_state: &str = match (current_state, current_symbol) {
                ("->q0", "0") => "q3",
                ("->q0", "1") => "q1",
                ("q1", "0") => "*q2",
                ("q3", "1") => "*q2",
                _ => "Φ",
            };
            println!("{current_state} --- ({current_symbol}) ---> {next_state}");
            current_state = next_state;
        }
        i += 1;
    }
}

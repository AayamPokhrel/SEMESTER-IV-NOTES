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
            println!("The string \"{str}\" is accepted by ε-NFA.");
        }
        false => {
            string_processor(&str);
            println!("The string \"{str}\" is not accepted by the ε-NFA.");
        }
    };
}

fn str_01_validation(str: &str) -> bool {
    let mut i: usize = 0;
    let mut seen_one: bool = false;

    while i < str.len() {
        let current_symbol: &str = &str[i..i + 1];

        match current_symbol {
            "0" => {
                if seen_one {
                    return false;
                }
            }
            "1" => {
                seen_one = true;
            }
            _ => {
                println!("Cannot process string outside of Σ={{0,1}}.");
                std::process::exit(1);
            }
        };

        i += 1;
    }

    return true;
}

fn string_processor(str: &str) {
    println!("Initial state: ->*q0");
    println!("Final states:*q0,*q1");
    println!("ε-transition: ->*q0 --- (ε) ---> *q1");

    let mut current_state: &str = "->*q0";
    let mut i: usize = 0;

    while i < str.len() {
        let current_symbol: &str = &str[i..i + 1];

        if current_state == "->*q0" && current_symbol == "1" {
            println!("->*q0 --- (ε) ---> *q1");
            current_state = "*q1";
        }

        let next_state: &str = match (current_state, current_symbol) {
            ("->*q0", "0") => "->*q0",
            ("*q1", "1") => "*q1",
            ("*q1", "0") => "Φ",
            ("->*q0", "1") => "*q1",
            _ => "Φ",
        };

        println!("{current_state} --- ({current_symbol}) ---> {next_state}");
        current_state = next_state;

        i += 1;
    }
}

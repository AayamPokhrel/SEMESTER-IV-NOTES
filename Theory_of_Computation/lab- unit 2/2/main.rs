fn main() {
    let mut str: String = String::new();
    println!("Choose any string from alphabet Σ={{a,b}} of at least length 4: ");
    std::io::stdin()
        .read_line(&mut str)
        .expect("Cannot read user's input");
    let str: String = str.trim().to_string();
    let validation: bool = str_ab_validation(&str);
    match validation {
        true => {
            string_processor(&str);
            println!("The string \"{str}\" is accepted by DFA.");
        }
        false => {
            string_processor(&str);
            println!("The string states towards dead state(qd), therefore \"{str}\" is not accepted by the DFA.");
        }
    };
}

fn str_ab_validation(str: &str) -> bool {
    if str.len() < 4 {
        println!("Input string length>=4.");
        std::process::exit(1);
    }
    let mut i: usize = 0;
    while i < str.len() {
        let current_symbol: &str = &str[i..i + 1];
        if i != 1 && i != 3 {
            match current_symbol {
                "a" | "b" => {}
                _ => {
                    println!("Cannot process string outside of Σ={{a,b}}.");
                    std::process::exit(1);
                }
            };
        } else if i == 1 {
            match current_symbol {
                "a" => {}
                "b" => {
                    return false;
                }
                _ => {
                    println!("Cannot process string outside of  Σ={{a,b}}.");
                    std::process::exit(1);
                }
            };
        } else if i == 3 {
            match current_symbol {
                "a" => {
                    return false;
                }
                "b" => {}
                _ => {
                    println!("Cannot process string outside of  Σ={{a,b}}.");
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
    println!("Final state: *q4");
    println!("Dead state: qd");
    println!("Processing the string \"{str}\":");
    let mut current_state: &str = "->q0";
    let mut i: usize = 0;
    while i < str.len() {
        let current_symbol: &str = &str[i..i + 1];
        let next_state: &str = match (current_state, current_symbol) {
            ("->q0", "a") => "  q1",
            ("->q0", "b") => "  q6",

            ("  q1", "a") => "  q2",
            ("  q1", "b") => "  qd",

            ("  q5", "a") => "  q6",
            ("  q5", "b") => "  qd",

            ("  q2", "a") | ("  q2", "b") => "  q3",

            ("  q6", "a") | ("  q6", "b") => "  q7",

            ("  q3", "a") => "  qd",
            ("  q3", "b") => " *q4",

            ("  q7", "a") => "  qd",
            ("  q7", "b") => " *q4",
            (" *q4", "a") | (" *q4", "b") => " *q4",

            ("  qd", "a") | ("  qd", "b") => "  qd",

            _ => "  qd",
        };
        println!("{current_state} --- ({current_symbol}) ---> {next_state}");
        current_state = next_state;
        i += 1;
    }
}

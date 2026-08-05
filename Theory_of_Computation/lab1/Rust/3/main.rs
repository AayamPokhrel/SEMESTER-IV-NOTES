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
            println!("The string \"{str}\" is accepted by DFA.");
        }
        false => {
            string_processor(&str);
            println!("The string states towards dead state(qd), therefore \"{str}\" is not accepted by the DFA.");
        }
    };
}

fn str_01_validation(str: &str) -> bool {
    let mut i: usize = 0;
    while i < str.len() {
        if i == 0 {
            let current_symbol: &str = &str[i..i + 1];
            match current_symbol {
                "0" | "1" | "ε" => {}
                _ => {
                    println!("Cannot process string outside of Σ={{0,1}}.");
                    std::process::exit(1);
                }
            };
        }
        // closing if
        else {
            let current_symbol: &str = &str[i..i + 1];
            let previous_symbol: &str = &str[i - 1..i];
            match (previous_symbol, current_symbol) {
                ("0", "1") | ("1", "0") | ("1", "1") => {}
                ("0", "0") => {
                    return false;
                }
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
    println!("Since,\"ε\" also occurs in the language (L), initial state is also one of the final state.");
    println!("Initial state: ->*q0");
    println!("Final states: ->*q0, *q1, *q2, *q3");
    println!("Dead state: qd");
    let mut current_state: &str = "->*q0";
    let mut i: usize = 0;
    while i < str.len() {
        let current_symbol: &str = &str[i..i + 1];
        let next_state: &str = match (current_state, current_symbol) {
            ("->*q0", "0") => "  *q3",
            ("->*q0", "1") => "  *q1",

            ("  *q1", "0") => "  *q2",
            ("  *q1", "1") => "->*q0",

            ("  *q2", "0") => "   qd",
            ("  *q2", "1") => "  *q1",

            ("  *q3", "0") => "   qd",
            ("  *q3", "1") => "->*q0",

            ("   qd", "0") => "   qd",
            ("   qd", "1") => "   qd",
            _ => "   qd",
        };
        println!("{current_state} --- ({current_symbol}) ---> {next_state}");
        current_state = next_state;
        i += 1;
    }
}

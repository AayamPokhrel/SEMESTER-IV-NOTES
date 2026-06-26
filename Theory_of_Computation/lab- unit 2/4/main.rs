fn main() {
    let mut str: String = String::new();
    println!("Enter any string inside your multi-line comments, Σ={{ε,/,*,_}} where _ is a comment which may include or not include \\n as a new-line.");
    use std::io::Read; //to read multi line in terminal
    std::io::stdin()
        .read_to_string(&mut str)
        .expect("Failed to read user input");
    let str: String = str.trim_end().to_string();
    let validation: bool = multi_line_comment_checker(&str);
    match validation {
        true => {
            string_processor(&str);
            println!("The comment \"{str}\" is accepted by DFA in a C-Program.");
        }
        false => {
            string_processor(&str);
            println!("Either the comment is incomplete or the comment is invalid. Therefore, \"{str}\" is not accepted by DFA as multi-line comment in C-Program");
        }
    };
}

/*
+-------+-------+------+------+
| State |   /   |  *   | _    |
+-------+-------+------+------+
|-> q0  |   q1  |  qd  |  qd  |
|   q1  |   qd  |  q2  |  qd  |
|   q3  |  *q4  |   q3 |  q2  |
|   q2  |   q2  |  q3  |  q2  |
|  *q4  |   q1  |  qd  |  qd  |
|   qd  |   qd  |  qd  |  qd  |
+-------+-------+------+------+
q1 to q2 with symbol '/' denotes single line comment which is not what this DFA accpets, so it is forwarded towards dead state for this specific DFA.
*/
fn multi_line_comment_checker(str: &str) -> bool {
    if str.is_empty() {
        return true;
    }
    if str.len() > 0 && str.len() < 4 {
        println!("Cannot process string which is not empty and its length less than 4.");
        std::process::exit(1);
    }
    let mut i: usize = 0;
    while i < str.len() {
        let current_symbol: &str = &str[i..i + 1];
        if i == 0 {
            match current_symbol {
                "/" => {}
                _ => {
                    return false;
                }
            };
        } else if i == 1 {
            match current_symbol {
                "*" => {}
                _ => {
                    // "//" this is a single line comment so we're transitioning it towards dead
                    // state
                    return false;
                }
            };
        } else if i == str.len() - 2 {
            match current_symbol {
                "*" => {}
                _ => {
                    return false;
                }
            };
        } else if i == str.len() - 1 {
            match current_symbol {
                "/" => {}
                _ => {
                    return false;
                }
            };
        }
        i += 1;
    }
    return true;
}

fn string_processor(str: &str) {
    println!("Since, \"ε\" also occurs in the language (L), initial state is also one of the final state.");
    println!("Initial state: ->*q0");
    println!("Final states: ->*q0,*q3");
    println!("Dead state: qd");
    let mut current_state: &str = "->*q0";
    let mut i: usize = 0;
    while i < str.len() {
        let current_symbol: &str = &str[i..i + 1];
        let next_state: &str = match (current_state, current_symbol) {
            ("->*q0", "/") => "   q1",
            ("->*q0", "*") | ("->*q0", _) => "   qd",
            ("   q1", "*") => "   q2",
            ("   q1", "/") | ("   q1", _) => "   qd",
            ("   q2", "*") => "   q3",
            ("   q2", "/") | ("   q2", _) => "   q2",
            ("   q3", "/") => "  *q4",
            ("   q3", "*") => "   q3",
            ("   q3", _) => "   q2",
            ("  *q4", "/") => "   q1",
            ("  *q4", "*") | ("  *q4", _) => "   qd",
            _ => "   qd",
        };
        println!("{current_state} --- ({current_symbol}) ---> {next_state}");
        current_state = next_state;
        i += 1;
    }
}

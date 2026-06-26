/* Identifiers
1. Must begin with a letter (A-Z, a-z) or an underscore (_).
2. Can contain letters, digits (0-9), and underscores (_).
3. Cannot start with a digit.
4. Cannot contain special characters or spaces.
5. Cannot be a C keyword.
6. C is case-sensitive (count and Count are different identifiers).
*/

/*
1. Keywords are reserved words predefined by the C language.
2. They have fixed meanings and cannot be redefined.
3. They cannot be used as identifiers (variable, function, array names, etc.).
4. Their spelling must be exactly as defined (C is case-sensitive).
5. Their names cannot be modified or changed by the programmer.
*/

/*
 * approach
 * -> check if it is a keyword first, if not check if it is a identifier else reject in nested match
 * -> validate keywords first
 * -> validate identifiers with rules and make sure its not a keyword
 *  -> take few keywords, like int, float, char.
 *  -> so the language becomes L {int,float,char} for keywords and {_,A..Z,a..z, 1-9(but cannot
 *  start with it, case sensitive)
 *  -> functions: main(), keyword_checker(str: &str)->bool, indentifier_checker(str: &str) -> bool,
 *                 string_processor(str: &str)
 */
fn main() {
    println!(
        "Alphabets Σ={{ε,A..Z,a..z,0..9,_}}, keywords used here = {{\"int\",\"float\",\"char\"}}"
    );

    let mut str: String = String::new();
    std::io::stdin()
        .read_line(&mut str)
        .expect("Failed to read user's input");

    str = str.trim().to_string();

    if keyword_checker(&str) {
        println!("\"{str}\" is a keyword. It is accepted by DFA. Processing the string..");
        string_processor(&str);
    } else if identifier_checker(&str) {
        println!("\"{str}\" is an identifier. It is accepted by DFA. Processing the string..");
        string_processor(&str);
    } else {
        println!("\"{str}\" is neither a keyword nor an identifier. It is rejected by DFA.");
        string_processor(&str);
    }
}

/*
 *
 */

fn keyword_checker(str: &str) -> bool {
    match str {
        "int" | "float" | "char" => {}
        _ => {
            return false;
        }
    };
    return true;
}

fn identifier_checker(str: &str) -> bool {
    let mut i: usize = 0;
    while i < str.len() {
        let current_symbol: &str = &str[i..i + 1];
        if i == 0 {
            if (current_symbol >= "A" && current_symbol <= "Z")
                || (current_symbol >= "a" && current_symbol <= "z")
                || (current_symbol == "_")
            {
            } else {
                return false;
            }
        }
        if (current_symbol >= "A" && current_symbol <= "Z")
            || (current_symbol >= "a" && current_symbol <= "z")
            || match current_symbol {
                "0" | "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9" | "_" => true,
                _ => false,
            }
        {
        } else {
            return false;
        }
        i += 1;
    }
    return true;
}

/* Transition table for keywords: int, char, float; identifiers: all

+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+------------------------------------------+------+------+
| State |   a   |   c   |   f   |   h   |   i   |   l   |   n   |   o   |   r   |   t   | A..Z,b,d,e,g,j,k,m,p,q,s,u..z,_          | SC   | 0..9 |
+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+------------------------------------------+------+------+
| ->q0  | *q13  |  q1   |  q5   | *q13  |  q10  | *q13  | *q13  | *q13  | *q13  | *q13  | *q13                                     | qd   | qd   |
| q1    | *q13  | *q13  | *q13  |  q2   | *q13  | *q13  | *q13  | *q13  | *q13  | *q13  | *q13                                     | qd   | *q13 |
| q2    |  q3   | *q13  | *q13  |  q13  | *q13  | *q13  | *q13  | *q13  | *q13  | *q13  | *q13                                     | qd   | *q13 |
| q3    | *q13  | *q13  | *q13  | *q13  | *q13  | *q13  | *q13  | *q13  | *q4   | *q13  | *q13                                     | qd   | *q13 |
| *q4   | *q13  | *q13  | *q13  | *q13  | *q13  | *q13  | *q13  | *q13  | *q13  | *q13  | *q13                                     | qd   | *q13 |
| q5    | *q13  | *q13  | *q13  | *q13  | *q13  |  q6   | *q13  | *q13  | *q13  | *q13  | *q13                                     | qd   | *q13 |
| q6    | *q13  | *q13  | *q13  | *q13  | *q13  | *q13  | *q13  |  q7   | *q13  | *q13  | *q13                                     | qd   | *q13 |
| q7    |  q8   | *q13  | *q13  | *q13  | *q13  | *q13  | *q13  | *q13  | *q13  | *q13  | *q13                                     | qd   | *q13 |
| q8    | *q13  | *q13  | *q13  | *q13  | *q13  | *q13  | *q13  | *q13  | *q13  | *q9   | *q13                                     | qd   | *q13 |
| *q9   | *q13  | *q13  | *q13  | *q13  | *q13  | *q13  | *q13  | *q13  | *q13  | *q13  | *q13                                     | qd   | *q13 |
| q10   | *q13  | *q13  | *q13  | *q13  | *q13  | *q13  | *q11  | *q13  | *q13  | *q13  | *q13                                     | qd   | *q13 |
| q11   | *q13  | *q13  | *q13  | *q13  | *q13  | *q13  | *q13  | *q13  | *q13  | *q12  | *q13                                     | qd   | *q13 |
| *q12  | *q13  | *q13  | *q13  | *q13  | *q13  | *q13  | *q13  | *q13  | *q13  | *q13  | *q13                                     | qd   | *q13 |
| *q13  | *q13  | *q13  | *q13  | *q13  | *q13  | *q13  | *q13  | *q13  | *q13  | *q13  | *q13                                     | qd   |  qd  |
| qd    | qd    | qd    | qd    | qd    | qd    | qd    | qd    | qd    | qd    | qd    | qd                                       | qd   | qd   |
+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+------------------------------------------+------+------+
*/

fn is_letter(s: &str) -> bool {
    (s >= "A" && s <= "Z") || (s >= "a" && s <= "z")
}

fn is_num_or_underscore(s: &str) -> bool {
    (s >= "0" && s <= "9") || s == "_"
}

fn string_processor(s: &str) {
    let mut current_state: &str = "->*q0";
    let mut i: usize = 0;

    while i < s.len() {
        let current_symbol: &str = &s[i..i + 1];
        let next_state: &str = match (current_state, current_symbol) {
            ("->*q0", "i") => "q10",
            ("q10", "n") => "q11",
            ("q11", "t") => "*q12",

            ("->*q0", "c") => "q1",
            ("q1", "h") => "q2",
            ("q2", "a") => "q3",
            ("q3", "r") => "*q4",

            ("->*q0", "f") => "q5",
            ("q5", "l") => "q6",
            ("q6", "o") => "q7",
            ("q7", "a") => "q8",
            ("q8", "t") => "*q9",

            ("*q4", _) | ("*q9", _) | ("*q12", _) | ("*q13", _)
                if is_num_or_underscore(current_symbol) || is_letter(current_symbol) =>
            {
                "*q13"
            }

            ("->*q0", _) if is_letter(current_symbol) || current_symbol == "_" => "*q13",

            ("q1", _)
            | ("q2", _)
            | ("q3", _)
            | ("q5", _)
            | ("q6", _)
            | ("q7", _)
            | ("q8", _)
            | ("q10", _)
            | ("q11", _)
                if is_letter(current_symbol) || is_num_or_underscore(current_symbol) =>
            {
                "*q13"
            }

            ("->*q0", _) if current_symbol >= "0" && current_symbol <= "9" => "qd",
            (_, _) if current_symbol >= "0" && current_symbol <= "9" => {
                if current_state == "*q13" {
                    "*q13"
                } else {
                    "qd"
                }
            }

            (_, _) if current_symbol == " " || current_symbol == "\n" || current_symbol == "\t" => {
                "qd"
            }
            _ => "qd",
        };

        println!("{current_state} --- ({current_symbol}) ---> {next_state}");
        current_state = next_state;
        i += 1;
    }
}

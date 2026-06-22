fn main() {
    let mut str: String = String::new();
    println!("Enter any string: ");
    std::io::stdin()
        .read_line(&mut str)
        .expect("Failed to read user input");
    let str = str.trim();
    let strlen: usize = str.len();
    //prefix
    println!("Prefixes for string \"{str}\":");
    for i in 0..=strlen {
        if i == 0 {
            println!("ε");
        } else {
            let prefix = &str[0..i];
            println!("{prefix}");
        }
    }
    //Suffix
    println!("Suffixes for string \"{str}\":");
    for i in 0..=strlen {
        if i == strlen {
            println!("ε");
        } else {
            let suffix = &str[i..strlen];
            println!("{suffix}");
        }
    }
    //Substring
    /*
     umm, lets suppose string is "Aayam"
    then
    Aayam
    i=0 to j=0
    E
    i=0 to j=1
    A
    0 2
    Aa
    0 3
    Aay
    0 4
    Aaya
    0 5
    Aayam
    1 2
    a
    1 3
    ay
    1 4
    aya
    1 5
    ayam
    2 3
    y
    2 4
    ya
    2 5
    yam
    3 4
    a
    3 5
    am
    4 5
    m

    to print first epsilon i == j
    i goes to strlen-1
    on i=0 j=0..5(strlen)
    on i=1 j=2..5
    on i=2 j=3..5
    on i=3 j=4..5
    on i=4 j=5..5
      */
    println!("Substrings for string \"{str}\":");
    for i in 0..=strlen - 1 {
        if i == 0 {
            for j in 0..=strlen {
                if j == i {
                    println!("ε");
                } else {
                    let substring = &str[i..j];
                    println!("{substring}");
                }
            }
        } else {
            for j in i+1..=strlen {
                let substring = &str[i..j];
                println!("{substring}");
            }
        }
    }
}

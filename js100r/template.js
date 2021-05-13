// Exercise 1
function reduceFraction(num, den) {
    let diff;
    const min = Math.min(num, den);
    for (let i = min; i > 0; i--) {
        if (num % i === 0 && den % i === 0) {
            diff = i;
            break;
        }
    }
    return [num / diff, den / diff];
}


// Exercise 2
function isMagicDate(day, month, year) {
    return (day * month) === (year % 100);
}

// Exercise 3
function sublist(l) {
    var result = []
    for (var i = 0; i < l.length; i++) {
        var t = []
        for (var j = i; j < l.length; j++) {
            t = t.concat(l[j])
            result.push(t)
        }
    }
    result.push([])
    return result
}

// Exercise 4
function pigLatin(word) {
    var sentence = word;
    if (sentence.charAt(0) === 'a'
        || sentence.charAt(0) === 'e'
        || sentence.charAt(0) === 'i'
        || sentence.charAt(0) === 'o'|| sentence.charAt(0) === 't'
        || sentence.charAt(0) === 'u' || sentence.charAt(0) === 'A'
        || sentence.charAt(0) === 'E'
        || sentence.charAt(0) === 'I'
        || sentence.charAt(0) === 'O'
        || sentence.charAt(0) === 'U') {
        return sentence.concat("w", "a", "y");  //调用concat()连接字符串
    } else {
        var length = sentence.length;
        for (var i = 0; i < sentence.length; i++) {
            if (sentence.charAt(0) === 'a'
                || sentence.charAt(0) === 'e'
                || sentence.charAt(0) === 'i'
                || sentence.charAt(0) === 'o'|| sentence.charAt(0) === 't'
                || sentence.charAt(0) === 'u' || sentence.charAt(0) === 'A'
                || sentence.charAt(0) === 'E'
                || sentence.charAt(0) === 'I'
                || sentence.charAt(0) === 'O'
                || sentence.charAt(0) === 'U') {
                break;
            }
            sentence = sentence + sentence.charAt(i);
        }
        sentence = sentence.substring(i, length - 1);
        length = sentence.length;
        let fir=sentence.charAt(0).toUpperCase;
        sentence = sentence.substring(1, length - 1);
        sentence = fir+sentence;
        return sentence.concat("a", "y");
    }
}

// Exercise 5
function morseCode(message) {
    var alphabet = {
        'a': '.-', 'b': '-...', 'c': '-.-.', 'd': '-..',
        'e': '.', 'f': '..-.', 'g': '--.', 'h': '....',
        'i': '..', 'j': '.---', 'k': '-.-', 'l': '.-..',
        'm': '--', 'n': '-.', 'o': '---', 'p': '.--.',
        'q': '--.-', 'r': '.-.', 's': '...', 't': '-',
        'u': '..-', 'v': '...-', 'w': '.--', 'x': '-..-',
        'y': '-.--', 'z': '--..', ' ': ' ',
        '1': '.----', '2': '..---', '3': '...--', '4': '....-',
        '5': '.....', '6': '-....', '7': '--...', '8': '---..',
        '9': '----.', '0': '-----',
    }
    var msg = message
    return msg.split('').map(function (e) {
        return alphabet[e.toLowerCase()] || '';
    }).join(' ').replace(/ +/g, ' ').replace(/(\s*$)/g, "");
}

// Exercise 6
var unary = ["", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"]// one letter
var partial = ["twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"];// for decades
var pastTen = ["ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"];// 10-11
function int2Text(num) {
    return hundred(parseInt(num / 100)) + remain(num % 100, parseInt(num / 100));
}

function hundred(num) {
    return (num ? unary[num] + " hundred" : "");
}

function remain(num, and) {
    var space = (and && num) ? " " : "";
    if (num < 20) {
        return space + (num < 10 ? unary[num] : pastTen[num % 10]);
    } else return space + partial[parseInt(num / 10) - 2] + (num % 10 ? " " + unary[num % 10] : '');
}

// Exercise 7
function missingComment(filename) {
    var fso = new ActiveXObject("Scripting.FileSystemObject");
    var f = fso.OpenTextFile(filename, 1);
    var s = "";
    while (!f.AtEndOfStream) {
        if (f.ReadLine() === "//") {
            f.ReadLine()
        } else {
            s += f.ReadLine() + "\n";
        }
    }
    f.Close();
    return s;
}

// Exercise 8
function consistentLineLength(filename, length) {
    var fso = new ActiveXObject("Scripting.FileSystemObject");
    var f = fso.OpenTextFile(filename, 1);
    var res = [];
    i = 0;
    while (!f.AtEndOfStream) {
        res[i] = f.ReadLine().substring(0, length - 1);
        i++;
    }
    f.Close();
    return res;
}

// // Exercise 9
// function knight(start, end, moves) {
//     return undefined
// }
//
// // Exercise 10
// function warOfSpecies(environment) {
//     return undefined
// }

module.exports = {
    reduceFraction: reduceFraction,
    isMagicDate: isMagicDate,
    sublist: sublist,
    pigLatin: pigLatin,
    morseCode: morseCode,
    int2Text: int2Text,
    missingComment: missingComment,
    consistentLineLength: consistentLineLength,
    // knight: knight,
    // warOfSpecies: warOfSpecies
}
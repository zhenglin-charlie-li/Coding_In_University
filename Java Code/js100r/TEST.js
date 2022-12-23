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
            if (sentence.charAt(0) !== 'a'
                || sentence.charAt(0) !== 'e'
                || sentence.charAt(0) !== 'i'
                || sentence.charAt(0) !== 'o'|| sentence.charAt(0) !== 't'
                || sentence.charAt(0) !== 'u' || sentence.charAt(0) !== 'A'
                || sentence.charAt(0) !== 'E'
                || sentence.charAt(0) !== 'I'
                || sentence.charAt(0) !== 'O'
                || sentence.charAt(0) !== 'U') {
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


console.log(pigLatin("Science"))
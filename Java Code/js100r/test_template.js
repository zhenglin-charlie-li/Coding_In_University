var expect = require('chai').expect;

var funcsToTest = require("./template");

describe("reduceFraction()", () => {
    it("should return [4,5] when given the input (12, 15)", () => {
        expect(funcsToTest.reduceFraction(12, 15)).to.be.eql([4,5]);
    });
    it("should return [3,7] when given the input (3, 7)", () => {
        expect(funcsToTest.reduceFraction(3, 7)).to.be.eql([3,7]);
    });
    it("should return [1,2] when given the input (8, 16)", () => {
        expect(funcsToTest.reduceFraction(8, 16)).to.be.eql([1,2]);
    });
});


describe("isMagicDate()", () => {
    it("should return true when given the input (10, 6, 1960)", () => {
        expect(funcsToTest.isMagicDate(10, 6, 1960)).to.be.equal(true);
    });
    it("should return true when given the input (3, 4, 2012)", () => {
        expect(funcsToTest.isMagicDate(3, 4, 2012)).to.be.equal(true);
    });
    it("should return false when given the input (4, 12, 2020)", () => {
        expect(funcsToTest.isMagicDate(4, 12, 2020)).to.be.equal(false);
    });
});

describe("sublist()", () => {
    it("should return the correct list given the input(['a', 1])", () => {
        expect(funcsToTest.sublist(["a", 1])).to.have.deep.members([[], ["a"], [1], ["a", 1]]);
    });
    it("should return the correct list given the input([1, 2, 3, 4])", () => {
        expect(funcsToTest.sublist([1, 2, 3, 4])).to.have.deep.members([
            [],
            [1],
            [2],
            [3],
            [4],
            [1, 2],
            [2, 3],
            [3, 4],
            [1, 2, 3],
            [2, 3, 4],
            [1, 2, 3, 4],
        ]);
    });
    it("should return the correct list given the input(['a', 2, (0, 'zero')])", () => {
        expect(funcsToTest.sublist(["a", 2, (0, "zero")])).to.have.deep.members([
            [],
            ["a"],
            [2],
            [(0, "zero")],
            ["a", 2],
            [2, (0, "zero")],
            ["a", 2, (0, "zero")],
        ]);
    });
});

describe("pigLatin()", () => {
    it("should return 'omputercay' when given the input 'computer' ", () => {
        expect(funcsToTest.pigLatin("computer")).to.be.eql("omputercay");
    });
    it("should return 'inkthay' when given the input 'think' ", () => {
        expect(funcsToTest.pigLatin("think")).to.be.eql("inkthay");
    });
    it("should return 'algorithmway' when given the input 'algorithm' ", () => {
        expect(funcsToTest.pigLatin("algorithm")).to.be.eql("algorithmway");
    });
    it("should return 'officeway' when given the input 'office' ", () => {
        expect(funcsToTest.pigLatin("office")).to.be.eql("officeway");
    });
    it("should return 'Omputercay' when given the input 'Computer' ", () => {
        expect(funcsToTest.pigLatin("Computer")).to.be.eql("Omputercay");
    });
    it("should return 'Iencescay!' when given the input 'Science!' ", () => {
        expect(funcsToTest.pigLatin("Science!")).to.be.eql("Iencescay!");
    });
});

describe("morseCode()", () => {
    it("should return '.... . .-.. .-.. --- .-- --- .-. .-.. -..' when given the input 'Hello, World!'", () => {
        expect(funcsToTest.morseCode("Hello, World!")).to.be.eql(".... . .-.. .-.. --- .-- --- .-. .-.. -..");
    });
    it("should return '- . ... - .. -. --. .---- ..--- ...-- - . ... - .. -. --.' when given the input 'Testing, 1, 2, 3, Testing!'", () => {
        expect(funcsToTest.morseCode("Testing, 1, 2, 3, Testing!")).to.be.eql("- . ... - .. -. --. .---- ..--- ...-- - . ... - .. -. --.");
    });
    it("should return '.---- .. ... --- -. . ..--- .. ... - .-- ---' when given the input '1 is one! 2 is two?'", () => {
        expect(funcsToTest.morseCode("1 is one! 2 is two?")).to.be.eql(".---- .. ... --- -. . ..--- .. ... - .-- ---");
    });
});

describe("int2Text()", () => {
    it("should return 'one hundred forty two' when given the input 142", () => {
        expect(funcsToTest.int2Text(142)).to.be.eql("one hundred forty two");
    });
    it("should return 'three hundred' when given the input 300", () => {
        expect(funcsToTest.int2Text(300)).to.be.eql("three hundred");
    });
    it("should return 'sixteen' when given the input 16", () => {
        expect(funcsToTest.int2Text(16)).to.be.eql("sixteen");
    });
    it("should return 'nine hundred twelve' when given the input 912", () => {
        expect(funcsToTest.int2Text(912)).to.be.eql("nine hundred twelve");
    });
});

describe("missingComment()", () => {
    it("should return ['init', 'overdrawn'] when given the input 'code1.js'", () => {
        expect(funcsToTest.missingComment('js/test_data/code1.js')).to.have.deep.members(['init', 'overdrawn']);
    });
    it("should return [] when given the input 'code2.js'", () => {
        expect(funcsToTest.missingComment('js/test_data/code2.js')).to.have.deep.members([]);
    });
});

describe("consistentLineLength()", () => {
    it("should return the right text when given the input 'text1.txt'", () => {
        expect(funcsToTest.consistentLineLength('js/test_data/text1.txt', 50)).to.have.deep.members(['Alice was beginning to get very tired of sitting', 'by her sister on the bank, and of having nothing', 'to do: once or twice she had peeped into the book', 'her sister was reading, but it had no pictures or', 'conversations in it,"and what is the use of a', 'book," thought Alice, "without pictures or', 'conversations?"']);
    });
    it("should return the right text when given the input 'text1.txt'", () => {
        expect(funcsToTest.consistentLineLength('js/test_data/text1.txt', 20)).to.have.deep.members(['Alice was beginning', 'to get very tired of', 'sitting by her', 'sister on the bank,', 'and of having', 'nothing to do: once', 'or twice she had', 'peeped into the book', 'her sister was', 'reading, but it had', 'no pictures or', 'conversations in', 'it,"and what is the', 'use of a book,"', 'thought Alice,', '"without pictures or', 'conversations?"']);
    });
});

// describe("knight()", () => {
//     it("should return true when given the input ('a1', 'c5', 2)", () => {
//         expect(funcsToTest.knight("a1", "c5", 2)).to.be.equal(true);
//     });
//     it("should return true when given the input ('c2', 'e3', 3)", () => {
//         expect(funcsToTest.knight("c2", "e3", 3)).to.be.equal(true);
//     });
//     it("should return false when given the input ('c6', 'h1', 3)", () => {
//         expect(funcsToTest.knight("c6", "h1", 3)).to.be.equal(false);
//     });
// });
//
// describe("warOfSpecies()", () => {
//     it('should return ["XXX.....", "XXX..OOO", "XX....O."] when given the input (["XX......", "XX....O.", ".....OOO"])', () => {
//         expect(funcsToTest.warOfSpecies(["XX......", "XX....O.", ".....OOO"])).to.have.deep.members(["XXX.....", "XXX..OOO", "XX....O."]);
//     });
//     it('should return ["XXX...", "XXOOOO", "......"] when given the input (["XX....", "XX....", "OOOOOO"])', () => {
//         expect(funcsToTest.warOfSpecies(["XX....", "XX....", "OOOOOO"])).to.have.deep.members(["XXX...", "XXOOOO", "......"]);
//     });
//     it('should return ["XX.OOO", "XX....", "XXOOOO"] when given the input (["XXX...", "XXOOOO", "......"])', () => {
//         expect(funcsToTest.warOfSpecies(["XXX...", "XXOOOO", "......"])).to.have.deep.members(["XX.OOO", "XX....", "XXOOOO"]);
//     });
// });
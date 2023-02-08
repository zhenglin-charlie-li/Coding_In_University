import { XMLParser } from 'fast-xml-parser';

const xmlFile = ``;

const parser = new XMLParser();
const json = parser.parse(xmlFile);
const array = json.aaaa.bbbb.cccc.dddd.eeee;
array.forEach((element) => {
  if (element.name === 'xxxxx') {
    console.log(JSON.parse(element.k_AnswerDataKifResponse));
  }
  if (element.name === 'xxxxxx') {
  }
});

export {};

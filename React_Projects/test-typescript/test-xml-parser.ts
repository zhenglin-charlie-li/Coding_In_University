import { DOMParserImpl as dom } from 'xmldom-ts';
import * as xpath from 'xpath-ts';
import fetch from 'electron-fetch';
import * as fs from 'fs';
import { type } from 'os';

// const xpath = require('xpath'), dom = require('xmldom').DOMParser
// const fetch = require('electron-fetch').default
async function test_parser_xml(url: string) {
  let requestURL = encodeURI(url);
  let xmlString = await fetch(requestURL).then((r) => r.text());

  try {
  } catch (e) {
    console.log(e);
  }
}

test_parser_xml('xxxxxxx').then((r) => console.log(r));

export {};

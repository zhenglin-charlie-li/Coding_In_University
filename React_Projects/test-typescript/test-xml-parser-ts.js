"use strict";
exports.__esModule = true;
var xmldom_ts_1 = require("xmldom-ts");
var xpath = require("xpath-ts");
var xml = '<book><title>Harry Potter</title></book>';
var doc = new xmldom_ts_1.DOMParserImpl().parseFromString(xml);
var nodes = xpath.select('//title', doc);
console.log(nodes[0].localName + ': ' + nodes[0].firstChild.data);
console.log('Node: ' + nodes[0].toString());

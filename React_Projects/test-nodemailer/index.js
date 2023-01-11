'use strict';
import nodemailer from 'nodemailer';
import dotenv from 'dotenv';

// async..await is not allowed in global scope, must use a wrapper
async function main() {
  dotenv.config();
  var smtp = process.env.SMTP;
  var mailFrom = process.env.SENDER;
  var mailPwd = process.env.PASSWORD;
  console.log(smtp);
  console.log(mailFrom);
  console.log(mailPwd);
  // Generate test SMTP service account from ethereal.email
  // Only needed if you don't have a real mail account for testing
  let testAccount = await nodemailer.createTestAccount();

  // create reusable transporter object using the default SMTP transport
  let transporter = nodemailer.createTransport({
    host: smtp,
    port: 465,
    secure: true, // true for 465, false for other ports
    auth: {
      user: mailFrom, // generated ethereal user
      pass: mailPwd, // generated ethereal password
    },
    ignoreTLS: true, // add this
    tls: {
      rejectUnAuthorized: true,
    },
  });

  // send mail with defined transport object
  let info = await transporter.sendMail({
    from: '"Fred Foo 👻" <1125806272@qq.com>', // sender address
    to: '1125806272@qq.com, nodemailer@zhenglinli.me', // list of receivers
    subject: 'Hello ✔', // Subject line
    text: 'Hello world?111', // plain text body
    html: '<b>Hello world?</b>', // html body
  });

  console.log('Message sent: %s', info.messageId);
  // Message sent: <b658f8ca-6296-ccf4-8306-87d57a0b4321@example.com>

  // Preview only available when sending through an Ethereal account
  console.log('Preview URL: %s', nodemailer.getTestMessageUrl(info));
  // Preview URL: https://ethereal.email/message/WaQKMgKddxQDoou...
}

main().catch(console.error);

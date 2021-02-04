var express = require('express');
const db = require('../mod/db.js');
var router = express.Router();
var mod = require('../mod/mod.js');
var mod2 = require('../mod/mod2.js');
var dup = require('../mod/dupli.js');
var bcrypt = require('bcrypt');
const bodyParser = require('body-parser')
router.use(bodyParser.urlencoded({ extended: false }))

router.get('/',function(req,res){
    var dbpost=db.get('post').value();
    var body=mod2.square(dbpost,req.user.nickname,req.user.id);
    var html=mod.HTML('비밀게시판','',body);
    res.send(html);
})

router.get('/write',function(req,res){
    var body=mod2.write();
    var html=mod.HTML('글 쓰기','write',body);
    res.send(html);
})
router.post('/write',function(req,res){
    var post=req.body;
    var now=new Date();
    db.get('post').push({
        no:req.user.write+1,
        title:post.title,
        maintxt:post.maintxt,
        data:now,
        author:req.user.nickname,
        id:req.user.id
    }).write();
    db.get('users').find({
        key:req.user.key
    }).assign({
        write:req.user.write+1
    }).write();
    res.redirect('/square')
})
router.get('/:postno',function(req,res){
    var num=Number(req.params.postno);
    console.log(num)
    var post=db.get('post').find({
        no:num
    }).value();
    res.send(post.maintxt);
})
module.exports=router;
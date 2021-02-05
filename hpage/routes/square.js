var express = require('express');
const db = require('../mod/db.js');
var router = express.Router();
var mod = require('../mod/mod.js');
var mod2 = require('../mod/mod2.js');
var dup = require('../mod/dupli.js');
var bcrypt = require('bcrypt');
const bodyParser = require('body-parser');
const { route } = require('./home.js');
router.use(bodyParser.urlencoded({ extended: false }))

router.get('/',function(req,res){
    var dbpost=db.get('post').value();
    var body=mod2.square(dbpost,req.user.nickname,req.user.id);
    var html=mod.HTML('비밀게시판','',body);
    res.send(html);
})

router.get('/write',function(req,res){
    var body=mod2.write('','');
    var html=mod.HTML('글 쓰기','write',body);
    res.send(html);
})
router.post('/write',function(req,res){
    var post=req.body;
    var dt= new Date;
    var month=(dt.getMonth()+1);
    if (month < 10 && month[0] != '0' && month != '') month = '0' + month;
    var day=dt.getDay();
    if (day < 10 && day[0] != '0' && day != '') day = '0' + day;
    var now = month+'/'+day;
    db.get('post').push({
        no:req.user.write+1,
        title:post.title,
        maintxt:post.maintxt,
        date:now,
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
    var post=db.get('post').find({
        no:num
    }).value();
    var body=mod2.post(post.title,post.maintxt,num);
    var html=mod.HTML(`글 보기-${post.title}`,'',body);

    res.send(html);
})
router.post('/modify',function(req,res){
    var post=req.body;
    var body=mod2.write(post.title,post.maintxt,post.num)+
    `<script>$('#post').attr('action','/square/modify_');
    $('#cancel').attr('onclick','window.history.back()')</script>`;
    var html=mod.HTML(`글 수정-${post.title}`,'write',body)
    res.send(html);
})
router.post('/modify_',function(req,res){
    var post=req.body
    db.get('post').find({
        no:Number(post.num)
    }).assign({
        title:post.title,
        maintxt:post.maintxt
    }).write();
    res.redirect(`/square/${post.num}`);
})
module.exports=router;
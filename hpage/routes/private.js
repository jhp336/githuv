var express = require('express');
const db = require('../mod/db.js');
var router = express.Router();
var mod = require('../mod/mod.js');
var mod2 = require('../mod/mod2.js');
const bodyParser = require('body-parser');
router.use(bodyParser.urlencoded({ extended: false }))

router.get('/',function(req,res){
    var dbpost=db.get('secret').filter({
        id:req.user.id
    }).value();
    var body=mod2.square(dbpost,req.user.nickname,req.user.id,'private')
    var html=mod.HTML('비밀게시판','',body);
    res.send(html);
})
router.get('/write',function(req,res){
    var body=mod2.write('','')+
    `<script>$('#post').attr('action','/private/write');</script>`;
    var html=mod.HTML('비밀글 쓰기','write',body);
    res.send(html);
})
router.post('/write',function(req,res){
    var post=req.body;
    var dt= new Date;
    var month=(dt.getMonth()+1);
    if (month < 10 && month[0] != '0' && month != '') month = '0' + month;
    var day=dt.getDate();
    if (day < 10 && day[0] != '0' && day != '') day = '0' + day;
    var now = month+'/'+day;
    var prvpost=db.get('secret').filter({
        id:req.user.id,
    }).value();
    db.get('secret').push({
        no:prvpost.length+1,
        title:post.title,
        maintxt:post.maintxt,
        date:now,
        author:req.user.nickname,
        id:req.user.id,
    }).write();
    db.get('users').find({
        key:req.user.key
    }).assign({
        prvwrite:req.user.prvwrite+1
    }).write();
    res.redirect('/private')
})
router.get('/:postno',function(req,res){
    var num=Number(req.params.postno);
    var post=db.get('secret').find({
        no:num,
        id:req.user.id,
    }).value();
    var body=mod2.post(post.title,post.maintxt,num,'private');
    var html=mod.HTML(`비밀글 보기-${post.title}`,'write',body);

    res.send(html);
})
router.post('/modify',function(req,res){
    var post=req.body;
    var body=mod2.write(post.title,post.maintxt,post.num)+
    `<script>$('#post').attr('action','/private/modify_');</script>`;
    var html=mod.HTML(`글 수정-${post.title}`,'write',body)
    res.send(html);
})
router.post('/modify_',function(req,res){
    var post=req.body
    db.get('secret').find({
        no:Number(post.num),
        id:req.user.id,
    }).assign({
        title:post.title,
        maintxt:post.maintxt
    }).write();
    res.redirect(`/private/${post.num}`);
})
router.post('/delete',function(req,res){
    var post=req.body;
    db.get('secret').remove({
        no:Number(post.num),
        id:req.user.id
    }).write();
    db.get('users').find({
        key:req.user.key
    }).assign({
        prvwrite:req.user.prvwrite-1
    }).write();
    res.send(`<script>alert('삭제되었습니다!');location.href='/private'</script>`)
})
module.exports=router;
var express = require('express');
var router=express.Router();
var mod=require('../mod/mod.js');
var db=require('../mod/db.js');
var dup=require('../mod/dupli.js');
const bodyParser = require('body-parser')
router.use(bodyParser.urlencoded({extended:false}))


router.get('/login',function(req,res){
    var flash=req.flash();
    var msg='';
    if(flash.error){
        msg=flash.error;
    }
    var body=mod.LOGIN(msg);
    var html=mod.HTML('로그인','login',body);
    res.send(html);
});   
router.get('/newaccount',function(req,res){
    var body=mod.NEWACC();
    var html=mod.HTML('회원가입','newaccount',body);
    res.send(html);
});   
router.get('/findidpw',function(req,res){
    var body=mod.FINDIDPW();
    var html=mod.HTML('아이디/비번 찾기','findidpw',body);
    res.send(html);
});   
router.post('/newaccount',function(req,res){
    res.send(dup(req,'닉네임','nickname'));
})
router.post('/newaccount_',function(req,res){
    res.send(dup(req,'아이디','id'));
})
router.post('/findidpw',function(req,res){
    var post=req.body;
    var name=post.name;
    var nick=post.nickname;
    var id=post.id;
    var user='';
    var body='';
    var html='';
    if(!id){
        var user=db.get('users').find({
            name:name,
            nickname:nick
        }).value();
        if(!user)
        body=mod.FINDIDPW('아이디','해당 이름, 닉네임으로 가입한 계정이 없습니다!');      
        else body=mod.FINDIDPW('아이디',user.id);
        html=mod.HTML('아이디/비번 찾기','findidpw',body);
        res.send(html);
        return;
    }
    user=db.get('users').find({
        name:name,
        id:id
    }).value();
    if(!user)
    body=mod.FINDIDPW('비밀번호','해당 이름, 아이디로 가입한 계정이 없습니다!'); 
    else body=mod.FINDIDPW('비밀번호',user.password);
    html=mod.HTML('아이디/비번 찾기','findidpw',body);
    res.send(html);
})

module.exports=router;
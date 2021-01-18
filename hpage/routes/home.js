var express = require('express');
var router=express.Router();
var mod=require('../mod/mod.js');

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


module.exports=router;
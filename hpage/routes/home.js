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
    var html=mod.HTML('login',body);
    res.send(html);
});   
router.get('/newaccount',function(req,res){
    var body=mod.NEWACC();
    var html=mod.HTML('newaccount',body);
    res.send(html);
});   
router.get('/findidpw',function(req,res){
    var body=mod.FINDIDPW();
    var html=mod.HTML('findidpw',body);
    res.send(html);
});   


module.exports=router;
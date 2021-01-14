var express = require('express');
var router=express.Router();
var mod=require('../mod/mod.js');

router.get('/',function(req,res){
    var flash=req.flash();
    var feedback='';
    if(flash.error){
        feedback=flash.error[0];
    }
    var body=mod.LOGIN(feedback);
    var html=mod.HTML('login',body);
    res.send(html);
});
module.exports=router;
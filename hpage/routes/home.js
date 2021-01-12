var express = require('express');
var router=express.Router();
var mod=require('../mod/mod.js');



router.get('/:page',function(req,res){
    var title=req.params.page;
    if(title!="login"&&title!="newaccount"&&title!="findidpw")
    next(err);
    var body=mod.BODY(title);
    var html=mod.HTML(title,body);
    res.send(html);
});   


module.exports=router;
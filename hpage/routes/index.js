var express = require('express');
var router=express.Router();
var mod=require('../mod/mod.js');

router.get('/',function(req,res){
    var title="login";
    var body=mod.BODY(title);
    var html=mod.HTML(title,body);
    res.send(html);
});
module.exports=router;
var express = require('express');
var router=express.Router();
var mod=require('../mod/mod.js');
var USER=require('../userinf/user.js')

router.get('/:page',function(req,res){
    var title=req.params.page;
    if(title!="login"&&title!="newaccount"&&title!="findidpw")
    next(err);
    var body=mod.BODY(title);
    var html=mod.HTML(title,body);
    res.send(html);
});   

router.post('/login_process',function(req,res){

})
router.post('/join_process',function(req,res){
    var user=req.body;
    var newacc={
        name:user.name,
        id:user.id,
        pw:user.pw,
        question:user.quest,
        directq:user.direct_q,
        year:user.year,
        month:user.month,
        day:user.day,
        sex:user.sex
    }
    user=new USER(newacc);
    user.save();
})
module.exports=router;
var express = require('express');
var router=express.Router();
const bodyParser = require('body-parser')
router.use(bodyParser.urlencoded({extended:false}))
var shortid=require('shortid');
var db=require('../mod/db.js');
var mod=require('../mod/mod.js');


module.exports=function(passport) {
    router.post('/join',function(req,res){
    var post=req.body;
    var nick=post.nickname;
    var name=post.name;
    var id=post.id;
    var pw=post.pw;
    var quest=post.quest;
    var direct=post.direct_q;
    var ans=post.ans;
    var year=post.year;
    var month=post.month;
    var day=post.day;
   // var joinday,visit,post,comment;
    var userinf={
        key:shortid.generate(),
        nickname:nick,
        name:name,
        id:id,
        password:pw,
        question:quest,
        direct:direct,
        answer:ans,
        year:year,
        month:month,
        day:day
    }
    db.get('users').push(userinf).write();
    req.login(userinf,function(err){
        req.session.save(function(){
            res.redirect('/auth/welcome');
        });
    })
})

router.post('/login',
    passport.authenticate('local', { 
        successRedirect: '/',
        failureRedirect: '/home/login',
        failureFlash:true
    })
);
    
router.get('/logout',function(req,res){
    req.logout();
    req.session.save(function(){
        res.redirect('/home/login');
    })
});

router.post('/findidpw_process',function(req,res){
    var post=req.body;
    var name=post.name;
    var id=post.id;
    var user='';
    var body='';
    var html='';
    if(!id){
        var user=db.get('users').find({
            name:name
        }).value();
        if(!user)
        body=mod.FINDIDPW('아이디','해당 이름으로 가입한 계정이 없습니다!');      
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

router.get('/welcome',function(req,res){
    html=`
    <!DOCTYPE html>
        <html>
            <head>
                <link rel="stylesheet" href="/css/style.css">
                <meta charset="utf-8">
                <title>Welcome</title>
            </head>
        <body >
            <header>
            <h1>환영합니다!</h1>
            <p><a href="/">메인 화면으로</a></p>         
            </header>
        </body>
        </html>
    `
    res.send(html);
})

    return router;
}
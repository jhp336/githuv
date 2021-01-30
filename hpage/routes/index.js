var express = require('express');
const db = require('../mod/db.js');
var router = express.Router();
var mod = require('../mod/mod.js');
var mod2 = require('../mod/mod2.js');
var dup = require('../mod/dupli.js');
const bodyParser = require('body-parser')
router.use(bodyParser.urlencoded({ extended: false }))

router.get('/', function (req, res) {
    console.log(req.session.passport)
    if (!req.user) {
        res.redirect('/home/login');
        return;
    }
    var body = mod2.mainpg(req.user.nickname, req.user.id);
    var html = mod.HTML('메인페이지', '', body);
    res.send(html);
});

router.get('/:userid/userinfo', function (req, res) {
    var user = db.get('users').find({
        id: req.params.userid
    }).value();
    var post = req.user;
    if (!user) {
        res.send("<script>alert('페이지가 존재하지 않습니다!');location.href='/';</script>");
        return;
    }
    if (!post || post.key != user.key) {
        res.send(`<script>alert('권한이 없습니다!');window.history.back();</script>`)
        return;
    }
    if (!post.answer)
        post.answer = '';
    if (post.month === '월')
        post.month = '';
    var body = mod2.userinfo(post.nickname,post.name, post.nickname, post.id, post.question
        , post.answer, post.year, post.month, post.day);
    var html = mod.HTML(`${post.nickname}님의 회원정보`, 'userinfo', body);
    res.send(html);
})
router.post('/:userid/userinfo',function(req,res){
    var post=req.body;
    var user=db.get('users').find({
        id:post.id,
        password:post.pw
    }).value();
    if(!user){
        res.send(`<script>alert('비밀번호가 일치하지 않습니다!');window.history.back();</script>`)
        return;
    }
    db.get('users').find({
        id:post.id
    }).assign({
        
    }).write();
    res.send('h')
    
})
router.post('/:userid/userinfo/modify', function (req, res) {
    res.send(dup.dupli_mod(req, req.user.nickname));
})
router.post('/:userid/userinfo/modify_', function (req, res) {
    res.send(dup.dupli_mod(req, req.user.nickname));
})

module.exports = router;
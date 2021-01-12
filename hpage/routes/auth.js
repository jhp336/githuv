var express = require('express');
var router=express.Router();
const bodyParser = require('body-parser')
router.use(bodyParser.urlencoded({extended:false}))

const low = require('lowdb')
const FileSync = require('lowdb/adapters/FileSync');

const adapter = new FileSync('db.json')
const db = low(adapter)
db.defaults({users:[]}).write();
router.get('/',function(req,res){
    db.get('users').remove({day: ''}).write();

})
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

    db.get('users').push({
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
    }).write();
    alert('회원가입이 완료되었습니다!');
    db.get('users').remove({day: ''}).write();
})
module.exports=router;
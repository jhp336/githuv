var express = require('express');
var router = express.Router();
var mod = require('../mod/mod.js');
var db = require('../mod/db.js');
var dup = require('../mod/dupli.js');
var shortid = require('shortid');
var bcrypt = require('bcrypt');
/*const bodyParser = require('body-parser')
router.use(bodyParser.urlencoded({ extended: false }))*/
router.use(express.urlencoded({extended:false}))

router.get('/login', function (req, res) {
    var flash = req.flash();
    var msg = '';
    if (flash.error) {
        msg = flash.error;
    }
    var body = mod.LOGIN(msg);
    var html = mod.HTML('로그인', 'login', body);
    res.send(html);
});
router.get('/newaccount', function (req, res) {
    var body = mod.NEWACC();
    var html = mod.HTML('회원가입', 'newaccount', body);
    res.send(html);
});
router.get('/findidpw', function (req, res) {
    var body = mod.FINDIDPW();
    var html = mod.HTML('아이디/비번 찾기', 'findidpw', body);
    res.send(html);
});
router.post('/newaccount', function (req, res) {
    res.send(dup.dupli_new(req, '닉네임', 'nickname'));
})
router.post('/newaccount_', function (req, res) {
    res.send(dup.dupli_new(req, '아이디', 'id'));
})
router.post('/findidpw', function (req, res) {
    var post = req.body;
    var name = post.name;
    var email = post.email;
    var id = post.id;
    var ans = post.answer;
    var user = '';
    var body = '';
    var html = '';
    if (!ans) {
        if (!id) {//아이디찾기
            var user = db.get('users').find({
                name: name,
                email: email
            }).value();
            if (!user)
                body = mod.FINDIDPW('아이디', '해당 이름, 이메일로 가입한 계정이 없습니다!');
            else body = mod.FINDIDPW('아이디', user.id);
            html = mod.HTML('아이디/비번 찾기', 'findidpw', body);
            res.send(html);
            return;
        }
        user = db.get('users').find({ //비밀번호찾기1
            name: name,
            id: id
        }).value();
        if (!user)
            body = mod.FINDIDPW('비밀번호', '해당 이름, 아이디로 가입한 계정이 없습니다!');
        else if (!user.answer.trim())
            body = mod.FINDIDPW('비밀번호', '질문 등록 안 해서 못 찾음ㅋㅋ');
        else body = mod.FINDIDPW('비밀번호', user);
        html = mod.HTML('아이디/비번 찾기', 'findidpw', body);
        res.send(html);
        return;
    }
    user = db.get('users').find({//비밀번호 찾기2
        id: id,
        answer: ans
    }).value();
    if (!user)
        body = mod.FINDIDPW('비밀번호', `질문에 대한 답변이 일치하지 않습니다!`);
    else {
        var tmppw = shortid.generate();
        bcrypt.hash(tmppw, 10, function (err, hash) {
            db.get('users').find({
                id: id,
                answer: ans
            }).assign({
                password: hash
            }).write();
        });
        body = mod.FINDIDPW('비밀번호', tmppw, 1);
    }
    html = mod.HTML('아이디/비번 찾기', 'findidpw', body);
    res.send(html);
})
router.get('/readMovieList', function(req,res){
    if(req.params.type==1)
        res.send({
            "message":"movie readMovieList 성공","code":200,"resultType":"list","result":[{"id":1,"title":"진격의 거인","title_eng":"The Swindlers","date":"2017-11-22","user_rating":3.9,"audience_rating":8.36,"reviewer_rating":4.33,"reservation_rate":61.69,"reservation_grade":1,"grade":15,"thumb":"http://movie2.phinf.naver.net/20171107_251/1510033896133nWqxG_JPEG/movie_image.jpg?type=m99_141_2","image":"http://movie.phinf.naver.net/20171107_251/1510033896133nWqxG_JPEG/movie_image.jpg"},{"id":2,"title":"저스티스 리그","title_eng":"Justice League","date":"2017-11-15","user_rating":3.9,"audience_rating":7.99,"reviewer_rating":5.83,"reservation_rate":12.63,"reservation_grade":2,"grade":12,"thumb":"http://movie2.phinf.naver.net/20170925_296/150631600340898aUX_JPEG/movie_image.jpg?type=m99_141_2","image":"http://movie.phinf.naver.net/20170925_296/150631600340898aUX_JPEG/movie_image.jpg"},{"id":3,"title":"토르:라그나로크","title_eng":"Thor: Ragnarok","date":"2017-10-25","user_rating":3.7,"audience_rating":9.03,"reviewer_rating":6.13,"reservation_rate":6.73,"reservation_grade":3,"grade":12,"thumb":"http://movie2.phinf.naver.net/20170928_85/1506564710105ua5fS_PNG/movie_image.jpg?type=m99_141_2","image":"http://movie.phinf.naver.net/20170928_85/1506564710105ua5fS_PNG/movie_image.jpg"},{"id":4,"title":"러빙 빈센트","title_eng":"Loving Vincent","date":"2017-11-09","user_rating":3.8,"audience_rating":9.19,"reviewer_rating":7.5,"reservation_rate":3.82,"reservation_grade":4,"grade":15,"thumb":"http://movie2.phinf.naver.net/20171013_210/1507861351048TMJcR_JPEG/movie_image.jpg?type=m99_141_2","image":"http://movie.phinf.naver.net/20171013_210/1507861351048TMJcR_JPEG/movie_image.jpg"},{"id":5,"title":"범죄도시","title_eng":"The Outlaws","date":"2017-10-03","user_rating":3.7,"audience_rating":9.27,"reviewer_rating":6.12,"reservation_rate":2.37,"reservation_grade":5,"grade":19,"thumb":"http://movie2.phinf.naver.net/20170915_299/1505458505658vbKcN_JPEG/movie_image.jpg?type=m99_141_2","image":"http://movie.phinf.naver.net/20170915_299/1505458505658vbKcN_JPEG/movie_image.jpg"}]}
        );
})
module.exports = router;
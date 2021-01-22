var mod = require('./mod.js');
var db = require('./db.js');

dupli = function (req, str, which) {
    var post = req.body;
    var body = mod.NEWACC();
    var html = mod.HTML('회원가입', 'newaccount', body);        
    var add=`</script>`
    if(which=='nickname'){
        var info=post.nickname;
        var user = db.get('users').find({
            nickname:info
        }).value();
        if(post.idbool==='1'){
            add=`$('#iddupok').attr('hidden',false);
            $('#iddupcheck').attr('hidden',true);`+add;
        }
        console.log(add);
        
    }
    else {
        var info=post.id;
        var user = db.get('users').find({
            id:info
        }).value();
        if(post.nicknamebool==='1'){
            add=`$('#nicknamedupok').attr('hidden',false);
            $('#nicknamedupcheck').attr('hidden',true);`+add;
        }
    }
    
    if (post.ans === undefined)
        post.ans = '';
    var script = `<script>
        $('#name').val('${post.name}');
        $('#nickname').val('${post.nickname}');
        $('#id').val('${post.id}');
        $('#pw').val('${post.pw}');
        $('#quest').val('${post.quest}');
        $('#direct').val('${post.direct_q}');
        $('#ans').val('${post.ans}');
        $('#year').val('${post.year}');
        $('#month').val('${post.month}');
        $('#day').val('${post.day}');
        `
    if (post.quest != '0') {
        script = script + `$('#ans').attr('disabled', false);`
        if (post.quest === 'dir')
            script = script + `$("#direct").show();`
    }

    if (user)//중복있는경우
    script = script + `$('#${which}').focus();
    alert('해당 ${str}이(가) 이미 있습니다. 다시 정해주세요!');`;
    else script = script + `$('#${which}dupok').attr('hidden',false);
    $('#${which}dupcheck').attr('hidden',true);
    $('#${which}bool').val('1');`; //중복 x

    return html+script+add;
}
module.exports= dupli;
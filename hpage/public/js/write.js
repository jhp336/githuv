
Write = function (form) {
    var title = $('#title')
    if (title.val().trim() === "") {
        $('#msg1').html('제목을 입력하세요!');
        $('#msg2').html('<br>')
        title.focus();
        return;
    }
    var main = $('#maintxt')
    if (main.val().trim() === "") {
        $('#msg1').html('<br>')
        $('#msg2').html('내용을 입력하세요!');
        main.focus();
        return;
    }
    $(form).attr('onsubmit', true);
    $(form).submit();
}
Delete = function (form, opt) {
    $(form).attr('action', `/${opt}/delete`);
    $(form).attr('onsubmit', true);
    $(form).submit();
}
Candelete = function (postid, id) {
    if (postid != id)
        $('.owneronly').hide();
}
author = function () {
    $('html').click(function (e) {
        $('.arrow_box').attr('hidden', true);
        if($(e.target).attr('class') === 'author'){
            var id = $(e.target).attr('id');
            var author=$(e.target).attr('name');
            $(`#author${id}`).html(`<span><a href="/square/search/id/${author}">작성글 보기</a></span><br><a href="/${author}/userinfo"><span>회원 정보</span></a>`)
            $(`#author${id}`).attr('hidden', false);
        }
    });
}
cmnt=function(form,opt){
    if($('#comment').val().trim()==='')
    return;
    $(form).attr('action',`/${opt}/comment`);    
    $(form).attr('onsubmit', true);
    $(form).submit();
}
hoverin=function(i,cmntid,userid){
    $(`#author${i}`).show();
    if(cmntid!=userid)
    $(`.notauthor${i}`).hide();
}
hoverout=function(i){
    $(`#author${i}`).hide();
}
cmntmodify=function(i,opt,postno,cmntno){
    var cmnt=$(`#cmnt${i}`).html().replace(/(?:<br>)/g, '\r\n');
    $(`#cmnt${i}`).html(`
    <form method="post" action="/${opt}/cmnt_mod">
        <textarea name="cmnt_mod">\r\n${cmnt}</textarea>
        <input type="hidden" name="num" value="${postno}"> 
        <input type="hidden" name="cmntnum" value="${cmntno}">
    </form>
    `);
    cmnt=cmnt.replace(/(?:\r\n|\r|\n)/g, '<br>');
    $(`#author${i}`).html(`
    <span style="cursor:pointer" onclick="modok('form')">확인 </span>
    <span style="cursor:pointer" onclick="modcancel('${i}','${cmnt}','${opt}','${postno}','${cmntno}')">취소</span>
    `);
}
modok=function(form){
    $(form).submit();
}
modcancel=function(i,cmnt,opt,postno,cmntno){
    $(`#cmnt${i}`).html(`${cmnt}`);
    $(`#author${i}`).html(`
    <span style="cursor:pointer">답글 </span>
    <span style="cursor:pointer" class="notauthor${i}" onclick="cmntmodify('${i}','${opt}','${postno}','${cmntno}');">수정 </span>
    <span style="cursor:pointer" class="notauthor${i}">삭제</span>
    `)
}
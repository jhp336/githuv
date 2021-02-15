
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
            $(`#author${id}`).html('<span>작성글 보기</span><br><span>회원 정보</span>')
            $(`#author${id}`).attr('hidden', false);
        }
    });

}
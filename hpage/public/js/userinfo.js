Modify=function(answer){
    $('#name').attr('disabled',false);
    $('#nickname').attr('disabled',false);
    $('#nicknamedupcheck').attr('hidden',false);
    $('#quest').attr('disabled',false);
    $('#ans').attr('disabled',false);
    $("#ans").attr('style','');
    $('#ans').val(answer);
    $('#year').attr('disabled',false);
    $('#month').attr('disabled',false);
    $('#day').attr('disabled',false);

    $('#modify').attr('hidden',true);
    $('#pw').attr('hidden',false);
    $('#done').attr('hidden',false);
}
duplicheck = function (id) {
    var test = /^(?=.*[a-zA-Z]|.*[가-힣])[a-zA-Z0-9가-힣]{2,10}$/;
    if (!test.test($('#nickname').val())) {
        alert('닉네임은 한글 또는 영문을 포함한 2~10 글자로 작성해주세요');
        $('#nickname').focus();
        return;
    }
    $('#new').attr('action', `/${id}/userinfo/modify`);
    $('#new').submit();
}

duplicheck_ = function (id) {
    var test = /^(?=.*[a-zA-Z])(?=.*[0-9])[a-zA-Z0-9]{4,12}$/;
    if (!test.test($('#id').val())) {
        alert('아이디는 영문과 숫자 4~12자리로 공백없이 작성해주세요');
        $('#id').focus();
        return;
    }
    $('#new').attr('action', `/${id}/userinfo/modify_`);
    $('#new').submit();
}
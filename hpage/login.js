enterpress=function(){
    if(window.event.keyCode==13)
    Login('#new');
}

Login=function(form){
    var ID=$('#id');
    var PW=$('#pw');
    if(ID.val()===""){
        alert('아이디를 입력해주세요')
        ID.focus();
        return;
    }

    if(PW.val()===""){
        alert('비밀번호를 입력해주세요')
        PW.focus();
        return;
    }

    $(form).submit();
}
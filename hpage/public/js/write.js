
Write= function(form){
    var title=$('#title')
    if(title.val()===""){
        $('#msg1').html('제목을 입력하세요!');
        title.focus();
        return;
    } 
    var main=$('#maintxt')
    if(main.val()===""){
        $('#msg2').html('내용을 입력하세요!');
        main.focus();
        return
    }
    $(form).submit();
}
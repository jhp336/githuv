function question(ele){
    var val=$(ele).val();
    if(val==='0'){
        $("#direct").hide();
        $('#ans').attr('disabled',true);
    }
    else {
        $('#ans').attr('disabled',false)
        if(val==='dir')
        $("#direct").show();
    }
}

Check=function(form){
    var ID=$('#id');
    var NAME=$('#name');    
    var PW=$("#pw");
    var test1=/^[가-힣]{1,12}$/;
    var test2=/^[a-zA-Z0-9]{4,12}$/;
    if(NAME.val()===""){
        alert('이름을 입력하세요');
        form.name.focus();
        return;
    }
    for(i=0;i<NAME.val().length;i++){
        if(!test1.test(NAME.val())){
            alert('이름은 한글 1~12자리로 공백없이 작성해주세요');
            form.name.focus();
            return;
        }    
    }//이름 처리

    if(ID.val()===""){
        alert('아이디를 입력하세요(영문 또는 숫자 조합, 4~12자리)');
        setTimeout(function(){form.id.focus();},1);
        return;
    }
    
    for(i=0;i<ID.val().length;i++){
        if(!test2.test(ID.val())){
            alert('아이디는 영문 또는 숫자 4~12자리로 공백없이 작성해주세요');
            form.id.focus();
            return;
        }
    }//아이디 처리


}
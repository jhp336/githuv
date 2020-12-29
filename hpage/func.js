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
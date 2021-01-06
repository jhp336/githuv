var express=require('express');
var app=express();
var mod=require('./mod/mod.js');
app.get('/:page',function(req,res){
    var title=req.params.page;
    var body=mod.BODY(title);
    var html=mod.HTML(title,body);
    res.send(html);

});
app.use(express.static(__dirname));
app.listen(3000);

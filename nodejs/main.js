var http = require('http');
var fs = require('fs');
var url= require('url');
const { REPL_MODE_SLOPPY } = require('repl');
var app = http.createServer(function(request,response){
    var _url = request.url;
    var queryData = url.parse(_url,true).query;
    var pathname = url.parse(_url,true).pathname;
    if(pathname==='/'){
        fs.readFile(`Data/${queryData.id}`,'utf8',function(err,para){
            var title = queryData.id;
            if(title===undefined){
                var title = 'Welcome!';
                var para = 'Welcome to Nodejs!';
            }            
            fs.readdir('data',function(err,filelist){
                var list=''
                for(var i=0;i<filelist.length;i++){
                 var arr=[1,0,2];
                    list=list+'<li><a href="?id='+filelist[arr[i]]+'">'+filelist[arr[i]]+'</a></li>'
                }
                var templat =`
                    <!doctype html>
                    <html>
                    <head>
                        <title>WEB1 - ${title}</title>
                        <meta charset="utf-8">
                    </head>
                    <body>
                        <h1><a href="/">WEB</a></h1>
                        <ul>
                        ${list}
                        </ul>
                        <h2>${title}</h2>
                        <p>${para}</p>
                    </body>
                    </html>
                `;
                response.writeHead(200);
                response.end(templat);
            });
        });
    }
    else {
        response.writeHead(404);
        response.end('Not Found');
    }         
});
            
app.listen(3000);

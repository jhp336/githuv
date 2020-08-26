var http = require('http');
var fs = require('fs');
var url= require('url');
const { REPL_MODE_SLOPPY } = require('repl');
var app = http.createServer(function(request,response){
    var _url = request.url;
    var queryData = url.parse(_url,true).query;
    var title = queryData.id;
    var stl='';
    if(_url =='/'){
        title='starcraft';
        stl='index';
    }
    if(_url == '/favicon.ico'){
        response.writeHead(404);
        response.end();
        return;
    }
    response.writeHead(200);
    fs.readFile(`movie/${title}`,'utf8',function(err,data){
        var tmp=`
        <!DOCTYPE html>

<html>

    <head>
        <title>${title+"..."}</title>
        <meta charset="utf-8">
        <link rel="stylesheet" href="${stl}style.css"/>
        <script src="color.js"></script>
    </head>

    <body>
        <h1 class="header"><a href="/"style="color:navy;" >STARCRAFT</a></h1>
        <input id="night_day" type="button" value="night" onclick="
        NightDay(this);
        ">
        <div id="grid">
            <ol>
                <p><li><a href="/?id=zerg"><img src="image/zerg.png">Zerg(저그)</a></li></p>
                <p><li><a href="/?id=terran"><img src="image/terran.png">Terran(테란)</a></li></p>
                <p><li><a href="/?id=protoss"><img src="image/protoss.png">Protoss(프로토스)<a></li></p>
            </ol>
            <div>
                <img src="image/${title}2.jpg" width="240" height="300" class="img">
                <img src="image/${title}.jpg" width="480" height="300" class="img img2">
                ${data}
            </div>
        </div>
        <input id="night_day" type="button" value="night" onclick="
        NightDay(this);
        ">
    </body>
</html>

        `;
        response.end(tmp);
    })
});
app.listen(2000);
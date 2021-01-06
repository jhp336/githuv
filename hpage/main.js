var http = require('http')
var url = require('url');
var app = http.createServer(function(request,response){
    var _url = request.url;
    var queryData = url.parse(_url, true).query;
    var title = queryData.id;
    if(_url == '/'){
      title = 'Login';
    }
    if(_url == '/favicon.ico'){
      return response.writeHead(404);
    }
    response.writeHead(200);
    var template = `
    <!DOCTYPE html>
<html>
    <head>
        <style>
        html{
            background-color: rgb(169, 194, 194);
        }
        body{
            margin-top: 30px;
            color: rgb(95, 95, 241);
        }
        header{
            text-align: center;
            margin: 0 auto;
            margin-bottom: 50px;
            padding: 1px 0 1px;
            width:450px;
            background-color: rgb(241, 237, 237);
            border-radius: 3px;
        }
        #new{
            margin: 0 auto;
            width: 450px;
            padding: 20px 0 10px ;
            background-color: rgb(241, 237, 237);
            border-radius: 3px;
        }
        table{
            margin: 0 auto;
        }
        .click{
            width: 45px;
            height: 25px;
            border: none ;
            color: rgb(220, 224, 228);
            background-color: rgb(8, 109, 104) ;
            cursor: pointer;
        }/*확인,취소버튼*/
        .btn{
            width: 250px;
            height: 40px;
            border: none ;
            color: rgb(220, 224, 228);
            background-color: rgb(8, 109, 104) ;
            cursor: pointer;
            font-size: 15px;
            margin: 10px 0 15px;
        }/*로그인 버튼*/
        .findbtn{
            width: 180px;
            height: 30px;
            border: none ;
            color: rgb(30, 31, 32);
            cursor: pointer;
            border-radius: 3px 3px 0 0;
        }/*아디찾기/비번찾기버튼*/
        input,button,select{
            border:2px solid rgb(220, 224, 228);
            border-radius: 3px;
        }
        .inputbox{
            width: 200px;
            height: 40px;
            padding:0 15px;
            font-size: 15px;
        }/*로그인 아이디/비번 박스*/
        .inputbox2{
            width:200px;
            height:20px;
            padding:3px 10px;
            font-size: 13px;
        }
        a{
            text-decoration:none;
            color: rgb(95, 95, 241) ;
        }
        a:hover{
            text-decoration: underline;
        }
        span{
            font-size:xx-small;
            color:red;
        }
        .click:hover,.font:hover{
            cursor: pointer;
        }
        .font:hover{
            text-decoration: underline;
        }
        </style>
        <meta charset="utf-8">
        <script src="https://code.jquery.com/jquery-3.5.1.slim.min.js" integrity="sha256-4+XzXVhsDmqanXGHaHvgh1gMQKX40OUvDEBTu8JcmNs=" crossorigin="anonymous"></script>
        <script>enterpress=function(){
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
        }</script>
        <script>function question(ele){
            var val=$(ele).val();
            if(val==='0'){
                $("#direct").hide();
                $('#ans').attr('disabled',true);
            }
            else {
                $("#direct").hide();
                $('#ans').attr('disabled',false)
                if(val==='dir')
                $("#direct").show();
            }
        }
        
        Check=function(form){
            var ID=$('#id');
            var NAME=$('#name');    
            var PW=$("#pw");
            var PWC=$('#pwc');
            var test1=/^[가-힣]{1,12}$/;
            var test2=/^(?=.*[a-zA-z])(?=.*[0-9])[a-zA-Z0-9]{4,12}$/;
            var test3=/^(?=.*[a-zA-Z])(?=.*[0-9])[a-zA-Z0-9~!@#$%^&*?]{4,12}$/;
            if(NAME.val()===""){
                alert('이름을 입력하세요');
                NAME.focus();
                return;
            }
            for(i=0;i<NAME.val().length;i++){
                if(!test1.test(NAME.val())){
                    alert('이름은 한글 1~12자리로 공백없이 작성해주세요');
                    NAME.focus();
                    return;
                }    
            }//이름 처리
        
            if(ID.val()===""){
                alert('아이디를 입력하세요(영문과 숫자 조합, 4~12자리)');
                ID.focus();
                return;
            }
            for(i=0;i<ID.val().length;i++){
                if(!test2.test(ID.val())){
                    alert('아이디는 영문과 숫자 4~12자리로 공백없이 작성해주세요');
                    ID.focus();
                    return;
                }
            }//아이디 처리
        
            if(PW.val()===""){
                alert('비밀번호를 입력하세요(영문과 숫자 조합, 4~12자리, 특수문자 ~!@#$%^&*? 가능)');
                PW.focus();
                return;
            }
            for(i=0;i<PW.val().length;i++){
                if(!test3.test(PW.val())){
                    alert('비밀번호는 영문과 숫자 4~12자리로 공백없이 작성해주세요 + 특수문자 ~!@#$%^&*? 포함 가능!')
                    PW.focus();
                    return;
                }
            }//비번 처리
        
            if(PWC.val()===""){
                alert('비밀번호 확인 칸을 작성해주세요');
                PWC.focus();
                return;
            }
            if(PW.val()!=PWC.val()){
                alert('비밀번호가 일치하지 않습니다');
                PWC.focus();
                return;
            }//비번 일치 처리
        
            $(form).submit();  
        }
        
        enterpress=function(){
            if(window.event.keyCode==13)
            Check('#new');
        }</script>
        <script>function clickbtn(but){
            var btn2, btn=$(but)
            if(btn.attr('id')==='idfind'){
                btn2=$('#pwfind');
                $('form').html(\`
                <table>
                    <tr>
                        <td><input class="inputbox" name= "name" id="name" type="text" placeholder="성명"></td>
                    </tr>
                </table>
                <br>
                <div style="text-align: center;">
                    <input class="click" type="button" value="확인"  onclick="Pressbtn('#new')">
                </div>
                \`)
            }
            else {
                btn2=$('#idfind');
                $('form').html(\`
                <table>
                    <tr>
                        <td><input class="inputbox" name="name" id="name" type="text" placeholder="성명"></td>
                    </tr>
                    <tr>
                        <td><input class="inputbox" name="id" id="id" type="text" placeholder="아이디"></td>
                    </tr>
                </table>
                <br>
                <div style="text-align: center;">
                    <input class="click" type="button" value="확인"  onclick="Pressbtn('#new')">
                </div>\`);
            }
            if(btn.css("background-color") != "rgb(241, 237, 237)"){
                btn.css("background-color","rgb(241, 237, 237)");
                btn2.css("background-color","rgb(176, 182, 182)");
            }
        }
        
        enterpress=function(){
            if(window.event.keyCode==13)
            Pressbtn('#new');
        }
        Pressbtn=function(form){
            var NAME=$('#name');
            var ID=$('#id');
            if(NAME.val()===""){
                alert('이름을 입력해주세요');
                NAME.focus();
                return;
            }
            if(ID.val()===""){
                alert('아이디를 입력해주세요');
                ID.focus();
                return;
            }
        
            $(form).submit();
        }
        </script>
        <script>login = function(){
            $('body').html(\`
                    <header>
                        <h1>로그인</h1>
                        <p style="font-weight:bold;">계정에 로그인을 해주세요!</p>
                    </header>
                    <form id="new">
                        <table>
                            <tr>
                                <td><input class="inputbox" id="id" type="text" placeholder="아이디"></td>
                            </tr>
                            <tr>
                                <td><input class="inputbox" id="pw" type="password" placeholder="비밀번호"></td>
                            </tr>
                        </table>     
                        <div style="text-align: center;">
                            <input id="login" class="btn" type="button" value="로그인" onclick="Login('#new')">
                        </div>
                        <div class="font" style="text-align: center;" onclick="find()">아이디/비밀번호를 잊으셨나요?</div>
                        <div class="font" style="text-align: center;" onclick="newacc()">계정이 없으신가요?</div>
                    </form>
            \`)
        }
        find=function(){
            $('body').html(\`
                    <header>
                        <h1>아이디/비밀번호 찾기</h1>
                        <p class="font" onclick="login()">로그인 화면으로</p>    
                    </header>
                    <div style="text-align: center;">
                        <input class="findbtn" id="idfind" type="button"  value="아이디 찾기" style="background-color: rgb(241, 237, 237);" onclick="
                        clickbtn(this);
                        ">
                        <input class="findbtn" id="pwfind" type="button" value="비밀번호 찾기"style="background-color: rgb(176, 182, 182)" onclick="
                        clickbtn(this);
                        ">
                    </div>
                    <form id="new">
                        <table>
                            <tr>
                                <td><input class="inputbox" name="name" id="name" type="text" placeholder="성명"></td>
                            </tr>
                        </table>
                        <br>
                        <div style="text-align: center;">
                            <input class="click" type="button" value="확인" onclick="Pressbtn('#new')">
                        </div>
                    </form>
        
            
            
            \`)
        }
        newacc=function(){
            $('body').html(\`
                
                    <header>
                        <h1>회원가입</h1>
                        <p style="font-weight:bold;">새 계정을 만들어 보세요!</p>
                    </header>
                    <form id="new" name="new" method="POST" action="./register">
                        <table>
                            <tr>
                                <td><label for="name"><span>* </span>성명</label></td>
                                <td><input class="inputbox2" id="name" type="text" placeholder="성명"></td>
                            </tr>
                            <tr>
                                <td><label for="id"><span>* </span>아이디</label></td>
                                <td><input class="inputbox2" name="id" id="id" type="text" placeholder="아이디"></td>
                            </tr>
                            <tr>
                                <td><label for="pw"><span>* </span>비밀번호</label></td>
                                <td><input class="inputbox2" id="pw" type="password" placeholder="비밀번호"></td>
                            </tr>
                            <tr>
                                <td><label for="pwc"><span>* </span>비밀번호 확인</label></td>
                                <td><input class="inputbox2" id="pwc" type="password" placeholder="비밀번호 확인"></td>
                            </tr>
                            <tr>
                                <td><label for="direct"><span>&nbsp&nbsp</span>분실 시 질문</label></td>
                                <td>
                                    <select class="inputbox2" style="width:224px; height: 30px;" name="que" onchange="question(this)">
                                        <option value="0">::선택::</option>
                                        <option value="별명은?">별명은?</option>
                                        <option value="고향은?">고향은?</option>
                                        <option value="dir">직접 입력</option>
                                    </select>
                                </td>                        
                            </tr>
                            <tr>
                                <td></td>
                                <td><input class="inputbox2" type="text" id="direct" placeholder="질문을 입력하세요" hidden></td>
                            </tr>
                            <tr>
                                <td><label for="ans"><span>&nbsp&nbsp</span>답변</label></td>
                                <td><input class="inputbox2" type="text" id="ans" disabled ></td>
                            </tr>
                            <tr>
                                <td><label for="birth"><span>&nbsp&nbsp</span>생년월일</label></td>
                                <td>
                                    <input class="inputbox2" id="birth" type="text" pattern="[0-9]{4,4}" placeholder="년도(4자리)" maxlength="4" style="width: 70px;">
                                    <select class="inputbox2" style="width:60px; height: 30px; " >
                                    <option>01</option>
                                    <option>02</option>
                                    <option>03</option>
                                    <option>04</option>
                                    <option>05</option>
                                    <option>06</option>
                                    <option>07</option>
                                    <option>08</option>
                                    <option>09</option>
                                    <option>10</option>
                                    <option>11</option>
                                    <option>12</option>
                                    </select>
                                    <input class="inputbox2" type="text" placeholder="일" pattern="[0-9]{1,2}" maxlength="2" style="width: 34.9px;">
                                </td>
                            </tr>
                            <tr>
                                <td><span>&nbsp&nbsp</span>성별</td>
                                <td>
                                    <input name="sex" type="radio">남성
                                    <input name="sex" type="radio">여성    
                                </td>
                            </tr>
                            <tr>
                                <td></td><td><div style="text-align: right; font-size: x-small;"><span>* </span>표시는 필수 입력</div></td>
                            </tr>
                            <tr><td><br></td></tr>
                            
                        </table>             
                        <div id="btn" style="text-align: center;">      
                            <button class="click" type="button" onclick="
                            Check('#new');
                            ">완료</button>
                            <input class="click" type="button" value="취소" onclick="
                            login()
                            ">
                        </div> 
                    </form>
            \`)
        }</script>
        <title>로그인</title>
    </head>
    <body onkeypress="enterpress()">
        <header>
            <h1>로그인</h1>
            <p style="font-weight:bold;">계정에 로그인을 해주세요!</p>
        </header>
        <form id="new">
            <table>
                <tr>
                    <td><input class="inputbox" id="id" type="text" placeholder="아이디"></td>
                </tr>
                <tr>
                    <td><input class="inputbox" id="pw" type="password" placeholder="비밀번호"></td>
                </tr>
            </table>     
            <div style="text-align: center;">
                <input id="login" class="btn" type="button" value="로그인" onclick="Login('#new')">
            </div>
            <div class="font" style="text-align: center;" onclick="find()">아이디/비밀번호를 잊으셨나요?</div>
            <div class="font" style="text-align: center;" onclick="newacc()">계정이 없으신가요?</div>
        </form>
    </body>
</html>
    `
    response.end(template);
 
});
app.listen(8000);
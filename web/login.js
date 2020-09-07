var checkLoginStatus=function(response) {   
    console.log(response);
    //statusChangeCallback(response);   
    if(response.status==='connected'){
      document.querySelector('#authBtn').value='Facebook Logout';
      FB.api('/me',function(res){
        document.querySelector('#name').innerHTML='  Welcome! '+res.name;
      });
    }
    else{
      document.querySelector('#authBtn').value='Facebook Login';
      document.querySelector('#name').innerHTML=' ';
    }
  }     
  window.fbAsyncInit = function() {
    FB.init({
      appId      : '1023818741381356',
      cookie     : true,                    
      xfbml      : true,     
      version    : 'v8.0'   
    });
    FB.getLoginStatus(checkLoginStatus);
};
(function(d, s, id) {
  var js, fjs = d.getElementsByTagName(s)[0];
  if (d.getElementById(id)) return;
  js = d.createElement(s); js.id = id;
  js.src = "https://connect.facebook.net/en_US/sdk.js";
  fjs.parentNode.insertBefore(js, fjs);
}(document, 'script', 'facebook-jssdk')); //fblogin

function checkLoginStatus2(){
  var gBtn=document.querySelector('#gBtn');
  var name=document.querySelector('#name2');
  if(gauth.isSignedIn.get()){
    console.log('Google Loginned');
    gBtn.value='Google Logout';
    var prof=gauth.currentUser.get().getBasicProfile();
    name.innerHTML='  Welcome!'+prof.getName();
  }
  else {
    console.log('Google Logouted');
    gBtn.value='Google Login';
    name.innerHTML=' ';
  }
}

function init(){
  gapi.load('auth2',function(){
    window.gauth = gapi.auth2.init({
      client_id:'512868300234-gmlbsdhunt0rf4pdb25hggoikcnqdemi.apps.googleusercontent.com'
    })
    gauth.then(function(){
      console.log('success');
      checkLoginStatus2();
    }, function(){
      console.log('error');
    });
  });
}
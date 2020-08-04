
    function NightDay(self){
        var target=document.querySelector('body');
        if(self.value==='night'){
            BackgroundColor('black');
            BodyColor('white');
            self.value='day';
        }
        else{
            BackgroundColor('white');
            BodyColor('black');
            self.value='night';
        }
    }
    function BackgroundColor(color){
        document.querySelector('body').style.backgroundColor=color;
    }
    function BodyColor(color){
        document.querySelector('body').style.color=color;
    }    
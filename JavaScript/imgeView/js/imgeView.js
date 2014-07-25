$( document ).ready( function(){
	var imgeView = ImgeView.createNew();
	imgeView.init();
});

//图片浏览器类
var ImgeView = {
	createNew:function(){
		var imgeViewObj = {};
		var describeText = {};
		var imgNumber = $(".imgRotate ul").children().length;
		var count = imgNumber;

		/*初始化操作*/
		imgeViewObj.init = function(){
			$( ".imgRotate li" ).click(this.switchPicHandle);
			$( "#next" ).click(this.nextHandle);
			$( "#pre" ).click(this.preHandle);
			this.switchPicHandle();
		}


		/*切换图片时的操作*/
		imgeViewObj.switchPicHandle = function(){
			$( ".describe" ).stop();
			$( this ).addClass( "selected" );
			$( this ).siblings().removeClass( "selected" );

			var img = $( ".selected" ).children( "img" ).clone();
			$( "#previewImge" ).children().remove();
			img.appendTo( $( "#previewImge" ) );
			describeText = $( ".selected" ).children( "img" ).attr( "alt" );
			$( ".describe" ).css({"top":"-130px","opacity":"0"});
			$( ".describe" ).text(describeText);
			$(".describe").animate({"top":"0px","opacity":"0.8"},"slow");
		}

		/*点击向右滚动按钮触发的动作*/
		imgeViewObj.nextHandle = function(){
			if($(".imgRotate ul").is(":animated"))
				return false;

			if(count != 3){
				$(".imgRotate ul").animate({left:'-='+"140px"},"normal");
				count--;
			}
			else
				return false;
		}

		/*点击向左滚动触发的动作*/
		imgeViewObj.preHandle = function(){
			if($(".imgRotate ul").is(":animated"))
				return false;

			if(count!=imgNumber){
				$(".imgRotate ul").animate({left:'+='+"140px"},"normal");
				count++;
			}
			else
				return false;
		}

		return imgeViewObj;
	}
}


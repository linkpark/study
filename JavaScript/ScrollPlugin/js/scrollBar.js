/*
关于轮播器的重构代码
*/

$( document ).ready( function(){
	var scrollBar = ScrollBar.createNew();
	scrollBar.init();
	
	function AutoScrollHandler(){
 	  scrollBar.autoScroll();
	}

	setInterval(AutoScrollHandler,5000);
} );

var ScrollBar = {
	createNew : function(){
		var scrollBarObj = {};
		var imgNumber = $("#scroll > div.wrap").length - 1;

		isAutoScroll = true;

		scrollBarObj.init = function(){
			$("#scrollLeftClick").click(this.scrollNext);
			$("#scrollRightClick").click(this.scrollPrev);
			$("#stopBegin").click(this.stopBeginHandler);
		}

		/*轮播器点击下一张时触发的动作*/
		scrollBarObj.scrollNext = function(){
			if( 0 == imgNumber )
				return false;
			
			var currentItem = $(".wrap.main");
			var index = currentItem.index();

			var itemWidth = currentItem.width();
			var windowWidth = $(window).width();
			var leftValue = (windowWidth - itemWidth)/2;
			if(leftValue < 0)
				leftValue = 0;

			if(currentItem.is(":animated"))
				return false;

			currentItem.children(".scrollImg")
			.children("a.prev-image").remove();
			currentItem.children(".scrollImg")
			.children("a.next-image").remove();

			var preImg = currentItem.children(".scrollImg")
							.children("a.current-image").clone();

			preImg.addClass("prev-image");
			preImg.removeClass("current-image")

			if(index == imgNumber){
				var nextItem = $("div.wrap:eq(0)");
			}
			else{
				var nextItem = $(".wrap.main + div.wrap");
			}

			nextItem.removeClass("hide");
			nextItem.removeClass("hiddenLeft");
			nextItem.addClass("hiddenRight");
			nextItem.css("left",itemWidth+leftValue);

			if(nextItem.index() == imgNumber){
				nextNextItem = $("div.wrap:eq(0)");
			}
			else{
				var nextNextItem = nextItem.next();
			}

			var nextImg = nextNextItem.children(".scrollImg")
							.children("a.current-image").clone();

			nextImg.addClass("next-image");
			nextImg.removeClass("current-image");
			nextImg.appendTo(nextItem.children(".scrollImg"));
			nextItem.animate({left:leftValue,opacity:'1'},1000,function(){
				nextItem.removeClass("hiddenRight");
				nextItem.removeAttr("style");
				nextItem.addClass("wrap");
				nextItem.addClass("main");
				preImg.appendTo(nextItem.children(".scrollImg"));
			});

			currentItem.animate({left:-itemWidth,opacity: '0.2'},1000,function(){
				currentItem.removeClass("main").removeAttr("style")
					.addClass("hiddenLeft").addClass("hide");
			});

		}

		/*轮播器点击上一张时触发的动作*/
		scrollBarObj.scrollPrev = function(){
			if( 0 == imgNumber )
				return false;

			var currentItem = $(".wrap.main");
			var index = currentItem.index();
			var itemWidth = currentItem.width();
			var windowWidth = $(window).width();
			var leftValue = (windowWidth - itemWidth)/2;
			if(leftValue < 0)
				leftValue = 0;

			if(currentItem.is(":animated"))
				return false;

			currentItem.children(".scrollImg")
			.children("a.prev-image").remove();

			currentItem.children(".scrollImg")
			.children("a.next-image").remove();


			if(currentItem.index() == 0){
				var prevItem = $("div.wrap:eq("+imgNumber+")");
			}
			else{
				var prevItem = currentItem.prev();
			}

			var left = leftValue-1000;
			prevItem.css("left",left+"px");

			var nextImg = currentItem.children(".scrollImg")
							.children("a.current-image").clone();

			prevItem.removeClass("hide");
			nextImg.addClass("next-image");
			nextImg.removeClass("current-image");

			if(prevItem.index() == 0){
				prevImg = $("div.wrap:eq("+imgNumber+")").children(".scrollImg")
								.children("a.current-image").clone();
			}
			else{
				prevImg = prevItem.prev().children(".scrollImg")
							.children("a.current-image").clone();
			}

			prevImg.removeClass("current-image");
			prevImg.addClass("prev-image");
			prevImg.appendTo(prevItem.children(".scrollImg"));

			prevItem.animate({left:leftValue,opacity:'1.0'},1000,function(){
				prevItem.removeClass("hiddenLeft");
				prevItem.addClass("main");
				prevItem.removeAttr("style");
				nextImg.appendTo(prevItem.children(".scrollImg"));
			});

		currentItem.animate({left:itemWidth,opacity: '0'},1000,function(){
			currentItem.removeClass("main").removeAttr("style")
				.addClass("hiddenLeft").addClass("hide");
			});
		}

		/*点击禁止自动滚动*/
		scrollBarObj.stopAutoScroll = function(){
			$("#stopBegin").attr("src","../images/scrollPlay.jpg");
			isAutoScroll = false;
		}

		/*点击开始自动滚动*/
		scrollBarObj.startAutoScroll = function(){
			$("#stopBegin").attr("src","../images/scrollStop.jpg");
			isAutoScroll = true;
		}

		scrollBarObj.stopBeginHandler = function(){
			if(isAutoScroll == true){
				$("#stopBegin").attr("src","./images/scrollPlay.jpg");
				isAutoScroll = false;
			}

			else{
				$("#stopBegin").attr("src","./images/scrollStop.jpg");
				isAutoScroll = true;
			}

			return false;
		}

		/*轮播器自动播放*/
		scrollBarObj.autoScroll = function(){
			if( isAutoScroll == true )
				this.scrollNext();
			else
				return false;
		}

		return scrollBarObj;
	}
}

#define LEFT 220
#define RIGHT 220
#define lf 1
#define rg 0
#define md 2

void setup() {	//定义输入输出管号 
  	pinMode(5,OUTPUT);
  	pinMode(9,OUTPUT);
  	pinMode(18,INPUT);
  	pinMode(14,INPUT);
  	pinMode(17,INPUT);
}

int i = 2;//记录本次转向是否为左转 ，是则为1 
int j = 2;//记录上次...1 
int state = md;

void loop() {//循环函数 
  	int t1 = 1010;//控制左转的时间 
  	int t2 = 1010;//右 
  	int c = 0;//记录拉回来的时候的转向次数 
  
  	int L = 0;
  	int R = 0;
  	int F = 0;
  	L = digitalRead(14);//L为左传感器信号 
  	R = digitalRead(18);//右 
  	F = digitalRead(17);//中 
  
  	if(F == 0)//中间传感器检测到黑色时 ，微调或直行 
  	{
	    if(L == 1 && R == 0)//如果左边检测到白色，右边检测到黑色 
	    {
	    	state = lf;
	    	analogWrite(9,250);//由于左右履带松紧程度不同，左轮速度zan为设定值250 
	        analogWrite(5,200);//右轮减速，向右微调 
	    }
	    else if(L == 0 && R == 1)//反之 
	    {
	    	state = rg;
	        analogWrite(9,200);
	        analogWrite(5,255);//由于左右履带松紧程度不同，右轮速度为设定值255 
	    }
	    else//其他情况 ，直行 
	    {
	    	state = md;
	        analogWrite(9,250);
	        analogWrite(5,255);
	    }
	    delay(10); //持续10ms 
  	}
  
  	else//中间检测不到黑色，大幅度调整 
  	{
	  	if(i != j)//如果上次的转向和这次不同 ，很可能在直线区域 
	  	{
	  		if(F == 1)//
	  		{
	  			if(L == 1 && R == 0)//如果偏左，右转 
		    	{
		    		state = lf;
		    		analogWrite(9,LEFT);
		        	analogWrite(5,50);
		        	j = i;
		        	i = 0;
		        	delay(20);
		    	}
		    	else if(L == 0 && R == 1)//如果偏右... 
		    	{
		    		state = rg;
		        	analogWrite(9,50);
		        	analogWrite(5,RIGHT);
		        	j = i;
		        	i = 1;
		        	delay(20);
		    	}
		    	else//其他情况 
	      		{
		      		if(L == 0 && R == 0)//如果左右都检测到，就直行20ms
		      		{ 
				        analogWrite(9,LEFT);
				        analogWrite(5,RIGHT);
				        delay(20);
			        } 
			        else//如果完全偏离，则拉回来 
					{
						if(state == lf)//偏离前最后一次是向左转 
						{
							if(L == 1 && R == 1 && F == 1)//当三个传感器都检测不到的时候，右转+直行 循环 
							{
								analogWrite(9,LEFT);
			        			analogWrite(5,50);
			        			j = i; 
			        			i = 0;
			        			delay(20);
							}
						}
						else//偏离前最后一次为向右转 
						{
							if(L == 1 && R == 1 && F == 1)//当三个传感器都检测不到的时候，左转+直行 循环 
							{
								analogWrite(9,50);
			        			analogWrite(5,RIGHT);
			        			j = i; 
			        			i = 1;
			        			delay(20);
							}
						} 
					} 
		      	}
			}  		
		}
		else//如果上次转向和这次相同，很可能仍在180度大转弯中 
		{
			if(L == 1 && R == 0)//如果偏左，向右大转 
		    {
		    	state = lf;
		    	analogWrite(9,LEFT);
		        analogWrite(5,50);
		        j = i;
		        i = 0;
		        delay(20);
		    }
		    else if(L == 0 && R == 1)//偏右，... 
		    {
		    	state = rg;
		        analogWrite(9,50);
		        analogWrite(5,RIGHT);
		        j = i;
		        i = 1;
		        delay(20);
		    }
	      	else//其他情况 
	  		{
	      		if(L == 0 && R == 0)//如果左右都检测到，就直行20ms
	      		{ 
			        analogWrite(9,LEFT);
			        analogWrite(5,RIGHT);
			        delay(20);
		        } 
		        else//如果完全偏离，则拉回来 
				{
					if(state == lf)//偏离前最后一次是向左转 
					{
						if(L == 1 && R == 1 && F == 1)//当三个传感器都检测不到的时候，右转+直行 循环 
						{
							analogWrite(9,LEFT);
		        			analogWrite(5,50);
		        			j = i; 
		        			i = 0;
		        			delay(20);
						}
					}
					else//偏离前最后一次为向右转 
					{
						if(L == 1 && R == 1 && F == 1)//当三个传感器都检测不到的时候，左转+直行 循环 
						{
							analogWrite(9,50);
		        			analogWrite(5,RIGHT);
		        			j = i; 
		        			i = 1;
		        			delay(20);
						}
					} 
				} 
	      	}
		}
  	}
}

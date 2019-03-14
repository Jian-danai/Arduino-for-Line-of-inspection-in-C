#define LEFT 220
#define RIGHT 220
#define lf 1
#define rg 0
#define md 2

void setup() {	//������������ܺ� 
  	pinMode(5,OUTPUT);
  	pinMode(9,OUTPUT);
  	pinMode(18,INPUT);
  	pinMode(14,INPUT);
  	pinMode(17,INPUT);
}

int i = 2;//��¼����ת���Ƿ�Ϊ��ת ������Ϊ1 
int j = 2;//��¼�ϴ�...1 
int state = md;

void loop() {//ѭ������ 
  	int t1 = 1010;//������ת��ʱ�� 
  	int t2 = 1010;//�� 
  	int c = 0;//��¼��������ʱ���ת����� 
  
  	int L = 0;
  	int R = 0;
  	int F = 0;
  	L = digitalRead(14);//LΪ�󴫸����ź� 
  	R = digitalRead(18);//�� 
  	F = digitalRead(17);//�� 
  
  	if(F == 0)//�м䴫������⵽��ɫʱ ��΢����ֱ�� 
  	{
	    if(L == 1 && R == 0)//�����߼�⵽��ɫ���ұ߼�⵽��ɫ 
	    {
	    	state = lf;
	    	analogWrite(9,250);//���������Ĵ��ɽ��̶Ȳ�ͬ�������ٶ�zanΪ�趨ֵ250 
	        analogWrite(5,200);//���ּ��٣�����΢�� 
	    }
	    else if(L == 0 && R == 1)//��֮ 
	    {
	    	state = rg;
	        analogWrite(9,200);
	        analogWrite(5,255);//���������Ĵ��ɽ��̶Ȳ�ͬ�������ٶ�Ϊ�趨ֵ255 
	    }
	    else//������� ��ֱ�� 
	    {
	    	state = md;
	        analogWrite(9,250);
	        analogWrite(5,255);
	    }
	    delay(10); //����10ms 
  	}
  
  	else//�м��ⲻ����ɫ������ȵ��� 
  	{
	  	if(i != j)//����ϴε�ת�����β�ͬ ���ܿ�����ֱ������ 
	  	{
	  		if(F == 1)//
	  		{
	  			if(L == 1 && R == 0)//���ƫ����ת 
		    	{
		    		state = lf;
		    		analogWrite(9,LEFT);
		        	analogWrite(5,50);
		        	j = i;
		        	i = 0;
		        	delay(20);
		    	}
		    	else if(L == 0 && R == 1)//���ƫ��... 
		    	{
		    		state = rg;
		        	analogWrite(9,50);
		        	analogWrite(5,RIGHT);
		        	j = i;
		        	i = 1;
		        	delay(20);
		    	}
		    	else//������� 
	      		{
		      		if(L == 0 && R == 0)//������Ҷ���⵽����ֱ��20ms
		      		{ 
				        analogWrite(9,LEFT);
				        analogWrite(5,RIGHT);
				        delay(20);
			        } 
			        else//�����ȫƫ�룬�������� 
					{
						if(state == lf)//ƫ��ǰ���һ��������ת 
						{
							if(L == 1 && R == 1 && F == 1)//����������������ⲻ����ʱ����ת+ֱ�� ѭ�� 
							{
								analogWrite(9,LEFT);
			        			analogWrite(5,50);
			        			j = i; 
			        			i = 0;
			        			delay(20);
							}
						}
						else//ƫ��ǰ���һ��Ϊ����ת 
						{
							if(L == 1 && R == 1 && F == 1)//����������������ⲻ����ʱ����ת+ֱ�� ѭ�� 
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
		else//����ϴ�ת��������ͬ���ܿ�������180�ȴ�ת���� 
		{
			if(L == 1 && R == 0)//���ƫ�����Ҵ�ת 
		    {
		    	state = lf;
		    	analogWrite(9,LEFT);
		        analogWrite(5,50);
		        j = i;
		        i = 0;
		        delay(20);
		    }
		    else if(L == 0 && R == 1)//ƫ�ң�... 
		    {
		    	state = rg;
		        analogWrite(9,50);
		        analogWrite(5,RIGHT);
		        j = i;
		        i = 1;
		        delay(20);
		    }
	      	else//������� 
	  		{
	      		if(L == 0 && R == 0)//������Ҷ���⵽����ֱ��20ms
	      		{ 
			        analogWrite(9,LEFT);
			        analogWrite(5,RIGHT);
			        delay(20);
		        } 
		        else//�����ȫƫ�룬�������� 
				{
					if(state == lf)//ƫ��ǰ���һ��������ת 
					{
						if(L == 1 && R == 1 && F == 1)//����������������ⲻ����ʱ����ת+ֱ�� ѭ�� 
						{
							analogWrite(9,LEFT);
		        			analogWrite(5,50);
		        			j = i; 
		        			i = 0;
		        			delay(20);
						}
					}
					else//ƫ��ǰ���һ��Ϊ����ת 
					{
						if(L == 1 && R == 1 && F == 1)//����������������ⲻ����ʱ����ת+ֱ�� ѭ�� 
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

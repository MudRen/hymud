#include <ansi.h>
inherit F_CLEAN_UP;
inherit F_ANA;


int halt_breaking(object me);
int continue_breaking(object me);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
		string meri;
	mapping anamichi;
	mapping *anamichis;
	mapping meridian;
		int i,j;
	if(!arg) 
{
/*
	tell_object(me, "��ĳ�Ѩ�����"+(int)me->query("ana/m1")+"\n");	
	tell_object(me, "��ĳ�Ѩ�����"+(int)me->query("ana/m2")+"\n");	
	tell_object(me, "��ĳ�Ѩ�����"+(int)me->query("ana/m3")+"\n");	
	tell_object(me, "��ĳ�Ѩ�����"+(int)me->query("ana/m4")+"\n");	
	tell_object(me, "��ĳ�Ѩ�����"+(int)me->query("ana/m5")+"\n");	
	tell_object(me, "��ĳ�Ѩ�����"+(int)me->query("ana/m6")+"\n");	
	tell_object(me, "��ĳ�Ѩ�����"+(int)me->query("ana/m7")+"\n");	
	tell_object(me, "��ĳ�Ѩ�����"+(int)me->query("ana/m8")+"\n");	
	tell_object(me, "��ĳ�Ѩ�����"+(int)me->query("ana/m9")+"\n");	
*/	
	meridian = get_meridian("m1");
  i=(int)me->query("ana/m1");
  i=i-1;
  j=i;

  
  if  ( (int)me->query("ana/m1",1) <=0) 
	{
	tell_object(me, meridian["mer"]+": �� "+"\n" );	
}
	else
{
	anamichi=anamichi_m1[i];
	tell_object(me, HIR+meridian["mer"]+":" );	
		for (j=0;j<=i;j++)
		{
			anamichi=anamichi_m1[j];
if (j==(i)) tell_object(me, anamichi["ana"]+"\n" );	
	else
{		
if (j==14)
		 tell_object(me, anamichi["ana"]+">"+"\n" );	
else  tell_object(me, anamichi["ana"]+">" );	
}

}
} 


	meridian = get_meridian("m2");
  i=(int)me->query("ana/m2");
  i=i-1;
  j=i;
    
  
 if  ( (int)me->query("ana/m2",1) <=0) 
	{
	tell_object(me, meridian["mer"]+": �� "+"\n" );	
}
	else
{
	anamichi=anamichi_m2[i];
	tell_object(me,HIG+ meridian["mer"]+":" );	
		for (j=0;j<=i;j++)
		{
			anamichi=anamichi_m2[j];
if (j==(i)) tell_object(me, anamichi["ana"]+"\n" );	
	else
{		
if (j==14)
		 tell_object(me, anamichi["ana"]+">"+"\n" );	
else  tell_object(me, anamichi["ana"]+">" );	
}
		

}
} 


meridian = get_meridian("m3");
  i=(int)me->query("ana/m3");
  i=i-1;
  j=i;
    
  
 if  ( (int)me->query("ana/m3",1) <=0) 
	{
	tell_object(me, meridian["mer"]+": �� "+"\n" );	
}
	else
{
	anamichi=anamichi_m3[i];
	tell_object(me, HIY+meridian["mer"]+":" );	
		for (j=0;j<=i;j++)
		{
			anamichi=anamichi_m3[j];
if (j==(i)) tell_object(me, anamichi["ana"]+"\n" );	
	else 
{		
if (j==14)
		 tell_object(me, anamichi["ana"]+">"+"\n" );	
else  tell_object(me, anamichi["ana"]+">" );	
}
		

}
} 


meridian = get_meridian("m4");
  i=(int)me->query("ana/m4");
  i=i-1;
  j=i;
    
  
  if  ( (int)me->query("ana/m4",1) <=0) 
	{
	tell_object(me, meridian["mer"]+": �� "+"\n" );	
}
	else
{
	anamichi=anamichi_m4[i];
	tell_object(me, HIB+meridian["mer"]+":" );	
		for (j=0;j<=i;j++)
		{
			anamichi=anamichi_m4[j];
if (j==(i)) tell_object(me, anamichi["ana"]+"\n" );	
	else
{		
if (j==14)
		 tell_object(me, anamichi["ana"]+">"+"\n" );	
else  tell_object(me, anamichi["ana"]+">" );	
}
		

}
} 

meridian = get_meridian("m5");
  i=(int)me->query("ana/m5");
  i=i-1;
  j=i;
    
  
 if  ( (int)me->query("ana/m5",1) <=0) 
	{
	tell_object(me, meridian["mer"]+": �� "+"\n" );	
}
	else
{
	anamichi=anamichi_m5[i];
	tell_object(me, HIM+meridian["mer"]+":" );	
		for (j=0;j<=i;j++)
		{
			anamichi=anamichi_m5[j];
if (j==(i)) tell_object(me, anamichi["ana"]+"\n" );	
	else 
		{		
if (j==14)
		 tell_object(me, anamichi["ana"]+">"+"\n" );	
else  tell_object(me, anamichi["ana"]+">" );	
}


}
} 
meridian = get_meridian("m6");
  i=(int)me->query("ana/m6");
  i=i-1;
  j=i;
    
  
  if  ( (int)me->query("ana/m6",1) <=0) 
	{
	tell_object(me, meridian["mer"]+": �� "+"\n" );	
}
	else
{
	anamichi=anamichi_m6[i];
	tell_object(me, HIC+meridian["mer"]+":" );	
		for (j=0;j<=i;j++)
		{
			anamichi=anamichi_m6[j];
if (j==(i)) tell_object(me, anamichi["ana"]+"\n" );	
	else 
		{		
if (j==14)
		 tell_object(me, anamichi["ana"]+">"+"\n" );	
else  tell_object(me, anamichi["ana"]+">" );	
}


}
} 


meridian = get_meridian("m7");
  i=(int)me->query("ana/m7");
  i=i-1;
  j=i;
    
  
 if  ( (int)me->query("ana/m7",1) <=0) 
	{
	tell_object(me, meridian["mer"]+": �� "+"\n" );	
}
	else
{
	anamichi=anamichi_m7[i];
	tell_object(me, HIW+meridian["mer"]+":" );	
		for (j=0;j<=i;j++)
		{
			anamichi=anamichi_m7[j];
if (j==(i)) tell_object(me, anamichi["ana"]+"\n" );	
	else 
		{		
if (j==14)
		 tell_object(me, anamichi["ana"]+">"+"\n" );	
else  tell_object(me, anamichi["ana"]+">" );	
}


}
} 

meridian = get_meridian("m8");
  i=(int)me->query("ana/m8");
  i=i-1;
  j=i;
    
  
if  ( (int)me->query("ana/m8",1) <=0) 
	{
	tell_object(me, meridian["mer"]+": �� "+"\n" );	
}
	else
{
	anamichi=anamichi_m8[i];
	tell_object(me, YEL+meridian["mer"]+":" );	
		for (j=0;j<=i;j++)
		{
			anamichi=anamichi_m8[j];
if (j==(i)) tell_object(me, anamichi["ana"]+"\n" );	
	else 
		{		
if (j==14)
		 tell_object(me, anamichi["ana"]+">"+"\n" );	
else  tell_object(me, anamichi["ana"]+">" );	
}


}
} 

meridian = get_meridian("m9");
  i=(int)me->query("ana/m9");
  i=i-1;
  j=i;
    
  
if  ( (int)me->query("ana/m9",1) <=0) 
	{
	tell_object(me, meridian["mer"]+": �� "+"\n" );	
}
	else
{
	anamichi=anamichi_m9[i];
	tell_object(me, CYN+meridian["mer"]+":" );	
		for (j=0;j<=i;j++)
		{
			anamichi=anamichi_m9[j];
if (j==(i)) tell_object(me, anamichi["ana"]+"\n" );	
	else
		{		
if (j==14)
		 tell_object(me, anamichi["ana"]+">"+"\n" );	
else  tell_object(me, anamichi["ana"]+">" );	
}


}
} 


		return notify_fail(CYN"ָ���ʽ : chongxue <��������>(m1-m9)\n"NOR);
}		
	return chongxue(me,arg);
}

int continue_breaking(object me)
{
	mapping meridian = get_meridian(me->query_temp("meri"));
	mapping *anamichis = get_anamichis(me->query_temp("meri"));
	mapping anamichi = anamichis[(int)me->query_temp("anami")];
	
	me->start_busy(60);
	tell_object(me, HIR "\n������չ������Դ�ͨ"+meridian["meri"]+HIR"��"+anamichi["ana"]+NOR"��\n"NOR);
	return 1;
}

private void stop_breaking(object me)
{
        if (! interactive(me))
        {
                me->force_me("chat* sigh");
                call_out("user_quit", 0, me);
        }
}

int halt_breaking(object me)
{
	tell_object(me, "����ֹ�˱չس�Ѩ��\n");
	message_vision(HIY "$N" HIY "����̾��һ�����������������ۡ�\n\n" NOR, me);
	me->set_temp("biguan", 0);
	return 1;
}
private void user_quit(object me)
{
        if (! me || interactive(me))
                return;
      
        me->force_me("quit");
}

int help(object me)
{
        write(@HELP
ָ���ʽ : chongxue <��������>
�������ţ���m1��m9��Ϊ��Ϊ
m1������,m2��ά��,m3������,m4��  ��,
m5��ά��,m6��  ��,m7��  ��,m8��  �� ,
m9�������� 
�չ������Դ�ͨ����Ѩ������Ҫ�ǳ������������ڹ����ײ���������
һ����ͨ�˿�����ǿ�������ʡ�

HELP );
        return 1;
}

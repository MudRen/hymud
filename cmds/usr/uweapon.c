#include <ansi.h>
int main(object me, string arg)
{
	string info,name,id,file,infoa,infob;
  object weapon,newob,oldob;
	object obj, who, *inv, obj2;
	int i, amount;
    if(me->is_busy())
        return notify_fail("��������æ��\n");

if (!arg)
{
	printf(HIY+me->query("name")+""HIM" ���������б�"HIY"\n"HIW"----------------------------------------------\n"NOR);
  file = "/p/residence/weapon/"+me->query("id")+"_w1.c";
  newob=load_object(file);
	if( newob)
	{
	printf(HIG"����w1 ��������:"+HIB" %s\n"NOR,newob->query("name")+"("+newob->query("id")+")");
	}
	else printf(HIG"����w1 ��������:"+HIB" ��\n"NOR);

  file = "/p/residence/weapon/"+me->query("id")+"_w2.c";
  newob=load_object(file);
	if( newob)
	{
	printf(HIG"����w2 ��������:"+HIB" %s\n"NOR,newob->query("name")+"("+newob->query("id")+")");
	}
	else printf(HIG"����w2 ��������:"+HIB" ��\n"NOR);
		
		
  file = "/p/residence/weapon/"+me->query("id")+"_w3.c";
  newob=load_object(file);
	if( newob)
	{
	printf(HIG"����w3 ��������:"+HIB" %s\n"NOR,newob->query("name")+"("+newob->query("id")+")");
	}
	else printf(HIG"����w3 ��������:"+HIB" ��\n"NOR);

file = "/p/residence/weapon/"+me->query("id")+"_w4.c";
  newob=load_object(file);
	if( newob)
	{
	printf(HIG"����w4 ��������:"+HIB" %s\n"NOR,newob->query("name")+"("+newob->query("id")+")");
	}
	else printf(HIG"����w4 ��������:"+HIB" ��\n"NOR);
	

file = "/p/residence/weapon/"+me->query("id")+"_w5.c";
  newob=load_object(file);
	if( newob)
	{
	printf(HIG"����w5 ��������:"+HIB" %s\n"NOR,newob->query("name")+"("+newob->query("id")+")");
	}
	else printf(HIG"����w5 ��������:"+HIB" ��\n"NOR);

		
	printf(HIY+me->query("name")+""HIM" ��������б�"HIY"\n"NOR);

  file = "/p/residence/weapon/"+me->query("id")+"_a1.c";
  newob=load_object(file);
	if( newob)
	{
	printf(HIG"����a1 �������:"+HIB" %s\n"NOR,newob->query("name")+"("+newob->query("id")+")");
	}
	else printf(HIG"����a1 �������:"+HIB" ��\n"NOR);


  file = "/p/residence/weapon/"+me->query("id")+"_a2.c";
  newob=load_object(file);
	if( newob)
	{
	printf(HIG"����a2 �������:"+HIB" %s\n"NOR,newob->query("name")+"("+newob->query("id")+")");
	}
	else printf(HIG"����a2 �������:"+HIB" ��\n"NOR);
		
		
  file = "/p/residence/weapon/"+me->query("id")+"_a3.c";
  newob=load_object(file);
	if( newob)
	{
	printf(HIG"����a3 �������:"+HIB" %s\n"NOR,newob->query("name")+"("+newob->query("id")+")");
	}
	else printf(HIG"����a3 �������:"+HIB" ��\n"NOR);		


		
  file = "/p/residence/weapon/"+me->query("id")+"_a4.c";
  newob=load_object(file);
	if( newob)
	{
	printf(HIG"����a4 �������:"+HIB" %s\n"NOR,newob->query("name")+"("+newob->query("id")+")");
	}
	else printf(HIG"����a4 �������:"+HIB" ��\n"NOR);		
		
  file = "/p/residence/weapon/"+me->query("id")+"_a5.c";
  newob=load_object(file);
	if( newob)
	{
	printf(HIG"����a5 �������:"+HIB" %s\n"NOR,newob->query("name")+"("+newob->query("id")+")");
	}
	else printf(HIG"����a5 �������:"+HIB" ��\n"NOR);		
		
  file = "/p/residence/weapon/"+me->query("id")+"_a6.c";
  newob=load_object(file);
	if( newob)
	{
	printf(HIG"����a6 �������:"+HIB" %s\n"NOR,newob->query("name")+"("+newob->query("id")+")");
	}
	else printf(HIG"����a6 �������:"+HIB" ��\n"NOR);		

  file = "/p/residence/weapon/"+me->query("id")+"_a7.c";
  newob=load_object(file);
	if( newob)
	{
	printf(HIG"����a7 �������:"+HIB" %s\n"NOR,newob->query("name")+"("+newob->query("id")+")");
	}
	else printf(HIG"����a7 �������:"+HIB" ��\n"NOR);		

  file = "/p/residence/weapon/"+me->query("id")+"_a8.c";
  newob=load_object(file);
	if( newob)
	{
	printf(HIG"����a8 �������:"+HIB" %s\n"NOR,newob->query("name")+"("+newob->query("id")+")");
	}
	else printf(HIG"����a8 �������:"+HIB" ��\n"NOR);												

  file = "/p/residence/weapon/"+me->query("id")+"_a9.c";
  newob=load_object(file);
	if( newob)
	{
	printf(HIG"����a9 �������:"+HIB" %s\n"NOR,newob->query("name")+"("+newob->query("id")+")");
	}
	else printf(HIG"����a9 �������:"+HIB" ��\n"NOR);		

  file = "/p/residence/weapon/"+me->query("id")+"_a10.c";
  newob=load_object(file);
	if( newob)
	{
	printf(HIG"����a10 �������:"+HIB" %s\n"NOR,newob->query("name")+"("+newob->query("id")+")");
	}
	else printf(HIG"����a10 �������:"+HIB" ��\n"NOR);		

	printf(HIW"---------"HIM" �� ����V��������ϵͳ �� "HIW"------------\n"NOR);
me->start_busy(1);
}
else
{
  file = "/p/residence/weapon/"+me->query("id")+"_"+arg+".c";
	newob=load_object(file);
	if (!newob)
	return notify_fail("û��������������������\n");

	if (newob)
{
oldob=present(newob->query("id"),me);
if (oldob && oldob->query("makeritem")==1  && oldob->query("ownmake")==1)
{
message_vision(HIG "$N˫��һ�� һ"+newob->query("unit")+newob->query("name")+"("+newob->query("id")+")"+HIG" ��ʧ��������С�\n" NOR, me);
	 destruct(oldob);


	inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++) {
if (base_name(inv[i])+".c"==file)
	 destruct(inv[i]);

}

}
else
{
message_vision(HIR "$N˫��һչ һ"+newob->query("unit")+newob->query("name")+"("+newob->query("id")+")"+HIR" ������г�����$N���ϡ�\n" NOR, me);
newob=load_object(file);
newob->move(me);
newob->set("bowner",me->query("id"));
}
}
me->start_busy(3);
}		
return 1;
}
int help(object me)
{  
write(@HELP
ָ���ʽ: 
	uweapon �鿴����ӵ�еĴ���������
	uweapon ���� �ٻ�����ӵ�еĴ���������
HELP
   );   
return 1;
}                                                                             
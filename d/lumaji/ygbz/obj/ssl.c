#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIW"ʥ����"NOR, ({ "sheng sheli","sheli"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", HIB"���ʥ��������Ϊа������,��˵�ں�������!
����������ʱ��е������ƺ��й�����,�㲻����������(xi)������ͷ\n"NOR);
                set("unit", "��");
}
    setup();
}
void init()
{
    if (query("zhuren")!=this_player()->query("id"))
return 0;
        add_action("do_xi", "xi");
}
int do_xi(string arg)
{
  object me = this_player();
  int maxneili,neili;
    neili = me->query("neili");
    maxneili = me->query("max_neili");
    
  if(!id(arg)) return 0;
  if(me->is_busy()) return notify_fail("����һ��������û����ɡ�\n");

if ((int)me->query("neili") > (int)me->query("max_neili") * 2)
                 return notify_fail("��������Ѿ������˼��ޣ���������ȥ���߻���ħ\n");

     if( environment(me)->query("no_fight"))
                return notify_fail("���ﲻ�ʺ�������\n");

  if(!me->query("zjbygbz_max"))
{
 if(!query("bei_eat"))
{
   me->add("max_neili",me->query("max_neili")/10);

 write(HIC "���͵�һ��,�о�һ����ֵ��ھ�ԴԴ���ϵĴ�"HIW"ʥ����"NOR"�ﴫ
�����Լ�������,��о��Լ�������ֵ�������Ե�����!\n" + NOR);

     me->set("zjbygbz_max",1);
   set("bei_eat",1);
}
}
if(me->query_temp("ssl_xi"))
{
 if(me->query_temp("ssl_zjb")+5 > time())
  return notify_fail("��������ȡʥ�����������ء�\n");
}
me->set_temp("ssl_xi",1);
me->set_temp("ssl_zjb",time());
    
    me->add("neili",maxneili/3);  
    
 write("�㶨�˶���,˫�ְ���"HIW"ʥ����"HIG"��,�е�һ���ھ���
"HIW"ʥ����"NOR"�д������Լ�������\n" + NOR);

if (!me->query("zjbygbz_ssl"))  { 
  if (random(6)>=3) 
  me->set("zjbygbz_ssl","daoxin");
 else 
 me->set("zjbygbz_ssl","zhanshen");
}
  switch(me->query("zjbygbz_ssl"))
  {
  case "daoxin":   
    call_out("on_daoxin", 1);
    break;
    case "zhanshen":
    call_out("on_zhanshen", 1);
    break;
  }
return 1;
}
void on_zhanshen(object me)
{
  me = this_player(); 
if ((int)me->query_skill("force",1)<1000)
me->improve_skill("force", random((int)me->query_int() * 8 - 9));
 me->delete_temp("ssl_xi");
  if (random(10)>8)    me->start_busy(1);

//message_vision(MAG"\n"+me->name()+"��ս��¼������!\n"NOR, this_player());
   write("����ȡʥ����������ʱ��,ͻȻ���г�����!һЩ��ֵĻ���,
�е��Լ���"HIM"�ڹ�"NOR"һЩ�����׵ĵط�ͻȻ��ͨ��!\n" + NOR);

return;
}
void on_daoxin(object me)
{
  me = this_player(); 
if ((int)me->query_skill("literate",1)<1000)
  me->improve_skill("literate", random((int)me->query_int() * 8 - 9));
 me->delete_temp("ssl_xi");
  if (random(10)>8)    me->start_busy(1);

//message_vision(WHT"\n"+me->name()+"�ĵ�����ħ�󷨽�����!\n"NOR, this_player());
   write("����ȡʥ����������ʱ��,ͻȻ���г�����!һЩ��ֵĻ���,
�е��Լ���"HIW"����֪ʶ"HIB"һЩ�����׵ĵط�ͻȻ��ͨ��!\n" + NOR);
  
return;
}


#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIY"ȡ������"NOR, ({ "zhangpeng" }) );
    set_weight(1);
            set("no_put", 1);
            set("value", 0);
    if( clonep() )
            set_default_object(__FILE__);
    else {
	       
            set("no_put", 1);
            set("no_steal", 1);
            //set("no_get", 1);
            set("no_beg", 1);
            set("value", 100000);
            set("unit", "��");
            set("material", "paper");
            set("long", "�������(usezp)���ﵽ������ľ��� ��(homezp)����������ľ�����\n");
          }

    setup();
}
void init()
{
	add_action("do_eat", "usezp");
	add_action("do_set", "homezp");
}

int do_set(string arg)
{
        object me = this_player();
        string target;
 	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");

    if (me->is_fighting()) 
        return notify_fail("���������������!\n");
    if (me->is_busy()) 
        return notify_fail("������������!\n");
    if (me->query("neili")<3000)
	return notify_fail("�����������!\n");
    if(environment(me)->query("outdoors")=="xy1"
       ||environment(me)->query("outdoors")=="xy2"
       ||environment(me)->query("outdoors")=="xy3"
       ||environment(me)->query("outdoors")=="xy4"
       ||environment(me)->query("outdoors")=="xy5"
       ||environment(me)->query("outdoors")=="xy6"
||environment(me)->query("outdoors")=="xy7"
||environment(me)->query("outdoors")=="xy8"
||environment(me)->query("outdoors")=="xy9"
||environment(me)->query("outdoors")=="xy10"
||environment(me)->query("outdoors")=="xy11"
||environment(me)->query("outdoors")=="xy12"
||environment(me)->query("outdoors")=="xy13"
||environment(me)->query("outdoors")=="xy14"
||environment(me)->query("outdoors")=="xy15"
||environment(me)->query("outdoors")=="xy16"       
||environment(me)->query("outdoors")=="xy17"
||environment(me)->query("outdoors")=="xy18"
||environment(me)->query("outdoors")=="xy19"
||environment(me)->query("outdoors")=="xy20"
||environment(me)->query("outdoors")=="xy21"
||environment(me)->query("outdoors")=="xy22"
||environment(me)->query("outdoors")=="xy23"
||environment(me)->query("outdoors")=="xy24"
||environment(me)->query("outdoors")=="xy25"
||environment(me)->query("outdoors")=="xy26"
||environment(me)->query("outdoors")=="xy27"
||environment(me)->query("outdoors")=="xy28"
||environment(me)->query("outdoors")=="xy29"
||environment(me)->query("outdoors")=="xy30"
||environment(me)->query("outdoors")=="xy31"
||environment(me)->query("outdoors")=="xy32"
||environment(me)->query("outdoors")=="xy33"
||environment(me)->query("outdoors")=="xy34"
||environment(me)->query("outdoors")=="xy35"
||environment(me)->query("outdoors")=="xy36")
{
        target=(string)file_name(environment(me));
        me->set("qjtarget",target);
        me->start_busy(8);
        message_vision(HIY "$N�԰�ȡ�������ó���һ������������!\n" NOR, me);
        message_vision(HIY "�´�ʹ��ȡ�������㽫��ֱ����������!\n" NOR, me);
        me->add("neili",-2000);
}	
else 
{
        message_vision(HIG "$N���ﲻ��ʹ��!\n" NOR, me);
}
	return 1;
}


int do_eat(string arg)
{
        object me = this_player();
        object tarset;
 	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");

    if (me->is_fighting()) 
        return notify_fail("���������������!\n");
    if (me->is_busy()) 
        return notify_fail("������������!\n");
    if (me->query("neili")<3000)
	return notify_fail("�����������!\n");

     if (!me->query("qjtarget"))
        return notify_fail("��û����������ľ���!\n");
        
     if (!me->query("qjtarget"))
       {
        me->move("d/city/guangchang");
       }
      else{
      tarset=me->query("qjtarget");
      me->move(tarset);
      }
        me->start_busy(8);
        message_vision(HIY "$N��ȡ�������ó� �����˽�ȥ��һ������������!\n" NOR, me);
        me->add("neili",-2000);
	destruct(this_object());

	return 1;
}


// ���

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIY"�ƽ�"NOR, ({"gold egg"}));
	set_weight(10);
    set("value", 0);
set("no_steal",1);
set("liwu",1);
set("no_beg",1);
    set("no_put",1);
    set("no_get","ÿ����ֻ��һ������Ҫ��ô̰�ģ�\n");
    set("no_drop","��ô���Ķ�����Ҳ�ӣ���\n");
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("long", "һ��"+HIY"�ƽ𵰣�"NOR+"�ƺ����Զһ�(duihuan)��\n");
                set("unit", "��");
	}
}
  void init()
{
  add_action("do_open","duihuan");
}
int do_open()
{
	int exp,pot,score;
object corpse;
object ob;
int i,j;
        object me = this_player();

        this_player()->start_busy(30);

	exp = 500+random(388);
	             pot = exp*0.8;
             score = random(20)+10;
        me->add("max_neili", 1);
        me->add("combat_exp", exp);
        me->add("potential", pot);
tell_object(me,HIY"�㱻�����ˣ�һ����������\n" +
             chinese_number(exp) + "��ʵս����\n"+
             chinese_number(pot) + "��Ǳ��\n" NOR);

i=random(8)+1;
j=random(18)+1;
//tell_object(me,HIY"���ҵ���һЩ�ƽ�!\n"+NOR);
if (random(5)==0)
{
ob=new("/clone/money/gold");
ob->set_amount(j);
ob->move(me);
message_vision(HIY"$N�һ���һ���ƽ𵰣�$N������"+j+"����Ļƽ�. \n"NOR, this_player());
}
else
if (random(8)==0)
{
ob=new("/clone/money/1000-cash");
ob->set_amount(i);
ob->move(me);
message_vision(HIY"$N�һ���һ���ƽ𵰣���$N������"+i+"��һǧ����Ʊ. \n"NOR, this_player());
}
else

{
ob=new("/clone/money/silver");
ob->set_amount(j);
ob->move(me);
message_vision(HIY"$N�һ���һ���ƽ𵰣�$N������"+j+"����İ���. \n"NOR, this_player());
}




	destruct(this_object());
	return 1;
}

void owner_is_killed()
{
	destruct(this_object());
}
